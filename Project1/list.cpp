#include "list.h" 


List::List()
    : m_head(nullptr), m_tail(nullptr), m_size(0) 
{
}


List::List(const Song &aSong)
    :m_head(nullptr), m_tail(nullptr), m_size(1)
{
   Node* newNode = new Node(aSong);
   m_head = newNode;
   m_tail = newNode;
}

List::~List()
{
    Node* curr = m_head;
    while(curr != nullptr)
    {
        m_head = curr->next;
        delete curr;
        curr = m_head;
    }
}


void List::add(const Song &aSong)
{
    Node* newNode = new Node(aSong);
    if(!m_head)
    {
        m_head = newNode;
        m_tail = newNode;
    }
    else
    {
        m_tail->next = newNode;
        m_tail = newNode;
    }
   m_size++; 
}


bool List::isEmpty() const 
{
    if(m_size == 0) { return true; }
    return false;
}


bool List::editSongLikes(const char* artist, const char* title, int likes)
{
    bool compareArtist;     
    bool compareTitle; 
 
    for (Node* curr = m_head; curr; curr = curr->next)
    {
        compareArtist = strcmp(curr->data->getArtist(), artist);
        compareTitle = strcmp(curr->data->getTitle(), title);
        if(!(compareArtist + compareTitle))
        {
            curr->data->setLikes(likes);
            return true;
        }
    }
    return false;
}


bool List::displayArtistInOrderPopularity(const char* artist)
{
    Song** SongPtr = new Song*[m_size];


    int size = 0; 

    for(Node* curr = m_head; curr; curr = curr->next)
    {
       bool foundArtist = strcmp(curr->data->getArtist(), artist);
       if(!foundArtist)
       {
           SongPtr[size] = curr->data;
           size++;
       }
    }
    if (size == 0) { return false; }
    
    sortGreatestToLeast(SongPtr,size);
    
    for(int i = 0; i < size; i++)
	 {
        std::cout << "\nArtist: " << SongPtr[i]->getArtist() << '\n';
		std::cout << "Title: " << SongPtr[i]->getTitle() << '\n';
		std::cout <<  "Lenght: " << SongPtr[i]->getLength() << '\n';
		std::cout << "Likes: " << SongPtr[i]->getLikes() << '\n';
	 }

    
    delete[] SongPtr;
    return true; 
}

void List::sortGreatestToLeast(Song** &Songptr, int size)
{
    Song* temp;

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if (Songptr[i]->getLikes() > Songptr[j]->getLikes())
            {
                temp = Songptr[j];
                Songptr[j] = Songptr[i];
                Songptr[i] = temp;
            }
        }
    }
    temp = nullptr;
}


 bool List::removeSongsBelowNumberOfLikes(int likes)
{

     int previousSizeOfList = m_size;
     Node* prev = m_head;
     Node* curr = m_head;
    
     while (curr)
     {
         if (curr->data->getLikes() <= likes)
         {
				 if (curr == m_head)
				 {
					 m_head = curr->next;
					 delete curr;
					 curr = m_head;
                     prev = m_head;
				 }
                 else if(curr == m_tail)
				 {
					 m_tail = prev;
					 delete curr;
					 m_tail->next = nullptr;
                     curr = nullptr;
				 }
				 else
				 {
					 prev->next = curr->next;
					 delete curr;
					 curr = prev->next;
				 }
				 m_size--;
         }

         else
         {
             curr = curr->next;
             if (prev->next != curr)
             {
                 prev = prev->next;
             }
         }
         
     }

     if (m_size == previousSizeOfList) { return false; }

     return true;
}


 void List::printList()
{
   int songNumber = 1;
    
   for(Node* curr = m_head; curr; curr = curr->next)  
   {
       std::cout << "\nSong " << songNumber << ":\n";
       std::cout << "Artist: "  << curr->data->getArtist() << "\n"
                 << "Title: "   <<curr->data->getTitle() << "\n"
                 << "Length: " << curr->data->getLength() << "\n"
                 << "Likes: "   << curr->data->getLikes() << "\n\n";
       songNumber++;
   }
}



