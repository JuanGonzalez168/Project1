#pragma once
#include <cstring>
#include <iostream>

class Song
{
public:
    Song();
    Song(const char* artist, const char* title, float length, int likes);
    Song(const Song &aSong);
    ~Song();

    const char* getArtist() const;
    const char* getTitle() const;
    float getLength() const;
    int getLikes() const;

    void setArtist(const char* artist);
    void setTitle(const char* title);
    void setLength(float length);
    void setLikes(int likes);

    friend std::ostream& operator<<(std::ostream &out, const Song &aSong);
    friend bool operator==(const Song* ptr, const Song &otherSong);
    const Song& operator=(const Song &aSong);

private: 
    char* m_artist;
    char* m_title;
    float m_length;
    int m_likes;

    void allocateBuffer(char* &thisCharPtr, const char* buffer);
};

