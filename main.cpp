#include <iostream>
using namespace std;
int main()
{
    srand(time(0));  
    int n, i, j, t, x, controlli, indice;
    bool scambio;

    cout << "Quanti numeri vuoi generare?" << endl;
    cin >> n;
    int numeri[n];

    i = 0;
    while (i <= n - 1) {
        numeri[i] = 1 + rand() % n;
        i = i + 1;
    }
    i = 0;
    scambio = true;
    while (i <= n - 1 && scambio) {
        scambio = false;
        j = 0;
        while (j <= n - 2 - i) {
            if (numeri[j] > numeri[j + 1]) {
                t = numeri[j];
                numeri[j] = numeri[j + 1];
                numeri[j + 1] = t;
                scambio = true;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    i = 0;
    while (i < n) {
        cout << "Il " << i + 1 << "° numero è " << numeri[i] << endl;
        i = i + 1;
    }
    cout << "Quale numero vuoi trovare?" << endl;
    cin >> x;
    indice = (int) (-1);
    i = 0;
    controlli = 0;
    x = 0;
    while (j <= n - 1 && indice == -1) {
        controlli = controlli + 1;
        if (numeri[i] == x) {
            indice = i;
        }
        i = i + 1;
    }
    if (indice == -1) {
        cout << "Il numero cercato non è nel vettore." << endl;
    } else {
        cout << "Il numero " << x << " è stato trovato nella " << indice << " cella. Con il metodo sequenziale sono stati eseguiti " << controlli << " controlli." << endl;
    }
    int inizio, medio, fine;

    indice = (int) (-1);
    inizio = 0;
    fine = n - 1;
    controlli = 0;
    while (indice == -1 && inizio <= fine) {
        medio = (int) ((double) (inizio + (fine - inizio)) / 2);
        if (numeri[medio] == x) {
            indice = medio;
        } else {
            if (numeri[medio] > x) {
                fine = medio - 1;
            } else {
                inizio = medio + 1;
            }
        }
        controlli = controlli + 1;
    }
    cout << "Il numero " << x << " è stato trovato nella " << indice << " cella. Con la ricerca binaria sono stati eseguiti " << controlli << " controlli." << endl;
  
}


