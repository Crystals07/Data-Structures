#include<bits/stdc++.h>
using namespace std;

 struct node
 {

       int data;

       node* next;

 };

 void push(node** href,int num)
 {

   if(*href==NULL)
  {
      cout<<"\nThe Circular list is empty\n"<<"It will be first element\n";

      node* ptr=new node();

      ptr->data=num;

     (*href)=ptr;

     ptr->next=(*href); 
  
 }

     else
   {

     node* newptr=new node();

     newptr->data=num;

     newptr->next=(*href);

     node* travel=newptr;

     travel=travel->next;

     while(travel->next!=*href)
   {
 	travel=travel->next;
   }

     travel->next=newptr;

    *href=newptr;

    }

  }

    void display(node** href1)
   {

      int i=1;

      node* traverse1=*href1;

      if(*href1==NULL) cout<<"\nCircular list is empty\n";
  
  else
  {

      cout<<"\nFirst element of node "<<i<<" is :"<<traverse1->data<<endl;

      traverse1=traverse1->next;

      while(traverse1!=*href1)

  {

     cout<<"\nElement of node "<<i+1<<" is :"<<traverse1->data<<endl; 

     traverse1=traverse1->next;

    i++;

    }

  }

 }


  int countlen(node** href2)
{

    int i=1;

    if(*href2==NULL) return 0;
 
    else
  {
     node* traverse=*href2;

    traverse=traverse->next;

    while(traverse!=(*href2))
   {

       traverse=traverse->next;

       i++;
   }

   return i;

    }

 }


 void append(node** href,int item)
 {

   if(*href==NULL) 
  {

      cout<<"Circlurlist is empty\n"<<"It will be first element\n";

     push(href,item);

 }

    else
  {

   node* traverse=*href;

   traverse=traverse->next;

   while(traverse->next!=*href)
   {

     traverse=traverse->next;

   }

     node* newptr=new node();

     newptr->data=item;

     traverse->next=newptr;

    newptr->next=*href;


  }

}


  void insert_n(node** href,int n,int number)
 {

    int len=countlen(href);

    if(n<=0||n>len) cout<<"\nInvalid position\n";

   else if(n==1)
 {
      cout<<"\nInsertion at beg\n";
      push(href,number);
 }

  else if(n==len)
 {
     cout<<"\nInsertion at end\n";
     append(href,number);
 }

   else
 {

      cout<<"\nInsertion at intermediate position\n";

      node* traverse=*href;
 
      int i=1;

     while(i!=n-1)
     {
        traverse=traverse->next;
        i++;
      }

     node* newptr=new node();

     newptr->data=number;

     newptr->next=traverse->next;

     traverse->next=newptr;
 

   }

 }

   void delete_n(node**href,int pos)
 {

	int len=countlen(href);

	if(*href==NULL) cout<<"\nList is empty cannot del an item\n";

	else if(pos<=0||pos>len) cout<<"\nInvalid position\n";

	else if(pos==1)
	{

		 cout<<"\nDeletion of first node\n";

		 if((*href)->next==NULL) 
 		{
 			(*href)->next=NULL;
 			free(href);
 			cout<<"\nFirst & only node deleted\n";
		 }

	 else
 	{
   		node* traverse=*href;
   		node*first=*href;
   
		traverse=traverse->next;
   
		while(traverse->next!=*href)
   		{
    			traverse=traverse->next;
   		}
  
		 traverse->next=(*href)->next;
   		
                *href=(*href)->next;
   		
                free(first);
   		
                cout<<"\nFirst node deleted\n";
        }

    }

	else if(pos==len)
	{
   		 cout<<"\nDeletion of Last node\n";
  		 
                node* traverse=*href;
  		
                node*last=NULL;
 		
               traverse=traverse->next;
   
		while(traverse->next!=*href)
   		{
   			 last=traverse;
    			traverse=traverse->next;
   		}
   		
		last->next=*href;
   		traverse->next=NULL;
		   
		free(traverse->next);
  
		free(traverse);
  		
	       cout<<"\nDeletion of Last node Succesfull\n";

  }

    else
    {
          cout<<"\nDeletion of Intermediate node\n";
     
          int i=1;
      
          node* traverse=*href;
     
          while(i!=pos-1)
         {
              traverse=traverse->next;
             i++;
         }
  
          traverse->next=traverse->next->next;
  
          cout<<"\nDeletion of Intermediate node Succesfull\n"; 
   
   }

 }



    int main()
 {

     node* head=NULL;

     int size,n,pos;

     cout<<"\nEnter the no of elements :";

     cin>>size;

     for(int i=1;i<=size;i++) 

    //push(&head,i);

     append(&head,i);

     cout<<"\nEnter the position you want to insert :";

     cin>>n;

     insert_n(&head,n,77);
 
     display(&head);

     cout<<"\nEnter the position you want to delete :";

     cin>>pos;

     delete_n(&head,pos);

     cout<<"\nAfter deletion of an element\n";

     display(&head);

    cout<<"\nTotal no of elements :"<<countlen(&head)<<endl;
 
 }
