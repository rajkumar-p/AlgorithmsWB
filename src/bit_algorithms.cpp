#include "bit_algorithms.h"

unsigned int count_ones(unsigned int num) {
    unsigned int count = 0;
    int mask = 1;
    for (; num != 0; num = num >> 1) {
        count += num & mask;
    }

    return count;
}

// Works on 32 bit input
unsigned int count_ones_by_lookup(unsigned int num) {
    unsigned char lookup_table[256] = {
            0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4,
            3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5 , 2, 3, 3, 4, 3, 4, 4, 5,
            3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4,
            3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4,
            3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5,
            3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6 , 7, 2, 3, 3, 4,
            3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
            3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6,
            7, 7, 8
    };
    unsigned int first_byte = (num & 0xFF) >> 0;
    unsigned int second_byte = (num & 0xFF00) >> 8;
    unsigned int third_byte = (num & 0XFF0000) >> 16;
    unsigned int fourth_byte = (num & 0XFF000000) >> 24;

    unsigned int count = lookup_table[first_byte] + lookup_table[second_byte]
                        + lookup_table[third_byte] + lookup_table[fourth_byte];
    return count;
}

unsigned int count_ones_better(unsigned int num) {
    unsigned int count = 0;
    for (; num != 0; ++count) {
        num = num & (num - 1);
    }

    return count;
}

bool bit_parity(unsigned int num) {
    num = num ^ (num >> 16);
    num = num ^ (num >> 8);
    num = num ^ (num >> 4);
    num = num ^ (num >> 2);
    num = num ^ (num >> 1);
    return num & 1;
}

int convert_byte_order(const int number)
{
    // ALGORITHM
    // 1) Copy number into a stack variable
    // 2) Place two char * - one in the first byte and one in the last
    // 3) Reverse contents using the two char *
    int result = number;
    char *begin = (char *)&result;
    char *end = (char *)&result + sizeof(int) - 1;
    while (begin < end) {
        char t = *begin;
        *begin = *end;
        *end = t;
        ++begin;
        --end;
    }

    return result;
}
