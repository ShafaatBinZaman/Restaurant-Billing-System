/** WELCOME TO GROUP B-7's LAB PROJECT **/
/**  RESTAURANT BILLING SYSTEM **/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>

struct foods
{
    char food[20];
    float price;
    int qty;
};

struct orders
{
    char customer[50];
    char date[50];
    int numOfFoods;
    struct foods f[50];
};
//functions to generate biils
void generateBillHeader(char name[50],char date[30])
{
    printf("\n\n");
    printf("\t    Bhai Bhai Restaurant");
    printf("\n\t  ...................");
    printf("\nDate:%s",date);
    printf("\nInvoice To: %s",name);
    printf("\n");
    printf(".......................................\n");
    printf("Foods\t\t");
    printf("Qty\t\t");
    printf("Total\t\t");
    printf("\n.......................................");
    printf("\n\n");
}
void generateBillBody(char food[30],int qty, float price)
{
    printf("%s\t\t",food);
    printf("%d\t\t",qty);
    printf("%.2f\t\t",qty * price);
    printf("\n");
}



void generateBillFooter(float total)
{
    printf("\n");
    float dis = 0.1*total;
    float netTotal=total-dis;
    float VAT=0.09*netTotal,pay=netTotal + 2*VAT;//netTotal + VAT + ST
    printf(".......................................\n");
    printf("Sub Total\t\t\t%.2f",total);
    printf("\nDiscount @10%s\t\t\t%.2f","%",dis);
    printf("\n\t\t\t\t-------");
    printf("\nNet Total\t\t\t%.2f",netTotal);
    printf("\nVAT @9%s\t\t\t\t%.2f","%",VAT);
    printf("\nST @9%s\t\t\t\t%.2f","%",VAT);
    printf("\n---------------------------------------");
    printf("\nPay\t\t\t\t%.2f Tk.",pay);
    printf("\n---------------------------------------\n");
}
int main()
{

    system("COLOR 70");
    int opt,n;
    struct orders ord;
    struct orders order;
    char saveBill = 'y',contFlag = 'y';
    char name[50];
    FILE *fp;

    while(contFlag == 'y')
    {

        float total = 0;
        int invoiceFound = 0;


        printf("\t********** BHAI BHAI RESTAURANT **********");
        printf("\n\nWhich operation do you want to perform?");
        printf("\n\n1.Generate an Invoice");
        printf("\n2.Search an Invoice");
        printf("\n3.Show all Invoices");
        printf("\n4.Exit");



        printf("\n\nYour choice is:\t");
        scanf("%d",&opt);
        fgetc(stdin);
        switch(opt)
        {
        case 1:

            printf("\nPlease insert the name of the customer:\t");
            fgets(ord.customer,50,stdin);
            ord.customer[strlen(ord.customer)-1] = 0;
            strcpy(ord.date,__DATE__);
            printf("\nHow many items is the customer buying :\t");
            scanf("%d",&n);
            ord.numOfFoods = n;
            for(int i=0; i<n; i++)
            {
                fgetc(stdin);
                printf("\n\n");
                printf("Please input the name of item %d:\t",i+1);
                fgets(ord.f[i].food,20,stdin);
                ord.f[i].food[strlen(ord.f[i].food)-1]=0;
                printf("Please enter the quantity:\t\t");
                scanf("%d",&ord.f[i].qty);
                printf("Unit price for this item:\t\t");
                scanf("%f",&ord.f[i].price);
                total += ord.f[i].qty * ord.f[i].price;
            }

            generateBillHeader(ord.customer,ord.date);
            for(int i=0; i<ord.numOfFoods; i++)
            {
                generateBillBody(ord.f[i].food,ord.f[i].qty,ord.f[i].price);
            }
            generateBillFooter(total);

            printf("\nDo you want to save the invoice [yes/no]:\t");
            scanf("%s",&saveBill);

            if(saveBill == 'y')
            {
                fp = fopen("RestaurantBill.dat","a+");
                fwrite(&ord,sizeof(struct orders),1,fp);
                if(fwrite != 0)
                    printf("\nThe bill was saved successfully!");
                else
                    printf("\nSorry,the bill was not saved!");
                fclose(fp);
            }
            break;

        case 2:
            printf("Enter the name of the customer:\t");

            fgets(name,50,stdin);
            name[strlen(name)-1] = 0;

            fp = fopen("RestaurantBill.dat","r");
            printf("\t*****Invoice of %s*****",name);
            while(fread(&order,sizeof(struct orders),1,fp))
            {
                float tot = 0;
                if(!strcmp(order.customer,name))
                {
                    generateBillHeader(order.customer,order.date);
                    for(int i=0; i<order.numOfFoods; i++)
                    {
                        generateBillBody(order.f[i].food,order.f[i].qty,order.f[i].price);
                        tot+=order.f[i].qty * order.f[i].price;
                    }
                    generateBillFooter(tot);
                    invoiceFound = 1;
                }

            }
            if(!invoiceFound)
            {
                printf("\nSorry the invoice for %s was not found!",name);
            }
            fclose(fp);
            break;

        case 3:

            fp = fopen("RestaurantBill.dat","r");
            printf("\n  *****Your Previous Invoices*****\n");
            while(fread(&order,sizeof(struct orders),1,fp))
            {
                float tot = 0;
                generateBillHeader(order.customer,order.date);
                for(int i=0; i<order.numOfFoods; i++)
                {
                    generateBillBody(order.f[i].food,order.f[i].qty,order.f[i].price);
                    tot+=order.f[i].qty * order.f[i].price;
                }
                generateBillFooter(tot);
            }
            fclose(fp);
            break;

        case 4:
            printf("\n\t\t Bye Bye :)\n\n");
            exit(0);
            break;

        default:
            printf("Sorry invalid option");
            break;
        }
        printf("\n\nDo you want to perform another operation?[yes/no]:\t");
        scanf("%s",&contFlag);
        system("cls");
    }
    printf("\n\t\t Bye Bye :)\n\n");
    printf("\n\n");

    return 0;
}
