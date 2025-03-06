#ifndef AGAC_H
#define AGAC_H

class AgacDugumu {
public:
    char veri;       // Düğümdeki karakter
    AgacDugumu* sol; // Sol çocuk
    AgacDugumu* sag; // Sağ çocuk    
    AgacDugumu(char veri);
    ~AgacDugumu();
};

class Agac {
    public:
    AgacDugumu* kok;
    Agac();      
    ~Agac();              
    // Ağaca veri ekleme      
    void agacOlustur(char veri); 
    AgacDugumu* ekle(AgacDugumu* dugum, char veri);
   // Agacı cizme
    void agacCiz() ;
    void cizDugumler(AgacDugumu* dugum, char goster[][200], int satir, int sutun, int bosluk) ;
    
    int hesapla(AgacDugumu* dugum, bool solCocukMu);
    int toplamDegerHesapla() ;   
    
    void aynaYap() ;
    void aynaYap(AgacDugumu* dugum);


};

#endif
