class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
	vector<vector<int>> max_mtx(A.size() + 1, vector<int>(B.size() + 1, 0));

	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < B.size(); ++j) {
			if (A[i] == B[j]) max_mtx[i + 1][j + 1] = max_mtx[i][j] + 1;
			else max_mtx[i + 1][j + 1] = max(max_mtx[i+1][j], max_mtx[i][j+1]);
		}
	}

	return max_mtx[A.size()][B.size()];
}
};
