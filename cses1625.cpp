#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define FOR(i, n) for(int i = 1; i<=n; i++)
#define F0R(i, n) for(int i = 0; i<n; i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
string pth;
map<string, bool> v;

void dfs(int x, int y, string g){
	if(v[g]) return;
	if(g.size() > 48) return;
	v[g] = 1;
	if(x + 1 <= 7 && !v[g + "D"]) dfs(x+1, y, g+"D");
	if(y + 1 <= 7 && !v[g + "R"]) dfs(x, y+1, g+"R");
	if(x - 1 > 0 && !v[g + "U"]) dfs(x-1, y, g+"U");
	if(y - 1 > 0 && !v[g + ""])
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> pth;
	dfs(1, 1, "");

	cout.flush();
	return 0;
}