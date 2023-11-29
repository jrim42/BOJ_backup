/*
#include <stdio.h>
#include <stdbool.h>

bool isPrimeNum (int x)
{
    for(int i=2; i<x; i++)
        if(x%i == 0)
            return false;
    return true;
}
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrimeNum (int x)
{
    int end = (int)sqrt(x);
    for(int i=2; i<=end; i++)
        if(x%i == 0)
            return false;
    return true;
}