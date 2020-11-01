#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int max1=100;
int top = -1;
int top1 = -1;
int stack1[100];
int stack2[100];

void push(int x)
{
	if(top>max1)
	{
		cout<<"Stack Full!!";
	}
	else
	{
		if(top==-1)
		{
			top = top+1;
			top1 = top1+1;	
	        stack1[top]=x;
	        stack2[top1]=x;
	        
		}
		else
		{
			top = top+1;	
	        stack1[top]=x;
	        if(stack2[top1]<x)
	        {
	        	int k = stack2[top1];
	        	top1 = top1+1;
	        	stack2[top1] = k;
			}
			else
			{
			top1 = top1+1;	
	        stack2[top1]=x;
			}

		}
	
    }
}
void pop()
{
	if(top<0)
	cout<<"stack underflow";
	else
	{
		int ele = stack1[top];
		cout<<"element popped"<<" "<<ele<<endl;
		
		top = top-1;
		top1 = top1-1;
	}
	
}
int min()
{
	return stack2[top1];
}

int main()
{
	push(40);
	push(20);
	push(30);
	push(10);
	pop();
	pop();
	push(60);
	push(25);
	int z = min();//get minimum
	cout<<"minimum elememt:"<<" "<<z<<endl;
	for(int i = top;top>=0;top--)
	cout<<stack1[top]<<" ";
}
