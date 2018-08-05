class Solution:
    """
    @param strs: A list of strings
    @return: The longest common prefix
    """
    def longestCommonPrefix(self, strs):
        # write your code here
        if len(strs) <= 1:
            return strs[0] if len(strs) == 1 else ''
        end, minl = 0, min(len(i) for i in strs)
        while end < minl:
            for i in range(1, len(strs)):
                if strs[i][end] != strs[i-1][end]:
                    return strs[0][:end]
            end += 1
        return strs[0][:end]

if __name__ == '__main__':
    print(Solution().longestCommonPrefix(['abcdef', 'abcdfffff']))