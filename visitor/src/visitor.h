#ifndef __VISITOR_H
#define __VISITOR_H

typedef struct cart_item{
    int price;
    char* name;
    void (*accept)(void*,struct cart_item*);
} CartItem;

typedef struct visitor{
    void (*visit)(struct visitor*,CartItem*);
} Visitor;

typedef struct visitor_bill{
    void (*visit)(CartItem*);
    int totalAmount;
} BillVisitor;

typedef struct visitor_invoice{
    void (*visit)(CartItem*);
} InvoiceVisitor;

Visitor* getBillVisitor();
Visitor* getInvoiceVisitor();
CartItem* getCartItem(char* name,int price);

#endif
