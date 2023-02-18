#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Cezarov algoritam za kriptiranje teksta
 * 
 * @param[in] message Tekst koji treba kriptirati
 * @param[in] key Ključ pomoću kojeg se kriptira tekst
 * @return Kriptirani tekst
 */
string caesar_encrypt(string message, int key) {
    string encrypted_message = "";

    for (char c : message) {
        if (isalnum(c)) {
            if (isalpha(c)) {
                if (islower(c)) {
                    c = (((c - 97) + key) % 26) + 97;
                } else {
                    c = (((c - 65) + key) % 26) + 65;
                }
            } else if (isdigit(c)) {
                c = ((c - 48 + key) % 10) + 48;
            }
            encrypted_message += c;
        } else {
            encrypted_message += c;
        }
    }

    return encrypted_message;
}

/**
 * @brief Cezarov algoritam za dekriptiranje teksta
 * 
 * @param[in] message Tekst koji treba dekriptirati
 * @param[in] key Ključ pomoću kojeg se dekriptira tekst
 * @return Dekriptirani tekst
 */
string caesar_decrypt(string message, int key) {
    string decrypted_message = "";

    for (char c : message) {
        if (isalnum(c)) {
            if (isalpha(c)) {
                if (islower(c)) {
                    c = (((c - 97) - key + 26) % 26) + 97;
                } else {
                    c = (((c - 65) - key + 26) % 26) + 65;
                }
            } else if (isdigit(c)) {
                c = ((c - 48 - key + 10) % 10) + 48;
            }
            decrypted_message += c;
        } else {
            decrypted_message += c;
        }
    }

    return decrypted_message;
}

/**
 * @brief Glavna funkcija
 * 
 * @return 0 ako se program uspješno izvršio
 */
int main() {
    string message, encrypted_message, decrypted_message;
    int key;

    cout << "Unesite poruku koju želite kriptirati: ";
    getline(cin, message);

    cout << "Unesite ključ za kriptiranje: ";
    cin >> key;

    encrypted_message = caesar_encrypt(message, key);
    cout << "Kriptirana poruka: " << encrypted_message << endl;

    decrypted_message = caesar_decrypt(encrypted_message, key);
    cout << "Dekriptirana poruka: " << decrypted_message << endl;

    return 0;
}
