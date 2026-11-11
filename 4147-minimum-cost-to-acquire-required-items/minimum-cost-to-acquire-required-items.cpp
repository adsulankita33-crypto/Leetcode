
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {
        
        long long common = min(need1, need2);

        // Option 1: Buy common requirements using type 3 items
        long long ans1 = common * costBoth
                       + (need1 - common) * 1LL * cost1
                       + (need2 - common) * 1LL * cost2;

        // Option 2: Buy only type 3 items for all requirements
        long long ans2 = max(need1, need2) * 1LL * costBoth;

        // Option 3: Buy all items separately
        long long ans3 = need1 * 1LL * cost1
                       + need2 * 1LL * cost2;

        return min({ans1, ans2, ans3});
    }
};
