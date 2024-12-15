/*
  You can read full description of that problem in that link:  https://leetcode.com/problems/non-overlapping-intervals/
We try to remove the least amount of intervals from our vector matrix to get not - overlapping intervals series.
We know each interval has a starting point and ending point. I will show borders of the intervals using '@' and '-' along the intervals.
According to description, intervals should be like that:  [1, 5]; [2, 9]; [5, 11]... So the starting points of the
each intervals should increase in every step. By default, the end points is bigger than its staring points. 
#So we can describe correct version of the interval series like that:
@----@           @----@  
     @----@ @----@  
--> If the interval's end point is equal to the next interval's starting point, that is also true.
Let's analyze incorrect version of the interval series where we should remove some intervals.
--> However, before that, we need to know the form of our matrix. So our matrix contains intervals which has 2 elements in each interval, if we assume there is n interval, our matrix will be like that: intervals[n][2] <--
#First possibility:
@---@        @----@
   @---@ @---@ 
It is easily seen that the first and the second intervals overlap. From that example we can set the rule like that:
interval[current][0] >= interval[previous][1]. That is our main rule and we will use it, remember it as a main rule for our solution. Think the current and previous as the first and the second intervals, respectively.
İf this condition is not met, that means there is a problem and one interval should be removed, we are sure with that. But which one? In that senario, we can delete either the first one or the second one, it does not matter. To give an exact answer to that questin we need to analyze more senarios.

#Second possibility:
@--------@   @---@
  @--@  @---@  
You can see both the first, second and third intervals overlap. Let's think which one should we remove? Of cours the bigger one! Because, otherwise we need to remove both the first and the third at the same time which is not minimum, but removing just the second with one removing process we reach the goal.

From that we can realize, if the one interval contains the other completely, it is better to remove larger one, because the larger one generate more risk that the smaller one. (Risk means the possibilty of causing overlapping).
How to understand that one interval contains the other? It happens when the main rule is broken and at the same time if the previous interval's end points is bigger that current interval's end points.
a--------b
  c---d
Such us, from that example we saw, our main rule is broken, because the condition of "b >= c" is not met. In addition, at the same time, "b > d", so that implies the previous interval contains the the next one.

Let's merge all the key points. If the condition of "interval[current][0] >= interval[previous][1]" is met, there is no problem yet, we can go through. Otherwise there is a problem and we need to remove one interval. If one contains the other, the bigger one shoul be removed.

Now, let's speak about "removing". Actually when I said "removing" each time in that explanation, I do not mean to delete the interval from the matrix. I mean we can slip that and do not consider and care that.

Let's write Pseudo code for that problem.
 int eraseOverlapIntervals(intervals[n][2]) { 
    int count = 0, previous = 1, current = 1; 
    while (current < n){
      if (intervals[current][0] > intervals[previous][1]){ // If everything is ok and there is not any overlapping yet
        previous = current;   // That means because there is no problem you can go through the next pair of intervals, because of that we increase previous like that.
                            // (current will increase after if - else).
      }
      else{ // That means there is a overlapping.
        count++; // Automatically increment the count which represents the number of the overlappings.
        if (intervals[previous][1] >= intervals[current][1]){ // To check whether the previous interval contain the next one, or not.
          previous = current; // If yes, we should not care the "previous" (it is larger) and take new intervals.
        }
      }
      current += 1;
    }
  }     

  
İt's almost over! There is just one important point that the given intervals in the matrix is not the correct order. Such us, the first interval may be given at the last, the second one may be given firstly and so on. Like the intervals is not given in the ascending order, it is mixed. So we need to sort them. Due to the logic of the intervals, their starting points should be in the ascending order(actually non-decreasing, because the starting points may be the same in some cases). (Endpoints can be or not. If endpoints is not ascending there is an overlap).
So we should sort them in the non-decreasing order due to their starting points. In C++, we have build-in sort function, which can do it. If in other languages, that exists you can use, otherwise you can write your own sort function.

In that example, I will show the solution in C++
*/


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0, previous = 0, current = 1;
        while (current < intervals.size()){
            if (intervals[current][0] >= intervals[previous][1]){
                previous = current;
            }else{
                count++;
                if (intervals[previous][1] >= intervals[current][1]){
                    previous = current;
                }
            }
            current++;
        }
        return count;
    }        
};
