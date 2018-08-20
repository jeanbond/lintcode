
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None    
    
class Solution:
    ''' 
    Solve the BST-delete operation
        recursion method
        Consider 3 kinds situation:
            1/when del node is a leaf, remove it immediately;
            2/when del node has one leaf(child) node, use child node replace it;
            3/when del node has two leave(left and right child all exist), we should find 
            their post-inherit node to replace it, (opa: find this node's post-inherit's min node, 
            then use the post-inherit's min node to replace del-node, fix del-node(min-node)'s left
            child, remove post-inherit's min node at the same time);
    '''
    def findMinNode(self, root):
        if root.left == None:
            return root
        else:
            return self.findMinNode(root.left)
    
    def delMinNode(self, root):
        if root.left == None:
            return root.right
        root.left = self.delMinNode(root.left)
        return root

    def removeNode(self, root, value):
        '''
        recursion method;
        '''
        # leaf;
        if root == None:
            return root
        #one child;
        if value < root.val:
            root.left = self.removeNode(root.left, value)
        elif value > root.val:
            root.right = self.removeNode(root.right, value)
        else:
            #two children;
            if root.left == None:
                return root.right
            if root.right == None:
                return root.left
            tmp = root
            #use post-inherit replace;
            root = self.findMinNode(root.right)
            #remove post-inherit's min node;
            root.right = self.delMinNode(tmp.right)
            #fix left child;
            root.left = tmp.left
        return root

if __name__ == '__main__':
    pass
