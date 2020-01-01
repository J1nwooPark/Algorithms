#include <iostream>
#include <algorithm>
#define MAX_LEN 1000
using namespace std;
void LCS(string a, string b, int lcs[MAX_LEN + 1][MAX_LEN + 1])
{
	for (int i = 0; i <= a.length(); i++)
		lcs[i][0] = 0;
	for (int i = 0; i <= b.length(); i++)
		lcs[0][i] = 0;

	for (int i = 1; i <= a.length(); i++)
		for (int j = 1; j <= b.length(); j++)
			if (a[i - 1] == b[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
}
