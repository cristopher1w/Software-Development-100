#include<iostream>
#include<fstream>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<direct.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;

void gotoxy(int x, int y)
{
COORD c;
c.X=x;
c.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

class menu
{
public :
    void main_menu(void) ;
private :
    void edit_menu(void) ;
} ;

class product
{
public :
    void add_item(void) ;
    void delete_item(void) ;
    void modify_item(void) ;
    void list_of_item(void) ;
    void purchase(void) ;

private :
    int last_code(void) ;
    void delete_record(int) ;
    void modify_record(int) ;
    void display_record(int) ;
    int item_found(int) ;
    int recordno(int) ;
    void sort(void) ;

    int itemcode ;
    char itemname[30] ;
    float itemcost, itemprice ;
} ;


class account
{
public :
    void bill_list(void) ;
    void prepare_bill(int) ;
    int last_billno(void) ;
    void add_bill(int, int t_itemcode, char *t_itemname, float t_qty,
                  float t_cost, float t_price) ;

private :
    int code, billno, length ;
    int dd, mm, yy ;
    float cost, price, quantity ;
    char name[30] ;
} ;

void menu :: main_menu(void)
{
    system("cls");
    char ch ;
    while (1)
    {
    system("cls");
    gotoxy(10,3) ;      cout<<"***************************************************************************************" ;
        gotoxy(10,4   ) ;cout<<"**" ;                                                                                           gotoxy(95,4   ) ;cout<<"**" ;
        gotoxy(10,5   ) ;cout<<"**" ;                                                                                           gotoxy(95,5   ) ;cout<<"**" ;
        gotoxy(10,6   ) ;cout<<"**" ;                                                                                           gotoxy(95,6   ) ;cout<<"**" ;
        gotoxy(10,7   ) ;cout<<"**" ;                                                                                           gotoxy(95,7   ) ;cout<<"**" ;
        gotoxy(10,8   ) ;cout<<"**" ;                                                                                           gotoxy(95,8   ) ;cout<<"**" ;
        gotoxy(10,9   ) ;cout<<"**" ;                                                                                           gotoxy(95,9  ) ;cout<<"**" ;
        gotoxy(10,10 ) ;cout<<"**" ;                                                                                           gotoxy(95,10   ) ;cout<<"**" ;
        gotoxy(10,11 );cout<<"**" ;                                                                                            gotoxy(95,11   ) ;cout<<"**" ;
        gotoxy(10,12 );cout<<"**" ;                                                                                            gotoxy(95,12   ) ;cout<<"**" ;
        gotoxy(10,13 );cout<<"**" ;                                                                                            gotoxy(95,13   ) ;cout<<"**" ;
        gotoxy(10,14 );cout<<"**" ;                                                                                            gotoxy(95,14  ) ;cout<<"**" ;
        gotoxy(10,15 );cout<<"**" ;                                                                                            gotoxy(95,15   ) ;cout<<"**" ;
        gotoxy(10,16 );cout<<"**" ;                                                                                            gotoxy(95,16   ) ;cout<<"**" ;
        gotoxy(10,17 );cout<<"**" ;                                                                                            gotoxy(95,17  ) ;cout<<"**" ;
        gotoxy(10,18 );cout<<"**" ;                                                                                            gotoxy(95,18   ) ;cout<<"**" ;
        gotoxy(10,19 );cout<<"**" ;                                                                                            gotoxy(95,19   ) ;cout<<"**" ;
        gotoxy(10,20 );cout<<"**" ;                                                                                            gotoxy(95,20   ) ;cout<<"**" ;
        gotoxy(10,21 );cout<<"**" ;                                                                                            gotoxy(95,21   ) ;cout<<"**" ;
        gotoxy(10,22 );cout<<"**" ;                                                                                            gotoxy(95,22   ) ;cout<<"**" ;
        gotoxy(10,23) ; cout<<"***************************************************************************************" ;
        gotoxy(32,6) ;
    std::cout <<"SALES  MANAGEMENT  SYSTEM  By Team CYBERNAUTS" ;
        gotoxy(28,5) ;
    std::cout <<"||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||" ;          gotoxy(28,6) ;cout <<"||";
        gotoxy(28,7) ;
    std::cout <<"||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||" ;            gotoxy(77,6) ;cout <<"||";
        gotoxy(30,9) ;
    std::cout <<"1: PURCHASE  PRODUCTS" ;
        gotoxy(30,11) ;
    std::cout <<"2: LIST OF PRODUCTS" ;
        gotoxy(30,13) ;
    std::cout <<"3: EDIT PRODUCTS FILE" ;
        gotoxy(30,15) ;
    std::cout <<"4: BILLS REPORT" ;
        gotoxy(30,17) ;
     std::cout <<"5: QUIT" ;
        gotoxy(30,20) ;
    std::cout <<"Enter Your Choice -->" ;
        ch = getche() ;

        if (ch == '1')
        {
            product p ;
            p.purchase() ;
        }

        else if (ch == '2')
        {
            product p ;
            p.list_of_item() ;
        }

        else if (ch == '3')
            edit_menu() ;

        else if (ch == '4')
        {
            account a ;
            a.bill_list();
        }

        else if (ch == '5')
            break ;
    }
}

void menu :: edit_menu(void)
{
    char ch ;
    while (1)
    {
        system("cls");
        gotoxy(10,4) ;cout<<"**";       gotoxy(61,4) ;cout<<"**";    gotoxy(10,5) ;cout<<"**";    gotoxy(10,6) ;cout<<"**";
       gotoxy(10,7) ;cout<<"**";       gotoxy(10,8) ;cout<<"**";    gotoxy(10,9) ;cout<<"**";
       gotoxy(10,10) ;cout<<"**";    gotoxy(10,11) ;cout<<"**";  gotoxy(10,12) ;cout<<"**";
       gotoxy(10,13) ;cout<<"**";    gotoxy(10,14) ;cout<<"**";   gotoxy(10,15) ;cout<<"**";
       gotoxy(10,16) ;cout<<"**";    gotoxy(10,17) ;cout<<"**";   gotoxy(10,18) ;cout<<"**";
       gotoxy(10,19) ;cout<<"**";    gotoxy(10,20) ;cout<<"**";   gotoxy(10,21) ;cout<<"**";
       gotoxy(10,22) ;cout<<"**";    gotoxy(61,5) ;cout<<"**";     gotoxy(61,6) ;cout<<"**";
       gotoxy(61,7) ;cout<<"**";       gotoxy(61,8) ;cout<<"**";     gotoxy(61,9) ;cout<<"**";
       gotoxy(61,10) ;cout<<"**";    gotoxy(61,11) ;cout<<"**";   gotoxy(61,12) ;cout<<"**";
       gotoxy(61,13) ;cout<<"**";    gotoxy(61,14) ;cout<<"**";   gotoxy(61,15) ;cout<<"**";
       gotoxy(61,16) ;cout<<"**";    gotoxy(61,17) ;cout<<"**";   gotoxy(61,18) ;cout<<"**";
       gotoxy(61,19) ;cout<<"**";    gotoxy(61,20) ;cout<<"**";   gotoxy(61,21) ;cout<<"**";   gotoxy(61,22) ;cout<<"**";

        gotoxy(10,3) ;        cout<<"*****************************************************" ;
        gotoxy(25,6) ;        cout <<"EDIT   MENU" ;
        gotoxy(25,7) ;        cout <<"~~~~~~~~~~~" ;
        gotoxy(25,10) ;      cout <<"1: ADD  PRODUCTS" ;
        gotoxy(25,12) ;      cout <<"2: MODIFY  PRODUCTS" ;
        gotoxy(25,14) ;      cout <<"3: DELETE  PRODUCTS" ;
        gotoxy(25,16) ;      cout <<"0: EXIT" ;
        gotoxy(25,19) ;      cout <<"Enter Choice :    " ;
        gotoxy(10,23) ;      cout<<"*****************************************************" ;
        ch = getche() ;


        if (ch == '1')
        {
            product p ;
            p.add_item() ;
            break ;
        }
        else if (ch == '2')
        {
            product p ;
            p.modify_item() ;
            break ;
        }
        else if (ch == '3')
        {
            product p ;
            p.delete_item() ;
            break ;
        }
        else if (ch == '0')
            break ;
    }
}

int product :: last_code(void)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int t=0 ;
    while (file.read((char *) this, sizeof(product)))
        t = itemcode ;
    file.close() ;
    return t ;
}

void product :: list_of_item(void)
{
    system("cls");
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0) ;
    int row = 6 , found = 0 ;
    gotoxy(30,2) ;
    cout <<"LIST OF ITEMS" ;
    gotoxy(3,4) ;
    cout <<"ITEM CODE     ITEM NAME                     BUYING COST          SELLING PRICE" ;
    gotoxy(2,5) ;
    cout <<"**************************************************************************************" ;
    while (file.read((char *) this, sizeof(product)))
    {
        Sleep(200);
        found = 1 ;
        gotoxy(6,row) ;
        cout <<itemcode ;
        gotoxy(17,row) ;
        cout <<itemname ;
        gotoxy(50,row) ;
        cout <<itemcost ;
        gotoxy(70,row) ;
        cout <<itemprice ;
        if ( row == 22 )
        {
            row = 5 ;
            gotoxy(1,25) ;
            cout <<"Press any key to continue..." ;
            getche() ;
        system("cls");
            gotoxy(30,2) ;
            cout <<"LIST OF ITEMS" ;
            gotoxy(3,4) ;
            cout <<"ITEM CODE     ITEM NAME       BUYING COST         SELLING PRICE" ;
            gotoxy(2,5) ;
            cout <<"***************************************************************";
        }
        else
            row++ ;
    }
    if ( !found )
    {
        gotoxy(5,10) ;
        cout <<"\7Records not found" ;
    }
    gotoxy(1,25) ;
    cout <<"Press any key to continue..." ;
    getche() ;
    file.close () ;
}

void product :: add_item(void)
{
    int tcode, valid ;
    char ch, t_itemcost[10], t_itemprice[10] ;
    tcode = last_code() ;
    tcode++ ;
    do
    {
       system("cls");
        gotoxy(71,2) ;
        cout <<"<0>=Exit" ;
        gotoxy(27,3) ;
        cout <<"ADDITION OF PRODUCTS" ;
        gotoxy(26,4) ;
        cout <<"************************" ;
        gotoxy(5,6) ;
        cout <<"Item Code : " <<tcode ;
        gotoxy(5,8) ;
        cout <<"Item Name : " ;
        gotoxy(5,10) ;
        cout <<"Buying Cost : " ;
        gotoxy(5,12) ;
        cout <<"Selling Price : " ;
        do
        {
            valid = 1 ;

            gotoxy(3,25) ;
            cout <<"ENTER ITEM NAME TO ADD IN THE MENU" ;
            gotoxy(5,8) ;
            cout <<"Item Name : " ;
            gets(itemname) ;
                if (itemname[0] == '0')
                return ;
            if ((strlen(itemname) < 1) || (strlen(itemname) > 30))
            {
                valid = 0 ;
                gotoxy(3,24) ;
                cout <<"\7 Range = 1..30" ;
                getch() ;
            }
        }
        while (!valid) ;
        do
        {
            valid = 1 ;

            gotoxy(3,25) ;
            cout <<"ENTER BUYING COST TO ADD IN THE MENU" ;
            gotoxy(5,10) ;
            cout <<"Buying Cost : " ;
            gets(t_itemcost) ;
            itemcost = atof(t_itemcost) ;
            if (t_itemcost[0] == '0')
                return ;
            if (itemcost < 1 || itemcost > 800000)
            {
                valid = 0 ;
                gotoxy(3,24) ;
                cout <<"\7 Range = 1..80000" ;
                getch() ;
            }
        }
        while (!valid) ;
        do
        {
            valid = 1 ;

            gotoxy(3,25) ;
            cout <<"ENTER SELLING PRICE TO ADD IN THE MENU" ;
            gotoxy(5,12) ;
            cout <<"Selling Price : " ;
            gets(t_itemprice) ;
            itemprice = atof(t_itemprice) ;
            if (t_itemprice[0] == '0')
                return ;
            if (itemprice < itemcost || itemprice > 1000000)
            {
                valid = 0 ;
                gotoxy(3,24) ;
                cout <<"\7 Range = " <<itemcost <<"..1000000" ;
                getch() ;
            }
        }
        while (!valid) ;
        do
        {

            gotoxy(5,15) ;
            cout <<"Do you want to save this record (y/n) : " ;
            ch = getche() ;
            ch = toupper(ch) ;
            if (ch == '0')
                return ;
        }
        while (ch != 'N' && ch != 'Y') ;
        if (ch == 'Y')
        {
            itemcode = tcode ;
            fstream file ;
            file.open("PRODUCT.DAT", ios::out | ios::app ) ;
            file.write((char *) this, sizeof(product)) ;
            file.close() ;
            tcode++ ;
        }
        do
        {
          ;
            gotoxy(5,17) ;
            cout <<"Do you want to add more records (y/n) : " ;
            ch = getche() ;
            ch = toupper(ch) ;
            if (ch == '0')
                return ;
        }
        while (ch != 'N' && ch != 'Y') ;
    }
    while (ch == 'Y') ;
}

void product :: display_record(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    while (file.read((char *) this, sizeof(product)))
    {
        if (itemcode == tcode)
        {
            gotoxy(5,3) ;
            cout <<"Item Code : "<<itemcode ;
            gotoxy(5,4) ;
            cout <<"Item Name : "<<itemname ;
            gotoxy(5,5) ;
            cout <<"Buying Cost : "<<itemcost ;
            gotoxy(5,6) ;
            cout <<"Selling Price : "<<itemprice ;
            break ;
        }
    }
    file.close() ;
}


int product :: item_found(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int found=0 ;
    while (file.read((char *) this, sizeof(product)))
    {
        if (itemcode == tcode)
        {
            found++ ;
            break ;
        }
    }
    file.close() ;
    return found ;
}

int product :: recordno(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int found=0 ;
    while (file.read((char *) this, sizeof(product)))
    {
        found++ ;
        if (itemcode == tcode)
            break ;
    }
    file.close() ;
    return found ;
}


void product :: delete_record(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    fstream temp ;
    temp.open("temp.dat", ios::out) ;
    file.seekg(0,ios::beg) ;
    while ( !file.eof() )
    {
        file.read((char *) this, sizeof(product)) ;
        if ( file.eof() )
            break ;
        if ( itemcode != tcode )
            temp.write((char *) this, sizeof(product)) ;
    }
    file.close() ;
    temp.close() ;
    file.open("PRODUCT.DAT", ios::out) ;
    temp.open("temp.dat", ios::in) ;
    temp.seekg(0,ios::beg) ;
    while ( !temp.eof() )
    {
        temp.read((char *) this, sizeof(product)) ;
        if ( temp.eof() )
            break ;
        file.write((char *) this, sizeof(product)) ;
    }
    file.close() ;
    temp.close() ;
}


void product :: delete_item(void)
{
    system("cls");
    char t_code[5], ch ;
    int t, tcode ;
    gotoxy(3,25) ;
    cout <<"Press <ENTER> to see the list" ;
    gotoxy(5,3) ;
    cout <<"Enter Item Code of the item to be deleted : " ;
    gets(t_code) ;
    t = atoi(t_code) ;
    tcode = t ;
    if (t_code[0] == '0')
        return ;
    if (tcode == 0)
    {
        list_of_item() ;

        gotoxy(3,25) ;
        cout <<"Press <ENTER> to Exit" ;
        gotoxy(5,24) ;
        cout <<"Enter Item Code of the item to be deleted : " ;
        gets(t_code) ;
        t = atoi(t_code) ;
        tcode = t ;
        if (tcode == 0)
            return ;
    }
    system("cls");
    if (!item_found(tcode))
    {
        gotoxy(5,5) ;
        cout <<"\7Record not found" ;
        getch() ;
        return ;
    }
    display_record(tcode) ;
    do
    {

        gotoxy(5,8) ;
        cout <<"Do you want to delete this record (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
    }
    while (ch != 'N' && ch != 'Y') ;
    if (ch == 'N')
        return ;
    delete_record(tcode) ;
    gotoxy(5,15) ;
    cout <<"\7Record Deleted" ;
    getch() ;
}



void product :: modify_record(int tcode)
{
    int recno ;
    recno = recordno(tcode) ;
    int valid, t_code ;
    char ch, t_itemcost[10], t_itemprice[10], t_itemcode[5] ;
    gotoxy(71,2) ;
    cout <<"<0>=Exit" ;
    gotoxy(5,12) ;
    cout <<"Item Code : " ;
    gotoxy(5,14) ;
    cout <<"Item Name : " ;
    gotoxy(5,16) ;
    cout <<"Item Cost : " ;
    gotoxy(5,18) ;
    cout <<"Item Price : " ;
    do
    {

        cout <<"Change (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;

        gotoxy(3,25) ;
        cout <<"ENTER ITEM CODE TO ADD IN THE MENU" ;
        gotoxy(5,12) ;
        cout <<"Item Code : " ;
        gets(t_itemcode) ;
        t_code = atoi(t_itemcode) ;
        if (t_code == 0)
            return ;
        if (item_found(t_code) && t_code != tcode)
        {
            valid = 0 ;
            gotoxy(3,24) ;
            cout <<"\7 CODE ALREADY GIVEN" ;
            getch() ;
        }
    }
    do
    {

        cout <<"Change (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;

        gotoxy(3,25) ;
        cout <<"ENTER ITEM NAME TO ADD IN THE MENU" ;
        gotoxy(5,14) ;
        cout <<"Item Name : " ;
        gets(itemname) ;
        if (itemname[0] == '0')
            return ;
        if ((strlen(itemname) < 1) || (strlen(itemname) > 20))
        {
            valid = 0 ;
            gotoxy(3,24) ;
            cout <<"\7 Range = 1..20" ;
            getch() ;
        }
    }
    do
    {

        cout <<"Change (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;

        gotoxy(3,25) ;
        cout <<"ENTER ITEM COST TO ADD IN THE MENU" ;
        gotoxy(5,16) ;
        cout <<"Item Cost : " ;
        gets(t_itemcost) ;
        itemcost = atof(t_itemcost) ;
        if (t_itemcost[0] == '0')
            return ;
        if (itemcost < 1 || itemcost > 800)
        {
            valid = 0 ;
            gotoxy(3,24) ;
            cout <<"\7 Range = 1..800" ;
            getch() ;
        }
    }
    do
    {

        cout <<"Change (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;

        gotoxy(3,25) ;
        cout <<"ENTER ITEM PRICE TO ADD IN THE MENU" ;
        gotoxy(5,18) ;
        cout <<"Item Price : " ;
        gets(t_itemprice) ;
        itemprice = atof(t_itemprice) ;
        if (t_itemprice[0] == '0')
            return ;
        if (itemprice < itemcost || itemprice > 1000)
        {
            valid = 0 ;
            gotoxy(3,24) ;
            cout <<"\7 Range = " <<itemcost <<"..1000" ;
            getch() ;
        }
    }
    do
    {

        gotoxy(5,21) ;
        cout <<"Do you want to save this record (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    if (ch == 'N')
        return ;
    itemcode = t_code ;
    cout <<"\n" <<itemname ;
    cout <<itemcost ;
    cout <<itemprice ;
    getch() ;
    fstream file ;
    file.open("PRODUCT.DAT", ios::out | ios::ate) ;
    int location ;
    location = (recno-1) * sizeof(product) ;
    file.seekp(location) ;
    file.write((char *) this, sizeof(product)) ;
    file.close() ;
    sort() ;
    system("cls");
    gotoxy(5,15) ;
    cout <<"\7Record Modified" ;
    getch() ;
}

void product :: modify_item(void)
{
       system("cls");
    char t_code[5], ch ;
    int t, tcode ;
    gotoxy(3,25) ;
    cout <<"Press <ENTER> to see the list" ;
    gotoxy(5,3) ;
    cout <<"Enter Item Code of the item to be Modify : " ;
    gets(t_code) ;
    t = atoi(t_code) ;
    tcode = t ;
    if (t_code[0] == '0')
        return ;
    if (tcode == 0)
    {
        list_of_item() ;

        gotoxy(3,25) ;
        cout <<"Press <ENTER> to Exit" ;
        gotoxy(5,24) ;
        cout <<"Enter Item Code of the item to be modify : " ;
        gets(t_code) ;
        t = atoi(t_code) ;
        tcode = t ;
        if (tcode == 0)
            return ;
    }
   system("cls");
    if (!item_found(tcode))
    {
        gotoxy(5,5) ;
        cout <<"\7Record not found" ;
        getch() ;
        return ;
    }
    display_record(tcode) ;
    do
    {
        gotoxy(5,8) ;
        cout <<"Do you want to Modify this record (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
    }
    while (ch != 'N' && ch != 'Y') ;
    if (ch == 'N')
        return ;
    modify_record(tcode) ;
}

void product :: sort(void)
{
    int i=0,j ;
    product arr[100] ;
    product temp ;
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    while (file.read((char *) &arr[i], sizeof(product)))
        i++ ;
    int size ;
    size = i ;
    file.close() ;
    for (i=1; i<size; i++)
        for (j=0; j<size-i; j++)
        {
            if (arr[j].itemcode > arr[j+1].itemcode)
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    file.open("PRODUCT.DAT", ios::out) ;
    for (i=0; i<size; i++)
        file.write((char *) &arr[i], sizeof(product)) ;
    file.close() ;
}

void product :: purchase(void)
{
   system("cls");
    account a ;
    int t_billno, purchased=0 ;
    t_billno = a.last_billno() ;
    t_billno++ ;
    char t_code[5], ch;
    float t_quantity ;
    int t, tcode, i=0, valid ;
    float qty ;
    int t_itemcode ;
    float t_qty, t_cost, t_price ;
    char t_itemname[30] ;

    do
    {
        system("cls");
        gotoxy(3,25) ;
        cout <<"Press <ENTER> to see the list" ;
        gotoxy(5,3) ;
        cout <<"Enter Item Code of the item to be Purchase : " ;
        gets(t_code) ;
        t = atoi(t_code) ;
        tcode = t ;
        if (t_code[0] == '0')
        {
            if (purchased)
                a.prepare_bill(t_billno) ;
            return ;
        }
        if (tcode == 0)
        {
            list_of_item() ;

            gotoxy(3,25) ;
            cout <<"Press <ENTER> to Exit" ;
            gotoxy(5,24) ;
            cout <<"Enter Item Code of the item to be Purchase : " ;
            gets(t_code) ;
            t = atoi(t_code) ;
            tcode = t ;
            if (tcode == 0)
            {
                if (purchased)
                    a.prepare_bill(t_billno) ;
                return ;
            }
        }
        system("cls");
        if (!item_found(tcode))
        {
            gotoxy(5,5) ;
            cout <<"\7Item Code not found" ;
            getch() ;
            if (purchased)
                a.prepare_bill(t_billno) ;
            return ;
        }
        gotoxy(60,2) ;

        display_record(tcode) ;
        do
        {
            valid = 1 ;

            gotoxy(3,25) ;
            cout <<"ENTER QUANTITY TO BE PURCHASE IN PCS." ;
            gotoxy(5,8) ;
            cout <<"Quantity : " ;
            cin>>t_quantity ;
            qty=t_quantity ;
            if (t_quantity == 0)
            {
                if (purchased)
                    a.prepare_bill(t_billno) ;
                return ;
            }
            if (qty < 1 || qty > 800)
            {
                valid = 0 ;
                gotoxy(3,24) ;
                cout <<"\7 Range = 1..800" ;
                getch() ;
            }
        }
        while (!valid) ;
        do
        {

            gotoxy(5,10) ;
            cout <<"Do you want to cancel this purchase (y/n) : " ;
            ch = getche() ;
            ch = toupper(ch) ;
        }
        while (ch != 'N' && ch != 'Y') ;
        if (ch == 'N')
        {
            purchased = 1 ;
            fstream file ;
            file.open("PRODUCT.DAT", ios::in) ;
            file.seekg(0,ios::beg) ;
            while (file.read((char *) this, sizeof(product)))
            {
                if (itemcode == tcode)
                {
                    t_itemcode = itemcode ;
                    strcpy(t_itemname,itemname) ;
                    t_cost = itemcost ;
                    t_price = itemprice ;
                    t_qty = qty ;
                    a.add_bill(t_billno, t_itemcode, t_itemname, t_qty, t_cost, t_price) ;
                    i++ ;
                    break ;
                }
            }
            file.close() ;
        }
        do
        {

            gotoxy(5,12) ;
            cout <<"Do you want to purchase more (y/n) : " ;
            ch = getche() ;
            ch = toupper(ch) ;
        }
        while (ch != 'N' && ch != 'Y') ;
    }
    while (ch == 'Y') ;
    a.prepare_bill(t_billno) ;
}

int account :: last_billno(void)
{
    fstream file ;
    file.open("BILL.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int t=0 ;
    while (file.read((char *) this, sizeof(account)))
        t = billno ;
    file.close() ;
    return t ;
}

void account :: add_bill(int t_billno, int t_itemcode, char t_itemname[30], float t_qty, float t_cost, float t_price)
{
    code = t_itemcode ;
    strcpy(name,t_itemname) ;
    cost = t_cost ;
    price = t_price ;
    quantity = t_qty ;
    billno = t_billno ;
    fstream file ;
    file.open("BILL.DAT", ios::out | ios:: app ) ;
    file.write((char *) this, sizeof(account)) ;
    file.close() ;
}

void account :: prepare_bill(int t_billno)
{
   system("cls");

    float total, total_bill ;
    gotoxy(33,3) ;
    cout <<"CUSTOMER BILL" ;
    gotoxy(55,5) ;
    gotoxy(8,7) ;
    cout <<"ITEMS PURCHASED" ;
    gotoxy(8,8) ;
    cout <<"===================" ;
    gotoxy(8,9) ;
    cout <<"Item code      Item name      Cost Price      Qty      Total";
    gotoxy(8,10) ;
    cout <<"-----------------------------------------------------------------------------------------";
    int row=11 ;
    fstream file ;
    file.open("BILL.DAT", ios::in) ;
    file.seekg(0) ;
    {
        if (billno == t_billno)
        {
            gotoxy(8,5) ;
            cout <<"BILL NO. # " <<billno ;
            gotoxy(8,6) ;
            cout <<"=========================" ;
            gotoxy(10,row) ;
            cout <<code ;
            gotoxy(18,row) ;
            cout <<name ;
          //  gotoxy(39,row) ;
            cout <<cost ;
            gotoxy(47,row) ;
            cout <<price ;
            gotoxy(56,row) ;
            cout <<quantity ;
            total = (quantity * price );
            gotoxy(63,row) ;
            cout <<total ;
            total_bill = (  total_bill + total );
            row++ ;
        }
    }
    file.close() ;
    gotoxy(39,row+1) ;
    cout <<"TOTAL BILL: TK." <<total <<" /=" ;
    getch() ;
}

void account :: bill_list(void)
{
    system("cls");
    fstream file ;
    file.open("BILL.DAT", ios::in) ;
    file.seekg(0) ;
    int row=5, found=0, pageno=1, prev_billno=0, flag=0 ;
    float total=0.0, total_bill=0.0 ;
    gotoxy(30,2) ;
    cout <<"LIST OF BILLS" ;
    gotoxy(3,4) ;
    cout <<"Billno.      Item Code      Item name     Cost Pri      Qty       Total" ;
    gotoxy(3,5) ;
    cout
            <<"===========================================================================" ;
    while (file.read((char *) this, sizeof(account)))
    {
        row++ ;
        Sleep(200);
        found = 1 ;
        if (prev_billno != billno)
        {
            if (flag)
            {
                gotoxy(52,row) ;
                cout <<"TOTAL BILL: TK." <<total_bill <<"/=" ;
                total_bill = 0.0 ;
                row++ ;
            }
            gotoxy(4,row) ;
            cout <<billno ;
        }
        flag = 1 ;

        gotoxy(24,row) ;
        cout <<code ;
        gotoxy(32,row) ;
        cout <<name ;
        gotoxy(52,row) ;
        cout <<cost ;
        gotoxy(59,row) ;
        cout <<price ;
        gotoxy(67,row) ;
        cout <<quantity ;
        total = (quantity * price );
        gotoxy(73,row) ;
        cout <<total ;
        total_bill = (total_bill + total) ;
        if ( row >= 23 )
        {
            row = 5 ;
            gotoxy(66,1) ;
            cout <<"Page no. : " <<pageno ;
            pageno++ ;
            gotoxy(1,25) ;
            cout <<"Press any key to continue..." ;
            getche() ;
             system("cls");
            gotoxy(30,2) ;
            cout <<"LIST OF BILLS" ;
            gotoxy(3,4) ;
            cout <<"Billno.      Item Code         Item name         CostPrice      Qty           Total" ;
            gotoxy(3,5) ;
            cout
                    <<"===========================================================================" ;
        }
        prev_billno = billno ;
    }
    row++ ;
    gotoxy(52,row) ;
    cout <<"TOTAL BILL: TK." <<total_bill <<"/=" ;
    if ( !found )
    {
        gotoxy(5,10) ;
        cout <<"\7Records not found" ;
    }
    gotoxy(66,1) ;
    cout <<"Page no. : " <<pageno ;
    gotoxy(1,25) ;
    cout <<"Press any key to continue..." ;
    getche() ;
    file.close () ;
}

int main(void)
{
   system("cls");
    menu m ;
    m.main_menu() ;
}
