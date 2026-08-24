#include<iostream>
#include<cmath>
using namespace std ;

void Qroot(int a , int b , int c ){

    int d = b*b  - 4*a*c ;

    int x1 = ((-b) + sqrt(d)) / 2*a ;
    int x2 = ((-b) - sqrt(d)) / 2*a ;
    
    if(d == 0){
        cout << "Roots are Real and Equal => " << x1 ;
    }

    else if(d > 0){
        cout << "Roots are Real and DIstinct => " << x1 << " , " << x2 ;
    }

    else{
        cout << "Roots are Imaginary " ;
    }

}

int main(){
    Qroot(1 , 8 , 12) ;
}