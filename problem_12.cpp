
#include <bits/stdc++.h>

using namespace std;

bool isOperator(char ch) {
    return (ch == '+' or ch == '*' or ch == '-' or ch == '/');
}

bool operatorCheck(string syntax) {
    int n = syntax.size() - 1;
    if (isOperator(syntax[0])) {
        return false;
    }
    if (isOperator(syntax[n])) {
        return false;
    }
    for (int i = 1; syntax[i]; i++) {
        if (isOperator(syntax[i])) {
            if (isOperator(syntax[i - 1])) {
                return false;
            }
            if (syntax[i - 1] == '(') {
                return false;
            }
        }
        if (isOperator(syntax[i - 1])) {
            if (syntax[i] == ')') {
                return false;
            }
        }
        if(syntax[i-1] == '(' and syntax[i] == ')' ) return false;
    }
    return true;
}

bool bracketCheck(string syntax) {
    stack<char> brackets;
    for (int i = 0; syntax[i]; i++) {
        if (syntax[i] == '(')
            brackets.push('(');
        else if (syntax[i] == ')') {
            if (brackets.size())
                brackets.pop();
            else
                return false;
        }
    }
    if (brackets.size() == 0)
        return true;
    else
        return false;
}

bool isValidIdentifier(string str) {
    // Check if the string is not empty and the first character is a letter or underscore
    if (str.empty() or !(isalpha(str[0]) or str[0] == '_')) {
        return false;
    }

    // Check the rest of the characters
    for (char c : str) {
        if (!(isalnum(c) or c == '_')) {
            return false;
        }
    }

    // Check if it is not a C++ keyword
    static const string keywords[] = {
        "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor",
        "bool", "break", "case", "catch", "char", "char8_t", "char16_t", "char32_t",
        "class", "compl", "concept", "const", "consteval", "constexpr", "const_cast",
        "continue", "co_await", "co_return", "co_yield", "decltype", "default", "delete",
        "do", "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern",
        "false", "float", "for", "friend", "goto", "if", "inline", "int", "long",
        "mutable", "namespace", "new", "noexcept", "not", "not_eq", "nullptr", "operator",
        "or", "or_eq", "private", "protected", "public", "register", "reinterpret_cast",
        "requires", "return", "short", "signed", "sizeof", "static", "static_assert",
        "static_cast", "struct", "switch", "template", "this", "thread_local", "throw",
        "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using",
        "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"
    };

    for (string keyword : keywords) {
        if (str == keyword) {
            return false;
        }
    }

    return true;
}


int main()
{
    freopen("12.txt", "r", stdin);
    string syntax;
    while(getline(cin, syntax)) {

        if(isValidIdentifier(syntax)) {
            cout << syntax << " : Valid id" << endl;
        } else if (bracketCheck(syntax) and operatorCheck(syntax)) {
            cout << syntax << " : Valid\n";
        } else {
            cout << syntax << " : Invalid\n";
        }
    }

    return 0;
}
