#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<map>
#include"Book.h"
#include<pthread.h>
#include <windows.h>
#include<unistd.h>



using namespace std;




//Function for the Thread
void *countDown(void *arg){
    
    pair<int,bool*>* a = (pair<int,bool*> *)arg;
    int n = a->first;
    
    
    for(int i = n; i> 0; i--)
    {
        sleep(10);//sleeps for 10 seconds
                 //every 10 seconds is one day
    }
    
    *a->second= false; //Change the book loan state to false -> it's been returned
     pthread_exit(NULL);
}



class Library{

    public:
    map<string,Book> library;

    Library(){ }

    void get();
    void addBook();
    void deleteBook();
    void student();
    void librarian();
    void booksAvailable();
    void booklist(int);
    void seeRegistration();
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
        {
            system("cls");
            librarian();
        }
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

//Menu for librarian
void Library::librarian()
{
    system("cls");
    int i;
        cout<<"\n\t************ WELCOME LIBRARIAN ************\n";
        cout<<"\n\t\t>>Please Choose One Option:\n";
        cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book's Registration\n\n\t\t3.Add Book\n\n\t\t4.Delete Book\n\n\t\t5.Go to main menu\n\n\t\t6.Close Program\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        switch(i)
        {
            case 1:booklist(2);
                     break;
            case 2:  system("cls");
                     seeRegistration(); //This search would be to see a book register
                     break;
            case 3: system("cls");
                    addBook();
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
//Menu for student
void Library::student()
{
    int i;
        cout<<"\n\t************ WELCOME STUDENT ************\n";
        cout<<"\n\t\t>>Please Choose One Option:\n";
        cout<<"\n\t\t1.View BookList\n\n\t\t2. Books available for loan\n\n\t\t3. Borrow a Book\n\n\t\t4.Go to main menu\n\n\t\t5.Close Program\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
            

        switch(i)
        {
            case 1:booklist(1); //See the books the library owns
                     break;
            case 2:booksAvailable(); //See only the books available for loan
                     break;
            case 3:borrowBook(); //Borrow book -> this will use threads
                     break;
            case 4:system("cls");
                     get();
                     break;
            case 5:deleteFiles(); //The Program closes
            default:cout<<"\n\t\tPlease enter correct option :(";
            getch();
            system("cls");
            student();
        }
}

//Books Available at the moment
void Library::booksAvailable(){
    
    int i = 0;

    for(map<string,Book>::iterator it = library.begin();it!=library.end();it++){

        pair<string,Book> book = *it;
       
       if(!book.second.getLoanState())
       {
            i++;
            book.second.print_book(); //Print the books available at the library
       }
        
    }

    if(i == 0)
    {
        cout<<"There are no books available at the library, come another time"<<endl;
    }

    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    student();
}
//All the books the library has
void Library::booklist(int i)
{
    

    if(library.empty())//If there are no books added yet
    {
        cout<<"There are no books yet"<<endl;
    }
    
    //Print books
    for(map<string,Book>::iterator it = library.begin();it!=library.end();it++){

        pair<string,Book> book = *it;
        book.second.print_book(); 
    }
    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    if(i==1) 
        student();
    else
        librarian();
}

//To see a book loan registration
void Library::seeRegistration(){ 
    
    string title,s;
    cout<<"Please enter the title of the book"<<endl;
    getline(cin,s);
    cout<<"Title: ";
    getline(cin,title);
    transform(title.begin(),title.end(),title.begin(),::tolower); //The key is in lower case

    auto it = library.find(title);  

    if ( it == library.end() ) {  
    // not found  
     cout<<"We don't own that book.";  
    }   
    else {  
        ifstream f;
        string text;

        f.open(library[title].getTitle(),ios::in);

        if(f.fail()) 
        {
            cout<<"The file could not open"<<endl;
        }

        while(!f.eof()) //Print file
        {
            getline(f,text);  
            cout<<text<<endl;
        }
        
        f.close(); 
    }  


    cout<<"\n\t\t Search: Press any key to continue.....";
    getch();
    system("cls");
    //go back to the librarian menu
    librarian();
}

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
                
                key = title; //Key in lower case
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
                
                key = title; 
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
        int x = remove(title.c_str()); //deleting file
    }

    cout<<"\n\t\tPress any key to continue.....";
        getch();
        system("cls");
        librarian();

}
void Library::borrowBook(){
    
    if(library.empty())
    {
        cout<<"There are no books available at the library, come another time"<<endl;
        
    }
    else{
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
            else 
            {  
                //If it's found -> see if it's availabe for loanment
                if(library[title].getLoanState())
                {
                    cout<<"The book it's not available at the moment"<<endl;
                }  
                else{
                    int days;
                    cout<<"The book is available for loan"<<endl;
                    cout<<"Enter the number of days you wish to borrow the book: "<<endl;
                    cin>>days;

                   

            //Threads
                    library[title].setLoanState(true); //it's been lent
                    
                    //Thread: once it finishes it will return the loanstate to false
                    
                    pthread_t loan;

                    pair<int,bool*> p = library[title].getPair(days);
                    

                    pthread_create(&loan,NULL,&countDown,&p);


                    //Register the loanment on the file
                    fstream f;
                    f.open(library[title].getTitle(), ios::app);
                    if (!f)
                        cout << "No such file found";
                    else {
                        
                        if(days > 1)
                        {
                            f <<endl<< " - Lent for "<<days<<" days";
                        }
                        else if(days == 1)
                        {
                            f <<endl<< " - Lent for 1 day";
                        }
                        f.close();
                    }

                }
        
            }  
    }
    //Ask for how many days
    

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




