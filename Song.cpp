/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2018.
 *
 * @file   Song.cpp
 * @author Jim Daehn
 * @brief  Song class implementation.
 */


#include "Song.h"

Song::Song(const std::string& artist, const std::string& title) :
        _artist(artist), _title(title) {
}

std::string Song::getArtist() const {
    return _artist;
}

std::string Song::getTitle() const {
    return _title;
}

Song::~Song() {
}
