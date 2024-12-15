#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices){
    int n = prices.size(), profit = 0;
    
    for (int i = 1; i < n; ++i){
        if (prices[i] > prices[i-1]){
            profit += (prices[i] - prices[i-1]);
        }
    }
    
    return profit;
}

/*
    We can use dp here, but that is useless. Instead we can just use Greedy algorithm
    to solve it and that is it!
    
    To understand the solution, imagine the prices as a graph like:
    
    |
  7 | *
  6 |                         *
  5 |           *
  4 |                                 *
  3 |                 *
    |
  1 |     *
    |

    Here, there are just 2 ascending line, which are (1-5) and (3-6). If we compute just these, the result will appear!
*/

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    
    cout << maxProfit(prices) << endl;
    
    return 0;
}
