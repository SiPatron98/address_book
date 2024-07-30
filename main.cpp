#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

struct Osoba
{
    int id;
    string imie, nazwisko, nrTelefonu, email, adres;
};

int odczytajDaneZPliku(vector<Osoba> &osoby)
{
    int nrAtrybutu = 1;
    Osoba osoba;
    string linia, atrybut;
    fstream plik;
    plik.open("osoby.txt", ios::in);
    if (plik.good() == false)
    {
        cout << "Nie ma takiego pliku, tworze plik..." << endl;
        Sleep(3000);
        plik.open("osoby.txt", ios::out);
        cout << "Utworzono plik." << endl;
        Sleep(2000);
    }
    else
    {
        while(getline(plik, linia))
        {
            stringstream ss(linia);
            while(getline(ss, atrybut, '|'))
            {
                switch(nrAtrybutu)
                {
                case 1:
                    osoba.id = stoi(atrybut);
                    nrAtrybutu++;
                    break;
                case 2:
                    osoba.imie = atrybut;
                    nrAtrybutu++;
                    break;
                case 3:
                    osoba.nazwisko = atrybut;
                    nrAtrybutu++;
                    break;
                case 4:
                    osoba.nrTelefonu = atrybut;
                    nrAtrybutu++;
                    break;
                case 5:
                    osoba.email = atrybut;
                    nrAtrybutu++;
                    break;
                case 6:
                    osoba.adres = atrybut;
                    nrAtrybutu++;
                    break;
                }
                if (nrAtrybutu == 7)
                {
                    nrAtrybutu = 1;
                    osoby.push_back(osoba);
                }
            }
        }
    }
    plik.close();

    return osoby.size();
}

int dodajOsobe(vector<Osoba> &osoby)
{
    int idOstattniejOsoby;
    Osoba ostatniaOsoba;
    fstream plik;
    string imie, nazwisko, nrTelefonu, email, adres;
    Osoba osoba;
    cout << "Podaj imie: ";
    cin >> imie;
    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    cout << "Podaj numer telefonu: ";
    cin.sync();
    getline(cin, nrTelefonu);
    cout << "Podaj email: ";
    cin >> email;
    cout << "Podaj adres: ";
    cin.sync();
    getline(cin, adres);

    if (osoby.size() > 0)
    {
        ostatniaOsoba = osoby.back();
        osoba.id = ostatniaOsoba.id + 1;
    }
    else
    {
        osoba.id = 1;
    }
    osoba.imie = imie;
    osoba.nazwisko = nazwisko;
    osoba.nrTelefonu = nrTelefonu;
    osoba.email = email;
    osoba.adres = adres;

    osoby.push_back(osoba);

    plik.open("osoby.txt", ios::out | ios::app);

    plik << osoba.id << "|";
    plik << imie << "|";
    plik << nazwisko << "|";
    plik << nrTelefonu << "|";
    plik << email << "|";
    plik << adres << "|";
    plik << endl;

    plik.close();

    cout << "Dodano nowa osobe" << endl;
    Sleep(1500);

    return osoby.size();
}

void wyswietlWszystkieOsoby(vector<Osoba> osoby)
{
    system("cls");
    for (int i = 0; i < osoby.size(); i++)
    {
        cout << "ID: " << osoby[i].id << endl;
        cout << "Imie: " << osoby[i].imie << endl;
        cout << "Nazwisko: " << osoby[i].nazwisko << endl;
        cout << "Numer telefonu: " << osoby[i].nrTelefonu << endl;
        cout << "E-mail: " << osoby[i].email << endl;
        cout << "Adres: " << osoby[i].adres << endl << endl;
    }
    system("pause");
}

void wyszukajOsobyPoImieniu(vector<Osoba> osoby)
{
    string imieDoWyszukania;
    bool czyJestChociazJednaOsoba = false;
    cout << "Podaj imie, ktore chcesz wyszukac: ";
    cin >> imieDoWyszukania;
    system("cls");

    for (int i = 0; i < osoby.size(); i++)
    {
        if (osoby[i].imie == imieDoWyszukania)
        {
            czyJestChociazJednaOsoba = true;
            cout << "ID: " << osoby[i].id << endl;
            cout << "Imie: " << osoby[i].imie << endl;
            cout << "Nazwisko: " << osoby[i].nazwisko << endl;
            cout << "Numer telefonu: " << osoby[i].nrTelefonu << endl;
            cout << "E-mail: " << osoby[i].email << endl;
            cout << "Adres: " << osoby[i].adres << endl << endl;
        }
    }
    if (czyJestChociazJednaOsoba == false)
    {
        cout << "Nie ma osoby o takim imieniu" << endl;
    }
    system("pause");
}

void wyszukajOsobyPoNazwisku(vector<Osoba> osoby)
{
    string nazwiskoDoWyszukania;
    bool czyJestChociazJednaOsoba = false;
    cout << "Podaj nazwisko, ktore chcesz wyszukac: ";
    cin >> nazwiskoDoWyszukania;
    system("cls");

    for (int i = 0; i < osoby.size(); i++)
    {
        if (osoby[i].nazwisko == nazwiskoDoWyszukania)
        {
            czyJestChociazJednaOsoba = true;
            cout << "ID: " << osoby[i].id << endl;
            cout << "Imie: " << osoby[i].imie << endl;
            cout << "Nazwisko: " << osoby[i].nazwisko << endl;
            cout << "Numer telefonu: " << osoby[i].nrTelefonu << endl;
            cout << "E-mail: " << osoby[i].email << endl;
            cout << "Adres: " << osoby[i].adres << endl << endl;
        }
    }
    if (czyJestChociazJednaOsoba == false)
    {
        cout << "Nie ma osoby o takim nazwisku." << endl;
    }
    system("pause");
}

void nadpiszPlik(vector<Osoba> osoby)
{
    fstream plik;
    plik.open("osoby.txt", ios::out);

    for (Osoba osoba : osoby)
    {
        plik << osoba.id << "|";
        plik << osoba.imie << "|";
        plik << osoba.nazwisko << "|";
        plik << osoba.nrTelefonu << "|";
        plik << osoba.email << "|";
        plik << osoba.adres << "|";
        plik << endl;
    }

    plik.close();

}

void usunWybranaOsobe(vector<Osoba> &osoby)
{
    int idOsoby;
    char wybor;
    system("cls");
    cout << "----- USUWANIE OSOBY -----" << endl << endl;
    cout << "Podaj ID osoby, ktora chcesz usunac: ";
    cin >> idOsoby;

    for (size_t i = 0; i < osoby.size(); i++)
    {
        if (osoby[i].id == idOsoby)
        {
            while (true)
            {
                cout << "Czy na pewno chcesz usunac te osobe? (t/n): ";
                cin >> wybor;
                if (wybor == 't')
                {
                    osoby.erase(osoby.begin() + i);
                    cout << "Usunieto wybrana osobe" << endl;
                    Sleep(2000);
                    nadpiszPlik(osoby);
                    return;
                }
                else if (wybor == 'n')
                {
                    return;
                }
                else
                {
                    cout << "Podales nieznana opcje, poczekaj 2 sekundy i wpisz t lub n" << endl;
                    Sleep(2000);
                }
            }
        }
    }
    cout << "Nie ma osoby o podanym ID" << endl;
    Sleep(2000);
}

void edytujWybranaOsobe(vector<Osoba> &osoby)
{
    int idOsoby;
    char wybor;
    string atrybutDoZmiany;
    system("cls");
    cout << "----- EDYCJA OSOBY -----" << endl << endl;
    cout << "Podaj ID osoby, ktora chcesz edytowac: ";
    cin >> idOsoby;

    for (size_t i = 0; i < osoby.size(); i++)
    {
        if (osoby[i].id == idOsoby)
        {
            system("cls");
            cout << "----- EDYCJA OSOBY -----" << endl << endl;
            cout << "1. Imie" << endl;
            cout << "2. Nazwisko" << endl;
            cout << "3. Numer telefonu" << endl;
            cout << "4. E-mail" << endl;
            cout << "5. Adres" << endl;
            cout << "6. Powrot do menu glownego" << endl;
            cout << "Wybierz co chcesz edytowac: ";
            cin >> wybor;
            switch(wybor)
            {
            case '1':
                cout << "Podaj imie: ";
                cin >> atrybutDoZmiany;
                osoby[i].imie = atrybutDoZmiany;
                nadpiszPlik(osoby);
                cout << "Dokonano edycji" << endl;
                Sleep(1000);
                return;

            case '2':
                cout << "Podaj nazwisko: ";
                cin >> atrybutDoZmiany;
                osoby[i].nazwisko = atrybutDoZmiany;
                nadpiszPlik(osoby);
                cout << "Dokonano edycji" << endl;
                Sleep(1000);
                return;

            case '3':
                cout << "Podaj numer telefonu: ";
                cin.sync();
                getline(cin, atrybutDoZmiany);
                osoby[i].nrTelefonu = atrybutDoZmiany;
                nadpiszPlik(osoby);
                cout << "Dokonano edycji" << endl;
                Sleep(1000);
                return;

            case '4':
                cout << "Podaj e-mail: ";
                cin >> atrybutDoZmiany;
                osoby[i].email = atrybutDoZmiany;
                nadpiszPlik(osoby);
                cout << "Dokonano edycji" << endl;
                Sleep(1000);
                return;

            case '5':
                cout << "Podaj adres: ";
                cin.sync();
                getline(cin, atrybutDoZmiany);
                osoby[i].adres = atrybutDoZmiany;
                nadpiszPlik(osoby);
                cout << "Dokonano edycji" << endl;
                Sleep(1000);
                return;

            case '6':
                return;
            }
        }
    }
    cout << "Nie ma osoby o podanym ID" << endl;
    Sleep(2000);
}

int main()
{
    vector <Osoba> osoby;
    int idOstatniejOsoby = 0;
    int iloscOsob = 0;
    char wybor;

    iloscOsob = odczytajDaneZPliku(osoby);

    while(true)
    {
        system("cls");
        cout << "<<<<< KSIAZKA ADRESOWA >>>>>" << endl << endl;
        cout << "----- MENU GLOWNE -----" << endl;
        cout << "1. Dodaj osobe" << endl;
        cout << "2. Wyszukaj osobe po imieniu" << endl;
        cout << "3. Wyszukaj osobe po nazwisku" << endl;
        cout << "4. Wyswietl wszystkie osoby" << endl;
        cout << "5. Usun osobe" << endl;
        cout << "6. Edytuj osobe" << endl;
        cout << "9. Zakoncz program" << endl;
        cin >> wybor;
        switch(wybor)
        {
        case '1':
            iloscOsob = dodajOsobe(osoby);
            break;
        case '2':
            wyszukajOsobyPoImieniu(osoby);
            break;

        case '3':
            wyszukajOsobyPoNazwisku(osoby);
            break;
        case '4':
            wyswietlWszystkieOsoby(osoby);
            break;
        case '5':
            usunWybranaOsobe(osoby);
            break;
        case '6':
            edytujWybranaOsobe(osoby);
            break;

        case '9':
            exit(0);

        default:
            cout << "Podano nieobslugiwana opcje, poczekaj 3 sekundy i  wybierz cos innego." << endl;
            Sleep(3000);

        }
    }
    return 0;
}
