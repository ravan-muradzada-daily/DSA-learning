#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings_1(string s);

int numberOfSubstrings_2(string s);

int main(){
    string s = "abcabc";
    
    cout << numberOfSubstrings_1(s) << "\n\n";
    cout << numberOfSubstrings_2(s) << "\n\n";
    
    return 0;
}

int numberOfSubstrings_1(string s){
    int n = s.length();
    int left = 0, count = 0;
    unordered_map<char, int> mp; // letter, count
    
    for (int right = 0; right < n; ++right){
        mp[s[right]]++;
        
        while (mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1){
            count += (n - right);
            mp[s[left]]--;
            left++;
        }
    }
    
    return count;
}

int numberOfSubstrings_2(string s){
    int n = s.length(), count = 0;
    int lastSeen[3] = {-1, -1, -1};
    
    for (int i = 0; i < n; ++i){
        lastSeen[s[i] - 'a'] = i;
        if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
            count += (1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2])));
        }
    }
    
    return count;
}

/*
    Explanation for the first method: While traversing the string up to the end, it we find
    all the characters at least one, that means we find one of the possible smallest substring.
    So the chars after that can be additional, thus we add like count += (n - right);
    Here we calculate possibilities from the current index up to the end.
*/

/*
    Here we just calculate reverse. So we calculate the possibilities from the 0 up to the current index.
    If each char appears at least once, we try to find the smallest partion of it.
*/
