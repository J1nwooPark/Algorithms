#include <algorithm>
void MatrixChain(int min_multiple[][/*matrix_num/*], int matrix_rowcols[], int matrix_num)
{
	for (int i = 0; i < matrix_num; i++)
		min_multiple[i][i] = 0;
	for (int i = 1; i < matrix_num; i++)
	{
		for (int j = 0; j < matrix_num - i; j++)
		{
			min_multiple[j][j + i] = 987654321;
			for (int k = j; k < j + i; k++)
				min_multiple[j][j + i] = std::min(min_multiple[j][j + i], min_multiple[j][k] + min_multiple[k + 1][j + i] + matrix_rowcols[j] * matrix_rowcols[k + 1] * matrix_rowcols[j + i + 1]);
		}
	}
}
