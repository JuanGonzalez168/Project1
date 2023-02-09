#include "song.h"

Song::Song() 
    : m_artist(nullptr), m_title(nullptr), m_length(0), m_likes(0)
{
}

Song::Song(const char* artist, const char* title, float length, int likes) 
    :m_length(length), m_likes(likes)
{
    allocateBuffer(this->m_artist, artist);
    allocateBuffer(this->m_title, title);
}

void Song::allocateBuffer(char* &thisCharPtr ,const char* buffer)
{
    int buffSize = strlen(buffer) + 1;
    thisCharPtr = new char[buffSize];
    strcpy_s(thisCharPtr, buffSize ,buffer);
}


Song::Song(const Song &aSong)
    : m_artist(nullptr), m_title(nullptr), m_length(0), m_likes(0)
{
    *this = aSong;    
}

Song::~Song()
{
    if(this->m_artist && this->m_title)
    {
        delete[] this->m_artist;
        delete[] this->m_title;
        this->m_artist = nullptr;
        this->m_artist = nullptr;
    }
}

const char* Song::getArtist() const
{
    return this->m_artist;
}

const char* Song::getTitle() const
{
    return this->m_title;
}

float Song::getLength() const
{
    return this->m_length;
}

int Song::getLikes() const
{
    return this->m_likes;
}

std::ostream& operator<<(std::ostream& out, const Song &aSong)
{
    out << aSong.m_artist << "\n" << aSong.m_title << "\n"
        << aSong.m_length << "\n" << aSong.m_likes << "\n";
    return out;
}

const Song& Song::operator=(const Song& aSong) 
{
   if(this == &aSong)
   {
       return *this;
   }
   setArtist(aSong.m_artist);
   setTitle(aSong.m_title);
   setLength(aSong.m_length);
   setLikes(aSong.m_likes);

   return *this;
}

bool operator==(const Song* ptr, const Song &otherSong)
{
    bool compareArtist = strcmp(ptr->m_artist, otherSong.m_artist);
    bool compareTitle = strcmp(ptr->m_title, otherSong.m_title);
    if(!(compareArtist + compareTitle)) { return true; }
    return false;
}

void Song::setArtist(const char* artist)
{
    if(this->m_artist)
    {
        delete[] this->m_artist;
    }
    allocateBuffer(this->m_artist, artist);
}

void Song::setTitle(const char* title)
{
    if(this->m_title)
    {
        delete[] this->m_title;
    }
    allocateBuffer(this->m_title,title);
}

void Song::setLength(float length)
{
    this->m_length = length;
}

void Song::setLikes(int likes)
{
    this->m_likes = likes;
}

