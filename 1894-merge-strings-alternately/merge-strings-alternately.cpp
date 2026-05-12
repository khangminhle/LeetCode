class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // Check string length of word1 and word2
        int maxLength = 0;
        int minLength = 0;
        string mergedStr = "";
        if(word1.length() >= word2.length()) {
            maxLength = word1.length();
            minLength = word2.length();

            for(int i = 0; i < minLength; i++) {
                mergedStr += word1[i];
                mergedStr += word2[i];
            }

            for(int i = minLength; i < maxLength; i++) {
                mergedStr += word1[i];
            }
        } else {
            maxLength = word2.length();
            minLength = word1.length();

            for(int i = 0; i < minLength; i++) {
                mergedStr += word1[i];
                mergedStr += word2[i];
            }

            for(int i = minLength; i < maxLength; i++) {
                mergedStr += word2[i];
            }
        }

        return mergedStr;
    }
};