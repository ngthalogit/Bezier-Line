/* Bezier Deg(3) */ 
/* File Header */ 
 
#include <iostream>
#include <vector>
using namespace std;
#define N 3 
 
/* u = [a,b] */
 
#define a 0
#define b 1

vector<float> B[N];

double PowerFunc(double, int);
int Factorial(int);

double Function_B_u(int, float);
double Function_C_u(float, int);

void inPutByIos();
void outPutByIos();

void inPutFile();
void outPutFile();