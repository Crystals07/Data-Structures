/*This code is contributed by Jaideep Rana*/

#include<bits/stdc++.h>
using namespace std;

//Dijkestra code

class Graph
{
	int V,E;

	vector<pair<int,int> > v[(int)1e2];

public:

	Graph(int,int);
	void addEdge(int,int,int);
	void Dijkstras(int,int);
};

Graph::Graph(int V,int E)
{
	this->V=V;
	this->E=E;
}

void Graph::addEdge(int x,int y,int z)
{
	v[x].push_back({y,z});
	v[y].push_back({x,z});

	/* (x,y) is edge from x 2 y
       (y,z) z is edge weight
    */
}

void Graph::Dijkstras(int x,int y)
{
	
	int dis[(int)1e2];
	int vis[(int)1e2];

	int parent[(int)1e4];

	priority_queue< pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > > q;

	q.push({0,x});

	memset(dis,1e4,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(parent,-1,sizeof(parent));

	cout<<"Starting dijkstras"<<endl;

	while(q.size())
	{
		int curr_vertex = q.top().second;
		int distance = q.top().first;
		q.pop();

		if(vis[curr_vertex]) continue;

		cout<<"@ "<<curr_vertex<<" "<<distance<<endl;

		dis[curr_vertex] = distance;
		vis[curr_vertex] = 1;

		if(curr_vertex == y) break;

		for(auto neigh: v[curr_vertex])
		{
			cout<<"neigh "<<neigh.first<<" DISTANCE "<<neigh.second<<"\n";

			if(dis[neigh.first] > dis[curr_vertex]+ neigh.second)
			{
				parent[neigh.first] = curr_vertex;
				q.push({dis[curr_vertex]+neigh.second,neigh.first});
				dis[neigh.first] = dis[curr_vertex]+ neigh.second;
			}
		} 
	}

	cout<<"\nAfter Dijkstras algorithm\n";

	for(int i=0;i<=V;i++) cout<<i<<" MIN DISTANCE :"<<dis[i]<<"\n";

	cout<<"\nMinimum distance\n";
	
	int spath=y;

	vector<int> p;

	while(parent[spath]!=-1)
	{
		p.push_back(parent[spath]);

		spath=parent[spath];
	}

	for(auto it=p.rbegin();it!=p.rend();it++) cout<<*it<<" ";

	cout<<y<<endl;	
}




int main()
{
	int V,E,x,y;

	//cout<<"\nEnter total Vertices and Edges\n";

	//cin>>V>>E;

    V=8;
    E=14;

	cout<<"\nEnter source and Destination\n";

	cin>>x>>y;

	Graph g(V,E);

	g.addEdge(0,1,4);
	g.addEdge(0,7,8);
	g.addEdge(1,2,8);
	g.addEdge(1,7,11);
	g.addEdge(7,8,7);
	g.addEdge(7,6,1);
	g.addEdge(2,8,2);
	g.addEdge(2,3,7);
	g.addEdge(2,5,4);
	g.addEdge(8,6,6);
	g.addEdge(6,5,2);
	g.addEdge(5,4,10);
	g.addEdge(5,3,14);
	g.addEdge(3,4,9);

	g.Dijkstras(x,y);

}