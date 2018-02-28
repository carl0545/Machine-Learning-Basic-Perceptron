/*
*Dylan Carlson 2018
*Machine Learning
*Assignment 3
*/

#include <iostream>
#include <string>
#include "mat.h"



using namespace std; //Function reads in total inputs, rows and column for the matrix from stdin

void setBasics(int*, int*, int*);
void setValuesf(Matrix*);

int main(){
  int u_inputs, u_rows, u_cols;
  Matrix train;

  setBasics(&u_inputs, &u_rows, &u_cols);

  train = new Matrix(u_rows, u_cols, "train");

  








}

/*
*Function reads in total inputs, rows and column for the matrix from stdin
*/
void setBasics(int *input, int *rows, int *cols){
  cin >> *input;
  cin >> *rows;
  cin >> *cols;
}

void setValuesf(Matrix *m){


}
