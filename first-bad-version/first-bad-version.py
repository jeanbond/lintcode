"""
class SVNRepo:
    @classmethod
    def isBadVersion(cls, id)
        # Run unit tests to check whether verison `id` is a bad version
        # return true if unit tests passed else false.
You can use SVNRepo.isBadVersion(10) to check whether version 10 is a
bad version.
"""


class Solution:
    """
    @param: n: An integer
    @return: An integer which is the first bad version.
    """
    def findFirstBadVersion(self, n):
        if n < 1: return -1
        l, h = 1, n
        while(l <= h):
            mid = (l + h) // 2
            if SVNRepo.isBadVersion(mid):
                h = mid - 1
            else:
                l = mid + 1
        return l

if __name__ == '__main__':
    print('这个用力因为包含内部方法，所以不能本地测试；LC平台测试已通过！')