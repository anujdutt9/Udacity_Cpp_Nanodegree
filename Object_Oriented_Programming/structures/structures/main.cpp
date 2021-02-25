//
//  main.cpp
//  structures
//
//  Created by Anuj Dutt on 2/16/21.
//

#include <iostream>
#include <cassert>


// Define a structure
class Date {
// Access Modifier
public:
    // Constructor
    Date(int d, int m, int y);

    // Getters or Accessor functions
    int GetDay() const { return day; }
    int GetMonth() const { return month; }
    int GetYear() const { return year; }
    
    // Setter or Mutator functions
    void SetDay(int d);
    void SetMonth(int m);
    void SetYear(int y);

// Access Modifier
private:
    // provide initial values that can be overwritten
    int day{1};
    int month{1};
    int year{0};
};


// Scope Resolution
// :: -> Scope Resolution operator
// use this operator to specify which namespace or class
// to search in order to resolve an identifier.

// setting the values of private variables directly using this function
// Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

Date::Date(int d, int m, int y) {
    SetDay(d);
    SetMonth(m);
    SetYear(y);
}

// Setter Function Declaration
void Date::SetDay(int d){
    if (d >= 1 && d <= 31){
        day = d;
    }
}

void Date::SetMonth(int m){
    if (m >= 1 && m <= 12){
        month = m;
    }
}

void Date::SetYear(int y){
    year = y;
}


int main(int argc, const char * argv[]) {
    // instantiate structure by providing values
    // that go to a constructor
    Date date(29, 8, 2021);

    
    // Assert for date
    assert(date.GetDay() == 29);
    assert(date.GetMonth() == 8);
    assert(date.GetYear() == 2021);
    
    std::cout << date.GetDay() << "/" << date.GetMonth() << "/" << date.GetYear() << "\n";
    
    return 0;
}
