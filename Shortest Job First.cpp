#include<bits/stdc++.h>
using namespace std;
 
struct Process
{
   int pid; 
   int tempoConsumo;  
};
 
// Organizar os processos em ordem crescente de tempo de consumo
bool comparison(Process a, Process b)
{
     return (a.tempoConsumo < b.tempoConsumo);
}
 
// Encontra o tempo de espera.
void econtraTempoEspera(Process proc[], int n, int wt[])
{
    //Tempo de espera 1 é 0
    wt[0] = 0;
 
    // Calculando
    for (int i = 1; i < n ; i++ )
        wt[i] = proc[i-1].tempoConsumo + wt[i-1] ;
}
 
//Calcula o tempo de resposta.
void resposta(Process proc[], int n,
                        int wt[], int tat[])
{
    
    for (int i = 0; i < n ; i++)
        tat[i] = proc[i].tempoConsumo + wt[i];
}
 
//FCalcula a média de tempo
void media(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    
   econtraTempoEspera(proc, n, wt);
 
    
    resposta(proc, n, wt, tat);
 
    
    cout << "\nProcessos "<< " Tempo de consumo "
         << " Tempo de espera " << " Tempo de resposta\n";
 
  //Calcula tempo total de espera e repsosta
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << proc[i].pid << "\t\t"
             << proc[i].tempoConsumo << "\t " << wt[i]
             << "\t\t " << tat[i] <<endl;
    }
 
    cout << "Media d etempo de espera = "
         << (float)total_wt / (float)n;
    cout << "\nMédia de tempo de resposta = "
         << (float)total_tat / (float)n;
}
 

int main()
{
    Process proc[] = {{1, 6}, {2, 8}, {3, 7}, {4, 3}};
    int n = sizeof proc / sizeof proc[0];
 
    // Organizando pelo tempo de consumo.
    sort(proc, proc + n, comparison);
 
    cout << "Ordem de execução: \n";
    for (int i = 0 ; i < n; i++)
        cout << proc[i].pid <<" ";
 
    findavgTime(proc, n);
    return 0;
}

