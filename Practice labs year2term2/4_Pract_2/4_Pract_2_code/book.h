#ifndef BOOK_H
#define BOOK_H
#include <cstring>
#include <stdio.h>

class Book
{
	char *author;
	char *title;
	char *publisher;
	int year;
	int number_pages;
	void set_arr(char *&, const char *);
public:
	Book() {
		author = nullptr;
		title = nullptr;
		publisher = nullptr;
		year = 0;
		number_pages = 0;
	}
	//Book(const char *author = "", const char *title = "", const char *publisher = "", int year = 0, int number_pages = 0);
	Book(const char *author, const char *title, const char *publisher, int year, int number_pages);
	~Book();
	const char *get_author() const;
	const char *get_title() const;
	const char *get_publisher() const;
	int get_year() const;
	int get_numer_pages() const;
	void set_author(const char *);
	void set_title(const char *);
	void set_publisher(const char *);
	void set_year(int);
	void set_number_pages(int);

	void display();
};

#endif // BOOK_H
