#include "stdlib.h"
#include <string.h>
#include "stdio.h"
void yap(int *argc, char *argv[])
{

  FILE *dosya;
  char *satir = NULL;
  char mod[2];
  int satir_sayac = 1;
  char c;
  mod[0] = argv[1][0];
  mod[1] = argv[1][1];
  char *dosyaAdi = malloc(sizeof(char) * 100);
  dosyaAdi = argv[2];

  size_t buff = 0;
  size_t nread = 0;

  if ((dosya = fopen(dosyaAdi, "r")) != NULL)
  {
    while ((nread = getline(&satir, &buff, dosya)) != -1)
    {
     
      if (strstr(satir, "strcpy"))
      {
        if (strcmp(mod,"-s")==0)
        {
          printf("Satır %d: strcpy() kullanılmış.\n", satir_sayac);
        }
        else if (strcmp(mod,"-r")==0)
        {
          printf("Satır %d: strcpy() kullanılmış. Yerine strncpy() kullanmalısınız.\n", satir_sayac);
        }
      }
      
      satir_sayac++;
    }
  }
  else
    printf("Dosya Bulunamadı...");

    fclose(dosya);
    satir_sayac = 1;

  if ((dosya = fopen(dosyaAdi, "r")) != NULL)
  {
    while ((nread = getline(&satir, &buff, dosya)) != -1)
    {
      
      if (strstr(satir, "strcat"))
      {
        if (strcmp(mod,"-s")==0)
        {
          printf("Satır %d: strcat() kullanılmış.\n", satir_sayac);
        }
        else if (strcmp(mod,"-r")==0)
        {
          printf("Satır %d: strcat() kullanılmış. Yerine strlcat() kullanmalısınız.\n", satir_sayac);
        }
      }
      satir_sayac++;
    }
  }

  else
    printf("Dosya Bulunamadı...");
   
   fclose(dosya);
   satir_sayac = 1;

  if ((dosya = fopen(dosyaAdi, "r")) != NULL)
  {
    while ((nread = getline(&satir, &buff, dosya)) != -1)
    {
     
      if (strstr(satir, "gets"))
      {
        if (strcmp(mod,"-s")==0)
        {
          printf("Satır %d: gets() kullanılmış.\n", satir_sayac);
        }
        else if (strcmp(mod,"-r")==0)
        {
          printf("Satır %d: gets() kullanılmış. Yerine fgets() kullanmalısınız.\n", satir_sayac);
        }
      }
      satir_sayac++;
    }
  }

  else
    printf("Dosya Bulunamadı...");
   
    fclose(dosya);
    satir_sayac = 1;


  if ((dosya = fopen(dosyaAdi, "r")) != NULL)
  {
    while ((nread = getline(&satir, &buff, dosya)) != -1)
    {
     
      if (strstr(satir, "getpw"))
      {
        if (strcmp(mod,"-s")==0)
        {
          printf("Satır %d: getpw() kullanılmış.\n", satir_sayac);
        }
        else if (strcmp(mod,"-r")==0)
        {
          printf("Satır %d: getpw() kullanılmış. Yerine getpwuid() kullanmalısınız.\n", satir_sayac);
        }
      }
      satir_sayac++;
    }
  }


  else
    printf("Dosya Bulunamadı...");
   
    fclose(dosya);
    satir_sayac = 1;

   if ((dosya = fopen(dosyaAdi, "r")) != NULL)
  {
    while ((nread = getline(&satir, &buff, dosya)) != -1)
    {
      
      if (strstr(satir, "sprintf"))
      {
        if (strcmp(mod,"-s")==0)
        {
          printf("Satır %d: sprintf() kullanılmış.\n", satir_sayac);
        }
        else if (strcmp(mod,"-r")==0)
        {
          printf("Satır %d: sprintf() kullanılmış. Yerine snprintf() kullanmalısınız.\n", satir_sayac);
        }
      }
      satir_sayac++;
    }
  }
  

  else
  printf("Dosya Bulunamadı...");
  free(satir);
  fclose(dosya);

}

int main(int *argc, char *argv[])
{
  yap(argc, argv);
  return 0;
}

