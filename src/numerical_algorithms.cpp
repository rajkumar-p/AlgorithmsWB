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

bool is_number_a_palindrome(unsigned int number)
{
    unsigned int iter = std::log10(number);
    while (number > 9) {
        // Get the first digit
        unsigned int first_digit = number / std::pow(10, iter);
        // Get the last digit
        unsigned int last_digit = number % 10;
        if (first_digit != last_digit) {
            return false;
        }

        // Remove first digit
        number = number % int(std::pow(10, iter));
        // Remove last digit
        number = number / 10;

        iter = iter - 2;
    }

    return true;
}
