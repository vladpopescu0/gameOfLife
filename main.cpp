#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
int main() {
  ifstream fin("fisier.in");
  int n,m,iterations=10;
  fin>>n>>m;
  int mainArray[13][13],arr[13][13];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      if(i==0 || i==n || j==0 || j==m){
        mainArray[i][j]=0;
      }else{
        fin>>mainArray[i][j];
      }
      arr[i][j]=mainArray[i][j];
    }
  }
  while(iterations){
    for(int i=1;i<n;i++){
      for(int j=1;j<m;j++){
        int counter=0;
        for(int x=i-1;x<=i+1;x++){
          for(int y=j-1;y<=j+1;y++){
            if(arr[x][y]==1){
              counter++;
            }
          }
        }
        if(arr[i][j]==1){
          counter--;
        }
        //cout<<"//"<<counter<<"//";
        if(mainArray[i][j]==0 && counter==3){
          mainArray[i][j]=1;
        }else if(mainArray[i][j]==1 && (counter!=2 && counter!=3)){
          mainArray[i][j]=0;
        }
        cout<<mainArray[i][j]<<" ";
      }
      cout<<endl;
    }
    for(int i=0;i<=n;i++){
      for(int j=0;j<=m;j++){
        arr[i][j]= mainArray[i][j];
      }
    }
    cout<<endl;
    //system("cls");
    usleep(300000);
    iterations--;
  }
}
/*
0	0	0	0	0	0	0	0	0	0
0	0	0	0	0	0	0	0	0	0
0	0	0	0	0	0	0	0	0	0
0	0	0	0	0	0	0	0	0	0
0	0	0	1	1	1	1	1	0	0
0	0	0	0	0	0	0	0	0	0
0	0	0	0	0	0	0	0	0	0
0	0	0	0	0	0	0	0	0	0
0	0	0	0	0	0	0 0 0	0
0	0	0	0	0	0	0	0	0	0
 */