#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll multiply(int n, int mid, int m){
    ll res = 1;
    
    for (int i = 0; i < n; ++i){
        res *= mid;
        if (res > m) return -1;
    }
    
    return res;
}


int NthRoot(int n, int m){
    ll left = 1, right = m, mid, fmid;
    
    while (left <= right){
        mid = (left + right) / 2;
        fmid = multiply(n, mid, m);
        
        if (fmid == -1){
            right = mid - 1;
        }else if(fmid == m){
            return mid;
        }else{
            left = mid + 1;
        }
    }
    
    return -1;
}

int main(){
    int m = 4096, n = 6;
    
    cout << NthRoot(n, m) << endl;
    
    return 0;
}
