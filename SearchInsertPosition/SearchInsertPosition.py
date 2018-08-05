class Solution:
    """
    @param A: an integer sorted array
    @param target: an integer to be inserted
    @return: An integer
    """
    def searchInsert(self, A, target):
        start, end = 0,len(A) - 1
        #二分法的时候注意，start和end大小判断的时候，等于是否需要，一定要想清楚，大部分的时候是需要的
        #但是也有不用=的情况，如果用等号，在能找到元素的时候没差异，但是在找不到元素的时候会返回插入位置
        #切记
        while(start <= end):
            midLoc = (start + end) // 2
            if A[midLoc] < target:
                start = midLoc + 1
            elif A[midLoc] > target:
                end = midLoc - 1
            else:return midLoc
        return start

if __name__ == "__main__":
    print(Solution().searchInsert([1,3,5,6,8,9], 7))