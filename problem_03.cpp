#include <bits/stdc++.h>

using namespace std;

int main() {
    
    cout << "Enter the Course code: ";
    string code;
    cin >> code;

    map < string, string > departments;
    departments.insert({"CSE", "Computer Science & Engineering"});
    departments.insert({"EEE", "Electircal & Electronic Engineering"});
    departments.insert({"ICE", "Information & Communication Engineering"});
    departments.insert({"Chem", "Chemistry"});
    departments.insert({"Math", "Mathematics"});

    string dept = "";
    dept += code[0];
    dept += code[1];
    dept += code[2];

    map < char, string > year;
    year.insert({'1', "1st Year"});
    year.insert({'2', "2nd Year"});
    year.insert({'3', "3rd Year"});
    year.insert({'4', "4th Year"});

    map < char, string > semester;
    semester.insert({'1', "1st Semester"});
    semester.insert({'2', "2nd Semester"});

    map < char, string > course;
    course.insert({'1', "Software Engineering"});
    course.insert({'2', "Database Management Systems"});
    course.insert({'3', "Web Engineering"});
    course.insert({'4', "Compiler Design"});
    course.insert({'5', "Engineering Ethics"});
    course.insert({'6', "Communication Engineering"});
    course.insert({'6', "Mobile Application Development"});

    map < char, string > type;
    type.insert({'1', "Therory"});
    type.insert({'2', "Lab"});

    cout << departments[dept] << ", " << year[code[4]] << ", " << semester[code[5]] << ", " << course[code[6]] << ", " << type[code[7]] << endl;

    return 0;
}
