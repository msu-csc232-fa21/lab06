/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2018.
 *
 * @file   Song.h
 * @author Jim Daehn
 * @brief  Song class specification.
 */

#ifndef LAB10_SONG_H
#define LAB10_SONG_H

#include <string>

class Song {
private:
    std::string _artist;
    std::string _title;
public:
    Song(const std::string& artist, const std::string& title);
    std::string getArtist() const;
    std::string getTitle() const;
    virtual ~Song();
};


#endif //LAB10_SONG_H
