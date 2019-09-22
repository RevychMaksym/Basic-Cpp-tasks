#include <iostream>

int main(int argc, char const *argv[]) {
  std::cout << "Please enter the number you want to reverse: ";
  int32_t input;
  std::cin >> input;
  int reverse;
  while(input != 0)    
  {    
    rem = input % 10;      
    reverse = reverse * 10 + rem;    
     input /= 10;    
  }    
 std::cout<<"Reversed Number: "<< reverse <<std::endl;     
return 0;  
}  
