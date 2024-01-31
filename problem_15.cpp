#include<bits/stdc++.h>

using namespace std;

bool solve(string input, map<pair<char, char>, string>&table) {
    stack<pair<int, char>>stk;
    stk.push({0, 'E'});

    int space = 0;

    for(int i = 0; i < input.size(); i++) {
        while(stk.top().second != input[i] and stk.top().second != '#') {
            pair<int, char> front = stk.top();

            if(table[{front.second, input[i]}] == "") {
                return false;
            }

            for(int i = 0; i < front.first; i++) cout << " ";
            cout << front.second << "--->" << table[{front.second, input[i]}] << endl;
            space = front.first+5;
            stk.pop();
            string right_side = table[{front.second, input[i]}];
            reverse(right_side.begin(), right_side.end());
            for(char ch : right_side) {
                stk.push({space, ch});
            }
        }

        if(stk.top().second == input[i]) {
            stk.pop();
        }
        if(stk.top().second == '#') {
            stk.pop();
            i -= 1;
        }
    }

    while(!stk.empty()) {
        for(int i = 0; i < stk.top().first; i++) cout << " ";
        cout << stk.top().second << "--->" << "#" << endl;
        stk.pop();
    }
}

int main() {

    string input;
    getline(cin, input);

    map<pair<char, char>, string>table;

    table[make_pair('E', 'i')] = "TP"; // here E_prime = P
    table[make_pair('E', '(')] = "TP";
    table[make_pair('P', '+')] = "+TP";
    table[make_pair('P', ')')] = "#";
    table[make_pair('P', '$')] = "#";
    table[make_pair('T', 'i')] = "FQ"; // here T_prime = Q
    table[make_pair('T', '(')] = "FQ";
    table[make_pair('Q', '+')] = "#";
    table[make_pair('Q', ')')] = "#";
    table[make_pair('Q', '$')] = "#";
    table[make_pair('Q', '*')] = "*FQ";
    table[make_pair('F', 'i')] = "i";
    table[make_pair('F', '(')] = "(E)";


    if(solve(input, table)) {
        cout << "\n\nAccepted!\n\n";
    } else {
        cout << "\n\nRejected!\n\n";
    }

    return 0;

}
