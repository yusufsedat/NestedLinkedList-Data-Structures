/** 
* @file yoneticiListesiDugum.cpp
* @description   Yönetici Listesinin düğümlerini oluşturan yer.
* @course   1.Öğretim B grubu
* @assignment   1.Ödev
* @date   20.11.2022
* @author   Yusuf Sedat Sağaltıcı  yusuf.sagaltici@ogr.sakarya.edu.tr
*/





#include "../include/yoneticiListesiDugum.hpp"

YoneticiListesiDugum::YoneticiListesiDugum(double ortalama)
{
	this->sonrakiDugum = NULL;
	this->oncekiDugum = NULL;
	this->ortalama = ortalama;
}

void	YoneticiListesiDugum::ortalamaHesapla()
{
	SatirListesiDugum *geciciDugum = this->satirListesi->ilkDugumuCagir();
	double toplam = 0;
	int sayac = 0;
	while (geciciDugum != NULL)
	{
		toplam += geciciDugum->sayiCagir();
		sayac++;
		geciciDugum = geciciDugum->sonrakiDugumuCagir();
	}
	this->ortalama = toplam / sayac;
}

void	YoneticiListesiDugum::satirListesiDegistir(SatirListesi *satirListesi)
{
	this->satirListesi = satirListesi;
}


YoneticiListesiDugum::~YoneticiListesiDugum()
{
	delete this->satirListesi;
}

YoneticiListesiDugum *YoneticiListesiDugum::sonrakiDugumuCagir()
{
	return this->sonrakiDugum;
}

void	YoneticiListesiDugum::oncekiDugumuDegistir(YoneticiListesiDugum *oncekiDugum)
{
	this->oncekiDugum = oncekiDugum;
}

YoneticiListesiDugum *YoneticiListesiDugum::oncekiDugumuCagir()
{
	return this->oncekiDugum;
}

double YoneticiListesiDugum::ortalamaCagir()
{
	return this->ortalama;
}

void	YoneticiListesiDugum::sonrakiDugumuDegistir(YoneticiListesiDugum *sonrakiDugum)
{
	this->sonrakiDugum = sonrakiDugum;
}


void YoneticiListesiDugum::ortalamaDegistir(double ortalama)
{
	this->ortalama = ortalama;
}

SatirListesi	*YoneticiListesiDugum::satirListesiCagir()
{
	return this->satirListesi;
}
