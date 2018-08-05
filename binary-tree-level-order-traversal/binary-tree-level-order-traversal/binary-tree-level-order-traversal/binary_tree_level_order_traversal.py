
import queue

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

class Solution:
    ret = []
    """
    @param root: A Tree
    @return: Level order a list of lists of integer
    """
    def levelOrder(self, root):
        tmp = []
        if root == None:return self.ret
        q = queue.Queue()
        q.put(root)

        while not q.empty():
            tmp.clear()
            qsize = q.qsize()
            for i in range(qsize):
                ele = q.get()
                tmp.append(ele.val)
                if ele.left != None:q.put(ele.left)
                if ele.right != None:q.put(ele.right)
            self.ret.append(list(tmp))
        return self.ret
            
            


if __name__ == '__main__':
    s = Solution()
    root = TreeNode(1)
    s.levelOrder(root)