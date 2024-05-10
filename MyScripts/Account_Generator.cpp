#include <bits/stdc++.h>
using namespace std;
#define AUTO_GENERATE_TEAM_NAME
#define AUTO_GENERATE_ACCOUNT

#ifdef AUTO_GENERATE_TEAM_NAME
    #define TEAM_NUMBER 10
#endif

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
    ofstream SettingFile("contest.user.yaml");
#ifdef AUTO_GENERATE_ACCOUNT
        ofstream AccountFile("account.txt");
#else
        ifstream AccountFile("account.txt");
#endif

    string prev_teamname, teamname, account, password;
    int Team_Idx = 1;

#ifdef AUTO_GENERATE_TEAM_NAME
    while(Team_Idx < TEAM_NUMBER){
        teamname = Generate_Account(Team_Idx);
#else
    while (getline(TeamnameFile, teamname)) {
#endif
        if(teamname == prev_teamname) {
#ifdef AUTO_GENERATE_ACCOUNT
            AccountFile << account << "\n";
#endif
            PasswordFile << password << "\n";
            continue;
        }
#ifdef AUTO_GENERATE_ACCOUNT
        account = Generate_Account(Team_Idx);
#else
        getline(AccountFile, account);
#endif
        password = Generate_Password();
        
        SettingFile << "  - username: \"" << account << "\"\n";
        SettingFile << "    password: \"" << password << "\"\n";
        SettingFile << "    first_name: \"" << teamname << "\"\n";
#ifdef AUTO_GENERATE_ACCOUNT
        AccountFile << account << "\n";
#endif
        PasswordFile << password << "\n";
        Team_Idx++;
        
        prev_teamname = teamname;
    }
    TeamnameFile.close();
    PasswordFile.close();
    AccountFile.close();
    SettingFile.close();
}
