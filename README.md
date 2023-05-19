# CWICZENIE 6

We wszystkich tych rzeczach -D DEBUG jest opcjonany, polecam wylaczyc bo bedzie duzo syfu w terminalu

**Uruchamianie biblioteki**

>"g++ main.cpp semaphore.cpp -std=c++17 -D DEBUG

**Uruchiamianie powielacza**

>"g++ program.cpp -o program -std=c++17 -D DEBUG; g++ main.cpp -std=c++17 -D DEBUG;"
albo 
>"make run1"

> ''./a.out X ./program Y'' 
gdzie X to ilosc procesow, ktore stworzymy, a Y to ilosc sekcji krytycznych(wartosc semafora, bo w zaleznosci ile bedzie sekcji krytycznych to tyle procesow puscimy do korzystania z nich) 

Aby wyczyscic:
>''make clean'' aby wyczyscic
