#include <iostream> 
#include <locale.h>
#include <string>
#include <string.h>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <conio.h>
#include <fstream> 


/*EREN AL� KOCA ,��renci Servis Otomasyonu */ 







using namespace std;

struct ogrenci
{
	string adsoyad;
	string adres;
    float mesafe;
    long long int tel;
    string kan;
};

int fiyat(int km);
void bosluk();
void space();
int kontrol();
void st();
int main()
{
	
kontrol();
baslangic:
	setlocale(LC_ALL, "Turkish");
	cout<<"\n-�IKMAK ���N ANA MEN�YE D�N�N VE ESC TU�UNA BASIN-\n\n";
	cout<<"\n\n               ��RENC� SERV�S� OTOMASYONU               \n\n";
	ogrenci ogr[15];
	int menu;
	cout<<"1-��renci Kay�t\n2-��renci Arama\n3-��rencileri Listele\n4-Bilgilendirme ve Duyuru\n5-�cret Tarifesi\n6-��rencilerin Mesafeleri\n";
	cout<<"ESC-��k��\n";
	cout<<"\nYapmak istedi�iniz i�lemi se�iniz: ";menu=getche();cout<<endl;
char deneme;	
if(deneme==27)
exit(0);
	switch(menu)
	{
	
	case '1':
		{
			space();	
		  cout<<"\n\n\n                              ��RENC� KAYIT EKRANI                          \n\n";
			
            ofstream kayit("kayitlilar.txt");
            ofstream saat1("mesafeler.txt");
             for(int i=0;i<15;i++)
	        {
		 	cout<<i+1<<". ��rencinin ad�n� soyad�n� giriniz: ";
			cin.ignore();                                         //dizinin ilk eleman�nda adsoyad� txt ye ilk harfi eksik yaz�yor
			getline(cin,ogr[i].adsoyad);cout<<endl;
			cout<<i+1<<". ��rencinin adresini giriniz: ";
			getline(cin,ogr[i].adres);cout<<endl;
			cout<<i+1<<". ��rencinin mesafesini giriniz(km): ";
			cin>>ogr[i].mesafe;cout<<endl;
			cout<<i+1<<". ��rencinin velisinin tel nosunu giriniz: ";
			cin>>ogr[i].tel;cout<<endl;
			cout<<i+1<<". ��rencinin kan grubunu giriniz: ";
			cin>>ogr[i].kan;cout<<endl;
			
			
			
			kayit<<endl<<i+1<<". koltuk bilgileri: \n"<<"Ad-Soyad: "<<ogr[i].adsoyad<<endl;
			kayit<<"Adresi: "<<ogr[i].adres<<endl;
			kayit<<"Mesafesi: "<<ogr[i].mesafe<<endl;
			saat1<<"��renci: "<<ogr[i].adsoyad<<"  Mesafesi: "<<ogr[i].mesafe<<" km."<<endl;
			kayit<<"Veli �leti�im: "<<ogr[i].tel<<endl;
		    kayit<<"Kan Grubu: "<<ogr[i].kan<<endl;
		    char sec;
			cout<<"Yeni kay�t yapacak m�s�n�z?(e/h): ";cin>>sec;cout<<endl;
			if(sec=='h' || sec=='H')
			
			goto baslangic;	    
			}
		    cout<<"\n\n                   Kaydetti�iniz Bilgiler                  \n\n";
            for(int i=0;i<15;i++)
			{int km;km=ogr[i].mesafe;
			cout<<i+1<<". ��rencinin Ad-Soyad: "<<ogr[i].adsoyad<<endl;
			cout<<i+1<<". ��rencinin Adres: "<<ogr[i].adres<<endl;
			cout<<i+1<<". ��rencinin Mesafe: "<<ogr[i].mesafe<<endl;
			cout<<i+1<<". ��rencinin Veli Tel Nosu: "<<ogr[i].tel<<endl;
			cout<<i+1<<". ��rencinin Kan Grubu: "<<ogr[i].kan<<endl;
			fiyat(km);
			cout<<endl;
			  }  
			  
		    kayit.close();
		    saat1.close();
		    bosluk();
		    goto baslangic;
		 break;  
}
	case '2':
		{
			space();
			string isim;
			
			ifstream arama;
			arama.open("kayitlilar.txt");
			cout<<"Aramak istedi�iniz ��rencinin ad�n� giriniz: ";
			cin>>isim;cout<<endl;
				
					string veri;
while ( getline(arama,veri) )
      if(veri==isim)
      cout<<"bulundu"<<endl;
	  else
	  cout<"yok\n";
arama.close();
bosluk();
goto baslangic;
break;
}
 		case '3':
 			{
			 space();
		 	cout<<"\n\n\n\n       ��rencilerin Listesi       \n\n\n"<<endl;
		 	ifstream dosya("kayitlilar.txt");
		 	string satir;
		 	while ( getline(dosya,satir) )
      cout << satir << endl;
		dosya.close();
		bosluk();
		goto baslangic;	 
		}
		break;
		case '4':
			{
			space();
			ofstream yaz("Bilgilendirme.txt");
			yaz<<"\n\n1-Men� 1 ile ��rencileri kaydedebilirsiniz.\n";
			yaz<<"2-��renci kay�tta ��rencinin Ad Soyad�,Adresi,Ev ile Okul aras� mesafe,Velisinin telefon numaras� ve Kan Grubu istenir.\n";
			yaz<<"3-Men� 2 de ��renci ad� ile kay�t sorgulama yap�l�r.\n";
			yaz<<"4-Men� 3 ile t�m kay�tl� ��renciler listelenir.\n";
			yaz<<"5-Servis 15 ki�iliktir.\n";
			yaz<<"6-Men� 5 ��rencinin ev ile okul aras�ndaki mesafeye g�re �cret belirleme politikas�n� a��klar.\n";
			yaz<<"7-Herhangi i�lemden sonra program otomatik ana men�ye d�ner.\n";
		yaz.close();
			ifstream oku("Bilgilendirme.txt");
		 	string satir;
		 	while ( getline(oku,satir) )
      cout << satir << endl;
		
        oku.close();
         bosluk();
		goto baslangic;			
			break;
		}
			case '5':
				{
					space();
					ofstream yaz2("�cretlendirme.txt");
					yaz2<<"\n\n                      �cretlendirme Politikam�z                    \n";
					yaz2<<"Eviniz ile Okulunuz aras� km mesafesi:\n";
					yaz2<<"-5 km ye kadar 100 TL!\n\n-5km ile 10 km aras� 200TL!\n\n-10 km ile 20 km aras� 400 TL!\n\n";
					yaz2<<"-20 km �zeri 800 TL!\n\n";
					yaz2.close();
					ifstream oku2("�cretlendirme.txt");
		 	string satir2;
		 	while ( getline(oku2,satir2) )
      cout << satir2 << endl;
		
        oku2.close();
        bosluk();
				goto baslangic;
					break;
				}
			case '6':
				{
					space();
					cout<<"\n\n\n       Mesafe Listesi       \n\n\n"<<endl;
		 	ifstream dosya("mesafeler.txt");
		 	string satir;
		 	while ( getline(dosya,satir) )
      cout << satir << endl;
    
		dosya.close();
		bosluk();
		goto baslangic;	
					break;
				}
			case 27:
				{
				
			exit(0);	
			}
				
				
				
				
			default:
			cout<<"\nHATALI GIRIS YAPTINIZ!\n";
			goto baslangic;
		}
		



	
	
system("PAUSE") ;
	return 0;
	
	
}
int fiyat(int km)
{
	if(km<5)
	cout<"�cret:100 TL\n";
	else if(km>5 && km<10)
	cout<<"�cret: 200 TL\n";
    else if(km>10 && km<20)
	cout<<"�cret: 400 TL\n";
    else
    cout<<"�cret: 800 TL\n";
    return 1;
}
void bosluk()
{
	bas2:
	cout<<"\n\nNOT:Se�iminizi yapt�ktan sonra ana men�ye d�neceksiniz!\n\nEkrana bo�luk atamak istiyor musunuz?(e/h)";
		    char tuss;
		    tuss=getche();
		    if(tuss=='e'|| tuss=='E')
		    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		    else if(tuss=='h' || tuss=='H')
            cout<<endl;		    
			else
			{
			
			cout<<"\n\nL�tfen do�ru tu�a bas�n�z!\n";
		    goto bas2;
	}
}
void space()
{
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
int kontrol()
{
	string girilen;
	
	cout<<"\nNOT:Sifre:eren\n\n Sisteme Giris Yapmak Icin Sifreyi Giriniz: ";
	cin>>girilen;
	if(girilen=="eren" || girilen=="EREN")
	{
	cout<<"\nGIRIS BASARILI\n";
	return 1;}
	else
	{
	cout<<"\nSIFRE HATALI\n";
	return kontrol();}
}


