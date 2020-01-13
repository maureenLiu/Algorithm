//
//  main.cpp
//  word_search
//
//  Created by Maureen on 2020/1/13.
//  Copyright © 2020 Maureen. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char> >& board, int row, int col, string word, int index) {
        int maxRow = board.size();
        int maxCol = board[0].size();

        if(index == word.length() - 1)  return true;

        bool result = false;

        //访问过的单词就设置为'\n'，以防本次后面递归时又将其考虑在内了,例如board为[["a","a"]],word为"aaa"
        board[row][col] = '\n';
        //向word[0]位置的各个方向遍历
        if(row+1 < maxRow && board[row+1][col] == word[index+1]) {
            result = dfs(board, row+1, col, word, index+1);
            if(result) return true;
        }

        if(row-1 >=0 && board[row-1][col] == word[index+1]) {
            result = dfs(board, row-1, col, word, index+1);
            if(result) return true;
        }

        if(col+1 < maxCol && board[row][col+1] == word[index+1]) {
            result = dfs(board, row, col+1, word, index+1);
            if(result) return true;
        }

        if(col-1 >= 0 && board[row][col-1] == word[index+1]) {
            result = dfs(board, row, col-1, word, index+1);
            if(result) return true;
        }
        board[row][col] = word[index];
        return false;
    }

    bool exist(vector<vector<char> >& board, string word) {
        int row = board.size();
        if(!row) return false;
        int col = board[0].size();

        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++) {
                if(board[i][j] == word[0]) {
                   bool res =  dfs(board, i, j, word, 0);
                   if(res) return true;
                }
            }
        return false;
    }
};



int main(int argc, const char * argv[]) {
    vector<vector<char> > board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'},
    };
    string word = "SEE";
    Solution s;
    bool res = s.exist(board, word);
    printf("res=%d\n", res);
    return 0;
}

