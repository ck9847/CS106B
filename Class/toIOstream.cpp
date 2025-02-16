//
// Created by Lenovo on 25-1-23.
//
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>
/*int stringToInteger(const std::string& str);
int main() {
    std::ifstream input;
    input.open(R"(D:\everycodethatyoudontlike\CS106\practise\poedm.txt)");
    if(input.fail()) {
        std::cerr<<"Failed to open file"<<std::endl;
        return 1;
    }
    std::string line;
    int sum=0;
    while (std::getline(input, line)) {
        sum+=stringToInteger(line);
    }
    std::cout<<"The sum is "<< sum <<std::endl;
    input.close();
    return 0;
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

}*/
/*template <typename T>
class Grid {
    public:
    int rows,cols;
    T** grid;
    Grid(int r,int c):rows(r),cols(c) {
        grid=new T*[rows];
        for(int i=0;i<rows;i++) {
            grid[i]=new T[cols];
            for (int j = 0; j < cols; j++) {
                grid[i][j]=T();
            }
        }
    }
    ~Grid() {
        for (int i = 0; i < rows; i++) {
            delete[] grid[i];
        }
        delete[] grid;
    }
    bool inbounds(int r,int c) {
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }
    T* operator[](int index){return grid[index];}
    const T* operator[](int index)const{return grid[index];}
};

bool knightCanMove(Grid<std::string>& board,int r1,int c1,int r2,int c2) {
    if (board[r1][c1]!="knight"||board[r2][c2]!=" ") {
        return false;
    }
    if (!board.inbounds(r1,c1) || !board.inbounds(r2,c2)) {
        return false;
    }
    int dr=std::abs(r2-r1);
    int dc=std::abs(c2-c1);
    if ((dr==1&&dc==2)||(dr==2&&dc==1)) {
        return true;
    }else {
        return false;
    }
}

void test(Grid<std::string>& board,int r1,int c1,int r2,int c2,bool expected) {
    bool result = knightCanMove(board,r1,c1,r2,c2);
    std::cout<<"Test from("<<r1<<","<<c1<<")to("<<r2<<","<<c2<<"):"<<(result==expected?"passed":"Failed")<<std::endl;
}
int main() {
    Grid<std::string> board(8,8);
    board[1][2]="knight";
    board[0][4]="king";
    board[3][1]="rook";
    test(board,1,2,0,0,true);
    test(board,1,2,0,1,false);
    test(board,1,2,0,4,false);

    return 0;


}*/
/*
void nameDiamond(std::string s);
int main() {
    nameDiamond("Marty");
}
void nameDiamond(std::string s) {
    for (int i=0;i<s.length();i++) {
        std::cout<<s.substr(0,i+1)<<std::endl;
    }
    for (int i=0;i<s.length();i++) {
        for (int j=0;j<i+1;j++) {
        }
        std::cout<<s.substr(i+1)<<std::endl;
    }
}*/
int main() {
    std::vector<std::string> names {"xmin","xmax","ymin","ymax"};
    for (int i=0;i<names.size();i++) {
        std::cout<<names[i]<<std::endl;
    }
    /*for (std::string name:names) {
        std::cout<<name<<std::endl;
    }   输出与上面相同*/
    std::vector<int> numbers {1,2,3,4,5,6,7,8,9};
    for (int i=static_cast<int>(numbers.size())-1;i>=0;i--) {
        std::cout<<numbers[i];
    }
    std::cout<<std::endl;

    numbers.insert(numbers.begin()+2,5);
    for (int number:numbers) {
        std::cout<<number<<"";
    }
    /*for (int number:numbers) {
        std::cout<<number;
    }   输出与上面相同*/
    return 0;
}

