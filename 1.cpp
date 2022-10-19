#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<map>
#include"Book.h"

using namespace std;


class Library{

    public:
    map<string,Book> library;
    Library(){
           
    }

    void get();
    void addBook();
    void student();
    void librarian();
    void booklist(int);
    void see(int);

};

void Library::get()
{
   int i;
        cout<<"\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n";
        cout<<"\n\t\t>>Please Choose Any Option To login \n";
        cout<<"\n\t\t1.Student\n\n\t\t2.Librarian\n\n\t\t3.Close\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        if(i==1)
        {
            system("cls");
            student();
        }
        else if(i==2)
            librarian();

        else if(i==3)
            exit(0);
        else
        {
            cout<<"\n\t\tPlease enter correct option :(";
            getch();
            system("CLS");
           get();
        }
}
void Library::student()
{
    int i;
        cout<<"\n\t************ WELCOME STUDENT ************\n";
        cout<<"\n\t\t>>Please Choose One Option:\n";
        cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Go to main menu\n\n\t\t4.Close Program\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
            if(i==1)
                booklist(1);
            else if(i==2)
                see(1);
            else if(i==3)
            {
                system("cls");
                get();
            }
            else if(i==4)
                exit(0);
            else
            {
                cout<<"\n\t\tPlease enter correct option :(";
                getch();
                system("cls");
                student();
            }
}
void Library::booklist(int i)
{
    //just to see the menus

    //Revisar si le voy a tener q mover a este
      for(map<string,Book>::iterator it = library.begin();it!=library.end();it++){

        pair<string,Book> book = *it;
       // cout<<book.first<<":"<<endl; //la llave
        book.second.print_book(); //Se usa el el metodo de la clase persona, ya que es un objeto
    }
                cout<<"\n\t\tPress any key to continue.....";
                getch();
                system("cls");
                if(i==1)
                    student();
                else
                    librarian();
}
void Library::see(int x){
    
    cout<<"\n\t\t Search: Press any key to continue.....";
    getch();
    system("cls");
    if(x==1)
    student();
    else
    librarian();
}
void Library::librarian()
{
    int i;
        cout<<"\n\t************ WELCOME LIBRARIAN ************\n";
        cout<<"\n\t\t>>Please Choose One Option:\n";
        cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Add Book\n\n\t\t4.Go to main menu\n\n\t\t5.Close Program\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        switch(i)
        {
            case 1:booklist(2);
                     break;
            case 2:see(2);
                     break;
            case 3:addBook();
                     break;
            case 4:system("cls");
                     get();
                     break;
            case 5:exit(0);
            default:cout<<"\n\t\tPlease enter correct option :(";
            getch();
            system("cls");
            librarian();
        }
}

//Moverle para que dependa del tipo de libro
//Que la llave sea el ISBN

void Library::addBook(){
    
        string title,_author,_genre,_subject, _topic,_artist;
        int year,volume;

        int i;
        cout<<"\n\t\t>>Please Choose One Option:\n";
        cout<<"\n\t\t1.Add Novel\n\n\t\t2.Add Textbook\n\n\t\t3.Add Comic\n\n\t\t4.Return\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;

        switch(i)
        {   
            
            //Novel
            case 1:
                cout<<"Title: "; cin>>title;
                cout<<"Author: ";cin>>_author;
                cout<<"Publication year: "; cin>>year;
                cout<<"Genre: "; cin>>_genre;
                library[title] = Novel(title,_author,year,_genre);
                     break;
            //Textbook
            case 2:
                cout<<"Title: "; cin>>title;
                cout<<"Author: ";cin>>_author;
                cout<<"Publication year: "; cin>>year;
                cout<<"Subject: ";cin>>_subject;
                cout<<"Topic: ";cin>>_topic;
                library[title] = TextBook(title,_author,year,_subject,_topic);
                     break;
            //Comic
            case 3:
                cout<<"Title: "; cin>>title;
                cout<<"Author: ";cin>>_author;
                cout<<"Publication year: "; cin>>year;
                cout<<"Volume: ";cin>>volume;
                cout<<"Artisti: ";cin>>_artist;
                library[title] = Comic(title,_author,year,volume,_artist);
                     break;
            case 4:
                librarian();
                break;
            default:
            cout<<"\n\t\tPlease enter correct option :(";
                getch();
                system("cls");
                addBook();
           
        }
        cout<<"\n\t\tPress any key to continue.....";
        getch();
        system("cls");
        librarian();

}

int main()
{
    Library obj;
    obj.get();
    getch();
    return 0;
}

//Revisar que para agregar los libros, se pueda agregar todo el titulo como llave, pero en minúsculas
//o ver que se pueda poner la primer palabra
//tambien moverle al cin para que agarre toda la linea, para el título y autor
//hacer las distinciones de los tipos de libro a la hora de añadirlos a la lista
//agregar lo del documento a los estudiantes, y el registro de prestamos a los libros
//revisar como rayos usar los hilos