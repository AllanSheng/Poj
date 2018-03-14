#include <stdio.h>  

int map = 0;
const int END1 = 0x0000;
const int END2 = 0xFFFF;
const int state[16] = { 0xC800, 0xE400, 0x7200, 0x3100,
0x8C80, 0x4E40, 0x2720, 0x1310,
0x08C8, 0X04E4, 0X0272, 0X0131,
0X008C, 0X004E, 0X0027, 0X0013 };
int result = 17;

void read() 
{
	char c;
	for (int i = 0; i < 16; i++) {
		c = getchar();
		if (c == 'b') {
			map = map << 1;
			map = (map ^ 1);
		}
		else if (c == 'w') {
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
		if (map == END2 || map == END1)	{
			if (step < result) {
				result = step;
			}//end if step  
		}//end if map  
		return;
	}
	search(idx + 1, step);
	map = map ^ state[idx];
	search(idx + 1, step + 1);
	map = map ^ state[idx];

	return;
}

void print()
{
	if (result >= 17)
		printf("Impossible");
	else
		printf("%d", result);
}

int main()
{
	read();
	search(0, 0);
	print();
	return 0;
}
