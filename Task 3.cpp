#include <iostream>
using namespace std;

struct Player {
    int id;
    int score;
    Player* next;
    Player(int i) { id = i; score = 0; next = NULL; }
};

class Game {
    Player* head, * currentTurn;

public:
    Game() { head = NULL; currentTurn = NULL; }

    void addPlayer(int id) {
        Player* newP = new Player(id);
        if (!head) {
            head = newP;
            head->next = head;
            currentTurn = head;
        }
        else {
            Player* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newP;
            newP->next = head;
        }
    }

    void nextTurn() {
        if (currentTurn) {
            currentTurn = currentTurn->next;
            cout << "Current Turn: Player " << currentTurn->id << endl;
        }
    }

    void removePlayer(int id) {
        if (!head) return;
        Player* curr = head, * prev = NULL;

        while (curr->id != id) {
            prev = curr;
            curr = curr->next;
            if (curr == head) return;
        }

        // Agar ek hi player bacha ho
        if (curr->next == head && prev == NULL) {
            cout << "Game Over! Player " << curr->id << " wins!" << endl;
            delete curr;
            head = NULL;
            return;
        }

        if (curr == head) {
            Player* tail = head;
            while (tail->next != head) tail = tail->next;
            head = head->next;
            tail->next = head;
        }
        else {
            prev->next = curr->next;
        }

        if (currentTurn == curr) currentTurn = curr->next;
        delete curr;
    }
};

int main() {
    Game myGame;
    myGame.addPlayer(1);
    myGame.addPlayer(2);
    myGame.addPlayer(3);

    myGame.nextTurn();
    myGame.nextTurn();

    cout << "Player 2 is leaving the game..." << endl;
    myGame.removePlayer(2);

    myGame.nextTurn();
    return 0;
}