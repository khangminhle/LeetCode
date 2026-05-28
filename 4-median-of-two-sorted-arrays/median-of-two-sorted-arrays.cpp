class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if(m > n) {
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
            int temp1 = m;
            m = n;
            n = temp1;
        }

        if(m == 0) {
            nums1.push_back(INT_MIN);
            nums1.push_back(INT_MAX);
        }

        m = nums1.size();

        // An Odd, Even amount of elements
        int division = (m+n+1) / 2;

        int left = 0;
        int right = m;

        while(left <= right) {

            int mid = (left+right)/2;
            int mid2 = division-mid;

            int L1, R1, L2, R2;

            if(mid == 0) {
                L1 = INT_MIN;
                R1 = nums1[0];
            } else {
                if(mid == m) {
                    L1 = nums1[mid-1];
                    R1 = INT_MAX;
                } else {
                    L1 = nums1[mid-1];
                    R1 = nums1[mid];
                }
            }

            if(mid2 == 0) {
                L2 = INT_MIN;
                R2 = nums2[0];

            } else {
                if(mid2 == n) {
                    L2 = nums2[mid2-1];
    
                    R2 = INT_MAX;
                } else {
                    L2 = nums2[mid2-1];
                    R2 = nums2[mid2];
                }
            }

            if(L1 > R2) {
                right = mid-1;
            }

            if(L2 > R1) {
                left = mid+1;
            }

            /*
            cout<<"L1: "<<L1<<endl;
            cout<<"R1: "<<R1<<endl;
            cout<<"L2: "<<L2<<endl;
            cout<<"R2: "<<R2<<endl;
            */
            
            if(L1 <= R2 && L2 <= R1) {
                if((m+n) % 2 == 0) {
                    //cout<<"Da tim ra median:"<<max(L1, L2)<<" "<<min(R1, R2)<<endl;
                    //cout<<max(L1, L2)<<" "<<min(R1, R2)<<endl;
                    return (max(L1,L2) + min(R1, R2)) / 2.0;
                } else {
                    return max(L1, L2);
                }
                break;
            }
        }

        return 0.0;

    }
};