/*
 * Matrix.h
 *	The Matrix class provides the support for arbitrarily sized 2-D matrices.
 *	The class implement a set of functions according to the provided test file.
 *
 *  Created on: University Collage London. 
 *		  Date: 12.2018-01.2019
 *      Author: student number:18043309 
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>

using namespace std;

class Matrix {
protected:
	// These are the only member variables allowed!
	int noOfRows;
	int noOfColumns;
	double *data;
	
	//determine row-column indexing mapping to 1-D indexing
	int GetIndex (const int rowIdx, const int columnIdx) const;

public:
	//constructors
	Matrix (const int noOfRow, const int noOfCols);//standard constructor
	Matrix (const Matrix& input);//copy constructor	
	
	//destructor
	virtual ~Matrix ();
	
	//static member funtion for named constructors
	static Matrix Zeros(const int noOfRows, const int noOfColumns);
	static Matrix Ones(const int noOfRows, const int noOfColumns);
	
	//assignment operator
	Matrix& operator= (const Matrix& rhs);
	//a member function of multiplication assignment operator
	Matrix& operator*= (const Matrix& rhs);
	
	// a non-member function but a friend for "*" operator overloading 
	friend Matrix operator * (const Matrix& lhs,const Matrix rhs);
	
	//operator overloading to output the matrix
	friend ostream& operator<< (ostream& out, const Matrix& matrix);
		

	
	//create Toeplitz matrix
	static Matrix Toeplitz(const double* column, const int noOfRows,const double* row,const int noOfColumns);
	//print function
	static void Print(const double* column, const int noOfRows,const int noOfColumns);
		
	//static matrix transpose
	static Matrix Transpose(const Matrix& matrix);
	//non-static matrix transpose
	virtual Matrix& Transpose();

	//exchange rows or columns of matrices
	Matrix ExchangeRows(int row1,int row2);//exchange the whole rows
	Matrix ExchangeRows(int row1,int row2,int column1,int column2);//exchange partial values of the rows
	Matrix ExchangeColumns(int column1,int column2);//exchange the whole columns
	Matrix ExchangeColumns(int column1,int column2,int row1,int row2);//exchange partial values of the columns
	
	//accessors
	int GetEntry(int row,int column)const;//get the entries
	int GetNoOfRows()const;//get the number of rows
	int GetNoOfColumns()const;//get the number of columns
	
	//The function that sets every entry to zero
	Matrix& Zeros();
	//The function that sets every entry to one
	Matrix& Ones();
	
	//get the product of AT*A for least square solution
	double* lss_ATA(const Matrix& A);
	//get the product of AT*b for least square solution
	double* lss_ATB(const Matrix& A,const double* b);
	Matrix& TestingInput(const double* input, const int noOfRows,const int noOfColumns);
};

#endif /* MATRIX_H_ */
