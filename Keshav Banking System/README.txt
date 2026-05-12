Assignment: PROGRAMMING 621 ASSIGNMENTSystem: 
Multi-Branch Banking Management SystemName: 
Keshav Ramphal 

HOW TO COMPILE AND RUNCOMPILATION

1. Unzip the folder extract to desktop
2. go into the folder until you see set files like main.cpp then copy the path to the folder 
3. Open powershell
4. cd into the folder path you copied 
5. g++ -o BankSystem_Submission main.cpp EncryptionFile.cpp SeedFile.cpp
6. then ./Banksystem
7. if it redirects to VSCode and you get wired code ect, close VSCode or IDE and open the extracted file, you will find the C++ application which will direct you to terminal 
8. Run it and enjoy

The system will
1. Display the main menu
2. Automatically seed the database with default tellers and branches
3. Wait for user 

selectionBankSystem.h - Header file with structs, classes, and function declarationsmain.cpp - Main program logic and menu 
systemsEncryptionFile.cpp - XOR encryption implementation
SeedFile.cpp - Database seeding with default datacustomers.dat - 

Customer accounts with encrypted PINs transactions.dat - Transaction historytellers.dat - Teller credentials (encrypted passwords)
branches.dat - Branch 
informationsystem_config.txt - 
System configuration
settingscustomers.bak
transactions.bak
tellers.bak
branches.bak
system_config.bak

EXPORT FILES (GENERATED ON EXPORT): TransactionHistory.csv - All transactions in CSV formatBranchReport_[BranchCode].txt - 

Branch-specific customer 
reportsTELLER ACCOUNTS:

---------------Branch:
 Durban North (Durban03) Teller ID: T001 Password: Keshav123 Teller Name: Keshav Admin
Branch: Joburg CBD (Jozi06) Teller ID: T002 Password: Jozi123 Teller Name: Jozi Teller
Branch: Cape Town City (Cape01) Teller ID: T003 Password: Cape123 Teller Name: Cape Teller

CUSTOMER ACCOUNTS:-----------------No default customer accounts exist. Tellers must register customers. When a customer is registered, the system generates:- Unique Account Number (format: ACC-[BranchCode]-[5digits])- 5-digit PIN (displayed ONCE during registration)
