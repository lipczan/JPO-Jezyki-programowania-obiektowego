//wymagane biblioteki
#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <streambuf>
#include <sstream>

using namespace std;

/////////////////////////////////UWAGA////////////////////////////////////////////////
//program do dzia�ania wymaga plik�w: 
//kartoteka.txt
//macbeth.txt
//dane1.txt
//dane2.txt
//dane3.txt

bool isPunct (char c)
{
    if (c == '[' || c == ']' || c == '&' || c == '-' || c=='!' || c == ':' || c=='?' || c==' ' || c=='"' || c==',' || c=='.' || c==';' || c=='(' || c==')' || c=='\'')
        return true;
    else 
        return false;
}

const string phys_data(R"(
Speed:	366
Mass:	35
Point: 50 70
Speed:	378
Mass:	32
Point: 25 35
Speed:	400
Mass:	30
Point: 23 16)");

class Tekst {
public:
    string SciezkaPrim_;
    Tekst(string SciezkaPrim) {
        SciezkaPrim_ = SciezkaPrim;
    }
    ~Tekst() {}
    virtual void Wypisz() {

    }
    virtual void PrzetworzTekst() = 0;
};

class LiczbyWTekscie :public Tekst{
private:
    //string SciezkaPrim_;
    string SciezkaBis_;
public:
    LiczbyWTekscie(string SciezkaPrim,string SciezkaBis)
        :Tekst(SciezkaPrim){
        SciezkaBis_ = SciezkaBis;
        //SciezkaPrim_ = SciezkaPrim;
        this->PrzetworzTekst();
        this->Wypisz();
    };
    ~LiczbyWTekscie() {};
    void virtual PrzetworzTekst() {
        fstream file;
        file.open(SciezkaPrim_);

        fstream przepis;
        przepis.open(SciezkaBis_);

        regex pattern(R"((\+|-)?[[:digit:]]+)");
        //regex pattern_2(R"(((\+|-)?[[:digit:]]+)(\.(([[:digit:]]+)?))?((e|E)((\+|-)?)[[:digit:]]+)?)");

        string data;
        smatch wynik;

        while (getline(file, data)) {
            while (regex_search(data, wynik, pattern)) {
                przepis << wynik[0] << ".0 ";

                data = wynik.suffix().str();
            }
            przepis << endl;
        }

        przepis.close();
        file.close();
    }
    virtual void Wypisz() {
        fstream file;
        file.open(SciezkaPrim_);

        fstream przepis;
        przepis.open(SciezkaBis_);
 
        regex pattern_2(R"(((\+|-)?[[:digit:]]+)(\.(([[:digit:]]+)?))?((e|E)((\+|-)?)[[:digit:]]+)?)");
        regex pattern(R"((\+|-)?[[:digit:]]+)");

        string data;
        smatch wynik;

        ifstream jp2(SciezkaBis_);
        stringstream buffer;
        buffer << jp2.rdbuf();
        string data_2 = buffer.str();
        smatch wynik_2;

        while (getline(file, data)) {
            while (regex_search(data, wynik, pattern) and regex_search(data_2, wynik_2, pattern_2)) {

                cout << wynik[0] << " ";
                cout << wynik_2[0] << " ";
                cout << endl;

                data_2 = wynik_2.suffix().str();
                data = wynik.suffix().str();
            }
            cout << endl;
        }

    }
};

int main()
{
    int nr;
    bool t=true;
   
    while(t){
        cout << "Menu wyboru: \n";
        cout << "1. JPO lab 7b zad. 2\n";
        cout << "2. JPO lab 7b zad. 3\n";
        cout << "3. JPO lab 8 zad. 1\n";
        cout << "5. Kartoteka medyczna\n";
        cout << "6. Plik liczbowy\n";
        cout << "7. Pliki tekstowe\n";
        cout << "Wybor: ";
        cin>>nr;
        switch(nr){
            case 1:{
                ifstream input;
                input.open("macbeth.txt");
                int lines = 0;
                string words;
                vector<string> stringHolder;

                while (input >> words) {
                    remove_if(words.begin(), words.end(), isPunct);
                    words.erase(remove_if(words.begin(), words.end(), isPunct), words.end());
                    transform(words.begin(), words.end(), words.begin(), tolower);
                    stringHolder.push_back(words);
                }

                sort(stringHolder.begin(), stringHolder.end());

                int vSize = stringHolder.size();

                int wordCount = 1;
                words = stringHolder[0];

                int counter = 0;
                int tmp = 0, tmp_2 = 0;


                string input_word;
                cout << "Wprowadz poszukiwane slowo: ";
                cin >> input_word;

                for (int i = 1; i < vSize; i++) {
                    if (words != stringHolder[i]) {
                        //cout << words << " appeared " << wordCount << " amount of times " << endl;
                        if (words == input_word) {
                            tmp_2 = wordCount;
                        }
                        if (words == "macbeth") {
                            tmp = wordCount;
                        }
                        wordCount = 0;
                        words = stringHolder[i];
                        counter++;
                    }
                    wordCount++;
                }

                //cout << words << " appeared " << wordCount << " amount of times" << endl;
                cout << "Liczba unikalnych slow: " << counter << endl;
                cout << "Slowo Macbeth wystepuje w pliku: " << tmp << endl;
                if (tmp_2 != 0)
                    cout << "Liczba wystapien poszukiwanego slowa '" << input_word << "': " << tmp_2 << endl;
                else if (tmp_2 == 0 and words == input_word)
                    cout << "Liczba wystapien poszukiwanego slowa '" << input_word << "': " << wordCount << endl;
                else
                    cout << "Liczba wystapien poszukiwanego slowa '" << input_word << "': 0" << endl;

                t=false;
                break;
            }
            case 2:{
                ifstream input;
                input.open("macbeth.txt");
                int lines = 0;
                string words;
                vector<string> stringHolder;

                while (input >> words) {
                    remove_if(words.begin(), words.end(), isPunct);
                    words.erase(remove_if(words.begin(), words.end(), isPunct), words.end());
                    transform(words.begin(), words.end(), words.begin(), tolower);
                    stringHolder.push_back(words);
                }

                sort(stringHolder.begin(), stringHolder.end());

                int vSize = stringHolder.size();

                int wordCount = 1;
                words = stringHolder[0];
                int counter = 0;

                map<int, string>mapa;

                for (int i = 1; i < vSize; i++) {
                    if (words != stringHolder[i]) {
                        //cout << words << " appeared " << wordCount << " amount of times " << endl;

                        mapa[wordCount] = words;
                        wordCount = 0;
                        words = stringHolder[i];
                        counter++;
                    }
                    wordCount++;
                }

                cout << "20 najczesciej wystepujacych slow: " << endl;
                int i = 1;
                map <int, string>::reverse_iterator it;
                for (auto it = mapa.rbegin(); it != mapa.rend(); ++it) {
                    if (i <= 20)
                        cout <<i<<". "<< it->first << ", " << it->second << endl;
                    i++;
                }      
               
                t=false;
                break;
            }
            case 3: {
                regex pattern("Point:[[:space:]]*([[:digit:]]*)[[:space:]]*([[:digit:]]*)");

                smatch m;
                auto data = phys_data;

                while (data.size()!=0){
                    if (regex_search(data, m, pattern)) {
                        for (int i = 1; i < m.size(); ++i)
                            cout << " " << m[i];
                        cout << ", ";
                        data = m.suffix();
                    }
                }

                t=false;
                break;
            }
            case 4:{

                regex pattern("Point:[[:space:]]*([[:digit:]]*)[[:space:]]*([[:digit:]]*)");

                smatch m;
                auto data = phys_data;

                while (data.size() != 0) {
                    if (regex_search(data, m, pattern)) {
                        for (int i = 1; i < m.size(); ++i)
                            cout << " " << m[i];
                        cout << ", ";
                        data = m.suffix();
                    }
                }

                t=false;
                break;
            }        
            case 5:{
                fstream file;
                file.open("kartoteka.txt");
                
                if( file.good() == true )
                    cout << "Uzyskano dostep do pliku!" <<endl;
                else 
                    cout << "Dostep do pliku zostal zabroniony!" <<endl;
                    
                regex pattern("[[:space:]]*Adam[[:space:]]*Nowak[[:space:]]*680510[[:space:]]*");
                
                int lineo=0;
                bool tmp=true;
                string data;
                while(getline( file, data )){
                    ++lineo;
                    smatch wynik;
                    if( regex_search( data, wynik, pattern ) )
                    {   
                        tmp=false;
                        cout << "Wyszukano wers " << lineo << ": ";
                        //for (int i = 0; i < wynik.size(); ++i)
                             cout<< wynik[0];
                       
                    }
                }
                if (tmp){
                    cout<< "0";
                }

                cout << endl;
                
                file.close();
                t=false;
                break;
            }            
            case 6:{
                fstream file;
                file.open("dane1.txt");
                ofstream przepis("dane2.txt");
                
                if( file.good() == true )
                    cout << "Uzyskano dostep do pliku!" <<endl;
                else 
                    cout << "Dostep do pliku zostal zabroniony!" <<endl;

                //regex pattern(R"((?:^|\s)([+-]?[[:digit:]]+(?:\.[[:digit:]]+)?)(?=$|\s))");
                //regex pattern("^[0-9]");
                //regex pattern(R"((?:^|\s)([[:digit:]]?)(?=$|\s))");
                
                regex pattern(R"((?:^|\s)([1-9]|10)(?=$|\s))");   //dobry

                
                
                string data;
                smatch wynik;
                int i=1;
                
                while(getline( file, data )){
                    cout<<"Wers: "<<i<<" -> ";
                    while( regex_search( data, wynik, pattern ) ) {
                        
                        przepis<<wynik[0];
                        
                        cout<< wynik[0] <<", ";
                        data=wynik.suffix().str();
                    } 
                    cout<<endl;
                    i++;
                }

                if (przepis.good() == true)
                    cout << "Poprawnie przepisano dane!" << endl;
                else
                    cout << "Blad zapisu danych!" << endl;

                przepis.close();
                file.close();
                t=false;
                break;
            }           
            case 7:{
                string path_1="dane1.txt";
                string path_2 ="dane3.txt";
                LiczbyWTekscie x(path_1,path_2);

                t=false;
                break;
            }
            case 8:{
                t=false;
                break;
            }
            default: {
                cout<<"Wprowadz poprawny numer zadania!!!\n"<<endl;
                break;
            }
        }
    }
    return 0;
}
