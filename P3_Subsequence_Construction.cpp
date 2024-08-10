#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
int N, K;
int A[MaxN+1];
int P[MaxN+1]={};
int main(){
   cin>>N;
   for(int n=1; n<=N; n+=1){
      cin>>A[n];
      P[ A[n] ]=n;
   }
   for(K=1; K<=N && 0<P[K]; K+=1);
   vector<int> ans;
   for(int n=1; n<=N; n+=1)
      if( A[n]<K && P[ A[n] ]==n )
         ans.push_back(A[n]);
   cout<<ans.size()<<"\n";
   for(int v: ans)
      cout<<v<<" ";
}