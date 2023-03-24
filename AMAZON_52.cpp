#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int dominos(int n) {
        vector<long long>dom(n+1,0);
        if(n==1)
            return 1;
        else if(n==2)
            return 2;
        else if(n==3)
            return 5;
        else if(n==4)
            return 11;
        dom[1] = 1;
        dom[2] = 2;
        dom[3] = 5;
        dom[4] = 11;
        for(int i=5; i<=n; ++i) {
            dom[i] = (2*dom[i-1] +dom[i-3]) % 1000000007;
        }
        return dom[n];
    }
int main(){
    int n;
    cin>>n;
    cout<<dominos(n);
    return 0;
}
