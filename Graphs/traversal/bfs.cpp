#include<bits/stdc++.h>
using namespace std;

 void bfs(vector<int> adj[])
 {

 	int beg=0;  
 
 	queue<int> q;

 	q.push(beg);

 	int vis[100];
    
   for(int i=0;i<100;i++) vis[i]=0;
 	
   
 	vis[beg]=1;


 	while(!q.empty())
 	{
        int vertex=q.front();
        
        cout<<vertex<<" ";

        q.pop();

        for(int i: adj[vertex])
        {
        	if(vis[i]!=1)
            {
        		q.push(i);
        		vis[i]=1;

            }
        }


 	 }	


  }


int main()
{
	int row,x,y;

	cin>>row;

    vector<int> adj[100];

    for(int i=0;i<row;i++)
   {
      	cin>>x>>y;

      	adj[x].push_back(y);
      	adj[y].push_back(x);
   }

   cout<<"cnc"<<endl;

   bfs(adj);

} 