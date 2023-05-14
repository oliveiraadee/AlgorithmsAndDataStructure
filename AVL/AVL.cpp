#include <iostream>
#include "avl.h"

using namespace std;

BinaryTree::Node * AVLTree::insert(BinaryTree::Node * root, int key) {
	root = BinaryTree::insert(root, key);

	if (!balanced(root))
		root = rebalance(root);

	return root;
}

BinaryTree::Node * AVLTree::remove(BinaryTree::Node * root, int key) {
	if (root == NULL)
		return NULL;

	root = BinaryTree::remove(root, key);

	if (root != NULL && !balanced(root))
		root = rebalance(root);

	return root;
}

BinaryTree::Node * AVLTree::removeMax(BinaryTree::Node * root, int & max) {

	root = BinaryTree::removeMax(root, max);

	if (root != NULL && !balanced(root))
			root = rebalance(root);

	return root;
}

BinaryTree::Node * AVLTree::rebalance(Node * root) {
	ASSERT(!balanced(root), "Already balanced!");

	if (leftHeavy(root)) {
		if (rightHeavy(root->left))
			root->left = rotateLeft(root->left);

		root = rotateRight(root);
	} else { // rightHeavy
		if (leftHeavy(root->right))
			root->right = rotateRight(root->right);

		root = rotateLeft(root);
	}

	ASSERT(balanced(root), "Rebalance failed!");
	return root;
}

BinaryTree::Node * AVLTree::rotateLeft(Node * root) {
    Node * temp = root->right;
    Node * temp2 = temp->left;
    
    temp->left = root;
    root->right = temp2;
     updateH(root);
     updateH(temp);
	return temp;
}

BinaryTree::Node * AVLTree::rotateRight(Node * root) {
    
    Node * temp = root->left;
    Node * temp2 = temp->right;
    
    temp->right = root;
    root->left = temp2;
    
    updateH(root);
    updateH(temp);
	return temp;
}

void AVLTree::show(Node * root) {
	if (root == NULL)
		return;
	show(root->left);
	cout << "(" << root->key << ", "
			<< root->height << ", "
			<< BF(root) << ") ";
	show(root->right);
}

int AVLTree::validate(Node * root, int &min, int &max) {
	int valid = BinaryTree::validate(root, min, max);

	return valid && balanced(root);
}
BinaryTree::Node *  AVLTree::max(Node * a, Node * b) 
{ 
    return (a->height > b->height)? a : b; 
}
