/**
* @file           Agac.cpp / G231210030
* @description    Agaclar.txtdeki verilelerle ağaç oluşturma, ekleme, çizme, ağaç verisi hesaplama ve aynalama işlemleri yapıldı.
* @course         2. Öğretim C Grubu
* @assignment     2. Ödev
* @date           20.12.2024
* @author          Petek İrem Hızlı petek.hizli@ogr.sakarya.edu.tr
*/
#include "../include/Agac.hpp"
#include "../include/Bagli_liste.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

AgacDugumu::AgacDugumu(char veri) {
    this->sag=nullptr;
    this->sol=nullptr;
    this->veri=veri;
}
AgacDugumu::~AgacDugumu() {
    delete sol;  // Sol alt düğümü sil
    delete sag;  // Sağ alt düğümü sil
}

Agac::Agac(){
this->kok=nullptr;
}

Agac::~Agac() {
    delete kok;
}

void Agac::agacOlustur(char veri) {
    kok = ekle(kok, veri);
}

AgacDugumu* Agac::ekle(AgacDugumu* dugum, char veri) {
    if (!dugum) {
        return new AgacDugumu(veri);
    }
    if (veri < dugum->veri) {
        dugum->sol = ekle(dugum->sol, veri);
    } else {
        dugum->sag = ekle(dugum->sag, veri);
    }
    return dugum;
}
   
void Agac::agacCiz() {
    if (kok == nullptr) {
        std::cout << "Ağaç boş.\n";
        return;
    }

    const int MAX_SATIR = 50; // Maksimum satır sayısı (ağacın derinliğine göre ayarlanabilir)
    const int MAX_SUTUN = 200; // Maksimum sütun sayısı (ağacın genişliğine göre ayarlanabilir)
    char goster[MAX_SATIR][MAX_SUTUN];

    // Ekranı boşluklarla doldur
    for (int i = 0; i < MAX_SATIR; i++) {
        for (int j = 0; j < MAX_SUTUN; j++) {
            goster[i][j] = ' ';
        }
    }

    // Ağacı çizmek için yardımcı fonksiyonu çağır
    int kokSutun = MAX_SUTUN / 4; // Kök düğümü ekranın biraz daha soluna yerleştir
    cizDugumler(kok, goster, 0, kokSutun, kokSutun / 2);

    // Ekranı yazdır
    for (int i = 0; i < MAX_SATIR; i++) {
        bool bosSatir = true;
        for (int j = 0; j < MAX_SUTUN; j++) {
            if (goster[i][j] != ' ') bosSatir = false;
            cout << goster[i][j];
        }
        cout << '\n';
        if (bosSatir) break; // Boş satıra ulaştıysak erken çık
    }
}

void Agac::cizDugumler(AgacDugumu* dugum, char goster[][200], int satir, int sutun, int bosluk) {
    if (dugum == nullptr || satir >= 50 || sutun < 0 || sutun >= 200) return;

    // Mevcut düğümü yerleştir
    goster[satir][sutun] = dugum->veri;

    // Sol ve sağ çocuklar için çizgiler ekle
    if (dugum->sol) {
        for (int i = 1; i <= bosluk; i++) {
            if (sutun - i >= 0) goster[satir + 1][sutun - i] = '-';
        }
        goster[satir + 1][sutun - bosluk] = '/';
        cizDugumler(dugum->sol, goster, satir + 2, sutun - bosluk, bosluk / 2);
    }
    if (dugum->sag) {
        for (int i = 1; i <= bosluk; i++) {
            if (sutun + i < 200) goster[satir + 1][sutun + i] = '-';
        }
        goster[satir + 1][sutun + bosluk] = '\\';
        cizDugumler(dugum->sag, goster, satir + 2, sutun + bosluk, bosluk / 2);
    }
}


int Agac::toplamDegerHesapla() {
    return hesapla(kok, true); // Kökten başlayarak toplam değeri hesapla
}

int Agac::hesapla(AgacDugumu* dugum, bool solCocukMu) {
    if (dugum == nullptr) {
        return 0;  // Eğer düğüm boşsa, katkısı sıfır
    }

    // Sol ve sağ çocuklar için toplam değerlerini hesapla
    int solToplam = hesapla(dugum->sol, true);  // Sol çocuğa geçerken true gönder
    int sagToplam = hesapla(dugum->sag, false); // Sağ çocuğa geçerken false gönder

    // Mevcut düğümün toplam değerini hesapla
    int toplam = (solCocukMu ? solToplam * 2 : solToplam) + sagToplam + dugum->veri;

    return toplam;
}

void BagliListe::agacToplamlariniHesapla() {
    Dugum* simdiki = ilkDugum;
    int agacIndex = 1;

    while (simdiki != nullptr) {
        if (simdiki->agac != nullptr) {
            int toplam = simdiki->agac->toplamDegerHesapla();
            cout  << toplam << endl;
        } else {
           cout << "Ağaç " << agacIndex << " boş." << std::endl;
        }
        simdiki = simdiki->sonraki;
        agacIndex++;
    }
}

void Agac::aynaYap() {
    aynaYap(kok);  // Kökten itibaren ağacı aynala
}

void Agac::aynaYap(AgacDugumu* dugum) {
    if (dugum == nullptr) return;

    // Sol ve sağ alt ağaçları yer değiştir
    AgacDugumu* temp = dugum->sol;
    dugum->sol = dugum->sag;
    dugum->sag = temp;

    // Alt ağaçları aynala
    aynaYap(dugum->sol);
    aynaYap(dugum->sag);
    
}





















