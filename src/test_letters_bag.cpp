#include "letters_bag.h"
#include <fstream>
#include <iostream>

int main (int argc, char *argv[]) {

    srand(time(NULL));
    BolsaLetras b;
    ifstream in(argv[1]);

    if (in) {
        cout << "Leyendo desde " << argv[1] << "..." << endl;
        in >> b;
        in.close();
    }

    cout << b.toString() << endl;
    cout << b.get() << endl;
    cout << endl << b.toString() << endl;

    ofstream out(argv[2]);
    if (out) {
        out << b;
        out.close();
    }


    return 0;
}
