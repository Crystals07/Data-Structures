#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[],int e)
{
	int vis[100]={0};

	int parent[100];

    memset(parent,-1,sizeof(parent));

    //for(auto j: parent) cout<<j<<" ";

	int beg=0;
        
	vis[beg]=1;

    queue<int> q;

    q.push(beg);

    while(!q.empty())
    {
    	int vertex=q.front();

        cout<<vertex<<" ";

    	q.pop();

    	for(auto y: adj[vertex])
    	{
    		if(!vis[y])
    		{
    			q.push(y);
    			vis[y]=1;
    			parent[y]=vertex;
    		}

    		else 
    		{
    			if(parent[y] != vertex) cout<<"\nLoop detected\n"<<vertex<<" "<<y<<"\n";
    		    break;
    		}
    	}
    }
}




int main()
{

	int e,m,x,y;

    cout<<"\nEnter no of vertex :\n";

    cin>>e;

	cout<<"Enter no of edges : ";

    cin>>m;

	vector<int> adj[100];

	for(int i=0;i<m;i++)
	{
		cin>>x>>y;

		adj[x].push_back(y);
		adj[x].push_back(y);
	}


    bfs(adj,e);
   
	return 0;
}