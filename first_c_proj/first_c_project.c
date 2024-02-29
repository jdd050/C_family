/*
* My first C project. I like to make a quadratic equation solver when I start on a new language 
* just because it covers a decent amount of knowledge, such as user input, math exceptions, and in the case of C
* strings and memory
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 256

int main()
{
    // define coefficients and read user input into them (Ax^2 + Bx + C)
    double a, b, c;
    char line[MAX];

    // clean a
    do {
        fgets(line, sizeof(line), stdin);
    } while (sscanf(line, "%lf", &a) != 1);

    
    // clean b
    do {
        fgets(line, sizeof(line), stdin);
    } while (sscanf(line, "%lf", &b) != 1);

    // clean c
    do {
        fgets(line, sizeof(line), stdin);
    } while (sscanf(line, "%lf", &c) != 1);

    // calculate discriminant to determine root behavior
    // (if the discriminant is less than 0, there are imaginary root(s))
    double discriminant = (b*b) - (4*a*c);

    // calculate roots x = (-b +/- sqrt(b^2-4ac)) / 2a
    if (discriminant < 0) {
        double imaginary = sqrt(-discriminant)/(a+a);
        double real = -b/(a+a);
        printf("\nRoot 1: %lf + %lf * i\n",real, imaginary);
        printf("Root 2: %lf - %.lf * i\n",real, imaginary);
    } 
    else {
        double root_one = (-b + sqrt(discriminant))/(a+a);
        double root_two = (-b - sqrt(discriminant))/(a+a);
        printf("\nRoot 1: %lf \nRoot 2: %lf", root_one, root_two);
    }
    return 0;
}