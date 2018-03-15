#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

#define VER1

#ifdef VER1
int main() {
	double n, p, k;
	while (~scanf("%lf %lf", &n, &p)) {
		k = (double)pow(p, 1.0 / n);
		printf("%.0lf\n", k);
	}
}
#endif // VER1

#ifndef VER1
int main()
{
	long long left, right, mid;
	double n, p;
	while (cin >> n >> p) {
		left = 0; right = 1000000000;
		while (right > left) {
			mid = (left + right) / 2;
			if (pow(mid, n) - p>0)
			{
				right = mid;
			}
			else if (pow(mid, n) - p<0) {
				left = mid;
			}
			else {
				printf("%.0lld\n", mid);
				break;
			}
		}
	}
	return 0;
}
#endif // !VER1