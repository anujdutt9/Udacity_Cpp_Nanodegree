#include <iostream>
#include <string>


// Multiply function
int Multiply(int a, int b){
    return a * b;
}

// Helper function
void MultiplyAndLog(int a, int b){
    int result = Multiply(a, b);
    std::cout << result << std::endl;
}

int main(){
    MultiplyAndLog(3, 8);
    MultiplyAndLog(93, 45);
    return 0;
}