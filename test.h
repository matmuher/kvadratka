// Created by kseni on 25.08.2021.

#include <stdio.h>
#include "stdbool.h"

int solutions_equation(double a, double b, double c, double *x1, double *x2);
int is_Zero(double value);
int linear_equation(double b, double c, double* x1);
bool all_Tests();
int one_Test(double a, double b, double c, int nRootsValid, double x1valid, double x2valid);
int is_Nan(double value);
int is_Equal(double x, double xvalid);

enum Roots{
    INFINITY_ROOTS = -1,
    NO_ROOTS,
    ONE_ROOTS,
    TWO_ROOTS,
};