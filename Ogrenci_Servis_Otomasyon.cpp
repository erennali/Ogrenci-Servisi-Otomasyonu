#include <iostream> 
#include <locale.h>
#include <string>
#include <string.h>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <conio.h>
#include <fstream> 


/*EREN ALİ KOCA ,Öğrenci Servis Otomasyonu */ 







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
	cout<<"\n-ÇIKMAK İÇİN ANA MENÜYE DÖNÜN VE ESC TUŞUNA BASIN-\n\n";
	cout<<"\n\n               ÖĞRENCİ SERVİSİ OTOMASYONU               \n\n";
	ogrenci ogr[15];
	int menu;
	cout<<"1-Öğrenci Kayıt\n2-Öğrenci Arama\n3-Öğrencileri Listele\n4-Bilgilendirme ve Duyuru\n5-Ücret Tarifesi\n6-Öğrencilerin Mesafeleri\n";
	cout<<"ESC-Çıkış\n";
	cout<<"\nYapmak istediğiniz işlemi seçiniz: ";menu=getche();cout<<endl;
char deneme;	
if(deneme==27)
exit(0);
	switch(menu)
	{
	
	case '1':
		{
			space();	
		  cout<<"\n\n\n                              ÖĞRENCİ KAYIT EKRANI                          \n\n";
			
            ofstream kayit("kayitlilar.txt");
            ofstream saat1("mesafeler.txt");
             for(int i=0;i<15;i++)
	        {
		 	cout<<i+1<<". öğrencinin adını soyadını giriniz: ";
			cin.ignore();                                         //dizinin ilk elemanında adsoyadı txt ye ilk harfi eksik yazıyor
			getline(cin,ogr[i].adsoyad);cout<<endl;
			cout<<i+1<<". öğrencinin adresini giriniz: ";
			getline(cin,ogr[i].adres);cout<<endl;
			cout<<i+1<<". öğrencinin mesafesini giriniz(km): ";
			cin>>ogr[i].mesafe;cout<<endl;
			cout<<i+1<<". öğrencinin velisinin tel nosunu giriniz: ";
			cin>>ogr[i].tel;cout<<endl;
			cout<<i+1<<". öğrencinin kan grubunu giriniz: ";
			cin>>ogr[i].kan;cout<<endl;
			
			
			
			kayit<<endl<<i+1<<". koltuk bilgileri: \n"<<"Ad-Soyad: "<<ogr[i].adsoyad<<endl;
			kayit<<"Adresi: "<<ogr[i].adres<<endl;
			kayit<<"Mesafesi: "<<ogr[i].mesafe<<endl;
			saat1<<"Öğrenci: "<<ogr[i].adsoyad<<"  Mesafesi: "<<ogr[i].mesafe<<" km."<<endl;
			kayit<<"Veli İletişim: "<<ogr[i].tel<<endl;
		    kayit<<"Kan Grubu: "<<ogr[i].kan<<endl;
		    char sec;
			cout<<"Yeni kayıt yapacak mısınız?(e/h): ";cin>>sec;cout<<endl;
			if(sec=='h' || sec=='H')
			
			goto baslangic;	    
			}
		    cout<<"\n\n                   Kaydettiğiniz Bilgiler                  \n\n";
            for(int i=0;i<15;i++)
			{int km;km=ogr[i].mesafe;
			cout<<i+1<<". Öğrencinin Ad-Soyad: "<<ogr[i].adsoyad<<endl;
			cout<<i+1<<". Öğrencinin Adres: "<<ogr[i].adres<<endl;
			cout<<i+1<<". Öğrencinin Mesafe: "<<ogr[i].mesafe<<endl;
			cout<<i+1<<". Öğrencinin Veli Tel Nosu: "<<ogr[i].tel<<endl;
			cout<<i+1<<". Öğrencinin Kan Grubu: "<<ogr[i].kan<<endl;
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
			cout<<"Aramak istediğiniz öğrencinin adını giriniz: ";
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
		 	cout<<"\n\n\n\n       Öğrencilerin Listesi       \n\n\n"<<endl;
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
			yaz<<"\n\n1-Menü 1 ile öğrencileri kaydedebilirsiniz.\n";
			yaz<<"2-Öğrenci kayıtta Öğrencinin Ad Soyadı,Adresi,Ev ile Okul arası mesafe,Velisinin telefon numarası ve Kan Grubu istenir.\n";
			yaz<<"3-Menü 2 de öğrenci adı ile kayıt sorgulama yapılır.\n";
			yaz<<"4-Menü 3 ile tüm kayıtlı öğrenciler listelenir.\n";
			yaz<<"5-Servis 15 kişiliktir.\n";
			yaz<<"6-Menü 5 Öğrencinin ev ile okul arasındaki mesafeye göre ücret belirleme politikasını açıklar.\n";
			yaz<<"7-Herhangi işlemden sonra program otomatik ana menüye döner.\n";
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
					ofstream yaz2("Ücretlendirme.txt");
					yaz2<<"\n\n                      Ücretlendirme Politikamız                    \n";
					yaz2<<"Eviniz ile Okulunuz arası km mesafesi:\n";
					yaz2<<"-5 km ye kadar 100 TL!\n\n-5km ile 10 km arası 200TL!\n\n-10 km ile 20 km arası 400 TL!\n\n";
					yaz2<<"-20 km üzeri 800 TL!\n\n";
					yaz2.close();
					ifstream oku2("Ücretlendirme.txt");
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
	cout<"Ücret:100 TL\n";
	else if(km>5 && km<10)
	cout<<"Ücret: 200 TL\n";
    else if(km>10 && km<20)
	cout<<"Ücret: 400 TL\n";
    else
    cout<<"Ücret: 800 TL\n";
    return 1;
}
void bosluk()
{
	bas2:
	cout<<"\n\nNOT:Seçiminizi yaptıktan sonra ana menüye döneceksiniz!\n\nEkrana boşluk atamak istiyor musunuz?(e/h)";
		    char tuss;
		    tuss=getche();
		    if(tuss=='e'|| tuss=='E')
		    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		    else if(tuss=='h' || tuss=='H')
            cout<<endl;		    
			else
			{
			
			cout<<"\n\nLütfen doğru tuşa basınız!\n";
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


