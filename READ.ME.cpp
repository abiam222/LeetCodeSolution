This is the solution and analysis of 'Check If All 1's Are at Least Length K Places Away'

#1437
Link: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/

The solution is either on my profile
http://leetcode.com/profile/abiam222

or in the solutions.cpp file in this repository



How do we approach this solution?

Given an array of nums of 0's and 1s and an integer k,
We want to see if all 1's are at least k places away.

Assumptions and Base cases: 
If k=2 then all the 1's will either either 2 or more places away.

One of our main assumptions is that the array can start with a
0 or a 1

We can also assume that we will have data coming back from our array


Solution:

When we find '1' we need to make sure that then next 1 is k places away. 
From this intuition it doesn't matter if we start with a zero or the array
Is 0,0,0,1,0,1 we want to start counting out k places starting at 1

We will go through the array (aka for loop or while loop) through each index
and figure out couple of things:
	if its a zero, count the zero because it should be 'k' places apart from a 1
 	if its a 1, make sure that our count was at least 'k' places apart from a 1


	while (size of array)
		//its a zero
		//we keep count of our zeros (aka 'm')
		if (nums[i]==0)m++;

		//its a 1
		//make sure we were 'k' places apart
		//'m' is our count of places apart
		if (nums[i]==1){
			//if out count is less than 'k' then the 1's are too close to each other
			if (m<k){
			   found = false; 	
			}
		}
		 
	We also have a case where if array start with '1' then 'm'(our count) will be less than k
        But this doesn't necessarily mean that our answer is false. So we will add this case.
	
	if (nums[i]==1 && i!=0){ ... }
     
Analysis:

   Our current algorithm runs O(n) linear time. This is so because we have to iterate through each 
   Index in our array to calculate each zero and one.

  Can we improve our algorithm?

  In our algorithm if we find that our 1's are too close we continue processing our loop. This can hinder
  performance. What we can do is, if we find that our 'count' is less than 'k' then we can break out
  Of our loop
	if (m < k)
	     found = false;
	     break;
Where our performance will be O(n) for worst case scenario. This is if all 1's are at least k places from each other. And O(m) for best case scenario. This is if 1's aren't at least k places form each other and 'm' is the index of where we found this scenario.

   We are using new variables but keeping our same array. Hence our space memory for variables is just O(1) and for our array O(n). 