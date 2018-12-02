#include "core.h"

//--------------------------------------------------------//
//function fetches data from file to required variables weakly;
//--------------------------------------------------------//
void weak_fetch_file_data(std::ifstream &fin, long double &start, long double &end,
                     long double &step, long double& prec)
{
    fin >> start >> end >> step >> prec;
    if (fin.fail())
    {
        throw std::logic_error("Bad file content");
    }
    else if (prec <= 0 || prec >= 1)
    {
        throw std::logic_error("Invalid precision value\n Should bein (0,1)");
    }
    calc_results(start, end, step, prec);
}

//--------------------------------------------------------//
//function fetches data from file to required variables strongly skipping the unwanted content;
//used inside read_from_file func
//--------------------------------------------------------//
void fetch_file_data(std::ifstream &fin, long double &start, long double &end,
                     long double &step, long double prec)
{
    char elements[501];
    long double arr[4];

    try
    {
        while (!fin.eof())//
        {
            fin.getline(elements, 500);
        }
    } catch (...)
    {
        std::cerr << "(0_0)";
    }

    char *first = elements;
    char *tmp = elements;
    char *last = elements + 501;

    size_t count = 0;

    while(count < 4)
    {
        char *found_digit =  std::find_if(first, last,
            [](char a){
            return (48 <= a && a >= 57); });
        if (found_digit != last && found_digit != first)
        {
            if (*(found_digit - 1) == 45)
            {
                --found_digit;
            }
            tmp = found_digit;
            ++found_digit;
            unsigned int number_of_dots(0);
            while ((((48 <= *(found_digit) && *(found_digit) >= 57)) || (*(found_digit) == 46 && number_of_dots < 2)) && (found_digit != last))
            {
                ++found_digit;
                if (*(found_digit) == 46)
                {
                    ++number_of_dots;
                }
            }
            *(found_digit) = ' ';
            found_digit = tmp;

            fin.seekg(std::distance(first, found_digit));

            fin >> arr[count];

            ++count;
            if (found_digit == last)
            {   break;}
        }
        if (count == 4)
        {
            start = arr[0];
            end = arr[1];
            step = arr[2];
            prec = arr[3];
        }
        else
        {
            throw std::logic_error("incorrect file input");
        }

        calc_results(start, end, step, prec);

    }

}
bool read_from_file(long double &start, long double &end, long double &step, long double &prec)
{
    std::ifstream fin;
    fin.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    char path[101];
    std::cout << "Path to file required\n"
                 "100 symbols or less\n"
                 "No needto specify path if file and program in same folder\n"
                 "INPUT PATH HERE: ";
    std::cin >> path;
    try
    {
        fin.open(path);
    }
    catch(const std::ifstream::failure& failure)
    {
        std::cout << "file oppening issues\n";
        std::cerr << failure.what() << std::endl;
        std::cerr << failure.code() << std::endl;
        return 0;
    }

    try
    {
        weak_fetch_file_data(fin, start, end, step, prec);
    } catch (const std::exception & e)
    {
        std::cout << "Bad file content" << std::endl;
        std::cerr << e.what() << std::endl;
        return 0;
    }


    fin.close();
    return 1;
}

//--------------------------------------------------------//
//function creates table hat;
//--------------------------------------------------------//
void create_table_hat()
{

    std::cout << " ____________________________________________________________________________________\n";;
    std::cout << "|                |                |                |                |                |\n";
    std::cout << "|       x        |      f(x)      |    series(x)   | absolute error |      steps     |\n";
    std::cout << "|________________|________________|________________|________________|________________|\n";
}

void create_table_hat(std::ofstream &fout)
{
    fout << " ____________________________________________________________________________________\n";;
    fout << "|                |                |                |                |                |\n";
    fout << "|       x        |      f(x)      |    series(x)   | absolute error |      steps     |\n";
    fout << "|________________|________________|________________|________________|________________|\n";
}

//--------------------------------------------------------//
//function that adds new row with data to the table;
//--------------------------------------------------------//
void add_table_row(const long double x = 0, const long double embedded_func = 0,
                   const long double my_func = 0, const long double diviation = 0, const long long steps = 0)
{
    std::cout << "|" << std::setw(16) << x;
    std::cout << "|" << std::setw(16) << embedded_func;
    std::cout << "|" << std::setw(16) << my_func;
    std::cout << "|" << std::setw(16) << diviation;
    std::cout << "|" << std::setw(16) << steps;
    std::cout << "|\n";
    std::cout << "|________________|________________|________________|________________|________________|\n";
}

void add_table_row(std::ofstream &fout, const long double x = 0, const long double embedded_func = 0,
                   const long double my_func = 0, const long double diviation = 0, const long long steps = 0)
{
    fout << "|" << std::setw(16) << x;
    fout << "|" << std::setw(16) << embedded_func;
    fout << "|" << std::setw(16) << my_func;
    fout << "|" << std::setw(16) << diviation;
    fout << "|" << std::setw(16) << steps;
    fout << "|\n";
    fout << "|________________|________________|________________|________________|________________|\n";
}

//--------------------------------------------------------//
//function that calculates Taylor seria of sin^3(x);
//--------------------------------------------------------//
long double rec(long double x, long double prec, long double a1,long double sum, long long &n)
{
    if (fabsl(a1) < prec)
    {
        return sum;                       //ctr_TAB
    }

    long double q =- ((pow(3.0, 2*n + 1.0) - 3.0)* x*x)/((pow(3.0, 2*n - 1.0) - 3.0)*2.0*n*(2.0*n + 1.0));
    a1 = a1 * q;
    return rec(x, prec, a1, sum+a1, ++n);
}

//--------------------------------------------------------//
//throw-function for receiving and verifying input;
//--------------------------------------------------------//
template <typename Str, typename T>
void input (Str * msg, T &inp_var)
{
    std::cout << msg;
    std::cin >> inp_var;
    if (!std::cin)
    {
        throw std::logic_error("cin stream broken. Incorrect data was given");
    }
}

//--------------------------------------------------------//
//function that calls calc and display in console funcs;
//--------------------------------------------------------//
void calc_results(long double start, long double end, long double step, long double prec)//bool?
{//add mode
    //char *buffer_for_file_write = new char[static_cast<int>(((16*5)+6)*(4 + 2*((end - start)/step)))+1];
    create_table_hat();
    for (long double x = start; x <= end; x +=step)
    {
        long double result_cmath = powl(sin(x), 3.0);
        long double first_element_of_Taylor = (((3*3*3 - 3)/(2*3))/4)*x*x*x;
        long long steps = 2;
        long double result_rec = rec(x, prec, first_element_of_Taylor, first_element_of_Taylor, steps);

        add_table_row(x, result_cmath, result_rec, fabsl(result_cmath - result_rec), steps);
        steps = 2;
    }
}
void calc_results(std::ofstream &fout, long double start, long double end, long double step, long double prec)//bool?
{
    create_table_hat(fout);
    for (long double x = start; x <= end; x +=step)
    {
        long double result_cmath = powl(sin(x), 3.0);
        long double first_element_of_Taylor = (((3*3*3 - 3)/(2*3))/4)*x*x*x;
        long long steps = 2;
        long double result_rec = rec(x, prec, first_element_of_Taylor, first_element_of_Taylor, steps);

        add_table_row(fout, x, result_cmath, result_rec, fabsl(result_cmath - result_rec), steps);
        steps = 2;
    }
}
//--------------------------------------------------------//
//function that provides communication with users and takes
//cotrol of calls to all other func-modules;
//--------------------------------------------------------//
bool start_work()
{
    bool exceptions_exist = 1;
    bool answer(0);
    while  (exceptions_exist)
    {
        try
        {
            input ("Would you like to read from file? ", answer);
            exceptions_exist = 0;
        }
        catch (std::exception& e)
        {
            std::cin.clear();
            std::cin.ignore(100,'\n');
            exceptions_exist = 1;
            std::cout << "Bad input\n";
            std::cerr << e.what();
        }
    }

    long double start(0), end(0), step(1), prec(0);

    if (answer)// then  read from file
    {
        answer = 0;
        bool reading_succed = read_from_file(start, end, step, prec);
        while (!reading_succed)
        {
            input(" Try again?: ", answer);
            if (answer)
            {   reading_succed = read_from_file(start, end, step, prec);}
            else
            {   return 0;}
        }

    }
    else
    {
        exceptions_exist = 1;
        while  (exceptions_exist)
        {
            try
            {
                input ("input start ", start);
                input ("input end ", end);
                input ("input step ", step);
                input ("input prec ", prec);
                if (prec <= 0 || prec >= 1)
                {
                    throw std::logic_error("Invalid precision value\n Should bein (0,1)");
                }
                exceptions_exist = 0;

                if (end - start < step)
                {
                    std::cout << "start and end variable are too close";
                    throw std::logic_error("start and end input incorrect. start should be less than end");//
                }
            }
            catch (std::exception& e)
            {
                std::cin.clear();
                std::cin.ignore(100,'\n');
                exceptions_exist = 1;
                std::cout << "Bad input\n";
                std::cerr << e.what();
            }
        }
        calc_results(start, end, step, prec);
    }

    answer = 0;
    exceptions_exist = 1;
    while  (exceptions_exist)
    {
        try
        {
            input ("Would you like to save results in a file? ", answer);
            exceptions_exist = 0;
        }
        catch (std::exception& e)
        {
            std::cin.clear();
            std::cin.ignore(100,'\n');
            exceptions_exist = 1;
            std::cout << "Bad input\n";
            std::cerr << e.what();
        }
    }

    if (answer)
    {//call fout func;
        while (!write_in_file_func(start, end, step, prec))
        {
            answer = 0;
            input("try again?", answer);
            if (answer)
            {   write_in_file_func(start, end, step, prec);}
            else
            {   return 0;}
        }

    }

    return 1;
}
//--------------------------------------------------------//
//function for writing in file. calls overloaded with ofstream calc_results func
//--------------------------------------------------------//
bool write_in_file_func(long double start, long double end, long double step, long double prec)
{
    char path[56];
    std::cout << "Enter a path to existing file or name to create new file to save data (55 symb max): ";
    std::cin >> path;
    while (!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(100,'\n');
        std::cout << "too big input\n";
        std::cout << "Enter a path to existing file or name to create new file to save data (55 symb max): ";
        std::cin >> path;
    }
    std::ofstream fout;
    fout.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    try
    {
        fout.open(path);
    }
    catch (const std::ofstream::failure& f)
    {
        std::cout << "Issues while oppening the file\n";
        std::cerr << f.what() << std::endl;
        std::cerr << f.code() << std::endl;
        return 0;
    }
    calc_results(fout, start, end, step, prec);

    std::cout << "Done\n";
    return 1;
}
