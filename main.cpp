int main() {

  AlberoBinario<int> albero;

    albero.insRadice(1);
    
    albero.insFiglioSinistro(0, 2);
    albero.insFiglioDestro(0, 3);
    
    albero.insFiglioSinistro(1, 4);
    albero.insFiglioDestro(1, 5);
    
    cout << "Struttura dell'albero:" << endl;
    albero.stampa();
    
    albero.rimuovi(4);  
    cout << "Dopo la rimozione di un nodo foglia:" << endl;
    albero.stampa();
    
    albero.rimuovi(0);  
    
    return 0;
}
