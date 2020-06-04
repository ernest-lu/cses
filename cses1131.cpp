#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define f first
#define s second

//var 
int n,t1,t2;
vector<int> e[200001];
queue<int> bfs;
queue<pii> bfs2;
bool v[200001];
pii tt;

int main(){
	cin >> n;
	for(int i = 1; i<n; i++){
		cin >> t1 >> t2;
		e[t1].pb(t2);
		e[t2].pb(t1);
	}bfs.push(1);
	while(!bfs.empty()){
		t1 = bfs.front(); 
		bfs.pop(); if(v[t1])continue;
		v[t1] = 1; 
		for(int u : e[t1]){
			if(!v[u])bfs.push(u);
		}
	}bfs2.push(mp(t1,0)); for(int i = 1; i<=n; i++)v[i]=0;
	while(!bfs2.empty()){
		tt = bfs2.front();
		v[tt.f] = 1;
		bfs2.pop();
		for(int u : e[tt.f]){
			if(v[u])continue;
			bfs2.push(mp(u,tt.s+1));
		}
	}cout << tt.s << endl;
}