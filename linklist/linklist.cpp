#include<bits/stdc++.h>
using namespace std;

// Code is contributed by Jaideep Rana

 int countlen();

 void delete_first();

   struct node
 {

      int data;

      node* next;

 };

  struct node* start=NULL;

 node* create(int item)
 {
  node* temp=new node();

  temp->data=item;

  temp->next=NULL;

  return temp;
 }


 void insert_end()
{
  int num;

  cout<<endl<<"Enter the element "<<endl;

  if(start==NULL)
  {

	  cout<<"Linklist is empty\n"<<"Enter the number :";

	  cin>>num;

	 start=create(num);

 }

	else
	{

		node* ptr=start; 

		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}

		cin>>num;

		ptr->next=create(num);


	}

  }


	void insert_beg()
	{

	    int num;

           if(start==NULL) 
           {
		cout<<endl<<"linklist is empty\n"<<"Enter first element :";

		cin>>num;
	
		start=create(num);

	   }
	
		else
		{
	        	//node*ptr=start;
      
	        	 cout<<endl<<"Enter the number :";
  
                 	 cin>>num;

          		 node* newnode=create(num);
 
          		 newnode->next=start;

         		 start=newnode;  
     
		}
	
	}


	void insert_n(int n)
	{

		int len=countlen();

		if(n==1) 
		{
			cout<<endl<<"Insertion at beg\n";

			insert_beg();
		}

        	else if(n<=0||n>len) cout<<endl<<"Invalid position "<<endl;

        	else if(n==len) 
               {
		
    			cout<<endl<<"Insertion at the end "<<endl;

			insert_end();
		}

		else
		{
   			int i=1;

		       node*ptr=start;

		       while(i!=n-1)
  		      {
    			 ptr=ptr->next;
     			 i++;
  		       }

			int num;

			cout<<endl<<"Enter the number :";

			cin>>num;
			
			node*new_ptr=create(num);

			new_ptr->next=ptr->next;

			ptr->next=new_ptr;


		}

	}


	void display()
	{
		int i=1;

		node* traverse=start;

		if(traverse==NULL)
		{
			cout<<endl<<"Linklist is empty\n";
		}

		else
		{

			while(traverse!=NULL)
			{

				cout<<endl<<"Element of node "<<i<<" are :" <<traverse->data<<endl;

				traverse=traverse->next;

				i++;
                        }

			free(traverse);	
		}

	}


      void delete_first()
     {

	 node*first=start;

         node*second=first->next;

         start=second;

         first->next=NULL;

         free(first);
 
    }


   void deletenode()
 {

     int i=1;

     cout<<endl<<"  "<<"Enter the position you want to delete :";

     int del;

     cin>>del;

     int len=countlen();

     if(start==NULL) cout<<endl<<"Cannot delete the element as List is empty \n";

     else if(del>len||del<=0) cout<<endl<<"Cannot delete the element as that node "<<del<<" is not present\n";

  else if(del==1) 
  {
      cout<<endl<<"Deleted first node\n";

      delete_first();

   }




   else 
  {
     node*ptr=start;
   
    while(i!=del-1)
   {
      ptr=ptr->next;
      i++;
  }

   node*temp=ptr->next;

   if(temp->next==NULL) 
  {

      cout<<endl<<"Selected node "<<del<<" is deleted and it is last element "<<endl;

     ptr->next=NULL;

     free(temp);
  }


      else
     {
          cout<<endl<<"Selected node "<<del<<" is deleted and suffling is required "<<endl;

          ptr->next=temp->next;
 
          temp->next=NULL;

          free(temp);

      }

    }


  }


   int countlen()
  {

     node*count=start;

     int i=0;

   while(count!=NULL)
  {
	count=count->next;
	i++;
  }

       free(count);

       return i;

  }




  int main()
 {
      int x;

     while(1)
   {  

       cout<<endl<<"Insertion in a linklist at end 1 "<<endl;  

       cout<<"Insertion at the begining 2"<<endl;
 
       cout<<"Insertion at the position n 3"<<endl;
  
       cout<<"Delete the node 4"<<endl;

       cout<<"Display my linklist 5"<<endl;

       cout<<"Display the total no of elements 6"<<endl;

       cout<<endl<<"Enter your choice :";

       cin>>x;

    switch(x)
  {

    case 1:

     
      insert_end();
      break;

    case 2:
      
       insert_beg();
       break; 

    case 3:

      cout<<endl<<"Enter the n th position you want to insert :";
      int n;
      cin>>n;
      insert_n(n);
      break;

    case 4:
       deletenode();
       break;


    case 5:
       display();
       break;


    case 6:
      cout<<endl<<"Total no of elements are : "<<countlen()<<endl;
      break;

    default :

   cout<<endl<<"Wrong choice please select valid choice"<<endl;
    
     }


    }

 }
