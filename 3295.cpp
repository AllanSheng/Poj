#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <stack>
#include <algorithm>
using namespace std;
#define MAX_LEN 101
char str[MAX_LEN];

int check(int len, int p, int q, int r, int s, int t) 
{
	stack<int> st;
	for (int i = len - 1; i >=0; i--) {
		if (str[i] == 'p') st.push(p);
		else if (str[i] == 'q') st.push(q);
		else if (str[i] == 'r') st.push(r);
		else if (str[i] == 's') st.push(s);
		else if (str[i] == 't') st.push(t);
		else if (str[i] == 'K') {
			int tmp1 = st.top(); st.pop();
			int tmp2 = st.top(); st.pop();
			st.push(tmp1 && tmp2);
		}
		else if (str[i] == 'A') {
			int tmp1 = st.top(); st.pop();
			int tmp2 = st.top(); st.pop();
			st.push(tmp1 || tmp2);
		}
		else if (str[i] == 'N') {
			int tmp1 = st.top(); st.pop();
			st.push(!tmp1);
		}
		else if (str[i] == 'C') {
			int tmp1 = st.top(); st.pop();
			int tmp2 = st.top(); st.pop();
			if (tmp1&&!tmp2)
				st.push(0);
			else
				st.push(1);
		}
		else if (str[i] == 'E') {
			int tmp1 = st.top(); st.pop();
			int tmp2 = st.top(); st.pop();
			if (tmp1==tmp2)
				st.push(1);
			else
				st.push(0);
		}
	}
	return st.top();
}

int solve(char str[])
{
	int len = strlen(str);
	for (int p = 0; p < 2; p++) {
		for (int q = 0; q < 2; q++) {
			for (int r = 0; r < 2; r++) {
				for (int s = 0; s < 2; s++) {
					for (int t = 0; t < 2; t++) {
						int mark = check(len, p, q, r, s, t);
						if (mark == 0)
							return 0;
					}//t
				}//s
			}//r
		}//q
	}//p
	return 1;
}

int main()
{
	while (~scanf("%s",str)) {
		if (strcmp(str, "0") == 0)
			break;

		int flag = solve(str);
		if (flag) 
			printf("tautology\n");
		else
			printf("not\n");
	}
	return 0;
}