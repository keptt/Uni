#include <iostream>
#include <string.h>

#define SIZE_ARR 6//number of pupils

struct Pupil
{
    char address[50];
    char name[50];
    char last_name[50];
    char club[50];
    float mark;
};

struct Result
{
    double avg_mark;
    Pupil winner;

};

bool is_new(char *element, char **arr, size_t quantity)
{
    for (size_t i = 0; i < quantity; ++i)
    {
        if (strcmp(arr[i], element) == 0)
        {   return false;}
    }

    return true;
}

void input (Pupil &p, char **arr, size_t number, size_t quantity_of_arr_elements)
{
    std::cout << "Input name: ";
    std::cin >> p.name;
    std::cout << "Input last name: ";
    std::cin >> p.last_name;
    std::cout << "Input address: ";
    std::cin >> p.address;
    std::cout << "Input club: ";
    std::cin >> p.club;

    if (is_new(p.club, arr, quantity_of_arr_elements))
    {   arr[number] = p.club;}

    std::cout << "Input score: ";
    std::cin >> p.mark;
}
const Result seek_4_winner(Pupil *pups_arr, char *club)
{
    Pupil winner;
    int sum_of_marks = 0;
    int number_of_marks_in_same_club = 0;
    winner.mark = 0;
    for (int i = 0; i < SIZE_ARR; ++i)
    {
        if (strcmp(pups_arr[i].club, club) == 0)
        {
            sum_of_marks += pups_arr[i].mark;
            number_of_marks_in_same_club++;

            if (winner.mark <= pups_arr[i].mark)
            {   winner = pups_arr[i];}
        }
    }

    double avg_mark = sum_of_marks/number_of_marks_in_same_club;

    //Result *res = new Result();
    Result res;
    res.winner = winner;
    res.avg_mark = avg_mark;

    return res;
}

Result* parse_pupils(Pupil *pups_arr, char **arr, size_t quantity)
{
    Result *arr_of_results = new Result[quantity];

    for (size_t i = 0; i < quantity; ++i)
    {
        Result res = seek_4_winner(pups_arr, arr[i]);//array and string wich represents a certin club
        arr_of_results[i] = res;
    }

    return arr_of_results;
}

void display_results(Result *arr_of_results, size_t quantity_clubs)
{
    for (size_t i = 0; i < quantity_clubs; ++i)
    {
        std::cout << "....................................................\n ";

        std::cout << "Winnner of " << arr_of_results[i].winner.club << " club: "
                  << arr_of_results[i].winner.name << " " << arr_of_results[i].winner.last_name
                  << " with score: " << arr_of_results[i].winner.mark << std::endl;

        std::cout << "average mark in  " << arr_of_results[i].winner.club << " club: "
                  << arr_of_results[i].avg_mark << std::endl;

        std::cout << "....................................................\n ";
    }
}

void fill_arr_of_clubs(Pupil *arr_of_pupils, char **arr, size_t quantity)
{
    int j = 0;
    for (size_t i = 0; i < SIZE_ARR; ++i)
    {
        if (is_new(arr_of_pupils[i].club, arr, quantity))
        {
            arr[j] = arr_of_pupils[i].club;
            j++;
        }
    }
}

int main()
{
    size_t quantity_clubs = 3;

    char **arr = new char *[quantity_clubs];//array of clubs
    for (size_t i = 0; i < quantity_clubs; ++i)
    {
        arr[i] = new char[50];
    }

    Pupil arr_of_pupils[SIZE_ARR] = {
        {"Tom", "Dgff", "hdfs", "boxing", 100},
        {"Tht", "Grthr", "hdfs", "boxing", 200},
        {"Trth", "ertjf", "hdfs", "swimming", 97},
        {"Treht", "retjf", "hdfs", "cycling", 134},
        {"Tyuk", "erjff", "hdfs", "swimming", 88},
        {"Tuil", "Dfdgjgff", "hdfs", "cycling", 180},
    };

    fill_arr_of_clubs(arr_of_pupils, arr, 3);


    Result *arr_of_results = parse_pupils(arr_of_pupils, arr, quantity_clubs);
    display_results(arr_of_results, quantity_clubs);


    delete[] arr_of_results;

    for (size_t i = 0; i < quantity_clubs; ++i)
    {
        delete [] arr[i];
    }
    delete [] arr;

    return 0;
}
