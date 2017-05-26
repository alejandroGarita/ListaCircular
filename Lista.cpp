#include "Lista.h"
#include <iostream>
#include <malloc.h>

Lista::Lista() {
    headNode=NULL;
}

Lista::Lista(const Lista& orig) {
}

Lista::~Lista() {
}

int Lista::insertIntoListLast(char value){
    NODEPTR tempPtr,inicioPtr, newPtr;

    newPtr=(NODEPTR)malloc(sizeof(NODE));
    newPtr->data=value;
    newPtr->nextPtr=NULL;

    inicioPtr=headNode;

    if(inicioPtr==NULL){
        headNode=newPtr;
        newPtr->nextPtr=headNode;
        return 0;
    }

    tempPtr=inicioPtr->nextPtr;

    if(tempPtr->data==inicioPtr->data){
        inicioPtr->nextPtr=newPtr;
        newPtr->nextPtr=headNode;
        return 0;
    }else {
        while(tempPtr->nextPtr->data!=inicioPtr->data){
            tempPtr=tempPtr->nextPtr;
        }
        tempPtr->nextPtr=newPtr;
        newPtr->nextPtr=headNode;
        return 0;
    }
    return 0;
}

int Lista::eliminar(char value){
    NODEPTR tempPtr, previousPtr;

    tempPtr=headNode;

    if(tempPtr==NULL)
        return -1;

    while(tempPtr->nextPtr->data!=headNode->data){
        tempPtr=tempPtr->nextPtr;
    }

    if(tempPtr->data==headNode->data){
        if(tempPtr->data==value){
            headNode=NULL;
            return 0;
        }
    }

    if(tempPtr->nextPtr->data==value){
        tempPtr->nextPtr=tempPtr->nextPtr->nextPtr;
        headNode=headNode->nextPtr;
        return 0;
    }

    previousPtr=tempPtr;
    tempPtr=tempPtr->nextPtr->nextPtr;

    while(tempPtr->data!=headNode->data){
        if(tempPtr->data==value){
            previousPtr->nextPtr->nextPtr=tempPtr->nextPtr;
            return 0;
        }else{
            tempPtr=tempPtr->nextPtr;
            previousPtr=previousPtr->nextPtr;
        }
    }



    return -1;

}

int Lista::insertarOrden(char value){
    NODEPTR tempPtr,previousPtr, newPtr;

    newPtr=(NODEPTR)malloc(sizeof(NODE));
    newPtr->data=value;
    newPtr->nextPtr=NULL;

    tempPtr=headNode;
    previousPtr=headNode;

    if(tempPtr==NULL){
        headNode=newPtr;
        newPtr->nextPtr=headNode;
        return 0;
    }

    if(tempPtr->nextPtr->data==headNode->data){
        if(newPtr->data<tempPtr->data){
            headNode=newPtr;
            newPtr->nextPtr=tempPtr;
            tempPtr->nextPtr=headNode;
            return 0;
        }else{
            tempPtr->nextPtr=newPtr;
            newPtr->nextPtr=headNode;
            return 0;
        }
    }

    while(previousPtr->nextPtr->data!=headNode->data){
        previousPtr=previousPtr->nextPtr;
    }
    if(newPtr->data<tempPtr->data){
        headNode=newPtr;
        newPtr->nextPtr=tempPtr;
        previousPtr->nextPtr=headNode;
        return 0;
    }else{
        previousPtr=previousPtr->nextPtr;
        tempPtr=tempPtr->nextPtr;
    }

    while(tempPtr->data!=headNode->data){
        if(newPtr->data<tempPtr->data){
            previousPtr->nextPtr=newPtr;
            newPtr->nextPtr=tempPtr;
            return 0;
        }else{
            previousPtr=previousPtr->nextPtr;
            tempPtr=tempPtr->nextPtr;
        }
    }

    previousPtr->nextPtr=newPtr;
    newPtr->nextPtr=headNode;
    return 0;

}

int Lista::actualizar(char viejo, char nuevo){
    NODEPTR tempPtr;
    tempPtr=headNode;
    if(tempPtr==NULL){
        return -1;
    }

    if(tempPtr->data==viejo){
        tempPtr->data=nuevo;
        return 0;
    }else{
        tempPtr=tempPtr->nextPtr;
    }

    while(tempPtr->data!=headNode->data){
        if(tempPtr->data==viejo){
            tempPtr->data=nuevo;
            return 0;
        }else{
            tempPtr=tempPtr->nextPtr;
        }
    }

    return -1;
}

int Lista::printList(){
    // nodo temporal
    NODEPTR tempNode=headNode;

    if(tempNode!=NULL){
        while(tempNode!=NULL){
            std::cout<<tempNode->data<<"-->";
            tempNode=tempNode->nextPtr;
            if(tempNode->data==headNode->data){
                std::cout<<"HEAD\n\n";
                return 0;
            }
        }
    }else{
        std::cout<<"The list is empty.\n\n";
    }
    return 0;
}

