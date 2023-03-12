//
//  metodi.cpp
//  integrali mercatorum
//
//  Created by Gabriele Poggi on 08.03.23.
//

#include <stdio.h>
#include "Header.h"

/*metodi integrale*/
// get metodi
double Integrale::getA(void){
    return a;
};
double Integrale::getB(void){
    return b;
};

double Integrale::getDX(void){
    return dx;
};

double Integrale::integrale_trap(Funzione funzione)
{
    // spazio griglia
    double h = (b-a)/dx;
    // somma del risultato funzione primo e ultimo termine
    double s = funzione.f(a)+funzione.f(b);
 
    // aggiungo intervalli intermedi
    for (int i = 1; i < dx; i++) //loop per gli intervalli
        s += 2*funzione.f(a+i*h);
    return (h/2)*s;
};

/*metodi funzione*/
double Funzione::f(double x) const {
    if (*funz_pointer == 0){
        std::cout << "ERRORE: Nessuna funzione stabilita. usare il metodo Funzione.setFunzione(*nuova_funzione)\n";
        return 0;}
    else{
        return (*funz_pointer)(x);}
}

void Funzione::setFunzione(double (*nuova_f)(double)) {
    funz_pointer = nuova_f;
}
