#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxDistToClosest(vector<int>& seats) {     
    int pre_zeros = -1, suf_zeros = -1, max_zeros = -1, zeros = 0;
    for (int i = 0; i < seats.size(); i ++) {
        if (seats[i] == 0) {
            zeros ++;
        } else {
            if (pre_zeros == -1) {
                pre_zeros = zeros;
            } else {
                max_zeros = max(max_zeros, zeros);
            }
            zeros = 0;
        }
    } 
    suf_zeros = zeros;
    return max(max(pre_zeros, suf_zeros), (max_zeros + 1) / 2);
}

int main() {
    int n;
    vector<int> arr;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<maxDistToClosest(arr);
    return 0;
}
