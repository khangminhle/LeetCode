class Solution {
public:
    int findMinGreater(vector<int> &arr, int x) {
        int n = arr.size();
        int left = 0;
        int right = n-1;
        int pos = -1;

        while(left <= right) {
            int mid = (left+right)/2;

            if(arr[mid] > x) {
                pos = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }

        return pos;
    }
    int numMatchingSubseq(string s, vector<string>& words) {

        unordered_map<char, vector<int>> hmap;
        unordered_map<char, int> imap;

        int n = s.size();

        for(int i = 0; i < n; i++) {
            hmap[s[i]].push_back(i);
            imap[s[i]] = 0;
        }

        int result = 0;

        int m = words.size();

        for(int i = 0; i < m; i++) {
            string word = words[i];
            int l = word.size();

            bool flag = true;
            int index = -1;
            for(int j = 0; j < l; j++) {
                if(hmap.count(word[j]) == 0) {
                    flag = false;
                    break;
                }

                int k = findMinGreater(hmap[word[j]], index);

                //cout<<"word: "<<word<<endl;
                //cout<<"index: "<<index<<endl;
                //cout<<"k: "<<k<<endl;


                if(k == -1) {
                    flag = false;
                    break;
                } else {
                    index = hmap[word[j]][k];
                }

            }

            if(flag) {
                result += 1;
                //cout<<"word: "<<word<<endl;
            }
        }

        cout<<result<<endl;

        return result;
    }
};