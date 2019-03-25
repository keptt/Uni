#include "books_storage.h"

books_storage::books_storage()
{
}

books_storage::books_storage(library *arr, int size)
{
    internal_arr = new Book[size];
    books_storage::size = size;

    for (int i = 0; i < size; i++)
    {
        internal_arr[i].set_year(arr[i].year);
        internal_arr[i].set_number_pages(arr[i].number_pages);
        internal_arr[i].set_author(arr[i].author);
        internal_arr[i].set_publisher(arr[i].publisher);
        internal_arr[i].set_title(arr[i].title);
    }
}

void books_storage::print_hat() const
{
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("Title         Author        Year         Publisher        Number of pages\n");
}

void books_storage::print(Book &ex) const
{
    printf("%s         %s        %d         %s        %d\n", ex.get_title(),
                                                           ex.get_author(),
                                                           ex.get_year(),
                                                           ex.get_publisher(),
                                                           ex.get_numer_pages());
}

books_storage::~books_storage()
{
    printf("-Destor\n");
    delete [] internal_arr;
    printf("-Destor-\n");
}

void books_storage::print_books_by_author(const char *author) const
{
    print_hat();
    for (int i = 0; i < size; i++)
    {
        if (strcmp(internal_arr[i].get_author(), author) == 0)
        {
            print(internal_arr[i]);
        }
    }
}

void books_storage::print_books_by_publisher(const char *publisher) const
{
    print_hat();
    for (int i = 0; i < size; i++)
    {
        if (strcmp(internal_arr[i].get_publisher(), publisher) == 0)
        {
            print(internal_arr[i]);
        }
    }
}

void books_storage::print_books_after_year(int year) const
{
    print_hat();
    for (int i = 0; i < size; i++)
    {
        if (internal_arr[i].get_year() > year)
        {
            print(internal_arr[i]);
        }
    }
}