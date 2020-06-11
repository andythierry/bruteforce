#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<sstream>

using namespace ::std;
//extern "C" void  SampleFunction1(void);
//extern "C" char* initdico(char*);
//extern "C" bool cherchemot(const char* motR,unsigned long* indexmot,char* Fichier);


//void SampleFunction1();

static const char alphabet[] =
    "abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "0123456789";

static const char Secret[] = {0x74,0x5c,0x17,0x06,0x24,0x0a,0x34,0x0e,0x24,0x58,0x43,0x0f,0x27,0x5a,0x06,0x4a,0x68,0x7d,0x44,0x06,0x68,0x57,0x16,0x19,0x21,0x5b,0x16,0x18,0x68,0x40,0x0c,0x4b,0x23,0x5a,0x0c,0x1c,0x68,0x5c,0x0c,0x1c,0x68,0x4d,0x0c,0x1e,0x6f,0x42,0x06,0x4b,0x3b,0x5b,0x0f,0x1d,0x2d,0x50,0x43,0x02,0x3c,0x1a,0x43,0x21,0x3d,0x47,0x17,0x4b,0x24,0x51,0x17,0x4b,0x25,0x51,0x43,0x0a,0x68,0x45,0x16,0x02,0x2b,0x5f,0x43,0x0e,0x25,0x55,0x0a,0x07,0x66,0x14,0x22,0x03,0x64,0x14,0x02,0x05,0x2c,0x14,0x2a,0x4b,0x2f,0x41,0x06,0x18,0x3b,0x14,0x1a,0x04,0x3d,0x13,0x11,0x0e,0x68,0x5c,0x06,0x19,0x2d,0x14,0x05,0x04,0x3a,0x14,0x17,0x03,0x2d,0x14,0x08,0x0e,0x31,0x1a,0x4d,0x45,0x68,0x7c,0x06,0x19,0x2d,0x14,0x0a,0x1f,0x68,0x5d,0x10,0x51,0x68,0x51,0x56,0x58,0x71,0x0d,0x51,0x09,0x2a,0x01,0x05,0x5c,0x29,0x52,0x55,0x0d,0x7d,0x05,0x54,0x5c,0x7b,0x55,0x07,0x53,0x2d,0x55,0x50,0x5b,0x7b,0x07,0x07,0x5d,0x7e,0x1a,0x43,0x22,0x2e,0x14,0x1a,0x04,0x3d,0x14,0x14,0x04,0x26,0x50,0x06,0x19,0x68,0x43,0x0b,0x0a,0x3c,0x14,0x0a,0x18,0x68,0x5d,0x17,0x45,0x66,0x1a,0x43,0x1c,0x2d,0x58,0x0f,0x47,0x68,0x5e,0x16,0x18,0x3c,0x14,0x02,0x05,0x68,0x79,0x27,0x5e,0x68,0x5c,0x02,0x18,0x20,0x14,0x0c,0x0d,0x68,0x16,0x14,0x0e,0x24,0x58,0x43,0x0f,0x27,0x5a,0x06,0x49,0x66,0x14,0x2b,0x04,0x38,0x51,0x43,0x12,0x27,0x41,0x43,0x03,0x29,0x50,0x43,0x0d,0x3d,0x5a,0x4d,0x4b,0x1a,0x51,0x0d,0x0a,0x3d,0x50,0x4d,0x57,0x67,0x5c,0x17,0x06,0x24,0x0a,0};


static const int alphabetSize = sizeof(alphabet) - 1;

char Decipher[300];
unsigned
long indexmot=0;
char  motR[30]="easy";
char* dico;

//bool cherchemot(const char* motR,char* motFr,FILE* Fichier)//Prend en param le mot a rechercher (motR) le pointeur sur
bool cherchemot(const char* motR,unsigned long* indexmot,char* Fichier)//Prend en param le mot a rechercher (motR) le pointeur sur
{
    //le stream du fichier dictionnaire et renvoie true si
    // il trouve et false en cas d'echec ,motFr pointe sur le mot
    int index=0;
    *indexmot=1;
//while (fscanf(Fichier,"%s",motFr) != EOF)


    while (*(Fichier+index) != EOF)
    {

        if(*(Fichier+index)=='\n'||*(Fichier+index)==' ')
        {
            index++;
        }

        if (strncmp((Fichier+index), motR,strlen(motR))== 0)
        {

            return true;
            break;
        }

        while ((*(Fichier+index)!='\n')&&(*(Fichier+index)!=' '))
        {
            //  while((*(Fichier+index)!='\n')){


            index++;
            if(*(Fichier+index) == EOF)
                break;
        }

        (*indexmot)++;



    }


    return false;
}

char* initdico (char* fichier){

FILE *Fichier;
 int taille;
    Fichier = fopen(fichier, "r");
     if (!Fichier){
        printf("\aERREUR: Impossible d'ouvrir le fichier: %s.\n", fichier);

             return nullptr;
                    }
    for(taille=0; ( fgetc (Fichier) != EOF); taille++);
    rewind(Fichier);

    char* dico=(char*)malloc(taille);
    for(int i=0; i<=taille; i++)
    {

        *(dico+i)=fgetc(Fichier);


    }
    fclose(Fichier);
return dico;



}




bool affichtext(char* decod)
{
    for (int i=0; i<254; i++)
    {
        printf("%c",*(decod+i));
    }

    return true;
}

char* DecodeLeHash(char* pass)
{


    int iCle = 0;
    for (unsigned int i=0; i<sizeof(Secret); i++)
    {
        *(Decipher+i)=( Secret[i] xor pass[iCle%(sizeof(pass)/sizeof(char))]);
        iCle++;

    }

    return Decipher;
}

bool testhash(char* str)
{
    int hash=0;
    char n=0;
    for(int j=0; j<(int)strlen(str); j++)
    {
        n=str[j];
        hash += ((n-j+33) xor 31025);
        if(hash==124456)
        {
            return true;
        }
    }

    return false;
}

void CntrlValidMot(char* str)
{
    int ind=0;
    char mot[300];
    printf("%s   \r",str);
    //printf("hash %d:::mdp:%s\n", hash,str);

    if(testhash(str))
    {


        while(*(DecodeLeHash(str)+ind)!=EOF&&*(DecodeLeHash(str)+ind)!='\n'&&ind<254)// utiliser strlen(str)
        {

            while(*(DecodeLeHash(str)+ind)!=EOF&&*(DecodeLeHash(str)+ind)!=' '&&*(DecodeLeHash(str)+ind)!='\n'&&ind<254)
            {
                ind++;


            }
            ind++;
            sscanf ((DecodeLeHash(str)+ind),"%s",mot);

            //   printf("le mot de passe est %s",str);
            //   printf("test %c",DecodeLeHash(str));
            //      affichtext((DecodeLeHash(str)));
            if (cherchemot(mot,&indexmot,dico))
            {
                printf("\n %s trouve car c'est le %ld mot du dictionnaire \n",mot,indexmot);
            }
        }

    }

}





void bruteImpl(char* str, int index, int maxDepth)
{
    //  printf("%s   \r",str);
    for (int i =0; i < alphabetSize; ++i)
    {

        str[index] = alphabet[i];


if (index == maxDepth -1 )
        {
     //       str="H4ck";
            CntrlValidMot( str) ;

        }
        else
        {
            bruteImpl(str,index + 1, maxDepth);
        }
    }
}

void bruteSequential(int maxLen)
{
    char buff[maxLen]={' '};
    *(buff+maxLen)=0;
    void* buf = malloc(maxLen );

    for (int i = 4; i <= maxLen; ++i)
    {
        memset(buf, 0, maxLen + 1);

         bruteImpl(buff,0, i);
     //   bruteImpl((char*)buf,0, i);



    }
    free(buf);
}
int main(const int argc, const char * const argv[])
{
    char test[]="dico.txt";
char pass[]="H4ck";
    dico=initdico(test);
    CntrlValidMot(pass);
 //   bruteSequential(4);
printf("longueur d un char:%d \n",sizeof(char));
    printf("finished");
    return 0;
}
