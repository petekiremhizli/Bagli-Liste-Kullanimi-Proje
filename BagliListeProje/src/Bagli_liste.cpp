/**
* @file           Bagli_liste.cpp / G231210030
* @description    Agaclar.txtdeki verilelerle oluşturulan ağaçları bağlı listeye ekleme, ekrana çizgi çizme ve ağaç düğümü adreslerini ve
*                 verilerini ekrana yazdırma işlemleri yapıldı.
* @course         2. Öğretim C Grubu
* @assignment     2. Ödev
* @date           20.12.2024
* @author          Petek İrem Hızlı petek.hizli@ogr.sakarya.edu.tr
*/

#include "../include/Bagli_liste.hpp"
#include "../include/Agac.hpp"
#include <cstdlib>  // system("cls") için
#include <iomanip>
Dugum::Dugum(Agac* agac)  {
    this->agac=agac;
    this->sonraki=nullptr;
}

BagliListe::BagliListe() {
    this->ilkDugum=nullptr;
}

BagliListe::~BagliListe() {
    Dugum* simdiki = ilkDugum;
    while (simdiki != nullptr) {
        Dugum* silinecek = simdiki;
        simdiki = simdiki->sonraki;
        delete silinecek->agac;
        delete silinecek;
    }
}

void BagliListe::listeyeAgacEkle(Agac* yeniAgac) {
    Dugum* yeniDugum = new Dugum(yeniAgac);

    // Eğer liste boşsa, ilk düğüm olarak ekle
    if (ilkDugum == nullptr) {
        ilkDugum = yeniDugum;
    } else {
        // Listenin sonuna kadar ilerle
        Dugum* simdiki = ilkDugum;
        while (simdiki->sonraki != nullptr) {
            simdiki = simdiki->sonraki;
        }
        // Yeni düğümü listenin sonuna ekle
        simdiki->sonraki = yeniDugum;
    }
}


void BagliListe::cizgiCiz(int sayi) {
    for (int i = 0; i < sayi; i++) {
        cout << "*********   ";
    }
    cout << endl; // Çizgiden sonra bir alt satıra geç
}

void BagliListe::dugumVeSonrakiAdresleriniYazdir() {
    Dugum* simdiki = ilkDugum;
    int toplamDugum = 0;

    // Bağlı listedeki toplam düğüm sayısını bulma
    while (simdiki != nullptr) {
        toplamDugum++;
        simdiki = simdiki->sonraki;
    }

    // İşlem yapmak için gerekli değişkenler
    simdiki = ilkDugum;
    int gorunenBaslangic = 1;
    int gorunenAdet = 10;
    int index = 1;

    while (true) {
        system("cls");  // Ekranı temizle
        //1.
        cizgiCiz(gorunenAdet);

        // 2. satır: Düğüm adreslerini yazdır
        Dugum* temp = ilkDugum;
        for (int i = 1; temp != nullptr && i <= toplamDugum; i++) {
            if (i >= gorunenBaslangic && i < gorunenBaslangic + gorunenAdet) {
                cout << temp << "   ";  // Düğüm adresini yazdır
            }
            temp = temp->sonraki;
        }
        cout << endl;

        // 3. satır: Çizgi çiz
        cizgiCiz(gorunenAdet);
       

        //4.satır
        temp = ilkDugum;
        for (int i = 1; temp != nullptr && i <= toplamDugum; i++) {
        if (i >= gorunenBaslangic && i < gorunenBaslangic + gorunenAdet) {
        if (temp->agac != nullptr) {
         cout << setw(9) << temp->agac->toplamDegerHesapla()<< "   " ;  // Toplam değeri 9 boşluk kaplayacak şekilde yazdır
        } else {
            cout << setw(9) << "0";  // Eğer ağaç boşsa 0 yazdır
        }
    }
        temp = temp->sonraki; }
        cout << endl;

        cizgiCiz(gorunenAdet);
        // 5. satır: Sonraki düğüm adreslerini yazdır
        temp = ilkDugum;
        for (int i = 1; temp != nullptr && i <= toplamDugum; i++) {
            if (i >= gorunenBaslangic && i < gorunenBaslangic + gorunenAdet) {
                if (temp->sonraki != nullptr) {
                    cout << temp->sonraki << "   ";  // Sonraki düğüm adresini yazdır
                } else {
                    cout << "0   ";  // Eğer son düğümdeyse
                }
            }
            temp = temp->sonraki;
        }
        cout << endl;

        // 6. satır: Çizgi çiz
        cizgiCiz(gorunenAdet);

        // Beşinci satır: Gösterici işaretlerini yazdır (Oklar)
        for (int i = gorunenBaslangic; i < gorunenBaslangic + gorunenAdet; i++) {
            if (i == index) {
                cout << "^^^^^^^^^   ";  // Geçerli düğüm işaretçisini yazdır
            } else {
                cout << "            ";  // Boşluk bırak
            }
        }
        cout << endl;

       // Seçili düğümün ağacını çizdir
        if (simdiki != nullptr && simdiki->agac != nullptr) {
            cout << "\nSecili dugumun agaci:\n";
             simdiki->agac->agacCiz(); // Ağacı çizdir
}

        // Kullanıcı girdisini al ve işle
        if (!kullaniciGirdisiniIsle(toplamDugum, gorunenBaslangic, gorunenAdet, index)) {
            break;  // Çıkış yap
        }

        // Seçili düğümü güncelle
        Dugum* yeniSimdiki = ilkDugum;
        for (int i = 1; i < index; i++) {
            if (yeniSimdiki != nullptr) {
                yeniSimdiki = yeniSimdiki->sonraki;
            }
        }
        simdiki = yeniSimdiki;
    }
}
// Ağaç ve düğüm verilerini silme
void BagliListe::silDugum(int index) {
    if (index == 1) {
        // İlk düğüm siliniyor
        Dugum* temp = ilkDugum;
        ilkDugum = ilkDugum->sonraki;
        delete temp->agac;  // Ağacı sil
        delete temp;
    } else {
        // Orta veya son düğüm siliniyor
        Dugum* onceki = nullptr;
        Dugum* simdiki = ilkDugum;
        for (int i = 1; i < index; i++) {
            onceki = simdiki;
            simdiki = simdiki->sonraki;
        }
        if (onceki != nullptr && simdiki != nullptr) {
            onceki->sonraki = simdiki->sonraki;
            delete simdiki->agac;  // Ağacı sil
            delete simdiki;
        }
    }
}
// Kullanıcı girisi alma ve işleme
bool BagliListe::kullaniciGirdisiniIsle(int toplamDugum, int& gorunenBaslangic, int& gorunenAdet, int& index) {
    char secim;
    cout << "\nGezinmek icin 'd' (ileri), 'a' (geri), 's' (silme), 'w' (aynalama), 'q' (cikis): ";
    cin >> secim;
    

    if (secim == 'd' && index < toplamDugum) {
        index++;
        if (index >= gorunenBaslangic + gorunenAdet) {
            if (gorunenAdet == 10) {
                gorunenBaslangic += 10;
                gorunenAdet = 5;
            } else {
                gorunenBaslangic += 5;
            }
        }
    }
    else if (secim == 's') {
        // Seçili düğümü sil
        if (toplamDugum > 0) {
            silDugum(index);  // Düğümü sil
            toplamDugum--;    // Toplam düğüm sayısını güncelle

            // Eğer geçerli index toplam düğümden büyükse, bir önceki düğüme git
            if (index > toplamDugum) {
                index = toplamDugum;
            }

            // Eğer tüm düğümler silindiyse çıkış yap
            if (toplamDugum == 0) {
                return false;
            }
        }
        }
         else if (secim == 'a' && index > 1) {
        index--;
        if (index < gorunenBaslangic) {
            if (gorunenAdet == 5 && gorunenBaslangic > 10) {
                gorunenBaslangic -= 10;
                gorunenAdet = 10;
            } else {
                gorunenBaslangic -= 5;
            }
        }
    } else if (secim == 'w') {
        // Seçili düğümdeki ağacı aynala
        Dugum* simdiki = ilkDugum;
        for (int i = 1; i < index; i++) {
            if (simdiki != nullptr) simdiki = simdiki->sonraki;
        }
        if (simdiki != nullptr && simdiki->agac != nullptr) {
            simdiki->agac->aynaYap();  // Aynalama işlemi
        }
    } else if (secim == 'q') {
        return false;  // Çıkış yap
    }

    if (index < 1) index = 1;
    if (index > toplamDugum) index = toplamDugum;

    return true;  // Döngüye devam
}





   



    


