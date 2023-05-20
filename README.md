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

We wszystkich tych rzeczach -D DEBUG jest opcjonany, polecam wylaczyc bo bedzie duzo syfu w terminalu

* **Uruchamianie biblioteki:**

    >"g++ main.cpp semaphore.cpp -std=c++17 -D DEBUG

* **Uruchiamianie powielacza:**

    >"g++ program.cpp -o program -std=c++17 -D DEBUG; g++ main.cpp -std=c++17 -D DEBUG;"
    albo 
    >"make run1"

    > ''./a.out X ./program Y'' 
    gdzie X to ilosc procesow, ktore stworzymy, a Y to ilosc sekcji krytycznych(wartosc semafora, bo w zaleznosci ile bedzie sekcji krytycznych to tyle procesow puscimy do korzystania z nich) 

    Aby wyczyscic:
    >''make clean'' aby wyczyscic
