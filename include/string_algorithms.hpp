#ifndef ALGORITHMSWORKBENCH_STRING_ALGORITHMS_HPP
#define ALGORITHMSWORKBENCH_STRING_ALGORITHMS_HPP

#include <vector>

// https://leetcode.com/problems/group-anagrams/
std::vector<std::vector<std::string>> group_anagrams(
        const std::vector<std::string> &input);

// https://community.topcoder.com/stat?c=problem_statement&pm=2911&rd=5849
std::string make_match(const std::vector<std::string> &women_names,
        const std::vector<std::string> &women_prefs,
        const std::vector<std::string> &men_names,
        const std::vector<std::string> &men_prefs,
        const std::string &match_for);

// https://community.topcoder.com/stat?c=problem_statement&pm=2913&rd=5849
std::string new_member_username(const std::vector<std::string> &existing_names,
        const std::string &new_name);

// https://www.codewars.com/kata/5738f5ea9545204cec000155
unsigned int count_letters_digits_from(const std::string &str);

// https://www.codewars.com/kata/56a946cd7bd95ccab2000055
unsigned int count_lowercase_letters_from(const std::string &str);

// https://www.codewars.com/kata/59e19a747905df23cb000024
std::string string_letter_count(const std::string &str);

#endif //ALGORITHMSWORKBENCH_STRING_ALGORITHMS_HPP
