#include<bits/stdc++.h>
using namespace std;

//Dlinklist code contributed by Jaideep Rana

struct dnode
{

int data;

dnode* next;

dnode* prev;

};


int countlen(dnode*);

void push(dnode** href,int num) //add element at beg simillar to insert_beg
{

if(*href==NULL) 
{
dnode*newnode=new dnode();

newnode->data=num;

newnode->prev=NULL;

newnode->next=NULL;

*href=newnode;

}

else{

dnode*newnode=new dnode();

(*href)->prev=newnode;

newnode->data=num;

newnode->prev=NULL;

newnode->next=*href;

*href=newnode;
}


}

void append(dnode** first,dnode* ptr,int num)
{

//dnode* ptr=*first;

dnode* last;

if(*first==NULL)
{
cout<<endl<<"List is empty\n"<<"It will be first element\n"<<endl;

dnode* newnode=new dnode();

newnode->data=num;

newnode->prev=NULL;

newnode->next=NULL;

*first=newnode;

}

else
{

while(ptr!=NULL)
{

last=ptr;

ptr=ptr->next;

}

dnode* newptr=new dnode();

newptr->data=num;

newptr->prev=last;

last->next=newptr;

newptr->next=NULL;

//free(ptr);

}

}


void print(dnode* traverse)
{

dnode* last=traverse;

if(traverse==NULL) 
{
cout<<"Linklist is empty ";
return;
}

while(traverse!=NULL)
{

  cout<<endl<<"Forward traverse element is :"<<traverse->data;  
  
  last=traverse;

  traverse=traverse->next;

}

cout<<endl;

while(last!=NULL)
{

cout<<endl<<"Reverse traverse element is :"<<last->data;

last=last->prev;

}

free(traverse);

cout<<endl;
}


void insert_n(dnode** jai,dnode *j,int n,int item)
{

int len=countlen(j);

if(n<=0||n>len) cout<<endl<<"Not a valid position\n";

else if(n==len)
{
cout<<endl<<"Insertion at end\n";

while(j->next!=NULL)
{
j=j->next;
}

dnode* ptrnew=new dnode(); 

j->next=ptrnew;

ptrnew->data=item;

ptrnew->prev=j;

ptrnew->next=NULL;

}

else if(n>1&&n<len)
{

cout<<endl<<"Insertion at n pos\n";

int i=1;

while(i!=n-1)
{

j=j->next;
i++;
}

dnode* ptrnew=new dnode();

ptrnew->data=item;

ptrnew->next=(j->next);

(j->next)->prev=ptrnew;

(j)->next=ptrnew;

ptrnew->prev=j;

}

else if(n==1)
{
cout<<endl<<"Insertion at beg\n";

if(*jai==NULL)
{
cout<<"\nList is empty"<<"\nIt will be first element";

dnode* newptr=new dnode();

newptr->data=item;

newptr->next=NULL;

newptr->prev=NULL;

*jai=newptr;

}

else
{

cout<<endl<<"Insertion at beg but we have to shift each element\n";

dnode* newptr=new dnode();

newptr->data=item;

newptr->next=*jai;

newptr->prev=NULL;

(*jai)->prev=newptr;

*jai=newptr;

}
}

}

void deletedl(dnode** first,dnode* j,int pos)
{

int len=countlen(j);

if(*first==NULL)
{

cout<<"\nList is empty can't delete a element\n";

return;

}

else if(pos==1)
{

cout<<"\nFirst element is selected\n";

if(j->next!=NULL)
{
*first=j->next;
(j->next)->prev=NULL;
j->prev=NULL;
j->next=NULL;
j=NULL;
free(j);

if(j==NULL) cout<<"\n Sucessfully deleted "<<pos<<" node\n";

else cout<<"\n Failed to delete "<<pos<<" node\n"; 

}



else
{
cout<<"Only one element present\n";
j->prev=NULL;
j->next=NULL;
(*first)->prev=NULL;
(*first)->next=NULL;
(*first)=NULL;
free(*first);

if(*first==NULL) cout<<"\n Sucessfully deleted "<<pos<<"node\n";

else cout<<"\nFailed to delete "<<pos<<"node\n"; 

}

}

else if(pos==len)
{

cout<<"\n last node is selected\n";

int i=1;

while(i!=pos-1)
{
j=j->next;
i++;
}

(j->next)->prev=NULL;
(j->next)->next=NULL;

j->next=NULL;

free(j->next);

cout<<"\n last node is deleted\n";
}

else if(pos<=0||pos>len) 
{
cout<<"\n Invalid position\n"; 
return;
}

else
{

cout<<"\n Intermediate node is selected\n";

int i=1;

while(i!=pos-1)
{
j=j->next;
i++;
}

dnode* temp=j->next;

j->next=(j->next)->next;
(temp->next)->prev=j;

temp->prev=NULL;
temp->next=NULL;
temp=NULL;
delete temp;
//free(temp);

if(temp==NULL) cout<<"\n Sucessfully deleted "<<pos<<"node\n";

else cout<<"\n Failed to delete "<<pos<<"node and temp="<<temp->data<<" "<<temp<<"\n"; 

}

}



int countlen(dnode* len)
{
int i=0;

while(len!=0)
{
len=len->next;
i++;
}

free(len);
return i;
} 


int main()
{

dnode* head=NULL;

//append(&head,head,0);

int n,num;

cout<<"Enter no of elements :";

cin>>n;

cout<<endl<<"Enter each elements\n";


while(n--)
{

//cin>>num;

push(&head,n+1);

}


print(head);


int pos;

cout<<"\nEnter the node pos to be deleted :";

cin>>pos;

deletedl(&head,head,pos);
/*

int npos;

cout<<endl<<"Enter the postion :";

cin>>npos;

insert_n(&head,head,npos,100);

*/

print(head);

cout<<"\nNo of elements in the doublylist are :"<<countlen(head)<<endl;
}
