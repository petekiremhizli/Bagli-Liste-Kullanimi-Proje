/**
* @File Dna.cpp
* @description Dna yapıcı ve yıkıcısı, bağlı listeye kromozomları ekleme, Dna.txtden veri okuma,girilen satır numarasına göre
  dna.txtden kromozom döndürme, çaprazlama yapma, mutasyon yapma, otomatik işlemleri yapma, kromozomdaki en küçük geni ekrana yazdırma yazıldı.
* @course 2.Öğretim C GRUBU
* @assignment 1.ÖDEV
* @Date 26.11.2024
* @Author PETEK İREM HIZLI petek.hizli@ogr.sakarya.edu.tr
*/

#include "Dna.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Constructor: DNA başlatıcısı
Dna::Dna() { 
    this->baslangic=nullptr;// Dnadaki ilk kromozom
    this->son=nullptr;     //Dnadaki son kromozom
}

// Destructor: DNA'daki tüm kromozomları serbest bırakır
Dna::~Dna() {
    Kromozom* gecici = baslangic;
    while (gecici) {
        Kromozom* sil = gecici;
        gecici = gecici->sonraki;  // Sonraki kromozoma geç
        delete sil;                // Kromozomu serbest bırak
    }
    baslangic = nullptr;  // İşaretçileri sıfırla
    son = nullptr;
}

// Dna bağlı listemize yeni bir kromozom ekler
void Dna::yeniKromozomEkle(Kromozom* kromozom) {
    if (!baslangic) {  // Eğer liste boşsa
        baslangic = son = kromozom;
    } else {
        son->sonraki = kromozom;  // Son kromozomun sonrakisini bağla
        kromozom->onceki = son;  // Yeni kromozomun öncekisini bağla
        son = kromozom;          // Yeni kromozomu son olarak ata
    }
    kromozomSayisi++;
}

// Dosyadan genetik veriyi okur kromozom bağı listesine ekler
void Dna::dosyadanOku(const char* dosyaAdi) {
    ifstream dosya(dosyaAdi);
    if (!dosya.is_open()) {
        cout << "Dosya açilamadi: " << dosyaAdi << endl;
        return;
    }
    string satir;
    while (getline(dosya, satir)) {
        if (satir.empty()) continue; // Boş satırları atla
        Kromozom* yeniKromozom = new Kromozom();  // Yeni kromozom oluştur
        for (char gen : satir) {
            if (gen != ' ') {  // Boşlukları atla
                yeniKromozom->yeniGenEkle(gen);  // Genleri kromozoma ekle
            }
        }
        yeniKromozomEkle(yeniKromozom);  // Kromozomu DNA'ya ekle
    }

    dosya.close();  // Dosyayı kapat

}



//Girilen satır numarasına göre kromozomu bulma
Kromozom* Dna::kromozomuDondur(int index) {
    if (index < 0) {
        cout << "Hata: Geçersiz negatif indeks!" << endl;
        return nullptr;
        }
    int sayac = 0;
    Kromozom* gecici = baslangic;
    while (gecici != nullptr) {
        if (sayac == index) {
            return gecici; // İstenilen indeks bulundu
        }
        gecici = gecici->sonraki;
        sayac++;
    }
    return nullptr; // Eğer liste sonuna kadar gidip indeks bulunmazsa
}

void Dna::caprazlamaYap(int satir1,int satir2){
    
    Kromozom* ilkKromozom= kromozomuDondur(satir1);
    Kromozom* ikinciKromozom=kromozomuDondur(satir2);

    if(!ilkKromozom||!ikinciKromozom){
        cout << "Hatali satir numarasi girdiniz!" << endl;
        return;
    }
    int uzunluk1=ilkKromozom->genSayisi;
    int uzunluk2=ikinciKromozom->genSayisi;

    int ortaNokta1=uzunluk1/2;
    int ortaNokta2=uzunluk2/2;

    //Yeni/çaprazlanmış kromozomları Oluşturma A B C D F
    Kromozom* caprazlananKromozom1 = new Kromozom();
    Kromozom* caprazlananKromozom2 = new Kromozom();
   
 // İlk Kromozomun Solu + İkinci Kromozomun Sağı
    if (uzunluk1 % 2 != 0) { // Eğer tek sayıysa
        ilkKromozom->caprazlananKromozomuBirlestirme(caprazlananKromozom1, 0, ortaNokta1); // Orta dahil değil
    } else {
        ilkKromozom->caprazlananKromozomuBirlestirme(caprazlananKromozom1, 0, ortaNokta1); // Orta dahil
    }

    if (uzunluk2 % 2 != 0) { // Eğer tek sayıysa
        ikinciKromozom->caprazlananKromozomuBirlestirme(caprazlananKromozom1, ortaNokta2+1, uzunluk2); // Orta dahil değil
    } else {
        ikinciKromozom->caprazlananKromozomuBirlestirme(caprazlananKromozom1, ortaNokta2, uzunluk2); // Orta dahil
    }

    // İlk Kromozomun Sağı + İkinci Kromozomun Solu
    if (uzunluk1 % 2 != 0) { // Eğer tek sayıysa
        ilkKromozom->caprazlananKromozomuBirlestirme(caprazlananKromozom2, ortaNokta1 + 1, uzunluk1); // Orta dahil değil
    } else {
        ilkKromozom->caprazlananKromozomuBirlestirme(caprazlananKromozom2, ortaNokta1, uzunluk1); // Orta dahil
    }

    if (uzunluk2 % 2 != 0) { // Eğer tek sayıysa
        ikinciKromozom->caprazlananKromozomuBirlestirme(caprazlananKromozom2, 0, ortaNokta2 ); // Orta dahil değil
    } else {
        ikinciKromozom->caprazlananKromozomuBirlestirme(caprazlananKromozom2, 0, ortaNokta2); // Orta dahil
    }


    yeniKromozomEkle(caprazlananKromozom1);
    yeniKromozomEkle(caprazlananKromozom2);
    cout << "Caprazlama islemi tamamlandi.Yeni kromozomlar bagli listeye eklendi." << endl;

}
 
void Dna::mutasyonaUgrat( int kromozomSatir,int genSutun) {
    // 1. Hedef Kromozomu Bul
    Kromozom* hedefKromozom = kromozomuDondur(kromozomSatir);
    
    if (!hedefKromozom) {
        cout << "Hatali kromozom satir numarasi girdiniz!" << endl;
        return;
    }

    // 2. Kromozomun içindeki genleri gezerek belirtilen sütuna ulaş
    Gen* geciciGen = hedefKromozom->baslangic;
    int sayac = 0;
    
    // Listeyi gezerek hedef genin sütununu bul
    while (geciciGen != nullptr) {
        if (sayac == genSutun) {
            // 3. Hedef Geni Bul
            cout << "Mutasyon uygulaniyor: " << geciciGen->genDegeri << " -> X" << endl;
            geciciGen->genDegeri = 'X';  // Mutasyonu uygula
            return;
        }
        geciciGen = geciciGen->sonraki;  // Sonraki gene geç
        sayac++;
    }
    // Eğer gen bulunamazsa
    cout << "Hatali gen sutun numarasi!" << endl;
}


// Islemler.txt'deki işlemleri uygular
void Dna::otomatikIslemleriUygula(const char* dosyaAdi) {
    ifstream dosya(dosyaAdi);
    if (!dosya.is_open()) {
        cout << "Islemler dosyasi acilamadi!" << endl;
        return;
    }

    char islemTuru;
    int deger1, deger2;

    while (dosya >> islemTuru >> deger1 >> deger2) {
        if (islemTuru == 'C') {
            cout << "Caprazlama islemi: " << deger1 << " ve " << deger2 << endl;
            caprazlamaYap(deger1, deger2);
        }
         else if (islemTuru == 'M') {
            cout << "Mutasyon islemi: Kromozom " << deger1 << ", Gen " << deger2 << endl;
            mutasyonaUgrat(deger1, deger2);
        }
         else {
            cout << "Gecersiz islem: " << islemTuru << endl;
        }
    }

    dosya.close();
    cout << "Tum islemler tamamlandi!" << endl;
}

void Dna::kromozomunEnKucukGeniniYazdir() {
    if (baslangic == nullptr) {
        cout << "Yazdirilacak kromozom yok." << std::endl;
        return;
    }

    Kromozom* geciciKromozom = baslangic;
    while (geciciKromozom != nullptr) {
        
        // İlk genin değeri alınır
        Gen* ilkGen = geciciKromozom->baslangic;
        if (!ilkGen) {
            cout << "Bu kromozomda gen yok." << std::endl;
            geciciKromozom = geciciKromozom->sonraki;
            continue;
        }
        char ilkGenDegeri = ilkGen->genDegeri;

        // Sağdan sola kontrol
        Gen* geciciGen = geciciKromozom->son;  // Sondaki genden başlayarak kontrol edeceğiz
        bool yazdirildi = false;

        // Tüm genleri kontrol et
        while (geciciGen != nullptr) {
            if (geciciGen->genDegeri < ilkGenDegeri) {
                // İlk genden daha küçük bir gen bulundu
                cout << geciciGen->genDegeri<<" ";
                yazdirildi = true;
                break;  // En küçük gen bulundu, çık
            }
            geciciGen = geciciGen->onceki;  // Bir önceki gene geç
        }

        // Eğer küçük bir gen bulunamazsa, ilk gen yazdırılır
        if (!yazdirildi) {
            cout << ilkGenDegeri<<" ";
        }

        geciciKromozom = geciciKromozom->sonraki;  // Sonraki kromozoma geç
    }
}
