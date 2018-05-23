#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 101;
int D[MAX][MAX];
int main()
{
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= i; j++) {
                        cin >> D[i][j];
                }
        }
        for (int i = N - 1; i >= 1; i--) {
                for (int j = 1; j <= i; j++) {
                        D[i][j] = max(D[i + 1][j], D[i + 1][j + 1]) + D[i][j];
                }
        }
        cout << D[1][1];
}