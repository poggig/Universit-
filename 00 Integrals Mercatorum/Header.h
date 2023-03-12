//
//  Header.h
//  integrali mercatorum
//
//  Created by Gabriele Poggi on 08.03.23.
//

#ifndef Header_h
#define Header_h
#include <iostream>

class Funzione {
    
  
  public:
    Funzione(){};
    
    // la funzione
    double f(double x) const;
    // settare la funzione
    void setFunzione(double (*nuova_f)(double));
    
    private:
    double (*funz_pointer)(double) = 0; // pointer alla funzione
};



/*
 1. Definire la funzione f(x) da integrare
 2. Definire l'intervallo [a, b] su cui integrare la funzione
 3. Definire il numero di trapezi n
 4. Calcolare la larghezza di ogni trapezio h = (b - a) / n
 5. Inizializzare la variabile area a 0
 6. Calcolare il valore della funzione f(a) e f(b)
 7. Aggiungere (f(a) + f(b)) / 2 all'area
 8. Per i = 1 fino a n - 1:
      a. Calcolare il valore della funzione f(a + i*h)
      b. Aggiungere f(a + i*h) all'area
 9. Moltiplicare l'area per h e restituirla

 
*/
class Integrale{
public:
    Integrale( double a, double b, int dx){
        this -> a =a;
        this -> b =b;
        this-> dx = dx;
    };;
        // get metodi
        double getA(void);
        double getB(void);
        double getDX(void);
            
        // funzione per calcolare l'integrale (virtuale, da definire)
    double integrale_trap(Funzione funzione);
    // Distruttore
        ~Integrale() {}
private:
    double a; //primo estremo
    double b; // secondo estremo
    int dx; // delta x in cui suddividere l'area della funzione
};

#endif /* Header_h */
