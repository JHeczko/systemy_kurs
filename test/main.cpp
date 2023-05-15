#include <string>
#include <iostream>

using namespace std;

int main(){
    int licznik = 22;
    string adres = "./adres";
    adres += to_string(licznik);
    string adres1 = adres;
    cout << adres1;

}