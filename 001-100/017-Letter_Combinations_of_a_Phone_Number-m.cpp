// Given a digit string, return all possible letter combinations that the number
// could represent.
// A mapping of digit to letters (just like on the telephone buttons) is given
// below.
// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:
// Although the above answer is in lexicographical order, your answer could be
// in any order you want.

class Solution {
  public:
    vector<string> letterCombinations(string digits) {
        // valid input range from 2-9
        vector<vector<char>> table = {{'a', 'b', 'c'}, {'d', 'e', 'f'},
                                      {'g', 'h', 'i'}, {'j', 'k', 'l'},
                                      {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
                                      {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        vector<string> result(1); // initialize with 1 empty string
        for (auto &digit : digits) {
            // note: char compare here
            if (digit < '2' || digit > '9')
                return vector<string>();
            // number of chars of current digit
            int numChars = table[digit - '2'].size();
            int resSize = result.size();
            result.reserve(numChars * resSize);
            // concatenate result itself to its end several times
            // eg: {a, b} becomes {a, b, a, b}
            for (int i = 0; i < numChars - 1; ++i)
                copy_n(result.begin(), resSize, back_inserter(result));
            // add new chars in each string's end
            // eg: {a, b} becomes {ac, bc, ad, bd}
            for (int i = 0; i < numChars; ++i)
                for (int j = 0; j < resSize; ++j)
                    result[j + i * resSize] += table[digit - '2'][i];
        }
        return result.size() > 2 ? result : vector<string>();
    }
};