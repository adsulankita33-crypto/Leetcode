
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = nums[0];
        int sum = 0;

        // Find maximum element
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > maxi) {
                maxi = nums[i];
            }
        }

        // Calculate total moves
        for(int i = 0; i < nums.size(); i++) {
            sum = sum + (maxi - nums[i]);
        }

        return sum;
    }
};
