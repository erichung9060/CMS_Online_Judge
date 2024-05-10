#include <bits/stdc++.h>
using namespace std;
// #define ANNOYMOUS_TEAM_NUMBER 10

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

string Generate_Account(int idx) {
    stringstream account;
    account << "team" << setw(3) << setfill('0') << idx;
    return account.str();
}

int main() {
    srand(time(0));
    map<string, pair<string, string> > team;
    ifstream TeamnameFile("teamname.txt");
    ofstream PasswordFile("password.txt");
    ofstream AccountFile("account.txt");
    ofstream SettingFile("contest.user.yaml");

    string prev_teamname, teamname, account, password;
    int Team_Idx = 1;

#ifdef ANNOYMOUS_TEAM_NUMBER
    while(Team_Idx < ANNOYMOUS_TEAM_NUMBER){
    teamname = Generate_Account(Team_Idx);
#else
    while (getline(TeamnameFile, teamname)) {
#endif
        if(teamname == prev_teamname) {
            AccountFile << account << "\n";
            PasswordFile << password << "\n";
            continue;
        }
        account = Generate_Account(Team_Idx);
        password = Generate_Password();
        
        SettingFile << "  - username: \"" << account << "\"\n";
        SettingFile << "    password: \"" << password << "\"\n";
        SettingFile << "    first_name: \"" << teamname << "\"\n";
        AccountFile << account << "\n";
        PasswordFile << password << "\n";
        Team_Idx++;
        
        prev_teamname = teamname;
    }
    TeamnameFile.close();
    PasswordFile.close();
    AccountFile.close();
    SettingFile.close();
}
