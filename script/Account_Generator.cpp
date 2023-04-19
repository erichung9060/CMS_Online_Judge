#include <bits/stdc++.h>
using namespace std;
#define all(a) begin(a), end(a)
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair

const char chr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                    'A', 'B', 'C', 'D', 'E', 'F', 'G',
                    'H', 'I', 'J', 'K', 'L', 'M', 'N',
                    'O', 'P', 'Q', 'R', 'S', 'T',
                    'U', 'V', 'W', 'X', 'Y', 'Z',
                    'a', 'b', 'c', 'd', 'e', 'f', 'g',
                    'h', 'i', 'j', 'k', 'l', 'm', 'n',
                    'o', 'p', 'q', 'r', 's', 't',
                    'u', 'v', 'w', 'x', 'y', 'z'};

string genPass() {
    string password;
    for (int i = 0; i < 6; i++) {
        int idx = rand() % 62;
        password.pb(chr[idx]);
    }
    return password;
}

int main() {
    srand(time(NULL));
    /*
    users:
      - username: "team1"
        password: "dssinsdnds"
        first_name: "TeamName"
    */
    ifstream TeamnameFile("teamname.txt");
    ofstream PasswordFile("password.txt");
    ofstream SettingFile("context.yaml");

    for (int i = 1; i <= 200; i++) {
        string password = genPass();
        string teamname;
        getline(TeamnameFile,teamname);

        PasswordFile << password << '\n';
        SettingFile << "  - username: \"team" << setw(3) << setfill('0') << i << "\"\n";
        SettingFile << "    password: \"" << password << "\"\n";
        SettingFile << "    first_name: \"" << teamname << "\"\n";
    }
    TeamnameFile.close();
    PasswordFile.close();
    SettingFile.close();
}

// g++ gen.cpp && ./a.out && rm a.out
