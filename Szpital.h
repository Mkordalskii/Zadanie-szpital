#pragma once
#include "Pacjent.h"
#include <vector>
class Szpital
{
private:
	int maxPacjentow;
	std::vector<Pacjent> listaPacjentow;
public:
	Szpital();
	Szpital(int maxPacjentow)
		:maxPacjentow(maxPacjentow)
	{}
	int getMaxPacjentow() const
	{
		return maxPacjentow;
	}
	void setMaxPacjentow(int maxPacjentow)
	{
		this->maxPacjentow = maxPacjentow;
	}
	void wyswietl() const 
	{
		std::cout<< std::endl << "Maksymalna liczba pacjentow: " << maxPacjentow;
		std::cout<< std::endl << "Aktualna liczba pacjentow w szpitalu: " << listaPacjentow.size();
		std::cout << std::endl << "Lista pacjentow:" << std::endl;
		for (const auto& pacjent : listaPacjentow)
		{
			pacjent.wyswietl();
		}
	}
	void wyswietlPacjentowZoddzialu(const std::string &oddzial) const
	{
		std::cout << std::endl << "Lista pacjentów z oddzialu " << oddzial << " : " << std::endl;
		for (const auto& pacjent : listaPacjentow)
		{
			if (pacjent.sprawdzOddzial(oddzial))
			{
				pacjent.wyswietl();
			}
		}
	}
	double zwrocSredniaDniPobytu() const
	{
		int suma = 0;
		for (const auto& pacjent : listaPacjentow)
		{
			suma += pacjent.getLiczbaDniPobytu();
		}
		return suma / listaPacjentow.size();
	}
	void dodajPacjenta(const Pacjent &pacjent)
	{
		listaPacjentow.push_back(pacjent);
	}
	int zwrocNajPobyt() const
	{
		int najdluzszy = listaPacjentow[0].getLiczbaDniPobytu();
		for (const auto& pacjent : listaPacjentow)
		{
			if (pacjent.getLiczbaDniPobytu() > najdluzszy)
				najdluzszy = pacjent.getLiczbaDniPobytu();
		}
		return najdluzszy;
	}
	int zwrocIlePowyzejWieku(const int &wiek) const
	{
		int i = 0;
		for (const auto& pacjent : listaPacjentow)
		{
			if (pacjent.getWiek() > wiek)
			{
				i++;
			}
		}
		return i;
	}
};
