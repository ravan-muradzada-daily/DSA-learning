#include <bits/stdc++.h>
using namespace std;

vector<string> allPossible_IP_Addresses;

int convert(char a, char b, char c){
    return (a - '0') * 100 + (b - '0') * 10 + (c - '0');
}

void backtrack(string curr, string& str, int indx, int size, int dotCount){
    if (dotCount == 4 && indx == size){
        curr.pop_back();
        allPossible_IP_Addresses.push_back(curr);
        return;
    }
    if (dotCount > 4 || indx > size) return;
    
    if (indx == size - 1 || str[indx] == '0'){
        backtrack(curr + str[indx] + ".", str, indx + 1, size, dotCount + 1);
    }else{
        backtrack(curr + str[indx] + str[indx + 1] + ".", str, indx + 2, size, dotCount + 1);
        backtrack(curr + str[indx] + ".", str, indx + 1, size, dotCount + 1);
        if (indx < size - 2 && convert(str[indx], str[indx + 1], str[indx + 2]) <= 255){
            backtrack(curr + str[indx] + str[indx + 1] + str[indx + 2] + ".", str, indx + 3, size, dotCount + 1);
        }
    }
}

int main(){
    // The size of the string should be less than 12 or be equal.
    string str = "25525511135", curr = "";
    int size = str.length();
    backtrack(curr, str, 0, size, 0);
    
    for (string i: allPossible_IP_Addresses){
        cout << i << endl;
    }

    return 0;
}
