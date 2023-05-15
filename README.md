# cwiczenie 6

Flagi do kompilacji bibliteki "g++ main.cpp semaphore.cpp -std=c++17 -D DEBUG"
Flagi do kompilacji zadania z powielaczem "g++ program.cpp -o program -std=c++17 -D DEBUG; g++ main.cpp -std=c++17 -D DEBUG;"
# Uruchamianie biblioteki

# Uruchiamianie powielacza
"g++ program.cpp -o program -std=c++17 -D DEBUG; g++ main.cpp -std=c++17 -D DEBUG;"

"./a.out X ./program Y" - gdzie X to ilosc procesow, ktore stworzymy, a Y to ilosc sekcji krytycznych(wartosc semafora, bo w zaleznosci ile bedzie sekcji krytycznych to tyle procesow puscimy do korzystania z nich) 