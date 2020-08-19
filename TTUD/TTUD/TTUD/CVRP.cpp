int n, k, q;

int s[N];
int ans = 0;
void search(int i) {
	if (i > n) {
		int res = 1;
		for (int j = 1; j <= k; j++) {
			res *= factorial[nt[j]];
		}
		ans += res;
		return;
	}
	else {
		for (int j = 1; j <= k; j++) {
			if(s[j]+a[i]<=q)
			x[i] = j;
			s[j] += a[i];
			search(i+1);
			s[j] -= a[i];
			nt[j] -= 1;
		}
	}
}



void input() {
	cin >> n >> k >> q;
	for (int i = 1; i <= n; i++)cin >> a[i];
	search(1);
	return 0;
}