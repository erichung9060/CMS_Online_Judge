#include <bits/stdc++.h>
using namespace std;

// ＊Important＊ Check if the same team name exist for different teams.

#define AUTO_GENERATE_ACCOUNT
#define AUTO_GENERATE_TEAMNAME

#if defined(AUTO_GENERATE_ACCOUNT) && defined(AUTO_GENERATE_TEAMNAME)
    #define ACCOUNT_NUMBER 10
#endif

#define AccountPrefix "account"
#define TeamnamePrefix "team"

#define PASSWORD_LENTH 6
const char chr[] = {'2', '3', '4', '5', '6', '7', '8', '9',
                    'A', 'B', 'C', 'D', 'E', 'F', 'G',
                    'H', 'J', 'K', 'L', 'M', 'N',
                    'P', 'Q', 'R', 'S', 'T',
                    'U', 'V', 'W', 'X', 'Y', 'Z',
                    'a', 'b', 'c', 'd', 'e', 'f', 'g',
                    'h', 'i', 'j', 'k', 'm', 'n',
                    'p', 'q', 'r', 's', 't',
                    'u', 'v', 'w', 'x', 'y', 'z'};

string Generate_Password() {
    string password;
    int sz = sizeof(chr);
    for (int i = 0; i < PASSWORD_LENTH; i++) {
        int idx = rand() % sz;
        password += chr[idx];
    }
    return password;
}

string Generate_Account(int idx) {
    stringstream account;
    account << AccountPrefix << setw(3) << setfill('0') << idx;
    return account.str();
}

string Generate_Teamname(int idx) {
    stringstream teamname;
    teamname << TeamnamePrefix << setw(3) << setfill('0') << idx;
    return teamname.str();
}

int main() {
    srand(time(0));
    map<string, pair<string, string> > team;
    ofstream PasswordFile("password.txt");
    ofstream SettingFile("contest.user.yaml");
#ifdef AUTO_GENERATE_ACCOUNT
        ofstream AccountFile("account.txt");
#else
        ifstream AccountFile("account.txt");
#endif
#ifdef AUTO_GENERATE_TEAMNAME
        ofstream TeamnameFile("teamname.txt");
#else
        ifstream TeamnameFile("teamname.txt");
#endif

    string teamname, account, password;
    int Account_Idx = 1;

#if defined(AUTO_GENERATE_TEAMNAME) && defined(AUTO_GENERATE_ACCOUNT)
    while(Account_Idx <= ACCOUNT_NUMBER){
        teamname = Generate_Teamname(Account_Idx);
        account = Generate_Account(Account_Idx);
#elif !defined(AUTO_GENERATE_ACCOUNT) && !defined(AUTO_GENERATE_TEAMNAME)
    while (getline(AccountFile, account)) {
           getline(TeamnameFile, teamname);
#elif defined(AUTO_GENERATE_ACCOUNT) && !defined(AUTO_GENERATE_TEAMNAME)
    while (getline(TeamnameFile, teamname)) {
           account = Generate_Account(Account_Idx);
#elif !defined(AUTO_GENERATE_ACCOUNT) && defined(AUTO_GENERATE_TEAMNAME)
    while (getline(AccountFile, account)) {
           teamname = Generate_Teamname(Account_Idx);
#endif

        password = Generate_Password();
        
        SettingFile << "  - username: \"" << account << "\"\n";
        SettingFile << "    password: \"" << password << "\"\n";
        SettingFile << "    first_name: \"" << teamname << "\"\n";

#ifdef AUTO_GENERATE_ACCOUNT
        AccountFile << account << "\n";
#endif
#ifdef AUTO_GENERATE_TEAMNAME
        TeamnameFile << teamname << "\n";
#endif
        PasswordFile << password << "\n";

        Account_Idx++;
    }
    TeamnameFile.close();
    PasswordFile.close();
    AccountFile.close();
    SettingFile.close();
}

/*
    cms username:    account
    cms password:    password
    cms first_name:  teamname
*/
