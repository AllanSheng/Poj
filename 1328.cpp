#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int N = 1010;
struct node {
	double left, right;
}island[N];

int cmp(node a, node b) {
	return a.right<b.right;
}

int main()
{
	int n, d, kase = 0;
	while (~scanf("%d%d", &n, &d)) {
		if (n == 0 && d == 0)
			break;
		int x, y;
		double tmp;
		int flag = 0;
		for (int i = 0; i<n; i++) {
			scanf("%d%d", &x, &y);
			tmp = sqrt((double)(d*d) - y * y);
			island[i].left = x - tmp;
			island[i].right = x + tmp;
			if (y>d)
				flag = 1;
		}

		sort(island, island + n, cmp);
		printf("Case %d: ", ++kase);
		if (flag) {
			printf("-1\n");
			continue;
		}
		int ans = 1;
		node line = island[0];
		for (int i = 1; i<n; i++) {
			if (line.right<island[i].left) {
				ans++;
				line = island[i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
