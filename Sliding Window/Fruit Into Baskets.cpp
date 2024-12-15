#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits){
    int n = fruits.size();
    if (n <= 2) return n;
    int left = 0, maxLen = 0;
    unordered_map<int, int> mp; // nums, counts
    
    for (int right = 0; right < n; ++right){
        mp[fruits[right]]++;
        if (mp.size() > 2){
            mp[fruits[left]]--;
            if (mp[fruits[left]] == 0) mp.erase(fruits[left]);
            left++;
        }
        maxLen = right - left + 1;
    }
    return maxLen;
}

int main(){
    vector<int> fruits = {1, 2, 3, 2, 2};
    
    cout << totalFruit(fruits) << endl;
    
    return 0;
}
