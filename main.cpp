#include <cstdlib>

#include "Lista.h"

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {

    Lista myList;
    myList.insertIntoListLast('a');
    myList.insertIntoListLast('b');
    myList.insertIntoListLast('c');
    myList.insertIntoListLast('d');
    myList.insertIntoListLast('e');
    myList.insertIntoListLast('f');

    myList.actualizar('f','z');

    myList.insertarOrden('b');

    myList.printList();

    return 0;
}

