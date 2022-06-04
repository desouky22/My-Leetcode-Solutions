class Solution {
public:
    vector<int> ret;
    int rows, cols ,n;
    pair<int, int> topLeft ;
    pair<int, int> topRight ;
    pair<int, int> bottomRight ;
    pair<int , int> bottomLeft ;
    int all = 0;
    
    void Do(vector<vector<int>>& matrix){
        for(int y = topLeft.second; y <= topRight.second; y++){
            if(all == n)return;
            ret.push_back(matrix[topLeft.first][y]);
            all++;

        }
        topLeft.first ++;
        topLeft.second++;
        topRight.first++;

        
        for(int x = topRight.first; x < bottomRight.first; x++){
            if(all == n)return;
            ret.push_back(matrix[x][topRight.second]);
            all++;
            if(all == n)return;

        }
        topRight.second--;

        
        for(int y = bottomRight.second; y > bottomLeft.second; y--){
            if(all == n)return;  
            ret.push_back(matrix[bottomRight.first][y]);
              all++;
        }
        bottomRight.first--;
        bottomRight.second--;
        
        for(int x = bottomLeft.first; x > topLeft.first-1; x--){
            if(all == n)return;
            ret.push_back(matrix[x][bottomLeft.second]);
            all++;
        }
        bottomLeft.first--;
        bottomLeft.second++;
        
        cout<<all<<"\n";
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        rows = matrix.size() , cols = matrix[0].size();
        topLeft = {0,0};
        bottomRight = {rows-1,cols-1};
        topRight = {0,cols-1};
        bottomLeft = {rows-1,0};
        
        n = rows*cols;
        int cntr = 0;
        while(all != n){
            cntr++;
            Do(matrix);
            if(cntr >100)break;
        }
        return ret;
    }
};








