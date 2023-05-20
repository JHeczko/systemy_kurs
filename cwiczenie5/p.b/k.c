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
    char buffout[nbyte];





//-----------------------ZCZYTYWANIE Z POTOKU----------------------------------------------------------------------------------------------
        sleep(2);
        int pipeout = open("./pipe", O_RDONLY, 110110100);
        if(pipeout == -1){
            printf("Brak potoku");
            exit(EXIT_FAILURE);
        }
        int towarK = open("./towarK.txt", O_WRONLY, 110110100);
        int readII;  // ilosc odczytanych znakow

        do{    
            sleep(1);                                     
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
//--------------------------------KONIEC ZCZYTYWANIA----------------------------------------------------------------------------------------------------
    printf("\n");
    system("diff -s towarK.txt towarP.txt"); // sprawdzamy czy to samo

}
