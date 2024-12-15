/* Given a string containing digits from 2-9 inclusive, return all possible letter 
   combinations that the number could represent. Return the answer in any order. */
#include <bits/stdc++.h>
using namespace std;
unordered_map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                  {'5', "jkl"},{'6', "mno"},{'7', "pqrs"},
                                  {'8', "tuv"}, {'9', "wxyz"}}; // The chars for each number.
vector<string> allCombinations;
void backtrack(string& curr, string& digits, int indx, int size){
    if (indx == size){
        allCombinations.push_back(curr);
    }
    
    for (int i = 0; i < mp[digits[indx]].size(); ++i){
        curr.push_back(mp[digits[indx]][i]); // Choose the character
        backtrack(curr, digits, indx + 1, size); // Explore further
        curr.pop_back(); // Backtract to try other characters
    }
    /*  Another possible and correct version of the for loop.
        for (char i: mp[digits[indx]]){
            curr.push_back(i);
            backtrack(curr, digits, indx + 1, size);
            curr.pop_back();
        }
    */
}

/* 
    For each character of digits string, we should start a new combination.
    Like if our the first char is '2', we should start combinations like
    "a..", "b..", "c..".
    After creating this we need to explore for the second char of string and continue
    up to end.
*/
int main(){
    string digits = "23";    
    int size = digits.length();
    string curr = "";
    backtrack(curr, digits, 0, size);
    for (string i: allCombinations){
        cout << i << endl;
    }
    
    return 0;
}
