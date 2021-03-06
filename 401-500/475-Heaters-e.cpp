// Winter is coming! Your first job during the contest is to design a standard
// heater with fixed warm radius to warm all the houses.

// Now, you are given positions of houses and heaters on a horizontal line, find
// out minimum radius of heaters so that all houses could be covered by those
// heaters.

// So, your input will be the positions of houses and heaters seperately, and
// your expected output will be the minimum radius standard of heaters.

// Note:
// Numbers of houses and heaters you are given are non-negative and will not
// exceed 25000. Positions of houses and heaters you are given are non-negative
// and will not exceed 10^9. As long as a house is in the heaters' warm radius
// range, it can be warmed. All the heaters follow your radius standard and the
// warm radius will the same.

// Example 1: Input: [1,2,3],[2] Output: 1
// Explanation: The only heater was placed in the position 2, and if we use the
// radius 1 standard, then all the houses can be warmed.

// Example 2: Input: [1,2,3,4],[1,4] Output: 1
// Explanation: The two heater was placed in the position 1 and 4. We need to
// use radius 1 standard, then all the houses can be warmed.

// binary search
class Solution {
  public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        if (houses.empty())
            return 0;
        if (heaters.empty())
            return INT_MAX; // maximun possible value

        sort(heaters.begin(), heaters.end());

        int r = 0;

        for (auto &&ho : houses) {
            auto ht_iter = lower_bound(heaters.begin(), heaters.end(), ho);

            int r1 = ht_iter != heaters.end() ? *ht_iter - ho : INT_MAX;
            int r2 = ht_iter != heaters.begin() ? ho - *prev(ht_iter) : INT_MAX;

            r = max(r, min(r1, r2));
        }

        return r;
    }
};

class Solution {
  public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        if (houses.empty())
            return 0;

        if (heaters.empty())
            return INT_MAX; // maximun possible value

        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int r = 0, i = 0, j = 0;

        while (i < houses.size() && j < heaters.size()) {
            int temp_r1 = abs(houses[i] - heaters[j]);
            int temp_r2 = j + 1 < heaters.size()
                              ? abs(houses[i] - heaters[j + 1])
                              : INT_MAX;

            if (temp_r1 <= r)
                ++i;
            else if (temp_r2 <= r) {
                ++i;
                ++j;
            } else if (temp_r2 <= temp_r1)
                ++j; // next heater be closer to houses[i]
            else
                r = temp_r1; // curent min radius
        }

        return r;
    }
};