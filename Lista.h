#ifndef LISTA_H
#define LISTA_H

class Lista {
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();

    int insertIntoListLast(char value);
    int insertarOrden(char value);
    int eliminar(char value);
    int actualizar(char viejo, char nuevo);
    int printList();

private:
    struct node{
        char data;
        struct node *nextPtr;
    };

    /*variables*/
    typedef struct node NODE;
    typedef NODE *NODEPTR;

    NODEPTR headNode;


};

#endif /* LISTA_H */

