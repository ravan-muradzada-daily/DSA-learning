#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& stalls, int cows, int curr){
    int c = 1;
    int last = stalls[0];
    
    for (int i = 1; i < stalls.size(); ++i){
        if (stalls[i] - last >= curr){
            c++;
            last = stalls[i];
        }
        if (c >= cows) return true;
    }
    
    return false;
}

int aggressiveCows(vector<int> &stalls, int cows){
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int left = 1, right = stalls[n-1] - stalls[0], mid, res;
    
    while (left <= right){
        mid = (left + right) / 2;
        if (isPossible(stalls, cows, mid)){
            res = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    
    return res;
}

int main(){
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int cows = 4;
    
    cout << aggressiveCows(stalls, cows) << endl;
    
    return 0;
}
