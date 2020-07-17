#include "catch.hpp"
#include "string_algorithms.hpp"

TEST_CASE("group_anagrams() tests", "[group_anagram() tests]")
{
    SECTION("group_anagrams() tests") {
        std::vector<std::string> input = {
                "eat", "tea", "tan", "ate", "nat", "bat"
        };
        std::vector<std::vector<std::string>> output;
        output = group_anagrams(input);

        std::vector<std::string> v1 = {"bat"};
        std::vector<std::string> v2 = {"tan", "nat"};
        std::vector<std::string> v3 = {"eat", "tea", "ate"};

        REQUIRE(output.size() == 3);
    }
}

TEST_CASE("make_match() tests", "[make_match() tests]")
{
    SECTION("make_match() tests") {
        std::vector<std::string> women_names;
        std::vector<std::string> women_prefs;

        std::vector<std::string> men_names;
        std::vector<std::string> men_prefs;

        std::string match_for;

        women_names = {"Constance", "Bertha", "Alice"};
        women_prefs = {"aaba", "baab", "aaaa"};

        men_names = {"Chip", "Biff", "Abe"};
        men_prefs = {"bbaa", "baaa", "aaab"};

        match_for = "Bertha";
        REQUIRE(make_match(women_names, women_prefs, men_names, men_prefs, match_for) == "Biff");
        match_for = "Constance";
        REQUIRE(make_match(women_names, women_prefs, men_names, men_prefs, match_for) == "Chip");

        women_names = {"Constance", "Alice", "Bertha", "Delilah", "Emily"};
        women_prefs = {"baabaa", "ababab", "aaabbb", "bababa", "baabba"};

        men_names = {"Ed", "Duff", "Chip", "Abe", "Biff"};
        men_prefs = {"aabaab", "babbab", "bbbaaa", "abbbba", "abaaba"};

        match_for = "Constance";
        REQUIRE(make_match(women_names, women_prefs, men_names, men_prefs, match_for) == "Duff");
        match_for = "Delilah";
        REQUIRE(make_match(women_names, women_prefs, men_names, men_prefs, match_for) == "Chip");
        match_for = "Emily";
        REQUIRE(make_match(women_names, women_prefs, men_names, men_prefs, match_for) == "Ed");

        women_names = {"F", "M", "S", "h", "q", "g", "r", "N", "U", "x", "H", "P",
                       "o", "E", "R", "z", "L", "m", "e", "u", "K", "A", "w", "Q",
                       "O", "v", "j", "a", "t", "p", "C", "G", "k", "c", "V", "B",
                       "D", "s", "n", "i", "f", "T", "I", "l", "d", "J", "y", "b"};
        women_prefs = {"abaabbbb", "bbaabbbb", "aaabaaab", "aabbaaaa", "baabbaab",
                       "aaababba", "bbabbbbb", "bbbabbba", "aaabbbba", "aabbbaaa",
                       "abbabaaa", "babbabbb", "aaaaabba", "aaaabbaa", "abbbabaa",
                       "babababa", "abbaaaaa", "bbababba", "baaaaaba", "baaaaabb",
                       "bbbbabba", "ababbaaa", "abbbabab", "baabbbaa", "bbbaabbb",
                       "aababbab", "ababbabb", "abbaabba", "baabbabb", "aaabaaab",
                       "aabbbaba", "aabaaabb", "abababba", "aabbaaaa", "aabbabaa",
                       "bababaaa", "aabaaaab", "bbbbaabb", "baaababb", "abaabbab",
                       "aabbbaaa", "baabbaba", "bbabbbaa", "aabbbbaa", "abbbaaab",
                       "abababbb", "ababaaba", "bababaaa"};

        men_names = {"f", "C", "v", "g", "Q", "z", "n", "c", "B", "o", "M", "F",
                     "u", "x", "I", "T", "K", "L", "E", "U", "w", "A", "d", "t",
                     "e", "R", "D", "s", "p", "q", "m", "r", "H", "j", "J", "V",
                     "l", "a", "k", "h", "G", "y", "i", "P", "O", "N", "b", "S"};
        men_prefs = {"bbbaabab", "bbabaabb", "ababbbbb", "bbbababb", "baababaa",
                     "bbaaabab", "abbabbaa", "bbbabbbb", "aabbabab", "abbababa",
                     "aababbbb", "bababaab", "aaababbb", "baabbaba", "abaaaaab",
                     "bbaababa", "babaabab", "abbabbba", "ababbbab", "baabbbab",
                     "babbaaab", "abbbbaba", "bbabbbba", "baaabaab", "ababbabb",
                     "abbbaabb", "bbbbaabb", "bbbaaabb", "baabbaba", "bbabaaab",
                     "aabbbaab", "abbbbabb", "bbaaaaba", "bbbababa", "abbaabba",
                     "bababbbb", "aabaaabb", "babbabab", "baaaabaa", "ababbaba",
                     "aaabaabb", "bbaaabaa", "baaaaabb", "bbaabaab", "bbababab",
                     "aabaaaab", "aaaaabab", "aabbaaba"};

        match_for = "U";
        REQUIRE(make_match(women_names, women_prefs, men_names, men_prefs, match_for) == "x");

        women_names = {"q", "M", "w", "y", "p", "N", "s", "r", "a", "H", "o", "n",
                       "F", "m", "l", "b", "D", "j", "C", "u", "f", "I", "g", "L",
                       "i", "x", "A", "G", "O", "k", "h", "d", "c", "E", "B", "v",
                       "J", "z", "K", "e", "t"};
        women_prefs = {"aabbaaabb", "baabababb", "bbaababba", "bbbaaaaaa", "abaaaabaa",
                       "bababbbab", "abbaabbaa", "aabababbb", "bababaaaa", "abbababaa",
                       "aabbbbbba", "bbabbabab", "babaabbba", "babbabbbb", "baaabbbbb",
                       "baaabaaaa", "aaabbaaab", "abbaabbbb", "abbabbbab", "bbaaaabba",
                       "babbaaabb", "aabbabbab", "baaababba", "ababaabab", "bbbaabbab",
                       "aaaabbabb", "babaaaaaa", "abbbbaaab", "aabaaabba", "bbbaaaaba",
                       "bbbbbbaab", "aabbaaabb", "aabaabbab", "aababaaba", "bbabbbbab",
                       "abbabaaab", "babaaabbb", "bababbaaa", "aabbaabaa", "baaabbabb",
                       "bbbbbbbbb"};

        men_names = {"m", "k", "n", "q", "L", "E", "M", "l", "w", "x", "g", "e",
                     "i", "z", "F", "r", "a", "h", "f", "D", "J", "K", "j", "v",
                     "A", "t", "N", "y", "s", "c", "o", "p", "d", "b", "B", "G",
                     "O", "I", "u", "C", "H"};
        men_prefs = {"bbaaabbba", "bbaaaaaab", "abaaababb", "baaaabbbb", "abbbababa",
                     "baaaaaaaa", "aabbbbbab", "aaaaabbba", "baabababb", "babaaabab",
                     "baaababaa", "bbbbaabba", "bbaabbabb", "bbaaababb", "abbabbaba",
                     "aababaaab", "abbbbbbaa", "aabbaabaa", "bbbaabbba", "abbabbaba",
                     "aaabbbaaa", "bbaabaaaa", "aabababbb", "abbbbabab", "baaabbbba",
                     "bababbbba", "aababbaab", "bbaabbaab", "bbbaaabbb", "babbbbabb",
                     "ababababb", "babaaabab", "bbaaaaaba", "aaaaabaaa", "abbaaabbb",
                     "bbbbababb", "baabababb", "bbaabaaaa", "aaababbbb", "abbbbbbba",
                     "bbaabbaaa"};

        match_for = "o";
        REQUIRE(make_match(women_names, women_prefs, men_names, men_prefs, match_for) == "C");
    }
}

TEST_CASE("new_member_username() tests", "[new_member_username() tests]")
{
    SECTION("new_member_username() tests") {
        std::vector<std::string> existing_names;
        std::string new_name;

        existing_names = {"MasterOfDisaster", "DingBat", "Orpheus", "WolfMan", "MrKnowItAll"};
        new_name = "TygerTyger";
        REQUIRE(new_member_username(existing_names, new_name) == "TygerTyger");

        existing_names = {"MasterOfDisaster", "TygerTyger1", "DingBat", "Orpheus",
                          "TygerTyger", "WolfMan", "MrKnowItAll"};
        new_name = "TygerTyger";
        REQUIRE(new_member_username(existing_names, new_name) == "TygerTyger2");

        existing_names = {"TygerTyger2000", "TygerTyger1", "MasterDisaster", "DingBat",
                          "Orpheus", "WolfMan", "MrKnowItAll"};
        new_name = "TygerTyger";
        REQUIRE(new_member_username(existing_names, new_name) == "TygerTyger");

        existing_names = {"grokster2", "BrownEyedBoy", "Yoop", "BlueEyedGirl",
                          "grokster", "Elemental", "NightShade", "Grokster1"};
        new_name = "grokster";
        REQUIRE(new_member_username(existing_names, new_name) == "grokster1");

        existing_names = {"Bart4", "Bart5", "Bart6", "Bart7", "Bart8", "Bart9", "Bart10",
                          "Lisa", "Marge", "Homer", "Bart", "Bart1", "Bart2", "Bart3",
                          "Bart11", "Bart12"};
        new_name = "Bart";
        REQUIRE(new_member_username(existing_names, new_name) == "Bart13");
    }
}

TEST_CASE("count_letters_digits_from() tests", "[count_letters_digits_from() tests]")
{
    SECTION("count_letters_digits_from() tests") {
        std::string str;

        str = "hel2!lo";
        REQUIRE(count_letters_digits_from(str) == 6);

        str = "wicked .. !";
        REQUIRE(count_letters_digits_from(str) == 6);

        str = "!?..A";
        REQUIRE(count_letters_digits_from(str) == 1);

        str = "!?...";
        REQUIRE(count_letters_digits_from(str) == 0);

        str = "hello";
        REQUIRE(count_letters_digits_from(str) == 5);

        str = "";
        REQUIRE(count_letters_digits_from(str) == 0);
    }
}

TEST_CASE("count_lowercase_letters_from() tests", "[count_lowercase_letters_from() tests]")
{
    SECTION("count_lowercase_letters_from() tests") {
        std::string str;

        str = "abc";
        REQUIRE(count_lowercase_letters_from(str) == 3);

        str = "abcABC123";
        REQUIRE(count_lowercase_letters_from(str) == 3);

        str = "abcABC123!@€£#$%^&*()_-+=}{[]|\\':;?/>.<,~";
        REQUIRE(count_lowercase_letters_from(str) == 3);

        str = "";
        REQUIRE(count_lowercase_letters_from(str) == 0);

        str = "ABC123!@€£#$%^&*()_-+=}{[]|\\':;?/>.<,~";
        REQUIRE(count_lowercase_letters_from(str) == 0);

        str = "abcdefghijklmnopqrstuvwxyz";
        REQUIRE(count_lowercase_letters_from(str) == 26);
    }
}

TEST_CASE("string_letter_count() tests", "[string_letter_count() tests]")
{
    SECTION("string_letter_count() tests") {
        std::string str;

        str = "This is a test sentence.";
        REQUIRE(string_letter_count(str) == "1a1c4e1h2i2n4s4t");

        str = "";
        REQUIRE(string_letter_count(str) == "");

        str = "555";
        REQUIRE(string_letter_count(str) == "");

        str = "aaaaaaaaaa";
        REQUIRE(string_letter_count(str) == "10a");
    }
}
