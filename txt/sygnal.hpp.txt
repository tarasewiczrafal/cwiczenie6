#ifndef sygnal_HPP
#define sygnal_HPP
#include <iostream>
#include <string>
#include <vector>
#include "probka.HPP"
#include "SygnalLoader.HPP"
#include "AnalizatorSygnalu.HPP"
class Sygnal{
std::vector<Probka> probki;
public:
    Sygnal();
    void dodajProbke(const Probka& p);
    int iloscProbek();
    Probka& operator[](int i);
    friend std::ostream& operator<< (std::ostream& stream, const Sygnal& sygnal);
};
