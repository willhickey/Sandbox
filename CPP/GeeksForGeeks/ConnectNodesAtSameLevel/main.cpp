//https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1

#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int data;
	Node* left = NULL;
	Node* right = NULL;
	Node* nextRight = NULL;
};
//Node BuildTreeFromString(int, string);
//void LinkNextRight(Node);
void connect(Node*);
void TraverseInOrder(Node*);
int main()
{

	Node a;
	Node *root;
	a.data = 3;
	root = &a;
	Node b;
	Node c;
	b.data = 1;
	c.data = 2;
	root->left = &b;
	root->right = &c;
	connect(root);
	cout<<"Traverse!";
	TraverseInOrder(root);

	return 0;
}



void TraverseInOrder(Node *p)
{
	cout<<"Starting traverse "<<endl;
    while(p != NULL)
	{
		Node *temp = p;
		do
		{
			cout<<temp->data<<" ";
			temp = temp->nextRight;
		}while(temp != NULL);
		p = p->left;
	}
}

void connect(Node *p)
{
   queue<Node*> bfsQueue;
   bfsQueue.push(p);
   bfsQueue.push(NULL);	//level separator
   while(!bfsQueue.empty())
   {
		Node* current = bfsQueue.front();
		bfsQueue.pop();

		//enqueue children
		if(current->left != NULL)
			bfsQueue.push(current->left);
		if(current->right != NULL)
			bfsQueue.push(current->right);

		//If the current node is the last node in its level, then pop that null and add a new NULL to the queue
		if(bfsQueue.front() == NULL)
		{
			bfsQueue.push(NULL);
			bfsQueue.pop();
			//current is the end of the level. NULL its nextRight
			current->nextRight = NULL;

			if(bfsQueue.front() == NULL)
				return;
		}
		else
		{
			//cout<<"Setting "<<current->data<<" to "<<bfsQueue.front()->data<<endl;
			current->nextRight = bfsQueue.front();
		}
	}
}
