#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


struct nd{
	LL t = 0;
	pii as = mp(0, 0);
	pii ss = mp(0, 0);
};

//var 
LL n, q, a[200001];
nd tr[800001];

void prop(int z, int l, int r){
	int mid = (l + r)/2, sz1 = mid - l + 1, sz2 = r - (mid+1) +1, sz = sz1 + sz2;
	if(tr[z].as.f > tr[z].ss.f){
		tr[2*z].as = max(tr[2*z].as, tr[z].as);
		tr[2*z + 1].as = max(tr[2*z + 1].as, tr[z].as);
		tr[2*z].t = sz1 * tr[z].as.s;
		tr[2*z+1].t = sz2 * tr[z].as.s;
	}

	else{

	}

	tr[z].as = mp(0, 0);
	tr[z].ss = mp(0, 0);
}

void psh(int a, int b, int z, int l, int r){
	if(r < a || l > b) return;
	if(l >= a && r <= b) return;
	prop(z, l, r);
	int mid = (l + r)/2;
	psh(a, b, 2*z, l, mid);
	psh(a, b, 2*z+1, mid+1, r);
}

void ass(int a, int b, pii o, int z, int l, int r){
	if(r < a || l > b) return;
	if(l >= a && r <= b){
		tr[z].t = (o.s) * (r - l + 1);
		tr[z].as = max(o, tr[z].as);
		return;
	} 

	int mid = (l + r)/2;
	ass(a, b, o, 2*z, l, mid);
	ass(a, b, o, 2*z+1, mid+1, r);

	tr[z].t = tr[2*z].t + tr[2*z+1].t;

}

void iss(int a, int b, pii o, int z, int l, int r){
	if(r < a || l > b) return;
	if(l >= a && r <= b){
		tr[z].t += (o.s) * (r - l + 1);
		tr[z].ss.f = o.f; tr[z].ss.s += o.s;
		return;
	} 

	int mid = (l + r)/2;
	iss(a, b, o, 2*z, l, mid);
	iss(a, b, o, 2*z+1, mid+1, r);

	tr[z].t = tr[2*z].t + tr[2*z+1].t;

}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);



	cout.flush();
	return 0;
}