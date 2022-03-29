#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    string command, name, password, inName, inPassword, registerName, registerPassword;
    while (1)
    {
        cout<<"(Register/ exit/login)\n"
            << "Command: ";
        getline(cin, command);
        if(command=="exit")
        {
            return 1;
        }
        if(command=="register")
        {
            ofstream g("registration.txt");
            if(!g.is_open())
            {
                cout<<"could not open file\n";return 0;
            }
            cout<<"\n\n\n"
                <<"New Username: ";
            getline(cin, registerName);
            cout<<"New Password: ";
            g<<registerName;
            g<<'\n';
            g<<registerPassword;
            g.close();
        }
        if(command=="login")
        {
            ifstream f("registration.txt");
            if(!f.is_open())
            {
                cout<<"could not open file\n";
                return 0;
            }
            getline(f, name, '\n');
            getline(f, password, '\n');
            f.close();
            while(1)
            {
                cout<<"\n\n\n"
                    <<:"Enter Username: ";
                getline(cin, inName);
                cout<<"Enter Password: ";
                getline(cin, inPassword);
                if(inName==name && inPassword==password)
                {
                    cout<<"Login Successful\n"
                        <<"Welcome, "
                        <<inName;
                    break;
                }
                cout<<"incorrect name or password\n"
            }
        }
        cout<<"\n\n\n\n\n";
    }
    return 1;
}