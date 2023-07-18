#include <iostream>
using namespace std;

int main()
{
    string msg,crc,encoded;
    cout<<"Enter the message=";
    cin>>msg;
    cout<<"Enter the crc generator polynomial=";
    cin>>crc;
    int m= msg.length();
    int n=crc.length();
    encoded+=msg;


    //sender side
    cout<<"Sender Side: "<<endl;
    for (int i = 1; i <= n-1; i++)
    {
        encoded+='0';
    }
    

    for (int i = 0; i < encoded.size()-n; )
    {
        for (int j = 0; j < n; j++)
        {
            encoded[i+j] = encoded[i+j] ==crc[j]?'0':'1';
        }
        for (; i<encoded.length() && encoded[i]!='1'; i++);

    }
    encoded = msg+encoded.substr(encoded.length()-n+1);
    cout<< encoded<<endl<<endl;
    
    encoded = "";
    cout<<"Enter Received encoded message: ";
    cin>>encoded;
    //Receiver 

    cout<<"Receiver side: "<<endl;

    for (int i = 0; i < encoded.length()-crc.length(); )
    {
        for (int j = 0; j < crc.length(); j++)
        {
            encoded[i+j]=encoded[i+j]==crc[j]?'0':'1'; 
        }
        for ( ; i<encoded.length() && encoded[i]!='1'; i++);
    } 
       for (auto i : encoded.substr(encoded.length()-crc.length()))
       {
            if (i!='0')
            {
                cout<<"Error in communication...";
                return 0;
            }
            cout<<"No error!";
            return 0;   
       }
       
        
        
    
    
    
    return 0;
}