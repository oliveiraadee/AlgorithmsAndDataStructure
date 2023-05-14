
#ifndef AVL_H_
#define AVL_H_

#include "bst.h"

#include <algorithm> // max
using namespace std;

class AVLTree : public BinaryTree {
protected:

	static int BF(Node * node) {
		return H(node->left) - H(node->right);
	}
	static int balanced(Node * node) {
		return node == NULL || abs(BF(node)) < 2;
	}
	

	static int leftHeavy(Node * node) { return H(node->left) > H(node->right); }
	static int rightHeavy(Node * node) { return H(node->left) < H(node->right); }

	Node * rebalance(Node * node);
	Node * rotateLeft(Node * node);
	Node * rotateRight(Node * node);


public:
	using BinaryTree::insert;
	using BinaryTree::remove;
	using BinaryTree::show;
	using BinaryTree::validate;

protected:
	virtual Node * insert(Node * root, int key);
	virtual Node * remove(Node * root, int key);
	virtual Node * removeMax(Node * root, int & max);
    virtual  Node * max(Node * a,  Node * b);
	virtual void show(Node * root);
	virtual int validate(Node * root, int &min, int &max);
};


#endif 
