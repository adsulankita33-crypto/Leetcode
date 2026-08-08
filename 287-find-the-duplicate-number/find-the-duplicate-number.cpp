class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(n+1,0);
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        int duplicate=-1;
        for(int i=0;i<n;i++){
            if(freq[i]>1){
                duplicate=i;
            }
        }
        return duplicate;
    }
};