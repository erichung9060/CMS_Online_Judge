#include <bits/stdc++.h>
using namespace std;
#define TEAM_NUMBER 200
#define MIN_PROBLEM_ID 'A'
#define MAX_PROBLEM_ID 'H'
int main() {
    for (int i = 1; i <= TEAM_NUMBER; i++) {
        string foldername1 = "team" + string(3 - to_string(i).length(), '0') + to_string(i);
        for (const auto& entry1 : filesystem::directory_iterator(foldername1)) {
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
            char p = s[s.find(".%l") - 1];
            rename(entry1.path(), string(entry1.path()) + "_p" + string(1, p));
        }
    }
    cout << "Successful\n";
}
