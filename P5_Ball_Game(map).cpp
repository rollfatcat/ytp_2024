#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e9;
const int MaxM=1e5;

int N, M, a, b, c;
long ans=0;
map<int,int> to;

int main(){
   cin>>N>>M;
   for(int m=0; m<M; m+=1){
      cin>>a>>b;
      if( to.find(b)==to.end() )
         to[b]=b;
      if( a==1 ){
         cin>>c;
         if( to.find(c)==to.end() )
            to[c]=c;
         swap(to[b],to[c]);
      }else{ //a==2
         ans+= to[b];
      }
   }
   cout<<ans;
}