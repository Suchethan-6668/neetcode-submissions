/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool isSame(vector<vector<int>>& grid,int row,int col,int len) {
        int val = grid[row][col];

        for(int i = row;i < row+len;i++) {
            for(int j = col;j < col+len;j++) {
                if(grid[i][j] != val)return false;
            }
        }
        return true;
    }
    Node* solve(vector<vector<int>>& grid,int row,int col,int len) {
        if(isSame(grid,row,col,len))return new Node(grid[row][col] == 1,true);

        int half = len/2;

        Node* tl = solve(grid,row,col,half);
        Node* tr = solve(grid,row,col+half,half);
        Node* bl = solve(grid,row+half,col,half);
        Node* br = solve(grid,row+half,col+half,half);

        return new Node(true,false,tl,tr,bl,br);
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();

        return solve(grid,0,0,n);
        

        
    }
};