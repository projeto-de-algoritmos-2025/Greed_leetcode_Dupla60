/*
    Parece muito com a questão de Minimizar atraso, porém se houver um atraso não
    posso fazer aquele curso

    1° - Ordeno de forma crescente pelo Deadline
    2° - Verifico se o "tempoAtual" + "duration" <= "lasDay"
*/
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int ans = 0, now = 0;
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        for(int i = 0; i < courses.size(); i++){
            if(now + courses[i][0] <= courses[i][1]){
                now += courses[i][0];
                ans++;
            }
        }
        return ans;
    }
};
