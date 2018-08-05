class Solution:
    """
    @param numbers: Give an array numbers of n integer
    @param target: An integer
    @return: return the sum of the three integers, the sum closest target.
    """
    def threeSumClosest(self, numbers, target):
        # write your code here
        numbers.sort()
        ps = 99999999999
        n = len(numbers)
        for i in range(n):
            j = i+1; k = n-1
            while(j<k):
                sum=numbers[i]+numbers[j]+numbers[k]
                #ps = (abs(target-sum)) < (abs(target-ps)) ? sum : ps
                ps = sum if ((abs(target-sum)) < (abs(target-ps))) else ps
                if sum<target:
                    j += 1
                elif sum > target:
                    k -= 1
                else:
                    return target
        return ps

if __name__ == "__main__":
    print(Solution().threeSumClosest([121,21,2,12,1,2,34,3,4324,13,41234,3], 362))