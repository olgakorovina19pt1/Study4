#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>

#include "AES.h"
#include "BLOW.h"

using namespace std;
using namespace CryptoPP;

int main ()
{
    unsigned op, cip;
    string FIn, FOut, Pass;

    do {
        cout << "Enter the operation (0 - exit, 1 - encrypt, 2 - decrypt): ";
        cin >> op;

        if (op != 0) {
            cout << "|1 - AES-256|" << endl;
            cout << "|2 - Blowfish|" << endl;
            cout << "Choose algorithm and enter the number: ";
            cin >> cip;
        }

        if (op > 2) {
            cerr << "Error! Invalid operation" << endl;
        }

        else if (op > 0) {
            cout << "\nEnter a path to input file: ";
            cin >> FIn;

            cout << "\nEnter a path to output file: ";
            cin >> FOut;

            cout << "\nEnter a password: ";
            cin >> Pass;

            if (cip == 1) {
                AES_Cryptor aes(FIn, FOut, Pass);

                if (op == 1) {
                    if (aes.AES_Encrypt())
                        cout << "Successfull encrypting!" << endl;
                    else
                        cout << "Encryption failed!" << endl;
                } else {
                    if (aes.AES_Decrypt())
                        cout << "Successfull decrypting!" << endl;
                    else
                        cout << "Decryption failed!" << endl;
                }
            }
            else if (cip == 2) {
                BLOW_Cryptor b(FIn, FOut, Pass);

                if (op == 1) {
                    if (b.BLOWFISH_Encrypt())
                        cout << "Successfull encrypting!" << endl;
                    else
                        cout << "Encryption failed!" << endl;
                } else {
                    if (b.BLOWFISH_Decrypt())
                        cout << "Successfull decrypting!" << endl;
                    else
                        cout << "Decryption failed!" << endl;
                }
            }
            else {
                cerr << "Error! Incorrect algorithm number!!!\n";
            }
        }

    } while (op != 0);

    return 0;
}