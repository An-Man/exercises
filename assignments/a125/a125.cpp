// Assignment 1_2_5 Book Management System

#include <iostream>
#include <string>
#include <vector>


struct Book
{
    int id {};
    std::string title {};
    std::string author {};
    std::string ISBN {};
    int year {};
    int quant_total {};
    bool present {};
};

void display_book(Book& book)
{
    std::cout << book.id << '\n';
    std::cout << book.title << '\n';
    std::cout << book.author << '\n';
    std::cout << book.ISBN << '\n';
    std::cout << book.year << '\n';
    std::cout << book.quant_total << '\n';
    std::cout << book.present << '\n';
}

void add_book()
{
    
}

void remove_book(Book& book)
{

}

bool is_present(Book& book)
{
    return true;
}

int main()
{
    std::vector<Book> books(1000);

    Book book1 { 1, "kirja", "tekijä", "ISBNNN", 1996, 2, 1 };

    books.push_back(book1);

    //  for (auto x : )
    //    std::cout << x << '\n';

    // display_book(book1);

    return 0;

}