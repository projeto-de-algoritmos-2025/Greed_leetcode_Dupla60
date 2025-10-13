class Solution {
    /*
    Posso fazer o Interval Schedueling normal, mas quando encontrar um evento incompativel, removo-o
    1° ordenar em ordem crescente de termino
    2° para cada tarefa verifico se ela é compatível, se for, atualiza o valor de end[i], se não é removida
    */
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // Ordena em ordem crescente pelo intervals[i][1] (tempo de fim da tarefa)
        });
        // for(auto x : intervals){                             // Estava usando para achar erros
        //     cout << "[" << x[0] << " - " << x[1] << "]\n";
        // }
        int ans = 0;
        int end = -50001;

        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] >= end){ // Se é compatível
                end = intervals[i][1];  // Atualiza o horario de termino da ultima tarefa
            }
            else                        // Não compatível
                ans++;
        }

        return ans;
    }
};
