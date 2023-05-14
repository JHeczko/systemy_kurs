#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(){

    size_t nbyte = 20; // rozmiar pobieranych danych w bajtach
    char buffin[nbyte];


//------------------------------WCZYTYWANIE Z PLIKU DO POTOKU--------------------------------------------------------------------------------------------------
        int towarP = open("./towarP.txt", O_RDONLY,110110100);
        int pipein = open("./pipe", O_WRONLY, 110110100);
        if(pipein == -1){
            printf("Brak potoku");
            exit(EXIT_FAILURE);
        }
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
             
    }
//---------------------------------------------------KONIEC WCZYTYWANIE DO POTOKU--------------------------------------------------------------------------



