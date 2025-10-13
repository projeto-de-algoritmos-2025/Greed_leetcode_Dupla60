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
            return a[1] < b[1];     // Ordena de forma crescente em courses[i][1]
        });                         // (Crescente por Deadline)

        priority_queue<int> pq;     // Cria um MaxHeap 

        for(int i = 0; i < courses.size(); i++){    // Para cada curso
            if(now + courses[i][0] <= courses[i][1]){   // Se tenho tempo para fazer
                now += courses[i][0];                   // Atualiza o tempo
                ans++;                                  // Atualizo a resposta
                pq.push(courses[i][0]);                 // Coloco o tempo do curso no MaxHeap
            }
            else{      // Se não tenho tempo para fazer o curso
                if(!pq.empty() && pq.top() > courses[i][0]){    // Se existe uma opção que gasta 
                    int t = pq.top();                           // menos tempo (comparando com o Heap)
                    pq.pop();                                   // Removo a tarefa antiga do Heap
                    now = now + courses[i][0] - t;  // Removo o tempo da tarefa antiga e add o novo
                    pq.push(courses[i][0]);         // Adiciono a nova tarefa no Heap
                }
            }
        }
        return ans;
    }
};
