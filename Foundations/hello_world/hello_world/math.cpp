//
//  math.cpp
//  hello_world
//
//  Created by Anuj Dutt on 11/26/20.
//

#include "math.hpp"
#include <iostream>

using namespace std;

/* Function to add two Integers */
int Add(int a, int b){
    return a+b;
}


int Multiply(int a, int b){
    return a*b;
}


void pointer(){
    int x = 10;
    void *ptr1 = nullptr;
    cout << "x: " << x << endl;
    cout << "null pointer: " << ptr1 << endl;
    
    int *ptr = &x;
    cout << "address of x: " << ptr << endl;
    
    *ptr = 5;
    int y = *ptr;
    cout << "value of y: " << y << endl;
}


// Assignment
int Addptr(int *a, int *b){
    return *a + *b;
}


void AddVal(int *a, int *b, int *result){
    *result = *a + *b;
}

// Pass by Value
void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Pass by Reference
void SwapbyRef(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


void Factorial(int *a, int *b){
    int n = 1;
    for (int i = 1; i <= *a; ++i){
        n *= i;
    }
    *b = n;
}


void reference(){
    // Both x and ref point to same memory location
    // Hence any change in x is reflected in ref as well
    // Referent/Initializer
    int x = 10;
    // Reference
    int &ref = x;
    
    cout << "x: " << x << endl;
    cout << "ref: " << ref << endl;
    
    if (&x == &ref) {
        cout << "Both addresses match!!" << endl;
    }
}


void Print(int &ptr){
    cout << ptr << "\n";
}


void circumference(int radius){
    const float PI {3.141f};
    float area = PI * radius * radius;
    float circumference = PI * 2 * radius;
    cout << "Area is: " << area << endl;
    cout << "Circumference: " << circumference  << endl;
}
