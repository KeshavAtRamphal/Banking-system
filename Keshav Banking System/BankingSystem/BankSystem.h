#ifndef BANKINGSYSTEMFILE_BANKSYSTEM_H
#define BANKINGSYSTEMFILE_BANKSYSTEM_H

#include <fstream>
#include <ctime>
#include <cstring>
#include <iostream>
#include <string>
#include <cctype>
#include <cstddef>
using namespace std;

// File name constants

static const char CUSTOMERS_FILE[] = "customers.dat";
static const char TRANSACTIONS_FILE[] = "transactions.dat";
static const char TELLERS_FILE[] = "tellers.dat";
static const char BRANCHES_FILE[] = "branches.dat";
static const char CONFIG_FILE[] = "system_config.txt";
static const int MAX_LOGIN_ATTEMPTS = 3;

// Safe copy function to prevent buffer overflow
template <size_t N>
void safeCopy(char (&destination)[N], const string &source)
{
    strncpy(destination, source.c_str(), N - 1);
    destination[N - 1] = '\0';
}
// Teller struct - stores employee login info

struct Teller
{
    char tellerID[10];
    char tellerName[50];
    char tellerPassWord[50];
    char branchCode[10];
}; // Customer struct - stores customer account data

struct Customer
{
    char accountNumber[30];
    char accountName[50];
    char customerID[15];
    char contactNumber[12];
    char email[50];
    char physicalAddress[100];
    char dateOfBirth[11];
    char encryptedPin[50];
    double bankBalance;
    char branchCode[10];
    char accountType[20];
    int loginAttempts;
    bool isLocked;
};

// Branch struct
struct Branch
{
    char branchCode[10];
    char branchName[30];
    char city[40];
};

// Transaction struct

struct Transaction
{
    char accountNum[30];
    char targetAccount[50];
    char type[30];
    double amount;
    double balanceAfter;
    char branchCode[10];
    char tellerID[10];
    char date[20];
};

// Function prototypes

string xorDataEncryption(string data);
void seedSystem();
void logTransaction(
    const char *accNum,
    const char *type,
    double amount,
    double balanceAfter,
    const char *branchCode,
    const char *targetAccount = "",
    const char *tellerID = "SELF");

bool isValidSAID(string id);
bool isValid(const char *id);
bool isValidEmail(string email);
bool isValidContactNumber(string number);
bool isValidDOB(string dob);
string makeLower(string data);

// Base Account class for polymorphism

class Account
{
protected:
    double balance;

public:
    Account(double bal = 0.0)
    {
        balance = bal;
    }
    virtual double calculateInterest() = 0;
    virtual double minimumDeposit() = 0;
    virtual bool canWithdraw(double amount)
    {
        return amount > 0 && amount <= balance;
    }

    virtual ~Account() {}
}; // Savings Account - 5% interest

class SavingsAccount : public Account
{
public:
    SavingsAccount(double bal = 0.0) : Account(bal) {}
    double calculateInterest() override
    {
        return balance * 0.05;
    }

    double minimumDeposit() override
    {
        return 100.00;
    }
}; // Cheque Account - 2% interest
class ChequeAccount : public Account
{
public:
    ChequeAccount(double bal = 0.0) : Account(bal) {}

    double calculateInterest() override
    {
        return balance * 0.02;
    }

    double minimumDeposit() override
    {
        return 500.00;
    }
}; // Fixed Deposit Account - 8% interest, no withdrawals
class FixedDepositAccount : public Account
{
public:
    FixedDepositAccount(double bal = 0.0) : Account(bal) {}
    double calculateInterest() override
    {
        return balance * 0.08;
    }
    double minimumDeposit() override
    {
        return 1000.00;
    }
    bool canWithdraw(double amount) override
    {
        return false;
    }
}; // Student Account - 0% interest
class StudentAccount : public Account
{
public:
    StudentAccount(double bal = 0.0) : Account(bal) {}
    double calculateInterest() override
    {
        return 0.0;
    }
    double minimumDeposit() override
    {
        return 50.00;
    }
};

Account *createAccountObject(const char accountType[], double balance);

#endif