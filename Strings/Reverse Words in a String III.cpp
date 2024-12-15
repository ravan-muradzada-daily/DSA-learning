#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s){
    int i = 0, j = 0, n = s.length();
    
    while (j <= n){
        if (s[j] == ' ' || s[j] == '\0'){
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1; j++;
        }
        j++;
    }
    return s;
}

int main(){
    string s = "Let's take LeetCode contest";
    string reversedString = reverseWords(s);
    
    cout << reversedString;
    
    return 0;
}
