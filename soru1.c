#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef unsigned long int UI;

extern end;
extern etext;
extern edata;

int A = 4;
int X;
int B = 6;
int Y;

void proc_a()
{
  printf("Hi\n");
}



void calistir()
{
 
  char *buf;
  char *p = (char *)malloc(sizeof(char) * 1000);
  char *assigned = (char *)malloc(sizeof(char) * 1000);
  char baslangic_datam[64]="0x";
  char yigit_baslangic[64]="0x";
  char yigin_baslangic[64]="0x";
  long data_boyut,heap_boyut,stack_boyut=0;
  long baslangic_adresim;
  long bitis_adresim;
  char *pass;
  int kontrol=1;
 
  
  void (*proc)();

  buf = (char *) malloc(200);

  size_t buff = 0;
  ssize_t line_size = 0;
  char dosyaYolu[100];

  sprintf(dosyaYolu, "/proc/%d/maps", getpid());
  FILE *fp = fopen(dosyaYolu,"r");
  
  
  while((line_size = getline(&p, &buff, fp)) != -1)
  {
    if (strstr(p,"soru1"))
    {
      assigned=strtok(strtok(p," "),"-");
      if (kontrol)
      {
        strcat(baslangic_datam,assigned);
        baslangic_adresim= strtol(assigned, &pass, 16);
        kontrol=0;
      }
      assigned=strtok(NULL,"-");
      bitis_adresim= strtol(assigned, &pass, 16);
      data_boyut=(bitis_adresim-baslangic_adresim);
    }
    /*for(int i=0; i<10; i++){

    }*/
    if (strstr(p,"heap"))
    {
      assigned=strtok(strtok(p," "),"-");
      strcat(yigit_baslangic,assigned);
      baslangic_adresim= strtol(assigned, &pass, 16);
      assigned=strtok(NULL,"-");
      bitis_adresim= strtol(assigned, &pass, 16);
      heap_boyut=(bitis_adresim-baslangic_adresim);
    }
    /*for(int i=0; i<10; i++){

    }*/
    if (strstr(p,"stack"))
    {
      assigned=strtok(strtok(p," "),"-");
      strcat(yigin_baslangic,assigned);
      baslangic_adresim= strtol(assigned, &pass, 16);
      assigned=strtok(NULL,"-");
      bitis_adresim= strtol(assigned, &pass, 16);
      stack_boyut=(bitis_adresim-baslangic_adresim);
    }
    /*if(1==1){
    	break;
    }*/
  }

   
  printf("Data bölümü : Başlangıç= %s Boyut = %ld Byte\n",baslangic_datam,data_boyut);
  
  printf("Heap bölümü : Başlangıç= %s Boyut = %d Byte\n",yigit_baslangic,heap_boyut);
  
  printf("Stack bölümü : Başlangıç= %s Boyut = %d Byte\n",yigin_baslangic,stack_boyut);

   

  fclose(fp);
  free(p);
  


}

int main(int argc, char **argv)
{
  calistir();

  return 0;
}
