// Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string. Find all permutations
#include <bits/stdc++.h>
using namespace std;

vector<string> allPermutations;

void backtrack(string& s, int indx, int size){
    if (indx == size){
        allPermutations.push_back(s);
        return;
    }
    
    if (isalpha(s[indx])){
        s[indx] = s[indx] ^ 32;
        backtrack(s, indx + 1, size);
        s[indx] = s[indx] ^ 32;
    }
    backtrack(s, indx + 1, size);
}
/*
    First, we should understand what ^32 means. It helps us to convert the letter to uppercase,
    if it is lowercase, otherwise to lowercase.
    So in each if condition (12th line), we check whether the current index is letter or not.
    If not the nothing changes and the process continues for the next index. Otherwise, 
    we change the letter and send it to function (creating new reailty). To get all possible cases,
    we return it to back using ^32 again and send it to function without the change of the current index.
*/
int main(){
    string s = "a1b2";
    int size = s.length();
    
    backtrack(s, 0, size);
    
    for (string i: allPermutations){
        cout << i << endl;
    } 
    return 0;
}
