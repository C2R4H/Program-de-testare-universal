//VERSIUNEA 0.1 (NU LUCREAZA)


#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
  ifstream read;
  read.open("Test.txt");

  int Ni , Ki;
  string line;

  string test_read = "Test:";
  string intrebari_read = "Intrebari:";
  bool afisam_intrebari = false;

  while(getline (read, line)){
  string word_temp;

  bool show_intrebarea = false;
  bool get_numbers = false;
  int get_raspunsuri = 0;
  int get_raspuns_corect;
  int get_numarul_de_raspunsuri;

    for(int i = 0;i<line.size();i++){
      word_temp.push_back(line[i]);
      if(test_read==word_temp){
        cout<<"Numele Testului : ";
        for(int j = i+1;j<line.size();j++){
          cout<<line[j];i++;
        }
        cout<<endl;
        word_temp.clear();
      }

      else if(word_temp==intrebari_read && afisam_intrebari==false)
        afisam_intrebari = true;

      //Lucram cu intrebarile
      else if(afisam_intrebari == true){
         if(isdigit(line[i]) && get_numbers == false){
          char c = line[i];
          get_numarul_de_raspunsuri = c -'0';
          char c2= line[i+1];
          get_raspuns_corect = c2 -'0';
          get_numbers = true;
          i+=3;
        }

        else if(show_intrebarea==false){
          int l = i;
          while(line[l]!='?'){
            cout<<line[l];
            l++;
          }cout<<"?"<<endl;
          show_intrebarea = true;
        }

        else if(get_raspunsuri<get_numarul_de_raspunsuri && show_intrebarea==true){
          int o = i;
          cout<<"LINE="<<line[o]<<endl;
          word_temp.clear();
          for(get_raspunsuri = 0;get_raspunsuri<get_numarul_de_raspunsuri;get_raspunsuri++){
            if(line[o]==' ')
              o++;
            while(line[o]!=' '){
              cout<<line[o];
              o++;
            }cout<<endl;
            word_temp.clear();
          }

        }

      }
    }
  }
}
