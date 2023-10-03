#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    // cout << "Enter a string: ";
    string str;
    getline(cin, str);

    string word = "";

    for (char c : str) {
        bool flag = true;
        if (c != ' ') {
            word.push_back(c);
        }
        else {
            if (word.size() >= 4 && !isdigit(word[0])) {
                if (((word.substr(0, 3) == "ch_") || (word.substr(0, 3) == "bn_")) && isalnum(word[3])) {
                    for (int i = 4; i < word.size(); i++) {
                        if (!isalnum(word[i])) {
                            cout << word << " : "
                                 << "Invalid Input or Undefined\n";
                            word = "";
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                            if(word.substr(0, 3) == "ch_") cout << word << " : " << "Character variable\n";
                            else cout << word << " : " << "Binary variable\n";
                            word = "";
                        }
                }
                else {
                cout << word << " : "<< "Invalid Input or Undefined\n";
                word = "";
            }
            }
            else if(word.size() >= 2 && word[0] == '0' && (word[1] == '0' || word[1] == '1')) {
                for(int i = 2; word.size(); i++) {
                    if(word[i] != '0' && word[i] != '1') {
                        cout << word << " : "
                                 << "Invalid Input or Undefined\n";
                            word = "";
                            flag = false;
                            break;
                    }
                }
                if (flag) {
                    cout << word << " : "<< "Binary Number\n";
                    word = "";
                }
            }
            else {
                cout << word << " : "<< "Invalid Input or Undefined\n";
                word = "";
            }
        }
    }

    return 0;
}
