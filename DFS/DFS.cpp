// DFS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <algorithm>

template <typename T>
class BinaryTreeNode
{
    
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    T data;
public:
    BinaryTreeNode() : left(nullptr), right(nullptr), data(T())
    {
    };
    BinaryTreeNode(T data) : left(nullptr), right(nullptr), data(data)
    {

    }
    BinaryTreeNode(T data, BinaryTreeNode* left, BinaryTreeNode* right) : left(left), right(right), data(data)
    {

    }
    BinaryTreeNode(BinaryTreeNode const& other) = delete;
    
    BinaryTreeNode& operator=(BinaryTreeNode const& other) = delete;

    BinaryTreeNode(BinaryTreeNode&& other) noexcept : left(other.left), right(other.right), data(std::move(other.data))
    {
        other.left = nullptr;
        other.right = nullptr;
    }

    BinaryTreeNode* getLeft() const{
        return left;
    }

    BinaryTreeNode* getRight() const {
        return right;
    }

    T& getData() {
        return data;
    }

    void setLeft(BinaryTreeNode* leftNode) {
        left = leftNode;
    }

    void setRight(BinaryTreeNode* rightNode) {
        right = rightNode;
    }

    void setData(T newData) {
        data = newData;
    }
};

void InsertNode(BinaryTreeNode<int>& root, int data)
{
    if (data < root.getData())
    {
        if (root.getLeft() == nullptr)
        {
            root.setLeft(new BinaryTreeNode<int>(data));
        }
        else
        {
            InsertNode(*root.getLeft(), data);
        }
    }
    else
    {
        if (root.getRight() == nullptr)
        {
            root.setRight(new BinaryTreeNode<int>(data));
        }
        else
        {
            InsertNode(*root.getRight(), data);
        }
    }
}
void PreOrder(BinaryTreeNode<int>* root)
{
    if (root == nullptr)
    {
        return;
    }

    std::cout << root->getData() << " ";

    PreOrder(root->getLeft());
    PreOrder(root->getRight());
}

void PreOrderNonRecursive(BinaryTreeNode<int>* root)
{
    if (root == nullptr)
    {
        return;
    }

    std::stack<BinaryTreeNode<int>*> stack;
    stack.push(root);

    while (!stack.empty())
    {
        BinaryTreeNode<int>* current = stack.top();
        stack.pop();

        std::cout << current->getData() << " ";

        if (current->getRight() != nullptr)
        {
            stack.push(current->getRight());
        }
        if (current->getLeft() != nullptr)
        {
            stack.push(current->getLeft());
        }
    }
}

void InOrder(BinaryTreeNode<int>* root)
{
    if (root == nullptr)
    {
        return;
    }

    InOrder(root->getLeft());
    std::cout << root->getData() << " ";
    InOrder(root->getRight());
}

void HeapTree(BinaryTreeNode<int>* rooot)
{
    if (rooot == nullptr)
    {
        return;
    }

    std::cout << rooot->getData() << " ";
    HeapTree(rooot->getLeft());
    HeapTree(rooot->getRight());


}

void InsertNodeToHeap(BinaryTreeNode<int>& root, int data)
{
    if (data < root.getData())
    {
        if (root.getLeft() == nullptr)
        {
            root.setLeft(new BinaryTreeNode<int>(data));
        }
        else
        {
            InsertNodeToHeap(*root.getLeft(), data);
        }
    }
    else
    {
        if (root.getRight() == nullptr)
        {
            root.setRight(new BinaryTreeNode<int>(data));
        }
        else
        {
            InsertNodeToHeap(*root.getRight(), data);
        }
    }
}

void Heapify(BinaryTreeNode<int>* root)
{
    if (root == nullptr)
    {
        return;
    }

    // Heapify left and right subtrees
    Heapify(root->getLeft());
    Heapify(root->getRight());

    // Check if the current node is a heap node
    BinaryTreeNode<int>* left = root->getLeft();
    BinaryTreeNode<int>* right = root->getRight();

    if (left != nullptr && left->getData() < root->getData())
    {
        std::swap(left->getData(), root->getData());
    }
    if (right != nullptr && right->getData() < root->getData())
    {
        std::swap(right->getData(), root->getData());
    }
}

int main()
{
    BinaryTreeNode<int> root(10);
    InsertNode(root, 5);
    InsertNode(root, 15);
    InsertNode(root, 3);
    InsertNode(root, 7);
    InsertNode(root, 12);
    InsertNode(root, 18);

    std::cout << "Pre-order traversal of the binary tree: " << std::endl;
    PreOrder(&root);
    std::cout << std::endl;

    std::cout << "In-Order traversal of the binary tree: " << std::endl;
    InOrder(&root);
    std::cout << std::endl;

    std::cout << "Pre-Order traversal of the binary tree without recursive function: " << std::endl;
    PreOrderNonRecursive(&root);
    std::cout << std::endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
