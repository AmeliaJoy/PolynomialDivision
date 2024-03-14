#include <iostream>
using namespace std;
#include "Term.h"
#include "Polynomial.h"
int main(int argc, char *argv[])
{
    Polynomial workingDividend("2x^5+x^4-6x+9");
     Polynomial divisor("x^2-3x+1");
    Polynomial::print(workingDividend/divisor);
}