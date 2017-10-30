#ifndef SygnalLoader_HPP
#define SygnalLoader_HPP
#include "sygnal.HPP"
#include <string>

class Loader
{
public:
    Loader();
    Sygnal wczytaj(std::string nazwa_pliku);
    void zapiszSygnal(Sygnal& sygnal,std::string nazwa_pliku);

};


#endif // Loader_HPP
