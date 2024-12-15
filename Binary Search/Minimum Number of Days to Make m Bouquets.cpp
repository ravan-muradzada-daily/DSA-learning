#include <bits/stdc++.h>
using namespace std;

bool determine(vector<int>& bloomDay, int day, int m, int k){
    int count = 0, buckets = 0;
    
    for (int i = 0; i < bloomDay.size(); ++i){
        if (buckets >= m) return true;
        if (bloomDay[i] <= day){
            count++;
        }else{
            buckets += (count/k);
            count = 0;
        }
    }
    buckets += (count / k);
    
    return buckets >= m;
}

int minDays(vector<int>& bloomDay, int m, int k){
    int n = bloomDay.size();
    int left = *min_element(bloomDay.begin(), bloomDay.end());
    int right = *max_element(bloomDay.begin(), bloomDay.end());
    int midDay, res = -1;
    bool curr;
    
    while (left <= right){
        midDay = (left + right) / 2;
        curr = determine(bloomDay, midDay, m, k);
        
        if (curr){
            res = midDay;
            right = midDay - 1;
        }else{
            left = midDay + 1;
        }
    }
    
    return res;
}

int main(){
    vector<int> bloomDay = {7,7,7,7,12,7,7};
    int m = 2, k = 3;
    
    cout << minDays(bloomDay, m, k) << endl;
    
    return 0;
}
