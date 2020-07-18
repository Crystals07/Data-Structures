// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/

bool Deteccycle(int ver,vector<int> adj[],int vis[],int parent[])
{
    
    if(!vis[ver])
    {
        cout<<"\nCurrent vertex : "<<ver<<"\n";       
            
        vis[ver] = 1;    
        
        for(auto neigh: adj[ver])
        {
            if(!vis[neigh])
            {
                
                parent[neigh] = ver;
               
                if(Deteccycle(neigh,adj,vis,parent))
                {
                     return true;
                }
            }
            
            else if(parent[ver] != neigh)
            {
                cout<<"\nneigh : "<<neigh<<" "<<" ver : "<<ver<<" "<<"parent["<<ver<<"] "<<parent[ver]<<"\n";
                return true;
            }
        }
    
    }
    
    return false;
  
}  



bool isCyclic(vector<int> adj[], int V)
{
   int vis[(int)1e4] = {0};
   
   int parent[(int)1e4];
   
   for(auto &k : parent) k = -1;
   
   
   bool flag = false;
   
   for(int i = 0;i < V && !flag ;i++) flag = Deteccycle(i,adj,vis,parent); 
   
   return flag;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends