/**
* @File Dna.cpp
* @description Gen classının yapıcı fonksiyonu yazıldı.
* @course 2.Öğretim C GRUBU
* @assignment 1.ÖDEV
* @Date 26.11.2024
* @Author PETEK İREM HIZLI petek.hizli@ogr.sakarya.edu.tr
*/
#include "Gen.hpp"

Gen::Gen(char genDegeri){
    this->genDegeri=genDegeri;
    this->sonraki=nullptr;
    this->onceki = nullptr;
}


