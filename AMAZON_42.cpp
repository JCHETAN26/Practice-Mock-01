
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int n,k;
    cin>>n>>k;
    vector<int> Arr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        Arr.push_back(x);
    }

   vector<vector<int>> ahead(2,vector<int> (k+1,0));
   vector<vector<int>> cur(2,vector<int> (k+1,0));

      
       for(int ind = n-1;ind>=0;ind--){
           for(int buy=0;buy<=1;buy++){
               for(int cap=1;cap<=k;cap++){
                     if(buy==0){
                  cur[buy][cap] = max(ahead[0][cap],-Arr[ind]+ahead[1][cap]);
                }
                if(buy==1){
                  cur[buy][cap] = max(ahead[1][cap], Arr[ind]+ahead[0][cap-1]);
                }
               }  
           }
           ahead = cur;
       }
       cout<<ahead[0][k];
    return 0;
}
