#ifndef DNA_HPP
#define DNA_HPP
#include "Kromozom.hpp"

class Dna {
    public: 
    Kromozom* baslangic;  // DNA'daki ilk kromozomu tutar
    Kromozom* son;        // DNA'daki son kromozomu tutar
    
    int kromozomSayisi;
    
    Dna();                           // DNA'yı başlatır
   ~Dna();                           // Belleği temizler
    
    void dosyadanOku( const char* dosyaAdi); // Dosyadan genetik veriyi okur
        
    void yeniKromozomEkle(Kromozom* kromozom); // Yeni kromozom ekler
    
    void caprazlamaYap(int satir1,int satir2);
    
    // Belirtilen indeksteki kromozomu döndürür ve bu sayede caprazlama için satır numarsını kullanabiliriz
    Kromozom* kromozomuDondur(int index); 
   
    void mutasyonaUgrat(int genSayisi,int kromozomSatir);
    
    void otomatikIslemleriUygula(const char* dosyaAdi);
    
    //En kücük geni yazdirma
    void kromozomunEnKucukGeniniYazdir();


};
#endif
