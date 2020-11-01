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


void preorder(node *root)
{
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

 node *insert(node* root,int x)
 {
 	node *temp1 = root;
 	node *y = new node(x);
 	queue<node*> q;
 	q.push(temp1);
 	while(q.size()!=0)
 	{
 		node *temp = q.front();
 		q.pop();
 		if(temp->left!=NULL)
 		q.push(temp->left);
 		else
 		{
 		temp->left = y;
 		break;
 	}
 	if(temp->right!=NULL)
 		q.push(temp->right);
 		else
 		{
 		temp->right = y;
 		break;
 	}
 		
	 }
	 return root;
 }

bool search(node* root,int x)
 {
 	bool res;
 	node *temp1 = root;
 	queue<node*> q;
 	q.push(temp1);
 	while(q.size()!=0)
 	{
 		node *temp = q.front();
 		q.pop();
 		if(temp->data==x)
 		{
 			res = true;
 			break;
		 }
 		if(temp->left!=NULL)
 		q.push(temp->left);
 	
 	if(temp->right!=NULL)
 		q.push(temp->right);	
	 }
	 return res;
 }
 
void deletefinal(node* root,node* del) // delete node from tree
{ 
    queue<struct node*> q; 
    q.push(root); 
    node* temp; 
    while (!q.empty()) { 
        temp = q.front(); 
        q.pop(); 
        if (temp == del) { 
            temp = NULL; 
            delete (del); 
            return; 
        } 
        if (temp->right) { 
            if (temp->right == del) { 
                temp->right = NULL; 
                delete (del); 
                return; 
            } 
            else
                q.push(temp->right); 
        } 
  
        if (temp->left) { 
            if (temp->left == del) { 
                temp->left = NULL; 
                delete (del); 
                return; 
            } 
            else
                q.push(temp->left); 
        } 
    } 
} 
 
 node *delete1(node *root,int x)
 {
 	node *temp1 = root;
 	node *temp;
 	node *y;
 	queue<node*> q;
 	q.push(temp1);
 	while(q.size()!=0)
 	{
 		temp = q.front();
 		q.pop();
 		if(temp->data == x)
		 {
		 	y = temp;
		 }
 		if(temp->left!=NULL)
 		q.push(temp->left);

 	if(temp->right!=NULL)
 		q.push(temp->right);
 		
	 }
	 int z = temp->data;
	 deletefinal(root,temp);
	 y->data = z;

	 return root;
	 
 }

int main()
{
	node *head = new node(10);	
	head ->right = new node(20);
	head->left = new node(30);
	head->right->left = new node(40);
	head->left->right = new node(50);
	head = insert(head,70);
	bool ans = search(head,40);
	head = delete1(head,10);
	 preorder(head);
	 cout<<endl;
	 cout<<ans;
}
