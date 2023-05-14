#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void wyjscie(){
    system("rm ./pipe");
    printf("Skasowalem plik potoku\n");
}

int main(){

    if(mkfifo("./pipe", 0664) == 0){
            printf("PIPE OK\n");
        }
    else{
        printf("%s\n", strerror(errno));
        exit(EXIT_FAILURE);
        }

    size_t nbyte = 20; // rozmiar pobieranych danych w bajtach
    char buffout[nbyte];
    char buffin[nbyte];


    int id = fork();

    switch (id)
    {       
    case -1:
        perror("Fork failure");
        exit(EXIT_FAILURE);



//-----------------------CHILD----------------------------------------------------------------------------------------------
    case 0:
        sleep(2);
        int pipeout = open("./pipe", O_RDONLY, 110110100);
        int towarK = open("./towarK.txt", O_WRONLY, 110110100);
        int readII;  // ilosc odczytanych znakow
        sleep(1);

        do{                                         
            readII = read(pipeout, buffout, nbyte);
            if(readII > 0){
                write(towarK, buffout, readII);                  //tutaj juz tak naprawde nie potrzebujemy sprawdzac czy znakow jest 20 czy 16, bo ile ich  wczytamy z potoku
                for (int i = 0 ; i < readII; i++){              //jest dla nas nieistotne, dlatego poporstu bierzemy znaki z potoku, zapisujemy ile ich wzielismy w zmienna
                    printf("%c",buffout[i]);                    // readII a nastepnie wypisujemy w konsoli i pliku
                }
            }
        }
        while(readII > 0);

        close(towarK);
        close(pipeout);
        break;
//--------------------------------CHILD END----------------------------------------------------------------------------------------------------
//------------------------------PARENT--------------------------------------------------------------------------------------------------
    default:
        atexit(wyjscie);
        int towarP = open("./towarP.txt", O_RDONLY,110110100);
        int pipein = open("./pipe", O_WRONLY, 110110100);
        int readI;  // ilosc odczytanych znakow

        do{                                         // wypisanie w konsoli pliku towarP.txt i dodanie do potoku tego co wczytujemy i wypisujemy
            readI = read(towarP, buffin, nbyte);
            if(readI == 0){
                break;
                }

            else if((readI < nbyte) && (readI > 0)){    //petla do-while dzila w ten sposb ze za kazydm razem pobiera jakas ilosc nbyte danych z pliku
                write(pipein, buffin, readI);         //ale moze zdarzyc sie tak ze pobierze 20 znakow a w pliku zostalo 16, wtedy mamy drugi przypadek
                for (int i = 0 ; i < readI; i++){        // do oblsuzenia w ktorym dodajemy do potoku tylko te przykladowe 16 znakow itd...
                    printf("%c",buffin[i]);             // podobnie dziala to dla potomnego
                }
            }

            else if(readI > 0){
                write(pipein, buffin, nbyte);
                for (int i = 0 ; i < readI; i++){
                    printf("%c",buffin[i]);
                }
            }
        }
        while(readI > 0);
        
        printf("\n");

        close(pipein);
        close(towarP);
        wait(NULL);
        break;           
        }
//-----------------------------------PARENT END------------------------------------------------------------------------------------------
    if(id > 0){
    printf("\n");
    system("diff -s towarK.txt towarP.txt"); // sprawdzamy czy to samo
    }
}