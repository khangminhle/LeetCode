class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int i = digits.size()-1;

        bool flag = false;
        while(i >= 0) {

            if(digits[i] < 9) {
                digits[i] += 1;
                flag = true;
                break;
            }

            if(digits[i] == 9) {
                digits[i] = 0;
            }

            i--;
        }

        if(flag == false) {
            digits.insert(digits.begin(), 1);
        }
        //show(digits);

        return digits;  
    }
};