#include <iostream>
using namespace std;

template <typename T>
class AlberoBinario {
private:
    T nodi[100]; 
    bool presente[100]; 

public:
  
    AlberoBinario() {
        for (int i = 0; i < 100; ++i) {
            presente[i] = false;  
    }

    bool alberoVuoto() const {
        return !presente[0];  
    }

    void insRadice(const T& valore) {
        if (!presente[0]) {  
            nodi[0] = valore; 
            presente[0] = true;  
        } else {
            cout << "La radice è già presente!" << endl;  
        }
    }

    T radice() const {
        if (presente[0]) {
            return nodi[0];  
        } else {
            cout << "L'albero è vuoto!" << endl;
        }
    }

    bool isFoglia(int indice) const {
        
        return (2 * indice + 1 >= 100 || !presente[2 * indice + 1]) &&  
               (2 * indice + 2 >= 100 || !presente[2 * indice + 2]);    
    }

    int figlioSinistro(int indice) const {
        int sinistro = 2 * indice + 1;  
        if (sinistro < 100 && presente[sinistro]) { 
            return sinistro;
        }
        cout << "Il figlio sinistro non esiste!" << endl;  
    }

    int figlioDestro(int indice) const {
        int destro = 2 * indice + 2;  
        if (destro < 100 && presente[destro]) {  
            return destro;
        }
        cout << "Il figlio destro non esiste!" << endl;  
    }

    // Inserisce un valore come figlio sinistro di un nodo dato
    void insFiglioSinistro(int indice, const T& valore) {
        int sinistro = 2 * indice + 1;  
        if (sinistro < 100 && !presente[sinistro]) {  
            nodi[sinistro] = valore;  
            presente[sinistro] = true;  
        } else {
            cout << "Figlio sinistro già presente o indice fuori limite!" << endl;  
        }
    }

    void insFiglioDestro(int indice, const T& valore) {
        int destro = 2 * indice + 2;  
        if (destro < 100 && !presente[destro]) {  
            nodi[destro] = valore;  
            presente[destro] = true; 
        } else {
            cout << "Figlio destro già presente o indice fuori limite!" << endl; 
        }
    }

    void rimuovi(int indice) {
        if (isFoglia(indice)) {  
            presente[indice] = false;  
        } else {
            cout << "Il nodo non è una foglia, quindi non può essere rimosso!" << endl;  
        }
    }

   
    void stampa() const {
        for (int i = 0; i < 100; ++i) {
            if (presente[i]) {  
                cout << "Pos " << i << ", Valore: " << nodi[i] << ", ";

                if (2 * i + 1 < 100 && presente[2 * i + 1]) {
                    cout << "Figlio sinistro: " << nodi[2 * i + 1] << ", ";
                } else {
                    cout << "Figlio sinistro: N/A, ";  
                }

                if (2 * i + 2 < 100 && presente[2 * i + 2]) {
                    cout << "Figlio destro: " << nodi[2 * i + 2] << endl;
                } else {
                    cout << "Figlio destro: N/A" << endl; 
                }
            }
        }
    }
};
