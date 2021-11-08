/*

Newton-Raphson method of finding the root. 
Algorithm: 

    1. Evaluate f'(x)
    2. Estimate new root given a guess of said root: xnew = xi - f(xi)/f'(xi)
    3. Find the absolute relative approximate error as ((xnew - xi)/xnew) * 100

Problem: 
    Given 
    f(x) = x^2 - x - 12
    f'(x) = 2x - 1
*/

#include <stdio.h>
#include <math.h>
#define INITIAL_GUESS 8
#define ROOT 4

float evaluateDerivative(float);
float evaluateBase(float);
float evaluateNext(float);
float evaluateError(float);

int main(){
    int iteration = 0;
    float currentRoot = INITIAL_GUESS; 
    while(iteration < 16){
        printf("Current iteration: %i \n", iteration);
        printf("Current root estimate: %f \n", currentRoot);
        currentRoot = evaluateNext(currentRoot);
        printf("Current error: %f \n === \n", evaluateError(currentRoot));
        if(evaluateError(currentRoot) <= 0.00005){
            printf("Current root estimate is within error boundary. Terminating program...");
            break;
        }
        iteration++;
    }
    return 0; 
}

float evaluateDerivative(float x){
    return (2*x - 1);
}

float evaluateBase(float x){
    return (pow(x, 2) - x - 12);
}

float evaluateError(float value){
    float num = fabs(ROOT - value);
    return (num/value)*100;
}

float evaluateNext(float current){
    return (current - (evaluateBase(current) / evaluateDerivative(current)));
}