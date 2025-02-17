//
// Created by Lenovo on 25-2-16.
//
#include <iostream>
#include <sstream>
#include <algorithm>
int getInteger(std::string str);
void song() {
  std::cout<<"Now this is the story"<<std::endl;
  std::cout<<"all about how"<<std::endl;
  std::cout<<"My life got flipped"<<std::endl;
  std::cout<<"Turned upside down"<<std::endl;
}

int main(){
  /*std::cout<<"Now this is the story"<<std::endl;
  std::cout<<"all about how"<<std::endl;
  std::cout<<"My life got flipped"<<std::endl;
  std::cout<<"Turned upside down"<<std::endl;*/

  song();
  std::cout<<"Hello World!"<<std::endl;
  int age=getInteger("How old are you?");
  std::cout<<"Yeah right!Marty wisher he were "<<age<<"!"<<std::endl;

  /*std::cout<<"Now this is the story"<<std::endl;
  std::cout<<"all about how"<<std::endl;
  std::cout<<"My life got flipped"<<std::endl;
  std::cout<<"Turned upside down"<<std::endl;*/
  song();

  return 0;
}


int getInteger(std::string str) {
  std::cout << str;
  std::string age;

  while (true) {
    std::cin >> age;

    // 使用 std::all_of 检查字符串中的所有字符是否都是数字
    if (std::all_of(age.begin(), age.end(), [](char c) { return std::isdigit(c); })) {
      // 将字符串转换为整数
      int num;
      std::stringstream ss(age);
      ss >> num;
      return num;
    } else {
      std::cout << "wrong input!Try again!" << std::endl;
    }
  }
}