import heapq as h
class Solution:
    '''
    We need two heap to store all data:
        big heap: to store smaller part data.(caution:python has no big heap package(python's heap or 
                                              priority queue is small heap), so we need to reverse data element by multipy -1;)
        small heap: to store bigger part data.
    Core method: 
        1. control two heaps' size to be equal.
        2. Do not let any big data into small heap and vice versa.
        3. we just need to choose element's location, not to calculate them when we find media-number.
        4. there are two cases when we find media-number, handle them diffrently, to know more by readign code.
    '''
    # two heaps
    bigHeap = []  #store smaller part data;
    smallHeap = []#store bigger part data;

    def medianII(self, nums):
        ret = []
        for i in nums:
            self.inser(i)
            ret.append(self.getMid()) 
        return ret
    
    def inser(self, num):
        ''' 
        Caution:
            U can only push data into smaller heap, then translate into bigger heap,
            or it will cause some mistakes(some big data will be pushed into smaller heap.
        '''
        h.heappush(self.smallHeap, num)
        h.heappush(self.bigHeap, -self.smallHeap[0])
        h.heappop(self.smallHeap)

        # balence the heap size;
        if len(self.bigHeap) > len(self.smallHeap):
            h.heappush(self.smallHeap, -self.bigHeap[0])
            h.heappop(self.bigHeap)

    def getMid(self):
        ''' 
        Warning: we just need to find location, Do not do any calculating;
        '''
        return -self.bigHeap[0] if (len(self.bigHeap)+len(self.smallHeap))&1==0 else self.smallHeap[0]


if __name__ == '__main__':
    Solution().medianII([23,2,3,44])