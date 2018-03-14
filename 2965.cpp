#include <stdio.h> 
int map = 0;
const int END = 0xFFFF;

const int state[16] = { 0xF888, 0xF444, 0xF222, 0xF111,
0x8F88, 0x4F44, 0x2F22, 0x1F11,
0x88F8, 0X44F4, 0X22F2, 0X11F1,
0X888F, 0X444F, 0X222F, 0X111F };
int result = 17;

int x[16] = { 0 };
int y[16] = { 0 };

int ansX[16] = { 0 };
int ansY[16] = { 0 };


void read()
{
	char c;
	for (int i = 0; i < 16; i++) {
		c = getchar();
		if (c == '-') {		//´ò¿ª 1
			map = map << 1;
			map = (map ^ 1);
		}
		else if (c == '+') {	//¹Ø±Õ 0
			map = map << 1;
		}
		else
			i--;
	}
}
void search(int idx, int step)
{
	if (step >= result)
		return;
	if (idx >= 16) {
		if (map == END) {
			if (step < result) {
				result = step;
				for (int i = 0; i < step; i++) {
					ansX[i] = x[i];
					ansY[i] = y[i];
				}
			}//end if step 
		}//end if map 
		return;
	}
	search(idx + 1, step);
	map = map ^ state[idx];
	x[step] = idx / 4 + 1;
	y[step] = idx % 4 + 1;
	search(idx + 1, step + 1);
	map = map ^ state[idx];
	return;
}
void print()
{
	if (result < 17) {
		printf("%d\n", result);
		for (int i = 0; i < result; i++) {
			printf("%d %d\n", ansX[i], ansY[i]);
		}
	}

}
int main()
{
	read();
	//printf("%0x\n", map);
	search(0, 0);
	print();
	return 0;
}
