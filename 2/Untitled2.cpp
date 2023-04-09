#include<iostream>
#include<string>

using namespace std;

class Publication {
private:
    string title ;
    float price ;

public:
    Publication() : title (""), price (0.0) {}
    Publication(string t, float p ) : title (t), price (p){}

void getData () {
 cout << "Enter title: ";
 getline (cin,title);
 cout <<"Enter price:" ;
 cin >> price;
 cin.ignore(); // consume newline
}
void putData() const {
cout << "Title:" <<title <<endl;
cout << "Price:" <<price <<endl;
}

  };

class Book : public Publication {
 private:
     int pageCount;
 public:
    Book () : Publication (), pageCount (0) {}
    Book (string t, float p, int pc ) : Publication (t,p),
    pageCount (pc) {}


void getData () {

    Publication :: getData () ;
    cout << "Enter page count: ";
    cin >> pageCount;
    cin.ignore (); //consume newline
    }

void putData() const {
 Publication :: putData () ;
 cout<< "Page count:" << pageCount << endl ;

}

};

class Tape: public Publication {

private:
    float playingTime ;
public:
    Tape () : Publication (), playingTime (0.0) {}
    Tape (string t, float p, float pt ) : Publication (t,p),
    playingTime (pt) {}

void getData () {
 Publication :: getData () ;
 cout << "Enter playing time (minutes):";
 cin >> playingTime ;
 cin.ignore(); //consume newline
}

void putData () const {
 Publication :: putData ();
 cout << "Playing time (minutes):" << playingTime <<endl ;
}
};

int main () {
 Book b;
 Tape t;
 b.getData();
 t.getData ();
 cout << endl << "Book info:" <<endl;

 b.putData();
 cout << endl <<"Tape info:" <<endl ;
 t.putData () ;
 return 0;

}
