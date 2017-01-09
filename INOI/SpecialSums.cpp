#include <bits/stdc++.h>
using namespace std;

const int sz = (int)1e6 + 10;
long long a[sz], b[sz];
long long pre[sz], suf[sz], mx_pre[sz], lef[sz], righ[sz];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	long long mx = 10 + LLONG_MIN/2;

	for(int i=0; i<n; i++){
	    cin >> a[i];
	}

	for(int i=0; i<n; i++){
	    cin >> b[i];
	}

	long long tmp = a[0];
	mx = max(mx, tmp);
	pre[0] = a[0];
	mx_pre[0] = pre[0];
	for(int i=1; i<n; i++){
	    pre[i] = pre[i-1] - a[i-1] + b[i-1] + a[i];
	    mx_pre[i] = max(mx_pre[i-1], pre[i]);
	}

	suf[n-1] = a[n-1];
	if(n > 1){
	    mx = max(mx, suf[n-1] + mx_pre[n-2]);
	}else{
	    mx = max(mx, suf[n-1]);
	}

	//max crossing sum
	for(int i=n-2; i>0; i--){
	    suf[i] = suf[i+1] - a[i+1] + b[i+1] + a[i];
	    mx = max(mx, suf[i] + mx_pre[i-1]);
	}
	if(n > 1){
	    suf[0] = suf[1] - a[1] + b[1] + a[0];
	    mx = max(suf[0] - b[n-1] + a[n-1], mx);
	}

	lef[0] = a[0];
	for(int i=1; i<n; i++){
		lef[i] = max(lef[i-1] + b[i], a[i]);
	}

	righ[n-1] = a[n-1];
	for(int i=n-2; i>=0; i--){
		righ[i] = max(righ[i+1] + b[i], a[i]);
	}

	//non crossing max is sum of max left sum and max right sum
	for(int i=0; i<n-1; i++){
		mx = max(mx, lef[i] + righ[i+1]);
	}

	cout << mx << endl;

	return 0;
}
