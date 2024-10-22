#include <iostream>
#include <fstream> 
#include <string>
#include <algorithm>
#include <sstream> 
using namespace std;



string XORencryption(const string& fileWords, const string& key){
    string encryptedFile = fileWords;
    // XOR encryption
    for (size_t i = 0; i < encryptedFile.size(); i++){
        encryptedFile[i] = encryptedFile[i] ^ key[i%key.size()];
    }
    return encryptedFile;
    
}

int main()
{
    
// Declaring variables
string fileWords;
string key;
string inputFileName;
string line;
string encryptedFile;
string outputFileName;
int DorE;
cout << "Would you like to encrypt or decrypt a file? 1 for encrypt, 2 for decrypt: ";
cin >> DorE;

// User enters the key
cout << "Enter key: ";
cin >> key;

// User enters the file name
cout << "Enter file name: ";
cin >> inputFileName;

// Opens the file in binary mode to ensure consistency
ifstream MyReadFile(inputFileName, ios::binary);

// Checks if the file exists or not
if(MyReadFile){
    // Reads the file line by line into a stringstream then into a string to ensure no hidden characters
    stringstream myReadLines;
    myReadLines << MyReadFile.rdbuf();
    fileWords = myReadLines.str();
    MyReadFile.close();

    // Encrypts the file
    encryptedFile = XORencryption(fileWords, key);

    // User enters the output file name
    cout << "what would you like to name the file? ";
    cin >> outputFileName;

    // Creates the output file
    ofstream writeFile(outputFileName,ios::binary);

    // Writes the encrypted file to the output file
    writeFile << encryptedFile;
    writeFile.close();

    // Checks for encryption or decryption
    // Reason why this works: XOR encryption is the same as XOR decryption (symmetric encryption)
    if (DorE == 1){
        cout << "File Encrypted to " << outputFileName << endl;
    }
    else if (DorE == 2){
        cout << "File Decrypted to " << outputFileName << endl;
    }
    return 0;

    } else{
    cout << "File not found" << endl;
    return 0;
    }





}
