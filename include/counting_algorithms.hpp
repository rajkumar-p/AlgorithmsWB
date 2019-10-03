#ifndef ALGORITHMSWORKBENCH_COUNTING_ALGORITHMS_HPP
#define ALGORITHMSWORKBENCH_COUNTING_ALGORITHMS_HPP

#include <functional>
#include <list>

// https://www.geeksforgeeks.org/counting-inversions/
template<typename T,
        typename F = std::function<bool(T, T)>>
size_t count_inversions(std::vector<T> &elements,
                        F cmp_fn = std::less<T>());

template<typename T,
        typename F>
size_t count_inversions(std::vector<T> &elements,
                        F cmp_fn)
{
    size_t inversions = 0;
    for (size_t i = 1; i < elements.size(); ++i) {
        T key = elements[i];
        int j = i - 1;
        while (j >= 0 && cmp_fn(key, elements[j])) {
            elements[j + 1] = elements[j];
            --j;
        }
        inversions = inversions + i - j - 1;
        elements[j + 1] = key;
    }

    return inversions;
}

template <typename T,
        typename F = std::function<bool(T, T)>>
size_t better_count_inversions(std::vector<T> &elements,
          F cmp_fn = std::less<T>());
template <typename T,
        typename F = std::function<bool(T, T)>>
void wrapper(std::vector<T> &elements,
             const size_t begin,
             const size_t end,
             F cmp_fn,
             size_t &inversions);
template <typename T,
        typename F = std::function<bool(T, T)>>
void count_inversions_helper(std::vector<T> &elements,
                             const size_t begin,
                             const size_t middle,
                             const size_t end,
                             F cmp_fn,
                             size_t &inversions);

template <typename T, typename F>
size_t better_count_inversions(std::vector<T> &elements,
          F cmp_fn)
{
    size_t inversions = 0;
    wrapper(elements, 0, elements.size() - 1, cmp_fn, inversions);
    return inversions;
}

template <typename T,
        typename F>
void wrapper(std::vector<T> &elements,
             const size_t begin,
             const size_t end,
             F cmp_fn,
             size_t &inversions)
{
    if (begin < end) {
        size_t middle = (end - begin) / 2 + begin;
        wrapper(elements, begin, middle, cmp_fn, inversions);
        wrapper(elements, middle + 1, end, cmp_fn, inversions);
        count_inversions_helper(elements, begin, middle, end, cmp_fn,
                inversions);
    }
}

template <typename T,
        typename F>
void count_inversions_helper(std::vector<T> &elements,
                             const size_t begin,
                             const size_t middle,
                             const size_t end,
                             F cmp_fn,
                             size_t &inversions)
{
    std::list<T> l1(elements.begin() + begin,
                    elements.begin() + middle + 1);
    std::list<T> l2(elements.begin() + middle + 1,
                    elements.begin() + end + 1);

    size_t insert_pos = begin;
    while (!l1.empty() && !l2.empty()) {
        T e1 = l1.front();
        T e2 = l2.front();

        if (cmp_fn(e1, e2)) {
            elements[insert_pos] = e1;
            l1.pop_front();
        } else {
            inversions += l1.size();
            elements[insert_pos] = e2;
            l2.pop_front();
        }
        ++insert_pos;
    }

    while (!l1.empty()) {
        T e1 = l1.front();
        elements[insert_pos] = e1;
        ++insert_pos;
        l1.pop_front();
    }

    while (!l2.empty()) {
        T e2 = l2.front();
        elements[insert_pos] = e2;
        ++insert_pos;
        l2.pop_front();
    }
}

#endif //ALGORITHMSWORKBENCH_COUNTING_ALGORITHMS_HPP
