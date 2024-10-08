//Header file: binaryTree.h

#ifndef H_binaryTree
#define H_binaryTree

#include <iostream> 
#include "myStack.h"

using namespace std;

    //Definition of the Node
template <class elemType>
struct nodeType 
{
    elemType info;
    nodeType<elemType> *lLink;
    nodeType<elemType> *rLink;
};
	
    //Definition of the class
template <class elemType>
class binaryTree
{
public:
    const binaryTree<elemType>& operator=
                 (const binaryTree<elemType>&); 
      //Overload the assignment operator.

    bool isEmpty() const;
      //Function to determine whether the binary tree is empty.
      //Postcondition: Returns true if the binary tree is empty;
      //               otherwise, returns false.

    void inorderTraversal() const;
      //Function to do an inorder traversal of the binary tree.
      //Postcondition: Nodes are printed in inorder sequence.

    void preorderTraversal() const;
      //Function to do a preorder traversal of the binary tree.
      //Postcondition: Nodes are printed in preorder sequence.

    void postorderTraversal() const;
      //Function to do a postorder traversal of the binary tree.
      //Postcondition: Nodes are printed in postorder sequence.

    void nonRecursiveInTraversal() const;
    void nonRecursivePreTraversal() const;
    void nonRecursivePostTraversal() const;

    int treeHeight() const;
      //Function to determine the height of a binary tree.
      //Postcondition: Returns the height of the binary tree.

    int treeNodeCount() const;
      //Function to determine the number of nodes in a 
      //binary tree.
      //Postcondition: Returns the number of nodes in the 
      //               binary tree.

    int treeLeavesCount() const;
      //Function to determine the number of leaves in a 
      //binary tree.
      //Postcondition: Returns the number of leaves in the 
      //               binary tree.

    void destroyTree();
      //Function to destroy the binary tree.
      //Postcondition: Memory space occupied by each node 
      //               is deallocated.
      //               root = nullptr;

    virtual bool search(const elemType& searchItem) const = 0;
      //Function to determine if searchItem is in the binary 
      //tree.
      //Postcondition: Returns true if searchItem is found in 
      //               the binary tree; otherwise, returns 
      //               false.

    virtual void insert(const elemType& insertItem) = 0;
      //Function to insert insertItem in the binary tree.
      //Postcondition: If there is no node in the binary tree
      //               that has the same info as insertItem, a
      //               node with the info insertItem is created
      //               and inserted in the binary search tree.

    virtual void deleteNode(const elemType& deleteItem) = 0;
      //Function to delete deleteItem from the binary tree 
      //Postcondition: If a node with the same info as 
      //               deleteItem is found, it is deleted from
      //               the binary tree.
      //               If the binary tree is empty or 
      //               deleteItem is not in the binary tree, 
      //               an appropriate message is printed.

    binaryTree(const binaryTree<elemType>& otherTree); 
      //Copy constructor

    binaryTree();   
      //Default constructor

    ~binaryTree();   
      //Destructor

protected:
    nodeType<elemType>  *root;

private:
    void copyTree(nodeType<elemType>* &copiedTreeRoot,
                  nodeType<elemType>* otherTreeRoot);
      //Makes a copy of the binary tree to which 
      //otherTreeRoot points. 
      //Postcondition: The pointer copiedTreeRoot points to
      //               the root of the copied binary tree.

    void destroy(nodeType<elemType>* &p);
      //Function to destroy the binary tree to which p points. 
      //Postcondition: Memory space occupied by each node, in 
      //               the binary tree to which p points, is 
      //               deallocated.
      //               p = nullptr;

    void inorder(nodeType<elemType> *p) const;
      //Function to do an inorder traversal of the binary
      //tree to which p points.  
      //Postcondition: Nodes of the binary tree, to which p
      //               points, are printed in inorder sequence.

    void preorder(nodeType<elemType> *p) const;
      //Function to do a preorder traversal of the binary
      //tree to which p points.  
      //Postcondition: Nodes of the binary tree, to which p
      //               points, are printed in preorder 
      //               sequence.

    void postorder(nodeType<elemType> *p) const;
      //Function to do a postorder traversal of the binary
      //tree to which p points.  
      //Postcondition: Nodes of the binary tree, to which p
      //               points, are printed in postorder 
      //               sequence.

    int height(nodeType<elemType> *p) const;
      //Function to determine the height of the binary tree
      //to which p points. 
      //Postcondition: Height of the binary tree to which 
      //               p points is returned.

    int max(int x, int y) const;
      //Function to determine the larger of x and y.
      //Postcondition: Returns the larger of x and y.

    int nodeCount(nodeType<elemType> *p) const;
      //Function to determine the number of nodes in 
      //the binary tree to which p points. 
      //Postcondition: The number of nodes in the binary 
      //               tree to which p points is returned.

    int leavesCount(nodeType<elemType> *p) const;
      //Function to determine the number of leaves in  
      //the binary tree to which p points 
      //Postcondition: The number of leaves in the binary 
      //               tree to which p points is returned.
};

	//Definition of member functions

template <class elemType>
binaryTree<elemType>::binaryTree()
{
    root = nullptr;
}

template <class elemType>
bool binaryTree<elemType>::isEmpty() const
{
    return (root == nullptr);
}

template <class elemType>
void binaryTree<elemType>::inorderTraversal() const
{
    inorder(root);
}

template <class elemType>
void binaryTree<elemType>::preorderTraversal() const
{
    preorder(root);
}

template <class elemType>
void binaryTree<elemType>::postorderTraversal() const
{
    postorder(root);
}

template <class elemType>
int binaryTree<elemType>::treeHeight() const
{
    return height(root);
}

template <class elemType>
int binaryTree<elemType>::treeNodeCount() const
{
    return nodeCount(root);
}

template <class elemType>
int binaryTree<elemType>::treeLeavesCount() const
{
    return leavesCount(root);
}

template <class elemType>
void  binaryTree<elemType>::copyTree
                       (nodeType<elemType>* &copiedTreeRoot,
                        nodeType<elemType>* otherTreeRoot)
{
    if (otherTreeRoot == nullptr)
        copiedTreeRoot = nullptr;
    else
    {
        copiedTreeRoot = new nodeType<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
        copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
    }
} //end copyTree

template <class elemType>
void binaryTree<elemType>::inorder
                              (nodeType<elemType> *p) const
{
    stackType<nodeType<elemType>*> stack;
    nodeType<elemType> *current;
    current = root;

    while ((current != nullptr) || (!stack.isEmptyStack()))
        if (current != nullptr)
        {
            stack.push(current);
            current = current->lLink;
        }
        else
        {
            current = stack.top();
            stack.pop();
            cout << current->info << " ";
            current = current->rLink;
        }

    cout << endl;
}

template <class elemType>
void binaryTree<elemType>::preorder
                              (nodeType<elemType> *p) const
{
    stackType<nodeType<elemType>*> stack;
    nodeType<elemType> *current;

    current = root;

    while ((current != nullptr) || (!stack.isEmptyStack()))
        if (current != nullptr)
        {
            cout << current->info << " ";
            stack.push(current);
            current = current->lLink;
        }
        else
        {
            current = stack.top();
            stack.pop();
            current = current->rLink;
        }

    cout << endl;
}

template <class elemType>
void binaryTree<elemType>::postorder
                              (nodeType<elemType> *p) const
{
    stackType<nodeType<elemType>*> stack;
    nodeType<elemType> *current;

    current = root;
    nodeType<elemType>* lastVisited = nullptr;

    while (!stack.isEmptyStack() || current != nullptr) {
        if (current != nullptr) {
            stack.push(current);
            current = current->lLink;
        } else {
            nodeType<elemType>* topNode = stack.top();

            if (topNode->rLink != nullptr && lastVisited != topNode->rLink) {
                current = topNode->rLink;
            } else {
                cout << topNode->info << " ";
                lastVisited = topNode;
                stack.pop();
            }
        }
    }
}

   //Overload the assignment operator
template <class elemType>
const binaryTree<elemType>& binaryTree<elemType>::
        operator=(const binaryTree<elemType>& otherTree)
{ 
    if (this != &otherTree) //avoid self-copy
    {
        if (root != nullptr)   //if the binary tree is not empty,
                            //destroy the binary tree
            destroy(root);

        if (otherTree.root == nullptr) //otherTree is empty
            root = nullptr;
        else
            copyTree(root, otherTree.root);
    }//end else

    return *this; 
}

template <class elemType>
void  binaryTree<elemType>::destroy(nodeType<elemType>* &p)
{
    if (p != nullptr)
    {
        destroy(p->lLink);
        destroy(p->rLink);
        delete p;
        p = nullptr;
    }
}

template <class elemType>
void  binaryTree<elemType>::destroyTree()
{
    destroy(root);
}

	//copy constructor
template <class elemType>
binaryTree<elemType>::binaryTree
                (const binaryTree<elemType>& otherTree)
{
    if (otherTree.root == nullptr) //otherTree is empty
        root = nullptr;
    else
        copyTree(root, otherTree.root);
}

    //Destructor
template <class elemType>
binaryTree<elemType>::~binaryTree()
{
    destroy(root);
}

template<class elemType>
int binaryTree<elemType>::height
                             (nodeType<elemType> *p) const
{
    if (p == nullptr)
        return 0;
    else
        return 1 + max(height(p->lLink), height(p->rLink));
}

template <class elemType>
int binaryTree<elemType>::max(int x, int y) const
{
    if (x >= y)
        return x;
    else
        return y;
}

template <class elemType>
int binaryTree<elemType>::nodeCount(nodeType<elemType> *p) const
{
    if (p == nullptr)
        return 0;

    stackType<nodeType<elemType>*> stack;
    stack.push(p);
    int count = 0;

    while (!stack.isEmptyStack())
    {
        nodeType<elemType>* current = stack.top();
        stack.pop();
        count++;

        if (current->rLink != nullptr)
            stack.push(current->rLink);
        if (current->lLink != nullptr)
            stack.push(current->lLink);
    }

    return count;
}

template <class elemType>
int binaryTree<elemType>::leavesCount(nodeType<elemType> *p) const
{
    if (p == nullptr)
        return 0;

    stackType<nodeType<elemType>*> stack;
    stack.push(p);
    int count = 0;

    while (!stack.isEmptyStack())
    {
        nodeType<elemType>* current = stack.top();
        stack.pop();

        if (current->lLink == nullptr && current->rLink == nullptr)
            count++;

        if (current->rLink != nullptr)
            stack.push(current->rLink);
        if (current->lLink != nullptr)
            stack.push(current->lLink);
    }

    return count;
}

#endif