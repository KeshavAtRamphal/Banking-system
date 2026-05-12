#include <iostream>
#include <fstream>
#include <cstring>
#include "BankSystem.h"

using namespace std;
// Creates empty file if missing

void createFileIfMissing(const char fileName[]){
    ifstream testFile(fileName, ios::binary);
    if (!testFile)
    {
        ofstream createFile(fileName, ios::binary);
        createFile.close();
    }
    testFile.close();
}

// Seeds system with default tellers and branches
void seedSystem()
{
    createFileIfMissing(CUSTOMERS_FILE);
    createFileIfMissing(TRANSACTIONS_FILE);

    Teller tellers[3] = {};
    safeCopy(tellers[0].tellerID, "T001");
    safeCopy(tellers[0].tellerName, "Keshav Admin");
    safeCopy(tellers[0].tellerPassWord, xorDataEncryption("Keshav123"));
    safeCopy(tellers[0].branchCode, "Durban03");

    safeCopy(tellers[1].tellerID, "T002");
    safeCopy(tellers[1].tellerName, "Jozi Teller");
    safeCopy(tellers[1].tellerPassWord, xorDataEncryption("Jozi123"));
    safeCopy(tellers[1].branchCode, "Jozi06");

    safeCopy(tellers[2].tellerID, "T003");
    safeCopy(tellers[2].tellerName, "Cape Teller");
    safeCopy(tellers[2].tellerPassWord, xorDataEncryption("Cape123"));
    safeCopy(tellers[2].branchCode, "Cape01");

    ofstream tellerfile(TELLERS_FILE, ios::binary);
    tellerfile.write((char *)tellers, sizeof(tellers));
    tellerfile.close();

    Branch branches[3] = {};
    safeCopy(branches[0].branchCode, "Durban03");
    safeCopy(branches[0].branchName, "Durban North");
    safeCopy(branches[0].city, "Durban");

    safeCopy(branches[1].branchCode, "Jozi06");
    safeCopy(branches[1].branchName, "Joburg CBD");
    safeCopy(branches[1].city, "Johannesburg");

    safeCopy(branches[2].branchCode, "Cape01");
    safeCopy(branches[2].branchName, "Cape Town City");
    safeCopy(branches[2].city, "Cape Town");

    ofstream branchFile(BRANCHES_FILE, ios::binary);
    branchFile.write((char *)branches, sizeof(branches));
    branchFile.close();

    ifstream checkConfig(CONFIG_FILE);
    if (!checkConfig)
    {
        ofstream configFile(CONFIG_FILE);
        configFile << "BANK_NAME=Standard Bank Richfield" << endl;
        configFile << "VERSION=1.0" << endl;
        configFile << "MAINTENANCE_MODE=OFF" << endl;
        configFile << "MAX_LOGIN_ATTEMPTS=3" << endl;
        configFile << "DEFAULT_INTEREST_SAVINGS=0.05" << endl;
        configFile << "DEFAULT_INTEREST_CHEQUE=0.02" << endl;
        configFile << "DEFAULT_INTEREST_FIXED_DEPOSIT=0.08" << endl;
        configFile.close();
    }
    checkConfig.close();
    cout << "System seeded successfully." << endl;
}