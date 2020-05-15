#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


void show_calificativ(double nr){
  if(nr==100)
    cout<<"EXCELENT"<<endl;
  else if(nr>80)
    cout<<"BINE"<<endl;
  else if(nr>50)
    cout<<"SATISFACATOR"<<endl;
  else if(50>nr)
    cout<<"BAD"<<endl;
}

string nume_test;
vector<string> intrebari; //Salvam intrebarile intrun vector
vector<string> raspunsuri; //Salvam raspunsurile intrun vector
vector<int> raspunsuri_totale;
vector<int> raspunsuri_corecte;

int main(){
  ifstream read;
  read.open("Test.txt");

  string read_test = "Test:";
  string read_intrebari = "Intrebari:";

  string line;
  bool getintrebari = false;
  bool console_show_input = false;
  while(getline (read, line)){

    bool get_question = false; //E adevarat daca avem intrebarea salvata
    bool get_numbers = false; //E adevarat daca avem numarul de raspunsuri

    int time_i = 1;
    string word_temp;
    string raspunsuri_temp;
    for(int i = 0;i<line.size();i++){
      if(line[i]!=';')
        word_temp.push_back(line[i]);

      if(word_temp==read_test){
        for(int j = i+1;j<line.size();j++)
          nume_test.push_back(line[j]);
        word_temp.clear();
        break;
      }

      else if(word_temp==read_intrebari)
        getintrebari = true;
      
      else if(getintrebari==true){
        int Ni;//Numarul de raspunsuri alternative la intrebarea i 
        int Ki;//Numarul de raspunsuri alternative la intrebarea i 

        //Salvam intrebarea intrun vector
        if(line[i]=='?' && get_question == false ){
          intrebari.push_back(word_temp);
          get_question = true;
          word_temp.clear();
        }

        //Aflam cite raspunsuri are(Ni) si care este corecta (Ki)
        else if(get_numbers==false && get_question == true && isdigit(line[i])){
          get_numbers = true;
          char n = line[i];
          char k = line[i+2];
          Ni = n - '0';
          Ki = k - '0';
          raspunsuri_totale.push_back(Ni);
          raspunsuri_corecte.push_back(Ki);
          i+=3;
          word_temp.clear();
        }

        //Afisam raspunsurile la intrebare
        else if(get_numbers == true){
          if(line[i]==' ' || line[i]==';'){
            raspunsuri_temp.append(word_temp);
            word_temp.clear();
            if(time_i==Ni)
              raspunsuri.push_back(raspunsuri_temp);
            time_i+=1;
          }
        }
      }
    }
  }


  double calificativ = 0;
  cout<<"Testul : "<<nume_test<<endl;
  cout<<endl;
  for(int i = 0;i<intrebari.size();i++){
    cout<<"Intrebarea : "<<intrebari[i]<<endl;
    cout<<endl;
    string word_temp = raspunsuri[i];
    for(int l = 0;l<raspunsuri[i].size();l++){
      if(word_temp[l]!=' ')
        cout<<word_temp[l];
      else
        cout<<endl;
    }cout<<endl;
    cout<<endl;
    
    int nr;
    cout<<"Introduceti raspunsul : ";cin>>nr;
    if(nr==raspunsuri_corecte[i])
      calificativ++;
  }

  calificativ = (calificativ / raspunsuri.size()) * 100;
  cout<<endl;
  show_calificativ(calificativ);

}
