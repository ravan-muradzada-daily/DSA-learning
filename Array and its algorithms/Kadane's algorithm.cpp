#include <iostream>
#include <climits>
using namespace std;

/*
The reason updating sum variable to 0 is that taking the values after reaching here
might be more useful for us, because imagine here: .... 5, 6, 7. Assume up to last point 
we have sum < 0. Increasing sum from here like sum += 5 is not useful a lot. Because if sum < 0,
the result will decrease, but it was 0, it cannot impact any. So thus, making it 0 is important.

*/

int KadaneAlgorithm(int arr[], int size){
    int sum = 0, maxSum = INT_MIN;
    
    for (int i = 0; i < size; ++i){
        sum += arr[i];
        maxSum = max(maxSum, sum);
        if (sum < 0) sum = 0;
    }
    
    return maxSum;
}

int main(){
    const int size = 11;
    int arr[size] = {4, 1, 5, -1, -3, 2, 0, -6, 9, 3, -7}; // Output: 14
    cout << KadaneAlgorithm(arr, size);
    return 0;
}
