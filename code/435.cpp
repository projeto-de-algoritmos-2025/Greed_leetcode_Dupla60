class Solution {
    /*
    Posso fazer o Interval Schedueling normal, mas quando encontrar um evento incompativel, removo-o
    1° ordenar em ordem crescente de termino
    2° para cada tarefa verifico se ela é compatível, se for, atualiza o valor de end[i], se não é removida
    */
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        // for(auto x : intervals){
        //     cout << "[" << x[0] << " - " << x[1] << "]\n";
        // }
        int ans = 0;
        int end = -50001;

        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] >= end){
                end = intervals[i][1];
            }
            else
                ans++;
        }

        return ans;
    }
};
