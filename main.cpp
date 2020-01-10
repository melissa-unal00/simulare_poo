#include <iostream>
using namespace std;


class formular_inscriere
{
protected:
    string nume;
    float medie_bac, nota_mate;
public:
    friend istream& operator>>(istream& in, formular_inscriere &ob);
    friend class probaIF;
    friend class probaID;
    friend class proba_a_doua_fac;


    void afisare()
    {
        cout<<"Nume: "<<nume<<endl;
        cout<<"Medie bac "<<medie_bac<<endl;
        cout<<"Nota bac mate"<<nota_mate<<endl;

    }
};

class candidat: public formular_inscriere
{
    static int nr_inreg;
    bool IF, ID;
    float medie_absolvire;
    int nr_cand;
    string prog_studiu_absolvit;
public:
    friend class probaIF;
    friend class probaID;
    friend class proba_a_doua_fac;
    candidat()
    {

    }

    friend istream& operator>>(istream& in, candidat &ob);
    void afisare_candidat()
    {
        formular_inscriere::afisare();
        if(IF==1) cout<<"Nota bacalaureat matematica: "<<nota_mate<<endl;
        if(ID==1)
        {
            cout<<"Program de studiu absolvit: "<<prog_studiu_absolvit;
            cout<<"Medie de absolire: "<<medie_absolvire;
        }
        cout<<"Numarul dumneavoastra de inregistrare este: "<<++nr_inreg<<endl;
        if(ID==1 && IF ==0)
            cout<<"ID_"<<nr_inreg<<endl;
        else if(ID==0 && IF==1)
            cout<<"IF2_"<<nr_inreg<<endl;
        else if (ID==1 && IF==1)
            cout<<"ID2_"<<nr_inreg<<endl;
        else
            cout<<nr_inreg<<endl;

    }
};

class probaIF
{
    float s1,s2;
    float nota_scris, MA;
public:
    probaIF()
    {
        nota_scris=0;
        MA=0;
    }
    friend class candidat;
    float nota()
    {
        nota_scris=(s1+s2)/2.0;
        candidat can;
        MA=0.8*nota_scris+0.2*can.medie_bac;
    }

};

class probaID
{
    float nota_oral, MA;
public:
    probaID()
    {
        nota_oral=0;
        MA=0;
    }
    friend class candidat;
    float nota()
    {
        candidat can;
        MA=0.6*nota_oral+0.2*can.nota_mate;
    }

};

class proba_a_doua_fac
{
    float nota_oral, MA;
public:
    proba_a_doua_fac()
    {
        nota_oral=0;
        MA=0;
    }
    friend class candidat;
    float nota()
    {
        candidat can;
        MA=0.6*nota_oral+0.2*can.medie_absolvire;
    }

};


int candidat::nr_inreg=0;

istream& operator >>(istream& in,formular_inscriere& ob)
{
    cout<<"Nume: ";
    in>>ob.nume;
    cout<<"Medie bac: ";
    in>>ob.medie_bac;
    cout<<"Nota mate: ";
    in>>ob.nota_mate;

}

istream& operator >>(istream& in,candidat& ob)
{
    in>>(formular_inscriere&)ob;
    cout<<"Mai studiati si la alta facultate?: "; ///1 sau 0
    in>>ob.IF;
    cout<<endl;
    in>>ob.ID;
    if(ob.IF==1)
    {
        cout<<"Cati candidati doresti sa adaugi: ";
        cin>>ob.nr_cand;
    }


}

///Unal Melissa, grupa 253, CodeBlocks

int main()
{
    int i;
    candidat *v = new candidat[100];
    int n;
    cout<<"Cati candidati doresti sa adaugi: ";
    cin>>n;
    for(i=0;i<n;i++)
        cin>>v[i];

    return 0;
}
