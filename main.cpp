/*
*Dylan Carlson 2018
*Machine Learning
*Assignment 3
*/

#include <iostream>
#include <string>
#include "mat.h"


using namespace std;

void setTargetValues(Matrix*, Matrix); //Function grabs the target values from the training matrix and assigns them to the target matrix
void setBasics(int*, int*, int*); //Function reads in total inputs, rows and column for the matrix from stdin
void setValuesf(Matrix*); //Function sets the elements of the matrix from stdin
void printMatrix(Matrix); //Prints the contents matrix

int main(){

  //////////INPUT OF TRAINING AND TESTING MATRIX///////
  int train_inputs, train_rows, train_cols, test_rows, test_cols;
  int target_rows, target_cols;
  Matrix train, test, target;

  ///Training Matrix
  setBasics(&train_inputs, &train_rows, &train_cols);
  train = new Matrix(train_rows, train_cols, "train");
  setValuesf(&train);

  ///Testing Matrix
  setBasics(NULL, &test_rows, &test_cols);
  test = new Matrix(test_rows, test_cols, "test");
  setValuesf(&test);

  ///Target Matrix
  target_cols = train_cols - test_cols;
  target_rows = train_rows;

  target = new Matrix(target_rows, target_cols, "target");

  setTargetValues(&target, train);

  ///Resize Training Matrix
  train.narrow(train_cols - target_cols);
  train_cols = train.numCols();



  //////////////////////////////////////////





}

/*
*Function grabs the target values from the training matrix and assigns them to the target matrix
*/
void setTargetValues(Matrix *target, Matrix training){
  int starting_col;

  starting_col = training.numCols() - target->numCols();

  for(int r = 0; r < target->numRows(); r++){
    for(int c = starting_col; c - starting_col < target->numCols(); c++){
      target->set(r,c - starting_col, training.get(r,c));
    }
  }


}

/*
*Function reads in total inputs, rows and column for the matrix from stdin
*/
void setBasics(int *input, int *rows, int *cols){

  if(input != NULL){ //input not recieved for the testing matrix
    cin >> *input;
  }

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
