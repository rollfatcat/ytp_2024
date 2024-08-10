#include<bits/stdc++.h>
using namespace std;

const int MaxRC=1e6;
const int MaxS=5e6;

int R, C, nr, nc;
int dr[128]={};
int dc[128]={};
string S;
vector<vector<char>> ans;

int main(){
   dc['h']=-1; dc['l']=1;
   dr['k']=-1; dr['j']=1;
   
   cin>>R>>C>>S;
   ans.resize(R);
   for(int r=0; r<R; r+=1)
      ans[r].resize(C,'.');
   nr=nc=0;
   for(char ch: S){
      if( dr[ch]+dc[ch]==0 ){
         ans[nr][nc]=ch;
         nr=(nc==C-1)? (nr==R-1)? 0: nr+1: nr;
         nc=(nc==C-1)? 0: nc+1;
      }else{
         nr=(nr+dr[ch]+R)%R;
         nc=(nc+dc[ch]+C)%C;
      }
   }
   for(int r=0; r<R; r+=1){
      for(int c=0; c<C; c+=1)
         cout<<ans[r][c];
      cout<<"\n";
   }
}