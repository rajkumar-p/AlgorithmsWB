#ifndef ALGORITHMSWORKBENCH_SORTING_ALGORITHMS_HPP
#define ALGORITHMSWORKBENCH_SORTING_ALGORITHMS_HPP

#include <functional>
#include <vector>
#include <list>

/*
 * Method Definitions
 */
// Insertion Sort
template<typename T,
        typename F = std::function<bool(T, T)>>
void insertion_sort(std::vector<T> &elements,
        F cmp_fn = std::less<T>());

// Selection Sort
template<typename T,
        typename F = std::function<bool(T, T)>>
void selection_sort(std::vector<T> &elements,
        F cmp_fn = std::less<T>());

// Bubble Sort
template <typename T,
        typename F = std::function<bool(T, T)>>
void bubble_sort(std::vector<T> &elements,
        F cmp_fn = std::less<T>());

// Merge Sort
template<typename T,
        typename F = std::function<bool(T, T)>>
void merge_sort(std::vector<T> &elements,
        F cmp_fn = std::less<T>());
template<typename T,
        typename F = std::function<bool(T, T)>>
void merge_sort_helper(std::vector<T> &elements,
        size_t begin, size_t end, F cmp_fn);
template<typename T,
        typename F = std::function<bool(T, T)>>
void merge_helper(std::vector<T> &elements, size_t begin,
                  size_t middle, size_t end, F cmp_fn);

// Heap Sort
template<typename T,
        typename F = std::function<bool(T, T)>>
void heap_sort(std::vector<T> &elements, F cmp_fn = std::less<T>());

/*
 * Method Implementations
 */
// Insertion sort
template<typename T, typename F>
void insertion_sort(std::vector<T> &elements, F cmp_fn)
{
    for(size_t i = 1; i < elements.size(); ++i) {
        T key = elements[i];
        int j = i - 1;
        while(j >= 0 && cmp_fn(key, elements[j])) {
            elements[j + 1] = elements[j];
            --j;
        }

        elements[j + 1] = key;
    }
}

// Selection Sort
template<typename T, typename F>
void selection_sort(std::vector<T> &elements, F cmp_fn)
{
    for (size_t i = 0; i < elements.size(); ++i) {
        size_t min_index = i;
        for (size_t j = i + 1; j < elements.size(); ++j) {
            if (cmp_fn(elements[j], elements[min_index])) {
                min_index = j;
            }
        }
        std::swap(elements[i], elements[min_index]);
    }
}

template <typename T, typename F>
void bubble_sort(std::vector<T> &elements, F cmp_fn)
{
    for (size_t i = 0; i < elements.size(); ++i) {
        for (size_t j = i + 1; j < elements.size(); ++j) {
            if (cmp_fn(elements[j], elements[i])) {
                std::swap(elements[i], elements[j]);
            }
        }
    }
}

// Merge Sort
template<typename T, typename F>
void merge_sort(std::vector<T> &elements,
        F cmp_fn)
{
    merge_sort_helper(elements, 0, elements.size() - 1, cmp_fn);
}

template<typename T, typename F>
void merge_sort_helper(std::vector<T> &elements,
        size_t begin, size_t end,
        F cmp_fn)
{
    if (begin < end) {
        size_t middle = (end - begin) / 2 + begin;
        merge_sort_helper(elements, begin, middle, cmp_fn);
        merge_sort_helper(elements, middle + 1, end, cmp_fn);
        merge_helper(elements, begin, middle, end, cmp_fn);
    }
}

template<typename T, typename F>
void merge_helper(std::vector<T> &elements, size_t begin,
        size_t middle, size_t end, F cmp_fn)
{
    std::list<T> l1(elements.begin() + begin, elements.begin() + middle + 1);
    std::list<T> l2(elements.begin() + middle + 1, elements.begin() + end + 1);

    size_t insert_index = begin;
    while (!l1.empty() && !l2.empty()) {
        if (cmp_fn(l1.front(), l2.front())) {
            elements[insert_index] = l1.front();
            ++insert_index;
            l1.pop_front();
        } else {
            elements[insert_index] = l2.front();
            ++insert_index;
            l2.pop_front();
        }
    }

    while (!l1.empty()) {
        elements[insert_index] = l1.front();
        ++insert_index;
        l1.pop_front();
    }

    while (!l2.empty()) {
        elements[insert_index] = l2.front();
        ++insert_index;
        l2.pop_front();
    }
}

template<typename T, typename F>
void heapify(std::vector<T> &elements,
                 unsigned int start,
                 unsigned int end,
                 F cmp_fn)
{
    if (start >= end) {
        return;
    }

    unsigned int selected = start;
    unsigned int left_child_index = 2 * start + 1;
    unsigned int right_child_index = 2 * start + 2;

    if (left_child_index <= end &&
        cmp_fn(elements[selected], elements[left_child_index])) {
        selected = left_child_index;
    }
    if (right_child_index <= end &&
        cmp_fn(elements[selected], elements[right_child_index])) {
        selected = right_child_index;
    }

    if (start != selected) {
        std::swap(elements[start], elements[selected]);
        heapify(elements, selected, end, cmp_fn);
    }

}

template<typename T, typename F>
void make_heap(std::vector<T> &elements, F cmp_fn)
{
    unsigned int from = (elements.size() / 2) - 1;
    for (int i = from; i >= 0; --i) {
        heapify(elements, i, elements.size() - 1, cmp_fn);
    }
}

template<typename T, typename F>
void heap_sort(std::vector<T> &elements, F cmp_fn)
{
    make_heap(elements, cmp_fn);
    for (unsigned int heap_size = elements.size() - 1; heap_size > 0; --heap_size) {
        std::swap(elements[0], elements[heap_size]);
        heapify(elements, 0, heap_size - 1, cmp_fn);
    }
}

void sort_binary_array(std::vector<bool> &numbers);

void sort_array_with_0_1_2(std::vector<unsigned short> &numbers);
void sort_array_with_0_1_2_V2(std::vector<unsigned short> &numbers);

#endif //ALGORITHMSWORKBENCH_SORTING_ALGORITHMS_HPP
