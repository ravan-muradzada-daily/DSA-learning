#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals){
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result(1, {intervals[0][0], intervals[0][0]});
    
    int lastIndex = 0;
    
    for (int i = 0; i < n; ++i){
        if (result[lastIndex][1] >= intervals[i][0]){
            result[lastIndex][1] = max(result[lastIndex][1], intervals[i][1]);
        }else{
            result.push_back(intervals[i]);
            lastIndex++;
        }
    }
    
    return result;
}

/*
    If the first element of the current interval is less
    (or equal) than the second element of last merged interval
    interval in result, that refers these should merge. However, there
    are two cases: one is like {1, 4}, {2, 6}. In that case some part
    of the second interval is already in the first one, those we can 
    write {1, 6}. However, the examples like {1, 4}, {2, 3}, again 
    4>=2, but 3 is also less than 4. That refers the second interval 
    is subinterval of the first one. Thus we just write {1, 4}.
    From here, we can get a result like the ending point of merged 
    interval should be the maximum of the second elements of two 
    intervals.
    If the first element of the current interval is more than 
    the second element of the last marged interval, that means this is
    the new interval and we can add it to the result array.
*/

int main(){
    vector<vector<int>> intervals = {{1,4}, {2,6}, {8,10}, {15,18}};
    auto result = merge(intervals);
    
    for (auto& i: result){
        for (int j: i){
            cout << j << " ";
        } cout << "\t";
    }
    
    return 0;
}
