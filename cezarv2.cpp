#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, int key) {
    string cipher_text = "";
    for (char c : text) {
        // Kriptira se samo slova i brojevi
        if (isalnum(c)) {
            // Kriptiranje velikih slova
            if (isupper(c)) {
                cipher_text += (c - 'A' + key) % 26 + 'A';
            }
            // Kriptiranje malih slova
            else if (islower(c)) {
                cipher_text += (c - 'a' + key) % 26 + 'a';
            }
            // Kriptiranje brojeva
            else if (isdigit(c)) {
                cipher_text += (c - '0' + key) % 10 + '0';
            }
        }
        else {
            // Ostali znakovi ostaju nepromijenjeni
            cipher_text += c;
        }
    }
    return cipher_text;
}

string decrypt(string cipher_text, int key) {
    string plain_text = "";
    for (char c : cipher_text) {
        // Dekriptira se samo slova i brojevi
        if (isalnum(c)) {
            // Dekriptiranje velikih slova
            if (isupper(c)) {
                plain_text += (c - 'A' - key + 26) % 26 + 'A';
            }
            // Dekriptiranje malih slova
            else if (islower(c)) {
                plain_text += (c - 'a' - key + 26) % 26 + 'a';
            }
            // Dekriptiranje brojeva
            else if (isdigit(c)) {
                plain_text += (c - '0' - key + 10) % 10 + '0';
            }
        }
        else {
            // Ostali znakovi ostaju nepromijenjeni
            plain_text += c;
        }
    }
    return plain_text;
}

int main() {
    string text;
    int key;

    cout << "Unesite tekst za kriptiranje: ";
    getline(cin, text);

    cout << "Unesite kljuc za kriptiranje: ";
    cin >> key;

    string encrypted_text = encrypt(text, key);
    cout << "Kriptirani tekst: " << encrypted_text << endl;

    string decrypted_text = decrypt(encrypted_text, key);
    cout << "Dekriptirani tekst: " << decrypted_text << endl;

    return 0;
}
