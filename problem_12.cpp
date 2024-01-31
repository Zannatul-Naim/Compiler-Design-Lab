#include<bits/stdc++.h>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isIdentifierOrInteger(const string& str) {
    if (str.empty()) return false;
    if(isdigit(str[0])) return false;
    if (!isalpha(str[0]) and str[0] != '_') return false;
    for (char c : str) {
        if (!isalnum(c) and c != '_') return false;
    }
    return true;
}

bool isIdentifier(string s) {
   
   if(!isalpha(s[0]) and s[0] != '_' ) return false;
   for(char ch : s) {
    if(!isalnum(ch) and ch != '_') return false;
   } return true;

}

bool isInteger(string s) {
    for(char ch : s) {
        if(!isdigit(ch)) return false;
    } return true;
}

stack<char>bracket;
bool isValidExpression(string s) {
    int i = 0; 

    while(i < s.size()) {
        if(s[i] == '(') {
            bracket.push(s[i]);
        } else if(s[i] == ')') {
            if(bracket.empty()) return false;
            else bracket.pop();
        } else if(isOperator(s[i])) {
            if(i+1 < s.size() and isOperator(s[i+1])) return false;
            else {}
        } else {
            string id = "";
            while(i < s.size() and !isOperator(s[i]) and s[i] != '(' and s[i] != ')') {
                id += s[i];
                i++;
            } i--;
            // cout << id << " ";
            if(!isIdentifier(id) and !isInteger(id)) return false;
        }
        i++;
    }
    return true;
}

int main() {

    string expression;
    freopen("12.txt", "r", stdin);

    while(getline(cin, expression)) {
        // cout << expression << endl;
        if (isValidExpression(expression)) {
            cout << "\nVALID\n";
        } else {
            cout << "\nINVALID\n";
        }
    }

    return 0;
}
