/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
using namespace std;

#include<iostream>
#include<stack>

class TreeNode {
public:
     int val;
     TreeNode *left, *right;
      TreeNode(int val) {
          this->val = val;
          this->left = this->right = NULL;
      }
  };

class BSTIterator {
public:
     stack<TreeNode *> s;
public:
    /*
    * @param root: The root of binary tree.
    */BSTIterator(TreeNode * root) {
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
    }

    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        return !s.empty();
    }

    /*
     * @return: return next node
     */
    TreeNode * next() {
        if(!hasNext()){
            return NULL;
        }
        TreeNode *ou = s.top();
        TreeNode *out = ou;
        s.pop();

        //Caustion: time limit problem will be caused here;
        if(ou->right != NULL){
            ou = ou->right;
            while(ou != NULL){
                s.push(ou);
                ou = ou->left;
            }
        }
        
        return out;
    }
};

int main()
{
    cout<<"test"<<endl;
    return 0;
}
