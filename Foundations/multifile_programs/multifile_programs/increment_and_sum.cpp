//
//  increment_and_sum.cpp
//  multifile_programs
//
//  Created by Anuj Dutt on 2/6/21.
//

#include <vector>
#include "vect_add_one.hpp"
#include "increment_and_sum.hpp"
using std::vector;

int IncrementAndComputeVectorSum(std::vector<int> v){
    int total = 0;
    AddOneToEach(v);
    
    for (auto& i: v){
        total += i;
    }
    
    return total;
}
