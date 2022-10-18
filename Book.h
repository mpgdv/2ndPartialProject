//Clase libros

#include<iostream>
#include<string>

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
    public:
        Novel():genre(""){};
        Novel(string title,string author,int year_publication,string _genre):Book(title,author,year_publication){
            genre = _genre;
        } //un string para el nombre
        //void comer();
        //void SetBirthday(int,int,int);
};

class TextBook: public Book{ 
    private:
        string subject;
        string topic;
    public:
        TextBook():subject(""),topic(""){};
        TextBook(string title,string author,int year_publication,string _subject,string _topic):Book(title,author,year_publication){
            subject = _subject;
            topic = _topic;
        } 
};

class Comic: public Book{ 
    private:
        string subject;
        string topic;
    public:
        Comic():subject(""),topic(""){};
        Comic(string title,string author,int year_publication,string _subject,string _topic):Book(title,author,year_publication){
            subject = _subject;
            topic = _topic;
        } 
};