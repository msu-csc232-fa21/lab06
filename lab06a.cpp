/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2018.
 *
 * @file   lab10a.cpp
 * @author TODO: Part 1, Step 1 - Remove these instructions and place your name and commit your changes with the message:
 * CSC232-LAB10 - Updated author tag in lab10a.cpp
 */

#include <cstdlib>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "Song.h"

using std::cout;
using std::endl;
using std::make_unique;
using std::unique_ptr;
using std::map;
using std::string;
using std::vector;

void demoMoveUniquePtr();

unique_ptr<Song> SongFactory(const std::string &artist, const std::string &title);

void makeSongs();

void songVector();

class MyClass;

class ClassFactory;

void demoUniqueOwnership();

void demoUniqueArray(int);

int main(int argc, char **argv) {
    // TODO: Part 1, Step 2 - Uncomment the call to demoMoveUniquePtr()
    //demoMoveUniquePtr();
    // TODO: Part 1, Step 5 - Comment out the above call and uncomment the following call
    //makeSongs();
    // TODO: Part 1, Step 6a - Comment out the above call and uncomment the following call
    //songVector();
    //demoUniqueOwnership();
    //demoUniqueArray(5);

    return EXIT_SUCCESS;
}

void demoMoveUniquePtr() {
    auto ptrA = make_unique<Song>("Diana Krall", "The Look of Love");
    cout << ptrA->getArtist() << endl;

    // TODO: Part 1, Step 3a - Uncomment out the next line
    // auto ptrB = ptrA;
    // TODO: Part 1, Step 3b - Comment out the next line
    auto ptrB = move(ptrA);

    cout << ptrB->getArtist() << endl;

    // TODO: Part 1, Step 4 - Uncomment the next line.
    //cout << ptrA->getArtist() << endl;
}

/**
 * The following example shows how to create unique_ptr instances and pass them
 * between functions.
 */
void makeSongs() {
    // Create a new unique_ptr with a new object.
    auto song = make_unique<Song>("Mr. Children", "Namonaki Uta");

    // Use the unique_ptr.
    map<string, string> songs;
    songs[song->getArtist()] = song->getTitle();

    // Move pointer from one unique_ptr to another.
    unique_ptr<Song> song2 = std::move(song);

    // this should have no affect
    songs[song2->getArtist()] = song2->getTitle();

    // Obtain unique_ptr from function that returns by value.
    auto song3 = SongFactory("Michael Jackson", "Beat It");

    songs[song3->getArtist()] = song3->getTitle();

    for (auto it = songs.begin(); it != songs.end(); ++it) {
        cout << "[" << it->first << ", " << it->second << "]" << endl;
    }
}

unique_ptr<Song> SongFactory(const std::string &artist, const std::string &title) {
    // Implicit move operation into the variable that stores the result.
    return make_unique<Song>(artist, title);
}

/**
 * The following example shows how to create unique_ptr instances and use them in a vector.
 * In the range for loop, notice that the unique_ptr is passed by reference. If you try to
 * pass by value here, the compiler will throw an error because the unique_ptr copy
 * constructor is deleted.
 */
void songVector() {
    vector<unique_ptr<Song>> songs;

    // Create a few new unique_ptr<Song> instances
    // and add them to vector using implicit move semantics.
    songs.push_back(make_unique<Song>("B'z", "Juice"));
    songs.push_back(make_unique<Song>("Namie Amuro", "Funky Town"));
    songs.push_back(make_unique<Song>("Kome Kome Club", "Kimi ga Iru Dake de"));
    songs.push_back(make_unique<Song>("Ayumi Hamasaki", "Poker Face"));

    // Pass by const reference when possible to avoid copying.
    // TODO: Part 1, Step 6b: Remove the & after auto to pass the unique_ptr by value
    for (const auto &song : songs) {
        cout << "Artist: " << song->getArtist() << "   Title: "
             << song->getTitle() << endl;
    }
}

/**
 * The following example shows how to initialize a unique_ptr that is a class
 * member.
 */
class ClassFactory {
public:
    void doSomething() {
        cout << "I'm doing something..." << endl;
    }
};

class MyClass {
private:
    // MyClass owns the unique_ptr.
    unique_ptr<ClassFactory> factory;

public:
    // Initialize by using make_unique with ClassFactory default constructor.
    MyClass() :
            factory(make_unique<ClassFactory>()) {
    }

    void makeClass() {
        factory->doSomething();
    }
};

void demoUniqueOwnership() {
    MyClass myClass;
    myClass.makeClass();
}

/**
 * You can use make_unique to create a unique_ptr to an array, but you cannot
 * use make_unique to initialize the array elements
 */
void demoUniqueArray(int size) {
    // Create a unique_ptr to an array of 5 integers.
    auto p = make_unique<int[]>(size);

    // Initialize the array.
    for (int i = 0; i < size; ++i) {
        p[i] = i;
        cout << p[i] << endl;
    }
}
