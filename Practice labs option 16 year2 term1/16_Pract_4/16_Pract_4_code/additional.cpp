#include <stdio.h>
#include <cmath>


int main ()
{

    int x (0), y (0);
    double r (0);
    bool request;

    printf ("Input x and y cordinates of the point: ");
    scanf  ("%d %d", &x, &y);

    printf ("Input a radius length: ");
    scanf ("%lf", &r);

    printf("What u wanna be performed? [main task - 1, add. task - 0]: ");
    scanf ("%d", &request);

    if (request == 1)
    {
        if (pow(x, 2) + pow(y, 2) > pow(r, 2))
        {
            printf("The point is outside the circle/n");

        }
        else
        {
            printf("The point is inside the circle\n");
            if (y < 0)
            {
                printf("Point is lower the x –axis\n");
            }
            else
            {

                printf("Point is above the x-axis\n");
                if (y > r / 2)
                {
                    printf("the point is above the y = r/2\n");
                }
                else
                {
                    printf("the point is lower than y = r/2\n");
                    if (x < 0)
                    {
                        printf("The point is to the left of x = 0;\n ");
                    }

                    else
                    {
                        printf("The point is to the right of x = 0;\n ");
                        printf("POINT'S TOTALLY INSIDE THE AREA!\n");
                    }
                }
            }

        }
    }
    else
    {

        if (pow(x, 2) + pow (y,2) <= pow(r, 2) &&
            x >= 0 &&
            y <= r/2.0 &&
            y >= 0)
        {
            printf("Point is inside the area\n");
        }
        else
        {
            printf("Point is outside the area\n");
        }
    }
    return 0;
}
