void PhanPhoiTheoK(int A[], int B[], int C[], int& m, int& n, const int& k)
{
	int i = 0;
	while (i < MAX)
	{
		for (int j = 0; j < k; j++)
			B[j] = A[i++];
		for (int q = 0; q < k; q++)
			C[q] = A[i++];
	}
}