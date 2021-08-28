#include <math.h>
#include "test.h"
#include <assert.h>

const double epsilon = 1e-4;

int main(){

    printf("What to do? 0 - tests, 1 - to solve\n");
    int answer = 0;
    scanf("%d", &answer);
    if (answer == 0) {
        if (all_Tests()) {
            printf("All tests success!");
            return 0;
        }
        return 1;
    }

    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

    if (scanf("%lf %lf %lf", &a, &b, &c)!= 3){
        printf("Error\nEnter three numbers");
        return 0;
    }

    switch (solutions_equation(a, b, c, &x1, &x2)){
        case NO_ROOTS:
            printf("No roots");
            break;
        case ONE_ROOTS:
            printf("x1 = %lg", x1);
            break;
        case TWO_ROOTS:
            printf("x1 = %lg, x2 = %lg", x1, x2);
            break;
        case INFINITY_ROOTS:
            printf("Infinity roots");
            break;

        default:
            printf("Error");
    }
    return 0;
}

/*
This function returns the number of solutions to the equation with coefficients: a, b, c
*/
int solutions_equation(double a, double b, double c, double* x1, double* x2){

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (is_Zero(a)) {
        *x2 = NAN;
        return linear_equation(b, c, x1);
    }
    double D = b * b - 4 * a * c;
    if (is_Zero(D)) {
        *x1 = -b / (2 * a);
        *x2 = NAN;
        return ONE_ROOTS;
    }
    if (D < 0) {
        *x1 = *x2 = NAN;
        return NO_ROOTS;
    }

    *x1 = (-b + sqrt(D)) / (2 * a);
    *x2 = (-b - sqrt(D)) / (2 * a);
    return TWO_ROOTS;
}

int is_Zero(double value){
    return (fabs(value) < epsilon);
}

int linear_equation(double b, double c, double* x1){

    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);

    if (is_Zero(b)) {
        if (is_Zero(c)){
            *x1 = INFINITY;
            return INFINITY_ROOTS;
        }
        *x1 = NAN;
        return NO_ROOTS;
    }
    *x1 = -c / b;
    return ONE_ROOTS;
}
