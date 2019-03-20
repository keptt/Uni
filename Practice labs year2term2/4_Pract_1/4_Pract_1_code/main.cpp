#include <book.h>

using namespace std;

int main()
{   Book *b = new Book("Wan", "One", "OnePublish", 1911, 111);

    b->display();
    b->set_author("Kim");
    b->set_title("K");
    b->set_publisher("KElite");
    b->set_number_pages(1000);
    b->set_year(1999);
    b->display();

    delete b;
    return 0;
}
