#include "src/visitor.h"
#include <stdio.h>

int main(){
    Visitor* billVisitor=getBillVisitor();
    Visitor* invoiceVisitor=getInvoiceVisitor();

    CartItem* buiscuit=getCartItem("Buiscuit",10);
    CartItem* coffee=getCartItem("Coffee",20);
    CartItem* chocolate=getCartItem("Chocolate",50);

    CartItem *itemArray[3];
    itemArray[0]=coffee;
    itemArray[1]=buiscuit;
    itemArray[2]=chocolate;

    for(int i=0;i<3;i++){
        itemArray[i]->accept(billVisitor,itemArray[i]);
    }

    printf("Total bill amount %d \n",((BillVisitor*)billVisitor)->totalAmount);

    for(int i=0;i<3;i++){
    itemArray[i]->accept(billVisitor,itemArray[i]);
    }

    printf("--------Invoice deatils--------- \n");
    
    for(int i=0;i<3;i++){
    itemArray[i]->accept(invoiceVisitor,itemArray[i]);
    }
    
}