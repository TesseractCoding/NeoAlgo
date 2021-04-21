"""
Egg Dropping Puzzle

Imagine there is a building of N floors and you have K eggs.
How many minimum number of attempts it would take to find the minimum floor (or first floor) F (0 <= f <= N) 
    where any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. 

Each move, you may take an unbroken egg and drop it from any floor f (where 1 <= f <= N). 
If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.


Input: Number of floors, number of eggs
Output: An integer denoting the number of minimum moves it would take.

Thoughts: 
When we drop an egg from a floor f, there can be two cases:
1. The egg breaks 
    We only need to check for floors below f with the remaining eggs. So the problem reduces to (K - 1) eggs with (f - 1) floors
2. The egg doesn’t break. 
    We only need to check for floors above f with the remaining eggs. So the problem reduces to (K) eggs and (N - f) floors.

So, if we write the above 2 cases in a recursive relation, it will be as below:

    min(1 + findFloorHelper(K - 1, f - 1), findFloorHelper(K, N - f))

But, the above approach has a time complexity of O(K * N * N) and there exists much optimal solutions than the above.

Approach:
Let's think of the problem in a different way.
We have K eggs and M attempts to determine the 'critical floor' in a N floors building findFloor(K, M).
We use 1 egg and 1 attempt to check if the current floor we are at is indeed 'critical'.

Now, if the egg breaks, we can use (K - 1) eggs and (M - 1) attempts to find the floor with findFloor(K - 1, M - 1).
if the egg doesn't break, we can use (K) eggs and (M - 1) attempts to find the floor with findFloor(K, M - 1).

So, the relation becomes this:
    findFloor(K, M) = 1 + findFloor(K - 1, M - 1) + findFloor(K, M - 1)

We are not taking the maximum above because we try with one egg first. If it is broken, the target floor is below the current floor, else it's above. 
So the number of detected floor is the sum of the two. (above + below + current)

//The below code is contributed by Jahnavi Majji as a part of GSSoC'21.
"""


def findFloor(numFloors, numEggs):
    cache = [0 for _ in range(numEggs + 1)]
    #cache[i] stores the value of max floors we can use i eggs and m attemps to detect.

    attempts = 0
    while(cache[numEggs] < numFloors) :
        for i in range(numEggs, 0, -1):
            cache[i] = 1 + cache[i] + cache[i - 1]

        attempts += 1

    return attempts

if __name__ == '__main__':
    print("Enter the number of floors: ")
    numFloors = int(input())
    print("Enter the number of eggs: ")
    numEggs = int(input())
    print("The critical floor is: ", findFloor(numFloors, numEggs))

""" 
Sample Input: 
Enter the number of floors: 14
Enter the number of eggs: 3
    
Output: 
The critical floor is: 4
    
Time Complexity: O(K * log(N)) where K = eggs we have and N = building height we are on.
Space Complexity: O(K)

"""
