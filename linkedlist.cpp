#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *link;
	node(int x)
	{
		data = x;
		link = NULL;
	}
};
node* insert(node *head,int x)
{
	node *y = new node(x);
	y->link  = head;
	head = y;
	return head;
}
node* insert_end(node *head,int x)
{
	node *y = new node(x);
		node *temp1 = head;
	while(temp1->link!=NULL)
	{
	
		temp1 = temp1->link;
	}
	
	temp1->link  = y;
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
			temp1 = temp1->link;
		}
		y->link = temp1->link;
		temp1->link = y;
		return head;
		
}
node* delete1(node* head)
{
	node* temp1 = head;
	if(head==NULL)
	return NULL;
	if(head->link == NULL)
	return NULL;
    head = head->link;
    free(temp1);
    return head;

}
node* delete1_end(node* head)
{
	node* temp1 = head;
	node* prev;
	if(head==NULL)
	return NULL;
	if(head->link == NULL)
	return NULL;  
	while(temp1->link!=NULL)
	{
    prev = temp1;	
	temp1 = temp1->link;
}
    prev->link = NULL;
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
    if(head->link == NULL)
	return NULL; 
	while(count < x-2)
	{
		temp1 = temp1->link;
		count++;
	  }  
	prev = temp1->link;
	temp1->link = temp1->link->link;
	free(prev);
	return head;
}

int main()
{
	node *head = new node(10);
	head ->link = new node(20);
	head ->link->link = new node(30);
	node *temp = insert(head,5);
	temp = insert_end(temp,40);
	temp = insert_middle(temp,25,3);
	temp  = delete1(temp);
	temp  = delete1_end(temp);
	temp  = delete1_middle(temp,3);
	while(temp!=NULL)
	{
		cout<< temp->data<<" ";
		temp = temp->link;
	}
	
}
