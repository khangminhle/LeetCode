class Solution {
public:
    bool isNumber(string a) {

        if(a.size() > 1) {
            return true;
        }



        switch(a[0]) {
            case '+':
                return false;
            case '-':
                return false;
            case '*':
                return false;
            case '/':
                return false;
            default:
                return true;
        }
    }

    int operate(int num1, int num2, string a) {

        if(a.size() > 1) {
            return INT_MIN;
        }

        cout<<"Dang operate: "<<num1<<a<<num2<<endl;
        switch(a[0]) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                return num1 / num2;
            default:
                return INT_MIN;
        }
    }
    
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        vector<int> stack;
        for(int i = 0; i < n; i++) {

            if(isNumber(tokens[i])) {
                stack.push_back(stoi(tokens[i]));
            } else {
                if(stack.size() > 1) {
                    int firstNumber = stack.back();
                    stack.pop_back();
                    int secondNumber = stack.back();
                    stack.pop_back();
                    int newNumber = operate(secondNumber, firstNumber, tokens[i]);
                    stack.push_back(newNumber);
                }
            }

        }
        return stack.back();
    }
};