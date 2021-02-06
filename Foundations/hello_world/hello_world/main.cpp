//
//  main.cpp
//  hello_world
//
//  Created by Anuj Dutt on 11/26/20.
//

#include <iostream>
#include <vector>
#include "math.hpp"

// Define Namespace
using namespace std;

// Function declaration/prototype
void userInput();

int main(int argc, const char * argv[]) {
    // Scalars
    int i {0};
    int x = 3, y = 5, res;
    int result = 0;
    
    // Pointer to Address of x
    // prt points to address of x
    int *ptr = &x;
    
    // Void pointer
    // can take in value of any type
    void *ptr1 = &x;
    
    char ch = 'a';
    bool flag = true; // true/false or 0/1
    float f = 0.001f; // suffix with literal f
    double d = 512.42;
    
    // Vector
    //int arr[5];
    int arr1[5] = {1,2,3,4,5};
    int arr1_len = sizeof(arr1)/sizeof(arr1[0]);
    
    std::cout << "Hello, World!" << std::endl;
    cout << "i: " << i << endl;
    cout << "ch: " << ch << endl;
    cout << "flag: " << flag << endl;
    cout << "f: " << f << endl;
    cout << "d: " << d << endl;
    
    // Print out elements of array
    for (int j=0; j < arr1_len; j ++){
        cout << "arr1: " << arr1[j] << endl;
    }
    
    // Function Call
    //userInput();
    cout << "Sum of "<< x << " and " << y << " is " << Add(x, y) << endl;
    cout << "Address of x is: " << ptr << endl;
    cout << "Address of x using Void pointer: " << ptr1 << endl;
    
    pointer();
    result = Addptr(&x, &y);
    cout << "Addptr: " << result << endl;
    
    AddVal(&x, &y, &result);
    cout << "AddVal result: " << result << endl;
    
    Swap(&x, &y);
    cout << "Swap x, y: " << x << " , " << y << endl;
    
    Factorial(&x, &res);
    cout << "Factorial of x = " << x << " is " << res << endl;
    
    // Reference
    reference();
    
    // Swap by Reference
    SwapbyRef(x, y);
    cout << "x: " << x << "\n";
    cout << "y: " << y << "\n";
    
    // Pass by Ref
    Print(*ptr);
    
    circumference(x);
    
    // Vectors like Linked List, Dictionary etc.
    vector<int> v_1{0, 1, 2};
    vector<int> v_2 = {3, 4, 5};
    vector<int> v_3;
    v_3 = {6};
    
    cout << "v_1" << endl;
    for (int i = 0; i < v_1.size(); ++i) {
        cout << v_1[i] << endl;
    }
    
    cout << "v_2" << endl;
    for (int i = 0; i < v_2.size(); ++i) {
        cout << v_2[i] << endl;
    }
    
    cout << "v_3" << endl;
    for (int i = 0; i < v_3.size(); ++i) {
        cout << v_3[i] << endl;
    }
    
    // Using "auto" keyword, compiler automatically determines the type of the variable
    auto a = 5;
    auto v_6 = {1, 2, 3};
    
    return 0;
}


/* Function to read User Input */
//
void userInput(){
    int age;
    char buff[512];
    cout << "Please enter your age.." << endl;
    cin >> age;
    cout << "Your age is: " << age << endl;
    
    cout << "Please enter your name.." << endl;
    // Read string from user that contains spaces
    // Inputs: Buffer, Number of chars to read, delimiter
    cin.getline(buff, 64, '\n');
    cout << "Name: " << buff << endl;
}
