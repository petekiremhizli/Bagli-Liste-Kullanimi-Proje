/**
* @File Dna.cpp
* @description Kromozom sınıfının yapıcı ve yıkıcı fonksiyonu, kromozoma gen ekleme fonksiyonu, kromozom çaprazlamaya yardımcı olan fonksiyon yazıldı.
* @course 2.Öğretim C GRUBU
* @assignment 1.ÖDEV
* @Date 26.11.2024
* @Author PETEK İREM HIZLI petek.hizli@ogr.sakarya.edu.tr
*/
#include "Kromozom.hpp"
#include <iostream>
using namespace std;

Kromozom::Kromozom(){
    this->baslangic= nullptr;//ilk kromozom
    this->son = nullptr;//son kromozom
    this->genSayisi = 0;//kromozom uzunluğu
    this->onceki=nullptr;
    this->sonraki=nullptr;
}

Kromozom::~Kromozom() {
    Gen* gecici = baslangic;
    while (gecici) {
        Gen* sil = gecici;
        gecici = gecici->sonraki;  // Sonraki gene geç
        delete sil;                // Gen nesnesini serbest bırak
    }
    baslangic = nullptr;  // İşaretçileri sıfırla
    son = nullptr;
}


// Kromozom bağlı listemize gen ekler
void Kromozom::yeniGenEkle(char genDegeri) {
    Gen* yeniGen = new Gen(genDegeri);
    if (!baslangic) {  // Eğer kromozomda hiç gen yoksa
        baslangic = son = yeniGen;
    } else {
        son->sonraki = yeniGen;  // Son gene yeni geni bağla
        yeniGen->onceki = son;   // Yeni genin öncekisini bağla
        son = yeniGen;           // Yeni geni son olarak ata
    }
    genSayisi++;
}

// Belirtilen satırlardaki kromozomları başka bir kromozomda bir araya getirir
void Kromozom::caprazlananKromozomuBirlestirme(Kromozom* hedef, int baslangicGeni, int bitisGeni)  {
    int sayac = 0;
    Gen* gecici = baslangic;
    while (gecici != nullptr) {
        if (sayac >= baslangicGeni && sayac < bitisGeni) {
            hedef->yeniGenEkle(gecici->genDegeri);
        }
        gecici = gecici->sonraki;
        sayac++;
    }
}

