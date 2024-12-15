#include <bits/stdc++.h>
using namespace std;

int calculateTotalHours(vector<int>& piles, int k, int h){
    int res = 0;
    
    for (int i = 0; i < piles.size(); ++i){
        if (res > h) break;
        res += ceil((double)piles[i] / (double)k);
    }
    
    return res;
}

int minEatingSpeed(vector<int>& piles, int h){
    int n = piles.size();
    int left = 0, right = *max_element(piles.begin(), piles.end());
    int mid, currHours, res;
    // We use binary search from 1 to maximum possible k (which is the max of the array).
    while (left <= right){
        mid = (left + right) / 2;
        currHours = calculateTotalHours(piles, mid, h);
        
        if (currHours <= h){
            res = mid;
            right = mid - 1;
            // If currHours <= h, that means that is ok, but we should search
            // smaller k.
        }else{
            left = mid + 1;
            // If currHours > h, that is not ok, so we need larger k, to handle this.
        }
    }
    
    return res;
}

int main(){
    vector<int> piles = {3,6,7,11};
    int h = 8;    
    
    cout << minEatingSpeed(piles, h) << endl;
    
    return 0;
}
