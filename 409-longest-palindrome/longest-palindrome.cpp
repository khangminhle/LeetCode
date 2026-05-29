class Solution {
public:
    int longestPalindrome(string s) {

        int n = s.size();
        unordered_map<char, int> hm;

        int count = 0;

        for(int i = 0; i < n; i++) {
            cout<<hm[s[i]]<<endl;

            hm[s[i]] += 1;

            if((hm[s[i]] % 2) == 0) {
                count += 2;
            }
        }

        for(int i = 0; i < n; i++) {
            if(hm[s[i]] % 2 != 0) {
                return count + 1;
            }
        }

        return count;
    }
};