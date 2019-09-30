/*
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}.
You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
Line 1 :  Number of ways i.e. W
*/
#include<iostream>
using namespace std;

int countWaysToMakeChange(int coins[], int numDenominations, int value){

    int n = value, m = numDenominations;
    int**output = new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        output[i] = new int[m+1];

    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            output[i][j] = -1;
    int ans = 0;

    for(int i=0;i<=n;i++)
        output[i][0] = 0;
    for(int j=0;j<=m;j++)
        output[0][j] = 1;


    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=m;j++)
        {
            int waysIncl = 0,waysExcl = 0;
            if(i>=coins[m-j]) //m-j is the index of first element of our considered part of coins
            {
                waysIncl = output[i-coins[m-j]][j];

            }
            waysExcl = output[i][j-1];
            output[i][j] = waysExcl+waysIncl;
        }
    }

    ans = output[n][m];


    for(int i=0;i<=n;i++)
    {

        delete[]output[i];
    }
    delete[]output;
    return ans;


}


int main(){

  int numDenominations;
  cin >> numDenominations;
  int* denominations = new int[numDenominations];
  for(int i = 0; i < numDenominations; i++){
    cin >> denominations[i];
  }
  int value;
  cin >> value;

  cout << countWaysToMakeChange(denominations, numDenominations, value);

}


