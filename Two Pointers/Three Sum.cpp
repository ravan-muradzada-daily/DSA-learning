#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ThreeSum_1(vector<int>& nums){
    // Brute Force
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int n = nums.size();
    for (int i = 0; i < n; ++i){
        if (i != 0 && nums[i] == nums[i-1]) continue;
        for (int j = i + 1; j < n; ++j){
            if (j != i+1 && nums[j] == nums[j-1]) continue;
            for (int z = j + 1; z < n; ++z){
                if (z != j+1 && nums[z] == nums[z-1]) continue;
                if (nums[i] + nums[j] + nums[z] == 0){
                    result.push_back({nums[i], nums[j], nums[z]});
                }
            }
        }
    }
    // Time complexity: O(n^3)
    // Space complexity: O(1)
    return result;
}

vector<vector<int>> ThreeSum_2(vector<int>& nums){
    // Better approach
    sort(nums.begin(), nums.end());
    int n = nums.size();
    unordered_set<int> st;
    set<vector<int>> all;
    for (int i = 0; i < n; ++i){
        if (i != 0 && nums[i] == nums[i-1]) continue;
        st.clear();
        int target = -nums[i];
        for (int j = i + 1; j < n; ++j){
            if (st.find(target - nums[j]) != st.end()){
                all.insert({nums[i], nums[j], target - nums[j]});
            }
            st.insert(nums[j]);
        }
        
    }
    vector<vector<int>> result(all.begin(), all.end());
    
    // Time complexity: O(n^2)
    // Space complexity: ~O(n)
    
    return result;
}

vector<vector<int>> ThreeSum_3(vector<int>& nums) {
    // The best approach
    sort(nums.begin(), nums.end());
    int n = nums.size(), j = 0, k = 0, target;
    vector<vector<int>> result;
    
    for (int i = 0; i < n; ++i){
        if (i != 0 && nums[i] == nums[i-1]) continue;
        
        j = i + 1;
        k = n - 1;
        target = -nums[i];
        while (j < k){
            if (nums[j] + nums[k] < target){
                k--;
            }else if (nums[j] + nums[k] > target){
                j++;
            }else{
                result.push_back({nums[i], nums[j], nums[k]});
                j++; k--;
                while (j < k && nums[j] == nums[j-1]) j++;
                while (j < k && nums[k] == nums[k+1]) k--;
            }
        }
        
    }
    // Time complexity: O(n^2)
    // Space complexity: O(1)
    return result;
}

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4,2};
    // -4, -1, -1, 0, 1, 2, 2
     
    auto result = ThreeSum_3(nums);
    
    for (auto& i: result){
        for (int j: i){
            cout << j << " ";
        } cout << endl;
    }
    
    
    return 0;
}
