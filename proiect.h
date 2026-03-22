#ifndef PROIECT_H_INCLUDED
#define PROIECT_H_INCLUDED

#include <vector>
using namespace std;


class Facultate{
    string nume;
    int nr_domenii;
    string domenii_de_licenta[10];

public:
    Facultate (const string& nume_, int nr_domenii_);
    const string& getNume() const;
    int getNr_domenii() const;
    void setDomenii(int i, string domeniu);
    const string& getDomenii(int i) const;
    friend ostream& operator<<(ostream& out, const  Facultate& f);
    inline void afisareDomeniu(Facultate& f, int i) const;

    class Domeniu{
        string nume;
        int nr_discipline;
        vector<string> discipline;
        int nr_studenti_taxa;
        int nr_studenti_buget;
        string semestru;
        float medie_admitere_buget;
        int diferenta;

    public:
        Domeniu();
        const string& getNume () const{ return nume; }
        int getNr_discipline () const{ return nr_discipline; }
        const string& getDiscipline (int i) const{ return discipline[i]; }
        int getNr_studenti_taxa () const{ return nr_studenti_taxa; }
        int getNr_studenti_buget () const{ return nr_studenti_buget; }
        const string& getSemestru () const{ return semestru; }
        float getMedie () const{ return medie_admitere_buget; }
        void setDiscipline (int i, string disciplina){ discipline[i] = disciplina; }
        void setNr_discipline (){ nr_discipline = discipline.size(); }
        void setNr_studenti_taxa ( int nr_studenti_taxa_ ){ nr_studenti_taxa = nr_studenti_taxa_; }
        void setNr_studenti_buget ( int nr_studenti_buget_ ){ nr_studenti_buget = nr_studenti_buget_; }
        void setSemestru (string semestru_) { semestru = semestru_; }
        void setMedieAdmitereBuget (float medie_admitere_buget_) { medie_admitere_buget = medie_admitere_buget_; }
        void afisareDiferentaNrLocuri_TB ();
        inline Domeniu& operator=(string d);
        void nrLocuri_TB ();
        void disciplineSemestru_Curent ();
        void listaDiscipline ();
        void afisareStudenti_TB ();
        ~Domeniu();
    };

    class Student{
        string nume;
        int nr_credite;
        float medie;
        int grupa;
        string domeniu;
        float medie_admitere_buget;

    public:
        Student();
        Student ( const string& nume_, int nr_credite_, float medie_, int grupa_, const string& domeniu_);
        const string& getNume () const;
        int getNr_credite () const;
        float getMedie () const;
        int getGrupa () const;
        const string& getDomeniu () const;
        float getMedieAdmitereBuget ();
        Student& operator=(Student& other);
        ~Student();
    };

    bool admitereBuget (Student& s);
    void afisareAdmitereBuget (Student& s);
    ~Facultate();
};
#endif // PROIECT_H_INCLUDED
