/*
    Parece muito com a questão de Minimizar atraso, porém se houver um atraso não
    posso fazer aquele curso

    1° - Ordeno de forma crescente pelo Deadline
    2° - Verifico se o "tempoAtual" + "duration" <= "lastDay"
_______________________________________________________________________________________
    Pós "WA"
    Preciso de alguma forma para levar em consideração a duração também, e não somente o deadline
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
            else{   
                if(!pq.empty() && pq.top() > courses[i][0]){    // Se existe uma opção que não 
                    int t = pq.top();                           // caberia mas tem tempo menor
                    pq.pop();
                    now = now + courses[i][0] - t; 
                    pq.push(courses[i][0]);
                }
            }
        }
        return ans;
    }
};
