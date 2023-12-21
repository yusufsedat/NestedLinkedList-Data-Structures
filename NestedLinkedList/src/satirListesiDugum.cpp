
/** 
* @file satirListesiDugum.cpp
* @description   Satır Listesinin düğümlerini oluşturan yer.
* @course   1.Öğretim B grubu
* @assignment   1.Ödev
* @date   20.11.2022
* @author   Yusuf Sedat Sağaltıcı  yusuf.sagaltici@ogr.sakarya.edu.tr
*/






#include "../include/satirListesiDugum.hpp"

SatirListesiDugum *SatirListesiDugum::sonrakiDugumuCagir()
{
	return this->sonrakiDugum;
}

SatirListesiDugum::SatirListesiDugum(int sayi)
{
	this->sonrakiDugum = NULL;
	this->oncekiDugum = NULL;
	this->sayi = sayi;
}

SatirListesiDugum *SatirListesiDugum::oncekiDugumuCagir()
{
	return this->oncekiDugum;
}

void	SatirListesiDugum::oncekiDugumuDegistir(SatirListesiDugum *oncekiDugum)
{
	this->oncekiDugum = oncekiDugum;
}

void	SatirListesiDugum::sonrakiDugumuDegistir(SatirListesiDugum *sonrakiDugum)
{
	this->sonrakiDugum = sonrakiDugum;
}

void SatirListesiDugum::sayiDegistir(int sayi)
{
	this->sayi = sayi;
}

SatirListesiDugum::~SatirListesiDugum()
{
	this->sonrakiDugum = NULL;
	this->oncekiDugum = NULL;
	this->sayi = 0;
}

int SatirListesiDugum::sayiCagir()
{
	return this->sayi;
}