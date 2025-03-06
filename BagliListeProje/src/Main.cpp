/**
* @File Dna.cpp
* @description Switch case yapısı ile menü yazıldı.
* @course 2.Öğretim C GRUBU
* @assignment 1.ÖDEV
* @Date 26.11.2024
* @Author PETEK İREM HIZLI petek.hizli@ogr.sakarya.edu.tr
*/
#include <iostream>
#include "Dna.hpp"
using namespace std;
int main() {
    int secim = 0;
    Dna *dna = new Dna();
    dna->dosyadanOku("Dna.txt");

    do {
        std::cout << "-------Menu:------\n";
        std::cout << "1- Caprazlama Yap\n";
        std::cout << "2- Mutasyon Yap\n";
        std::cout << "3- Otomatik Islemler\n";
        std::cout << "4- Ekrana Yazdir\n";
        std::cout << "5- Cikis\n";
        std::cout<< "--------------------\n";
        std::cout << "Seciminizi yapin: ";
        std::cin >> secim;

        switch (secim) {
            case 1:
            int satir1,satir2;
                cout << "Caprazlama islemi secildi.\n";
                cout << "Caprazlama icin iki kromozom satir numarasi girin (0'dan baslar):"<<endl;
                cout<< "Caprazlanacak ilk kromozomun satir numarasi:";
                cin>> satir1;
                cout<< "Caprazlanacak ikinci kromozomun satir numarasi:";               
                cin>> satir2;
            
                dna->caprazlamaYap(satir1,satir2);
                cout<<"Caprazlama yapildi.\n";
                
                break;
            case 2:
                cout << "Mutasyon islemi secildi.\n";
                int kromozomSatir, genSutun;
                cout << "Mutasyona ugrayacak kromozomun satir numarasi girin: ";
                cin >> kromozomSatir;
                cout << "Mutasyona ugrayacak kromozomun sutun(gen) numarasini girin: ";
                cin >> genSutun;

                // Mutasyonu uğratma
                dna->mutasyonaUgrat(kromozomSatir,genSutun);
                cout <<"Mutasyon islemi yapildi."<< endl;
                
                break;
            case 3:
                cout << "Otomatik islemler secildi.\n";
                // Otomatik işlemleri uygulama
                dna->otomatikIslemleriUygula("Islemler.txt");

                // Sonucu ekrana yazdır
                cout << "Islemler tamamlandi.\n";

                break;
             case 4:
                cout << "Ekrana sirali sekilde yazma islemini secildi.\n";
                // Sıralayarak yazdırma işlemini başlatıyoruz
                dna->kromozomunEnKucukGeniniYazdir();
                cout << endl;
                break;
            case 5:
                cout << "Programdan cikiliyor.\n";
                break;
            default:
                cout << "Gecersiz secim. Lutfen tekrar deneyin.\n";
        }
    } while (secim != 5);
    delete dna;
    return 0;
}
