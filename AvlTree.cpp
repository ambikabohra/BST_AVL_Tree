#include <iostream>
#include "AvlTree.h"

using namespace std;

/**
 * Default constructor.
 */
AvlTree::AvlTree()
: BinarySearchTree()
{
}

AvlTree::~AvlTree()
{
}

int AvlTree::height(const BinaryNode *ptr) const
{
	return ptr == nullptr ? -1 : ptr->height;
}


void AvlTree::insert(const int data, BinaryNode* &ptr)
{
	BinarySearchTree::insert(data, ptr);
	balance(ptr);
}


void AvlTree::remove(const int data, BinaryNode* &ptr)
{
	BinarySearchTree::remove(data, ptr);
	balance(ptr);
}

BinaryNode *AvlTree::balance(BinaryNode* &ptr)
{
	if (ptr == nullptr) return ptr;

	// Left side too high.
	if (height(ptr->left) - height(ptr->right) > 1)
	{
		if (height(ptr->left->left) >= height(ptr->left->right))
		{
			ptr = singleRightRotation(ptr);
			cout << "    --- Single right rotation at node "
					<< ptr->data << endl;
		}
		else
		{
			ptr = doubleLeftRightRotation(ptr);
			cout << "    --- Double left-right rotation at node "
					<< ptr->data << endl;
		}
	}

	// Right side too high.
	else if (height(ptr->right) - height(ptr->left) > 1)
	{
		if (height(ptr->right->right) >= height(ptr->right->left))
		{
			ptr = singleLeftRotation(ptr);
			cout << "    --- Single left rotation at node "
					<< ptr->data << endl;
		}
		else
		{
			ptr = doubleRightLeftRotation(ptr);
			cout << "    --- Double right-left rotation at node "
					<< ptr->data << endl;
		}
	}

	// Recompute the node's height.

	ptr->height = (max(height(ptr->left),
			height(ptr->right)) + 1);
	if (checkBalance(ptr) < 0)
	{
		cout << endl << "***** Tree unbalanced!" << endl;
	}

	return ptr;
}


BinaryNode *AvlTree::singleRightRotation(BinaryNode *k2)
{
	//reference : http://www.geeksforgeeks.org/avl-tree-set-1-insertion/
	//reference : http://www.sanfoundry.com/cpp-program-implement-avl-trees/

	BinaryNode *temp = k2->left;
	k2->left = temp->right;
	temp->right = k2;
	k2->height = max(height(k2->left), height(k2->right))+1;
	temp->height = max(height(temp->left), height(temp->right))+1;
	return temp;
}


BinaryNode *AvlTree::doubleLeftRightRotation(BinaryNode *k3)
{
	//reference : http://www.geeksforgeeks.org/avl-tree-set-1-insertion/
	//reference : http://www.sanfoundry.com/cpp-program-implement-avl-trees/
	BinaryNode *temp = k3->left;
	k3->left = singleLeftRotation (temp); //left rotation
	return singleRightRotation (k3); //right rotation
}


BinaryNode *AvlTree::doubleRightLeftRotation(BinaryNode *k1)
{
	BinaryNode *temp;
	temp = k1->right;
	k1->right = singleRightRotation (temp); //first right rotation
	return singleLeftRotation (k1); //left rotation
}


BinaryNode *AvlTree::singleLeftRotation(BinaryNode *k1)
{

	BinaryNode *temp = k1->right; //take right element
	k1->right = temp->left;
	temp->left = k1; //replace k1 with its left element
	k1->height = max(height(k1->left), height(k1->right))+1;
	temp->height = max(height(temp->left), height(temp->right))+1;
	return temp;
}


int AvlTree::checkBalance(BinaryNode *ptr)
{
	if (ptr == nullptr) return -1;

	int leftHeight  = checkBalance(ptr->left);
	int rightHeight = checkBalance(ptr->right);

	if ((abs(height(ptr->left) - height(ptr->right)) > 1)
			|| (height(ptr->left)  != leftHeight)
			|| (height(ptr->right) != rightHeight))
	{
		return -2;       // unbalanced
	}

	return height(ptr);  // balanced
}
