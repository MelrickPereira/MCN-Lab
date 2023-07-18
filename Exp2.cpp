// Display IP
// CLASS of the IP
// Default Mask
// Network ID
// Host ID
#include <iostream>
#include <conio.h>
#include <string.h>
#include <vector>
using namespace std;

void printNetworkHostID(string ip, string ch)
{
    cout << "Network ID: ";
    int count;

    if (ch == "A")
        count = 1;
    if (ch == "B")
        count = 2;
    if (ch == "C")
        count = 3;
    int i;
    for (i = 0; i < ip.size(); i++)
    {
        cout << ip[i];
        char temp = ip[i];
        if (temp == '.')
            count--;
        if (count == 0)
            break;
    }
    cout << endl;
    i++;
    cout << "Host ID: ";
    for (; i < ip.size(); i++)
    {
        cout << ip[i];
    }
}

int main()
{
    cout<<"Hello world";
    string ip;

    vector<string> ip_no;
    cout << "Enter IP address: ";
    cin >> ip;

    // To determine the class of IP
    //  class A - 0 to 127
    //  class B - 128 to 191
    //  class C - 192 to 223
    //  class D - 224 to 239
    cout << "IP: " << ip << endl;
    int j = 0;
    ip+=".";
    string temp = "";
    for (int i = 0; i < ip.size(); i++)
    {
        if (ip[i] == '.')
        {
            ip_no.push_back(temp);
            temp = "";
           continue;
        }
        temp+=ip[i];
    }
    for(auto x:ip_no)
        cout<<x<<",";
    //  comparing 

    if (ip_no.at(0) >= "0" && ip_no.at(0) <= "127")
    {
        cout << "Class A" << endl;
        cout << "Subnet Mask: 255.0.0.0" << endl;
        printNetworkHostID(ip, "A");
    }
    else if (ip_no.at(0) >= "128" && ip_no.at(0) <= "191")
    {
        cout << "Class B" << endl;
        cout << "Subnet Mask: 255.255.0.0" << endl;
        printNetworkHostID(ip, "B");
    }
    else if (ip_no.at(0) >= "192" && ip_no.at(0) <= "223")
    {
        cout << "Class C" << endl;
        cout << "Subnet Mask: 255.255.255.0" << endl;
        cout<<"Network Address: ";
        int i;
        for(i=0;i<3;i++)
        {
                cout<<ip_no[i]+"."; 
            
        }
        cout<<endl;
        cout<<"Host Address: ";
        for(;i<ip_no.size();i++)
        {
            cout<<ip_no[i]+".";
        }
        cout<<endl;
    }

    else
    {
        cout << "Reserved for future use";
    }

    return 0;
}
