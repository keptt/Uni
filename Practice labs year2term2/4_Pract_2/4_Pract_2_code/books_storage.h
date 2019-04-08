#ifndef BOOKS_STORAGE_H
#define BOOKS_STORAGE_H
#include "book.h"

struct library
{
	const char *author;
	const char *title;
	const char *publisher;
	int year;
	int number_pages;
	//        char author[101];
	//        char title[101];
	//        char publisher[101];
	//        int year;
	//        int number_pages;
};

class books_storage
{
	Book *internal_arr;
	int size;
	void print_hat() const;
	void print(Book &ex) const;
public:
	books_storage();
	books_storage(library *arr, int size);
	void print_books_by_author(const char *author) const;
	void print_books_by_publisher(const char *publisher) const;
	void print_books_after_year(int year) const;
	~books_storage();
};

#endif // BOOKS_STORAGE_H
