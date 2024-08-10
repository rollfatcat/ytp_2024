#include<bits/stdc++.h>
using namespace std;

const int MaxS=100;
string S;
int main(){
   cin>>S;
   reverse(S.begin(),S.end());
   
   int ans=0;
   int Bcnt=0;
   for(char now: S){
      Bcnt+= now=='b';
      ans+= (now=='a')*Bcnt*(Bcnt-1)>>1;
   }
   cout<<"DuckDuck "<<(ans&1? 1: 2);
}