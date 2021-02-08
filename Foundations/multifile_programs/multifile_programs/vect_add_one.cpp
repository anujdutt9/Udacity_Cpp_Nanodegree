//
//  vect_add_one.cpp
//  multifile_programs
//
//  Created by Anuj Dutt on 2/6/21.
//

#include <iostream>
#include <vector>
#include "vect_add_one.hpp"

using std::vector;
using std::cout;

void AddOneToEach(std::vector<int> &v){
    for (auto& i: v){
        i++;
    }
    
    cout << "v After Increment: \n";
    for (int i=0; i < v.size(); ++i){
        cout << v[i];
    }
    cout << "\n";
}
