/*
Whis and Beerus are playing a new game today . They form a tower of N coins and make a move in alternate turns . Beerus being the God plays first . In one move player can remove 1 or X or Y coins from the tower . The person to make the last move wins the Game . Can you find out who wins the game ?
Input Format :
Contains three value N,X,Y as mentioned in the problem statement
Output Format :
A string containing the name of the winner like “Whis” or “Beerus” (without quotes)
*/
#include<bits/stdc++.h>
using namespace std;
string solve(int n, int x, int y)
{

    string*coinStatus = new string[n+1];
    coinStatus[0] = "other";
    if(n>=1)
        coinStatus[1] = "current";

    for(int i=2;i<=n;i++)
    {
        string st_1 = "",st_x = "",st_y = "";
        st_1 = coinStatus[i-1];
        if(i>=x)
            st_x = coinStatus[i-x];
        if(i>=y)
            st_y = coinStatus[i-y];

        if(st_x == "other" || st_y == "other" || st_1 == "other")
            coinStatus[i] = "current";
        else
            coinStatus[i] = "other";



    }
    string ans = "";
    if(coinStatus[n] == "current")
        ans = "Beerus";

    else
        ans = "Whis";
    delete [] coinStatus;
    return ans;
}


int main()
{
    int n,x,y;
	cin>>n>>x>>y;
	cout<<solve(n,x,y)<<endl;
}
