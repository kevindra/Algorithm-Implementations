/**
*	Two nodes of a BST are swapped, correct the BST.
*/

#include <iostream>

using namespace std;

struct node
{
	int val;
	node *left, *right;
};

node *createNewNode(int val)
{
	node *np = new node;
	np->val = val;
	np->left = NULL;
	np->right = NULL;

	return np;
}

void insert(node * &root, int val)
{
	if( root == NULL ) { root = createNewNode(val); return; }

	if( val < root->val ) { insert(root->left, val); }
	else if( val >= root->val ) { insert(root->right, val); }
}

void inorder(node *root)
{
	if( root == NULL ) { return; }

	inorder(root->left);
	cout<<root->val<<", ";
	inorder(root->right);
}

void findSwappedNodes(node *root, node *&prev, node *&first, node *&mid, node *&last)
{
	if(root == NULL) return;

	findSwappedNodes(root->left, prev, first, mid, last);

	if(prev == NULL) { }
	else if (prev->val > root->val)
	{
		if(first == NULL)
		{
			first = prev; mid = root;
		}
		else
		{
			last = root;
		}
	}
	prev = root;
	findSwappedNodes(root->right, prev, first, mid, last);
}

void fix(node *root)
{
	node *prev, *first, *mid, *last;
	prev = first = mid = last = NULL;

	findSwappedNodes(root, prev, first, mid, last);

	if(first && last) { swap(first->val, last->val); }
	else { swap(first->val, mid->val); }
}

int main()
{
	int a[] = {5,2,7,1,4,6,10,3,8,9};
	int n = 8;

	node *root = NULL;

	for(int i=0; i<n; i++)
	{
		insert(root, a[i]);
	}

	// add two more values to the tree but at wrong places (violating the BST principles)
	root->left->val = 1;
	root->left->left->val = 2;

	cout<<"Inorder: ";	inorder(root); cout<<endl;

	fix(root);

	cout<<"Inorder after fix: "; inorder(root); cout<<endl;

	system("pause");
}