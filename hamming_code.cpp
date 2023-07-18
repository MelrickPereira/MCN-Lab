#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    string data = "11100011";
    int m = data.size();
    

    //calculating r
    int r=0;
    while(pow(2,r)<m+r+1)
    {
        r++;
    }
    set<int>powerof2;

    for(int i=0;i<r;i++)
    {
        powerof2.insert(pow(2,i));
    }
    // for(auto x:powerof2)
    //     cout<<x<<" ";
    // cout<<r;
    int n = m+r;
    string result;
    int j=0;
    for(int i=n;i>=1;i--)
    {
        if(powerof2.count(i))
        {
           result+="." ;
           continue;
        }
        result+=data[j++];
    }
    reverse(result.begin(),result.end());

    for(int i=0;i<r;i++)
    {
        string temp="";
        int index = pow(2,i);
        int count = index;
        int j=0;
        while(result[j]!='.')
            {
                j++;
                continue;
            }
        for(;j<n;j++)
        {
            
            if(count!=0)
            {
                temp+=result[j];
                count--;
            }
            else
            {
                j+=index-1;
                count = index;
            }
            
        }
        int ones_count=0;
        for(int k=0;k<temp.size();k++)
        {
            if(temp[k]=='1')
                ones_count++;
        }
        cout<<result<<endl;
        cout<<temp<<endl;
        cout<<ones_count<<endl;
        
        if(ones_count%2!=0)
            result.at(index-1)='1';
        else
            result.at(index-1)='0';


    }
    reverse(result.begin(),result.end());
    cout<<result;

    return 0;
}