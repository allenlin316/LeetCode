#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int room_num, key_num, row, col, tmp;
    vector<int> rooms;
    cin >> room_num;
    row = col = room_num;
    vector<vector<int>> matrix(row, vector<int>(col));
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            matrix[i][j] = 0;
        }
    }
    for(int room=0; room<room_num; room++){
        cin >> key_num;
        while(key_num--){
            cin >> tmp;
            matrix[room][tmp] = 1;
        }
    }
    bool res[room_num];
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(matrix[i][j] == 1){
                res[j] = true;
            }
        }
    }
    int cnt=0;
    for(int i=0; i<room_num; i++){
        if(!res[i]){
            cout << "no";
            return 0;
        }
    }
    cout << "yes";
}
