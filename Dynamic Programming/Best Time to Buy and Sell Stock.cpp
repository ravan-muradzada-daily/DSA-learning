#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices){
    int n = prices.size(), result = 0, least = prices[0];
    
    for (int i = 1; i < n; ++i){
        result = max(result, prices[i] - least);
        least = min(least, prices[i]);
    }
    return result;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    
    cout << maxProfit(prices) << endl;

    return 0;
}
