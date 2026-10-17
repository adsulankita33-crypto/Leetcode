class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while(n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for(int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end(), [&](auto a, auto b) {
            int sum1 = digitSum(a.first);
            int sum2 = digitSum(b.first);

            if(sum1 == sum2) {
                return a.first < b.first;
            }

            return sum1 < sum2;
        });

        vector<int> visited(n, 0);
        int swaps = 0;

        for(int i = 0; i < n; i++) {
            if(visited[i] || arr[i].second == i) {
                continue;
            }

            int cycleSize = 0;
            int j = i;

            while(!visited[j]) {
                visited[j] = 1;
                j = arr[j].second;
                cycleSize++;
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
};