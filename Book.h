//Clase libros

//#include<iostream>
//#include<string>
#include<bits/stdc++.h>
//Map -> trabaja con pares -> llave, valor

using namespace std;

class Book{

    private:
        string title;
        string author;
        int year_publication;
        bool loan_state = false; //false-> it's in the library, true-> it's been lent
        //loan registration

    public:
        Book():title(""),author(""),year_publication(0){}
        Book(string title,string author,int year_publication):title(title),author(author),
                year_publication(year_publication){

        }
        string getTitle(){return title;}
        string getAuthor(){return author;}
        int getYear(){return year_publication;}
        bool getLoanState(){return loan_state;}

        bool setLoanState(bool x){loan_state = x;}
        
        void print_book(){
            cout<<"\""<<title<<"\" by "<<author<<endl;
        }

};
class Novel: public Book{ 
    private:
        string genre;
        fstream registration; //Loan registration
    public:
        Novel():genre(""){};
        Novel(string title,string author,int year_publication,string _genre):Book(title,author,year_publication){
            genre = _genre;

            registration.open(title,ios::out);
            if(!registration)
            {
                cout<<"Error in creating file!";
            }
            registration<<endl<<"Title: "<<title<<endl<<"Author: "<<author<<endl;
            registration<<"Year of puplication: "<<year_publication<<endl<<"Genre: "<<genre<<endl;
            registration<<endl<<endl<<"Loan Registration: "<<endl;

            registration.close();
        } 
        
};

class TextBook: public Book{ 
    private:
        string subject;
        string topic;
        fstream registration;
    public:
        TextBook():subject(""),topic(""){};
        TextBook(string title,string author,int year_publication,string _subject,string _topic):Book(title,author,year_publication){
            subject = _subject;
            topic = _topic;

            registration.open(title,ios::out);
            if(!registration)
            {
                cout<<"Error in creating file!";
            }
            registration<<endl<<"Title: "<<title<<endl<<"Author: "<<author<<endl;
            registration<<"Year of puplication: "<<year_publication<<endl<<"Subject: "<<subject<<endl<<"Topic: "<<topic<<endl;
            registration<<endl<<endl<<"Loan Registration: "<<endl<<endl;

            registration.close();
        } 
};

class Comic: public Book{ 
    private:
        int volume; 
        string artist;
        fstream registration;
    public:
        Comic():volume(0),artist(""){};
        Comic(string title,string author,int year_publication,int _volume,string _artist):Book(title,author,year_publication){
            volume = _volume;
            artist = _artist;

            registration.open(title,ios::out);
            if(!registration)
            {
                cout<<"Error in creating file!";
            }
            registration<<endl<<"Title: "<<title<<endl<<"Author: "<<author<<endl<<"Artist: "<<artist<<endl;
            registration<<"Year of puplication: "<<year_publication<<endl<<"Volume: "<<endl;
            registration<<endl<<endl<<"Loan Registration: "<<endl<<endl;

            registration.close();
        } 
};