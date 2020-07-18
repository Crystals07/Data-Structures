#include <bits/stdc++.h>
using namespace std;

 std::vector<int> adj[100];
 
  int vis[10000];


 void dfs(int x)
{   
   cout<<x<<" ";

   vis[x]=1;

   for(auto vertex: adj[x])
   {
   		if(vis[vertex]!=1)
       {
       		//vis[vertex]=1;
       		dfs(vertex);
       }   			
   }
}


   int main()
 {

   int row,x,y;
   cin>>row;

   for (int i = 0; i < 1e4; ++i) vis[i]=0;

   for(int i=0;i<row;i++)
   {
   		cin>>x>>y;

   		adj[x].push_back(y);
   		adj[y].push_back(x);
   }
     
     dfs(0);

 }
