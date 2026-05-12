#include <iostream> 
#include <string> 
#include <sstream> 
#include <iomanip> 
#include "BankSystem.h" 

using namespace std; 

// XOR encryption - encrypts data and returns hex string 

string xorDataEncryption(string data) { 
    char keySet = 'K'; 
    stringstream output; 
    for (int i = 0; i < (int)data.size(); i++) {
        int encryptedChar = ((unsigned char)data[i]) ^ keySet; 
        output << hex << setw(2) << setfill('0') << encryptedChar; 
        } 
        return output.str(); 
    }