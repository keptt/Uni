
#include <iostream>

bool fill_file(const char *path, size_t number_elements)
{
    FILE  *f;
    if ((f = fopen(path, "wb")))
    {
        for (size_t i = 0; i < number_elements; ++i)
        {
            int n = rand()%20;
            fwrite(&n, sizeof(int), 1, f);
        }
        fclose(f);
        return true;
    }
    else
    {
        return false;
    }
}
bool execute_main_task(const char *path, size_t num)
{
    FILE  *f;
    int digit(0);
    long int current_cursor(0);

    if (!(f = fopen(path, "rb+")))
    {
        return false;
    }
    fseek(f, 0, SEEK_SET);
    size_t i = 0;
    while (i < num)
    {
        fread(&digit, sizeof(int), 1, f);

        if (digit % 16 == 0)
        {
            current_cursor = ftell(f);
            fseek(f, 0, SEEK_END);
            fwrite(&digit, sizeof(int), 1, f);
            //fprintf(f, "%d", digit);
            fseek(f, current_cursor, SEEK_SET);

        }
        ++i;
    }
    fclose(f);
    return true;
}

void show(char *path)
{
    FILE  *f;
    f = fopen(path, "r+");

    int digit(0);

    std::cout << "--------------------------\n";

     while (fread(&digit, sizeof(int), 1, f) == 1)
     {
         std::cout << digit << std::endl;
     }
     fclose(f);
     std::cout << "............................\n";
}

int main()
{
    char file_path[50];
    std::cout << "INput path: ";
    std::cin >> file_path;
    fill_file(file_path, 20);
    show(file_path);
    execute_main_task(file_path, 20);
    show(file_path);
    return 0;
}


