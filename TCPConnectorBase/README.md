# 🔍 TCPConnectorBase (C++)

> **⚠️ IMPORTANT LEGAL DISCLAIMER & COPYRIGHT**
> 
> **All Rights Reserved © 2026 Oblicion0x9**
> 
> This software and its source code have been developed **strictly for educational purposes, academic study, and authorized testing in isolated lab environments**. 
> - You **may** view and study the code for personal learning.
> - You **may not** copy, modify, redistribute, or use this tool on networks or systems without explicit prior authorization from the owner.
> - The author assumes **no responsibility** for any misuse, unauthorized access, or damage caused by this software.

---

## 🇮🇹 Italiano

### Descrizione
**TCPConnectorBase C++** è un semplice scanner di porte TCP scritto in C++ (basato su WinSock2). Il programma permette di verificare se una specifica porta su un indirizzo IP è aperta o chiusa tramite un tentativo di connessione TCP.

Questo progetto è stato sviluppato a scopo didattico per esercitarsi con:
- Programmazione con i Socket (WinSock2)
- Fondamenti di Networking e protocollo TCP/IP
- Sviluppo in C++
- Logica di base degli strumenti di diagnostica di rete

### Funzionalità
- Verifica singola porta TCP
- Rilevamento dello stato della porta (`Open` / `Closed`)
- Interfaccia a riga di comando leggera e interattiva
- Struttura semplice, facile da leggere ed estendere

### Compilazione (Windows - MinGW)
Poiché il codice utilizza le librerie socket di Windows (`winsock2.h`), è necessario collegare la libreria `ws2_32` durante la compilazione:

```bash
g++ scanner.cpp -o scanner.exe -lws2_32
```

### Possibili miglioramenti futuri
- [ ] Supporto multipiattaforma (compatibilità nativa Linux/POSIX)
- [ ] Supporto multithreading per scansioni più rapide
- [ ] Scansione di un range di porte
- [ ] Timeout di connessione configurabile
- [ ] Output colorato su terminale
- [ ] Supporto IPv6

---

## 🇬🇧 English

### Description
**TCPConnectorBase C++** is a basic TCP port scanner written in C++ (using WinSock2). The program allows checking whether a specific port on a target IP address is open or closed by attempting a TCP handshake.

This project was created strictly for educational purposes to practice:
- Socket programming (WinSock2)
- Basic networking & TCP/IP fundamentals
- C++ development
- Core concepts behind network diagnostic tools

### Features
- Single TCP port scanning
- Open / Closed port state detection
- Lightweight and interactive CLI implementation
- Clean structure, easy to modify and extend

### Compilation (Windows - MinGW)
Since the code relies on Windows socket libraries (`winsock2.h`), you must link the `ws2_32` library when compiling:

```bash
g++ scanner.cpp -o scanner.exe -lws2_32
```

### Future Improvements
- [ ] Cross-platform support (Linux/POSIX sockets compatibility)
- [ ] Multithreading support
- [ ] Port range scanning
- [ ] Configurable connection timeout
- [ ] Colored terminal output
- [ ] IPv6 support

---

## 💻 Code Snippets & Architecture

### Connection Check Logic
```cpp
// Function to test TCP port connection
void CheckPort(Target& target)
{
    WSADATA info; 
    WSAStartup(MAKEWORD(2,2), &info);
    
    SOCKET mySocket = socket(AF_INET, SOCK_STREAM, 0);

    if (mySocket == INVALID_SOCKET) {
        cout << "[!] ERROR: Failed Socket Creation: " << WSAGetLastError() << endl;
        WSACleanup();
        return; 
    }

    sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_port = htons(target.port);
    service.sin_addr.s_addr = inet_addr(target.ip.c_str());

    cout << "[i] Attempting connection..." << endl;

    int connection = connect(mySocket, (SOCKADDR*)&service, sizeof(service));

    if (connection == SOCKET_ERROR) {
        cout << "[!] ERROR: Connection failed (Port Closed/Filtered)" << endl;
        target.isOpen = false;
    } else {
        target.isOpen = true;
        cout << "[+] CONNECTED: Port is Open" << endl;
    }
    
    closesocket(mySocket); 
    WSACleanup();
}
```

### Target Configuration
```cpp
// Function to update target IP and Port
void Change(Target& target)
{
    cout << "*************************" << endl;
    cout << " Change Target           " << endl;
    cout << "*************************" << endl << endl;
    
    string ip;
    int port;
    
    cout << "Enter IP > ";
    cin >> ip;
    target.ip = ip;
    
    cout << "Enter PORT > ";
    cin >> port;
    target.port = port;
    
    cout << "[i] Target updated successfully" << endl;
    Sleep(700);
    system("cls");
}
```

### Available CLI Commands
```cpp
// Display available commands
void Info()
{
    cout << "Commands: status, list, info, help, exit\n"
         << "close, disconnect, localhost\n"
         << "run, start, cls, clear" << endl;
}
```
