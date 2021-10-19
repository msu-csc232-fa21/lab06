/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2018.
 *
 * @file lab10b.cpp
 * @author TODO: Part 2, Step 1 - Remove these instructions and place your name here; commit your changes with the commit message:
 * CSC232-LAB10 - Updated authors tag in lab10b.cpp
 */

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "Song.h"

using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::vector;

void demoCreation();
void demoShareSwap();
void demoSharedPtrsWithSTL();

int main(int argc, char** argv) {
    // TODO: Part 2, Step 2a - Uncomment the following call to demoCreation()
    //demoCreation();
    // TODO: Part 2, Step 3a - Uncomment the following call to demoShareSwap()
    //demoShareSwap();
    // TODO: Part 2, Step 4 - Uncomment the following call to demoSharedPtrsWithSTL()
    //demoSharedPtrsWithSTL();
    return EXIT_SUCCESS;
}

/**
 * Whenever possible, use the make_shared function to create a shared_ptr when
 * the memory resource is created for the first time. make_shared is exception-safe.
 * It uses the same call to allocate the memory for the control block and the
 * resource, and thereby reduces the construction overhead. If you do not use
 * make_shared, then you have to use an explicit new expression to create the
 * object before you pass it to the shared_ptr constructor. The following
 * example shows various ways to declare and initialize a shared_ptr together
 * with a new object.
 */
void demoCreation() {
    // Use make_shared function when possible.
    auto sp1 = make_shared<Song>("The Beatles", "Im Happy Just to Dance With You");
    cout << sp1->getArtist() << ", ";
    cout << sp1->getTitle() << endl;

    // Ok, but slightly less efficient.
    // Note: Using new expression as constructor argument
    // creates no named variable for other code to access.
    shared_ptr<Song> sp2(new Song("Lady Gaga", "Just Dance"));
    cout << sp2->getArtist() << ", ";
    cout << sp2->getTitle() << endl;

    // When initialization must be separate from declaration, e.g. class members,
    // initialize with nullptr to make your programming intent explicit.
    shared_ptr<Song> sp5(nullptr);
    //Equivalent to: shared_ptr<Song> sp5;
    //...
    sp5 = make_shared<Song>("Elton John", "I'm Still Standing");
    cout << sp5->getArtist() << ", ";
    cout << sp5->getTitle() << endl;
    // TODO: Part 2, Step 2b - Assign sp2 to sp5 on the next line, prior to the cout
    cout << sp5->getArtist() << ", ";
    cout << sp5->getTitle() << endl;
}

/**
 * The following example shows how to declare and initialize shared_ptr instances
 * that take on shared ownership of an object that has already been allocated by
 * another shared_ptr.
 */
void demoShareSwap() {
    //Initialize with copy constructor. Increments ref count.
    auto sp1 = make_shared<Song>("The Beatles", "Im Happy Just to Dance With You");
    shared_ptr<Song> sp2(new Song("Lady Gaga", "Just Dance"));
    auto sp3(sp2);
    cout << sp3->getArtist() << ", ";
    cout << sp3->getTitle() << endl;

    //Initialize via assignment. Increments ref count.
    auto sp4 = sp2;
    cout << sp4->getArtist() << ", ";
    cout << sp4->getTitle() << endl;

    //Initialize with nullptr. sp7 is empty.
    shared_ptr<Song> sp7(nullptr);
    // TODO: Part 2, Step 3b - Uncomment out the next two lines
    // cout << sp7->getArtist() << ", ";
    // cout << sp7->getTitle() << endl;
    // TODO: Part 2, Step 3c - Recomment out the above two lines.

    // Initialize with another shared_ptr. sp1 and sp2
    // swap pointers as well as ref counts.
    sp1.swap(sp2);
    cout << sp1->getArtist() << ", ";
    cout << sp1->getTitle() << endl;
}

/**
 * shared_ptr is also helpful in Standard Template Library (STL) containers when
 * you are using algorithms that copy elements. You can wrap elements in a shared_ptr,
 * and then copy it into other containers with the understanding that the underlying
 * memory is valid as long as you need it, and no longer. The following example
 * shows how to use the replace_copy_if algorithm on shared_ptr instances in a vector.
 */
void demoSharedPtrsWithSTL() {
    vector<shared_ptr<Song>> v;

    v.push_back(make_shared<Song>("Bob Dylan", "The Times They Are A Changing"));
    v.push_back(make_shared<Song>("Aretha Franklin", "Bridge Over Troubled Water"));
    v.push_back(make_shared<Song>("Thala", "Entre El Mar y Una Estrella"));

    vector<shared_ptr<Song>> v2;
    remove_copy_if(v.begin(), v.end(), back_inserter(v2), [] (shared_ptr<Song> s)
    {
        return s->getArtist().compare("Bob Dylan") == 0;
    });

    for (const auto& s : v2)
    {
        cout << s->getArtist() << ":" << s->getTitle() << endl;
    }
}
