# IoC / IP Monitor Tool

Simple C++ tool to read a list of servers and compare them against a blacklist of known malicious IPs.

## ⚙️ Features
- Reads server list from file (`IoC.txt`)
- Loads blacklist from file (`blacklist.txt`)
- Compares IPs against known malicious entries
- Generates a simple report (`report.txt`)
- Console output with basic alert highlighting



## 📁 Input format

**IoC.txt**
scanner,192.168.1.23
laptop,192.168.3.45
undefined,45.90.126.124
nas,192.132.154.123
printer,192.168.0.12
camera,192.168.1.77
router,192.168.1.1


**blacklist.txt**
10.10.0.11,ransomware
10.10.0.12,ddos



## ⚠️ Disclaimer

This project is for **educational and defensive security purposes only**.
The author is **not responsible for any misuse of this software**.  
This tool is intended to demonstrate basic IoC/blacklist checking concepts and should not be used for malicious activities.
Use responsibly and in compliance with applicable laws.


## 🚫 No Warranty

This software is provided "as is", without warranty of any kind.


## How to run
1. Run C++ program to generate `report.txt`
2. Double click `server.bat`
3. Open dashboard in browser


## 🧠 Author
http-vincel


## Usage/Examples
```bash
@echo off
cd /d %~dp0

echo Starting IoC Dashboard...
start "" python -m http.server 8000
timeout /t 2 >nul
start "" http://localhost:8000/index.html
```



```cpp
// Read Function
void Read(vector<Server>& list, int& speed)
{
    ifstream File("IoC.txt");
    
    string line;
    if (File.is_open())
    {
        while (getline(File, line))
        {
            int pos = line.find(",");
            string nameStr = line.substr(0, pos);
            string ipStr = line.substr(pos + 1);
            
            Sleep(speed);
            cout << "[+] Read: " << nameStr << ": (" << ipStr << ") " << endl;
            
            Server s = {nameStr, ipStr};
            list.push_back(s);
        }
        File.close();
    } else
    {
        cout << "[!] Error" << endl;
    }
}
```



```cpp
// Controll Function
void Controll(vector<Server>& list, vector<Blacklist>& blacklists)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ofstream CreateReport("report.txt", ios::app);
    for (auto& s : list)
    {
        for (auto& b : blacklists)
        {
            if (s.ip == b.ip_b)
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "[!] WARNING:";
                SetConsoleTextAttribute(hConsole, 7);
                cout << " IP Banned " << b.ip_b << " Type: " << b.type << endl;
                
                if (CreateReport.is_open())
                {
                    CreateReport << "[!] WARNING: IP Banned " << b.ip_b << " Type: " << b.type << endl;
                }
            }
        }
    }
}
```



```cpp
// Blacklist Function
void ReadBlacklist(vector<Blacklist>& blacklist)
{
    ifstream BlackList("blacklist.txt");
    string line;
    
    if (BlackList.is_open())
    {
        while (getline(BlackList, line))
        {
            
            int pos = line.find(",");
            string ipStr = line.substr(0, pos);
            string typeStr = line.substr(pos + 1);
            
            Blacklist list = {ipStr, typeStr};
            blacklist.push_back(list);
        }
        BlackList.close();
    }
}
```



