#include <iostream>
#include<string.h>
using namespace std;
class persoana{
  protected:
      int id;
      static int next_id;
      char *nume;
  public:
      static int next_idd();
      persoana(char *);
      virtual ~persoana();
      persoana(const persoana &);
      int get_id() {return id;};
      char * get_nume() {return nume;}
      persoana & operator=(persoana &);
      friend istream & operator >>(istream &, persoana &);
      friend ostream & operator <<(ostream &, persoana &p);
};
int persoana::next_id=0;
int persoana::next_idd()
{
    next_id++;
    return next_id;
}
persoana & persoana::  operator=(persoana &p)
{
    id=p.id;
    nume=new char[strlen(p.nume)];
    strcpy(nume,p.nume);
    return *this;
}
persoana:: persoana(const persoana &p)
{
    id=p.id;
    nume=new char[strlen(p.nume)];
    strcpy(nume, p.nume);

}
istream & operator>>(istream &in, persoana &p)
{
   cout<<"introduceti numele persoanei:\n";
   in>>p.nume;
    return in;
}

ostream & operator<<(ostream &out, persoana &p)
{
    out<<"Persoana cu id-ul ";
    out<<p.id;
    out<<" se numeste ";
    int a=strlen(p.nume);
    for(int i=0;i<a;i++)
    out<<p.nume[i];
    return out;
}
persoana::persoana(char *s=(char*)"\0")
{
    id=next_idd();
    nume =new char [strlen(s)];
    strcpy(nume,s);

}
persoana::~persoana()
{
    delete [] nume;
    cout<<"Persoana distrusa...\n";
}
class abonat:public persoana{
   protected:
       char *nr_telefon;
   public:
       abonat(char *, char *);
       virtual ~abonat();
       abonat(const abonat &);
       abonat & operator=(const abonat &);
       virtual void citire(istream &);
       virtual void afisare(ostream &);
       friend ostream & operator<<(ostream &, abonat &);
};
void abonat::afisare(ostream &out)
{
    out<<"Abonatul nu are skype\n";
    out<<"id-ul abonatului este: ";
    out<<id<<" \n";
    out<<"numele acestuia este: ";
    out<<nume<<"\n";
    out<<"nr de telefon: ";
    out<<nr_telefon<<"\n";
}
void abonat:: citire(istream &in)
{
    persoana &p=*this;
    in>>p;
    cout<<"nr de tel:\n";
    in>>nr_telefon;
}
abonat & abonat :: operator=(const abonat &a)
{
    id=a.id;
    nume=new char[strlen(a.nume)];
    strcpy(nume,a.nume);
    nr_telefon=new char[strlen(a.nr_telefon)];
    strcpy(nr_telefon,a.nr_telefon);
    return *this;
}
abonat:: abonat(const abonat &a)
{
    id=a.id;
    nume=new char[strlen(a.nume)];
    strcpy(nume,a.nume);
    nr_telefon=new char[strlen(a.nr_telefon)];
    strcpy(nr_telefon,a.nr_telefon);

}

abonat::abonat(char *s1=(char*)"\0", char *s2=(char*)"\0"):persoana(s1)
{
    nr_telefon=new char[strlen(s2)];
    strcpy(nr_telefon,s2);
}
abonat::~abonat()
{
    delete [] nr_telefon;
    cout<<"Abonat distrus...\n";
}
class abonat_skype:public abonat{
   protected:
       char id_skype[50];
   public:
       abonat_skype(char *, char *, char *);
       virtual ~abonat_skype();
       abonat_skype(abonat_skype &);
       abonat_skype & operator=(abonat_skype &);
       void citire(istream &)=0;
       void afisare(ostream &out);
};
void abonat_skype::afisare(ostream &out)
{
    out<<"id-ul abonatului este: ";
    out<<id<<" \n";
    out<<"numele acestuia este: ";
    out<<nume<<"\n";
    out<<"nr de telefon: ";
    out<<nr_telefon<<"\n";
    out<<"id-ul de skype: ";
    out<<id_skype<<"\n";
}
void abonat_skype:: citire(istream &in)
{
    cout<<"introduceti numele abonatului skype:\n";
    in>>nume;
    cout<<"introduceti nr de telefon:\n";
    in>>nr_telefon;
    cout<<"\nintroduceti id-ul de skype al abonatului skype:\n";
    in>>id_skype;
}
abonat_skype::abonat_skype(abonat_skype &as)
{
    id=as.id;
    nume=new char[strlen(as.nume)];
    strcpy(nume,as.nume);
    nr_telefon=new char[strlen(as.nr_telefon)];
    strcpy(nr_telefon,as.nr_telefon);
    strcpy(id_skype,as.id_skype);

}
abonat_skype & abonat_skype:: operator=(abonat_skype &as)
{
    id=as.id;
    nume=new char[strlen(as.nume)];
    strcpy(nume,as.nume);
    nr_telefon=new char[strlen(as.nr_telefon)];
    strcpy(nr_telefon,as.nr_telefon);
    strcpy(id_skype,as.id_skype);
    return *this;
}
abonat_skype::~abonat_skype()
{
  cout<<"Abonat skype distrus...\n";
}
abonat_skype::abonat_skype(char *s1=(char*)"\0", char *s2=(char*)"\0", char *s3=(char*)"\0"):abonat(s1,s2)
{
    strcpy(id_skype,s3);
}
class abonat_skype_romania:public abonat_skype{
       char adresa_mail[50];
   public:
       abonat_skype_romania(char *s1, char *s2, char *s3, char *s4);
       virtual ~abonat_skype_romania();
       abonat_skype_romania(abonat_skype_romania&);
       abonat_skype_romania& operator=(abonat_skype_romania&);
       void citire(istream &in);
       void afisare(ostream &out);
};
void abonat_skype_romania::afisare(ostream &out)
{
    out<<"Abonatul are skype si este din Romania\n";
    out<<"id-ul abonatului este: ";
    out<<id<<" \n";
    out<<"numele acestuia este: ";
    out<<nume<<"\n";
    out<<"nr de telefon: ";
    out<<nr_telefon<<"\n";
    out<<"id-ul de skype: ";
    out<<id_skype<<"\n";
    out<<"adresa de mail: ";
    out<<adresa_mail<<"\n";
}
void abonat_skype_romania:: citire(istream &in)
{
    cout<<"introduceti numele:\n";
    in>>nume;
    cout<<"introduceti numarul de telefon:\n";
    in>>nr_telefon;
    cout<<"introduceti id-ul de skype:\n";
    in>>id_skype;
    cout<<"introduceti adresa acestuia de e-mail:\n";
    in>>adresa_mail;
}
abonat_skype_romania::abonat_skype_romania(abonat_skype_romania &asr)
{
    id=asr.id;
    nume=new char[strlen(asr.nume)];
    strcpy(nume,asr.nume);
    nr_telefon=new char[strlen(asr.nr_telefon)];
    strcpy(nr_telefon,asr.nr_telefon);
    strcpy(id_skype,asr.id_skype);
    strcpy(adresa_mail,asr.adresa_mail);
}
abonat_skype_romania & abonat_skype_romania::operator=(abonat_skype_romania& asr)
{
    id=asr.id;
    nume=new char[strlen(asr.nume)];
    strcpy(nume,asr.nume);
    nr_telefon=new char[strlen(asr.nr_telefon)];
    strcpy(nr_telefon,asr.nr_telefon);
    strcpy(id_skype,asr.id_skype);
    strcpy(adresa_mail,asr.adresa_mail);
    return *this;
}

abonat_skype_romania::abonat_skype_romania(char *s1=(char*)"\0", char *s2=(char*)"\0", char *s3=(char*)"\0", char *s4=(char*)"\0"):abonat_skype(s1, s2, s3)
{
    strcpy(adresa_mail, s4);
}
abonat_skype_romania::~abonat_skype_romania()
{
   cout<<"Abonat skype romania distrus...\n";
}
class abonat_skype_extern:public abonat_skype{
       char tara[50];
   public:
       abonat_skype_extern( char *s1, char *s2, char *s3, char *s4);
       virtual ~abonat_skype_extern();
       abonat_skype_extern(abonat_skype_extern&);
       abonat_skype_extern & operator=(abonat_skype_extern&);
       void citire(istream &in);
       void afisare(ostream &out);

};
void abonat_skype_extern:: afisare(ostream &out)
{
    out<<"Abonatul are skype si este din alta tara\n";
    out<<"id-ul abonatului este: ";
    out<<id<<" \n";
    out<<"numele acestuia este: ";
    out<<nume<<"\n";
    out<<"nr de telefon: ";
    out<<nr_telefon<<"\n";
    out<<"id-ul de skype: ";
    out<<id_skype<<"\n";
    out<<"tara: ";
    out<<tara<<"\n";
}
void abonat_skype_extern :: citire(istream &in)

{
    cout<<"introduceti numele:\n";
    in>>nume;
    cout<<"introduceti numarul de telefon:\n";
    in>>nr_telefon;
    cout<<"introduceti id-ul de skype:\n";
    in>>id_skype;
    cout<<"introduceti tara acestuia\n";
    in>>tara;
}
abonat_skype_extern::abonat_skype_extern(abonat_skype_extern &ase)
{
    id=ase.id;
    nume=new char[strlen(ase.nume)];
    strcpy(nume,ase.nume);
    nr_telefon=new char[strlen(ase.nr_telefon)];
    strcpy(nr_telefon,ase.nr_telefon);
    strcpy(id_skype,ase.id_skype);
    strcpy(tara,ase.tara);

}
abonat_skype_extern &abonat_skype_extern::operator=(abonat_skype_extern& ase)
{
    id=ase.id;
    nume=new char[strlen(ase.nume)];
    strcpy(nume,ase.nume);
    nr_telefon=new char[strlen(ase.nr_telefon)];
    strcpy(nr_telefon,ase.nr_telefon);
    strcpy(id_skype,ase.id_skype);
    strcpy(tara,ase.tara);
    return *this;
}
abonat_skype_extern::~abonat_skype_extern()
{
    cout<<"Abonat skype extern distrus...\n";
}
abonat_skype_extern::abonat_skype_extern(char *s1=(char*)"\0", char *s2=(char*)"\0", char *s3=(char*)"\0", char *s4=(char*)"\0"):abonat_skype(s1,s2,s3)
{
    strcpy(tara, s4);
}
istream & operator>>(istream &in,abonat &a)
{
    a.citire(in);
    return in;

}
ostream & operator <<(ostream &out,abonat &a)
{
    a.afisare(out);
    return out;
}
class agenda{
       int n;
       abonat **A;
   public:
       agenda(int);
       ~agenda();
       void creare_agenda();
       abonat & operator [](const char*);
};
agenda::~agenda()
{

    for(int i=0;i<n;i++)
        delete A[i];
    delete [] A;
    cout<<"Agenda distrusa...\n";
}
abonat & agenda:: operator[](const char* s)
{
    int ok=0;
    char p[30];
    strcpy(p,s);
    while(ok==0)
      {for(int i=0;i<n;i++)
       if(strcmp(p,(char *)A[i]->get_nume())==0)
            {ok=1; return *A[i];}
      cout<<"nu exista numele in agenda,reintroduceti\n";
      cin>>p;
      }

}
void agenda::creare_agenda()
{
    int x,i=0;
    cout<<"Pentru a introduce cele "<<n<<" persoane, inainte de a le scrie datele, specificati ce fel de abonati sunt astfel:\n";
    cout<<"1.Abonat fara skype\n2.Abonat cu skype\n";
    while(i<n)
    {   cout<<"introduceti comanda pentru abonatul "<<i<<"\n";
        cin>>x;
        if(x==1)
            {A[i]=new abonat;
             cin>>*A[i];
             i++;}
        else if(x==2)
            {
              cout<<"1.este din romania\n2.este din alta tara\n";
              cin>>x;
              if(x==1)
                {A[i]=new abonat_skype_romania;
                 cin>>(*A[i]);
                 i++;}
              else if(x==2)
                {A[i]=new abonat_skype_extern;
                 cin>>(*A[i]);
                 i++;}
             }
        else cout<<"nu exista aceasta comanda\n";
    }
}
agenda::agenda(int x=0)
{   n=x;
    A=new abonat*[n];

}
int main()
{
   int x,i;
   char s1[50];
   cout<<"Introduceti numarul de abonati din agenda:";
   cin>>x;
   agenda A1(x);
   A1.creare_agenda();
   while(1)
   {cout<<"vreti sa aflati informatii despre un abonat?\n1)DA\n0)NU\n";
    cin>>i;
    if(i==1)
    {cout<<"Introduceti numele persoanei despre care vreti sa aflati informatii:\n";
     cin>>s1;
     cout<<A1[s1];}
    else if(i==0) break;
   }
   return 0;
}
