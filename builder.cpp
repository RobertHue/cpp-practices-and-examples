#include <iostream>
#include <string>
#include <memory>

using namespace std;

// github test...

// Produkt 
class Mahlzeit {
};

// konkretes Produkt
class Pizza : public Mahlzeit {
public:
    Pizza() {
        cout << "Pizza gebacken." << endl;
    }
};

// noch ein konkretes Produkt
class Rostwurst : public Mahlzeit {
public:
    Rostwurst(const string& beilage) {
        cout << "Rostwurst gebraten." << endl;
        if (!beilage.empty()) {
            cout << "Serviert mit " << beilage << endl;
        }
    }
};



// Erzeuger
class Restaurant {
protected:
    shared_ptr<Mahlzeit> mahlzeit;

    // Die abstrakte Factory-Methode, die von Erzeugern implementiert werden muss.
    virtual void MahlzeitZubereiten() = 0;

    virtual void BestellungAufnehmen() {
        cout << "Ihre Bestellung bitte!" << endl;
    }

    virtual void MahlzeitServieren() {
        cout << "Hier Ihre Mahlzeit. Guten Appetit!" << endl;
    }

public:
    // Diese Methode benutzt die Factory-Methode.
    void MahlzeitLiefern() {
        BestellungAufnehmen();
        MahlzeitZubereiten(); // Aufruf der Factory-Methode
        MahlzeitServieren();
    }
};

// konkreter Erzeuger für konkretes Produkt "Pizza"
class Pizzeria : public Restaurant {
protected:
    // Implementierung der abstrakten Methode der Basisklasse
    virtual void MahlzeitZubereiten() {
        mahlzeit = make_shared<Pizza>();
    }
};

// konkreter Erzeuger für konkretes Produkt "Rostwurst"
class Rostwurstbude : public Restaurant {
protected:
    // Implementierung der abstrakten Methode der Basisklasse
    virtual void MahlzeitZubereiten() {
        mahlzeit = make_shared<Rostwurst>("Pommes und Ketchup");
    }
};




int main() {
    Pizzeria daToni;
    daToni.MahlzeitLiefern();
	cout << endl;


    Rostwurstbude brunosImbiss;
    brunosImbiss.MahlzeitLiefern();
	cout << endl;

	
	system("Pause");
	return 0;
}
