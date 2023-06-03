/*
Name: Azmar Kashif
Section: B
Roll no: 22i-2716
*/
#include<iostream>
using namespace std;
class Library{
    char* bookTitle;
    char* author;
    int bookID;
    int quantity;
    float price;
    static int TotalBooks;
    public:
    Library(){
    bookTitle = new char[1];
    bookTitle[0] = '\0';
    author = new char[1];
    author[0] = '\0';
    bookID = 0;
    quantity = 0;
    price = 0.0;
    TotalBooks = 0;
    }
    /*
    getters and setters
    */
    char* getBookTitle(){
        return bookTitle;
    }
    char* getAuthor(){
        return author;
    }   
    int getBookID(){
        return bookID;
    }
    int getQuantity(){
        return quantity;
    }
    float getPrice(){
        return price;
    }
    void setBookTitle(char* title){
        bookTitle = title;
    }
    void setAuthor(char* authorName){
        author = authorName;
    }
    void setBookID(int bookID){
        this->bookID = bookID;
    }
    void setQuantity(int quantity){
        if(quantity < 0){ //adding check if quantity gets negative we return
            cout << "Quantity cannot be negative" << endl;
            return;
        }
        this->quantity = quantity;
    }
    void setPrice(float price){
        if(price < 0){ //adding check if price is negative we return
            cout << "Price cannot be negative" << endl;
            return;
        }
        this->price = price;
    }
    static void setTotalBooks(int totalBooks){
        TotalBooks = totalBooks;
    }
    void calcTotalPrice(){
       cout << "Total price: " << quantity * price << endl;
    }
    static int getTotalBooks(){
        return TotalBooks;
    }
};  
int Library:: TotalBooks = 0; //initializing the static var of class to 0 globally
Library getBook_at(Library books[100], int index){ //finding book at specific index
    return books[index];
}
void addBook(Library books[100], Library newBook){
    int numBooks = Library::getTotalBooks();
    books[numBooks] = newBook;
    Library::setTotalBooks(numBooks + 1);
}
void removeBook(Library books[100], int bookID){
    for(int i=0;i<100;i++){ 
        if(books[i].getBookID() == bookID){ //if book we want to rem gets equal to the bookID
        /*
        we remove it along with its attributes
        */
            books[i].setAuthor("");
            books[i].setBookID(0);
            books[i].setBookTitle("");
            books[i].setPrice(0);
            books[i].setQuantity(0);
            Library::setTotalBooks(Library::getTotalBooks() - 1); //and then we minus that book from the actual number of books
        }
    }
}
void SortByTitle(Library books[100]){ 
    for(int i=0;i<100-1;i++){
        for(int j=i;j<100;j++){
            if(books[i].getBookTitle() > books[j].getBookTitle()){ //sorting simply by swaping
                Library temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}
void sortByAuthor(Library books[100]){
    for(int i=0;i<100-1;i++){
        for(int j=i;i<100;j++){
            if(books[i].getAuthor() > books[j].getAuthor()){ //sorting simply by swaping
                Library temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}
void SortByPrice(Library books[100]){
     for(int i=0;i<99;i++){
        for(int j=i;i<100;j++){
            if(books[i].getPrice() > books[j].getPrice()){ //sorting simply by swaping
                Library temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}
bool searchByTitle(Library books[10], char* titlename){
    for(int i=0;i<100;i++){
        if(books[i].getBookTitle() == titlename){ //if the book we want to serach gets equal to the title entered
            return true; //we return true
        }else{
            return false;
        }
    }
}
Library mostExpensiveBook(Library books[10]){ //searching for the most expensive book
    Library mostExpensive = books[0]; //setting the first book in the lib to be most expensive
    for(int i=0;i<100;i++){
        if(books[i].getPrice() > mostExpensive.getPrice()){  //then we check if current book is expensive than the mostExpensive book
            mostExpensive = books[i]; //we assign it to most expensive
        }
    }
    return mostExpensive; //and then we return it
}
int main() {
    Library books[100]; //creating an array of Library objects
    books[0].setBookTitle("The Alchemist"); //setting values for the first book
    books[0].setAuthor("Paulo Coelho");
    books[0].setBookID(12345);
    books[0].setQuantity(10);
    books[0].setPrice(15.99);
    Library::setTotalBooks(1); //incrementing the total books count

    //printing details of the first book
    cout << "Book Title: " << books[0].getBookTitle() << endl;
    cout << "Author: " << books[0].getAuthor() << endl;
    cout << "Book ID: " << books[0].getBookID() << endl;
    cout << "Quantity: " << books[0].getQuantity() << endl;
    cout << "Price: " << books[0].getPrice() << endl;
    cout << "Total Books: " << Library::getTotalBooks() << endl;

    //adding a new book
    Library newBook;
    newBook.setBookTitle("To Kill a Mockingbird");
    newBook.setAuthor("Harper Lee");
    newBook.setBookID(67890);
    newBook.setQuantity(5);
    newBook.setPrice(12.99);
    addBook(books, newBook);
    cout << "Total Books: " << Library::getTotalBooks() << endl;

    //removing a book
    removeBook(books, 12345);
    cout << "Total Books: " << Library::getTotalBooks() << endl;

    //sorting by title
    SortByTitle(books);

    //sorting by author
    sortByAuthor(books);

    //sorting by price
    SortByPrice(books);

    //searching by title
    char* title = "The Alchemist";
    bool found = searchByTitle(books, title);
    if (found) {
        cout << "Book found" << endl;
    } else {
        cout << "Book not found" << endl;
    }

    //finding the most expensive book
    Library mostExpensive = mostExpensiveBook(books);
    cout << "Most Expensive Book: " << mostExpensive.getBookTitle() << endl;

    return 0;
}
