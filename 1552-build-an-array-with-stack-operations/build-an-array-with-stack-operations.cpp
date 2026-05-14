class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        vector<int> hash(n+1, 0);

        int m = target.size();
        int maxNumber = target[m-1];
        for(int i = 0; i < m; i++) {
            hash[target[i]] = 1;
        }

        for(int i = 0; i < n; i++) {
            int number = i+1;

            if(number > maxNumber) {
                break;
            }

            if(hash[number] == 1) {
                result.push_back("Push");
            } else {
                result.push_back("Push");
                result.push_back("Pop");
            }
        }

        return result;
    }
};