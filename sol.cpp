#include <bits/stdc++.h>

using namespace std;

int Power(int a, int b) {
	int res = 1;
	while (b > 0) {
		if (b & 1) {
			res *= a;
		}
		a *= a;
		b >>= 1;
	}
	return res;
}

int Binary(int num, int k) {
	int arr[16] = {0};
	int cnt = 0;
	// another approach to convert decimal to binary
	for (int i = 15; i >= 0; i--) {
		int temp = num >> i;
		arr[cnt++] = (temp & 1 ? 1 : 0);
	}
	// reverse the binary (based on the problem statement)
	reverse(arr, arr + 16);
	int d = 0;
	int index = 0;
	// must start with k - 1 (must add zeroes if needed)
	for (int i = k - 1; i >= 0; i--) {
		d += (arr[i] * Power(2, index));
		index++;
	}
	return d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int k;
		cin >> k;
		string s;
		cin >> s;
		// convert the current i value to its binary equivalent, then reverse the bits
		// afterwards, every binary value with less than k bits must be padded on the left
		// with zeroes so they are written with exactly k bits
		// swap the character in the i-th index with the character on the new index calculated
		bool vis[1 << k] = {false};
		for (int i = 0; i < (1 << k); i++) {
			int id = Binary(i, k);
			if (!vis[id]) {
				vis[i] = true;
				vis[id] = true;
				swap(s[i], s[id]);
			}
		}
		cout << s << '\n';
	}
	return 0;
}
