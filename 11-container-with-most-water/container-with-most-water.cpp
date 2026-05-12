class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxarea = 0;
        while(left < right){
            
            int min = -1;
            int area = right-left;
                                                            if(height[right]>=height[left]){
                                                                min = height[left];                                                                                            left+=1;
} else {
    min = height[right];
    right-=1;}
    area = area*min;
    if(area > maxarea){maxarea=area;}
        }     
        return maxarea;
    }
};