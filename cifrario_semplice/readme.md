# 🔐 Simple ASCII Caesar Cipher (C)

A lightweight, educational implementation of a classic **substitution cipher** (inspired by the Caesar Cipher) written in C. The program reads a string from standard input, shifts its characters using a user-defined numeric key, and demonstrates both the encryption and decryption processes.

---

## ⚙️ How It Works

Unlike the traditional Caesar Cipher that wraps around the 26 letters of the English alphabet, this implementation operates directly on the **ASCII character table**:

1. **Input Handling:** The program safely reads a plaintext string (up to 99 characters + null terminator) using `fgets()` and asks for an integer shift key (`chiave`).
2. **Encryption (`cifra` function):** It iterates through each character of the array until it reaches the null terminator (`'\0'`). For each character, it adds the integer key directly to its underlying ASCII decimal value:
   $$\text{Encrypted Char} = \text{Plaintext Char} + \text{Key}$$
3. **Decryption (`decifra` function):** To restore the original message, the function reverses the mathematical operation by subtracting the exact same key from each character's ASCII value:
   $$\text{Plaintext Char} = \text{Encrypted Char} - \text{Key}$$

*(Note: Because `fgets()` captures the trailing newline character `'\n'` when pressing Enter, that character is also shifted during encryption and restored upon decryption.)*

---

## ✨ Features
- Custom numeric shift key input
- In-place character array manipulation (zero extra memory overhead)
- Real-time demonstration of Plaintext → Ciphertext → Decrypted Text
- Standard C library implementation (`stdio.h`, `stdlib.h`)

---

## 🚀 Compilation & Usage

Compile the source code using `gcc` (or any standard C compiler):

```bash
gcc cipher.c -o cipher
```

Run the executable:

```bash
./cipher
```

### Example Output
```text
Inserisci il testo da cifrare: Hello World

Inserisci la chiave numerica: 3


Testo in chiaro: Hello World

Testo cifrato: Khoor#Zruog
Testo decifrato: Hello World
```

---

## 🔒 Copyright & Terms of Use

**All Rights Reserved © 2026 Oblicion0x9**

This code is published strictly for **educational and portfolio viewing purposes**. 
- You **may** view and study the source code.
- You **may not** copy, modify, or redistribute this code without explicit permission from the author.