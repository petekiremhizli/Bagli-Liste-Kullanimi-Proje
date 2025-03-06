#ifndef GEN_HPP
#define GEN_HPP

class Gen{
    public:
    char genDegeri;
    Gen* sonraki;
    Gen* onceki;
    Gen(char genDegeri); 
};
#endif