def encrypt(message, shift):
    cipher = ''
    for char in message:
        if char == ' ':
            cipher += char
        elif char.isupper():
            cipher += chr((ord(char) + shift - 65) % 26 + 65)
        else:
            cipher += chr((ord(char) + shift - 97) % 26 + 97)
    return cipher

message = input("Unesite poruku koju želite kriptirati: ")
shift = int(input("Unesite broj pomaka: "))
print("Kriptirana poruka: ", encrypt(message, shift))
