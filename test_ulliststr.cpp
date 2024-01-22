#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;
//Use this file to test your ulliststr implementation before running the test suite
void printULL(ULListStr& name){
    cout <<"hi";
}
int main(int argc, char* argv[])
{
ULListStr input;
for (int i=0; i<11; i++){
input.push_front("hello123456789" +i  );
}
cout << input.back() << "\n";
cout << input.front() << "\n";
cout << input.get(0)<< "\n";
input.print();
}
