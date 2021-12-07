#include<iostream>
#include<Eigen/Dense>//I used the Eigen 3.4.0 library

using namespace std;

int main()
{
	int row, col;
	cout << "This program outputs the matrix that computes projection over a subspace\n";
	cout << "To populate the matrix whose colomn vectors are spanning vectors of the subpace that we will project over it\n";
	cout << "Please enter the number of row and coloumns seperated by a space respectively: ";

	cin >> row >> col;
	cout << endl;
	Eigen::MatrixX<double> A(row,col);
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			cout << "What is the " << i << "th row " << j << "th col's element?";
			cin >> A(i-1,j-1);
			cout << endl;
		}
	}
	
	cout << A << endl;
	cout << endl;
	
	Eigen::MatrixX<double> B(row, col);
	cout << "To Find the Projection Over the Subspace, the Matrix Below Will Be The Left Operand of Matrix Multiplication:\n\n";
	B=A*((A.transpose()*A).inverse())*A.transpose();

	cout << B << endl<<endl;

	Eigen::MatrixX<double> V(row, 1);
	
	for (int i = 1; i <= row; i++)
	{
		cout << "What is the " << i << "th element of the vector? ";
		cin >> V(i - 1, 0);
		cout << endl;
	}
	cout << endl<<"The projection of the vector over the subspace is below: "<<endl<<endl;
	cout << B * V << endl;

	

	cin.get();
	return 0;
}
