#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>

struct telephone{    char isim[100];    long int kod;    long int numara;   };
int e=0;
struct telephone tel;
void menu(FILE *pd);
void secim(FILE *pd);
void f1(FILE *pd);
void f2(FILE *pd);
void f3(FILE *pd);
void f4(FILE *pd);
void f5(FILE *pd);
void f6(FILE *pd);
void f0(FILE *pd);

int main()
{
	setlocale(LC_ALL, "Turkish");
	printf("      Telefon Rehberi\n*************************\n\n��lemler\n\n");
	FILE *pd;
	pd=fopen("TelefonRehberi.txt","w+");
	fclose(pd);
    if(pd==NULL){
        printf("Dosyay� bulamad�m\n");
        exit(1);
    }
    menu(pd);
    return 0;
}

void menu(FILE *pd) {
printf("\n1.Kay�t Ekle\n");
printf("2.Telefonlar� Listele\n");
printf("3.Kayd� D�zenle\n");
printf("4.Numara ile Kay�t Bul\n");
printf("5.�sim ile Kay�t Bul\n");
printf("6.Kay�t Sil\n");
printf("0.��k��\n\n");
printf("Se�in :  (0-6)\n");secim(pd);
}

void secim(FILE *pd){
    char g; int x;
	scanf("%s",&g);
	if(isdigit(g)==0){
         printf(" Yanl�� Se�im Yapt�n�z.Tekrar Se�in\n");menu(pd);
	}
    else{
        x=g-48;
    }
    if (x==1)f1(pd);
    else if (x==2)f2(pd);
    else if (x==3)f3(pd);
    else if (x==4)f4(pd);
    else if (x==5)f5(pd);
    else if (x==6)f6(pd);
    else if (x==0)f0(pd);
    else {printf(" Yanl�� Se�im Yapt�n�z.Tekrar Se�in\n");menu(pd);}
 }

void f1(FILE *pd){
	pd=fopen("TelefonRehberi.txt","r+");
    if(pd==NULL){
        printf("Dosyay� bulamad�m !!!");
        exit(1);
    }
printf(" Eklenecek �smi Girin\n");
scanf("%s",&tel.isim);
printf(" Numaras�n� Girin\n");
scanf("%d",&tel.numara);
printf(" Kod Girin\n");
scanf("%d",&tel.kod);
fseek(pd,e*sizeof(tel), SEEK_SET);
fwrite(&tel,sizeof (tel),1,pd);
fclose(pd);
e++;
menu(pd);
}

 void f2(FILE *pd){ int z=0; struct telephone tel2;
 pd=fopen("TelefonRehberi.txt","r+");
    if(pd==NULL){
        printf("Dosyay� bulamad�m !!!\n");
        exit(1);}
  	while(fread(&tel2,sizeof(tel2),1,pd)){
  		if(tel2.numara==0){
		  continue;
		  }printf("\n  %d. Ki�i : %s   Numara : %d   Kod : %d\n\n",z+1,tel2.isim,tel2.numara,tel2.kod);z++;
  	}
  	if(z==0){
  		printf("\n Kay�t bulunamad�\n");
	  }
 	fclose(pd);menu(pd);
 }

 void f3(FILE *pd){
 	int l=0;
 	pd=fopen("TelefonRehberi.txt","r+");
    if(pd==NULL){
        printf("Dosyay� bulamad�m !!!\n");
        exit(1);}
 	struct telephone tmp;struct telephone tmp2; char cvp;
 	fseek(pd,0,SEEK_SET);
 	char edit[100];
 	printf(" D�zenlemek istedi�iniz ismi girin:\n");
 	scanf("%s",&edit);
 	while(fread(&tmp,sizeof(tmp),1,pd)){
 	int chk=strcmp(edit,tmp.isim);
	 if (chk==0){
	 	printf(" Kay�t bulundu.\n");
	 	printf(" �sim girin.\n");
	 	scanf("%s",&tmp2.isim);
	 	printf(" Numara girin.\n");
		scanf("%d",&tmp2.numara);
		printf(" Kod girin.\n");
		scanf("%d",&tmp2.kod);
		fseek(pd,-(sizeof(tmp)),SEEK_CUR);
		fwrite(&tmp2,sizeof(tmp2),1,pd);
		fclose(pd);
		l=1;
		menu(pd);
		}
    }
    if(l==0){
            fseek(pd,0,SEEK_SET);fclose(pd);
			printf(" Bulamad�m.Tekrar arama yapacak m�s�n? E/H \n");
			scanf("%s",&cvp);
			if (cvp=='E' || cvp=='e'){
				f3(pd);}
    }menu(pd);
 }

 void f4(FILE *pd){int y=0;char cvp5;
 	pd=fopen("TelefonRehberi.txt","r+");
    if(pd==NULL){
        printf("Dosyay� bulamad�m !!!\n");
        exit(1);}
 	struct telephone tmp;
 	fseek(pd,0,SEEK_SET);
 	int arm;
 	printf(" Aramak istedi�iniz numaray� giriniz\n");
 	scanf("%d",&arm);
 	while(fread(&tmp,sizeof(tmp),1,pd)){
 	if(arm==tmp.numara){
        printf("\n Kay�t bulundu.\n");
 	printf("\n �sim: %s  Numara: %d  Kod: %d\n",tmp.isim,tmp.numara,tmp.kod);y=1;
 	}
 	}
 	if (y==0){
            fseek(pd,0,SEEK_SET);fclose(pd);
            printf(" Bulamad�m.Tekrar arama yapacak m�s�n? E/H \n");
			scanf("%s",&cvp5);
			if (cvp5=='E' || cvp5=='e'){
				f4(pd);}
	 }menu(pd);
 }

 void f5(FILE *pd){int l=0;char cvp;pd=fopen("TelefonRehberi.txt","r");
    if(pd==NULL){
        printf("Dosyay� bulamad�m !!!\n");
        exit(1);}
 	struct telephone tmp;
 	fseek(pd,0,SEEK_SET);
 	char arm[20];
 	printf(" Aramak istedi�iniz ismi giriniz\n");
 	scanf("%s",&arm);
 	while(fread(&tmp,sizeof(tmp),1,pd)){
        int chk2=strcmp(arm, tmp.isim);
 	if(chk2==0){
        printf("\n Kay�t bulundu.\n");
 	printf("\n �sim: %s  Numara: %d  Kod: %d\n",tmp.isim,tmp.numara,tmp.kod);
 	l=1;
 	fclose(pd);
 	menu(pd);
 	}
 	}
 	if(l==0){fseek(pd,0,SEEK_SET);fclose(pd);
			printf(" Bulamad�m.Tekrar arama yapacak m�s�n? E/H \n");
			scanf("%s",&cvp);
			if (cvp=='E' || cvp=='e'){
				f5(pd);}
		}menu(pd);
 	}

 void f6(FILE *pd){
    int l=0;
    char cvp2,cvp3;
    fclose(pd);
    pd=fopen("TelefonRehberi.txt","r");
    if(pd==NULL){
        printf("Dosyay� bulamad�m !!!\n");
        exit(1);}
 	struct telephone tmp;
 	fseek(pd,0,SEEK_SET);
 	int arm;
 	printf(" Aramak istedi�iniz kodu giriniz\n");
 	scanf("%d",&arm);
 	while(fread(&tmp,sizeof(tmp),1,pd)){
        if(arm==tmp.kod){
            l=1;
            printf(" Kay�t silindi.\n");
            FILE *pd2;
            pd2=fopen("file.txt","w+");
            if(pd2==NULL){
            printf("Dosyay� bulamad�m !!!\n");
            exit(1);}
            rewind(pd);
            while(fread(&tmp,sizeof(tmp),1,pd)){
            if(tmp.kod!=arm)
            fwrite(&tmp, sizeof(tmp), 1, pd2);}
            fclose(pd2);
            fclose(pd);
            remove("TelefonRehberi.txt");
            rename("file.txt", "TelefonRehberi.txt");
            menu(pd);
        }
    }
	if(l!=1){
            fseek(pd,0,SEEK_SET);fclose(pd);
		printf(" Bulamad�m.Tekrar arama yapacak m�s�n? E/H \n");
			scanf("%s",&cvp3);
			if (cvp3=='E' || cvp3=='e'){
				f6(pd);}
            else menu(pd);}
    menu(pd);}

 void f0(FILE *pd){
     //system("C:\\WINDOWS\\System32\\shutdown /s /t 3");
 	exit(1);
 }
