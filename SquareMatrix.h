/*
 * SquareMatrix.h
 *		This class extends the Matrix class to implement specialised features 
 *	and operations appropriate for n-by-n matrices.
 *		The class implement a set of functions that can reproduce the idividual tasks
 *	carried out in the provided MAtlab script.
 *
 *  Created on: University Collage London. 
 *		  Date: 12.2018-01.2019
 *      Author: student number:18043309 
 */

#ifndef _SquareMatrix_H
#define _SquareMatrix_H

#include <iostream>
#include "Matrix.h"


class SquareMatrix:public Matrix{

public:
	//constructor
	SquareMatrix(const int noOfRow, const int noOfCols);
	SquareMatrix(const SquareMatrix& input);
	
	//destructor
	~SquareMatrix(){};
	
	//assignment operator
	using Matrix::operator=;
	
	//creat identity matrix
	SquareMatrix eye(const int dim);
	
	//create toeplitz matrix 
	static SquareMatrix toeplitz(const double* vec1); //use one vector as imput
	static SquareMatrix toeplitz(const double* vec1,const double* vec2);//use two vectors as imput
	
	//create triu function
	SquareMatrix triu(const SquareMatrix& matrix,const int dim);
	//create triu function
	SquareMatrix tril(const SquareMatrix& matrix,const int dim);
	
	//lu function with Algorithm 2.1	
	void lu1(const SquareMatrix& matrix);
	//lu function with Algorithm 2.2	
	void lu2(const SquareMatrix& matrix,SquareMatrix& lmatrix, SquareMatrix& umatrix, SquareMatrix& pmatrix);
	
	//Solve for y for equation Ly=Pb as algorithm 3.1:Forward substitution
	static SquareMatrix forwardSubstitution(const SquareMatrix& lmatrix,const SquareMatrix& b,const int m);
	//solve for x in equation Ux=y as algorithm 3.2:Back substitution
	void backSubstitution(const SquareMatrix& lmatrix,const SquareMatrix& b,const int m);
	//get the Pb for the right hand side of equation LUx=Pb
	static SquareMatrix b_permutation(const SquareMatrix& matrix, const double* b,const int dim);	
	
	//create testing matrix
	SquareMatrix& TestingMatrixInput(const double* input, const int noOfRows,const int noOfColumns);
};

#endif
