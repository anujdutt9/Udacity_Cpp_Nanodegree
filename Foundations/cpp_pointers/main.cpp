#include <iostream>
#include <string>
#include "string.h"

#define LOG(x) std::cout << "value of var is: " << x << std::endl

// Pointer: A pointer is an integer that holds an address in the memory

int main(){
    // This pointer is not a valid memory address, 0
    // initialized with nullptr to avoid pointing to a wrong memory address
    int* ptr = nullptr;
    // this uses memory on the stack
    int var = 8;

    // Find address of 8 in memory, and assign
    // it to a new variable "ptr"
    ptr = &var;

    LOG(var);
    std::cout << "address of var in memory is: " << ptr << std::endl;

    // Dereference the pointer i.e. manipulate data at address pointed
    // by the pointer
    *ptr = 10;
    LOG(var);

    // char = 1 byte of memory
    // allocate 8 chars = 8 bytes of memory in the heap
    char* buffer = new char[8];

    // Set the value at the starting of the buffer memory
    // NOTE: include "string.h" as memset is a macro in there
    memset(buffer, 9, 8);

    // Pointer to Pointer
    // ptr2 points to memory address of buffer pointer
    char** ptr2 = &buffer;

    // clear heap memory
    delete[] buffer;

    // Change pointer from one memory address to another
    int a = 5;
    int b = 10;
    
    // this pointer points to the memory address of "a"
    int* ptr3 = &a;
    std::cout << "\nptr3 pointing to address: " << ptr3 << std::endl;
    std::cout << "value at address ptr3 is pointing to: " << *ptr3 << std::endl;

    // to make the pointer point to memory address of "b"
    ptr3 = &b;
    std::cout << "\nptr3 pointing to address: " << ptr3 << std::endl;
    std::cout << "value at address ptr3 is pointing to: " << *ptr3 << std::endl;

    return 0;
}