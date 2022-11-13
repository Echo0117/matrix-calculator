/*
 * Matrix.cpp
 *
 *  Created on: University Collage London. 
 *		  Date: 12.2018-01.2019
 *      Author: student number:18043309  
 */

#include "Matrix.h"
#include <stdio.h>

//determine row-column indexing mapping to 1-D indexing
int Matrix::GetIndex (const int rowIdx, const int columnIdx) const{
	//assuming matrix is mapped onto a 1-D array column-wise
	return columnIdx*noOfRows+rowIdx;
}

//standard constructor
Matrix::Matrix (const int noOfRow, const int noOfCols){
	//assign for member variables in standard constructor
	noOfRows=noOfRow;
	noOfColumns=noOfCols;
	//allocate memory
	data=new double[noOfRows*noOfColumns*2];
	
	//initialise each array entry to 0.0
	for(int i=0;i<noOfRows*noOfColumns;++i){
		data[i]=0.0;
	}
}

//copy constructor
Matrix::Matrix (const Matrix& input){

	//assign for member variables in copy constructor
	noOfColumns=input.noOfColumns;
	noOfRows=input.noOfRows;
	
	//allocate memory
	data=new double[noOfRows*noOfColumns];
	
	//array entry-wise copy
	for(int i=0;i<noOfRows*noOfColumns;++i){
		data[i]=input.data[i];
	}
}

//destructor
Matrix::~Matrix(){
	delete[] data;
}

//static member funtion for assigning values to 0.0 to object matrix
Matrix Matrix::Zeros(const int noOfRows, const int noOfColumns){
	Matrix matrix(noOfRows,noOfColumns);
	
	//set every entry to 0.0 
	for(int i=0;i<noOfRows*noOfColumns;++i){
		matrix.data[i]=0.0;
	}
	return matrix;
}

//static member funtion for assigning values to 1.0 to object matrix
Matrix Matrix::Ones(const int noOfRows, const int noOfColumns){
	Matrix matrix(noOfRows,noOfColumns);
	
	//set every entry to 1.0 
	for(int i=0;i<noOfRows*noOfColumns;++i){
		matrix.data[i]=1.0;
	}
	return matrix;
}

//assignment operator
Matrix& Matrix::operator= (const Matrix& rhs){
	//prevent the same matrix assignment
	if(this==&rhs){
		return *this;
	}
	else{
		noOfRows=rhs.noOfRows;
		noOfColumns=rhs.noOfColumns;
			
	//assign the every value of lhs by the values of rhs
	for(int i=0;i<noOfRows*noOfColumns;i++){
		data[i]=rhs.data[i];
		}
	}
}

//operator overloading to output the matrix
ostream& operator<< (ostream& out, const Matrix& rhs){
	//interating through the rows
	for(int i=0;i<rhs.noOfRows;++i){
	//interating through the columns
		for(int j=0;j<rhs.noOfColumns;++j){
			
			//adjust the space to align the matrix 
			if(rhs.data[rhs.GetIndex(i,j)]<0){
				out<<rhs.data[rhs.GetIndex(i,j)]<<'	';
			}
			else{
				out<<' '<<rhs.data[rhs.GetIndex(i,j)]<<'	';
			}
		}
		out<<endl;	
	}
	return out;
}

//create Toeplitz matrix
Matrix Matrix::Toeplitz(const double* column, const int noOfRows,const double* row,const int noOfColumns){
	Matrix toeplitz(noOfRows,noOfColumns);

	for(int i=0;i<noOfRows;++i){
		for(int j=0;j<noOfColumns;++j){
			//when the number of column is equal or larger than the number of row
			if(i>=j){
				//interating through the index n of the input array
				for(int n=0;n<noOfRows;++n){
					//use the values of the column array to assign for toeplitz matrix
					if(i-j==n){
						toeplitz.data[toeplitz.GetIndex(i,j)]=column[n];
					}
					//use the values of the row array to assign for toeplitz matrix
					else if(j-i==n){
						toeplitz.data[toeplitz.GetIndex(i,j)]=row[n];
					}		
				}
			}
			//when the number of column is smaller than the number of row
		    else{
		    
				 for(int n=0;n<noOfColumns;++n){
					 //use the values of the row array to assign for toeplitz matrix
					if(j-i==n){
						toeplitz.data[toeplitz.GetIndex(i,j)]=row[n];
					}
					//use the values of the column array to assign for toeplitz matrix
					else if(i-j==n){
						toeplitz.data[toeplitz.GetIndex(i,j)]=column[n];
					}
				}
			}
		}
	}
	return toeplitz;
}

//print function for ToeplitzTestingHelper in test file
void Matrix::Print(const double* array, const int noOfRows,const int noOfColumns){
	//print for the first column
	if(noOfColumns==1){
		for(int i=0;i<noOfRows;++i){
			//adjust the space to align the matrix 
			if(array[i]<0){
				cout<<array[i]<<endl;	
			}
			else{
				cout<<' '<<array[i]<<endl;
			}
		}
	}
	//print for the first row
	else if(noOfRows==1){
		
		for(int i=0;i<noOfColumns;++i){
			
				cout<<' '<<array[i]<<' '<<' '<<' ';
		}
		cout<<endl;
	}
	
	//print for the expected matrix
	else{
		for(int i=0;i<noOfRows;++i){
			for(int j=0;j<noOfColumns;++j){
				//adjust the space to align the matrix 
				if(array[i+noOfRows*j]<0){
					
					cout<<array[i+noOfRows*j]<<'	';
				}
				else{
					cout<<' '<<array[i+noOfRows*j]<<'	';
				}
			}
			cout<<endl;
		}			
	}
}

//static transpose function
Matrix Matrix::Transpose(const Matrix& matrix){
	//define a matrix as the retult of transpose matrix of the original matrix
	Matrix trans(matrix.noOfColumns,matrix.noOfRows);
	
	for(int i=0;i<matrix.noOfColumns;++i){
		for(int j=0;j<matrix.noOfRows;++j){
			//assign the trans matrix by the original matrix with the index i and j switched
			trans.data[trans.GetIndex(i,j)]=matrix.data[matrix.GetIndex(j,i)];
		}
	}
	return trans;
}

//non-static transpose function
Matrix& Matrix::Transpose(){

	//define a matrix, using the noOfColumns of original matrix as the number of rows 
	//and the noOfRows of original matrix asthe number of columns
	Matrix trans((*this).noOfColumns,(*this).noOfRows);
		for(int i=0;i<(*this).noOfColumns;++i){
			for(int j=0;j<(*this).noOfRows;++j){
				//assign the trans matrix by the original matrix with the index i and j switched
				trans.data[trans.GetIndex(i,j)]=data[GetIndex(j,i)];
			}
		}
		
		//assign the original matrix as the new matrix
		*this=trans;
		
	return *this;
}

// a non-member function but a friend for "*" operator overloading 
Matrix operator * (const Matrix& lhs,const Matrix rhs){

	//create a matrix as the product of lhs and rhs
	Matrix result(lhs.noOfRows,rhs.noOfColumns);
		for(int i=0;i<result.noOfRows;i++){
			for(int j=0;j<result.noOfColumns;j++){
				for(int k=0;k<lhs.noOfColumns;k++){
					//use the regulation of matrix multiplication
					result.data[result.GetIndex(i,j)]+=lhs.data[lhs.GetIndex(i,k)]*rhs.data[rhs.GetIndex(k,j)];
				}
			}
		}
	return result;
}

//a member function of multiplication assignment operator
Matrix& Matrix::operator*= (const Matrix& rhs){
	//create a matrix as the product of lhs (*this point the matrix which call the function in test file ) and rhs 
	Matrix result=(*this)*rhs;
	
	//assgin the lhs matrix as the product result.
	(*this)=result;
	
	return *this;
}

//exchange the whole rows
Matrix Matrix::ExchangeRows(int row1,int row2){
	//create a matrix which is equal to the original matrix
	Matrix exchangeRow(noOfRows,noOfColumns);
	exchangeRow=(*this);

		//loop through all the values of the matrix to exchange two rows
		for(int i=0;i<noOfRows;i++){
			for(int j=0;j<noOfColumns;j++){
				//exchange two rows
				exchangeRow.data[exchangeRow.GetIndex(row1,j)]=(*this).data[(*this).GetIndex(row2,j)];
				exchangeRow.data[exchangeRow.GetIndex(row2,j)]=(*this).data[(*this).GetIndex(row1,j)];
			}
		}
	
	return exchangeRow;
}

//exchange partial values of the rows
Matrix Matrix::ExchangeRows(int row1,int row2,int column1,int column2){
	//create a matrix, which is equal to the matrix that has already exchanged 2nd and 4th rows
	Matrix exchangeRow(noOfRows,noOfColumns);
	exchangeRow=(*this).ExchangeRows(1, 3);

		for(int i=0;i<noOfRows;++i){
			for(int j=0;j<noOfColumns;++j){	
				//exchange rows but only for the specified columns
				for(int n=column1;n<=column2;++n){
					exchangeRow.data[exchangeRow.GetIndex(row2,n)]=((*this).ExchangeRows(1, 3)).data[((*this).ExchangeRows(1, 3)).GetIndex(row1,n)];	
					exchangeRow.data[exchangeRow.GetIndex(row1,n)]=((*this).ExchangeRows(1, 3)).data[((*this).ExchangeRows(1, 3)).GetIndex(row2,n)];
				}
			}
		}
	
	return exchangeRow;
}

//exchange the whole columns
Matrix Matrix::ExchangeColumns(int column1,int column2){
	//create a matrix which is equal to the original matrix
	Matrix exchangeColumn(noOfRows,noOfColumns);
	exchangeColumn=(*this);
	
		//loop through all the values of the matrix to exchange two columns
		for(int i=0;i<noOfRows;i++){
			for(int j=0;j<noOfColumns;j++){
				//exchange two columns
				exchangeColumn.data[exchangeColumn.GetIndex(i,column1)]=(*this).data[(*this).GetIndex(i,column2)];
				exchangeColumn.data[exchangeColumn.GetIndex(i,column2)]=(*this).data[(*this).GetIndex(i,column1)];
			}
		}
	
	return exchangeColumn;
}

//exchange partial values of the columns
Matrix Matrix::ExchangeColumns(int column1,int column2,int row1,int row2){
	//create a matrix, which is equal to the matrix that has already exchanged 1st and 2nd column
	Matrix exchangeColumn(noOfRows,noOfColumns);
	exchangeColumn=(*this).ExchangeColumns(0, 1);
	
		for(int i=0;i<noOfRows;++i){
			for(int j=0;j<noOfColumns;++j){	
				//exchange columns but only for the specified rows
				for(int n=row1;n<=row2;++n){
					exchangeColumn.data[exchangeColumn.GetIndex(n,column2)]=((*this).ExchangeColumns(0, 1)).data[((*this).ExchangeColumns(0, 1)).GetIndex(n,column1)];	
					exchangeColumn.data[exchangeColumn.GetIndex(n,column1)]=((*this).ExchangeColumns(0, 1)).data[((*this).ExchangeColumns(0, 1)).GetIndex(n,column2)];
			}
		}
	}
	return exchangeColumn;
}

//The function that sets every entry to zero
Matrix& Matrix::Zeros(){

		for(int i=0;i<(*this).noOfRows;++i){
			for(int j=0;j<(*this).noOfColumns;++j){
				data[GetIndex(i,j)]=0.0;
			}
		}		
	return *this;
}

//The function that sets every entry to one
Matrix& Matrix::Ones(){

		for(int i=0;i<(*this).noOfRows;++i){
			for(int j=0;j<(*this).noOfColumns;++j){
				data[GetIndex(i,j)]=1.0;
			}
		}		
	return *this;
}

//The function for getting the number of rows
int Matrix::GetNoOfRows()const{
	return this->noOfRows;
}

//The function for getting the number of columns
int Matrix::GetNoOfColumns()const{
	return this->noOfColumns;
}

//The function for getting the entries
int Matrix::GetEntry(int row,int column)const{

	return data[GetIndex(row,column)];
}

//get the product of AT*A for least square solution
double* Matrix::lss_ATA(const Matrix& A){

	//get the transpose matrix of A
	Matrix AT=Transpose(A);
	//intialise the product of A and the transpose matrix of A
	Matrix At_A(A.noOfColumns,A.noOfColumns);
	
	//get the product of A and the transpose matrix of A 
	At_A = AT*A;
	
	static double AT_A[9];
	
	for(int i=0;i<A.noOfRows*A.noOfColumns;i++){
		AT_A[i]=At_A.data[i];
	}
	
	return AT_A;
}

//get the product of AT*b for least square solution
double* Matrix::lss_ATB(const Matrix& A,const double* b){

	//get the transpose matrix of A
	Matrix AT=Transpose(A);

	//initialise B as Matrix class in order to multiply with AT
	Matrix B(noOfRows,1);
	for(int i=0;i<noOfRows;i++){
		B.data[i]=b[i];
	}
	
	//intialise the product of B and the transpose matrix of A
	Matrix At_B(A.noOfColumns,1);
	//get the product of A and the transpose matrix of A 
	At_B = AT*B;
	
	static double AT_B[3];
	
	for(int i=0;i<A.noOfColumns;i++){
		AT_B[i]=At_B.data[i];
	}
	
	return AT_B;
}

Matrix& Matrix::TestingInput(const double* input, const int noOfRows,const int noOfColumns){

	//initialise matrix as the type of SquareMatrix	
	Matrix matrix (noOfRows,noOfColumns);	
	
	//assign entries of matrix by input array
	for(int i =0;i<noOfRows*noOfColumns;i++){		
		matrix.data[i]=input[i];
	}		
	//assign the value of the object by matrix
	*this = matrix;
		
	return *this;
}



