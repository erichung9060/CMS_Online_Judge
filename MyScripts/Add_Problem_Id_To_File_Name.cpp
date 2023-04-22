#include <bits/stdc++.h>
using namespace std;
#define TEAM_NUMBER 200

int main() {
    for (int i = 1; i <= TEAM_NUMBER; i++) {
        string foldername1 = "team" + string(3 - to_string(i).length(), '0') + to_string(i);
        for (const auto& entry1 : filesystem::directory_iterator(foldername1)) {
            ifstream file(entry1.path());
            string s;
            file >> s;
            char p;
            for (int j = 0; j < s.length(); j++) {
                if (s[j] == 'p') {
                    if (j + 1 >= s.length()) {
                        cout << "fail on " << entry1.path() << '\n';
                        return 1;
                    }
                    p = s[j + 1];
                    break;
                }
            }
            file.close();
            rename(entry1.path(),string(entry1.path())+"_p"+string(1,p));
        }
    }
    cout << "Successful\n";
}
