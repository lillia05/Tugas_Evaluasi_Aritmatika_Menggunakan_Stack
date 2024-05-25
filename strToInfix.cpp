#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> strToInfix(string& inputString) {
    vector<string> expression;
    string num = "";
    int n = inputString.length();

    for (int i = 0; i < n; ++i) {
        char current = inputString[i];
        
        if (isdigit(current) || (current == '-' && (i == 0 || inputString[i - 1] == '('))) {
            num += current;
            while (i + 1 < n && isdigit(inputString[i + 1])) {
                num += inputString[++i];
            }
            expression.push_back(num);
            num = "";
        } else if (current == '+' || current == '-' || current == '*' ||
                   current == '/' || current == '%' || current == '(' || current == ')') {
            expression.push_back(string(1, current));
        }
    }
    return expression;
}

vector<string> handleNegative(vector<string>& expression) {
    vector<string> result;
    int n = expression.size();

    for (int i = 0; i < n; ++i) {
        if (expression[i] == "-" && (i == 0 || expression[i - 1] == "(" || 
                                     expression[i - 1] == "+" || expression[i - 1] == "-" || 
                                     expression[i - 1] == "*" || expression[i - 1] == "/" || 
                                     expression[i - 1] == "%")) {
            result.push_back("-1");
            result.push_back("*");
        } else {
            result.push_back(expression[i]);
        }
    }

    return result;
}

void printExpression(vector<string>& expression) {
    for (auto& token : expression) {
        cout << token << " ";
    }
    cout << endl;
}

int main() {
    string inputString;
    getline(cin, inputString);

    vector<string> expression = strToInfix(inputString);
    vector<string> finalExpression = handleNegative(expression);
    printExpression(finalExpression);

    return 0;
}
