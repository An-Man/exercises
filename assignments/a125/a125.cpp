// Assignment 1_2_5 Book Management System

#include <iostream>
#include <string>
#include <map>

struct Book
{
    int id {};
    std::string title {};
    std::string author {};
    std::string ISBN {};
    int year {};
    int quant_total {};
    bool present {true};
};

std::map<int, Book> all_books;  // a map to store the books in

void display_book(int b_id) // print book info by id
{
    std::cout << std::boolalpha;  // print bool value in letters
    std::cout << "Book id: " << all_books[b_id].id << '\n';
    std::cout << "Book title: " << all_books[b_id].title << '\n';
    std::cout << "Book author: " << all_books[b_id].author << '\n';
    std::cout << "Book ISBN: " << all_books[b_id].ISBN << '\n';
    std::cout << "Book year: " << all_books[b_id].year << '\n';
    std::cout << "Quantity of copies: " << all_books[b_id].quant_total << '\n';
    std::cout << "Book present: " << all_books[b_id].present << '\n';
    std::cout << "------\n";
}

void add_book() // add a new book by id number
{
    std::cout << "Adding a new book.\n";
    std::cout << "Input unique book id: ";
    int input_id {};
    std::cin >> input_id;
    
    Book new_book {};
    new_book.id = input_id;
    all_books[input_id] = new_book;  // add book to map by id

    std::cout << "Enter book title: ";
    std::cin >> std::ws;       // to remove whitespace which produced error
    std::getline(std::cin, all_books[input_id].title);

    std::cout << "Enter book author: ";
    std::getline(std::cin, all_books[input_id].author);

    std::cout << "Enter book ISBN: ";
    std::getline(std::cin, all_books[input_id].ISBN);

    std::cout << "Enter book year: ";
    int input_y {};
    std::cin >> input_y;  
    all_books[input_id].year = input_y;

    std::cout << "Enter quantity of copies: ";
    int input_q {};
    std::cin >> input_q;  
    all_books[input_id].quant_total = input_q;
}

void remove_book()
{
    std::cout << "To remove book, input book id: ";
    int input {};
    std::cin >> input;

    // from cppreference.com on map/erase
    for (auto it = all_books.begin(); it != all_books.end();)
    {
        if (it->first == input)
            it = all_books.erase(it);
        else
            ++it;
    }
}

void print_if_present()
{
    std::cout << "To check if book is present, enter id: ";
    int input_pres {};
    std::cin >> input_pres;
    
    if (all_books[input_pres].present) {
        std::cout << "Book is present.\n";
    } else {
        std::cout << "Book is not present.\n";
    }
}

int main()
{
    Book init_book { 1, "How to cook in C++", "Jane Author", "199824-20498-22", 1996, 2, 1 }; // example book
    all_books[1] = init_book;   // set this to map with id "1"
    
    add_book();         // these are just to test functionality
    
    std::cout << "To print book info, input book id: ";
    int input {};
    std::cin >> input;

    display_book(input);    

    print_if_present();

    remove_book();

    display_book(1);
    display_book(2);
    
    return 0;

}