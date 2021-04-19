"""Length of Longest Common Subsequence problem in Julia

Given two strings, we have to find the largest common subsequence in Julia

The problem can be solved using Dynamic Programming
"""

function lengthoflongestcommonsubsequence(S1, S2)
    # Build a 2D matrix in Bottom-Up manner. Every element
    # dp[i][j] contains the length of the longest common subsequence
    # of S1[0 .. i] and S2[0 .. j].
    n = length(S1)
    m = length(S2)

    # Fill every element of the 2D matrix with 0 as value
    dp = zeros(Int, n + 1, m + 1)

    for i in 1:(n + 1)
        for j in 1:(m + 1)

            # length of LCS when one of the string is empty is zero
            if i == 1 || j == 1
                dp[i,j] = 0

            # If the elements of both the strings match, then
            # the value of LCS increments by one.
            elseif S1[i - 1] == S2[j - 1]
                dp[i,j] = dp[(i - 1),(j - 1)] + 1
            else
            # Either include the last element from one string and exclude it from the other and 
            # compare them and vice versa and pick the one giving the maximum length out of the two 
                dp[i,j] = max(dp[(i - 1),j], dp[i,(j - 1)])
            end
        end
    end
    return dp[(n + 1),(m + 1)]
end


print("Enter the first string: ")
s1 = readline()
print("Enter the second string: ")
s2 = readline()
res = lengthoflongestcommonsubsequence(s1, s2)
print("The length of the longest common subsequence is ")
print(res)


# Time Complexity: O(n * m), where n, m are the size of the given strings
# Space Complexity: O(n * m)

# SAMPLE INPUT AND OUTPUT

# Enter the first string: cuckoo
# Enter the second string: cucumber
# The length of the longest common subsequence is 3
