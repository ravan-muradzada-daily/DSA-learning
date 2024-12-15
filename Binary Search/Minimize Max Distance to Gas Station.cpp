#include <bits/stdc++.h>
using namespace std;

class Solution_1{
private:
    Solution_1(){}
public:
    static double minimiseMaxDistance(vector<int> &arr, int k){
        int n = arr.size();   
        vector<int> countOfSt(n-1, 0);
        
        for (int gasSt = 1; gasSt <= k; ++gasSt){
            double maxDistance = -1;
            int maxDistanceIndex;
            
            for (int i = 0; i < n-1; ++i){
                double currDist = (double)(arr[i+1] - arr[i]) / (1+countOfSt[i]);
                
                if (currDist > maxDistance){
                    maxDistance = currDist;
                    maxDistanceIndex = i;
                }
            }
            
            countOfSt[maxDistanceIndex]++;
        }
        
        double maxDistance = -1;
        
        for (int i = 0; i < n-1; ++i){
            double currDistance = (double)(arr[i+1] - arr[i]) / (1+countOfSt[i]);
            maxDistance = max(maxDistance, currDistance);
        }

        return maxDistance;
    }
};

class Solution_2{
private:
    Solution_2(){}

public:
    static double minimiseMaxDistance(vector<int> &arr, int k){
        int n = arr.size();
        vector<int> countOfSt(n-1, 0);
        priority_queue<pair<double, int>> pq; // maxDistance, starting index
        
        for (int i = 0; i < n-1; ++i){
            pq.push({(double)arr[i+1]-arr[i], i});
        }
        
        for (int i = 1; i <= k; ++i){
            auto curr = pq.top();
            pq.pop();
            
            int index = curr.second;
            countOfSt[index]++;
            
            double newDiff = (double)(arr[index+1]-arr[index]) / (1 + countOfSt[index]);
            
            pq.push({newDiff, index});
        }
        
        return pq.top().first;
    }
    
    
    
};

class Solution_3{
private:
    Solution_3(){}
public:
    static double minimiseMaxDistance(vector<int> &arr, int k){
        int n = arr.size();
        
        double left = 0, right = 0;
        
        for (int i = 0; i < n-1; ++i){
            right = max(right, (double)(arr[i+1]-arr[i]));
        }
        
        
        double diff = 1e-9;
        
        while ((right-left)> diff){
            double mid = (right+left)/2;
            int currCount = calculateCurrCount(arr, mid);
            
            if (currCount > k){
                left = mid;
            }else{
                right = mid;
            }
        }
        
        return right;
    }
    
    static int calculateCurrCount(vector<int>& arr, double dist){
        int currCount = 0, n = arr.size();
        
        for (int i = 0; i < n-1; ++i){
            int diff = arr[i+1] - arr[i];
            int needed = diff / dist;
            
            if (needed * dist == diff){
                needed--;
            }
            
            currCount += needed;
        }
        
        return currCount;
    }
};
int main(){
    int k = 6;
    
    vector<int> arr = {1,2,3,4,5,6,7};
    
    cout << Solution_1::minimiseMaxDistance(arr, k) << "\n\n";
    cout << Solution_2::minimiseMaxDistance(arr, k) << "\n\n";
    cout << Solution_3::minimiseMaxDistance(arr, k) << "\n\n";
    
    return 0;
}
