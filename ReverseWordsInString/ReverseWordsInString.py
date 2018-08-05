class Solution:
    """
    @param: s: A string
    @return: A string
    """
    def reverseWords(self, s):
        if len(s)<1:
            return ''
        # write your code here
        s = s.strip()
        out = s.split(' ')
        out.reverse()
        return ' '.join(out)


if __name__ == "__main__":
    print(Solution().reverseWords('sdf ds fds af ds f dasf3r fads  asdf  dfs    '))