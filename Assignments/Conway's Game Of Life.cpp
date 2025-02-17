///
// Created by Lenovo on 25-2-14.
//
#include <iostream>
#include <random>
#include <vector>

class Solution {
    public:
        void gameOfLife(std::vector<std::vector<int> >& board) {
            int rows = board.size();  //获取棋盘的行数
            int cols = board[0].size();  //获取棋盘的列数

            std::vector<std::vector<int>> nextBoard=board;  //创建一个副本，用于存储下一状态

            //遍历棋盘每一个细胞
            for (int i=0;i<rows;i++) {
                for (int j=0;j<cols;j++) {
                    int liveNeighbours = countLiveNeighbours(board,i,j);  //计算当前细胞周围的活细胞数量

                    //如果当前细胞是活细胞
                    if (board[i][j]==1) {
                        //如果周围活细胞少于2个或多于3个，则该活细胞死亡
                        if (liveNeighbours<2||liveNeighbours>3) {
                            board[i][j]=0;
                        }
                    }
                    //如果当前细胞是死细胞
                    else {
                        //如果周围活细胞恰好为3个，死细胞复活
                        if (liveNeighbours==3) {
                            board[i][j]=1;
                        }
                    }
                }
            }
            //更新棋盘状态为下一状态
            board=nextBoard;
        }

    private:
         //countLiveNeighbours用于计算指定位置周围的活细胞数量
        int countLiveNeighbours(std::vector<std::vector<int> >& board, int row, int col) {
            int liveCount=0;
            //定义8个方向的偏移量，分别为左上、上、右上、左、右、左下、下、右下
            int directions[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
            int rows=board.size();
            int cols=board[0].size();

            //遍历8个方向，检查每个方向的细胞是否在棋盘内且为活细胞
            for (auto& direction:directions) {
                int newRow=row+direction[0];
                int newCol=col+direction[1];

                //检查新位置是否在棋盘内
                if (newRow>=0 && newRow<rows && newCol>=0 && newCol<cols) {
                    liveCount+=board[newRow][newCol];
                }
            }
            return liveCount;
    }
};


int main() {
    /*int boardLength= rand() % 100+1;  //格子的长度范围为[1,100]
    int boardWidth= rand() % 25+1;    //格子的宽度范围为[1,25]*/
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<int> disboardLength(1,100);
    std::uniform_int_distribution<int> disboardWidth(1,25);
    int boardLength=disboardLength(gen);
    int boardWidth=disboardWidth(gen);

    //初始化游戏板
    std::vector<std::vector<int>> board(boardLength, std::vector<int>(boardWidth, 0));

    //随机填充一些活细胞
    int liveCells;
    int maxLive=boardLength*boardWidth;
    std::cout<<"Input the liveCells: (Please enter a number in the range 2-"<<maxLive<<")"<<std::endl;
    std::cin>>liveCells;

    //随机生成活细胞位置
    std::uniform_int_distribution<> disRow(0,boardLength-1);
    std::uniform_int_distribution<> disCol(0,boardWidth-1);

    for (int i=0;i<liveCells;i++) {
        int row=disRow(gen);
        int col=disCol(gen);
        board[row][col]=1;  //将选中位置作为活细胞
    }

    //打印初始棋盘状态
    std::cout<<"Initial state board:"<<std::endl;
    for (const auto& row : board) {
        for (int cell:row) {
            std::cout<<cell<<" ";
        }
        std::cout<<std::endl;
    }

    Solution sol;
    sol.gameOfLife(board); //更新棋盘状态

    //打印更新后棋盘的状态
    std::cout<<"Updated state of the board:"<<std::endl;
    for (const auto& row:board) {
        for (int cell:row) {
            std::cout<<cell<<" ";
        }
        std::cout<<std::endl;
    }
}

