//
// Created by Abdelrahman on 5/28/2023.
//

#include <iostream>
#include <string>
#include "LibraryAPI.h"
#include "Book.h"
using namespace std;
int main(){
    string username , password , name ;
    LibraryAPI library ;
    cout << "---------------------------------------------------------------------------------------------" << endl
         << "----------------------------------Library Management System----------------------------------" << endl
         << "---------------------------------------------------------------------------------------------" << endl;
    auto dataChoice = 1 ;
    cout << "Do you want to use the saved data: " << endl
         << "1] Yes" << endl
         << "2] No " << endl ;
    cin >> dataChoice ;
    if (dataChoice == 1){
        library.readAdminsData();
        library.readBooksData();

        library.readCustomersData();

        cout << endl << "Reading data.." << endl ;
        cout << "Data has been read." << endl ;
    }
    else {
        cout << "No data has been read." << endl ;
    }
    if ( dataChoice == 2 ){
        while(true){


//        format in while running


            cout << "Enter your name: " << endl;
            cin >> name ;
            cout << "Enter your username: " << endl ;
            cin >> username;
            cout <<"Enter your Password: " << endl ;
            cin >> password ;
            try {
                library.createAdmin( name , username , password) ;
                break;
            }
            catch (std::invalid_argument& e) {
                std::cerr << "Error: " << e.what() << " is not valid." << endl ;
            }
        }
    }
    cout << "---------------------------------------------------------------------------------------------" << endl ;
    string usernameLogin , passwordLogin ;
    while (true){
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Login  Page <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl ;
        cout << "Username: " << endl ;
        cin >> usernameLogin;
        cout << "Password: " << endl ;
        cin >> passwordLogin;
        if(library.adminLogin(usernameLogin , passwordLogin)){
            cout << "---------------------------------------------------------------------------------------------" << endl
                 << "                                      Login Successfully                                     " << endl
                 << "---------------------------------------------------------------------------------------------" << endl ;
            break;
        }
        else{
            cout << "Invalid Username or Password." << endl ;
        }
    }

    int choice ;
    while (true){
        choice = 9 ;
        cout << "---------------------------------------------------------------------------------------------" << endl
             <<"1] Create Account" << endl
             << "2] Delete Account" << endl
             << "3] Search For Book" << endl
             << "4] Get Data" << endl
             << "5] Add Book to the Library" << endl
             << "6] Remove Book from the Library" << endl
             << "7] Borrow Book" << endl
             << "8] Return Book" << endl
             << "9] End" << endl
             << "Enter your Choice: " << endl ;
        cin >>  choice ;
        cout << "---------------------------------------------------------------------------------------------" << endl ;
        if(choice == 1 ){
            choice = 3 ;
            cout << "1] Create Admin " << endl
                 << "2] Create Customer " << endl
                 << "3] Back " << endl
                 << "Enter your choice: " << endl ;
            cin >> choice ;
            if (choice == 1){
                while(true){
                    string adminName , adminUsername , adminPassword ;
                    cout << "Enter the Admin Name: " << endl ;
                    cin >> adminName ;
                    cout << "Enter the Admin Username: " << endl ;
                    cin >> adminUsername ;
                    cout << "Enter the Admin Password: " << endl ;
                    cin >> adminPassword ;
                    try {
                        library.createAdmin(adminName, adminUsername, adminPassword);
                        cout << "Admin created." << endl;
                        break;
                    }
                    catch (std::invalid_argument& e) {
                        std::cerr << "Error: " << e.what() << " is not valid." << endl ;
                    }
                }
            }
            else if ( choice == 2){
                string customerName ;
                cout << "Enter Customer Name: " << endl ;
                cin >> customerName ;
                library.createCustomer(customerName) ;
                cout << "Customer created." << std::endl;
            }
            else {
                if ( choice > 3) {
                    cout << "Invalid Choice." << endl ;
                }
            }
        }
        else if ( choice == 2 ){
            choice = 3 ;
            cout << "1] Delete Admin " << endl
                 << "2] Delete Customer " << endl
                 << "3] Back " << endl
                 << "Enter your choice: " << endl ;
            cin >> choice ;
            if (choice == 1){
                int adminId ;
                while(true){
                    cout << "Enter the Admin Id You want to delete: "<< endl ;
                    cin >> adminId ;
                    try{
                        library.removeAdminById(adminId);
                        cout << "Admin removed." << std::endl;
                        break;
                    }
                    catch (std::runtime_error& e) {
                            std::cerr << "Error: " << e.what() << endl;
                    }
                }
            }
            else if ( choice == 2){
                int customerId ;
                while(true){
                    cout << "Enter the Customer Id You want to delete: "<< endl ;
                    cin >> customerId ;
                    try {
                        library.removeAdminById(customerId);
                        cout << "Customer removed." << std::endl;
                    }
                    catch (std::runtime_error& e) {
                        std::cerr << "Error: " << e.what() << endl;
                    }
                }
            }
            else {
                if ( choice > 3) {
                    cout << "Invalid Choice." << endl ;
                }
            }
        }
        else if ( choice == 3){
            choice = 4 ;
            cout << "1] Search by Title" <<  endl
                 << "2] Search by Category" <<  endl
                 << "3] Search by Author" <<  endl
                 << "4] Back" <<  endl;
            cin >> choice ;
            if (choice == 1 ){
                string bookTitle ;
                cout << "Enter the Book Title: " << endl ;
                cin >> bookTitle ;
                auto books = library.bookSearchByTitle(bookTitle) ;
                int size = books->getSize() ;
                for (int i = 0; i <size ; ++i) {
                    cout << "Search Result :" << endl
                         << "Book Id: " << (*books)[i]->getId() << endl
                         << "Book Category: " << (*books)[i]->getCategory() << endl
                         << "Book Author: " << (*books)[i]->getAuthor() << endl
                         << "Book Title: " << (*books)[i]->getTitle() << endl
                         << "Book State: ";
                    if ( (*books)[i]->isBorrowed()){
                        cout << "Borrowed" << endl ;
                    }
                    else {
                        cout << "Not Borrowed" << endl ;
                    }
                }
            }
            else if (choice == 2){
                string bookCategory ;
                cout << "Enter the Book Category: " << endl ;
                cin >> bookCategory ;
                auto books = library.bookSearchByCategory(bookCategory) ;
                int size = books->getSize() ;
                for (int i = 0; i <size ; ++i) {
                    cout << "Search Result :" << endl
                         << "Book Id: " << (*books)[i]->getId() << endl
                         << "Book Category: " << (*books)[i]->getCategory() << endl
                         << "Book Author: " << (*books)[i]->getAuthor() << endl
                         << "Book Title: " << (*books)[i]->getTitle() << endl
                         << "Book State: ";
                    if ( (*books)[i]->isBorrowed()){
                        cout << "Borrowed" << endl ;
                    }
                    else {
                        cout << "Not Borrowed" << endl ;
                    }
                    cout << "-------------------------------------------" << endl ;
                }
            }
            else if ( choice == 3){
                string bookAuthor;
                cout << "Enter the Book Author: " << endl ;
                cin >> bookAuthor ;
                auto books = library.bookSearchByAuthor(bookAuthor) ;
                int size = books->getSize() ;
                for (int i = 0; i <size ; ++i) {
                    cout << "Search Result :" << endl
                         << "Book Id: " << (*books)[i]->getId() << endl
                         << "Book Category: " << (*books)[i]->getCategory() << endl
                         << "Book Author: " << (*books)[i]->getAuthor() << endl
                         << "Book Title: " << (*books)[i]->getTitle() << endl
                         << "Book State: ";
                    if ( (*books)[i]->isBorrowed()){
                        cout << "Borrowed" << endl ;
                    }
                    else {
                        cout << "Not Borrowed" << endl ;
                    }
                }
            }
            else {
                if ( choice > 4) {
                    cout << "Invalid Choice." << endl ;
                }
            }
        }
        else if ( choice == 4 ){
                    choice = 6 ;
                    cout << "1] Display All Library Books " << endl
                         << "2] Display Borrowed Books" << endl
                            << "3] Display Non Borrowed Books" << endl
                            << "4] Display All Customers data" << endl
                            << "5] Display All Admins data" << endl;
                    cin >> choice ;
                    if( choice == 1 ) {
                        DynamicArray<Book *> *allBooks = library.getAllLibraryBooks();
                        std::cout << "All Library Books:" << std::endl;
                        for (int i = 0; i < allBooks->getSize(); i++) {
                            Book *book = (*allBooks)[i];
                            std::cout << "ID: " << book->getId() << ", Title: " << book->getTitle() << ", Author: "
                                      << book->getAuthor()
                                      << ", Category: " << book->getCategory();
                            if ( book->isBorrowed() ){
                                cout << ", State: Borrowed" << endl;
                            }
                            else{
                                cout << ", State: Not Borrowed" << endl;
                            }
                        }
                    }
                    else if( choice == 3 ){
                        DynamicArray<Book*>* nonBorrowedBooks = library.getNonBorrowedBooks();
                        std::cout << "Non-borrowed books:" << std::endl;
                        for (int i = 0; i < nonBorrowedBooks->getSize(); i++) {
                            Book* book = (*nonBorrowedBooks)[i];
                            std::cout << "ID: " << book->getId() << ", Title: " << book->getTitle()
                            << ", Author: " << book->getAuthor() << ", Category: " << book->getCategory() << std::endl;
                        }
                    }
                    else if ( choice == 2 ){
                        DynamicArray<Book*>* BorrowedBooks = library.getBorrowedBooks();
                        std::cout << "Borrowed books:" << std::endl;
                        for (int i = 0; i < BorrowedBooks->getSize(); i++) {
                            Book* book = (*BorrowedBooks)[i];
                            std::cout << "ID: " << book->getId() << ", Title: " << book->getTitle()
                                      << ", Author: " << book->getAuthor() << ", Category: " << book->getCategory() << std::endl;
                        }
                    }
                    else if(choice == 4) {
                        DynamicArray<Customer*>* customers = library.getCustomersData();
                        std::cout << "Customers data:" << std::endl;
                        for (int i = 0; i < customers->getSize(); i++) {
                            Customer* customer = (*customers)[i];
                            std::cout << "ID: " << customer->getId() << ", Name: " << customer->getName() << ", Borrowed books count : " << customer ->getBorrowedBooksCount() << std::endl;
                        }
                    }
                    else if(choice == 5) {
                        DynamicArray<Admin*>* admins = library.getAdminsData();
                        std::cout << "Admins data:" << std::endl;
                        for (int i = 0; i < admins->getSize(); i++) {
                            Admin* admin = (*admins)[i];
                            std::cout << "ID: " << admin->getId() << ", Name: " << admin->getName() << std::endl;
                        }
                    }
        }
        else if ( choice == 5 ){
            string bookTitle ;
            string bookAuthor ;
            string bookCategory ;
            cout << "Enter the Book Author Name: " << endl ;
            cin >> bookAuthor ;
            cout << "Enter the Book Category: " << endl ;
            cin >> bookCategory ;
            cout << "Enter the Book Title: " << endl ;
            cin >> bookTitle ;
            library.AddBook(bookTitle , bookAuthor , bookCategory) ;
        }
        else if ( choice == 6 ){
            int bookId ;
            cout << "Enter the Book ID: " << endl ;
            cin >> bookId ;
            library.removeBook(bookId);
        }
        else if ( choice == 7 ){
            int customerId , bookId ;
            cout << "Enter the Book ID: ";
            cin >> bookId ;
            cout << "Enter the Customer ID: ";
            cin >> customerId ;
            try{
                library.borrowBook(bookId , customerId);
            }
            catch (std::invalid_argument& e) {
                std::cerr << "Error: " << e.what() << " is not valid." << endl ;
            }
            catch (const char* message) {
                std::cerr << "Error: " << message << endl ;
            }
        }
        else if ( choice == 8 ){
            int customerId , bookId ;
            cout << "Enter the Book ID: ";
            cin >> bookId ;
            cout << "Enter the Customer ID: ";
            cin >> customerId ;
            library.returnBook(bookId , customerId);
        }
        else if ( choice == 9 ){
            library.saveData();
            cout << "Data has been Saved." << endl ;
            break;
        }
        else {
            cout << "inValid Choice." << endl ;
        }
    }
    return 0;
}