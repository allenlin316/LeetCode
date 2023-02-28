# [200. Number of Islands](https://leetcode.com/problems/number-of-islands/)

## 想法
運用到 `DFS` 遞迴的想法，當我為 `land` 的時候，我就 `DFS` 繼續找附近有沒有也是 `land` 的，當周圍都找完並把找過的註記起來，這樣就不會再算到同一塊 `land`。


## 程式碼
```cpp
void dfs(vector<vector<char>> &grid, int i, int j){
    grid[i][j] = '2';   //標記找過的點
    if(j-1>=0 && grid[i][j-1] == '1')
        dfs(grid, i, j-1);
    if(i-1>=0 && grid[i-1][j] == '1')
        dfs(grid, i-1, j);
    if(i+1<=grid.size()-1 && grid[i+1][j] == '1')
        dfs(grid, i+1, j);
    if(j+1 <= grid[i].size()-1 && grid[i][j+1] == '1')
        dfs(grid, i, j+1);
}

int numIslands(vector<vector<char>>& grid) {
    int cnt=0;
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
            if(grid[i][j] == '1'){
                cnt++;
                dfs(grid, i, j); // 檢查周圍是不是有跟目前這塊連在一起，有的話就標記起來才不會重複算到
            }
        }
    }
    return cnt;
}
```
![](https://imgur.com/NNyU2Hn.png)