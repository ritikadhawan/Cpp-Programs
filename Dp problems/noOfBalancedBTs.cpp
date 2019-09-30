/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Time complexity should be O(h).
Input Format :
Integer h
Output Format :
Count % 10^9 + 7
*/
#include<iostream>
#include<cmath>
using namespace std;
int binaryTreesOfHeightH(int h) {

  if(h==0)
    return 0;
  int*storage = new int[h+1];
  storage[0] = 1;
  storage[1] = 1;
  int mod = 1e9+7;
  for(int i = 2;i<=h;i++)
  {
    long long x = storage[i-1];
    long long y = storage[i-2];
    storage[i] = ((x*x)%mod + (2*(x*y)%mod)%mod)%mod;
  }
  int ans = storage[h];
  delete[]storage;
  return ans;
}


int main() {
    int h;
    cin >> h;
    int ans = binaryTreesOfHeightH(h);
    ans = ans % ((int)(pow(10, 9)) + 7);
    cout << ans << endl;
}

