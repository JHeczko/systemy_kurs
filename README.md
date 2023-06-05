# CWICZENIE 5

**Uruchamianie A:**
* **GLOWNY PROGAM:** 

    >Aby uruchomic program nalezy wpisac "make run1"

**Uruchamianie B:**

* **POTOK (make potok)**

    >Aby stworzyc potok nalezy w osobnym terminalu wpisac "make potok", jesli chcemy potok usunac nalezy w tym samym terminalu w ktorym stworzylismy potok wpisac liczbe -1, tak jak prosi program

* **KONSUMENT I PRODUCENT (make runP i make runK)**

    >Jesli chodzi o uruchomienie programów, ktore korszystaja z potokow, nalezy wpisac po uruchomieniu potoku, komende "make runK" jesli chcemy uruchomic proces konsumenta i komende "make runP" jesli chcemy uruchomic proces producenta

# CWICZENIE 6

>We wszystkich tych rzeczach -D DEBUG jest opcjonany, polecam wylaczyc bo bedzie duzo syfu w terminalu

* **Uruchamianie biblioteki:**

    >"g++ main.cpp semaphore.cpp -std=c++17 -D DEBUG

* **Uruchiamianie powielacza:**

    >"g++ program.cpp -o program -std=c++17 -D DEBUG; g++ main.cpp -std=c++17 -D DEBUG;"
    >albo 
    >"make run1"

    > ''./a.out X ./program Y'' 
    >gdzie X to ilosc procesow, ktore stworzymy, a Y to ilosc sekcji krytycznych(wartosc semafora, bo w zaleznosci ile bedzie sekcji krytycznych to tyle procesow puscimy do korzystania z nich) 

    > Aby wyczyscic:
    >"make clean" aby wyczyscic

# CWICZENIE 7

* **Uruchamianie zadania do pamieci:**

    > Aby uruchomic nalezy w takiej kolejnosci wpisac: "make help" , a nastepnie "make run_main" albo "g++ main.cpp -std=c++17"

* **Uruchamianie biblioteki:**

    > Zwykla kompilacja "g++ main.cpp class.cpp -std=c++17; ./a.out"

* **Uruchamianie zadania do pamieci ale z dolaczona biblioteka:**

    > Trzeba wpisac: "g++ semaphore.cpp -c; g++ memory.cpp -c; ar rvs lib.a memory.o semaphore.o; g++ kons.cpp lib.a -o kons; g++ prod.cpp lib.a -o prod; g++ main.cpp lib.a"

# CWICZENIE 8

* **Uruchamianie zadania z kolejkami:**

    > Aby skompilowac serwer nalezy wpisac "g++ serwer.cpp -std=c++17 -lrt -D DEBUG -o serwer.x", ay skompilowac klienta nalezy wpisac "g++ klient.cpp -std=c++17 -lrt -D DEBUG -o klient.x"

* **Uruchamianie biblioteki:**

    > Aby skompilowac biblioteke, poprostu trzeba wpisac "g++ kolejka.cpp -std=c++17 -lrt"

# CWICZENIE 9

* **Uruchamianie zadania z wątkami:**

    > Aby skompilowac wpisac "g++ main.cpp -std=c++17" albo "make run1", przy wpisywaniu "./a.out x y", gdzie 'x' - ilosc sekcji krytycznych, a 'y' - to ilosc wątkow