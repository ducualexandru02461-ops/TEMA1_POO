#include <iostream>
#include <vector>
#include "proiect.h"
#include "proiect.cpp"
using namespace std;

int main()
{
    vector<string> domenii_de_licenta = {"Informatica", "Matematica", "Calculatoare si Tehnologia Informatiei"};
    Facultate facultate ("Facultatea de Matematica si Informatica",domenii_de_licenta.size());
    cout << "\n" << "   ->BINE ATI VENIT LA:" << "\n\n";
    cout << facultate;
    cout << "\n" << "   ->IN CONTINUARE VA PREZENTAM DOMENIILE FACULTATII:" << "\n\n";
    for (int i = 0; i < facultate.getNr_domenii(); ++i){
        facultate.setDomenii(i,domenii_de_licenta[i]);
        facultate.afisareDomeniu(facultate,i);
    }
    Facultate :: Domeniu domeniu;
    string d1,d2,d3,s1,s2;
    d1 = "Informatica";
    d2 = "Matematica";
    d3 = "Calculatoare si Tehnologia Informatiei";
    s1 = "Semestrul I";
    s2 = "Semestrul II";
    domeniu = d2;
    domeniu.setSemestru(s2);
    domeniu.nrLocuri_TB();
    domeniu.disciplineSemestru_Curent();
    domeniu.setNr_discipline();
    cout << "\n" << "   ->Bine ati venit la domeniul de licenta: " << domeniu.getNume() << "\n\n";
    cout << "   ->In continuare veti studia:" << "\n";
    domeniu.listaDiscipline();
    domeniu.afisareStudenti_TB();
    domeniu.afisareDiferentaNrLocuri_TB();

    float medie1, medie2, medie3;

    medie1 = 6.5;
    medie2 = 5.5;
    medie3 = 6.75;

    Facultate :: Student student1("George", 40, medie1, 132, d1);
    Facultate :: Student student2("Mihai", 50, medie2, 104, d2);
    Facultate :: Student student3("Ionel", 45, medie3, 161, d3);

    facultate.afisareAdmitereBuget(student1);
    facultate.afisareAdmitereBuget(student2);
    facultate.afisareAdmitereBuget(student3);
    cout << "\n";
    return 0;
}
