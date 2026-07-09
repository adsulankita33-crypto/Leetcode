class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        int left=0;int right=height.size()-1;
        while(left<right){
            int widht=right-left;
            int ht=min(height[left],height[right]);
            int area=widht*ht;
            maxArea=max(area,maxArea);
        
        if(height[left]<height[right]){
            left++;
        }
        else{
            right--;
        }
        }
        return maxArea;
    }
};