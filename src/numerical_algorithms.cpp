#include <cmath>

#include "numerical_algorithms.hpp"

unsigned int reverse(unsigned int number)
{
    unsigned int actual = number;
    unsigned int p = 0;
    unsigned int rev = 0;
    while (actual != 0) {
        rev = (rev * 10) + (actual % 10);
        ++p;
        actual = actual / 10;
    }

    return rev;
}
