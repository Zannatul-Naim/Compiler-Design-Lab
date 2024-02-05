// @Mehedi-Hasan-Shakil
/*
Write a program to generate FIRST and FOLLOW sets using a given CFG.
*/
#include <bits/stdc++.h>
using namespace std;

map<char, vector<string>> grammar;
map<char, set<char>> first;
map<char, set<char>> follow;
vector<char> order; // order of the grammar

int main() {
    freopen("13.txt", "r", stdin);
    string production;
    while (getline(cin, production))
    {
        grammar[production[0]].push_back(production.substr(3));
        if(find(order.begin(), order.end(), production[0]) == order.end())
            order.push_back(production[0]);
    }
    // Print grammar
    cout << "_____Grammar_____\n";
    for(auto c : order) {
        cout<<c<<" -> ";
        for(auto x : grammar[c]) {
            cout<<x<<" | ";
        }
        cout<<"\n";
    }
    // First calculation
    for(int i = order.size()-1; i >= 0; i--) { // Calculation in reverse order
        for(auto x : grammar[order[i]]) { // Take each string of the production
            for(int j = 0; j < x.size(); j++) {
                if(x[j] < 'A' || x[j] > 'Z') { // Check the terminal E->+TP
                    first[order[i]].insert(x[j]);
                    break;
                }
                else {
                    for(auto f : first[x[j]]) first[order[i]].insert(f); // E->ABC : insert all first of A
                    if(first[x[j]].find('@') == first[x[j]].end()) break; // if A contains @ goto B
                }
            }
        }
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
                                    stop = true; // if the non-terminal doesn't contain epsilon(@), then stop
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
    //Print Follow
    cout<<"_____Follow_____\n";
    for(char c : order) {
        cout<<c<<" = {";
        for(auto x : follow[c]) {
            cout<<x<<", ";
        }
        cout<<"}\n";
    }
}
