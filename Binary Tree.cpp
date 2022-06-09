#include <iostream>
#include "TreeNode.h"

using namespace std;

template <typename T>
void print(TreeNode<T>* tree) {
	if (tree == NULL)
		return;
	print(tree->leftTree);
	cout << tree->item;
	print(tree->rightTree);
}

int main1() {
	// print tests and alphabet binary tree tests
	/*TreeNode<char>* D = new TreeNode<char>('D');
	TreeNode<char>* E = new TreeNode<char>('E');
	TreeNode<char>* B = new TreeNode<char>('B', D, E);
	TreeNode<char>* C = new TreeNode<char>('C');
	TreeNode<char>* A = new TreeNode<char>('A', B, C);

	print(A);*/

	return 0;
}


template<typename T>
TreeNode<T>* search(T key, TreeNode<T>* tree)
{
	if (tree == NULL) // key not in tree, insert
		tree = new TreeNode<T>(key);
	else if (key < tree->item)
		tree->leftTree = search(key, tree->leftTree);
	else if (key > tree->item)
		tree->rightTree = search(key, tree->rightTree);
	return tree;
}

int main2() {
	// question c
	TreeNode<char>* tree = NULL;
	tree = search('P', tree);
	tree = search('J', tree);
	tree = search('B', tree);
	tree = search('L', tree);
	tree = search('W', tree);
	tree = search('R', tree);
	tree = search('X', tree);

	print(tree);

	return 0;
}

int sumTree(TreeNode<int>* tree, int low, int high) {
	if (tree == NULL)
		return 0;

	int s = 0;
	if (tree->item >= low && tree->item <= high)
		s += tree->item;
	s += sumTree(tree->leftTree, low, high);
	s += sumTree(tree->rightTree, low, high);
	return s;
}

int main() {
	TreeNode<int>* tree = NULL;
	for (int i = 3; i < 9; i++) {
		tree = search(i, tree);
	}

	cout << sumTree(tree, 0, 10);
	return 0;
}