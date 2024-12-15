#include <bits/stdc++.h>
using namespace std;

string getHint(string secret, string guess){
    int n = secret.length(), bulls = 0, cows = 0;
    unordered_map<char, int> mp;
    
    for (int i = 0; i < n; ++i){
        if (secret[i] == guess[i]){
            bulls++;
        }else{
            mp[secret[i]]++;
        }
    }
    
    for (int i = 0; i < n; ++i){
        if (secret[i] != guess[i] && mp[guess[i]] > 0){
            cows++;
            mp[guess[i]]--;
        }
    }
    
    return to_string(bulls) + "A" + to_string(cows) + "B";
}


int main(){
    string secret = "1807", guess = "7810";
    
    cout << getHint(secret, guess);
    
    
    return 0;
}
