#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n,x[200001], t[200001], p;

void upd(int g, int k){
	for(;g <= n; g += (g&-g))
		t[g] += k;
}

LL ge(int g){
	LL res = 0;
	for(; g>0; g-=(g&-g))
		res += t[g];
	return res;
}

int main(){
	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> x[i];
		upd(i,1);
	}
	for(int i = 1; i<=n; i++){
		cin >> p;
		LL l = 1, r = n, mid;
		while(l<r){
			mid = (l+r)/2;
			if(ge(mid) >= p) r = mid;
			else l = mid+1;
		}
		cout << x[l] << " ";
		upd(l,-1);
	} cout << endl;
}