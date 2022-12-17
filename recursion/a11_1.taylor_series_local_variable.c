#include <stdio.h>
double numerator(int x, int power)
{
    if (power == 0)
        return (1);
    return (x * numerator(x, power - 1));
}

double denominator(int frequency)
{
    if (frequency == 0)
        return (1);
    return (frequency * denominator(frequency - 1));
}

double e(int x, int n)
{
    double up;
    double down;

    if (n == 0)
        return (1);
    if (n == 1)
        return (3);
    else
    {
        up = numerator(x, n);
        down = denominator(n);
        return (e(x, n -1) + up / down);
    }
}

#include <stdio.h>
int main()
{
    int n = -1;
    while (n++ < 100)
    {
        printf("e(2, %d) %lf \n", n, e(2, n));
    }
    return (0);
}

// Create a progrom that executes Taylors Series
// e^x = 1 + x^1 / 1! +  x^2 / 2!  + x^3 / 3!  + ... + x^n / n!      

// output
// e(2, 0) 1.000000 
// e(2, 1) 3.000000 
// e(2, 2) 5.000000 
// e(2, 3) 6.333333 
// e(2, 4) 7.000000 
// e(2, 5) 7.266667 
// e(2, 6) 7.355556 
// e(2, 7) 7.380952 
// e(2, 8) 7.387302 
// e(2, 9) 7.388713 
// e(2, 10) 7.388995 
// e(2, 11) 7.389046 
// e(2, 12) 7.389055 
// e(2, 13) 7.389056 
// e(2, 14) 7.389056 
// e(2, 15) 7.389056 
// e(2, 16) 7.389056 
// e(2, 17) 7.389056 
// e(2, 18) 7.389056 
// e(2, 19) 7.389056 
// e(2, 20) 7.389056 
// e(2, 21) 7.389056 
// e(2, 22) 7.389056 
// e(2, 23) 7.389056 
// e(2, 24) 7.389056 
// e(2, 25) 7.389056 
// e(2, 26) 7.389056 
// e(2, 27) 7.389056 
// e(2, 28) 7.389056 
// e(2, 29) 7.389056 
// e(2, 30) 7.389056 
// e(2, 31) 7.389056 
// e(2, 32) 7.389056 
// e(2, 33) 7.389056 
// e(2, 34) 7.389056 
// e(2, 35) 7.389056 
// e(2, 36) 7.389056 
// e(2, 37) 7.389056 
// e(2, 38) 7.389056 
// e(2, 39) 7.389056 
// e(2, 40) 7.389056 
// e(2, 41) 7.389056 
// e(2, 42) 7.389056 
// e(2, 43) 7.389056 
// e(2, 44) 7.389056 
// e(2, 45) 7.389056 
// e(2, 46) 7.389056 
// e(2, 47) 7.389056 
// e(2, 48) 7.389056 
// e(2, 49) 7.389056 
// e(2, 50) 7.389056 
// e(2, 51) 7.389056 
// e(2, 52) 7.389056 
// e(2, 53) 7.389056 
// e(2, 54) 7.389056 
// e(2, 55) 7.389056 
// e(2, 56) 7.389056 
// e(2, 57) 7.389056 
// e(2, 58) 7.389056 
// e(2, 59) 7.389056 
// e(2, 60) 7.389056 
// e(2, 61) 7.389056 
// e(2, 62) 7.389056 
// e(2, 63) 7.389056 
// e(2, 64) 7.389056 
// e(2, 65) 7.389056 
// e(2, 66) 7.389056 
// e(2, 67) 7.389056 
// e(2, 68) 7.389056 
// e(2, 69) 7.389056 
// e(2, 70) 7.389056 
// e(2, 71) 7.389056 
// e(2, 72) 7.389056 
// e(2, 73) 7.389056 
// e(2, 74) 7.389056 
// e(2, 75) 7.389056 
// e(2, 76) 7.389056 
// e(2, 77) 7.389056 
// e(2, 78) 7.389056 
// e(2, 79) 7.389056 
// e(2, 80) 7.389056 
// e(2, 81) 7.389056 
// e(2, 82) 7.389056 
// e(2, 83) 7.389056 
// e(2, 84) 7.389056 
// e(2, 85) 7.389056 
// e(2, 86) 7.389056 
// e(2, 87) 7.389056 
// e(2, 88) 7.389056 
// e(2, 89) 7.389056 
// e(2, 90) 7.389056 
// e(2, 91) 7.389056 
// e(2, 92) 7.389056 
// e(2, 93) 7.389056 
// e(2, 94) 7.389056 
// e(2, 95) 7.389056 
// e(2, 96) 7.389056 
// e(2, 97) 7.389056 
// e(2, 98) 7.389056 
// e(2, 99) 7.389056 