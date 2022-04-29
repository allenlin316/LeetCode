# [165-Compare Version Numbers](https://leetcode.com/problems/compare-version-numbers/)

## 問題
給定兩個版本編號，分別為 `version1`、`version2`，每個版本有一個或以上的 `revision`，每個版本會以 `.` 隔開，如果版本的數字有 0 為數字的開頭的話，不用理它。要比較兩個版本號碼的大小關係。`Revisions` 為 `0-indexed from left-to-right`，最左邊 revision 是 revision 0。如果在某一個 index 沒有 revision 就給 0。以下列規則比較

* If `version1 > version2`, return `-1`
* If `version1 < version2`, return `1`
* Otherwise, return 0 


## 想法
先把兩個字串切成一個一個的數字放進陣列再做比對，如果長度不一樣就用 0 補足。最後兩個陣列的每個值互相比對。


## 程式碼
```cpp
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        vector<int> v2;
        string delim = ".";
        int num, pos, i=0, j=0;
        while((pos=version1.find(delim)) != -1){ // 字串切割
            v1.push_back(stoi(version1.substr(0, pos)));
            version1.erase(0, pos+1);
        }
        while((pos=version2.find(delim)) != -1){
            v2.push_back(stoi(version2.substr(0, pos)));
            version2.erase(0, pos+1);
        }
        v1.push_back(stoi(version1)); // 把剩下的字串放進去
        v2.push_back(stoi(version2));
        while(v1.size() < v2.size())  // 補足長度
            v1.push_back(0);
        while(v2.size() < v1.size())
            v2.push_back(0);
        while(i<v1.size() && j<v2.size()){
            if(v1[i] > v2[j])   return 1;
            else if(v1[i] < v2[j])  return -1;
            i++;
            j++;
        }
        return 0;
    }
};
```

![](https://imgur.com/kQJ7wcg.png)


## 分類
`Two Pointers`