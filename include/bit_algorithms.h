#ifndef ALGORITHMSWORKBENCH_BIT_ALGORITHMS_H
#define ALGORITHMSWORKBENCH_BIT_ALGORITHMS_H

unsigned int count_ones(unsigned int num);
unsigned int count_ones_by_lookup(unsigned int num);
unsigned int count_ones_better(unsigned int num);

bool bit_parity(unsigned int num);

template<typename T>
T convert_byte_order(const T element)
{
    // ALGORITHM
    // 1) Copy number into a stack variable
    // 2) Place two char * - one in the first byte and one in the last
    // 3) Reverse contents using the two char *
    T result = element;
    char *start = (char *)&result;
    char *end = (char *)&result + sizeof(T) - 1;
    while (start < end) {
        char val = *start;
        *start = *end;
        *end = val;
        ++start;
        --end;
    }

    return result;
}

#endif //ALGORITHMSWORKBENCH_BIT_ALGORITHMS_H