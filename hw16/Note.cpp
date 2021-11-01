#include<iostream>

class Note {
  char *sender;
  char *message;

public:
  Note() {  // this constructor is called a default constructor
    sender = new char[3];
    sender[0] = 'A';  
    sender[1] = 'B';  
    sender[2] = 0;
    
    message = new char[3];
    message[0] = 'h';  
    message[1] = 'i';  
    message[2] = 0;
  }

  Note(const Note &copiedNote) {  // this constructor is called a copy constructor
    sender = new char[3];
    message = new char[3];
    
    //std::cerr << "before for loop"<< std::endl;

    for (int i = 0; copiedNote.sender[i] != 0; i++) {
      sender[i] = copiedNote.sender[i];

      //std::cerr << "sender[" << i << "] = " << copiedNote.sender[i] << std::endl;

      if (sender[i + 1] == 0) {
        sender[i + 1] = 0;

        //std::cerr << "sender[" << i + 1 << "] = " << 0 << std::endl;
      }
    }
    
    for (int i = 0; copiedNote.message[i] != 0; i++) {
      message[i] = copiedNote.message[i];

      //std::cerr << "message[" << i << "] = " << copiedNote.message[i] << std::endl;

      if (message[i + 1] == 0) {
        message[i + 1] = 0;
        //std::cerr << "message[" << i + 1 << "] = " << 0 << std::endl;;
      }
    }

    std::cerr << "note copied!" << std::endl;

  }

  ~Note() { 
    delete [] sender; delete [] message; 
  }

  void display(std::ostream &os) {
    os << "sender: " << sender << " ";
    os << "message: " << message << "\n";
  }
};

int main() {
  Note n1, n2(n1);
  n1.display(std::cerr);  // output  sender: AB message: hi
  n2.display(std::cerr);
}
