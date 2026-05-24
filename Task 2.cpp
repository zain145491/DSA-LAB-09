#include <iostream>
#include <string>
using namespace std;

struct Song {
    int id;
    string name;
    float duration;
    Song* next, * prev;

    Song(int i, string n, float d) {
        id = i; name = n; duration = d;
        next = prev = NULL;
    }
};

class Playlist {
    Song* head;

public:
    Playlist() { head = NULL; }

    void addSong(int id, string name, float dur) {
        Song* newSong = new Song(id, name, dur);
        if (!head) {
            head = newSong;
            return;
        }
        Song* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newSong;
        newSong->prev = temp;
    }

    void reversePlaylist() {
        Song* curr = head, * temp = NULL;
        while (curr != NULL) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            head = curr;
            curr = curr->prev;
        }
    }

    void display() {
        Song* temp = head;
        while (temp) {
            cout << "ID: " << temp->id << " | Name: " << temp->name << " | Dur: " << temp->duration << "m" << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Playlist p;
    p.addSong(101, "Dil Dil Pakistan", 4.2);
    p.addSong(102, "Afreen Afreen", 5.1);

    cout << "Original Playlist:" << endl;
    p.display();

    p.reversePlaylist();
    cout << "\nReversed (Shuffled) Playlist:" << endl;
    p.display();

    return 0;
}