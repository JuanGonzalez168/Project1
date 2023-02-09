#pragma once
#include "song.h"

class List
{
public:

    List();
    List(const Song& aSong);
    ~List();

    void add(const Song &aSong);
    bool isEmpty() const;
    bool editSongLikes(const char* artist, const char* title, int likes);
    bool displayArtistInOrderPopularity(const char* artist);
    bool removeSongsBelowNumberOfLikes(int likes);
    void printList();
    
private:
    struct Node
    {
        Song* data;
        Node* next;
        Node(const Song &aSong)
        {
            data = new Song(aSong);
            next = nullptr;
        }
        ~Node()
        {
            delete data;
            data = nullptr;
            next = nullptr;
        }
    };

Node* m_head;
Node* m_tail;
int m_size;

void sortGreatestToLeast(Song** &ptr, int size);
};
