#include <complex.h>
#include <math.h>
_Complex double a = 0.0 + 1.0 * _Complex_I;
_Complex double b = cos(3.14/4) + sin(3.14/4) * _Complex_I;
printf("%f %f\n", creal(a), cimag(a));
a *= b; 
printf("%f %f\n", creal(a), cimag(a));
