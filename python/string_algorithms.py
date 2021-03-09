def get_strings_count1(strings):
    str_count = {}
    for str in strings:
        if str_count.get(str, None) == None:
            str_count[str] = 1
        else:
            str_count[str] = str_count[str] + 1

    return str_count


def get_strings_count2(strings):
    str_count = {}
    sorted_strings = sorted(strings)
    i = 0
    while i < len(sorted_strings):
        begin = end = i
        while end < len(sorted_strings) and sorted_strings[begin] == sorted_strings[end]:
            end = end + 1

        str_count[sorted_strings[begin]] = end - begin
        i = end

    return str_count

if __name__ == "__main__":
    strings = [ "Alice", "Cody", "Cody", "Zak", "Zak", "Bob", "Charlie", "Dominic", "Charlie", "Zak" ]
    print("===== Testing get_strings_count1 =====")
    counts = get_strings_count1(strings)
    assert(len(counts) == 6)
    assert(counts["Alice"] == 1)
    assert(counts["Bob"] == 1)
    assert(counts["Cody"] == 2)
    assert(counts["Charlie"] == 2)
    assert(counts["Dominic"] == 1)
    assert(counts["Zak"] == 3)
    print("** Done Testing get_strings_count1 **")
    print("===== Testing get_strings_count2 =====")
    counts = get_strings_count2(strings)
    assert(len(counts) == 6)
    assert(counts["Alice"] == 1)
    assert(counts["Bob"] == 1)
    assert(counts["Cody"] == 2)
    assert(counts["Charlie"] == 2)
    assert(counts["Dominic"] == 1)
    assert(counts["Zak"] == 3)
    print("** Done Testing get_strings_count2 **")
