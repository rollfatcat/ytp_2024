#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const int MaxL=1e9;

long N, L;
long a[MaxN];
long b[MaxN];
int main(){
   cin>>N>>L;
   for(int n=0; n<N; n+=1)
      cin>>a[n];
   for(int n=0; n<N; n+=1)
      cin>>b[n];
   sort(a,a+N);
   sort(b,b+N);
   double ans=0.0;
   for(int n=0; n<N; n+=1){
      long dx=a[n]-b[N-1-n];
      ans+=sqrt( dx*dx+L*L );
   }
   cout<<fixed<<setprecision(8)<<ans;
}