//
//  main.cpp
//  multifile_programs
//
//  Created by Anuj Dutt on 2/6/21.
//

#include <iostream>
#include "increment_and_sum.hpp"
using std::cout;

int main(int argc, const char * argv[]) {
    vector<int> v{1,2,3,4,5};
    int total = IncrementAndComputeVectorSum(v);
    cout << "The total is " << total << "\n";
    return 0;
}
