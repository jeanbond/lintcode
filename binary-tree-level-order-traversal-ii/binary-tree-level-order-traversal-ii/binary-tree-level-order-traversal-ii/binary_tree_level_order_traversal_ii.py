"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

import queue
import copy

class Solution:
    ret = []
    """
    @param root: A tree
    @return: buttom-up level order a list of lists of integer
    """
    def levelOrderBottom(self, root):
        # write your code here
        if root == None:return self.ret
        q = queue.Queue()
        q.put(root)
        tmp = []

        while not q.empty():
            tmp.clear()
            size = q.qsize()
            for i in range(size):
                e = q.get()
                if e.left != None: q.put(e.left)
                if e.right != None: q.put(e.right)
                tmp.append(e.val)
            self.ret.append(copy.copy(tmp))
        self.ret.reverse()
        return self.ret;

if __name__ == "__main__":
    pass