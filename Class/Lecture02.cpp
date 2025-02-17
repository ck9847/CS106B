//
// Created by Lenovo on 25-2-17.
//
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cctype>

void quadratic(int a,int b,int c,double& root1,double& root2) {
    double d=sqrt(b*b-4.0*a*c);
    root1=(-b+d)/(2.0*a);
    root2=(-b-d)/(2.0*a);
}

void toUpperCase(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
        return std::toupper(c);
    });
}

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

void nameDiamond(std::string s) {
    for (int i=0;i<s.length();i++) {
        std::string output=s.substr(0,i+1);
        std::cout<<output<<std::endl;
    }
    for (int i=1;i<s.length();i++) {
        std::string output=s.substr(i,s.length());
        for (int j=0;j<i;j++) {
            std::cout<<" ";
        }
        std::cout<<output<<std::endl;
    }

}


int main() {
    std::string name="Marty Stepp";
    toUpperCase(name);
    std::cout<<name<<std::endl;
    std::cout<<"npos is "<<std::string::npos<<std::endl;

    std::string ageStr="42";
    int age=stringToInteger(ageStr);
    std::cout<<age<<std::endl;

    double r1,r2;
    quadratic(1,-3,-4,r1,r2);
    std::cout<<"The roots is:"<<r1<<" and "<<r2<<std::endl;

    std::string s="MARTY";
    nameDiamond(s);
    return 0;

}