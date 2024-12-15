#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p){
    int n = s.length(), m = p.length();
    int left = 0;
    vector<int> v1(26, 0), v2(26, 0), result;
    
    for (char i: p) v1[i - 'a']++;
    
    for (int right = 0; right < n; ++right){
        v2[s[right] - 'a']++;
        if ((right - left + 1) == m){
            if (v1 == v2) result.push_back(left);
            v2[s[left] - 'a']--;
            left++;
        }
    }
    
    return result;
}

int main(){
    string s = "cbaebabacd", p = "abc";
    
    auto result = findAnagrams(s, p);
    
    for (int i: result) cout << i << " ";
    
    return 0;
}
