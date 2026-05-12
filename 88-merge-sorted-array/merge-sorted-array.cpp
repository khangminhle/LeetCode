class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0; i < n; i++) {
            nums1[m+i] = nums2[i];
        }

            //Sort Array

        for(int i = 1; i < nums1.size(); i++) {
            int key = nums1[i];

            int j = i;

            while(j > 0) {
                if(key > nums1[j-1]) {
                    break;
                }

                nums1[j] = nums1[j-1];
                j--;
            }

            nums1[j] = key;
        }
    }
};