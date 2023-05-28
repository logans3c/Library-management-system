//
// Created by moham on 5/28/2023.
//
//
// Created by moham on 5/27/2023.
//


/*int main() {
    // Create an instance of the Library class
    Library libraryApi;
    Customer customer;
    libraryApi.createCustomer("Jane Smith");

    // Perform some test operations
    libraryApi.addBook(new Book("The Great Gatsby", "Mohammed Ashraf", "sex"));
    libraryApi.addBook(new Book("789012", "To Kill a Mockingbird", "Harper Lee"));
    libraryApi.addBook(new Book("345678", "1984", "George Orwell"));
    try {
        // Code that may throw an exception
        libraryApi.lendBook(1, 100002);
    } catch (const char* errorMessage) {
        // Exception handling
        std::cerr << "Error: " << errorMessage << std::endl;
    }

    // Get all the customers and display their information
    DynamicArray<Customer *> *customers = libraryApi.getAllCustomers();
    for (int i = 0; i < customers->getSize(); i++) {
        Customer *customer = (*customers)[i];
        std::cout << "Customer ID: " << customer->getId() << std::endl;
        std::cout << "Customer Name: " << customer->getName() << std::endl;
        std::cout << "BorrowedBooksIDs: " << customer->getBorrowedBooksI() << std::endl;
        std::cout << std::endl;
    }

    // Get all the books and display their information
    DynamicArray<Book *> *books = libraryApi.getAllLibraryBooks();
    for (int i = 0; i < books->getSize(); i++) {
        Book *book = (*books)[i];
        std::cout << "Book ID: " << book->getId() << std::endl;
        std::cout << "Book Title: " << book->getTitle() << std::endl;
        std::cout << "Book Author: " << book->getAuthor() << std::endl;
        std::cout << "Book Category: " << book->getCategory() << std::endl;

        std::cout << std::endl;
    }

    // Cleanup and deallocate memory
    for (int i = 0; i < customers->getSize(); i++) {
        delete (*customers)[i];
    }

    for (int i = 0; i < books->getSize(); i++) {
        delete (*books)[i];
    }
    delete books;

    return 0;
}
*/

#include <iostream>
#include "Library.h"
#include "Customer.h"
#include "../include/LibraryAPI.h"
#include <string>
/*int main() {
    // Step 1: Create an instance of the LibraryAPI class
    LibraryAPI libraryApi;

    // Step 2: Admin login
    std::string username = "admin";
    std::string password = "password";
    bool isAdminLoggedIn = libraryApi.adminLogin(username, password);
    if (isAdminLoggedIn) {
        std::cout << "Admin login successful!" << std::endl;
    } else {
        std::cout << "Admin login failed!" << std::endl;
    }

    // Step 3: Get admins data
    DynamicArray<Admin*>* admins = libraryApi.getAdminsData();
    std::cout << "Admins data:" << std::endl;
    for (int i = 0; i < admins->getSize(); i++) {
        Admin* admin = (*admins)[i];
        std::cout << "ID: " << admin->getId() << ", Name: " << admin->getName() << std::endl;
    }

    // Step 4: Get customers data
    DynamicArray<Customer*>* customers = libraryApi.getCustomersData();
    std::cout << "Customers data:" << std::endl;
    for (int i = 0; i < customers->getSize(); i++) {
        Customer* customer = (*customers)[i];
        std::cout << "ID: " << customer->getId() << ", Name: " << customer->getName() << std::endl;
    }

    // Step 5: Read books data
    libraryApi.readBooksData();

    // Step 6: Read admins data
    libraryApi.readAdminsData();

    // Step 7: Read customers data
    libraryApi.readCustomersData();

    // Step 8: Get all libraryApi books
    DynamicArray<Book*>* allBooks = libraryApi.getAllLibraryBooks();
    std::cout << "All libraryApi books:" << std::endl;
    for (int i = 0; i < allBooks->getSize(); i++) {
        Book* book = (*allBooks)[i];
        std::cout << "ID: " << book->getId() << ", Title: " << book->getTitle() << std::endl;
    }

    return 0;
}
*/
int main() {
    LibraryAPI library;

    //====================================BOOKS===============================================
    std::string bookTitle1 = "To Kill a Mockingbird";
    std::string bookAuthor1 = "Harper Lee";
    std::string bookCategory1 = "Fiction";
    library.AddBook(bookTitle1, bookAuthor1, bookCategory1);

    std::string bookTitle2 = "1984";
    std::string bookAuthor2 = "George Orwell";
    std::string bookCategory2 = "Dystopian";
    library.AddBook(bookTitle2, bookAuthor2, bookCategory2);

    std::string bookTitle3 = "Pride and Prejudice";
    std::string bookAuthor3 = "Jane Austen";
    std::string bookCategory3 = "Romance";
    library.AddBook(bookTitle3, bookAuthor3, bookCategory3);

    std::string bookTitle4 = "The Great Gatsby";
    std::string bookAuthor4 = "F. Scott Fitzgerald";
    std::string bookCategory4 = "Classic";
    library.AddBook(bookTitle4, bookAuthor4, bookCategory4);

    std::string bookTitle5 = "The Catcher in the Rye";
    std::string bookAuthor5 = "J.D. Salinger";
    std::string bookCategory5 = "Coming-of-Age";
    library.AddBook(bookTitle5, bookAuthor5, bookCategory5);

    std::string bookTitle6 = "The Hobbit";
    std::string bookAuthor6 = "J.R.R. Tolkien";
    std::string bookCategory6 = "Fantasy";
    library.AddBook(bookTitle6, bookAuthor6, bookCategory6);

    std::cout << " Books added to the library." << std::endl;

    DynamicArray<Book*>* allBooks = library.getAllLibraryBooks();
    std::cout << "All Library Books:" << std::endl;
    for (int i = 0; i < allBooks->getSize(); i++) {
        Book* book = (*allBooks)[i];
        std::cout << "ID: " << book->getId() << ", Title: " << book->getTitle() << ", Author: " << book->getAuthor()
                  << ", Category: " << book->getCategory() << std::endl;
    }

    //====================================ADMIN===========================================
    // ADD ADMIN_1
    std::string adminName0 = "Admin User";
    std::string adminUsername0 = "ahmed";
    std::string adminPassword0 = "12345678";
    library.createAdmin(adminName0, adminUsername0, adminPassword0);
    std::cout << "Admin created." << std::endl;
    //ADD ADMIN_2
//    std::string adminName1 = "Admin User";
//    std::string adminUsername1 = " admin 1";
//    std::string adminPassword1 = "adminpass1";
//    library.createAdmin(adminName1, adminUsername1, adminPassword1);
//    std::cout << "Admin created." << std::endl;


    //LOGIN WITH ADMIN
    std::string username = "Ashraf";
    std::string password = "12345678";
    bool isAdminLoggedIn = library.adminLogin(username, password);
    if (isAdminLoggedIn) {
        std::cout << "Admin login successful!" << std::endl;
    } else {
        std::cout << "Admin login failed!" << std::endl;
    }
    //get admins data
//    DynamicArray<Admin*>* admins = library.getAdminsData();
//    std::cout << "Admins data:" << std::endl;
//    for (int i = 0; i < admins->getSize(); i++) {
//        Admin* admin = (*admins)[i];
//        std::cout << "ID: " << admin->getId() << ", Name: " << admin->getName() << std::endl;
//    }
    library.saveData();
    library.readAdminsData();
    DynamicArray<Admin*>* adminsData = library.getAdminsData();

//     Iterate over the admins data and print the admin information
    for (int i = 0; i < adminsData->getSize(); ++i) {
        Admin* admin = (*adminsData)[i];
        std::cout << "Admin ID: " << admin->getId() << std::endl;
        std::cout << "Name: " << admin->getName() << std::endl;
        std::cout << "Username: " << admin->getUsername() << std::endl;
        std::cout << "Password: " << admin->getPassword() << std::endl;
        std::cout << std::endl;
    }


    //==================================================================================
    //==============================CUSTOMER============================================
    // ADD CUSTOMER
    std::string customerName0 = "John Doe";
    library.createCustomer(customerName0);
    std::cout << "Customer created." << std::endl;
    int customerId0 = 100003;
    int bookId0 = 1;
    int customerId1 = 100004;
    int bookId1 = 2;

    std::string customerName1 = "Mohammed Ashraf";
    library.createCustomer(customerName1);
    std::cout << "Customer created." << std::endl;
    library.borrowBook(bookId0, customerId0);
    library.borrowBook(bookId1, customerId1);

    //GET CUSTOMER DATA
    DynamicArray<Customer*>* customers = library.getCustomersData();
    std::cout << "Customers data:" << std::endl;
    for (int i = 0; i < customers->getSize(); i++) {
        Customer* customer = (*customers)[i];
        std::cout << "ID: " << customer->getId() << ", Name: " << customer->getName() << ", Borrowed books count : " << customer ->getBorrowedBooksCount() << std::endl;
    }






    return 0;
}