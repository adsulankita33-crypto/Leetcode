
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> arr;

        for(int i = 0; i < nums.size(); i++) {
            arr.push_back(1LL * nums[i] * nums[i]);
        }

        sort(arr.begin(), arr.end());

        long long score = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            if(i < (n + 1) / 2) {
                score += arr[n - 1 - i];
            }
            else {
                score -= arr[n - 1 - i];
            }
        }

        return score;
    }
};