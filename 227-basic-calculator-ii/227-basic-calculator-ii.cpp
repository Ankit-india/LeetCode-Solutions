class Solution {
public:
    int calculate(string s) {
        stack<int> equation;
        istringstream iss(s);

        int value;
        char op = '+';
        while (iss >> value) {
            if (op == '+') {
                equation.push(value);
            } 
            else if (op == '-') {
                equation.push(-value);
            } 
            else {
                int prev = equation.top();
                equation.pop();
                if (op == '*') {
                    prev = prev * value;
                } 
                else {
                    prev = prev / value;
                }
                equation.push(prev);
            }

            iss >> op;
        }

        int sum = 0;
        while (!equation.empty()) {
            sum += equation.top();
            equation.pop();
        }

        return sum;

    }
};