#include <iostream>
#include <cassert>

#define LOG(x) std::cout << x << std::endl

// Pass by Value
// Creates a new variable, stores in memory
void Increment_by_Value(int value){
    value++;
    LOG(value);
}

// Pass by Pointer
// pass in the pointer to address of the value we want to change
void Increment_by_Pointer(int* value){
    // dereference the variable and increment the value
    // stored at that address
    // dereference the pointer first and then increment the value
    (*value)++;
}

// Pass by Reference
// pass in the pointer to address of the value we want to change
void Increment_by_Reference(int& value){
    // "value" is a reference to "a", does not allocate any new memory
    // unlike pointers
    // increment the value in place
    value++;
}


int main(){
    int a = 5;
    Increment_by_Value(a);
    LOG(a);
    
    // "ref" is a reference to "a", does not allocate any new memory
    // unlike pointers
    int& ref = a;
    assert ((a == 5) && (ref == 5));
    LOG(ref);

    // now if we change the value assigned to ref
    ref = 2;
    assert ((ref == 2) && (a == 2));
    LOG(ref);
    
    // Pass in the memory address of "a"
    Increment_by_Pointer(&a);
    LOG(a);
    assert (a == 3);

    Increment_by_Reference(a);
    LOG(a);
    assert (a == 4);

    // we cannot change the reference from one variable to another
    int x = 5;
    int y = 10;
    int& ref2 = x;

    std::cout << "\nx: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "ref2 has value: " << ref2 << std::endl;

    // changing the reference to "b"
    ref2 = y;
    std::cout << "\nx: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "ref2 has value: " << ref2 << std::endl;

    return 0;
}