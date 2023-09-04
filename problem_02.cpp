#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c) {
    if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U') {
        return true;
    }
    return false;
}

int main() {

    string s = "Munmun is the student of Computer Science & Engineering";

    int len = s.size();
    int no_of_vowel = 0, no_of_consonants = 0;
    set < char > vowels, consonants;
    for(int i = 0; i < len; i++) {
        if(i+1 < len and (s[i] == ' ' and s[i+1] == ' ')) continue;
        if(is_vowel(s[i])) {
            no_of_vowel += 1;
            vowels.insert(s[i]);
        } else if((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= 'A' and s[i] <= 'Z')) {
            no_of_consonants += 1;
            consonants.insert(s[i]);
        }
    }

    cout << "No. of Vowels: " << no_of_vowel << endl;
    cout << "No. of Consonants: " << no_of_consonants << endl;

    cout << "Existed vowels are: ";
    for(auto i : vowels) {
        cout << i << " ";
    } cout << endl;

    cout << "Existed consonants are: ";
    for(auto i : consonants) {
        cout << i << " ";
    } cout << endl;


    return 0;

}
