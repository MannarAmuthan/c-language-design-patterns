#include "visitor.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void bill_visit(Visitor* visitor,CartItem* cart_item){
    BillVisitor* billVisitor=(BillVisitor*) visitor;
    billVisitor->totalAmount=(billVisitor->totalAmount)+cart_item->price;
}

void invoice_visit(Visitor* visitor,CartItem* cart_item){
    InvoiceVisitor* billVisitor=(InvoiceVisitor*) visitor;
    printf("---> Item name: %s , price: %d \n",cart_item->name,cart_item->price);
}

Visitor* getBillVisitor(){
    BillVisitor* billVisitor=(BillVisitor*)malloc(sizeof(BillVisitor));
    billVisitor->visit=bill_visit;
    return (Visitor*)billVisitor;
}

Visitor* getInvoiceVisitor(){
    InvoiceVisitor* invoiceVisitor=(InvoiceVisitor*)malloc(sizeof(InvoiceVisitor));
    invoiceVisitor->visit=invoice_visit;
    return (Visitor*)invoiceVisitor;
}

void visitorAccept(Visitor* visitor,CartItem* cart_item){
  visitor->visit(visitor,cart_item);
}

CartItem* getCartItem(char* name,int price){
    CartItem* cartItem=(CartItem*) malloc(sizeof(CartItem));
    int name_ln=strlen(name);
    cartItem->name=(char*)malloc(name_ln);
    strcpy(cartItem->name,name);
    cartItem->price=price;
    cartItem->accept=visitorAccept;
    return cartItem;
}