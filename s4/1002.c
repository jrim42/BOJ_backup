#include <stdio.h>
#include <math.h>

int main (void)
{
    int T;
    scanf("%d", &T);
    double x1, y1, r1;
    double x2, y2, r2;

    for(int i = 0; i<T; i++)
    {
        scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
        double d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        int result;

        if(x1 == x2 && y1 == y2)
        {
            if(r1 == r2)
                result = -1;
            else
                result = 0;
        }
        else if (d > r1+ r2 || d < fabs(r1 - r2))
            result = 0;
        else if (d == (r1 + r2) || d == fabs(r1 - r2))
            result = 1;
        else
            result = 2;
            
        printf("%d\n", result);
    }
    return 0;
}