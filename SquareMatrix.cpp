/*
 * SquareMatrix.cpp
 *
 *  Created on: University Collage London. 
 *		  Date: 12.2018-01.2019
 *      Author: student number:18043309 
 */


#include "SquareMatrix.h"
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>  
#include <math.h>

//standard constructor
SquareMatrix::SquareMatrix(const int noOfRow, const int noOfCols):Matrix (noOfRow, noOfCols){
}

//copy constructor
SquareMatrix::SquareMatrix(const SquareMatrix& input):Matrix(input){
}

//creat identity matrix
SquareMatrix SquareMatrix::eye(const int dim){

	SquareMatrix matrix(dim,dim);
	//set the diagonal values to 1.0
	for(int i=0;i<dim*dim;++i){
		matrix.data[GetIndex(i,i)]=1.0;
	}
	return matrix;
}

//create toeplitz matrix using one vector as input
SquareMatrix SquareMatrix::toeplitz(const double* vec1){

	SquareMatrix toeplitz(4,4);

	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			//interating through the index n of the input array
			for(int n=0;n<4;++n){
				if(i-j==n||j-i==n){
					//use the values of the vec1 array to assign for toeplitz matrix
					toeplitz.data[toeplitz.GetIndex(i,j)]=vec1[n];
				}			
			}
		}
	}
	return toeplitz;
}
//create toeplitz matrix using two vectors as input
SquareMatrix SquareMatrix::toeplitz(const double* vec1,const double* vec2){

	SquareMatrix toeplitz(4,4);

	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			//interating through the index n of the input array
			for(int n=0;n<4;++n){
				if(i-j==n){
				    //use the values of the vec1 array to assign for toeplitz matrix
					toeplitz.data[toeplitz.GetIndex(i,j)]=vec1[n];
				}	
				else if(j-i==n){
					//use the values of the vec2 array to assign for toeplitz matrix
					toeplitz.data[toeplitz.GetIndex(i,j)]=vec2[n];
				}		
			}
		}
	}
	return toeplitz;
}

//create triu function
SquareMatrix SquareMatrix::triu(const SquareMatrix& matrix,const int dim){

	SquareMatrix triu(dim,dim);
	
	for(int i=0;i<dim;++i){
		for(int j=0;j<dim;++j){
			//assign entries for upper triangular part
			if(i<=j){
			triu.data[GetIndex(i,j)]=matrix.data[matrix.GetIndex(i,j)];
			}
			//set 0 to lower triangular part
			else{
			triu.data[GetIndex(i,j)]=0.0;
			}
		}
	}
	return triu;
}

//create tril function
SquareMatrix SquareMatrix::tril(const SquareMatrix& matrix,const int dim){

	SquareMatrix tril(dim,dim);
	
	for(int i=0;i<dim;++i){
		for(int j=0;j<dim;++j){
		//set 0 to upper triangular part
			if(i<j){
			tril.data[GetIndex(i,j)]=0.0;
			}
			//assign entries for lowver triangular part
			else{
			tril.data[GetIndex(i,j)]=matrix.data[matrix.GetIndex(i,j)];
			}
		}
	}
	return tril;
}

//lu function with Algorithm 2.1	
void SquareMatrix::lu1(const SquareMatrix& matrix){
	//set precision
	cout.precision(4);
	//make cout print floats with a fixed number of decimals
	cout.setf(ios::fixed);
	
	 int det=0, p, h, k, i, j, temp[4][4];
  
	//initialise umatrix1 with the input matrix
	SquareMatrix umatrix1(matrix.noOfRows,matrix.noOfColumns);
	
	for(int i=0;i<matrix.noOfRows;++i){
		for(int j=0;j<noOfColumns;++j){
			umatrix1.data[GetIndex(i,j)]=matrix.data[matrix.GetIndex(i,j)];
			
		}
	}
	//initialise lmatrix1 with identity matrix	
	SquareMatrix lmatrix1(matrix.noOfRows,matrix.noOfColumns);
	
	for(int i=0;i<matrix.noOfRows;++i){
		for(int j=0;j<matrix.noOfColumns;++j){
			lmatrix1.data[GetIndex(i,i)]=1.0;		
		}
	}
	//initialize the value of m as the row of the input matrix
	int m=matrix.noOfRows;
	
	for (int i = 0; i < m; i++)
		//determine whether this algorithm can be used
        if (umatrix1.data[GetIndex(i,i)]==0)
        {
            cout << "can't use this meathod,because some of the pivots are equal to zero" << endl;
            cout<<endl;
            return;
        }

	//loop to perform the gaussian elimination
	for(int k=0;k<m-1;++k){
		for (int j=k+1;j<m;++j){
			//get the values of lower matrix
			lmatrix1.data[lmatrix1.GetIndex(j,k)]=(umatrix1.data[umatrix1.GetIndex(j,k)]) / (umatrix1.data[umatrix1.GetIndex(k,k)]);
		
			for(int n=k;n<m;++n){
				//get the values of upper matrix	
				umatrix1.data[umatrix1.GetIndex(j,n)]=umatrix1.data[umatrix1.GetIndex(j,n)]-lmatrix1.data[lmatrix1.GetIndex(j,k)]*umatrix1.data[umatrix1.GetIndex(k,n)];
				
			}
		}
	}
	//check if input matrix is singular matrix
	for(int i=0;i<matrix.noOfRows;i++){
		for(int j=i;j<matrix.noOfColumns;j++){
			if (i>=j){
				//check if any entry of upper triangular matrix is equal to 0 or NAN
				if(umatrix1.data[umatrix1.GetIndex(i,j)]==0||umatrix1.data[umatrix1.GetIndex(i,j)]==NAN){
					cout<<"please enter non-singular matrix"<<endl;
					cout<<endl;
					return;
				}
				else{
					break;
				}
			}
			else{
				break;
			}
		}
	}
	for(int i=0;i<matrix.noOfRows;i++){
		for(int j=0;j<=i;j++){
			//check if any entry of lower triangular matrix is equal to 0 or NAN
			if(lmatrix1.data[lmatrix1.GetIndex(i,j)]==0||lmatrix1.data[lmatrix1.GetIndex(i,j)]==NAN){
				cout<<"please enter non-singular matrix"<<endl;
				cout<<endl;
				return;
			}
			else{				
					break;
			}	
		}
	}
	
	//print the lmatrix1 and umatrix1
	cout<<"lmatrix1 = "<<endl;
	cout<<lmatrix1<<endl;
	cout<<"umatrix1 = "<<endl;
	cout<<umatrix1<<endl;
	
}
	
//lu function with Algorithm 2.2	
void SquareMatrix::lu2(const SquareMatrix& matrix,SquareMatrix& lmatrix, SquareMatrix& umatrix, SquareMatrix& pmatrix){

	//set precision
	cout.precision(4);
	//make cout print floats with a fixed number of decimals
	cout.setf(ios::fixed);
	
	int m=matrix.noOfRows;
	int i,j,k,n;
	
	//initialise lmatrix1 with the input matrix	
	SquareMatrix umatrix1(matrix.noOfRows,matrix.noOfColumns);
	
	for(i=0;i<matrix.noOfRows;++i){
		for(j=0;j<noOfColumns;++j){
			umatrix1.data[GetIndex(i,j)]=matrix.data[matrix.GetIndex(i,j)];
			
		}
	}
	//initialise lmatrix1 with identity matrix		
	SquareMatrix lmatrix1(matrix.noOfRows,matrix.noOfColumns);
	
	for(i=0;i<matrix.noOfRows;++i){
		for(j=0;j<matrix.noOfColumns;++j){
			lmatrix1.data[GetIndex(i,i)]=1.0;		
		}
	}
	//initialise pmatrix1 with identity matrix		
	SquareMatrix pmatrix1(matrix.noOfRows,matrix.noOfColumns);
	
	for(i=0;i<matrix.noOfRows;++i){
		for(j=0;j<matrix.noOfColumns;++j){
			pmatrix1.data[GetIndex(i,i)]=1.0;		
		}
	}

	for(k=0;k<m-1;++k){
	
		for(j=k+1;j<m;j++){
		
			//determines the entry with the largest absolute value
			if(abs(umatrix1.data[umatrix1.GetIndex(k,k)])<abs(umatrix1.data[umatrix1.GetIndex(j,k)])){
			
				//swap the row containing the diagonals of the column with the row containing the new pivot.
				for(n=k;n<m;n++){
					double tmp1= umatrix1.data[umatrix1.GetIndex(k,n)];
					umatrix1.data[umatrix1.GetIndex(k,n)]=umatrix1.data[umatrix1.GetIndex(j,n)];
					umatrix1.data[umatrix1.GetIndex(j,n)]=tmp1;
				}
				for(n=0;n<k;n++){
					double tmp2= lmatrix1.data[lmatrix1.GetIndex(k,n)];
					lmatrix1.data[lmatrix1.GetIndex(k,n)]=lmatrix1.data[lmatrix1.GetIndex(j,n)];
					lmatrix1.data[lmatrix1.GetIndex(j,n)]=tmp2;
				}
				//permutation matrix records this swapping of rows
				for(n=0;n<m;n++){
					double tmp3= pmatrix1.data[umatrix1.GetIndex(k,n)];
					pmatrix1.data[pmatrix1.GetIndex(k,n)]=pmatrix1.data[pmatrix1.GetIndex(j,n)];
					pmatrix1.data[pmatrix1.GetIndex(j,n)]=tmp3;
				}
			}
		}
		//loop to implement the gaussian elimination
		for (int j=k+1;j<m;++j){
			//get the values of lower matrix
			lmatrix1.data[lmatrix1.GetIndex(j,k)]=(umatrix1.data[umatrix1.GetIndex(j,k)]) / (umatrix1.data[umatrix1.GetIndex(k,k)]);
			
			for(int n=k;n<m;++n){
				//get the values of upper matrix
				umatrix1.data[umatrix1.GetIndex(j,n)]=umatrix1.data[umatrix1.GetIndex(j,n)]-lmatrix1.data[lmatrix1.GetIndex(j,k)]*umatrix1.data[umatrix1.GetIndex(k,n)];
				
			}
		}
	
	}
	//assign matrices in order to use in the test file
	lmatrix=lmatrix1;
	umatrix=umatrix1;
	pmatrix=pmatrix1;

}

//create testing matrix
SquareMatrix& SquareMatrix::TestingMatrixInput(const double* input, const int noOfRows,const int noOfColumns){

	//initialise matrix as the type of SquareMatrix	
	SquareMatrix matrix (noOfRows,noOfColumns);	
	
	//assign entries of matrix by input array
	for(int i =0;i<noOfRows*noOfColumns;i++){		
		matrix.data[i]=*(input+i);
	}		
	//assign the value of the object by matrix
	*this = matrix;
		
	return *this;
}

//Solve for y for equation Ly=Pb as algorithm 3.1:Forward substitution
SquareMatrix SquareMatrix::forwardSubstitution(const SquareMatrix& lmatrix,const SquareMatrix& b,const int m){	
	//initialise y as the type of SquareMatrix 
	SquareMatrix y(m,1);
	y.data[y.GetIndex(0,0)]=b.data[y.GetIndex(0,0)]/lmatrix.data[0];
	for(int k=1;k<m;k++){
		//initialise sum to store the sum of partial iteration
		double sum=0;
		for(int j=0;j<=k-1;j++){
			sum += lmatrix.data[lmatrix.GetIndex(k,j)]*y.data[y.GetIndex(j,0)];
			y.data[y.GetIndex(k,0)]=(b.data[y.GetIndex(k,0)]-sum) / lmatrix.data[lmatrix.GetIndex(k,k)];
		}
	}
	
	return y;
}

//solve for x in equation Ux=y as algorithm 3.2:Back substitution
void SquareMatrix::backSubstitution(const SquareMatrix& umatrix,const SquareMatrix& b,const int m){	
	
	//set precision
	cout.precision(4);
	//make cout print floats with a fixed number of decimals
	cout.setf(ios::fixed);
	//define the dynamic array to store the solutions x
	double* x=new double[m];
	
	x[m-1]=b.data[b.GetIndex(m-1,0)]/umatrix.data[umatrix.GetIndex(m-1,m-1)];
	for(int k=m-2;k>=0;k--){
		//initialise sum to store the sum of partial iteration
		double sum=0;
		for(int j=k+1;j<m;j++){
			sum += umatrix.data[umatrix.GetIndex(k,j)]*x[j];
			x[k]=(b.data[b.GetIndex(k,0)]-sum) / umatrix.data[umatrix.GetIndex(k,k)];
			
		}
	}
	
	//print the solution 
	cout<<"the solution of this program for linear equtions = "<<endl;
	cout<<endl;
	for(int i=0;i<m;i++){
		
		if(x[i]>=0){
			cout<<"x"<<i+1<<" = "<<' '<<x[i]<<endl;
		}
		else{
			cout<<"x"<<i+1<<" = "<<x[i]<<endl;
		}
	}
	delete[] x;
}	
	
//get the Pb for the right hand side of equation LUx=Pb
SquareMatrix SquareMatrix::b_permutation(const SquareMatrix& matrix,const double* b,const int dim){	

	SquareMatrix P(matrix.noOfRows,matrix.noOfColumns);
	//initialise matrix_b as the type of SquareMatrix 
	SquareMatrix matrix_b(dim,1);
	
	//assign entries of matrix_b by input array b
	for(int i=0;i<dim;i++){
		matrix_b.data[(matrix_b.GetIndex(i,0))]=b[i];
	}
	
	P = matrix;
	//assign the value of P as the product of P*b
	P *= matrix_b; 
	
	return P;
}


