#include<bits/stdc++.h>
using namespace std;

const int MaxN=3e5;
const int MaxQ=3e5;
const int MaxK=1e6;

long N, Q, K, x;
long ans=0;
int C[MaxN<<1]={};
string opt;
set<int> pool;

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   
   cin>>N>>Q;
   ans=N*(N-1)/2*N;
   fill(C,C+N,N);
   for(int n=0; n<N; n+=1){
      cin>>K;
      for(int k=0; k<K; k+=1){
         cin>>x;
         C[x]-=1;
         ans-=x;
      }
   }
   for(int n=0; n<(N+MaxN); n+=1)
      if( C[n]<N )
         pool.insert(n);
   for(int q=0; q<Q; q+=1){
      cin>>opt;
      if( opt=="toggle" ){
         cin>>x;
         C[x]=N-C[x];
         if( C[x]<N )
            pool.insert(x);
         else
            pool.erase(x);
         ans= ans-x*(N-C[x])+x*C[x];
      }else{
         x= *pool.begin();
         ans+= x*(N-C[x]);
         C[x]=N;
         pool.erase(x);
      }
      cout<<ans<<"\n";
   }
}