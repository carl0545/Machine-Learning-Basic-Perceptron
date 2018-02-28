/*
*Dylan Carlson 2018
*Machine Learning
*Assignment 3
*/

#include <iostream>
#include <string>
#include "mat.h"



using namespace std;

void setBasics(int*, int*, int*); //Function reads in total inputs, rows and column for the matrix from stdin
void setValuesf(Matrix*); //Function sets the elements of the matrix from stdin
void printMatrix(Matrix); //Prints the contents matrix

int main(){
  int u_inputs, u_rows, u_cols;
  Matrix train;

  setBasics(&u_inputs, &u_rows, &u_cols);

  train = new Matrix(u_rows, u_cols, "train");

  setValuesf(&train);


}

/*
*Function reads in total inputs, rows and column for the matrix from stdin
*/
void setBasics(int *input, int *rows, int *cols){
  cin >> *input;
  cin >> *rows;
  cin >> *cols;
}

/*
*Function sets the elements of the matrix from stdin
*/
void setValuesf(Matrix *m){

  for(int r = 0; r < m->numRows(); r++){
    for(int c = 0; c < m->numCols(); c++){
      int element;
      cin >> element;
      m->set(r,c, element);
    }
  }


}

/*
*Prints the contents matrix
*/
void printMatrix(Matrix m){
  int rows = m.numRows();
  int cols = m.numCols();

  for(int r = 0; r < rows; r++){
    for(int c = 0; c < cols; c++){
      cout << m.get(r,c) << " ";
    }
    cout << endl;
  }

}
