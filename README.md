# Machine-Learning-Basic-Perceptron
Building a basic perceptron from Machine Learning Assignment 3

#The Task
The perceptron is a fundamental building block of a neural network. So let's play with it before moving on to multiple layer neural networks.

Build a perceptron network in C/C++ (single layer as we saw in class). It should solve a problem that consists of n inputs and m outputs. Your program will be called nn. You may use the following code but all the rest needs to be written by you (do not copy code!!): mat.tar, mat.zip These are matrix and random number routines discussed in class. A sample test program is in mat.cpp and can be uncommented.

the training
Your program will read in training data from standard input. You should then scale your input to be between 0 and 1. Your program can then train as much as you believe is needed and then print the W matrix. It will then read in test data. For this assignment use all the training data and then use the test data. Do not train on the test data. We will deal with cross validation later. The input file looks like:

\#inputs
\#rows #cols
row1
row2
 ...
lastrow
\#rows #cols
row1
row2
 ...
lastrow
The training and test data each look like a matrix specification. First number is the number of features or inputs. All elements in a row after the first #inputs elements are the expected outputs in the training data. The #rows in the training matrix is greater than #inputs. The #rows in the second matrix is the same as #inputs. Your program will read in the training data and then train. Your network is a single layer perceptron network with a transfer function g(x) that is 1 if x>.5 and 0 otherwise. Then it will read in the test data and use the trained network on the test data to derive the correct outputs.
This is some example input will test the two input logical or:

2
4 3
0 0 0
0 1 1
1 0 1
1 1 1
4 2
0 0
0 1
1 0
1 1
(The test data testDataA3.tar shows more examples of the input format.)
Then for each test case it will print out on one line the unscaled input test case followed output using your learned W matrix. There are some single line printing routines in the matrix library that you might find helpful.

You may use my random number generator and matrix objects or write your own. If you do, then be sure to include the matrix library and any other code you need to build in your tar file! Do not use any other prepackaged software.

Your code must compile and run on the test machine (a Linux machine). If it does not compile or fails to run (e.g. gets seg faults) or in other ways produces no output that is a very serious fault and will result in a very poor score. In 4xx/5xx CS classes your code should at least run and produce reasonable output.

Grading will be based on matching my output. Since these programs are stochastic I will look that the format of your output matches and the values seem reasonable. Test suite will do a side by side comparison using the UNIX sdiff tool. See information on the class page about testing.
