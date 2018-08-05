class Solution:
    """
    @param numbers: Give an array
    @param target: An integer
    @return: Find all unique quadruplets in the array which gives the sum of zero
    """
    def fourSum(self, numbers, target):
        # write your code here
        ret = []
        numbers.sort()
        n = len(numbers)
        for i in range(n):
            if i>0 and numbers[i] == numbers[i-1]:continue
            for j in range(i+1, n, 1):
                if j > (i+1) and numbers[j] == numbers[j - 1]: continue
                sum = numbers[i]+numbers[j]
                k, l = j+1, n-1
                while(k < l):
                    if k > (j+1) and numbers[k] == numbers[k-1]: k += 1; continue;
                    if l < (n-1) and numbers[l] == numbers[l+1] : l -= 1;continue;
                    tsum = sum + numbers[k] + numbers[l]
                    if tsum < target:
                        k += 1
                    elif tsum > target:
                        l -= 1
                    else:
                        ret.append([numbers[i],numbers[j],numbers[k],numbers[l]])
                        k += 1; l -= 1
        return ret

if __name__ == "__main__":
    print(Solution().fourSum([1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,\
                              -33,-5,-72,12,-34,100,0,0,-2,2,-5,99,1,2,5,6,7,3,5,8,-33,-5\
                                 ,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,\
                              99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,\
                              -33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,\
                              99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,\
                              -5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2\
                                 ,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,\
                              -72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,\
                              6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,\
                              -34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,\
                              -33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,\
                              2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99], 11))
