#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;


bool is_pow_2(int i)
{
    int j=0;
    while (j<=i )
    {
        if (i==pow(2,j))
        {
            return 1;
        }

        j++;
    }
    return 0;
     
}

char calc_redundant(int i,string ans,int msg_size)
{
    string temp = "";
    int n=i;
    for (int j = i; j < msg_size; j++)
    {
        if(n>=0)
        {
        temp.push_back(ans.at(j));
        n--;
        continue;
        }
        j+=i;
        n=i;
        
    }

    int number_of_one = 0;
    int j=0;
    while (j<temp.size())
    {
        if(temp.at(j)=='1')
            number_of_one++;
        j++;
    }
    if(number_of_one%2==0)
        return '0';
    return '1';
    
    
    

}
int main()
{
    string data;
    cout<<"Enter the data: ";
    cin>>data;
    //To find number of redundant bits
    int size = data.size();
    int r=0;
    while (pow(2,r)<size+r+1)
    {
        r++;
    }
    // cout<< r;
    int msg_size = size+r;
    reverse(data.begin(), data.end());
    
    //adding the placeholders for redundant bits
    string ans="";
    int j=0;
    for (int i = 1; i <= msg_size; i++)
    {
        if(is_pow_2(i))
        {
            ans.push_back('2');
        }
        else{
            ans.push_back(data.at(j));
            j++;
        }
        
    }

     for (int i = 1; i <= ans.size(); i++)
    {
        if(is_pow_2(i))
        {
            ans.at(i) = calc_redundant(i,ans,msg_size);
        }
        
    }

    reverse(ans.begin(), ans.end());
    cout<<ans;



    

    _getch();
    return 0;
}