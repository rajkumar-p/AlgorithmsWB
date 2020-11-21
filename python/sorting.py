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
