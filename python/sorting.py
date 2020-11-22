import copy
import random


def get_random_numbers(start, end, count):
    ret = []
    for _ in range(0, count):
        ret.append(random.randint(start, end))

    return ret


def insertion_sort(numbers):
    for i in range(1, len(numbers)):
        current = numbers[i]
        j = i - 1
        while j >= 0 and numbers[j] > current:
            numbers[j + 1] = numbers[j]
            j -= 1

        numbers[j + 1] = current

    return numbers


def selection_sort(numbers):
    for i in range(0, len(numbers)):
        min_index = i
        for j in range(i + 1, len(numbers)):
            if numbers[j] < numbers[min_index]:
                min_index = j

        numbers[i], numbers[min_index] = numbers[min_index], numbers[i]

    return numbers


def bubble_sort(numbers):
    for i in range(0, len(numbers)):
        for j in range(i + 1, len(numbers)):
            if numbers[i] > numbers[j]:
                numbers[i], numbers[j] = numbers[j], numbers[i]

    return numbers


def merge(numbers, start, mid, end):
    a = numbers[start:mid+1]
    b = numbers[mid+1:end+1]

    insert_index = start
    a_index = b_index = 0
    while a_index < len(a) and b_index < len(b):
        if a[a_index] < b[b_index]:
            numbers[insert_index] = a[a_index]
            a_index += 1
        else:
            numbers[insert_index] = b[b_index]
            b_index += 1
        insert_index += 1

    while a_index < len(a):
        numbers[insert_index] = a[a_index]
        a_index += 1
        insert_index += 1

    while b_index < len(b):
        numbers[insert_index] = b[b_index]
        b_index += 1
        insert_index += 1


def merge_sort_helper(numbers, start, end):
    if start >= end:
        return

    mid = int(((end - start) / 2)) + start
    merge_sort_helper(numbers, start, mid)
    merge_sort_helper(numbers, mid + 1, end)
    merge(numbers, start, mid, end)


def merge_sort(numbers):
    merge_sort_helper(numbers, 0, len(numbers) - 1)
    return numbers


if __name__ == "__main__":
    numbers = get_random_numbers(0, 100, 10)

    print("===== Testing Insertion Sort =====")
    input = copy.deepcopy(numbers)
    sorted_output = insertion_sort(input)
    assert(sorted_output == sorted(numbers))
    print("** Done Testing Insertion Sort **")

    print("===== Testing Selection Sort =====")
    input = copy.deepcopy(numbers)
    sorted_output = selection_sort(input)
    assert(sorted_output == sorted(numbers))
    print("** Done Testing Selection Sort **")

    print("===== Testing Bubble Sort =====")
    input = copy.deepcopy(numbers)
    sorted_output = bubble_sort(input)
    assert(sorted_output == sorted(numbers))
    print("** Done Testing Bubble Sort **")

    print("===== Testing Merge Sort =====")
    input = copy.deepcopy(numbers)
    sorted_output = merge_sort(input)
    assert(sorted_output == sorted(numbers))
    print("** Done Testing Merge Sort **")
