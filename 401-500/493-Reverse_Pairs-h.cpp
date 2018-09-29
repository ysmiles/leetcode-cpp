// Given an array nums, we call (i, j) an important reverse pair if i < j and
// nums[i] > 2*nums[j].

// You need to return the number of important reverse pairs in the given array.

// Example1:

// Input: [1,3,2,3,1]
// Output: 2
// Example2:

// Input: [2,4,3,5,1]
// Output: 3
// Note:
// The length of the given array will not exceed 50,000.
// All the numbers in the input array are in the range of 32-bit integer.

// TODO: self implemented inplace_merge
class Solution {
    int sort_cnt(auto b, auto e) {
        if (e - b <= 1)
            return 0;

        auto mid = b + (e - b) / 2;

        int cnt = sort_cnt(b, mid) + sort_cnt(mid, e);
        for (auto i = b, j = mid; i != mid; ++i) {
            while (j != e && *i > 2LL * *j)
                ++j;
            cnt += j - mid;
        }

        inplace_merge(b, mid, e);

        return cnt;
    }

  public:
    int reversePairs(vector<int> &nums) {
        return sort_cnt(nums.begin(), nums.end());
    }
};