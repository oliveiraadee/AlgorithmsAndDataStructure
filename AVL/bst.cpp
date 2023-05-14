/*
 * bst.cpp
 *
 *  Created on: 30 de out de 2017
 *      Author: ramide
 */

#include <iostream>
#include <stdlib.h>
#include <climits> // INT_MIN e INT_MAX

#include "bst.h"

BinaryTree::Node * BinaryTree::insert(BinaryTree::Node * root, int key) {
	// TODO
	if (root == NULL){
	 	Node *novo = new Node(key);
    	root = novo;
	}else if(key > root->key){
		root->right = insert(root->right, key);
	}else{
		root->left = insert(root->left, key);
	}
	updateH(root);
    return root;
}

BinaryTree::Node * BinaryTree::search(BinaryTree::Node * root, int key) {
	if (root == NULL) return NULL;

	if (root->key == key) return root;

	if (root->key < key)
		return search(root->right, key);
	else
		return search(root->left, key);
}

BinaryTree::Node * BinaryTree::remove(BinaryTree::Node * root, int key) {

	if (root == NULL) return NULL; // (sub)�rvore vazia, nada a fazer

	if (key == root->key) { // Chave encontrada!
		if (root->left != NULL && root->right != NULL) { // Caso 3
			int maxLeft;
			// Removo o maior filho da esquerda e
			// substituo o valor do n� atual com o valor que era dele
			root->left = removeMax(root->left, maxLeft);
			root->key = maxLeft;
		} else { // Casos 1 e 2
			Node * tmp = root;
			root = (root->right != NULL)?root->right:root->left;
			delete tmp;
		}
	} else {
		if (key > root->key)
			root->right = remove(root->right, key);
		else
			root->left = remove(root->left, key);
	}

	if (root != NULL) updateH(root);

	return root;
}

BinaryTree::Node * BinaryTree::removeMax(BinaryTree::Node * root, int & max) {
	if (root == NULL) throw "ERRO";

	if (root->right != NULL) {
		root->right = removeMax(root->right, max);
	} else {
		max = root->key;
		Node * tmp = root;
		root = root->left;
		delete tmp;
	}

	if (root != NULL)
		updateH(root);

	return root;
}

void BinaryTree::predecessor(Node * root, Node * & pred, int key) {
	if (root == NULL) return;

	if (root->key == key) { 		
		root = root->left;			
		while (root != NULL) {
			pred = root;			
			root = root->right;
		}
	} else {
		if (key < root->key)		
			predecessor(root->left, pred, key);
		else						
			predecessor(root->right, pred = root, key);
	}
}

void BinaryTree::successor(Node * root, Node * & succ, int key) {
	// TODO
	if (root == NULL) return;

	if (root->key == key) { 		
		root = root->right;			
		while (root != NULL) {
			succ = root;			
			root = root->left;
		}
	} else {
		if (key > root->key)		
			successor(root->right, succ, key);
		else						/
			successor(root->left, succ  = root , key);
	}
	
}

int BinaryTree::validate(Node * root, int &min, int &max) {

	if (root == NULL) {
		min = INT_MAX;
		max = INT_MIN;
		return 1;
	}

	int lmin, lmax; 
	int rmin, rmax; 

	if (!validate(root->left, lmin, lmax) || (lmax > root->key)) return 0;

	if (!validate(root->right, rmin, rmax) || (rmin < root->key)) return 0;

	min = (root->left != NULL)?lmin:root->key;
	max = (root->right != NULL)?rmax:root->key;

	return 1;
}


void BinaryTree::show(Node * root) {
	if (root == NULL) return;

	show(root->left);
	cout << "(" << root->key << ", " << root->height << ") ";
	show(root->right);
}



