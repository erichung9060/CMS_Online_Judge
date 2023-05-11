#include <bits/stdc++.h>
using namespace std;
#define PASSWORD_LENTH 6

const char chr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                    'A', 'B', 'C', 'D', 'E', 'F', 'G',
                    'H', 'I', 'J', 'K', 'L', 'M', 'N',
                    'O', 'P', 'Q', 'R', 'S', 'T',
                    'U', 'V', 'W', 'X', 'Y', 'Z',
                    'a', 'b', 'c', 'd', 'e', 'f', 'g',
                    'h', 'i', 'j', 'k', 'l', 'm', 'n',
                    'o', 'p', 'q', 'r', 's', 't',
                    'u', 'v', 'w', 'x', 'y', 'z'};

string Generate_Password() {
    string password;
    for (int i = 0; i < PASSWORD_LENTH; i++) {
        int idx = rand() % 62;
        password += chr[idx];
    }
    return password;
}

/*
    Output:

    users:
      - username: "team1"
        password: "dssinsdnds"
        first_name: "TeamName"
*/

int main() {
    srand(time(0));

    ifstream TeamnameFile("teamname.txt");
    ofstream PasswordFile("password.txt");
    ofstream SettingFile("contest.user.yaml");

    string teamname;
    int User_Idx = 1;
    while (getline(TeamnameFile, teamname)) {
        string password = Generate_Password();
        PasswordFile << password << '\n';
        SettingFile << "  - username: \"team" << setw(3) << setfill('0') << User_Idx << "\"\n";
        SettingFile << "    password: \"" << password << "\"\n";
        SettingFile << "    first_name: \"" << teamname << "\"\n";
        User_Idx++;
    }
    TeamnameFile.close();
    PasswordFile.close();
    SettingFile.close();
}
