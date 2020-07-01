#include <bits/stdc++.h>
using namespace std;

vector<float> matrixMultiply(vector<vector<float>> matrix, vector<float> eigen) {
	int row = matrix.size(),
	    col = row;
	vector<float> res(row);
	for(int i = 0; i < row; i++) {
		float val = 0;
		for(int j = 0; j < col; j++)
			val += matrix[i][j] * eigen[j];
		res[i] = val;
	}
	return res;
}

bool isdone(float e1, float e2) {
	return abs(e1 - e2) >= 0.0001;
}

vector<float> divideit(vector<float> &matrix, float divisor) {
	vector<float> result;
	for(int i = 0; i < matrix.size(); i++) {
		result.push_back(matrix[i] /= divisor);
	}
	return result;
}

int main() {
	int row, col;
	cout << "Enter the dimension of matrix:\n";
	cin >> row >> col;
	vector<vector<float>> matrix(row, vector<float>(col));
	vector<float> eigen(row);
	cout << "Enter the matrix:\n";
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			cin >> matrix[i][j];
	cout << "Enter the initial guess:\n";
	for(int i = 0; i < row; i++)
		cin >> eigen[i];
	int itr = 0;
	cout << fixed << setprecision(4);
	float prev = -1000, curr = *max_element(eigen.begin(), eigen.end());
	while(isdone(prev, curr)) {
		prev = curr;
		eigen = matrixMultiply(matrix, eigen);
		curr = *max_element(eigen.begin(), eigen.end());
		eigen = divideit(eigen, curr);
		itr++;
		cout << "Step no : " << itr << "\n";
		cout << "Eigen Value : " << curr << "\n";
		cout << "Eigen Vector : \n";
		for(auto val:eigen) cout << val <<"\n";
		cout << endl;
	}
	cout << "\nAnswer is \n";
	cout << "Eigen Value : " << curr << "\n";
	cout << "Eigen Vector : \n";
	for(auto val:eigen) cout << val <<"\n";
	return 0;
}
