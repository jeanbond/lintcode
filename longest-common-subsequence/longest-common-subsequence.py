class Solution:
    """
    @param A: A string
    @param B: A string
    @return: The length of longest common subsequence of A and B
    """
    def longestCommonSubsequence(self, A, B):
        # write your code here
        if len(A) < 1 or len(B) < 1: return 0
        ans = [[0 for i in range(len(B)+1)] for j in range(len(A)+1)]
        for i in range(1, len(A)+1):
            for j in range(1, len(B)+1):
                if A[i-1] == B[j-1]: ans[i][j] = ans[i-1][j-1] + 1
                else:ans[i][j] = min(ans[i-1][j], ans[i][j-1])
        return ans[len(A)][len(B)];

if __name__ == '__main__':pass
