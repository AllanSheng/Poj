#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <stack>
#include <algorithm>
using namespace std;

#define VER1

#ifdef VER1
char paren[50];
int W[100];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int a = 0, b, x = 0, n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &b);
			for (int i = 0; i < b - a; i++)
				paren[x++] = '(';
			a = b;
			paren[x++] = ')';
		}
		int q = 0, l, r;
		for (int i = 0; i < x; i++) {
			l = 0, r = 1;
			if (paren[i] == ')') {
				int j = i;
				while (l != r) {
					j--;
					if (paren[j] == '(')
						l++;
					else
						r++;
				}
				W[q++] = l;
			}
		}
		for (int i = 0; i < q; i++)
			printf("%d", W[i]);
		printf("\n");
	}
}
#endif // VER1

#ifndef VER1
int main() {
	int T, n, a[25], i, j;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		a[0] = 0;
		for (i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			j = i - 1;
			while (a[i] - a[j] < i - j) j--;
			printf("%d ", i - j);
		}
		printf("\n");
	}
}
#endif // !VER1