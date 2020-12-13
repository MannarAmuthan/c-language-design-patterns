#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/visitor.h"


int shouldCalculateTotalBill();
int shouldPrintInvoice();

int mockVisitedItems=0;


void mock_invoice_visit(Visitor* visitor,CartItem* cart_item){
    mockVisitedItems++;
}

int main(){
    int isAllPassed=1;
    if(shouldCalculateTotalBill()==-1){
        printf("Test failed : In visitor Pattern : --> shouldCalculateTotalBill \n");
        isAllPassed=0;
    }

    if(shouldPrintInvoice()==-1){
    printf("Test failed : In visitor Pattern : --> shouldPrintInvoice \n");
    isAllPassed=0;
    }

    if(isAllPassed!=1){
        exit(-1);
    }
    else{
         printf("All tests are passed : In visitor Pattern \n");
    }
}

int shouldCalculateTotalBill(){
    Visitor* billVisitor=getBillVisitor();
    CartItem* item_one=getCartItem("Item one",10);
    CartItem* item_two=getCartItem("Item two",20);
    CartItem *itemArray[2];
    itemArray[0]=item_one;
    itemArray[1]=item_two;

    for(int i=0;i<2;i++){
        itemArray[i]->accept(billVisitor,itemArray[i]);
    }

    if(((BillVisitor*)billVisitor)->totalAmount!=30) return -1;
    return 0;
}

int shouldPrintInvoice(){
    Visitor* invoiceVisitor=getInvoiceVisitor();
    CartItem* item_one=getCartItem("Item one",10);
    CartItem* item_two=getCartItem("Item two",20);
    invoiceVisitor->visit=mock_invoice_visit;
    CartItem *itemArray[2];
    itemArray[0]=item_one;
    itemArray[1]=item_two;

    for(int i=0;i<2;i++){
        itemArray[i]->accept(invoiceVisitor,itemArray[i]);
    }

    if(mockVisitedItems!=2) return -1;
    return 0;
}
