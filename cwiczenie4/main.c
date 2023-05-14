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
    char buffin[nbyte];
    //Tworzenie potoku miedzy dwoma plikami
    int filed[2]; 
    if(pipe(filed) == -1){
        printf("%s", strerror(errno));
        exit(EXIT_FAILURE);
    };

    int id = fork();

    switch (id)
    {       
    case -1:
        perror("Fork failure");
        exit(EXIT_FAILURE);



//-----------------------CHILD----------------------------------------------------------------------------------------------
    case 0: 
        close(filed[1]); // nie potrzebujemy zapisywac danych w procesie potomnym
        
        int towarK = open("./towarK.txt", O_WRONLY, 110110100);
        int readII;  // ilosc odczytanych znakow
        sleep(1);

        do{                                         
            readII = read(filed[0], buffout, nbyte);
            if(readII > 0){
                write(towarK, buffout, readII);                  //tutaj juz tak naprawde nie potrzebujemy sprawdzac czy znakow jest 20 czy 16, bo ile ich wczytamy z potoku
                for (int i = 0 ; i < readII; i++){              //jest dla nas nieistotne, dlatego poporstu bierzemy znaki z potoku, zapisujemy ile ich wzielismy w zmienna
                    printf("%c",buffout[i]);                    // readII a nastepnie wypisujemy w konsoli i pliku
                }
            }
        }
        while(readII > 0);

        close(towarK);
        close(filed[0]);
        break;
//--------------------------------CHILD END----------------------------------------------------------------------------------------------------
//------------------------------PARENT--------------------------------------------------------------------------------------------------
    default:
        close(filed[0]); //nie potrzebujemy odczytywac danych w procesie macierzystym

        int towarP = open("./towarP.txt", O_RDONLY,110110100);
        int readI;  // ilosc odczytanych znakow

        do{                                         // wypisanie w konsoli pliku towarP.txt i dodanie do potoku tego co wczytujemy i wypisujemy
            readI = read(towarP, buffin, nbyte);
            sleep(1);
            if(readI == 0){
                break;
                }

            else if((readI < nbyte) && (readI > 0)){    //petla do-while dzila w ten sposb ze za kazydm razem pobiera jakas ilosc nbyte danych z pliku
                write(filed[1], buffin, readI);         //ale moze zdarzyc sie tak ze pobierze 20 znakow a w pliku zostalo 16, wtedy mamy drugi przypadek
                for (int i = 0 ; i < readI; i++){        // do oblsuzenia w ktorym dodajemy do potoku tylko te przykladowe 16 znakow itd...
                    printf("%c",buffin[i]);             // podobnie dziala to dla potomnego
                }
            }

            else if(readI > 0){
                write(filed[1], buffin, nbyte);
                for (int i = 0 ; i < readI; i++){
                    printf("%c",buffin[i]);
                }
            }
        }
        while(readI > 0);
        
        printf("\n");

        close(towarP);
        close(filed[1]);
        wait(NULL);
        break;           
        }
//-----------------------------------PARENT END------------------------------------------------------------------------------------------
    if(id > 0){
    printf("\n");
    system("diff -s towarK.txt towarP.txt"); // sprawdzamy czy to samo
    }
}
