#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second
 
struct nd{
	LL mxl;
	LL mxr;
	LL mx;
	LL s;
};
 
//var 
LL n, m, a[200001], gg, kk;
nd tr[800001];
 
void upd(int g, int k, int z, int l, int r){
	if(g > r || g < l) return;
	if(l == r){
		tr[z].mxl = k;
		tr[z].mxr = k;
		tr[z].mx = k;
		tr[z].s = k;
		return;
	}
	nd t1, t2; int mid = (l + r)/2;
	upd(g, k, 2*z, l, mid);
	upd(g, k, 2*z+1, mid+1, r);
	t1 = tr[2*z]; t2 = tr[2*z + 1];
	tr[z].mxl = max(t1.mxl, t1.s + t2.mxl);
	tr[z].mxr = max(t2.mxr, t2.s + t1.mxr);
	tr[z].s = t1.s + t2.s;
	tr[z].mx = max(max(t1.mx, t2.mx), t1.mxr + t2.mxl);
}
 
LL ge(){
	return tr[1].mx;
}
 
int main(){
	//setIO("");
 
	cin >> n >> m;
	for(int i = 1; i<=n; i++){
		cin >> a[i];
		upd(i, a[i], 1, 1, n);
	}
 
	while(m--){
		cin >> gg >> kk;
		upd(gg, kk, 1, 1, n);
		cout << max((LL)0,ge()) << endl;
	}
 
	cout.flush();
	return 0;
}