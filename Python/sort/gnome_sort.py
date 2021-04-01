"""
Gnome Sort algorithm implementation in Python3

Introduction:

It is a simple exchange sorting algorithm similar to insertion sort,
except that it moves an element to its proper place by a series of swaps,
as in bubble sort. In each iteration the algorithm finds the first place,
where two adjacent elements are in the wrong order and swaps them.
Afterwards it compares the swapped element with previous elements and
swaps them if they are in the wrong order. If adjacent elements are in
proper order or the end is reached, it starts a new iteration.
"""

def gnomeSort(nums):
    if len(nums) <= 1:
        return nums

    i = 1

    while i < len(nums):
        if nums[i - 1] <= nums[i]:
            i += 1
        else:
            nums[i - 1], nums[i] = nums[i], nums[i - 1]
            i -= 1
            if (i == 0):
                i = 1

user_input = input("Enter the numbers separated by a comma: ").strip()
nums = [int(item) for item in user_input.split(',')]
gnomeSort(nums)
print("Sorted nums of numbers using gnome sort method:", nums)

"""
Sample input:
Enter the numbers separated by a comma: 78,45,67,21,90

Sample output:
Sorted nums of numbers using gnome sort method: [21, 45, 67, 78, 90]

Best case time complexity: O(n)
Worst case time complexity: O(n^2)
Space complexity: O(1)
"""
