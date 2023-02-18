def caesar_cipher(message, key):
    """
    Funkcija za enkripciju poruke koristeći Caesarovu šifru.

    Argumenti:
    message (str): Poruka koju želimo enkriptirati.
    key (int): Ključ za enkripciju.

    Povratna vrijednost:
    str: Enkriptirana poruka.
    """
    cipher_text = ""
    for char in message:
        # Provjerava se da li se radi o isprintabilnom ASCII znaku
        if 32 <= ord(char) <= 126:
            # Enkripcija velikih slova
            if char.isupper():
                cipher_text += chr((ord(char) + key - 65) % 26 + 65)
            # Enkripcija malih slova
            elif char.islower():
                cipher_text += chr((ord(char) + key - 97) % 26 + 97)
            # Enkripcija brojeva i simbola
            else:
                cipher_text += chr((ord(char) + key - 32) % 95 + 32)
        else:
            # Ne enkriptiramo neisprintabilne znakove
            cipher_text += char
    return cipher_text

def decrypt_caesar_cipher(cipher_text, key):
    """
    Funkcija za dekripciju poruke koja je enkriptirana Caesarovom šifrom.

    Argumenti:
    cipher_text (str): Enkriptirana poruka koju želimo dekriptirati.
    key (int): Ključ za dekripciju.

    Povratna vrijednost:
    str: Dekriptirana poruka.
    """
    plain_text = ""
    for char in cipher_text:
        # Provjerava se da li se radi o isprintabilnom ASCII znaku
        if 32 <= ord(char) <= 126:
            # Dekripcija velikih slova
            if char.isupper():
                plain_text += chr((ord(char) - key - 65) % 26 + 65)
            # Dekripcija malih slova
            elif char.islower():
                plain_text += chr((ord(char) - key - 97) % 26 + 97)
            # Dekripcija brojeva i simbola
            else:
                plain_text += chr((ord(char) - key - 32) % 95 + 32)
        else:
            # Ne dekriptiramo neisprintabilne znakove
            plain_text += char
    return plain_text

# Korisnički unos poruke i ključa
message = input("Enter message: ")
key = int(input("Enter key: "))

# Enkripcija poruke
cipher_text = caesar_cipher(message, key)
print("Encrypted message: ", cipher_text)

# Dekripcija poruke
plain_text = decrypt_caesar_cipher(cipher_text, key)
print("Decrypted message: ", plain_text)
