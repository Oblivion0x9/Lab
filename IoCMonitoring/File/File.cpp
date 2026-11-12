#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

struct Server
{
    string name;
    string ip;
};


struct Blacklist
{
    string ip_b;
    string type;
};


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


/* Generic Control 
void Controll(vector<Server>& list)
{
    for (auto& l : list)
    {
        if (l.ip.find("192.") == string::npos)
        {
            cout << "[!] Suspicious: External IP Detected " << l.name << " " << l.ip << endl;
        }
    }
}
*/


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


int main(int argc, char* argv[])
{
    vector<Server> list;
    vector<Blacklist> blacklist;
    
    string choice;
    int speed = 150;
    cout << "To Start Type A: ";
    cin >> choice;
    
    if (choice == "A" || choice == "a")
    {
        cout << "Select Speed [1 or 2]: ";
        cin >> speed;
        
        if (speed == 1)
        {
            speed = 50;
        } else if (speed == 2)
        {
            speed = 100;
        } else
        {
            speed = 150;
        }
        
        Read(list, speed);  
        ReadBlacklist(blacklist);
        
        choice = "";
        
        cout << endl;
        cout << "Detect Suspicious IP [Y/n]: ";
        cin >> choice;
        
        if (choice == "Y" || choice == "y")
        {
            Controll(list, blacklist); 
        } else if (choice == "N" || choice == "n")
        {
            cout << "Manually Check The Created File" << endl;
        }
        
    } else
    {
        cout << "[!] Error: The Choice is not right" << endl;
    }
    
    
    
    
    system("pause");
    return 0;
}
