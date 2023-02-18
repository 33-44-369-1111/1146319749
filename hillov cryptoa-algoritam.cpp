"""
Dokumentacija za algoritam:

Algoritam koristi Hillovu šifru koja koristi matrice za kriptiranje i dekriptiranje teksta. Korisnik unosi tekst koji želi kriptirati i matricu ključa dimenzije 2x2, a algoritam izračunava kriptirani tekst i potrebne ključeve za dekripciju. 

Funkcija `getMatrixInverse` pronalazi inverz matrice dimenzije 2x2 modulo 26 koristeći formulu za pronalazak inverza matrice i inverz determinante. Funkcija vraća inverz matrice ili praznu matricu ako matrica nije invertibilna.

Funkcija `encrypt` kriptira uneseni tekst p pomoću matrice ključa K. Tekst se dijeli na blokove veličine matrice ključa i svaki blok se kriptira posebno. Za svaki blok teksta se izračuna vektor P i vektor C pomoću kojih se kriptira tekst. Kriptirani tekst se vraća kao string.

Funkcija `decrypt` dekiptiranje kriptiranog teksta. Kriptirani tekst se dijeli na blokove veličine matrice ključa i svaki blok se dekriptira posebno. Za svaki blok teksta se izračuna vektor P pomoću kojeg se dekriptira tekst. Dekriptirani tekst se vraća kao string.

Funkcija main je ulazna točka u program. Korisnik unosi tekst koji želi kriptirati i matricu ključa dimenzije 2x2. Algoritam koristi funkcije encrypt i decrypt za kriptiranje i dekriptiranje teksta te ispisuje kriptirani i dekriptirani tekst.

Primjer korištenja algoritma:

Unesite tekst: HELLO WORLD
Unesite kljuc 2x2 matrice (4 broja): 1 2 3 4
Kriptirani tekst: DMTZQOMLZF
Dekriptirani tekst: HELLOWORLD
"""


#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Funkcija koja vraća inverz matrice modulo 26
vector<vector<int>> getMatrixInverse(vector<vector<int>> mat)
{
    // Određivanje determinante matrice
    int det = (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]) % 26;
    if (det < 0) det += 26;

    // Pronalaženje inversa determinante
    int detInv = -1;
    for (int i = 0; i < 26; i++)
    {
        if ((det * i) % 26 == 1)
        {
            detInv = i;
            break;
        }
    }

    // Ako determinantna nije invertibilna, ne može se izračunati inverz matrice
    if (detInv == -1) return vector<vector<int>>();

    // Izračunavanje adjunkte matrice
    vector<vector<int>> adj(2, vector<int>(2));
    adj[0][0] = mat[1][1];
    adj[0][1] = -mat[0][1];
    adj[1][0] = -mat[1][0];
    adj[1][1] = mat[0][0];

    // Izračunavanje inverza matrice
    vector<vector<int>> matInv(2, vector<int>(2));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matInv[i][j] = ((adj[i][j] % 26) * detInv) % 26;
            if (matInv[i][j] < 0) matInv[i][j] += 26;
        }
    }

    return matInv;
}

// Funkcija koja kriptira uneseni tekst p pomoću matrice ključa K
string encrypt(string p, vector<vector<int>> K)
{
    int n = K.size();
    string c = "";
    for (int i = 0; i < p.length(); i += n)
    {
        vector<int> P(n);
        vector<int> C(n);
        for (int j = 0; j < n; j++)
        {
            P[j] = (int)(p[i+j] - 'A');
        }

        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int k = 0; k < n; k++)
            {
                sum += K[j][k] * P[k];
            }
            C[j] = sum % 26;
        }

        for (int j = 0; j < n; j++)
        {
            c += (char)(C[j] + 'A');
        }
    }
    return c;
}

// Funkcija koja dekriptira kriptirani tekst c pomoću matrice ključa K
string decrypt(string c, vector<vector<int>> K)
{
    int n = K.size();
    string p = "";
    vector<vector<int>> Kinv = getMatrixInverse(K);
// Ako matrica ključa nije invertibilna, ne može se izračunati inverz matrice
if (Kinv.empty())
{
    cout << "Matrica ključa nije invertibilna!" << endl;
    return "";
}

for (int i = 0; i < c.length(); i += n)
{
    vector<int> P(n);
    vector<int> C(n);
    for (int j = 0; j < n; j++)
    {
        C[j] = (int)(c[i+j] - 'A');
    }

    for (int j = 0; j < n; j++)
    {
        int sum = 0;
        for (int k = 0; k < n; k++)
        {
            sum += Kinv[j][k] * C[k];
        }
        P[j] = sum % 26;
    }

    for (int j = 0; j < n; j++)
    {
        p += (char)(P[j] + 'A');
    }
}
return p;
}

int main()

{
// Unos teksta i ključa
string plaintext, ciphertext;
vector<vector<int>> key(2, vector<int>(2));
cout << "Unesite tekst: ";
getline(cin, plaintext);
cout << "Unesite kljuc 2x2 matrice (4 broja): ";
for (int i = 0; i < 2; i++)
{
for (int j = 0; j < 2; j++)
{
cin >> key[i][j];
}
}
// Kriptiranje teksta
ciphertext = encrypt(plaintext, key);
cout << "Kriptirani tekst: " << ciphertext << endl;

// Dekriptiranje teksta
plaintext = decrypt(ciphertext, key);
cout << "Dekriptirani tekst: " << plaintext << endl;

return 0;
