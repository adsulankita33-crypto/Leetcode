class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        // Find indices of minimum and maximum
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIndex])
                minIndex = i;

            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        // Both from front
        int option1 = right + 1;

        // Both from back
        int option2 = n - left;

        // One from front, one from back
        int option3 = (left + 1) + (n - right);

        return min({option1, option2, option3});
    }
};