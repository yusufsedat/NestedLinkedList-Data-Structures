#ifndef YONETICI_LISTESI_DUGUM_HPP
#define YONETICI_LISTESI_DUGUM_HPP

#include "satirListesi.hpp"
#include <iostream>

class YoneticiListesiDugum
{
	private:
		YoneticiListesiDugum *oncekiDugum;
		YoneticiListesiDugum *sonrakiDugum;
		SatirListesi *satirListesi;
		double ortalama;
	public:
		YoneticiListesiDugum(double ortalamalar);
		~YoneticiListesiDugum();
		YoneticiListesiDugum *sonrakiDugumuCagir();
		YoneticiListesiDugum *oncekiDugumuCagir();
		double ortalamaCagir();
		void ortalamaDegistir(double ortalama);
		SatirListesi	*satirListesiCagir();
		void	satirListesiDegistir(SatirListesi *satirListesi);
		void	ortalamaHesapla();
		void sonrakiDugumuDegistir(YoneticiListesiDugum *sonrakiDugum);
		void oncekiDugumuDegistir(YoneticiListesiDugum *oncekiDugum);
};

#endif