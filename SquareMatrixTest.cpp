/*
 * SquareMatrixTest.cpp
 *
 *  Created on: University Collage London. 
 *		  Date: 12.2018-01.2019
 *      Author: student number:18043309 
 */

#include "Matrix.h"
#include "SquareMatrix.h"
#include <cstdlib>
#include <typeinfo>
#include <stdio.h>

using namespace std;

void onesAndeyesTesting () {
	cout << "Testing the function ones and eyes" << endl;
	cout << "Case 1:Creating a 4x4 matrix of ones with the ones:" << endl;
	{
		SquareMatrix matrix(4,4);
		cout<<"matrix1 = "<<endl;	
		cout << matrix.Ones(4,4)<< endl;
		cout << "Press any key to continue ..." << flush;
		system("read");
		cout << endl;
	}

	cout << "Case 2:Creating a 4x4 unit matrix with the eye:" << endl;
	{
		SquareMatrix matrix(4,4);
		cout<<"matrix2 = "<<endl;	
		cout << matrix.eye(4)<< endl;
		cout << "Press any key to continue ..." << flush;
		system("read");
		cout << endl;
	}
}


void ToeplitzTesting () {
	cout << "Testing the function toeplitz:" << endl;
	cout << "Case 1: When the input is only one vector" << endl;
	{
		double vec1[4] = {4, 3, 2, 1};
		// matrix should be stored as following
     	//4     3     2     1
     	//3     4     3     2
    	//2     3     4     3
     	//1     2     3     4
     	cout<<"vec1 = "<<endl;
     	cout<<" ";
     	for(int i=0;i<4;i++){
     		cout<<vec1[i]<<"       ";
     	}
     	cout<<endl;
     	cout<<endl;
		SquareMatrix toeplitz(4,4);
		cout<<"matrix3 = "<<endl;
		cout<<toeplitz.SquareMatrix::toeplitz(vec1)<<endl;
		cout << "Press any key to continue ..." << flush;
		system("read");
		cout << endl;
	}

	cout << "Case 2: When the inputs are two vectors" << endl;
	{
		double vec1[4] = {4, 3, 2, 1};
		double vec2[4] = {1, 2, 3, 4};
		// matrix should be stored as following
    	//1     3     2     1
     	//2     1     3     2
     	//3     2     1     3
    	//4     3     2     1
    	cout<<"vec1 = "<<endl;
    	cout<<" ";
     	for(int i=0;i<4;i++){
     		cout<<vec1[i]<<"       ";
     	}
     	cout<<endl;
     	cout<<"vec2 = "<<endl;
     	cout<<" ";
     	for(int i=0;i<4;i++){
     		cout<<vec2[i]<<"       ";
     	}
     	cout<<endl;
		SquareMatrix toeplitz1(4,4);
		cout<<"matrix4 = "<<endl;
		cout<<toeplitz1.SquareMatrix::toeplitz(vec2,vec1)<<endl;
		cout << "Press any key to continue ..." << flush;
		system("read");
		cout << endl;
	}
}

void TransposeTesting () {
	cout << "Testing the Transpose functions:" << endl;
	cout<<endl;
	{
		// the same matrix as in ToeplitzTesting
		double vec1[4] = {4, 3, 2, 1};
		double vec2[4] = {1, 2, 3, 4};
		SquareMatrix matrix = SquareMatrix::toeplitz(vec2,vec1);
		cout<<"the input matrix ="<<endl;
		cout<<matrix<<endl;
		Matrix transpose = Matrix::Transpose(matrix);
		cout << "Matrix5= " << endl;
		cout << transpose << endl;
		cout << "Press any key to continue ..." << flush;
		system("read");
		cout << endl;
	}
}

void triuTesting (){
	cout << "Testing the triu functions:" << endl;
	{
		// the same matrix as in ToeplitzTesting
		double vec1[4] = {4, 3, 2, 1};
		double vec2[4] = {1, 2, 3, 4};
		SquareMatrix matrix=SquareMatrix::toeplitz(vec2,vec1);
		cout<<"the input matrix ="<<endl;
		cout<<endl;
		cout<<matrix<<endl;			
		cout << "Matrix6= " << endl;
		cout <<matrix.SquareMatrix::triu(matrix,4)<< endl;
		cout << "Press any key to continue ..." << flush;
		system("read");
		cout << endl;
	}
}

void trilTesting (){
	cout << "Testing the tril functions:" << endl;
	{
		// the same matrix as in ToeplitzTesting
		double vec1[4] = {4, 3, 2, 1};
		double vec2[4] = {1, 2, 3, 4};
		SquareMatrix matrix=SquareMatrix::toeplitz(vec2,vec1);;
		cout<<"the input matrix ="<<endl;
		cout<<endl;
		cout<<matrix<<endl;		
		cout << "Matrix7= " << endl;
		cout <<matrix.SquareMatrix::tril(matrix,4)<< endl;
		cout << "Press any key to continue ..." << flush;
		system("read");
		cout << endl;
	}
}

void lu1Testing (){
	cout << "Testing the function lu" << endl;
	cout << "Algorithm 2.1"<<endl;
	cout << "Case1:it is matched with matlab syntax [lmatrix1, umatrix1] = lu(matrix3) "<<endl;
	cout<<endl;
	{
		double vec1[4] = {4, 3, 2, 1};
		// matrix should be stored as following
     	//4     3     2     1
     	//3     4     3     2
    	//2     3     4     3
     	//1     2     3     4
		SquareMatrix matrix=SquareMatrix::toeplitz(vec1);
		cout<<"the input matrix ="<<endl;
		cout<<endl;
		cout<<matrix<<endl;
		matrix.lu1(matrix);
		cout << "Press any key to continue ..." << flush;
		system("read");
		cout << endl;
	}
	cout << "Case2:when any of the pivots is equal to zero "<<endl;
	cout<<endl;
	{
		double vec1[4] = {0, 3, 2, 1};
		// matrix should be stored as following
     	//4     3     2     1
     	//3     4     3     2
    	//2     3     4     3
     	//1     2     3     4
		SquareMatrix matrix=SquareMatrix::toeplitz(vec1);
		cout<<"the input matrix ="<<endl;
		cout<<endl;
		cout<<matrix<<endl;
		matrix.lu1(matrix);
		cout << "Press any key to continue ..." << flush;
		system("read");
		cout << endl;
	}
	cout << "Case3:when the input matrix is singular "<<endl;
	cout<<endl;
	{
		static double input[9]={4,-5,7,-2,6,0,1,0,3};
		SquareMatrix matrix(3,3);
		matrix.SquareMatrix::TestingMatrixInput(input,3,3);
		cout<<"the input matrix ="<<endl;
		cout<<endl;
		cout<<matrix<<endl;
		matrix.lu1(matrix);
		cout << "Press any key to continue ..." << flush;
		system("read");
		cout << endl;
	}
}
void lu2Testing() {
	cout << "Testing the function lu" << endl;
	cout << "Algorithm 2.2"<<endl;
	
	cout << "Case 1: When the input is matrix3" << endl;
	cout << "It is matched with matlab syntax [lmatrix1, umatrix1, pmatrix1] = lu(matrix3) "<<endl;
	cout<<endl;
	{
		int dim = 4;
		double vec1[4] = {4, 3, 2, 1};
		// matrix should be stored as following
     	//4     3     2     1
     	//3     4     3     2
    	//2     3     4     3
     	//1     2     3     4
		SquareMatrix matrix1=SquareMatrix::toeplitz(vec1);
		cout<<"the input matrix ="<<endl;
		cout<<endl;
		cout<<matrix1<<endl;
		SquareMatrix lmatrix(dim,dim);
		SquareMatrix umatrix(dim,dim);
		SquareMatrix pmatrix(dim,dim);
		matrix1.lu2(matrix1,umatrix,lmatrix,pmatrix);
		cout<<"lmatrix1 = "<<endl;
		cout<<lmatrix<<endl;
		cout<<"umatrix1 = "<<endl;
		cout<<umatrix<<endl;
		cout<<"pmatrix1 = "<<endl;
		cout<<pmatrix<<endl;
		cout << "Press any key to continue ..." << flush;
		system("read");
		cout << endl;
	}

	cout << "Case 2: When the input is matrix4" << endl;
	cout << "It is matched with matlab syntax [lmatrix2, umatrix2, pmatrix2] = lu(matrix4) "<<endl;
	cout<<endl;
	{	
		int dim = 4;
		double vec1[4] = {4 ,3, 2, 1};
		double vec2[4] = {1, 2, 3, 4};
		// matrix should be stored as following
    	//1     3     2     1
     	//2     1     3     2
     	//3     2     1     3
    	//4     3     2     1
		SquareMatrix matrix2=SquareMatrix::toeplitz(vec2,vec1);
		cout<<"the input matrix ="<<endl;
		cout<<endl;
		cout<<matrix2<<endl;
		SquareMatrix lmatrix(dim,dim);
		SquareMatrix umatrix(dim,dim);
		SquareMatrix pmatrix(dim,dim);
		matrix2.lu2(matrix2,umatrix,lmatrix,pmatrix);
		cout<<"lmatrix2 = "<<endl;
		cout<<lmatrix<<endl;
		cout<<"umatrix2 = "<<endl;
		cout<<umatrix<<endl;
		cout<<"pmatrix2 = "<<endl;
		cout<<pmatrix<<endl;
		cout << "Press any key to continue ..." << flush;
		system("read");
		cout << endl;
	}
}

void applicationTesting1(){
	cout << "Testing the application of function lu" << endl;
	cout << "when Number of equations = Number of unknowns" << endl;
	cout << "Case 1: When the input is matrix3" << endl;
	{
		int dim=4;
		double b[4]={3,3,2,1};
		double vec1[4] = {4, 3, 2, 1};
		
		SquareMatrix matrix=SquareMatrix::toeplitz(vec1);	
		
		cout<<"the coefficient matrix ="<<endl;
		cout<<endl;
		cout<<matrix<<endl;
		cout<<"the right hand side array b of equations"<<endl;
		cout<<endl;
		for(int i=0;i<dim;i++){
			cout<<" "<<b[i]<<endl;
		}
		cout<<endl;
		
		cout<<"the expected solution caculated by online matrix caculator is"<<endl;
		cout<<"x1 =  0.4000"<<endl;
		cout<<"x2 =  0.5000"<<endl;
		cout<<"x3 =  0.0000"<<endl;
		cout<<"x4 = -0.1000"<<endl;
		cout<<endl;
		
		//initialize lmatrix,umatrix,pmatrix in order to get the return values from lu function
		SquareMatrix lmatrix(dim,dim);
		SquareMatrix umatrix(dim,dim);
		SquareMatrix pmatrix(dim,dim);
		matrix.SquareMatrix::lu2(matrix,lmatrix,umatrix,pmatrix);
			
		SquareMatrix Pb = SquareMatrix::b_permutation(pmatrix,b,dim);
		
		//call forwardSubstitution function, return SquareMatrix y		
		SquareMatrix y=matrix.forwardSubstitution(lmatrix,Pb,dim);
		
		//call backSubstitution function to get the solution of linear equations
		matrix.backSubstitution(umatrix,y,dim);
		
		cout << "Press any key to continue ..." << flush;
		system("read");
		cout << endl;
	}
	cout << "Case 2: When the input is matrix4" << endl;
	{
		int dim=4;
		double b[4]={3,3,2,1};
		double vec1[4] = {4, 3, 2, 1};
		double vec2[4] = {1, 2, 3, 4};
		
		SquareMatrix matrix=SquareMatrix::toeplitz(vec2,vec1);	
		cout<<"the coefficient matrix ="<<endl;
		cout<<endl;
		cout<<matrix<<endl;
		cout<<"the right hand side array b of equations"<<endl;
		cout<<endl;
		for(int i=0;i<dim;i++){
			cout<<" "<<b[i]<<endl;
		}
		cout<<endl;
		
		cout<<"the expected solution caculated by online matrix caculator ="<<endl;
		cout<<endl;
		cout<<"x1 = -0.6667"<<endl;
		cout<<"x2 =  0.4444"<<endl;
		cout<<"x3 =  0.7778"<<endl;
		cout<<"x4 = -0.7778"<<endl;
		cout<<endl;
		//initialize lmatrix,umatrix,pmatrix in order to get the return values from lu function
		SquareMatrix lmatrix(dim,dim);
		SquareMatrix umatrix(dim,dim);
		SquareMatrix pmatrix(dim,dim);
		matrix.SquareMatrix::lu2(matrix,lmatrix,umatrix,pmatrix);

		SquareMatrix Pb = SquareMatrix::b_permutation(pmatrix,b,dim);
		
		//call forwardSubstitution function, return SquareMatrix y		
		SquareMatrix y=matrix.forwardSubstitution(lmatrix,Pb,dim);

		//call backSubstitution function to get the solution of linear equations
		matrix.backSubstitution(umatrix,y,dim);
	
		cout << "Press any key to continue ..." << flush;
		system("read");
		cout << endl;
	}
}

void applicationTesting2(){
	cout << "Testing the application of function lu" << endl;
	cout << "when Number of equations > Number of unknowns" << endl;
	cout<<endl;
	cout << "Case1:when no swapping is required" << endl;
	cout<<endl;
	{
		int m=4;
		int n=3;
		double b[4]={3,3,2,1};
		double input[12] = {2, 1, 3, -1, 4, 2, 1, 5, -1, 2, 2, 1};
		Matrix A(4,3);
		A.Matrix::TestingInput(input,4,3);
			
		double* input_ATA=A.Matrix::lss_ATA(A);
	
		SquareMatrix AT_A(3,3);
		AT_A.SquareMatrix::TestingMatrixInput(input_ATA,3,3);
		
		cout<<"the coefficient matrix ="<<endl;
		cout<<endl;
		cout<< A <<endl;
		cout<<"the right hand side array b of equations"<<endl;
		cout<<endl;
		for(int i=0;i<m;i++){
			cout<<" "<<b[i]<<endl;
		}
		cout<<endl;

		cout<<"the expected solution caculated by online matrix caculator ="<<endl;
		cout<<endl;
		cout<<"x1 =  0.6559"<<endl;
		cout<<"x2 =  0.4002"<<endl;
		cout<<"x3 =  0.1919"<<endl;
		cout<<endl;

		double* AT_B=A.Matrix::lss_ATB(A,b);
		
		SquareMatrix lmatrix(n,n);
		SquareMatrix umatrix(n,n);
		SquareMatrix pmatrix(n,n);

		AT_A.SquareMatrix::lu2(AT_A,lmatrix,umatrix,pmatrix);
		SquareMatrix Pb = SquareMatrix::b_permutation(pmatrix,AT_B,n);	
		//call forwardSubstitution function, return SquareMatrix y		
		SquareMatrix y = AT_A.forwardSubstitution(lmatrix,Pb,n);
		
		//call backSubstitution function to get the solution of linear equations
		AT_A.backSubstitution(umatrix,y,n);
		cout << "Press any key to continue ..." << flush;
		system("read");
		cout << endl;
	}	
	cout << "Case2:when swapping is required" << endl;
	cout<<endl;
	{
		int m=4;
		int n=3;
		double b[4]={3,3,2,1};
		double input[12] = {2, 1, 3, -1, 4, 2, 1, 5, -1, 2, 2, 9};
		Matrix A(4,3);
		A.Matrix::TestingInput(input,4,3);
			
		double* input_ATA=A.Matrix::lss_ATA(A);
	
		SquareMatrix AT_A(3,3);
		AT_A.SquareMatrix::TestingMatrixInput(input_ATA,3,3);
		
		cout<<"the coefficient matrix ="<<endl;
		cout<<endl;
		cout<< A <<endl;
		cout<<"the right hand side array b of equations"<<endl;
		cout<<endl;
		for(int i=0;i<m;i++){
			cout<<" "<<b[i]<<endl;
		}
		cout<<endl;

		cout<<"the expected solution caculated by online matrix caculator ="<<endl;
		cout<<endl;
		cout<<"x1 =  0.6688"<<endl;
		cout<<"x2 =  0.4776"<<endl;
		cout<<"x3 = -0.0493"<<endl;
		cout<<endl;

		double* AT_B=A.Matrix::lss_ATB(A,b);
		
		SquareMatrix lmatrix(n,n);
		SquareMatrix umatrix(n,n);
		SquareMatrix pmatrix(n,n);

		AT_A.SquareMatrix::lu2(AT_A,lmatrix,umatrix,pmatrix);
		SquareMatrix Pb = SquareMatrix::b_permutation(pmatrix,AT_B,n);	
		//call forwardSubstitution function, return SquareMatrix y		
		SquareMatrix y = AT_A.forwardSubstitution(lmatrix,Pb,n);
		
		//call backSubstitution function to get the solution of linear equations
		AT_A.backSubstitution(umatrix,y,n);
		cout << "Press any key to continue ..." << flush;
		system("read");
		cout << endl;
	}	
}
int main () {

	for (;;) {
		cout << "Choose to test one of the following:" << endl;
		cout << "  Enter \'1\' for the ones and eyes function" << endl;
		cout << "  Enter \'2\' for the Toeplitz function" << endl;
		cout << "  Enter \'3\' for the Transpose function" << endl;
		cout << "  Enter \'4\' for the triu funtion" << endl;
		cout << "  Enter \'5\' for the tril funtion" << endl;
		cout << "  Enter \'6\' for the lu functions with the algorithm 2.1" << endl;
		cout << "  Enter \'7\' for the lu functions with the algorithm 2.2" << endl;
		cout << "  Enter \'8\' for the apppication of lu functions when Number of equations = Number of unknowns" << endl;
		cout << "  Enter \'9\' for the apppication of lu functions when Number of equations > Number of unknowns" << endl;
		cout << ">> ";
		cin.clear();
		cin.sync();
		char choice;
		cin >> choice;
		switch (choice) {
			case '1':	onesAndeyesTesting();
						break;
			case '2':	ToeplitzTesting();
						break;
			case '3':	TransposeTesting();
						break;			
			case '4':	triuTesting();
						break;
			case '5':	trilTesting();
						break;
			case '6':	lu1Testing();
						break;
			case '7':	lu2Testing();
						break;
			case '8':	applicationTesting1();
						break;
			case '9':	applicationTesting2();
						break;
		}
		fflush(stdin);
		cout << "Enter \'0\' to exit or \'1\' to choose another test" << endl;
		cout << ">> ";
		cin >> choice;
		if (choice == '0') {
			return 0;
		}
	}

}
