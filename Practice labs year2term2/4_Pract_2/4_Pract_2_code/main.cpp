#include "books_storage.h"
#include <stdexcept>

//enum Answer{
//    by_author, by_publisher, after_year
//};

//void library_menu(books_storage &storage)
//{
//    bool keep_going = true;

//    while (keep_going)
//    {
//        Answer ask(by_author);
//        printf("Welcome\n");
//        printf("What u wish to see: \n"
//               "1.Print by author (enter 0)\n"
//               "2.Print by publisher (enter 1)\n"
//               "3.Print after year (enter 2)\n");
//        scanf("%d", &ask);

//        switch (ask)
//        {
//        case by_author:
//            char author[55];
//            while(getchar() == '\0');
//            gets(author);
//            storage.print_books_by_author(author);
//            break;
//        case by_publisher:
//            char publisher[55];
//            while(getchar() == '\0');
//            gets(publisher);
//            storage.print_books_by_author(publisher);
//            break;
//        default:
//             throw std::logic_error("Unhandled special enum constant!");

//        case after_year:
//            int year;
//            scanf("%d", &year);
//            storage.print_books_after_year(year);
//            break;
//        }

//        printf("continue (1/0?): ");
//        scanf("%d", keep_going);
//    }

//}

int main()
{
    library arr[5] = {
        {"A A", "AAA", "aaa2000", 1, 100},
        {"B B", "BBB", "bbb3000", 2, 200},
        {"C C", "CCC", "ccc4000", 3, 300},
        {"D D", "DDD", "aaa2000", 4, 400},
        {"A A", "FFF", "eee6000", 5, 500}
    };

    books_storage store(arr, sizeof (arr)/sizeof (arr[0]));

//    printf("========================\n");
//    store.print_books_by_author("AAA");
//    printf("========================\n");
//    store.print_books_after_year(2);
//    printf("========================\n");
//    store.print_books_by_publisher("aaa2000");
//    printf("========================\n");
//    getchar();
    //library_menu(store);
}
