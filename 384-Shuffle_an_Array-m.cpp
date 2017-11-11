// Shuffle a set of numbers without duplicates.
// Example:
// // Init an array with set 1, 2, and 3.
// int[] nums = {1,2,3};
// Solution solution = new Solution(nums);
// // Shuffle the array [1,2,3] and return its result. Any permutation of
// [1,2,3] must equally likely to be returned. solution.shuffle();
// // Resets the array back to its original configuration [1,2,3].
// solution.reset();
// // Returns the random shuffling of array [1,2,3].
// solution.shuffle();

class Solution {
  public:
    Solution(vector<int> nums) : ns(nums) {
        u = uniform_int_distribution<unsigned>(0, nums.size() - 1);
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() { return ns; }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ret(ns);
        for (int i = 0; i < ns.size(); ++i)
            swap(ret[i], ret[u(e)]);
        return ret;
    }

  private:
    vector<int> ns;
    default_random_engine e;
    uniform_int_distribution<unsigned> u;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */