#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V,M;
	std::vector<int> adj[100];

public:
	
	Graph(int,int);
	bool isCyclic();
	bool findCycle(int,bool [],bool []);
	void addeEdge(int,int);
    void Topological();
    void dfs(int,bool[],vector<int>&);
    void add();
};

Graph::Graph(int V,int M)
{
	this->V=V;
	this->M=M;
}

void Graph::addeEdge(int x,int y)
{
	adj[x].push_back(y);
}

bool Graph::isCyclic()
{
	bool recstack[100]={0};
	bool vis[100]={0};

	bool flag=false;

    for(int i=0;i<V && !flag;i++) flag = findCycle(i,vis,recstack);

	return flag;
	
}

bool Graph::findCycle(int v,bool vis[],bool recstack[])
{

	vis[v]=1;
	
	recstack[v]=1;

	for(auto neigh: adj[v])
	{
		if(!vis[neigh])
		{
			if(findCycle(neigh,vis,recstack))
				return true;
		}
		
		else if(recstack[neigh]) return true;		
	}

    recstack[v]=0;

	return false;
}

void Graph::Topological()
{
	bool vis[100]={0};

	vector<int> vec;

	for(int i=0;i<V;i++) dfs(i,vis,vec);

    cout<<"\nAfter Topological sort\n";

	for(auto it=vec.rbegin();it!=vec.rend();it++) cout<<*it<<" ";

	cout<<"\nAfter Post-order traversal Graph\n";

	for(auto j: vec) cout<<j<<" ";

	cout<<endl;	
}

void Graph::dfs(int v,bool vis[],vector<int>& vec)
{
	if(!vis[v])
	{	
		vis[v]=1;

		for(auto n: adj[v])
		{
			if(!vis[n]) dfs(n,vis,vec);
		}

		vec.push_back(v);
	}

}


void Graph::add()
{
	int u,v;

	// M == E

	cout<<"\nEnter each edge\n";

	for(int i=0;i<M;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
	}
}



int main()
{

	Graph g(2,1);
/*
	g.addeEdge(5,0);
	g.addeEdge(5,2);
	g.addeEdge(4,0);
	g.addeEdge(4,1);
	g.addeEdge(2,3);
	g.addeEdge(3,1);
*/

	g.add();

	if(g.isCyclic()) cout<<"Contains cycle\n";

	else 
	{	
		cout<<"Acyclic\n";
		g.Topological();
	}



	return 0;
}