#include <bits/stdc++.h>
using namespace std;

vector<string> findRepeatedDnaSequences(string s){
    int n = s.length();
    if (n < 11) return {};
    vector<string> result;
    unordered_map<string, int> mp; // str, count
    
    for (int i = 0; i < n - 9; ++i){
        string curr = s.substr(i, 10);
        mp[curr]++;
        if (mp[curr] == 2){
            result.push_back(curr);
        }
    }
    
    return result;
}

int main(){
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    
    auto result = findRepeatedDnaSequences(s);
    
    for (string& i: result) cout << i << endl;
    
    return 0;
}
