#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n,m, ans = 0, dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1}, ar[1001][1001], c[1001][1001];
string s;
bool v[1001][1001];
pii ap,bp;

void dfs(int x, int y){
	//cout << x << " " << y << endl;
	v[x][y] = 1; c[x][y] = ans;
	for(int i = 0; i<4; i++){
		int xx = x + dx[i], yy = y+dy[i];
		if(xx > n || xx <= 0)continue;
		if(yy > m || yy <= 0)continue;
		if(!ar[xx][yy])continue;
		if(v[xx][yy])continue;
		dfs(xx,yy);
	}
}

void dfu(int x, int y, int p){
	
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m;
	for(int i = 1; i<=n; i++){
		cin >> s;
		for(int j = 0; j<m; j++){
			if(s[j] == '#')continue;
			if(s[j] == 'A')ap = mp(i,j+1);
			if(s[j] == 'B')bp = mp(i,j+1);
			ar[i][j+1] = 1;
		}
	}

	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			if(!ar[i][j])continue;
			if(v[i][j])continue;
			//cout << i << " " << j << endl;
			ans++;
			dfs(i,j);
		}
	}
	if(c[ap.f][ap.s] != c[bp.f][bp.s]){
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;

	cout.flush();
	return 0;
}