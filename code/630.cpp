/*
    Parece muito com a questão de Minimizar atraso, porém se houver um atraso não
    posso fazer aquele curso

    1° - Ordeno de forma crescente pelo Deadline
    2° - Verifico se o "tempoAtual" + "duration" <= "lastDay"
_______________________________________________________________________________________
    Pós "WA"
    Preciso de alguma forma para levar em consideração a duração também, e não somente o deadline

    talvés eu possa colocar todos os cursos na solução (em ordem de deadline) e ir removendo os de duração mais alta
*/
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int ans = 0, now = 0;
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        priority_queue<int> pq;

        for(int i = 0; i < courses.size(); i++){
            if(now + courses[i][0] <= courses[i][1]){
                now += courses[i][0];
                ans++;
                pq.push(courses[i][0]);
            }
            else{   // preciso remover o de duração max?
                if(pq.top() > courses[i][0]){
                    int t = pq.top();
                    pq.pop();
                    now = now + courses[i][0] - t; 
                }
            }
        }
        return ans;
    }
};
