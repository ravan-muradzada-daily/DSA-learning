#include <bits/stdc++.h>
using namespace std;

int missingK(vector<int>& nums, int k) {
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = nums[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    /*
        res = arr[h] + more
        miscount = arr[h] - (h+1)
        more = k-(miscount)
        res = arr[h] + k - (arr[h]-(h+1)) = k + h + 1
    */
    return k + high + 1;
}

int main(){
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, k);
    cout << "The missing number is: " << ans << endl;
    return 0;
}
