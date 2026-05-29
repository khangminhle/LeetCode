 
class Solution {
public:
    int longestPalindrome(string s) {

        int n = s.size();
        unordered_map<char, int> hm;

        for(int i = 0; i < n; i++) {
            if(hm.count(s[i]) > 0) {
                hm[s[i]] += 1;
            } else {
                hm[s[i]] = 1;
            }
        }

        int longest = 0;
        bool flag = false;
        for (const auto& i: hm) {
            cout<<i.first<<" "<<i.second<<endl;
            if((i.second % 2) == 0) {
                longest += i.second;
                continue;
            }

            // Odd number
            longest += (i.second)-1;
            flag = true;
        }

        if(flag) {
            longest += 1;
        }
        

        //cout<<"Longest: "<<longest<<endl;
        //cout<<"n:"<<n<<endl;
        return longest;
    }
};