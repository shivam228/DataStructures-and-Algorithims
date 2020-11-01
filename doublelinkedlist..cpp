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
node* insert(node *head,int x)
{
	node *y = new node(x);
	y->right  = head;
	head->left = y;
	head = y;
	return head;
}
node* insert_end(node *head,int x)
{
	node *y = new node(x);
		node *temp1 = head;
	while(temp1->right!=NULL)
	{
	
		temp1 = temp1->right;
	}
	
	temp1->right  = y;
	temp1->right->left = temp1;
	return head;
}
node* insert_middle(node *head,int x,int pos)
{
	    int count =0;
		node *y = new node(x);
		node *temp1 = head;
		while(count!=pos-1)
		{
			count++;
			temp1 = temp1->right;
		}
		y->right = temp1->right;
		y->left = temp1->right->left;
		temp1->right->left = y;
		temp1->right = y;
		return head;
		
}
node* delete1(node* head)
{
	node* temp1 = head;
	if(head==NULL)
	return NULL;
	if(head->right == NULL)
	return NULL;
    head = head->right;
    head->left = NULL;
    free(temp1);
    return head;

}
node* delete1_end(node* head)
{
	node* temp1 = head;
	node* prev;
	if(head==NULL)
	return NULL;
	if(head->right == NULL)
	return NULL;  
	while(temp1->right!=NULL)
	{
    prev = temp1;	
	temp1 = temp1->right;
}
    prev->right->left = NULL;
    prev->right = NULL;
	free(temp1);
    return head;

}
node* delete1_middle(node* head,int x)
{
	node* temp1 = head;
	node* prev;
	int count =0;
	if(head==NULL)
	return NULL;
    if(head->right == NULL)
	return NULL; 
	while(count < x-2)
	{
		temp1 = temp1->right;
		count++;
	  }  
	prev = temp1->right;
	temp1->right = temp1->right->right;
	temp1->right->left = temp1;
	prev->left = NULL;
	prev ->right =NULL;
	free(prev);
	return head;
}

int main()
{
	node *head = new node(10);
	
	head ->right = new node(20);
	head->right->left = head;
	head ->right->right = new node(30);
	head->right->right->left = head->right;
	node *temp = insert(head,5);
	temp = insert_end(temp,40);
	temp = insert_middle(temp,25,3);
	temp  = delete1(temp);
	temp  = delete1_end(temp);
	temp  = delete1_middle(temp,3);
	cout<<endl;
	while(temp!=NULL)
	{
		cout<< temp->data<<" ";
		temp = temp->right;
	}
	
}
