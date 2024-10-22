#include <iostream>
#include <fstream> 
#include <string>
#include <algorithm>
#include <sstream> 
using namespace std;



string XORencryption(const string& fileWords, const string& key){
    string encryptedFile = fileWords;
    for (size_t i = 0; i < encryptedFile.size(); i++){
        encryptedFile[i] = encryptedFile[i] ^ key[i%key.size()];
    }

    return encryptedFile;
    
}

int main()
{
    

string fileWords;
string key;
string inputFileName;
string line;
string encryptedFile;
string outputFileName;
int DorE;
cout << "Would you like to encrypt or decrypt a file? 1 for encrypt, 2 for decrypt: ";
cin >> DorE;

cout << "Enter key: ";
cin >> key;

cout << "Enter file name: ";
cin >> inputFileName;

ifstream MyReadFile(inputFileName, ios::binary);

if(MyReadFile){
    stringstream myReadLines;
    myReadLines << MyReadFile.rdbuf();
    fileWords = myReadLines.str();
    


    MyReadFile.close();

    encryptedFile = XORencryption(fileWords, key);

    cout << "what would you like to name the file? ";
    cin >> outputFileName;


    ofstream writeFile(outputFileName,ios::binary);

    writeFile << encryptedFile;

    writeFile.close();
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
