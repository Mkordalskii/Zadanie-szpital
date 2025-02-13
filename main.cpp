#include "Pacjent.h"
#include "Szpital.h"
#include <vector>
int main() {
	std::vector<Pacjent> listaPacjentow;
	listaPacjentow.emplace_back("Pacjent1", "Pacjent1", "111111111", "oddzial1", 1, 50);
	listaPacjentow.emplace_back("Pacjent2", "Pacjent2", "222222222", "oddzial2", 2, 60);
	listaPacjentow.emplace_back("Pacjent3", "Pacjent3", "333333333", "oddzial3", 3, 70);
	listaPacjentow[2].dodajKolejnyDzien();

	Szpital szpital1(10);

	for (const auto& pacjent : listaPacjentow)
	{
		szpital1.dodajPacjenta(pacjent);
	}
	szpital1.wyswietl();
	std::cout << std::endl <<"Srednia liczba dni pobytu: " << szpital1.zwrocSredniaDniPobytu();
	std::cout << std::endl <<"Ilu jest pacjentow powyzej podanego wieku: " << szpital1.zwrocIlePowyzejWieku(65);
	
	int najdluzszyPobyt = szpital1.zwrocNajPobyt(); // Pobierz maksymaln¹ liczbê dni pobytu
	std::cout<< std::endl << "PESELe pacjentow przebywajacych najdluzej w szpitalu (" << najdluzszyPobyt << " dni):" << std::endl;

	for (const auto& pacjent : listaPacjentow) {
		if (pacjent.getLiczbaDniPobytu() == najdluzszyPobyt) {
			std::cout << pacjent.getPesel() << std::endl; // Wyœwietl PESEL pacjenta
		}
	}
	return 0;
}