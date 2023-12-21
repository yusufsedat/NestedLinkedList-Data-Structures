#ifndef SATIR_LISTESI_HPP
#define SATIR_LISTESI_HPP

#include "satirListesiDugum.hpp"
#include <iostream>
#include <iomanip>

class SatirListesi
{
	private:
		SatirListesiDugum *ilk;
	public:
		SatirListesi(std::string satir);
		~SatirListesi();
		void yazdir(std::string tip, int index, void *veri, int sayi, int k, int j);
		SatirListesiDugum *ilkDugumuCagir();
		void sayiyiOrtala(int sayi);
		void ilkDugumuDegistir(SatirListesiDugum *ilk);
		std::string *satiriBol(std::string satir);
		void satirListesiYazdir(int index, int k);
};

#endif