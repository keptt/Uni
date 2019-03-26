#include "books_storage.h"
#include <stdexcept>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable: 4996)

enum Answer{
    by_author = 1, by_publisher, after_year
};

void library_menu(books_storage &storage)
{
    int keep_going = true;

    while (keep_going)
    {
        Answer ask(by_author);
        printf("Welcome\n");
        printf("What u wish to see: \n"
               "1.Print by author (enter 1)\n"
               "2.Print by publisher (enter 2)\n"
               "3.Print after year (enter 3)\n");
        scanf("%d", &ask);

        switch (ask)
        {
        case by_author:
            char author[65];
            while(getchar() != '\n');
			printf("Input an author: ");
            gets_s(author);
            storage.print_books_by_author(author);
            break;
        case by_publisher:
            char publisher[65];
			printf("Input a publisher: ");
			while (getchar() != '\n');
            gets_s(publisher);
            storage.print_books_by_publisher(publisher);
			break;
        default:
             throw std::logic_error("Unhandled special enum constant!");

        case after_year:
            int year;
			printf("Input a year: ");
            scanf("%d", &year);
            storage.print_books_after_year(year);
            break;
        }

        printf("continue (1/0?): ");
        scanf("%d", &keep_going);
    }
}

int main()
{
	library arr[5] = {
		{"A A", "AAA", "aaa2000", 1, 100},
		{"B B", "BBB", "bbb3000", 2, 200},
		{"C C", "CCC", "ccc4000", 3, 300},
		{"D D", "DDD", "aaa2000", 4, 400},
		{"A A", "FFF", "eee6000", 5, 500}
	};

	books_storage store(arr, sizeof(arr) / sizeof(arr[0]));

	library_menu(store);

	getchar();
}
