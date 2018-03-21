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
void perceptronAlg(Matrix, Matrix, Matrix); //Main perceptron algorithm
void setWeights(Matrix*);//Sets the random weight values at the beginning
double threshold(double val); //calculates whether to fire or not fire
void printOutput(Matrix, Matrix);


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
  test_cols++;
  test = new Matrix(test_rows, test_cols, "test");
  setValuesf(&test, true);


  ///Target Matrix
  target_cols = train_cols - test_cols;
  target_rows = train_rows;

  target = new Matrix(target_rows, target_cols, "target");

  setTargetValues(&target, train);

  ///Resize Training Matrix
  train.narrow(train_cols - target_cols);
  train_cols = train.numCols();


  //Normalize the training matrix to have input values between 0-1
  train.normalizeCols();



  //////Call the perceptron training algorithm
  perceptronAlg(train, target, test);


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
*Assigns random numbers to the initial weight matrix
*/
void setWeights(Matrix *weights){

  weights->rand(-.02,.05);

}

/*
*Perceptron algorithm that trains the 'train' matrix with the
*'target' matrix as it's expected outputs then utlizes the new
* weight matrix on the test matrix
*/
void perceptronAlg(Matrix train, Matrix target, Matrix test){
  int neurons;
  Matrix *weights, activations, values, fin;

  neurons = target.numCols();
  weights = new Matrix(train.numCols(), neurons);
  weights->constant(0);

  setWeights(weights);


  //Training loop
  for(int i = 0; i < TRAINING_ITERATIONS; i++){

    activations = train.dot(weights);

    activations.map(threshold);

    fin = new Matrix(activations);

    weights->sub((Matrix(train.Tdot(activations.sub(target)))).scalarMult(LEARNING_RATE));

  }

  Matrix newTest = new Matrix(test);

  test.normalizeCols();

  activations = test.dot(weights);

  activations.map(threshold);

  fin = new Matrix(activations);


  printOutput(newTest, fin);


}
/*
*Self made print function to match the neccesary required output template
*for the assignment
*/
void printOutput(Matrix train, Matrix fin){

 for(int r = 0; r < train.numRows(); r++){
   for(int c = 0; c < train.numCols(); c++){
     if(c == 0) continue;
     printf ("%.2f", train.get(r,c));
     cout << " ";
   }
   for(int c = 0; c < fin.numCols(); c++){
     printf ("%.2f", fin.get(r,c));
     cout << " ";
   }
   cout << endl;
 }

}

/*
*Threshold function utlilized within the perceptronAlg function
* Returns 1 if above zero, or returns 0 if not
*/
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
          m->set(r,c,-1.0);
          continue;
        }
        double element;
        cin >> element;
        m->set(r,c, element);
      }
    }

  }

  else{

    for(int r = 0; r < m->numRows(); r++){
      for(int c = 0; c < m->numCols(); c++){
        double element;
        cin >> element;
        m->set(r,c, element);
      }
    }
  }


}

/*
*Prints the contents of the matrix, Used for debugging
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
