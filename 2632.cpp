#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <stack>
#include <algorithm>
using namespace std;

struct bot {
	int x, y, direct;
}Bots[101];

struct o {
	int num, turn, repeat;
}orders[101];

int dir[4][2] = { {0,-1},{1,0},{0,1},{-1,0} };

int main()
{
	int i, K, A, B, M, N;
	scanf("%d", &K);
	while (K--) {
		scanf("%d%d\n%d%d", &A, &B, &N, &M);
		char c;
		for (i = 1; i <= N; i++) {
			int p, q;
			scanf("%d %d %c", &p, &q, &c);
			Bots[i].x = p;
			Bots[i].y = B + 1 - q;
			switch (c)
			{
			case 'N': Bots[i].direct = 0;	break;
			case 'E': Bots[i].direct = 1;	break;
			case 'S': Bots[i].direct = 2;	break;
			case 'W': Bots[i].direct = 3;	break;
			}
		}
		int flag = 1;
		for (i = 1; i <= M; i++) {
			scanf("%d %c %d", &orders[i].num, &c, &orders[i].repeat);
			for (int j = 0; flag && j < orders[i].repeat; j++) {	//repeat
				if (c == 'L') {
					Bots[orders[i].num].direct = (Bots[orders[i].num].direct - 1 + 4) % 4;
				}
				else if (c == 'R') {
					Bots[orders[i].num].direct = (Bots[orders[i].num].direct + 1 + 4) % 4;
				}
				else if (c == 'F') {
					int x = Bots[orders[i].num].x + dir[Bots[orders[i].num].direct][0];
					int y = Bots[orders[i].num].y + dir[Bots[orders[i].num].direct][1];
					if (x == 0 || y == 0 || x == A + 1 || y == B + 1) {
						printf("Robot %d crashes into the wall\n", orders[i].num);	
						flag = 0;
					}
					else {
						for (int m = 1; m <= N; m++) {
							if (x == Bots[m].x && y == Bots[m].y) {
								printf("Robot %d crashes into robot %d\n", orders[i].num, m);
								flag = 0;
							}
						}
					}
					if (flag) {
						Bots[orders[i].num].x = x;
						Bots[orders[i].num].y = y;
					}
				}
			}
		}
		if (flag)
			printf("OK\n");
	}
}