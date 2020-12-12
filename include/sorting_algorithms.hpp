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

template<typename T>
void heapify_subtree(std::vector<T> &elements,
                     unsigned int index,
                     unsigned int heap_size,
                     std::function<bool(T, T)> heap_fn)
{
    unsigned current_index = index;
    while (1) {
        unsigned int replace_index = current_index;
        unsigned int left_index = 2 * current_index + 1;
        unsigned int right_index = 2* current_index + 2;

        if (left_index < heap_size &&
            heap_fn(elements[left_index], elements[replace_index])) {
            replace_index = left_index;
        }
        if (right_index < heap_size &&
            heap_fn(elements[right_index], elements[replace_index])) {
            replace_index = right_index;
        }

        if (replace_index == current_index) {
            break;
        }

        std::swap(elements[current_index], elements[replace_index]);
        current_index = replace_index;
    }
}

template<typename T>
void make_heap(std::vector<T> &elements,
               std::function<bool(T, T)> heap_fn)
{
    int last_non_leaf_index = (elements.size() / 2) - 1;
    for (int i = last_non_leaf_index; i >= 0; --i) {
        heapify_subtree(elements, i, elements.size(), heap_fn);
    }
}

template<typename T, typename F>
void heap_sort(std::vector<T> &elements, F cmp_fn)
{
    // Heap function is the reverse of the comparison function
    std::function<bool(T, T)> heap_fn = [cmp_fn](T left, T right) {
        return cmp_fn(right, left);
    };
    make_heap(elements, heap_fn);
    for (unsigned int heap_size = elements.size(); heap_size > 0; --heap_size) {
        std::swap(elements[0], elements[heap_size - 1]);
        heapify_subtree(elements, 0, heap_size - 1, heap_fn);
    }
}

void sort_binary_array(std::vector<bool> &numbers);

void sort_array_with_0_1_2(std::vector<unsigned short> &numbers);
void sort_array_with_0_1_2_V2(std::vector<unsigned short> &numbers);

#endif //ALGORITHMSWORKBENCH_SORTING_ALGORITHMS_HPP
