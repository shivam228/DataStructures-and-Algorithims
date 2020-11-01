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


int checkBST(node *root,int min1,int max1)
{
	if(root == NULL)
	return 1;
	if(root->data<min1 || root->data>max1)
	{
		return 0;
	}
	int l = checkBST(root->left,min1,root->data-1);
	int r = checkBST(root->right,root->data+1,max1);
	int ans  = l&r;
	return ans;
}

int main()
{
	int min = INT_MIN;
    int max = INT_MAX;
	node *head = new node(30);	
	head ->right = new node(40);
	head->left = new node(20);
	head->right->left = new node(35);
	head->left->right = new node(25);
	int x = checkBST(head,min,max);
	cout<<x;
}
