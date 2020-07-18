/*
    ( ´-ω･)︻┻┳══━一一一一一一一				(× _ ×)
	
	Stay Low. Go Fast
	Kill First. Die Last
	One Shot. One Kill
	No Luck. Pure Skill 
*/

#include<bits/stdc++.h>
using namespace std;

/*************************** MACROS **************************/
#define ld long double
#define ll long long  
#define ull unsigned long long
#define loop(i,x,y) for(ll i=x;i<y;i++)
#define rloop(i,x,y) for(ll i=x;i>=y;i--)
#define vll vector<ll>
#define pb push_back
#define S second
#define F first
#define B begin()
#define E end()
#define W(x) while(x--)
#define pll pair< ll,ll >
#define vpll vector< pll >
#define qll queue<ll>
#define dqll deque<ll>
#define qpll queue<pll>
#define dqpll deque<pll>
#define pqll priority_queue<ll>
#define pqpll priority_queue<pll>
#define Line cout<<"\n**************************\n\n";

/*************************** CONST ******************************/

const ll MOD = 1000000007;
const ll MOD1 = 998244353;
const ll MIN_LL = -1e18;
const ll MAX_LL = 1e18;
const int MAX_INT = 1e9;
const int MIN_INT = -1e9;
const ld pie = 3.1415926535;
 
/************************** POW UTIL *****************************/
 
ll fpow(ll n,ll p){;ll m=1;while(p){if(p%2)m*=n;p>>=1;n*=n;}return m;}
ll mfpow(ll n,ll p,ll M){ll m=1;n%=M;while(p){if(p%2)m=(m*n)%M;n=(n*n)%M;p>>=1;}return m%M;}
 
/************************* PRINT UTIL *****************************/

template<class T> inline ostream& operator<<(ostream& o,vector<T> v){for(auto i:v)o<<i<<" ";return o;};
template<class T> inline ostream& operator<<(ostream& o,set<T> s){for(auto i:s)o<<i<<" ";return o;}
template<class T> inline ostream& operator<<(ostream& o,multiset<T> s){for(auto i:s)cout<<i<<" ";return o;}
template<class T1,class T2> inline ostream& operator<<(ostream& o,pair<T1,T2> p){o<<p.F<<" "<<p.S<<"\n";return o;}
template<class T1,class T2> inline ostream& operator<<(ostream& o,map<T1,T2> m){for(auto p:m)o<<p.F<<" "<<p.S<<"\n";return o;}

/*************************** VARIABLES **************************/

const vll days={31,28,31,30,31,30,31,31,30,31,30,31};
 
bool br,br1,br2; 
char ch,ch1,ch2;
 

ll n,m,k,x,y,z,mini,maxi,l,r,sum,t,w;
pll p,p1,p2;

string s,s1,s2;

set<ll> st,st1,st2;
multiset<ll> mst; 

map<ll,ll> mp;

/**************************** FXNS ****************************/

vpll v[(int)1e6+100];
bool vis[(int)1e6+100];
ll d[(int)1e6+100];

void solve()
{

	// num of vertices and edges
	cin>>n>>m;

	// init dis to infy
	loop(i,0,n)d[i] = MAX_LL;

	// getting edges
	loop(i,0,m)
	{
		cin>>x>>y>>z;

		// building adj
		v[x].pb({y,z});
		v[y].pb({x,z});
	}

	priority_queue<pll,vpll,greater<pll> > q;

	// source and dest
	cin>>x>>y;

	// init source with 0
	q.push({0,x});

	cout<<"running disktras"<<endl;

	while(q.size())
	{
		// vertex
		z = q.top().S;
		// dis
		k = q.top().F;
		q.pop();

		cout<<"@ "<<z<<" "<<k<<" "<<vis[z]<<endl;

		// already visited
		if(vis[z])continue;

		d[z] = k;
		vis[z] = 1;

		// reached dest
		if(z == y)break;

		// iter over neighbour
		for(auto i:v[z])
		{	
			// relaxation

			cout<<"# "<<i.F<<" "<<d[i.F]<<" "<<d[z]+i.S<<endl;

			if(d[i.F] > d[z]+i.S)
			{
				q.push({d[z]+i.S,i.F});
			}
		}

	}

	loop(i,0,n)cout<<d[i]<<" ";cout<<"\n";
	cout<<"final distance b/w "<<x<<" "<<y<<" is "<<d[y]<<endl;
}
 
/*************************** MAIN ****************************/
 
int main(){
 
 
	// #ifndef ONLINE_JUDGE
	        // freopen("input.txt", "rt", stdin);
	        // freopen("output.txt", "wt", stdout);
	// #endif
 
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);

	solve();
 
	return 0;
}
