#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
	node(int x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};
void inorder(node *root)
{
	if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(node *root)
{
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(node *root)
{
	if(root==NULL)
	return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}


int main()
{
	node *head = new node(10);	
	head ->right = new node(20);
	head->left = new node(30);
	head->right->left = new node(40);
	head->left->right = new node(50);
	 inorder(head);
	 cout<<endl;
	 preorder(head);
	 cout<<endl;
	 postorder(head);
	 cout<<endl;
	
}
