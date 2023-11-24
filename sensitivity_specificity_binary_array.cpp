#include <iostream>
#include <vector>

using namespace std;


#include <iostream>
#include<array>
#include <vector>

using namespace std;

std::array<double, 2> solution(vector<int>& A, vector<int>& B)
{

	std::vector<int>::size_type N = A.size();
	int noOfPositive = 0, sensitivity = 0, specifity = 0;
	std::array<double, 2> sol;
	bool p = false;
	for (int h = 0; h < N; h++) {
		if ((A[h] != 0 && A[h] != 1) || (B[h] != 0 && B[h] != 1)) { p = true; };
		if (p) break;
		else if (A[h] == 1) { noOfPositive++; if (B[h] == 1) sensitivity++; }// noOfPositive counts how many positive cases we have
		else if (A[h] == 0) { if (B[h] == 0) specifity++; }
	}

	if (p) cout << "all entries should be 0 or 1" << endl;
	else if (noOfPositive == N || noOfPositive == 0) cout << "A should contain at least one 0 and at least one 1";
	else {
		sol[1] = double(specifity) / double(N - noOfPositive);
		sol[0] = double(sensitivity) / double(noOfPositive);
	}
	return sol;
}

int main()
{
	//testing 
	std::vector<int> A(8), B(8);
	std::array<double, 2> Sol;
	A[0] = 1; A[1] = 0; A[2] = 0; A[3] = 1; A[4] = 0; A[5] = 1; A[6] = 1; A[7] = 0;
	B[0] = 1; B[1] = 1; B[2] = 0; B[3] = 1; B[4] = 1; B[5] = 1; B[6] = 0; B[7] = 1;
	/*for (int i = 0; i < 5; i++) {
		A[i] = i;
		B[i] = 0;
	}*/
	Sol = solution(A, B);
	cout << "Sensitivity is " << Sol[0] << endl;
	cout << "Specifity is " << Sol[1] << endl;

	return 0;
}