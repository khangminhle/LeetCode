class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        vector<int> stack;
        int result = 0;
        for(int i = 0; i < n; i++) {

            if(tokens[i] == "+" ) {
                int firstNumber = stack.back();
                stack.pop_back();
                int secondNumber = stack.back();
                stack.pop_back();
                int sum = secondNumber + firstNumber;
                stack.push_back(sum);
                continue;
            }

            if(tokens[i] == "-") {
                int firstNumber = stack.back();
                stack.pop_back();
                int secondNumber = stack.back();
                stack.pop_back();
                int substraction = secondNumber - firstNumber;
                stack.push_back(substraction);
                continue;
            }

            if(tokens[i] == "*") {
                int firstNumber = stack.back();
                stack.pop_back();
                int secondNumber = stack.back();
                stack.pop_back();
                int multiplication = secondNumber * firstNumber;
                stack.push_back(multiplication);
                continue;
            }

            if(tokens[i] == "/") {
                int firstNumber = stack.back();
                stack.pop_back();
                int secondNumber = stack.back();
                stack.pop_back();
                int division = secondNumber / firstNumber;
                stack.push_back(division);
                continue;
            }

            stack.push_back(stoi(tokens[i]));
        }

        return stack.back();
    }
};