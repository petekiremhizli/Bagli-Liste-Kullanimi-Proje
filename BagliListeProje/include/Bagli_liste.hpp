#ifndef BAGLI_LISTE_H
#define BAGLI_LISTE_H
#include <iostream>
#include "../include/Agac.hpp"
using namespace std;

// Tek yönlü bağlı listenin düğümü
class Dugum{
    public:
    Agac* agac;
    Dugum* sonraki; // sonraki ağacın adresini tutucaz
     // Constructor
    Dugum(Agac* agac); 

};

// Tek yönlü bağlı liste sınıfı
class BagliListe{
    private:
    Dugum* ilkDugum; //bağlı listemizin ilk düğümü 
   public:
  
    BagliListe();
    ~BagliListe();
    void dugumVeSonrakiAdresleriniYazdir(); // Düğüm adreslerini yazdırma fonksiyonu

    void listeyeAgacEkle(Agac* agac);
    void listedenAgacSil(Agac* agac);
    void cizgiCiz(int sayi);
    bool kullaniciGirdisiniIsle(int toplamDugum, int& gorunenBaslangic, int& gorunenAdet, int& index);
    void silDugum(int index);
    void agacToplamlariniHesapla();
   
    

  


    




};
#endif 