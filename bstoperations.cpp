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
 	if(root == NULL)
 	root = new node(x);
 	node *temp = root;
 	while(temp!=NULL)
 	{
 		if(temp->data>x)
 		{
 		if(temp->left==NULL)
		{
		 	temp->left = new node(x);
		 	break;
		}	
		else
			 temp = temp->left;
		}
		else
		{
			if(temp->right==NULL)
		{
		 	temp->right = new node(x);
		 	break;
		}	
		else
			 temp = temp->right;
		}
 		
	 }
	 return root;
}

bool search(node* root,int x)
 {
 	bool res;
 	node *temp1 = root;
 	while(temp1!=NULL)
 	{
 	if(temp1->data==x)
 	{
 	res = true;
 	break;
	 }
	 if(temp1->data>x)
	 temp1  =temp1->left;
	 else
	 temp1 = temp1->right;
}
if(temp1 == NULL)
res = false;
return res;
}

node* delete1(node* root, int key) 
{ 
    if (root == NULL) 
	return root;  
    
	if (key < root->data) 
        root->left = delete1(root->left, key); 
        
    
	else if (key > root->data) 
        root->right = delete1(root->right, key); 
   
    else
    {  
       if(root->left == NULL && root->right == NULL)//node with 0 child
       {
       	free(root);
       	return NULL;
	   }
     
        else if(root->left == NULL && root->right != NULL) //node with one child
        { 
            node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL && root->left != NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
                                                // node with two children
        node* temp = root->right;
        while(temp->left!=NULL)
        {
        	temp =  temp->left;
		}
  
        root->data = temp->data; 
        root->right = delete1(root->right, temp->data); 
    } 
    return root; 
} 





int main()
{
	node *head = new node(50);	
	head ->right = new node(70);
	head->left = new node(30);
	head->right->left = new node(60);
	head->left->right = new node(40);
	head = insert(head,80);
	head = insert(head,65);
	bool ans = search(head,50);
	head = delete1(head,50);
	cout<<ans<<endl;
	 preorder(head);
	 cout<<endl;
	
}
