#ifndef SATIR_LISTESI_DUGUM_HPP
#define SATIR_LISTESI_DUGUM_HPP

#include <iostream>

class SatirListesiDugum
{
	private:
		SatirListesiDugum *oncekiDugum;
		SatirListesiDugum *sonrakiDugum;
		int sayi;
	public:
		SatirListesiDugum(int sayi);
		~SatirListesiDugum();
		SatirListesiDugum *sonrakiDugumuCagir();
		void sonrakiDugumuDegistir(SatirListesiDugum *sonrakiDugum);
		SatirListesiDugum *oncekiDugumuCagir();
		void oncekiDugumuDegistir(SatirListesiDugum *oncekiDugum);
		int sayiCagir();
		void sayiDegistir(int sayi);
};

#endif