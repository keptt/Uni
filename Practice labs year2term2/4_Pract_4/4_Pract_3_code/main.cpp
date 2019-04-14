#include <iostream>
#include "straight_line.h"
#define POINTS_NUM 2

void input(int i, point &a)
{
    printf("input %i point x coordinate: ", i);
    scanf("%i", &a.x);
    printf("input %i point y coordinate: ", i);
    scanf("%i", &a.y);
}

void ui()
{
    point a, b;

    printf("first line\n");

    input(1, a);
    input(2, b);

    straight_line line1(a, b);

    printf("second line\n");

    input(1, a);
    input(2, b);

    straight_line line2(a, b);

    int answer(4);
    do
    {
        printf("What to do with them [0 - show equasions, 1 - show angle between them, 2 - tell if paralel, 3 - flush console, 4 - nothing ]: ");
        scanf("%i", &answer);
        switch(answer)
        {
        case 0:
            printf("a equasion: "); line1.print_equasion(); printf("\n");
            printf("b equasion: "); line2.print_equasion(); printf("\n");
            break;
        case 1:
            printf("angle between: %f\n", line1 % line2);
            break;
        case 2:
            printf("are paralel: %d\n", line1 || line2);
            break;
        case 3:
            system("cls");
            break;
        case 4:
            break;
        default:
            printf("Wrong input\n");
        }
        //printf("Enter any key to continue");
        system("pause");
    }
    while(answer != 4);
}

int main()
{
    ui();

    return 0;
}


