class Solution:
    """
    @param numbers: Give an array numbers of n integer
    @return: Find all unique triplets in the array which gives the sum of zero.
    """
    def threeSum(self, numbers):
        ret = []
        numbers.sort()
        n = len(numbers)
        for i in range(n):
            if i>0 and numbers[i] == numbers[i-1]:
                continue;
            j = i+1; k = n-1
            while(j<k):
                if j>(i+1) and numbers[j]==numbers[j-1]:
                    j += 1 ;continue;
                if k < n-1 and numbers[k]==numbers[k+1]:
                    k -= 1; continue;
                sum = numbers[i] + numbers[j] + numbers[k]
                if sum < 0:
                    j += 1
                elif sum > 0:
                    k -= 1
                else:
                    ret.append([numbers[i], numbers[j], numbers[k]])
                    j += 1; k -= 1
        return ret

if __name__ == "__main__":
    print(Solution().threeSum([3,4343,4,2,34,234,3434,32423,4,324,23]))