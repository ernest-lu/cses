#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second //min
 
 
//var 
int p[200001], n, q, t1, t2, x;
pii tr[800001];
char tt;
vector<int> ans;
 
void upd(int g, int k, int a, int l, int r){
	//cout << a << " " << l << " " << r << endl;
	if(g < l || g > r)return;
	tr[a].f = max(tr[a].f, k);
	tr[a].s = min(tr[a].s, k);
	if(l == r){tr[a].f = k; tr[a].s = k; return;}
	int mid = (l + r)/2;
	upd(g, k, 2*a, l, mid);
	upd(g, k, 2*a + 1, mid+1, r);
}
 
int ge(int g, int h, int a, int l, int r){
 
	//cout << a << " " << l << " " << r << " " << tr[a].s << " " << tr[a].f << endl;
 
	if(tr[a].s > h || tr[a].f < g)
		return 0;
 
	if(tr[a].f <= h && tr[a].s >= g)
		return (r - l + 1);
 
	int mid = (l+r)/2;
	return ge(g, h, 2*a, l, mid) + ge(g, h, 2*a+1, mid+1, r);
}	
 
int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
 
	scanf("%d %d\n", &n, &q);
	for(int i = 1; i<=4*n; i++){tr[i].f = INT_MIN, tr[i].s = INT_MAX;}
	for(int i = 1; i<=n; i++){
		if(i < n)scanf("%d ", &p[i]);
		else scanf("%d\n", &p[i]);
		upd(i, p[i], 1, 1, n);
	}
 
	//cout << endl;

	 while(q--){
		scanf("%c ", &tt);
		if(tt == '!'){
			int g, k;
			scanf("%d %d\n", &g, &k);
			upd(g, k, 1, 1, n);
			continue;
		}
		int a, b;
		//cin >> a >> b;
		scanf("%d %d\n", &a, &b);
		//cout << a << " " << b << " " << ge(a,b,1,1,n) << endl;
		printf("%d\n", ge(a, b, 1, 1, n));
	}
 
	cout.flush();
	return 0;
}