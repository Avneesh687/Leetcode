class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res(m, string(n, '#'));
        int i = 0, j = 0;
        while(j < n-1){
            res[i][j] = '.';
            j++;
        }
        while(i < m){
            res[i][j] = '.';
            i++;
        }
        return res;
    }
};