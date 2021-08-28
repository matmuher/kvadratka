#include <corecrt_math.h>
#include "test.h"

int one_Test(double a, double b, double c, int nRootsValid, double x1valid, double x2valid){
    static int curr_test = 0;
    curr_test += 1;
    double x1 = NAN, x2 = NAN;
    int nRoots = solutions_equation(a, b, c, &x1, &x2);

    if (nRoots != nRootsValid || !is_Equal(x1, x1valid) || !is_Equal(x2, x2valid)) {
        printf("Failed test: %d\nProgram answer: nRoods = %d x1 = %lg x2 = %lg\nCorrect answer: nRoods = %d x1 = %lg x2 = %lg ",
               curr_test, nRoots, x1, x2, nRootsValid, x1valid, x2valid);
        return 0;
    }
    printf("Test #%d succeded\n", curr_test);
    return 1;
}

bool all_Tests(){
    //  write first the larger root then the smaller one
    //             a     b     c              nRoots                x1              x2
    if (!one_Test(0, 0, 1, NO_ROOTS,       NAN,     NAN)) return false;
    if (!one_Test(1, -3,2, TWO_ROOTS,      2,       1  )) return false;
    if (!one_Test(1, 0, 0, ONE_ROOTS,      0,       NAN)) return false;
    if (!one_Test(0, 4, 9, ONE_ROOTS,      -2.25,   NAN)) return false;
    if (!one_Test(0, 0, 0, INFINITY_ROOTS, INFINITY,NAN)) return false;
    return true;
}

int is_Equal(double x, double xvalid){
    if (is_Nan(x) && is_Nan(xvalid)){
        return 1;
    }
    if (x == INFINITY && xvalid == INFINITY){
        return 1;
    }
    return (is_Zero(x - xvalid));
}

int is_Nan(double value){
    return (value != value);
}