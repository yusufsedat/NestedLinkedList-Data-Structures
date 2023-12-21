
#ifndef YONETICI_LISTESI_HPP
#define YONETICI_LISTESI_HPP

#include "yoneticiListesiDugum.hpp"
#include <fstream>
#include <stdlib.h>
#include <time.h>

class YoneticiListesi
{
	private:
		YoneticiListesiDugum *ilk;
		std::string *satirlar;
		double *ortalamalar;
		int satirSayisi;

	public:
		YoneticiListesi();
		~YoneticiListesi();
		YoneticiListesiDugum *ilkDugumuCagir();
		void ilkDugumuDegistir(YoneticiListesiDugum *ilk);
		double *ortalamalariCagir();
		int *satirDugumuSil(int k, int index, int sayfaIndex, int toplam);
		int satirSayisiniCagir();
		void ortalamaHesapla();
		std::string *satiriBol(std::string satir);
		void listeOlustur();
		void dosyadanOku(std::string dosyaAdi);
		void baslikYazdir(int index, int sayfaIndex, int toplam);
		void listeYazdir(int index, int sayfaIndex, int toplam, int k);
		void yazdir(std::string tip, int sayfaIndex);
		void sirala();
		void dugumSil(int index, int sayfaIndex);
		int	 rastgeleDugumSec(int index, int sayfaIndex);
};



#endif