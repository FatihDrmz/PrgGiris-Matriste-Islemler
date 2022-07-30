/************************************************************
*                                                          **
*				ÖĞRENCİ ADI......: FATİH DURMAZ            **
*				ÖĞRENCİ NUMARASI.: G191210064              **
*				DERS GRUBU.......: 2/B                     **
************************************************************/

#include <iostream>
#include <ctime> //Random fonksiyonu icin gerekli.
#include <iomanip> //Setw fonksiyonu icin gerekli.

using namespace std;

//Matris'in satir ve sutunlarini gosteren tabloyu olusturan fonksiyondur.
void matristablosu(int boyut)
{
	for (int j = 1; j <= boyut; j++)
	{
		cout << j << setw(4);
	}

	cout << endl << setw(5);

	for (int j = 1; j <= boyut * 4; j++)
	{
		cout << "_";
	}

	cout << endl << endl;
}

int main()
{
	srand(time(NULL));

	bool kullanicimenusu = false;
	int  boyut, secenek, satir, sutun;

	cout << "Matris Boyutu:";
	cin >> boyut;

	int matrisolustur[25][25];
	int matrisdegistir[25][25];
	int matristersi[25][25];
	int matristoplam[25][25];

	int a = 1;
	int b = boyut;
	int elemantoplam = 0;

	//Matris boyutunun 5 ile 25 araliginda olmasini sağlar.
	while (boyut < 5 || boyut > 25)
	{
		cout << "matris boyutu 25'den kucuk, 5'den buyuk olmalidir." << endl << endl;
		cout << "Matris Boyutu:";
		cin >> boyut;
	}

	cout << endl << setw(8);

	matristablosu(boyut);

	//"matrisolustur" u ekrana cikarir.
	for (int i = 1; i <= boyut; i++)
	{
		if (i < 10)
			cout << setw(2) << i << " |   ";
		else
			cout << setw(3) << i << "|   ";

		for (int j = 1; j <= boyut; j++)
		{
			matrisolustur[i][j] = rand() % 9 + 1;
			cout << matrisolustur[i][j] << setw(4);
		}

		cout << endl << endl;
	}

	do {
		cout << endl << "1.Sutun Satir Degistir :" << endl;
		cout << endl << "2.Tekleri Basa Al(Satir) :" << endl;
		cout << endl << "3.Ters Cevir(Sutun) :" << endl;
		cout << endl << "4.Toplamlari Yazdir :" << endl;
		cin >> secenek;

		//Kullanici menusunden 1 ile 4 aralıgında deger secilmesini saglar.
		while (secenek < 1 || secenek > 4)
		{
			cout << endl << "1 ile 4 arasinda (1 ve 4 dahil) deger giriniz:";
			cin >> secenek;
		}

		switch (secenek)
		{
		case 1:
			cout << "satir sutun..:";
			cin >> satir;
			cin >> sutun;

			//Secilen satir ve sutunun matris boyutuna esit veya kucuk olmasini saglar.
			if (satir > boyut || sutun > boyut)
			{
				cout << endl << "satir ve sutun matris boyutundan buyuk!" << endl << endl;
				kullanicimenusu = true;
				break;
			}

			for (int i = 1; i <= boyut; i++)
			{
				for (int j = 1; j <= boyut; j++)
				{
					matrisdegistir[i][j] = matrisolustur[i][j];
				}
			}

			//Matrisin secilen satirini secilen sutununa,secilen sutununu secilen satirina atar.
			for (int i = 1; i <= boyut; i++)
			{
				matrisdegistir[a][sutun] = matrisolustur[satir][a];
				matrisdegistir[satir][a] = matrisolustur[a][sutun];

				a++;
			}

			//Secilen satirla sutunun kesistigi yerdeki elemanlari toplar.
			matrisdegistir[satir][sutun] = matrisolustur[satir][satir] + matrisolustur[sutun][sutun];

			cout << setw(8) << endl;

			matristablosu(boyut);

			//"matrisdegistiri" i ekrana cikarir.
			for (int i = 1; i <= boyut; i++)
			{
				if (i < 10)
					cout << setw(2) << i << " |   ";
				else
					cout << setw(3) << i << "|   ";

				for (int j = 1; j <= boyut; j++)
				{
					cout << matrisdegistir[i][j] << setw(4);
				}

				cout << endl << endl;
			}
			break;
		case 2:
			cout << "satir..:";
			cin >> satir;

			//Secilen satirin matris boyutuna esit veya kucuk olmasini saglar.
			if (satir > boyut)
			{
				cout << endl << "satir matris boyutundan buyuk olamaz!";
				kullanicimenusu = true;
				break;
			}

			//Secilen satirda bastan tekler ile ciftleri karsılastırarak tekleri satir basına, ciftleri satir sonuna alır.
			for (int i = 1; i <= boyut; i++)
			{
				for (int j = i; j <= boyut; j++)
				{
					if ((matrisolustur[satir][j] % 2 == 1) && (matrisolustur[satir][i] % 2 == 0))
					{
						int temp = matrisolustur[satir][j];
						matrisolustur[satir][j] = matrisolustur[satir][i];
						matrisolustur[satir][i] = temp;
					}
				}
			}

			cout << setw(8) << endl;

			matristablosu(boyut);

			//Yeni "matrisolustur" u ekrana cikarir.
			for (int i = 1; i <= boyut; i++)
			{
				if (i < 10)
					cout << setw(2) << i << " |   ";
				else
					cout << setw(3) << i << "|   ";

				for (int j = 1; j <= boyut; j++)
				{
					cout << matrisolustur[i][j] << setw(4);
				}

				cout << endl << endl;
			}
			break;
		case 3:
			cout << "sutun..:";
			cin >> sutun;

			//Secilen sutunun matris boyutuna esit veya kucuk olmasini saglar.
			if (sutun > boyut)
			{
				cout << endl << "sutun matris boyutundan buyuk olamaz!";
				kullanicimenusu = true;
				break;
			}

			for (int i = 1; i <= boyut; i++)
			{
				for (int j = 1; j <= boyut; j++)
				{
					matristersi[i][j] = matrisolustur[i][j];
				}
			}

			//Secilen sutunun elemanlarının yerini tersine cevirir.
			for (int i = 1; i <= boyut; i++)
			{
				matristersi[b][sutun] = matrisolustur[i][sutun];

				b--;
			}

			cout << setw(8) << endl;

			matristablosu(boyut);

			//"matristersi" ni ekrana cikarir.
			for (int i = 1; i <= boyut; i++)
			{
				if (i < 10)
					cout << setw(2) << i << " |   ";
				else
					cout << setw(3) << i << "|   ";

				for (int j = 1; j <= boyut; j++)
				{
					cout << matristersi[i][j] << setw(4);
				}

				cout << endl << endl;
			}
			break;
		case 4:
			//Matrisin elemanlari toplamini bulur.
			for (int i = 1; i <= boyut; i++)
			{
				for (int j = 1; j <= boyut; j++)
				{
					elemantoplam += matrisolustur[i][j]
				}
			}

			//Toplamdan ana matrisin elemanlarini cikararak "matristoplam" a atar.
			for (int i = 1; i <= boyut; i++)
			{
				for (int j = 1; j <= boyut; j++)
				{
					elemantoplam -= matrisolustur[i][j];
					matristoplam[i][j] = elemantoplam;
				}
			}

			cout << setw(8) << endl;

			matristablosu(boyut);

			//"matristoplam" i ekrana cikarir.
			for (int i = 1; i <= boyut; i++)
			{
				if (i < 10)
					cout << setw(2) << i << " |   ";
				else
					cout << setw(3) << i << "|   ";

				for (int j = 1; j <= boyut; j++)
				{
					cout << matristoplam[i][j] << setw(4);
				}

				cout << endl << endl;
			}
			break;
		}

	} while (kullanicimenusu);

	system("pause");
	return 0;
}