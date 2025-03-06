#ifndef KROMOZOM_HPP
#define KROMOZOM_HPP
#include "Gen.hpp"

class Kromozom{
    public:
    Kromozom* sonraki;
    Kromozom* onceki;
    
    Kromozom();
    ~Kromozom();
      
    Gen* baslangic;
    Gen* son;

    int genSayisi; // Kromozom uzunluğu
    
    void yeniGenEkle(char genDegeri);//Kromozoma gen ekleme
    void kromozomEkranaYazdir() const; // Kromozomdaki genleri yazdırır
    void caprazlananKromozomuBirlestirme(Kromozom* hedef, int baslangicGeni, int bitisGeni) ; // Belirtilen gen aralığını kopyalar


};
#endif
