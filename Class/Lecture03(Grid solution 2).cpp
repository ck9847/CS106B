//
// Created by Lenovo on 25-2-17.
//
#include <iostream>
#include <cmath>
#include <cstdlib>


template <typename T>
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


}