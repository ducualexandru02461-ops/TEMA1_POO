#include "proiect.h"
#include <iostream>

///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!CONTINUT CLASA FACULTATE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!///
Facultate :: Facultate (const string& nume_, int nr_domenii_){
    nume = nume_;
    nr_domenii = nr_domenii_;
}
const string& Facultate :: getNume() const{ return nume; }
int Facultate :: getNr_domenii() const{ return nr_domenii; }
void Facultate :: setDomenii(int i, string domeniu){ domenii_de_licenta[i] = domeniu; }
const string& Facultate :: getDomenii(int i) const{ return domenii_de_licenta[i]; }
ostream& operator<<(ostream& out, const  Facultate& f) {
    out << "~~~" << f.getNume() << "~~~" << "\n";
    return out;
}
inline void Facultate :: afisareDomeniu(Facultate& f, int i) const {
    cout << "~~~" << f.getDomenii(i) << "~~~" << "\n";
}

Facultate :: ~Facultate () {};

///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!CONTINUT CLASA DOMENIU!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!///
Facultate :: Domeniu :: Domeniu(){}

void Facultate :: Domeniu :: afisareDiferentaNrLocuri_TB () {
    if (nr_studenti_buget > nr_studenti_taxa){
        diferenta = nr_studenti_buget - nr_studenti_taxa;
    }
    else diferenta = nr_studenti_taxa - nr_studenti_taxa;
    cout << "\n   ->Diferenta dintre numarul de locuri de la buget si numarul de locuri de la taxa este: " << diferenta << "\n";
}

inline Facultate :: Domeniu& :: Facultate :: Domeniu :: operator=(string d){ ///declararea operatorului "=" pentru clasa Domeniu
    nume = d;
    return *this;
}

void Facultate :: Domeniu :: nrLocuri_TB () {
    if(nume == "Informatica"){
        nr_studenti_buget = 206;
        nr_studenti_taxa = 44;
        medie_admitere_buget = 6.71;
    }
    else if (nume == "Matematica"){
        nr_studenti_buget = 109;
        nr_studenti_taxa = 100;
        medie_admitere_buget = 5.35;
    }
        else if (nume == "Calculatoare si Tehnologia Informatiei"){
            nr_studenti_buget = 85;
            nr_studenti_taxa = 15;
            medie_admitere_buget = 5.12;
        }
}

void Facultate :: Domeniu :: disciplineSemestru_Curent (){
    if (semestru == "Semestrul I"){
        if (nume == "Informatica"){
            discipline = {"Arhitectura Sistemelor de Calcul","Programarea Algoritmilor","Instrumente si Tehnici de Baza in Informatica",
                            "Tehnici Web","Calcul Diferential si Integral","Structuri Algebrice in Informatica"};
        }
        else if (nume == "Matematica"){
            discipline = {"Programare Procedurala", "Algebra", "Geometrie I", "Algebra liniara", "Analiza matematica I"};
        }
            else if (nume == "Calculatoare si Tehnologia Informatiei"){
                discipline = {"Utilizarea sistemelor de operare", "Algebra si Geometrie", "Analiza matematica", "Programarea calculatoarelor"};
            }
    }
    else if (semestru == "Semestrul II"){
        if (nume == "Informatica"){
            discipline = {"Structuri de Date","Limbaje Formale si Automate","Baze de Date","Programare Orientata pe Obiecte",
                        "Logica Matematica si Computationala","Geometrie si Algebra Liniara"};
        }
        else if (nume == "Matematica"){
            discipline = {"Logica matematica", "Elemente de calcul stiintific", "Geometrie II", "Algebra", "Analiza Matematica II"};
        }
            else if (nume == "Calculatoare si Tehnologia Informatiei"){
                discipline = {"Grafica asistata pe calculator", "Calcul numeric", "Matematici speciale", "Programarea calculatoarelor II"};
            }
    }
}

void Facultate :: Domeniu :: listaDiscipline () {
    cout << "\n";
    for (int i = 0; i < nr_discipline; i++){
        cout << "~" << discipline[i] << "~" << "\n";
    }
    cout << "\n";
}

void Facultate :: Domeniu :: afisareStudenti_TB () {
    cout << "   ->Pentru domeniul " << nume << ", numarul locurilor disponibile pentru buget este " << nr_studenti_buget << ", iar pentru taxa este " << nr_studenti_taxa;
}

Facultate :: Domeniu :: ~Domeniu(){}


///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!CONTINUT CLASA STUDENT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!///
Facultate :: Student :: Student(){}
Facultate :: Student :: Student ( const string& nume_, int nr_credite_, float medie_, int grupa_, const string& domeniu_){
    nume = nume_;
    nr_credite = nr_credite_;
    medie = medie_;
    grupa = grupa_;
    domeniu = domeniu_;
};
const string& Facultate :: Student :: getNume () const{ return nume; }
int Facultate :: Student ::getNr_credite () const{ return nr_credite; }
float Facultate :: Student :: getMedie () const{ return medie; }
int Facultate :: Student :: getGrupa () const{ return grupa; }
const string& Facultate :: Student :: getDomeniu () const{ return domeniu; }
float Facultate :: Student :: getMedieAdmitereBuget () {
    if (domeniu == "Informatica"){
        medie_admitere_buget = 6.71;
    }
    else if (domeniu == "Matematica"){
        medie_admitere_buget = 5.35;
    }
        else if (domeniu == "Calculatoare si Tehnologia Informatiei"){
            medie_admitere_buget = 5.12;
        }
    return medie_admitere_buget;
}

Facultate::Student& :: Facultate::Student :: operator=(Student& other){
    nume = other.nume;
    grupa = other.grupa;
    domeniu = other.domeniu;
    return *this;
}

bool Facultate :: admitereBuget (Student& s) {
    if (s.getMedie() >= s.getMedieAdmitereBuget()){
        return true;
    }
    else return false;
}

void Facultate :: afisareAdmitereBuget (Student& s) {
    cout << "\n   ->";
    if (admitereBuget(s)){
        cout << "Studentul " << s.getNume() << " de la grupa " << s.getGrupa() << " a fost admis la buget la domeniul " << s.getDomeniu() << ".";
    }
    else cout << "Studentul " << s.getNume() << " de la grupa " << s.getGrupa() << " nu a fost admis la buget la domeniul " << s.getDomeniu() << ".";
}

Facultate :: Student :: ~Student(){};
