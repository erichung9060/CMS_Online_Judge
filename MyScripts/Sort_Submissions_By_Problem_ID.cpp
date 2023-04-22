#include <bits/stdc++.h>
using namespace std;
#define TEAM_NUMBER 200
#define MIN_PROBLEM_ID 'A'
#define MAX_PROBLEM_ID 'H'

int main() {
    for(char i=MIN_PROBLEM_ID;i<=MAX_PROBLEM_ID;i++){
        filesystem::create_directory("p"+string(1,i));
    }
    for (int i = 1; i <= TEAM_NUMBER; i++) {
        string TeamName = "team" + string(3 - to_string(i).length(), '0') + to_string(i);
        for (const auto& entry1 : filesystem::directory_iterator(TeamName)) {
            ifstream file(entry1.path());
            string s, line;

            for (int i = 0; i < 5; i++) {
                getline(file, line);
                s += line;
            }

            if (s.find(".%l") == string::npos) {
                cout << "fail on " << entry1.path() << '\n';
                return 1;
            }
            file.close();

            string problem_ID = "p" + string(1, s[s.find(".%l") - 1]);
            string NewName = string(entry1.path()).substr(8) + "_" + TeamName;
            filesystem::copy(entry1.path(), problem_ID + "/" +NewName);
        }
    }
    cout << "Successful\n";
}
