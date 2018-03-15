#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define VER1

#ifdef VER1
int main() {
	int s, d, k;
	//mode数组给出不同k值下总共需要亏损月的数量
	const int mode[5] = { 2, 4, 6, 9, 12 };
	while (~scanf("%d %d", &s, &d)) {
		k = 1;
		while (s*(5 - k) - d * k > 0)
			k++;
		k = s * (12 - mode[k - 1]) - d * mode[k - 1];
		if (k<0) printf("Deficit\n");
		else printf("%d\n", k);
	}
}
#endif // VER1

#ifndef VER1
int main()
{
	int s, d;
	int res;
	while (~scanf("%d %d", &s, &d)) {
		if (d > 4 * s)res = 10 * s - 2 * d;
		else if (2 * d>3 * s)res = 8 * s - 4 * d;
		else if (3 * d>2 * s)res = 6 * (s - d);
		else if (4 * d>s)res = 3 * (s - 3 * d);
		else res = -1;
		if (res<0)cout << "Deficit" << endl;
		else cout << res << endl;
	}
	return 0;
}
#endif // !VER1