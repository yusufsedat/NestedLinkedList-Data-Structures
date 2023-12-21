/** 
* @file yoneticiListesi.cpp
* @description   Yönetici Listesininin genel yapısını oluşturan ve dosyadan okuyan yer.
* @course   1.Öğretim B grubu
* @assignment   1.Ödev
* @date   20.11.2022
* @author   Yusuf Sedat Sağaltıcı  yusuf.sagaltici@ogr.sakarya.edu.tr
*/






#include "../include/yoneticiListesi.hpp"

YoneticiListesi::YoneticiListesi()
{
	this->ilk = NULL;
}

YoneticiListesi::~YoneticiListesi()
{
	YoneticiListesiDugum *gecici = ilk;
	while(ilk != NULL)
	{
		ilk = ilk->sonrakiDugumuCagir();
		delete gecici;
		gecici = ilk;
	}
}

void	YoneticiListesi::ilkDugumuDegistir(YoneticiListesiDugum *ilk)
{
	this->ilk = ilk;
}

YoneticiListesiDugum *YoneticiListesi::ilkDugumuCagir()
{
	return this->ilk;
}

void YoneticiListesi::dosyadanOku(std::string dosyaAdi)
{
	std::ifstream dosya;
	dosya.open(dosyaAdi.c_str());
	if(dosya.is_open())
	{
		std::string satir;
		int satirSayisi = 0;
		while(getline(dosya, satir))
			satirSayisi++;
		dosya.close();
		dosya.open(dosyaAdi.c_str());
		this->satirlar = new std::string[satirSayisi];
		this->ortalamalar = new double[satirSayisi];
		this->satirSayisi = satirSayisi;
		int i = 0;
		while(getline(dosya, satir))
		{
			this->satirlar[i] = satir;
			i++;
		}
		dosya.close();
	}
	else
	{
		std::cout << "Dosya acilamadi." << std::endl;
	}
}

std::string *YoneticiListesi::satiriBol(std::string satir)
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

void YoneticiListesi::ortalamaHesapla()
{
	for (int i = 0; i < this->satirSayisi; i++)
	{
		std::string *sayilar = this->satiriBol(this->satirlar[i]);
		int sayiSayisi = 0;
		while (sayilar[sayiSayisi] != "")
			sayiSayisi++;
		int toplam = 0;
		for (int j = 0; j < sayiSayisi; j++)
			toplam += std::stoi(sayilar[j]);
		this->ortalamalar[i] = toplam / sayiSayisi;
		delete[] sayilar;
	}
}

double *YoneticiListesi::ortalamalariCagir()
{
	return this->ortalamalar;
}

int YoneticiListesi::satirSayisiniCagir()
{
	return this->satirSayisi;
}

void	YoneticiListesi::listeOlustur()
{
	for (int i = 0; i < this->satirSayisi; i++)
	{
		YoneticiListesiDugum *yeniDugum = new YoneticiListesiDugum(this->ortalamalar[i]);
		yeniDugum->satirListesiDegistir(new SatirListesi(this->satirlar[i]));
		if (this->ilk == NULL)
			this->ilk = yeniDugum;
		else
		{
			YoneticiListesiDugum *gecici = this->ilk;
			while (gecici->sonrakiDugumuCagir() != NULL)
				gecici = gecici->sonrakiDugumuCagir();
			gecici->sonrakiDugumuDegistir(yeniDugum);
			gecici->sonrakiDugumuCagir()->oncekiDugumuDegistir(gecici);
		}
	}
}

void	YoneticiListesi::baslikYazdir(int index, int sayfaIndex, int toplam)
{
	if (sayfaIndex == 0)
		std::cout<<"Ilk    \n";
	else
		std::cout<<"<--    ";
	if (toplam > 8 && (sayfaIndex + 1) * 8 < toplam)
	{
		for (int i = 0; i < 8; i++)
			printf("%17s", " ");
	}
	if (sayfaIndex * index + 1 < this->satirSayisi && (sayfaIndex + 1) * 8 < toplam)
		std::cout<<" -->";
	else if (sayfaIndex != 0)
		std::cout<<" Son\n";
	std::cout<<"\n";;
}

void	YoneticiListesi::sirala()
{
	YoneticiListesiDugum *gecici = this->ilk;
	while (gecici != NULL)
	{
		YoneticiListesiDugum *gecici2 = gecici->sonrakiDugumuCagir();
		while (gecici2 != NULL)
		{
			if (gecici->ortalamaCagir() > gecici2->ortalamaCagir())
			{
				double geciciOrtalama = gecici->ortalamaCagir();
				gecici->ortalamaDegistir(gecici2->ortalamaCagir());
				gecici2->ortalamaDegistir(geciciOrtalama);
				SatirListesi *geciciSatirListesi = gecici->satirListesiCagir();
				gecici->satirListesiDegistir(gecici2->satirListesiCagir());
				gecici2->satirListesiDegistir(geciciSatirListesi);
			}
			gecici2 = gecici2->sonrakiDugumuCagir();
		}
		gecici = gecici->sonrakiDugumuCagir();
	}
}

void	YoneticiListesi::yazdir(std::string tip, int sayfaIndex)
{
	YoneticiListesiDugum *gecici = this->ilk;
	for (int i = 0; i < sayfaIndex * 8; i++)
	{
		if (gecici)
			gecici = gecici->sonrakiDugumuCagir();
	}
	int i = 0;
	while (gecici != NULL && i < 8)
	{
		if (tip == "adres")
			printf(" %08X ", gecici);
		else if (tip == "onceki")
			printf("|%08X|", gecici->oncekiDugumuCagir());
		else if (tip == "ortalama")
			printf("|%8.1f|", gecici->ortalamaCagir());
		else if (tip == "sonraki")
			printf("|%08X|", gecici->sonrakiDugumuCagir());
		else if (tip == "-")
			std::cout<<"----------";
		printf("%10s", " ");
		gecici = gecici->sonrakiDugumuCagir();
		i++;
	}
	std::cout<<"\n";
}

void	YoneticiListesi::dugumSil(int index, int sayfaIndex)
{
	YoneticiListesiDugum *gecici = this->ilk;
	int suanki = 0;
	for (int i = 0; i < sayfaIndex * 8; i++)
	{
		if (gecici != NULL)
			gecici = gecici->sonrakiDugumuCagir();
	}
	while (gecici != NULL)
	{
		if (suanki == index)
		{
			if (gecici->oncekiDugumuCagir() != NULL)
				gecici->oncekiDugumuCagir()->sonrakiDugumuDegistir(gecici->sonrakiDugumuCagir());
			if (gecici->sonrakiDugumuCagir() != NULL)
				gecici->sonrakiDugumuCagir()->oncekiDugumuDegistir(gecici->oncekiDugumuCagir());
			if (gecici == this->ilk)
				this->ilk = gecici->sonrakiDugumuCagir();
			delete gecici;
			break;
		}
		suanki++;
		gecici = gecici->sonrakiDugumuCagir();
	}
}

int	YoneticiListesi::rastgeleDugumSec(int index, int sayfaIndex)
{
	YoneticiListesiDugum *gecici = this->ilk;
	srand(time(NULL));
	for (int i = 0; i < sayfaIndex * 8; i++)
	{
		if (gecici)
			gecici = gecici->sonrakiDugumuCagir();
	}
	int i = 0;
	int j = 0;
	while (gecici != NULL)
	{
		if (i == index)
		{
			SatirListesiDugum *geciciSatirListesiDugumu = gecici->satirListesiCagir()->ilkDugumuCagir();
			while (geciciSatirListesiDugumu != NULL)
			{
				j++;
				geciciSatirListesiDugumu = geciciSatirListesiDugumu->sonrakiDugumuCagir();
			}
			return ((rand() % j) * -1 - 1);
		} 
		gecici = gecici->sonrakiDugumuCagir();
		i++;
	}
	return (0);
}

void	YoneticiListesi::listeYazdir(int index, int sayfaIndex, int toplam, int k)
{
	YoneticiListesiDugum *gecici = this->ilk;
	int suanki = 0;
	this->baslikYazdir(index, sayfaIndex, toplam);
	this->yazdir("adres", sayfaIndex);
	this->yazdir("-", sayfaIndex);
	this->yazdir("onceki", sayfaIndex);
	this->yazdir("-", sayfaIndex);
	this->yazdir("ortalama", sayfaIndex);
	this->yazdir("-", sayfaIndex);
	this->yazdir("sonraki", sayfaIndex);
	this->yazdir("-", sayfaIndex);
	for (int i = 0; i < sayfaIndex * 8; i++)
	{
		if (gecici != NULL)
			gecici = gecici->sonrakiDugumuCagir();
	}
	while(gecici != NULL)
	{
		if (suanki == index)
		{
			gecici->satirListesiCagir()->satirListesiYazdir(index, k);
			break;
		}
		suanki++;
		gecici = gecici->sonrakiDugumuCagir();
	}
}

int	*YoneticiListesi::satirDugumuSil(int k, int index, int sayfaIndex, int toplam)
{
	YoneticiListesiDugum *gecici = this->ilk;
	for (int i = 0; i < sayfaIndex * 8; i++)
	{
		if (gecici)
			gecici = gecici->sonrakiDugumuCagir();
	}
	int i = 0;
	int j = 0;
	while (gecici != NULL)
	{
		if (i == index)
		{
			SatirListesiDugum *geciciSatirListesiDugumu = gecici->satirListesiCagir()->ilkDugumuCagir();
			while (geciciSatirListesiDugumu != NULL)
			{
				if (j == -(k + 1))
				{	
					if (geciciSatirListesiDugumu->oncekiDugumuCagir() != NULL)
						geciciSatirListesiDugumu->oncekiDugumuCagir()->sonrakiDugumuDegistir(geciciSatirListesiDugumu->sonrakiDugumuCagir());
					if (geciciSatirListesiDugumu->sonrakiDugumuCagir() != NULL)
						geciciSatirListesiDugumu->sonrakiDugumuCagir()->oncekiDugumuDegistir(geciciSatirListesiDugumu->oncekiDugumuCagir());
					if (geciciSatirListesiDugumu == gecici->satirListesiCagir()->ilkDugumuCagir())
						gecici->satirListesiCagir()->ilkDugumuDegistir(geciciSatirListesiDugumu->sonrakiDugumuCagir());
					if (geciciSatirListesiDugumu->oncekiDugumuCagir() == NULL && geciciSatirListesiDugumu->sonrakiDugumuCagir() == NULL)
					{
						delete geciciSatirListesiDugumu;
						this->dugumSil(index, sayfaIndex);
						if (sayfaIndex * 8 + index + 1 == toplam)
							index--;
						if (this->ilkDugumuCagir() == NULL)
							index++;
						toplam--;
					}
					else
					{
						delete geciciSatirListesiDugumu;
						gecici->ortalamaHesapla();
					}
					int *dizi = new int[2];
					dizi[0] = index;
					dizi[1] = toplam;
					return (dizi);
				}
				j++;
				geciciSatirListesiDugumu = geciciSatirListesiDugumu->sonrakiDugumuCagir();
			}
		} 
		gecici = gecici->sonrakiDugumuCagir();
		i++;
	}
	return (NULL);
}
