#include <bits/stdc++.h>
using namespace std;

int size = 5;

void nextPermutation(vector<int>& nums){
    int breakPoint = -1;
    for (int i = size - 2; i >= 0; --i){ // Finding the break point
        if (nums[i] < nums[i + 1]){
            breakPoint = i;
            break;
        }
    }
    if (breakPoint == -1){
        reverse(nums.begin(), nums.end());
        return;
    }
    for (int i = size - 1; i > breakPoint; --i){ // Finding the least element which is
        if (nums[i] > nums[breakPoint]){        // greater than nums[breakPoint]
            swap(nums[i], nums[breakPoint]);
            break;
        }
    }
    reverse(nums.begin() + breakPoint + 1, nums.end());
}


void printVector(vector<int>& nums, string s){
    cout << s;
    for (int i = 0; i < size; ++i){
        cout << nums[i] << " ";
    }
    cout << endl;
}


int main(){
    vector<int> nums(size); // example
    srand(time(NULL));
    for (int i = 0; i < size; ++i) nums[i] = rand() % 20;
    printVector(nums, "Before: ");
    nextPermutation(nums);
    printVector(nums, "After: ");
    return 0;
}


/*
Here, how algorithm works:
    First, we need to realize what is permutations and how they increase. They are 
    different(all) combinations of the given numbers.
    According to increasing principle, they increase. However, the increasing amount
    is the as possible as slighest. Such us, 1 2 3 is going to the least greater 
    sequence, which is 1 3 2.
    
    If we try to think logically, we can get that, if up to a specific number, all
    numbers are increasing, that means for that index of number, we do need to increase it.
    Likehood, 1 4 3 2.  Here, up to 1, numbers are increasing and that means that portion
    is in the greatest format of itself, so we cannot do anything to these numbers untill
    the index of 1 would change. So we can get that, up to here, all increasing proccess
    have done, now it is time for 1. However, we need to increase it asap slighest.
    For that we need to find least element from the ending of the array up to 1 itself.
    Of course, it is obvious that the number is 2. And we can swap 1 and 2.
    Now we get the sequence like 2 4 3 1. That refers, the period of 2 in the first index
    has started. So in all cases, 2 .... is bigger than 1 . . . 
    Thus untill 2 does not change its place (which is previous place of 1), we should 
    get the slighest version of the portion of sequence after that, which is
    2 1 3 4.
*/
