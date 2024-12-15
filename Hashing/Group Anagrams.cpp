// Given an array of strings strs, group the anagrams together.
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams_1(vector<string>& strs){ // Using count array
    vector<vector<string>> result;
    map<vector<int>, vector<string>> mp;    
    
    vector<int> count;
    
    for (string& s: strs){
        count.assign(26, 0);
        for (char i: s){
            count[i - 'a']++;
        }
        mp[count].push_back(s);
    }
    
    for (auto& i: mp){
        result.push_back(i.second);
    }
    
    return result;
}

vector<vector<string>> groupAnagrams_2(vector<string>& strs){ // Using sorting
    vector<vector<string>> result;
    unordered_map<string, vector<string>> mp; // First is sorted str, others are proper ones.
    
    for (string& s: strs){
        string x = s;
        sort(x.begin(), x.end());
        mp[x].push_back(s);
    }
    
    for (auto& i: mp){
        result.push_back(i.second);
    }
    return result;
}

void printResult(vector<vector<string>>& strs){
    for (auto& s: strs){
        for (string& i: s){
            cout << i << " ";
        } cout << endl;
    }
    cout << "\n\n\n";
}

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = groupAnagrams_1(strs); // groupAnagrams_2(strs);
    
    printResult(result);

    return 0;
}
