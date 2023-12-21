
/** 
* @file main.cpp
* @description   Genel komutları (ileri git,sayfa atla vs.) yapan yer.
* @course   1.Öğretim B grubu
* @assignment   1.Ödev
* @date   20.11.2022
* @author   Yusuf Sedat Sağaltıcı  yusuf.sagaltici@ogr.sakarya.edu.tr
*/


#include "../include/yoneticiListesi.hpp"
#include "../include/satirListesi.hpp"
#include "../include/satirListesiDugum.hpp"
#include "../include/yoneticiListesiDugum.hpp"

int main(int argc, char *argv[])
{
	YoneticiListesi *yoneticiListesi = new YoneticiListesi();
	yoneticiListesi->dosyadanOku("veriler.txt");
	yoneticiListesi->ortalamaHesapla();
	yoneticiListesi->listeOlustur();
	yoneticiListesi->sirala();
	int index = 0;
	int sayfaIndex = 0;
	int k = 0;
	int toplam = yoneticiListesi->satirSayisiniCagir();
	while (true)
	{
		std::string satir;
		system("cls");
		yoneticiListesi->listeYazdir(index, sayfaIndex, toplam, k);
		std::getline(std::cin, satir);
		if (satir == "c" && sayfaIndex * 8 + index + 1 < toplam)
			index++;
		else if (satir == "z" && (sayfaIndex > 0 || index > 0))
			index--;
		else if (satir == "d" && (sayfaIndex + 1) * 8 < toplam)
		{
			index = 0;
			sayfaIndex++;
		}
		else if (satir == "a" && sayfaIndex > 0)
		{
			index = 0;
			sayfaIndex--;
		}
		else if (satir == "p" && toplam > 0)
		{
			yoneticiListesi->dugumSil(index, sayfaIndex);
			if (sayfaIndex * 8 + index + 1 == toplam)
				index--;
			if (yoneticiListesi->ilkDugumuCagir() == NULL)
				index++;
			toplam--;
		}
		if (satir == "k")
		{
			if (k == 0)
				k = yoneticiListesi->rastgeleDugumSec(index, sayfaIndex);
			else
			{
				int *sonuc = yoneticiListesi->satirDugumuSil(k, index, sayfaIndex, toplam);
				k = 0;
				index = sonuc[0];
				toplam = sonuc[1];
				delete[] sonuc;
				yoneticiListesi->sirala();
			}
		}
		else
			k = 0;
		if (index == 8)
		{
			index = 0;
			sayfaIndex++;
		}
		else if (index == -1 && sayfaIndex > 0)
		{
			index = 7;
			sayfaIndex--;
		}
	}
	return 0;
}