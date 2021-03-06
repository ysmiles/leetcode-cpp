// Given a string, determine if it is a palindrome, considering only
// alphanumeric characters and ignoring cases.
// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.
// Note:
// Have you consider that the string might be empty? This is a good question to
// ask during an interview.
// For the purpose of this problem, we define empty string as valid palindrome.

class Solution {
  public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        auto isalphanum = [](char &c) { return isalpha(c) || isdigit(c); };
        while (i < j) {
            if (!isalphanum(s[i])) {
                ++i;
                continue;
            }
            if (!isalphanum(s[j])) {
                --j;
                continue;
            }
            if (s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
};