#include "book.h"
Book::Book(const char *author, const char *title, const char *publisher, int year, int number_pages):author(), title(), publisher(),
                                                                                                     year(year), number_pages(number_pages)
{
    if (author == nullptr)
	{
        Book::author = nullptr;
	}
	else
	{
		Book::author = new char[strlen(author)+1];
		strcpy(Book::author, author);
	}
    if (title == nullptr)
	{
        Book::title = nullptr;
	}
	else
	{
		Book::title = new char[strlen(title)+1];;
		strcpy(Book::title, title);
	}
    if (publisher == nullptr)
	{
        Book::publisher = nullptr;
	}
    else
    {
        Book::publisher = new char[strlen(publisher)+1];
        strcpy(Book::publisher, publisher);
    }
}

Book::~Book()
{
    delete []author;
    delete []title;
    delete []publisher;
}

const char *Book::get_author() const
{
    return author;
}

const char *Book::get_title() const
{
    return title;
}

const char *Book::get_publisher() const
{
    return  publisher;
}

int Book::get_year() const
{
    return year;
}

int Book::get_numer_pages() const
{
    return number_pages;
}

void Book::set_author(const char *author = "")
{
    set_arr(Book::author, author);
}

void Book::set_title(const char *title)
{
    set_arr(Book::title, title);
}

void Book::set_publisher(const char *publisher)
{
    set_arr(Book::publisher, publisher);
}

void Book::set_year(int year)
{
    Book::year = year;
}

void Book::set_number_pages(int number_pages)
{
    Book::number_pages = number_pages;
}

void Book::set_arr(char *&field_arr, const char *arr)
{
    delete []field_arr;
    if (arr)
    {
        field_arr = new char[strlen(arr)+1];
        strcpy(field_arr, arr);
    }
	else
		field_arr = nullptr;
}

void Book::display()
{
    printf("\n");
    printf("author: %s\n", author);
    printf("title: %s\n", title);
    printf("publisher: %s\n", publisher);
    printf("publisher: %d\n", year);
    printf("publisher: %d\n", number_pages);
    printf("\n");
}



