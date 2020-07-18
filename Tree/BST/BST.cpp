#include<iostream>
using namespace std;

struct BST
{
	int data;

	BST* left=NULL;

	BST* right=NULL;
	
};

BST* findmin(BST* head)
{
	if(!head) return NULL;

	if(head->left!=NULL) head=findmin(head->left);

	else if(!head->left) return head;

	return head;

}

BST* create(int data)
{
	BST *temp=new BST();

	temp->data=data;

	temp->left=NULL;

	temp->right=NULL;

	return temp;
}


BST* insert(BST *head,int data)
{
	if(!head) return create(data);

    if(data<head->data) head->left=insert(head->left,data);  	
    
    if(data>head->data) head->right=insert(head->right,data);

    return head;

}

void Display(BST *head)
{  
	if(!head) return;

	Display(head->left);

	cout<<head->data<<" ";

	Display(head->right);
}

BST* Delete(BST *head,int data)
{
	if(!head) return 0;

	else if(head->data>data) head->left=Delete(head->left,data);

	else if(head->data<data) head->right=Delete(head->right,data);

	else
	{
		if(!head->left && !head->right) 
		{
			free(head);

			head=NULL;
		}

		else if(!head->left)
		{
                        BST* temp=head;

			head=head->right;

			free(temp);

			temp=NULL;		

		}

		else if(!head->right)
		{			
			
                        BST* temp=head;

			head=head->left;

			free(temp);

			temp=NULL;		
			
		}

		else
		{
			BST *temp=findmin(head->right);

			head->data=temp->data;

			head->right=Delete(head->right,temp->data);			
			
		}

	}

		return head;

}



int main()
{
	/* code */

  BST* head=NULL;

  int arr[]={12,5,3,7,15,13,17,1,9};

  for(int i=0;i<=8;i++) head=insert(head,arr[i]);

  Display(head);

  cout<<"\n After deletion\n";

  Delete(head,3);

  Display(head);

	return 0;
}

