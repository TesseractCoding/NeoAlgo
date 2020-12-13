# Importing sys module to initalize the maxsize
import sys
# Importing collection model to acess deque
from collections import deque
''' Knight-Walk '''
'''Problem Statement :Given a chess board of order N x M and
                      source points (s1, s2) and destination
                      points (d1, d2). The task to find minimum
                      number of moves required by the Knight to
                      go to the destination cell.
                      Note: The chess board consists of rows
                      numbered (1 to N) and columns (1 to M).
'''
# Assigning max value a variable can take
INT_MAX = sys.maxsize - 1
# Initialize Infinity
INF = 9999999
# All the posible moves of the knight
row = [2, 2, -2, -2, 1, 1, -1, -1]
col = [-1, 1, 1, -1, 2, -2, 2, -2]
# Create the Node


class Node:
    def __init__(self, x, y, dis=0):  # Distance of self from itself
        self.x = x
        self.y = y
        self.dis = dis

    # Since we are using the nodes as a hash we will need a
    # hashtable
    def __hash__(self):
        return hash((self.x, self.y, self.dis))

    def __eq__(self, other):
        return (self.x, self.y, self.dis) == (other.x, other.y, other.dis)

# Enter the number of rows
print("Enter the number of matrix : ")
n = int(input("Row:"))
# Taking input of the address of the source and destination
# as a tuple
print("Enter the source:")
x = int(input("src1:"))
y = int(input("src2:"))
src = Node(x, y)
print("Enter the source:")
x = int(input("des1:"))
y = int(input("des2:"))
des = Node(x, y)
# Knight Walk


def kinghtwalk(n, src, des):
    # Set to check if the cell is visited or not
    visited = set()
    # Create the queue to check the next reachable cell
    queue = []
    queue.append(src)
    # Loop while the queue is empty
    while queue:
        node = queue.pop(0)
        x = node.x
        y = node.y
        dis = node.dis
        if x == des.x and y == des.y:
            return dis
        if node not in visited:
            visited.add(node)
            for i in range(8):
                a = x + row[i]
                b = y + row[i]
                if present(a, b, n):
                    queue.append(Node(a, b, dis + 1))

# Check if the given node is valid or not
                    
                    
def present(a, b, n):
    # If either one of then is not true it mean the cell is
    # outside the board
    return not(a < 0 or y < 0 or x >= n or y >= n)

KW = kinghtwalk(n, src, des)
print("The shortest paths are {}".format(KW))
''' 
Sample input:
    Enter the sides of the Matrix :
    Enter the Row and the Column
    Row:4
    Column:4
    Enter the integers:
    0 3 INF 5 2 0 INF 4 INF 1 0 INF INF INF 2 0
Sample Output:
    The shortest paths are
    0 3 7 5
    2 0 6 4
    3 1 0 5
    5 3 2 0
'''
# Time complexity: O(N^2)

