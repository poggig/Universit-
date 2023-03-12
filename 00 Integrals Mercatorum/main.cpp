//
//  main.cpp
//  integrali mercatorum
//
//  Created by Gabriele Poggi on 08.03.23.
//

#include <iostream>
#include "Header.h"

using namespace std;


// Dichiarazione di una funzione da integrare

double quadrato(double x) {
    return x * x;
};

double a, b, dx;


int main() {
    Funzione quadr_ist; // istanza di un oggetto funzione (quadrato)
    //decidere la funzione da implementare
    quadr_ist.setFunzione(quadrato);

        
    while (a>=b){
        cout << "Inputare inizio dell'intervallo (a)\n";
        cin >> a;
        
        cout << "Inputare fine dell'intervallo (b)\n";
        cin >> b;
        if (a>=b){cout <<"a deve essere minore di b\n";
            continue; // se a è maggiore uguale di b ricomincia il loop
        };
        cout << "Inputare delta X in cui dividere intervallo della funzione: \n";
        cin >> dx;
        
        
    };
    
    
    Integrale intgr( a, b, dx); //istanza di integrale
    
    double result = intgr.integrale_trap(quadr_ist);
    cout << " l'integrale calcolato con la formula del trapezio, per la funzione definita è\n\n" ;

    cout << result ;
    cout << "\n\n";
    
    return 0;
}
