#include <iostream>
#include <string>
using namespace std;

class Player {
    private:
        char symbol;
        string name;

    public:
        Player(char s, const string &n) {
            symbol = s;
            name = n;
        }

        char getSymbol() const {
            return symbol;
        }

        string getName() const {
            return name;
        }
};

class Board {
    private:
        char board[9];

    public:
        Board() {
            for(char &c : board) c = ' ';
        }

        void print() {
            cout << board[0] << " | " << board[1] << " | " << board[2] << "\n--+---+--\n"
            << board[3] << " | " << board[4] << " | " << board[5] << "\n--+---+--\n"
            << board[6] << " | " << board[7] << " | " << board[8] << '\n';
        }

        bool makeMove(int r, int c, Player &player) {
            r--; c--;
            if(r >= 0 && r < 3 && c >= 0 && c < 3 && board[r*3 + c] == ' ') {
                board[r*3 + c] = player.getSymbol();
                return true;
            }
            return false;
        }

        bool isWinner(Player &player) {
            int winConditions[][3] = {
                {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
                {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
                {0, 4, 8}, {2, 4, 6}
            };

            for(auto &condition : winConditions) {
                bool win = true;
                for(int pos : condition) {
                    if(board[pos] != player.getSymbol()) {
                        win = false;
                        break;
                    }
                }
                if(win) return true;
            }
            return false;
        }

        bool isFull() {
            for(char c : board) {
                if(c == ' ') return false;
            }
            return true;
        }
};

void play() {
    string name;
    cout << "Siapa namamu (Player 1)? ";
    getline(cin, name);
    Player player1('X', name);
    cout << "Siapa namamu (Player 2)? ";
    getline(cin, name);
    Player player2('O', name);

    Board board;
    Player* turn = &player1;

    while(true) {
        int r, c;
        board.print();
        cout << "Sekarang adalah giliran " << turn->getName() << " (" << turn->getSymbol() << "). Masukkan langkahmu, baris(1-3) kolom(1-3): ";
        cin >> r >> c;

        while(!board.makeMove(r, c, *turn)) {
            cin.clear();
            cin.ignore(LONG_LONG_MAX, '\n');
            cout << "Inputmu salah. Masukkan langkah valid! ";
            cin >> r >> c;
        }

        if(board.isWinner(*turn)) {
            board.print();
            cout << "Selamat. " << turn->getName() << " (" << turn->getSymbol() << ") menang :)\n";
            break;
        } else if(board.isFull()) {
            board.print();
            cout << "Tidak ada yang menang, kalian seri :(\n";
            break;
        }

        turn = (turn == &player1) ? &player2 : &player1;
    }
}

int main() {
    cout << "Selamat datang di Tic-Tac-Toe\n";
    while(true) {
        play();
        char input;
        cout << "Apakah ingin main lagi (y/n)? ";
        cin >> input;
        cin.ignore(LONG_LONG_MAX, '\n');

        if(tolower(input) != 'y') {
            cout << "Sampai jumpa!";
            break;
        }
    }
}