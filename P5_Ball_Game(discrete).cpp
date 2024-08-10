#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e9;
const int MaxM=1e5;

int N, M, b, c;
int qry[MaxM][3];
int srt[MaxM<<1];
int  to[MaxM<<1];
long ans=0;


int main(){
   cin>>N>>M; N=0;
   for(int m=0; m<M; m+=1){
      cin>>qry[m][0]>>qry[m][1];
      srt[N++]=qry[m][1];
      if( qry[m][0]==2 )
         continue;
      cin>>qry[m][2];
      srt[N++]=qry[m][2];
   }
   sort(srt,srt+N);
   N=unique(srt,srt+N)-srt;
   for(int n=0; n<N; n+=1)
      to[n]=srt[n];
   for(int m=0; m<M; m+=1){
      b=lower_bound(srt,srt+N,qry[m][1])-srt;
      if( qry[m][0]==1 ){
         c=lower_bound(srt,srt+N,qry[m][2])-srt;
         swap(to[b],to[c]);
      }else{ // qry[m][0]==2
         ans+= to[b];
      }
   }
   cout<<ans;
}