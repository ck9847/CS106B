//
// Created by Lenovo on 25-2-17.
//
#include <iostream>
#include <fstream>

int stringToInteger(const std::string& str) {
  int sum=0;
  int currentNum=0;
  bool inNumber=false;
  for (char ch:str) {
    if (std::isdigit(ch)) {
      currentNum=currentNum*10+ch-'0';
      inNumber=true;
    }else if (inNumber) {
      sum+=currentNum;
      currentNum=0;
      inNumber=false;
    }
  }
  if (inNumber) {
    sum+=currentNum;
  }
  return sum;

}

int main(){
  std::ifstream input;
  input.open("test.txt");
    if (input.fail()) {
      std::cerr << "Error opening file" << std::endl;
    }
  std::string token;
  int words=0;
  while(input>>token){
    if (stringToInteger(token)>0) {
      std::cout<<"The int token is "<<token<<std::endl;
    }
    std::cout<<"Here is a word: "<<token<<std::endl;
    words++;
}
    std::cout<<"Total number of words: "<<words<<std::endl;
    input.close();
    return 0;

  }

