#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include "string_algorithms.hpp"

std::vector<std::vector<std::string>> group_anagrams(
        const std::vector<std::string> &input)
{
    std::vector<std::vector<std::string>> output;
    std::unordered_map<std::string, std::vector<std::string>> anagrams;

    for (const std::string &str : input) {
        std::string sorted_str = str;
        std::sort(sorted_str.begin(), sorted_str.end());
        anagrams[sorted_str].push_back(str);
    }

    for (const std::pair<std::string, std::vector<std::string>> &kv : anagrams) {
        output.push_back(kv.second);
    }

    return output;
}

unsigned int get_match_score(const std::string &pref1, const std::string &pref2)
{
    unsigned int score = 0;
    if (pref1.length() != pref2.length()) {
        return 0;
    }

    for (size_t i = 0; i < pref1.length(); ++i) {
        if (pref1[i] == pref2[i]) {
            ++score;
        }
    }

    return score;
}

std::string make_match(const std::vector<std::string> &women_names,
                       const std::vector<std::string> &women_prefs,
                       const std::vector<std::string> &men_names,
                       const std::vector<std::string> &men_prefs,
                       const std::string &match_for)
{
    std::map<std::string, std::string> women;
    for (size_t i = 0; i < women_names.size(); ++i) {
        women[women_names[i]] = women_prefs[i];
    }

    std::unordered_map<std::string, std::string> men;
    for (size_t i = 0; i < men_names.size(); ++i) {
        men[men_names[i]] = men_prefs[i];
    }

    for (const std::pair<std::string, std::string> &woman : women) {
        std::string best_match = "undefined";
        unsigned int match_score = 0;

        for (const std::pair<std::string, std::string> &man : men) {
            unsigned int score = get_match_score(woman.second, man.second);
            if (score > match_score) {
                match_score = score;
                best_match = man.first;
            } else if (score == match_score) {
                if (man.first < best_match) {
                    best_match = man.first;
                }
            }
        }

        if (match_for == woman.first) {
            return best_match;
        }

        men.erase(best_match);
    }

    return "undefined";
}

std::string new_member_username(const std::vector<std::string> &existing_names,
                                const std::string &new_name)
{
    std::unordered_map<std::string, bool> names;
    for (const std::string &name : existing_names) {
        names[name] = true;
    }

    unsigned int index = 0;
    std::string query = new_name;
    while (1) {
        if (names.find(query) == names.end()) {
            return query;
        }

        query = new_name + std::to_string(++index);
    }
}

unsigned int count_letters_digits_from(const std::string &str)
{
    unsigned int count = 0;
    for (char c : str) {
        if (isalnum(c)) {
            ++count;
        }
    }

    return count;
}

unsigned int count_lowercase_letters_from(const std::string &str)
{
    unsigned int count = 0;
    for (const char c : str) {
        if (islower(c)) {
            ++count;
        }
    }

    return count;
}

std::string string_letter_count(const std::string &str)
{
    std::string result;

    std::map<char, int> count_map;
    for (const char c : str) {
        if (!isalpha(c)) {
            continue;
        }

        char curr = tolower(c);

        if (count_map.find(curr) == count_map.end()) {
            count_map[curr] = 1;
        } else {
            count_map[curr] = count_map[curr] + 1;
        }
    }

    for (const std::pair<char, int> &p : count_map) {
        result = result + std::to_string(p.second) + p.first;
    }

    return result;
}
