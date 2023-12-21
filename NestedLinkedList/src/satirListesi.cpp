/** 
* @file satirListesi.cpp
* @description   Satır Listesinin ve genel yapının (çizgiler vs.) yapıldığı yer.
* @course   1.Öğretim B grubu
* @assignment   1.Ödev
* @date   20.11.2022
* @author   Yusuf Sedat Sağaltıcı  yusuf.sagaltici@ogr.sakarya.edu.tr
*/





#include "../include/satirListesi.hpp"

SatirListesi::SatirListesi(std::string satir)
{
	int i = 0;
	std::string *sayilar = this->satiriBol(satir);
	this->ilk = NULL;
	while (sayilar[i] != "")
	{
		SatirListesiDugum *yeniDugum = new SatirListesiDugum(std::stoi(sayilar[i]));
		if (this->ilk == NULL)
			this->ilk = yeniDugum;
		else
		{
			SatirListesiDugum *gecici = this->ilk;
			while (gecici->sonrakiDugumuCagir() != NULL)
				gecici = gecici->sonrakiDugumuCagir();
			gecici->sonrakiDugumuDegistir(yeniDugum);
			gecici->sonrakiDugumuCagir()->oncekiDugumuDegistir(gecici);
		}
		i++;
	}
	delete[] sayilar;
}

void	SatirListesi::satirListesiYazdir(int index, int k)
{
	int j = 0;
	std::cout<<"\n";
	for (int i = 0; i < index; i++)
		printf("%20s", " ");
	std::cout<<"^^^^^^^^^^\n";
	SatirListesiDugum *gecici = this->ilk;
	while (gecici != NULL)
	{
		this->yazdir("adres", index, gecici, 0, k, j);
		this->yazdir("-", index, NULL, 0, k, j);
		this->yazdir("sayi", index, NULL, gecici->sayiCagir(), k, j);
		this->yazdir("-", index, NULL, 0, k, j);
		this->yazdir("sonraki", index, gecici->sonrakiDugumuCagir(), 0, k, j);
		this->yazdir("-", index, NULL, 0, k, j);
		std::cout<<"\n";
		gecici = gecici->sonrakiDugumuCagir();
		j++;
	}
}

SatirListesi::~SatirListesi()
{
	SatirListesiDugum *gecici = ilk;
	while(ilk != NULL)
	{
		ilk = ilk->sonrakiDugumuCagir();
		delete gecici;
		gecici = ilk;
	}
}

SatirListesiDugum *SatirListesi::ilkDugumuCagir()
{
	return this->ilk;
}

void	SatirListesi::ilkDugumuDegistir(SatirListesiDugum *ilk)
{
	this->ilk = ilk;
}

void	SatirListesi::sayiyiOrtala(int sayi)
{
	int gecici = sayi;
	int tek = 1;
	int basamak = 0;
	int boslukSayisi;

	while (sayi > 0)
	{
		sayi /= 10;
		basamak++;
	}
	boslukSayisi = 8 - basamak;
	if (basamak % 2 == 0)
		tek = 0;
	std::cout<<"|";
	for (int i = 0; i < boslukSayisi / 2 + tek; i++)
		std::cout<<" ";
	std::cout<<gecici;
	for (int i = 0; i < boslukSayisi / 2; i++)
		std::cout<<" ";
	std::cout<<"|";
}

std::string *SatirListesi::satiriBol(std::string satir)
{
	std::string *sayilar;
	size_t pos = 0;	
	std::string satirKopyasi = satir;
	int i = 0;
	while ((pos = satirKopyasi.find(" ")) != std::string::npos)
	{
		i++;
		satirKopyasi.erase(0, pos + 1);
	}
	sayilar = new std::string[i + 1];
	i = 0;
	while ((pos = satir.find(" ")) != std::string::npos)
	{
		sayilar[i] = satir.substr(0, pos);
		satir.erase(0, pos + 1);
		i++;
	}
	sayilar[i] = "";
	return (sayilar);
}

void	SatirListesi::yazdir(std::string tip, int index, void *veri, int sayi, int k, int dugumIndex)
{
	for (int i = 0; i < index; i++)
		printf("%20s", " ");
	if (tip == "adres")
		printf(" %08X \n", veri);
	else if (tip == "sayi")
	{
		sayiyiOrtala(sayi);
		if (k < 0 && dugumIndex == -(k + 1))
			std::cout<<"     <--secilen dugum\n";
		else
			std::cout<<"\n";
	}
	else if (tip == "sonraki")
		printf("|%08X|\n", veri);
	else if ("-")
		std::cout<<"----------\n",veri;
}
