// @Mehedi-Hasan-Shakil
/*
Write a program to generate a FOLLOW set and parsing table using the following LL(1) 
grammar and FIRST set: 
Grammar      FIRST set 
E -> TE'     {id, (} 
E'-> +TE'|@  {+, @} 
T -> FT'     {id, (} 
T'-> *FT'|@  {*, @}
F -> (E)|id  {id, (} 
*/
#include <bits/stdc++.h>
using namespace std;

map<char, vector<string>> grammar;
map<pair<char, char>, string> table;
map<char, set<char>> first;
map<char, set<char>> follow;
vector<char> order;

void calculate_follow() {
    // Follow calculation
    follow[order[0]].insert('$');
    for(char target : order) { // Follow to be calculated for target
        for(char c : order) { // Check each production rule if the target is present at rightside
            for(auto str : grammar[c]) {
                bool stop = false;
                int j = 0;
                for(int i = 0; i < str.size(); i++) {
                    if(str[i] == target) {
                        for(j = i + 1; j < str.size(); j++) {
                            if(str[j] < 'A' || str[j] > 'Z') { // if it is a terminal then stop
                                follow[target].insert(str[j]);
                                stop = true;
                                break;
                            }
                            else {
                                for(char f : first[str[j]]) {
                                    if(f != '@') follow[target].insert(f);
                                }
                                if(first[str[j]].find('@') == first[str[j]].end()) {
                                    stop = true; // if the non-terminal doesn't contain epsilo(@), then stop
                                    break;
                                }
                            }
                        }
                    }
                    if(stop) // current production has completed
                        break;
                }
                if(j == str.size()) { // if we reach at the end of the production
                    for(char f : follow[c]) { // push the follow of the left hand side
                        follow[target].insert(f);
                    }
                }
            }
        }
    }
}

int main() {
    order = {'E', 'P', 'T', 'Q', 'F'};
    grammar['E'] = {"TP"};
    grammar['P'] = {"+TP", "@"};
    grammar['T'] = {"FQ"};
    grammar['Q'] = {"*FQ", "@"};
    grammar['F'] = {"(E)", "i"};
    first['E'] = {'(', 'i'};
    first['P'] = {'+', '@'};
    first['T'] = {'(', 'i'};
    first['Q'] = {'*', '@'};
    first['F'] = {'(', 'i'};
    // Print grammar
    cout << "_____Grammar_____\n";
    for(auto c : order) {
        cout<<c<<" -> ";
        for(auto x : grammar[c]) {
            cout<<x<<" | ";
        }
        cout<<"\n";
    }
    // Print first
    cout<<"_____First_____\n";
    for(char c : order) {
        cout<<c<<" = {";
        for(auto x : first[c]) {
            cout<<x<<", ";
        }
        cout<<"}\n";
    }
    // Follow calculation
    calculate_follow();
    //Print Follow
    cout<<"_____Follow_____\n";
    for(char c : order) {
        cout<<c<<" = {";
        for(auto x : follow[c]) {
            cout<<x<<", ";
        }
        cout<<"}\n";
    }
    // Table formation
    for(char row : order) {
        for(char col : first[row]) {
            if(col != '@') {
                bool isSet = false;
                for(auto str : grammar[row]) {
                    if(str[0] == col) {
                        table[{row, col}] = string(1, row) + "->" + str;
                        isSet = true;
                    }
                }
                if(!isSet)
                    table[{row, col}] = string(1, row) + "->" + grammar[row][0];
            }
        }
        if(first[row].find('@') != first[row].end()) {
            for(char col : follow[row]) {
                table[{row, col}] = string(1, row) + "->@";
            }
        }
    }
    // Print table
    cout<<"_____Parse Table_____\n";
    vector<char> column = {'i', '+', '*', '(', ')', '$'};
    for(char c : column) cout<<setw(8)<<c; cout<<"\n";
    for(char row : order) {
        cout<<row<<"    ";
        for(char col : column) {
            if(!table[{row, col}].empty())
                cout<<left<<setw(8)<<table[{row, col}];
            else
                cout<<"        ";
        }
        cout<<"\n";
    }
}
