#pragma once
#include <iostream>
class Pacjent
{
private:
	std::string imie, nazwisko, pesel, nazwaOddzialu;
	int wiek, liczbaDniPobytu = 0;
public:
	Pacjent(std::string imie, std::string nazwisko, std::string pesel, std::string nazwaOddzialu, int liczbaDniPobytu, int wiek)
		:imie(imie), nazwisko(nazwisko), pesel(pesel), nazwaOddzialu(nazwaOddzialu), liczbaDniPobytu(liczbaDniPobytu), wiek(wiek)
	{};
	bool sprawdzCzyPowyzej(int dniPobytu)
	{
		return liczbaDniPobytu > dniPobytu;
	}
	int getLiczbaDniPobytu() const
	{
		return liczbaDniPobytu;
	}
	int getWiek() const
	{
		return wiek;
	}
	std::string getPesel() const
	{
		return pesel;
	}
	void dodajKolejnyDzien()
	{
		liczbaDniPobytu++;
	}
	bool sprawdzOddzial(const std::string &sprawdzanaNazwaOddzialu) const
	{
		return sprawdzanaNazwaOddzialu == nazwaOddzialu;
	}
	void wyswietl() const 
	{
		std::cout << std::endl << "Imie: " << imie;
		std::cout << std::endl << "Nazwisko: " << nazwisko;
		std::cout << std::endl << "Wiek: " << wiek;
		std::cout << std::endl << "PESEL: " << pesel;
		std::cout << std::endl << "Nazwa oddzialu: " << nazwaOddzialu;
		std::cout << std::endl << "Liczba dni pobytu: " << liczbaDniPobytu;
	}

};