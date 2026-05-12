class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string firstString = strs[0];

        string longestPrefix = "";
        for(int i = 0; i < firstString.length(); i++) {
            longestPrefix = firstString.substr(0,i+1);
            bool flag = false;
            for(int j = 1; j < strs.size(); j++) {
                size_t found = strs[j].find(longestPrefix);
                if(found == string::npos) {
                    flag = true;
                    break;
                } else {
                    int realIndex = static_cast<int>(found);
                    if(realIndex != 0 ) {
                        flag = true;
                        break;
                    }
                }
            }
            if(flag == true) {
                return firstString.substr(0,i);
            }
        }
        return longestPrefix;
    }
};