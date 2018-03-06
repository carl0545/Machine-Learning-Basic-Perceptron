/*
*Dylan Carlson 2018
*Machine Learning
*Assignment 3
*/

#include <iostream>
#include <string>
#include "mat.h"



using namespace std;

const double LEARNING_RATE = .25;
const int TRAINING_ITERATIONS = 100;

void setTargetValues(Matrix*, Matrix); //Function grabs the target values from the training matrix and assigns them to the target matrix
void setBasics(int*, int*, int*); //Function reads in total inputs, rows and column for the matrix from stdin
void setValuesf(Matrix*, bool); //Function sets the elements of the matrix from stdin
void printMatrix(Matrix); //Prints the contents matrix
void perceptronAlg(Matrix, Matrix); //Main perceptron algorithm
void setWeights(Matrix*);//Sets the random weight values at the beginning
double threshold(double val); //calculates whether to fire or not fire



int main(){

  //////
  initRand();

  //////////INPUT OF TRAINING AND TESTING MATRIX///////
  int train_inputs, train_rows, train_cols, test_rows, test_cols;
  int target_rows, target_cols;
  Matrix train, test, target;

  ///Training Matrix
  setBasics(&train_inputs, &train_rows, &train_cols);
  train_cols++; //bias column
  train = new Matrix(train_rows, train_cols, "train");
  setValuesf(&train, true);

  ///Testing Matrix
  setBasics(NULL, &test_rows, &test_cols);
  test = new Matrix(test_rows, test_cols, "test");
  setValuesf(&test, false);

  ///Target Matrix
  target_cols = train_cols - test_cols - 1;
  target_rows = train_rows;

  target = new Matrix(target_rows, target_cols, "target");

  setTargetValues(&target, train);

  ///Resize Training Matrix
  train.narrow(train_cols - target_cols);
  train_cols = train.numCols();



  //////////////////////////////////////////
  perceptronAlg(train, target);


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

void setWeights(Matrix *weights){

  weights->rand(-.02,.05);

}

void perceptronAlg(Matrix train, Matrix target){
  int neurons;
  Matrix *weights, activations, values, fin;

  neurons = target.numCols();
  weights = new Matrix(train.numCols(), neurons);
  weights->constant(0);

  setWeights(weights);



  for(int i = 0; i < TRAINING_ITERATIONS; i++){

    activations = train.dot(weights);

    activations.map(threshold);

    fin = new Matrix(activations);

    weights->sub((Matrix(train.Tdot(activations.sub(target)))).scalarMult(LEARNING_RATE));

  }

  cout << "final: " << endl;
  fin.print();




}


double threshold(double val){

  if(val <= 0){
    return 0;
  }
  else{
    return 1.0;
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
void setValuesf(Matrix *m, bool bias){

  if(bias){
    for(int r = 0; r < m->numRows(); r++){
      for(int c = 0; c < m->numCols(); c++){
        if(c == 0){
          m->set(r,c,-1);
          continue;
        }
        int element;
        cin >> element;
        m->set(r,c, element);
      }
    }

  }

  else{

    for(int r = 0; r < m->numRows(); r++){
      for(int c = 0; c < m->numCols(); c++){
        int element;
        cin >> element;
        m->set(r,c, element);
      }
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
