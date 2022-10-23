#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<map>
#include"Book.h"

using namespace std;

//A cada libro agregarle un hilo cuando se  rente, 
//este será para el tiempo. Y por ejemplo q sean 5 seg por día, 
//y vaya disminuyendo. Para q cuando se quiera volver a rentar, ya no se pueda
//Entoncces el hilo será por tiempo
//no se, si el hilo existe no se puede rentar -> decir cuantos días faltan para q se rente
class Library{

    public:
    map<string,Book> library;
    Library(){
           
    }

    void get();
    void addBook();
    void deleteBook();
    void student();
    void librarian();
    void booklist(int);
    void see();
    void borrowBook();
    void deleteFiles(); //When the program closes

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
            deleteFiles();
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
        cout<<"\n\t\t1.View BookList\n\n\t\t2. Borrow a Book\n\n\t\t3.Go to main menu\n\n\t\t4.Close Program\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
            

         

        switch(i)
        {
            case 1:booklist(1);
                     break;
            case 2:borrowBook(); //Change to borrow
                     break;
            case 3:system("cls");
                     get();
                     break;
            case 4:deleteFiles();
            default:cout<<"\n\t\tPlease enter correct option :(";
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
void Library::see(){ //To see a book register
    
    cout<<"\n\t\t Search: Press any key to continue.....";
    getch();
    system("cls");
   
    librarian();
}
void Library::librarian()
{
    int i;
        cout<<"\n\t************ WELCOME LIBRARIAN ************\n";
        cout<<"\n\t\t>>Please Choose One Option:\n";
        cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Add Book\n\n\t\t4.Delete Book\n\n\t\t5.Go to main menu\n\n\t\t6.Close Program\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        switch(i)
        {
            case 1:booklist(2);
                     break;
            case 2:see(); //This search would be to see a book register
                     break;
            case 3:addBook();
                     break;
            case 4:deleteBook();
                    break;
            case 5:system("cls");
                     get();
                     break;
            case 6:deleteFiles();
            default:cout<<"\n\t\tPlease enter correct option :(";
            getch();
            system("cls");
            librarian();
        }
}

//Moverle para que dependa del tipo de libro
//Que la llave sea el título completo en minúsculas

//Agregar delete
void Library::addBook(){
    
        string title,author,genre,subject, topic,artist,s,key;
        int year,volume;

        int i;
        cout<<"\n\t\t>>Please Choose One Option:\n";
        cout<<"\n\t\t1.Add Novel\n\n\t\t2.Add Textbook\n\n\t\t3.Add Comic\n\n\t\t4.Return\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
       
       map<string,Book>::iterator it;

        switch(i)
        {   
            
            //Novel
            case 1:
                getline(cin,s);
                cout<<"Title: "; 
                getline(cin,title);
                
                key = title; //la llave será el título en mínusculas
                transform(key.begin(),key.end(),key.begin(),::tolower);

                it = library.find(key); 
                if ( it == library.end() ) {  
                // if it's not at the library
                    cout<<"Author: ";
                    getline(cin,author);
                    cout<<"Publication year: "; 
                    cin>>year;
                    getline(cin,s);
                    cout<<"Genre: ";
                    getline(cin,genre);
                    library[key] = Novel(title,author,year,genre);
                }   
                else {  
                    //found  
                    cout << "That novel it's already at the library";  
                }  
                break;
            //Textbook
            case 2:
                getline(cin,s);
                cout<<"Title: "; 
                getline(cin,title);
                
                key = title; //la llave será el título en mínusculas
                transform(key.begin(),key.end(),key.begin(),::tolower);

                it = library.find(key); 
                if ( it == library.end() ) {  
                // if it's not at the library
                    cout<<"Author: ";
                    getline(cin,author);
                    cout<<"Publication year: "; 
                    cin>>year;
                    getline(cin,s);
                    cout<<"Subject: ";
                    getline(cin,subject);
                    cout<<"Topic: ";
                    getline(cin,topic);

                    library[key] = TextBook(title,author,year,subject,topic);
                    
                }   
                else {  
                    //found  
                    cout << "That textbook it's already at the library";  
                }  
                break;
              
            //Comic
            case 3:
                getline(cin,s);
                cout<<"Title: "; 
                getline(cin,title);
                
                key = title; //la llave será el título en mínusculas
                transform(key.begin(),key.end(),key.begin(),::tolower);

                it = library.find(key); 
                if ( it == library.end() ) {  
                // if it's not at the library
                    cout<<"Author: ";
                    getline(cin,author);
                    cout<<"Artist: ";
                    getline(cin,artist);
                    cout<<"Publication year: "; 
                    cin>>year;
                    cout<<"Volume: ";
                    cin>>volume;
                    

                    library[key] = Comic(title,author,year,volume,artist); 
                }   
                else {  
                    //found  
                    cout << "That textbook it's already at the library";  
                }  
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

void Library::deleteBook(){
    
    string title,s;
    cout<<"Please enter the title of the book to delete"<<endl;
    getline(cin,s);
    cout<<"Title: ";
    getline(cin,title);
    transform(title.begin(),title.end(),title.begin(),::tolower);

    if(!library.erase(title))
    {
        cout<<"We don't have that book at the library"<<endl;
    }
    else{
        cout<<"It's been deleted"<<endl;
    }

    cout<<"\n\t\tPress any key to continue.....";
        getch();
        system("cls");
        librarian();

}
void Library::borrowBook(){
    
    string title,s;
    cout<<"Please enter the title of the book to borrow"<<endl;
    getline(cin,s);
    cout<<"Title: ";
    getline(cin,title);
    transform(title.begin(),title.end(),title.begin(),::tolower);

    auto it = library.find(title);  
     
    if ( it == library.end() ) {  
    // not found  
     cout<<"We don't own that book.";  
    }   
    else {  
        //If it's found -> see if it's availabe for loanment
        if(library[title].getLoanState())
        {
            cout<<"The book it's not available at the moment"<<endl;
            borrowBook();
        }  
        else{
            cout<<"The book is available for loan"<<endl;
        }
        
    }  

    cout<<"\n\t\tPress any key to continue.....";
        getch();
        system("cls");
        student();
}
void Library::deleteFiles()
{
    int in;
    string name;
    
    for(map<string,Book>::iterator it = library.begin();it!=library.end();it++){

        pair<string,Book> book = *it; 
        name = book.second.getTitle();
        in = remove(name.c_str());  //const char[]
    }
    exit(0);
}

int main()
{
    Library obj;
    obj.get();
    getch();
    return 0;
}
//o ver que se pueda poner la primer palabra --> puse todo el titulo 
//tambien moverle al cin para que agarre toda la linea, para el título y autor
//hacer las distinciones de los tipos de libro a la hora de añadirlos a la lista
//agregar lo del documento a los estudiantes, y el registro de prestamos a los libros
//revisar como rayos usar los hilos

//Agregar eliminar