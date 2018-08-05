

class Solution:
    """
    @param A: A string
    @param B: A string
    @return: the length of the longest common substring
    """
    def longestCommonSubstring(self, A, B):
        if len(A) < 1 or len(B) < 1: return 0
        ans = [[0 for i in range(len(B) + 1)] for j in range(len(A)+1)]
        maxval = -1
        for i in range(1, len(A)+1):
            for j in range(1,len(B)+1):
                if A[i-1] == B[j-1]:ans[i][j] = ans[i-1][j-1] + 1
                maxval = max(maxval, ans[i][j])
        return maxval

if __name__ == "__main__":
    print(Solution().longestCommonSubstring('abcd', 'abc'))