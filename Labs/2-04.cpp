#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

bool res=false;//global variable to check if word is found or not
void solve(vector<vector<char>>& board,string &word,int x,int y,int idx){
    if(idx==word.length()){ 
        res=true;
        return;
    }
    board[x][y]='.'; //mark current as . ( . = reserved) to avoid selecting again
    if(x+1!=board.size() && board[x+1][y]==word[idx]){
        solve(board,word,x+1,y,idx+1);
    }
    if(x-1!=-1 && board[x-1][y]==word[idx]){
        solve(board,word,x-1,y,idx+1);
    }
    if(y+1!=board[0].size() && board[x][y+1]==word[idx]){
        solve(board,word,x,y+1,idx+1);
    }
    if(y-1!=-1 && board[x][y-1]==word[idx]){
        solve(board,word,x,y-1,idx+1);
    }
    board[x][y]=word[idx];// Unmark current
}
bool wordexist(vector<vector<char>>& board, string &word) {
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]==word[0]){ // if first latter found then procede further otherwise not
                solve(board,word,i,j,1);
                if(res)
                    return true;
            }
        }
    }
    return false;
}

int main(){
    vector<std::vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word ="ABCB";
    cout<<"Word "<<(wordexist(board,word)? "found!" : "not found!");
    return 0;
}