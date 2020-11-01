#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int max1=100;
int front = -1;
int queue1[100];
int rear =-1;

void push(int x)
{
	if(rear == max1-1)
	cout<<"queue full";
	else
	{
	if(rear==-1)
	{
		rear++;
		front++;
		queue1[rear] = x; 
	}
	else
	{
	rear++;
	queue1[rear] = x;
}
}
}
void pop()
{
	if(front == -1)
	cout<<"queue underflow"<<endl;
	else
	{
		if(front == rear)
		{
		int ele = queue1[front];
		cout<<"element popped"<<" "<<ele<<endl;
		front=-1;
		rear= -1;
	    }
	else
	{
		int ele1 = queue1[front];
		cout<<"element popped"<<" "<<ele1<<endl;
		front = front+1;
	}
	}
	
}

int main()
{
	push(40);
	push(20);//push represents enqueue operation
	push(30);
	push(10);
	pop();//pop represents dequeue operation
	pop();
	pop();
	pop();
	pop();
	push(60);
	push(25);
	for(int i = front;i<=rear;i++)
	cout<<queue1[i]<<" ";
}
