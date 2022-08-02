#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int sum=0;
struct node
{
    char foodname[50];
    int quantity;
    float price;
    int data;
    char type[30];
    struct node *prev;
    struct node *next;
};

struct node *adc = NULL,*t,*cust = NULL;
struct node *ads = NULL, *adt = NULL;
struct node *head_s;

void ad_men()
{
    printf("\n\t\t\t\t\t\t\t1. View total sales\n");
    printf("\t\t\t\t\t\t\t2. Add new items in the order menu\n");
    printf("\t\t\t\t\t\t\t3. Delete items from the order menu\n");
    printf("\t\t\t\t\t\t\t4. Display order menu\n");
    printf("\t\t\t\t\t\t\t5. Back To Main Menu \n\n");
    printf("\t\t\t\t\t\t\t   Enter Your Choice:");
}

void cust_men()
{
    printf("\n\t\t\t\t\t\t\t1. Place your order\n");
    printf("\t\t\t\t\t\t\t2. View your ordered items\n");
    printf("\t\t\t\t\t\t\t3. Delete an item from order\n");
    printf("\t\t\t\t\t\t\t4. Display final bill\n");
     printf("\t\t\t\t\t\t\t5. Display items according to type\n");
    printf("\t\t\t\t\t\t\t6. Back To Main Menu \n\n");
    printf("\t\t\t\t\t\t\t   Enter Your Choice:");
}

struct node* cr_ad(struct node *head,int data, char foodname[25], float price,char type[35])
{
    t = (struct node*)malloc(sizeof(struct node));

    t->data = data;
    t->price = price;
    t-> quantity = 0;
    strcpy(t->foodname,foodname);
    strcpy(t->type,type);
    t->next = NULL;
    t->prev = NULL;

    struct node *temp = head;

    if(temp==NULL)
        ads = adt = t;
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;

        temp->next=t;
        t->prev = adt;
        adt = t;
    }

    return ads;
}

struct node* cr_cus(struct node *head,int data,int quantity)
{
    t = (struct node*)malloc(sizeof(struct node));

    struct node *temp1 = ads;
    int flag = 0;
    while(temp1!=NULL)
    {
        if(temp1->data==data)
        {
            flag = 1;
            break;
        }
        temp1 = temp1->next;
    }

    if(flag==1)
    {
        t->data = data;
        t->price = quantity*(temp1->price);
        t-> quantity = quantity;
        strcpy(t->foodname,temp1->foodname);
        strcpy(t->type,temp1->type);
        t->next = NULL;
        t->prev = NULL;

        struct node *temp = head;

        if(temp==NULL)
            adc = cust = t;
        else
        {
            while(temp->next!=NULL)
                temp=temp->next;

            temp->next=t;
            t->prev = cust;
            cust = t;
        }


    }
    else
    {
        printf("\n\t\t\t\t\t\t\tThis item is not available!\n");
    }
    return adc;
}

void disp(struct node *head)
{
    struct node *temp1 = head;
    if(temp1==NULL)
    {
        printf("\n\t\t\t\t\t\t\t\tList is empty!\n\n");
    }
    else
    {
        printf("\n");
        while(temp1!=NULL)
        {
            if(temp1->quantity==0)
                printf("\t\t\t\t\t\t\t%d\t%s\t%0.2f\t%s\n",temp1->data,temp1->foodname,temp1->price,temp1->type);
            else
            {
                printf("\t\t\t\t\t\t\t%d\t%s\t%d\t%0.2f\t%s\n",temp1->data,temp1->foodname,temp1->quantity,temp1->price,temp1->type);
            }

            temp1 = temp1->next;
        }
        printf("\n");
    }

}





void disp_type(struct node *head)
{
    struct node *temp1 = head;
    if(temp1==NULL)
    {
        printf("\n\t\t\t\t\t\t\t\tList is empty!\n\n");
    }
    else
    
    
    {
        char newtype[30];
        printf("Enter type of food:South,North,Chinese\n");
        scanf("%s",newtype); 
        int flag=0;
        printf("\t\t\t\t\t\t\tNo\tName\tPrice\tType\n");
        while( temp1!=NULL)
        {
            if(strcmp(temp1->type,newtype)==0){
               flag=1;
                printf("\t\t\t\t\t\t\t%d\t%s\t%0.2f\t%s\n",temp1->data,temp1->foodname,temp1->price,temp1->type);
            }

            temp1 = temp1->next;
        }
        
        if(flag==0){
            
            printf("NO SUCH TYPE!");
        }
        printf("\n");
    }
}



void update(struct node *head)
{
    struct node *temp1 = head;
    if(temp1==NULL)
    {
        printf("\n\t\t\t\t\t\t\t\tList is empty!\n\n");
    }
    else
    
    
    {
        int serialno;
        printf("serial number of food to update:\n");
        scanf("%d",&serialno); 
       
        printf("\t\t\t\t\t\t\tNo\tName\tPrice\tType\n");
        while( temp1->data!=serialno && temp1->next!=NULL)
        {
           
            temp1 = temp1->next;
        }
        if(temp1->data!=serialno){
            printf("Food with that serialno does not exist!");
        }
        else{
            int newprice;
            printf("Enter new price of the food item:");
            scanf("%d",&newprice);
            
            
            temp1->price=newprice;
            
        }
        
        
        printf("\n");
    }
}









struct node* totalsales(int data,int quantity)
{
    t = (struct node*)malloc(sizeof(struct node));
    int flag = 0;

    struct node *temp1 = ads;
    while(temp1->data!=data)
    {
        temp1 = temp1->next;
    }

    t->data = data;
    t->price = quantity*(temp1->price);
    t-> quantity = quantity;
    strcpy(t->foodname,temp1->foodname);
    strcpy(t->type,temp1->type);
    t->next = NULL;
    t->prev = NULL;

    struct node *temp = head_s;

    if(temp==NULL)
        head_s = t;
    else
    {
        while(temp->next!=NULL)
        {
            if(temp->data==data)
            {
                flag = 1;
                break;
            }
            
            temp=temp->next;
        }

        if(flag==1)
        {
            temp->quantity += t-> quantity;
            temp->price += t->price;
        }
        else
        {
            temp->next=t;
        }
    }

    return head_s;
}

void calc_totalsale()
{
    struct node *temp = adc;
    while(temp!=NULL)
    {
        head_s = totalsales(temp->data, temp->quantity);
        temp=temp->next;
    }
}

struct node* delete(int data,struct node *head, struct node* tail)
{
    if(head==NULL)
    {
        printf("\n\t\t\t\t\t\t\tList is empty\n");
    }
    else
    {
        struct node* temp;
        if(data==head->data)
        {
            temp = head;
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            free(temp);
        }
        else if(data==tail->data)
        {
            temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            free(temp);
        }
        else
        {
            temp = head;
            while(data!=temp->data)
            {
                temp = temp->next;
            }
            (temp->prev)->next = temp->next;
            (temp->next)->prev = temp->prev;
            free(temp);
        }
    }
    return head;
}

int deleteadmin()
{
    printf("\n\t\t\t\t\tEnter serial no. of the food item which is to be deleted: ");
    int num;
    scanf("%d",&num);

    struct node* temp=ads;
    while(temp!=NULL)
    {
        if (temp->data == num)
        {
            ads = delete(num, ads, adt);
            return 1;
        }
        temp=temp->next;
    }

    return 0;
}

int deletecustomer()
{
    printf("\n\t\t\t\t\tEnter serial no. of the food item which is to be deleted: ");
    int num;
    scanf("%d",&num);

    struct node* temp=adc;
    while(temp!=NULL)
    {
        if (temp->data == num)
        {
            adc = delete(num, adc, cust);
            return 1;
        }
        temp=temp->next;
    }

    return 0;
}

void displaybill()
{
    disp(adc);
    struct node *temp = adc;
    float total_price = 0;
    while (temp!=NULL)
    {
        total_price +=temp->price;
        temp = temp->next;
        
    }

    printf("\t\t\t\t\t\t\tTotal price: %0.02f\n",total_price);
    sum+=total_price;

}

struct node* del(struct node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    else
    {
        struct node* temp = head;
        while(temp->next!=0)
        {
            temp = temp->next;
            free(temp->prev);
        }
        free(temp);
        head = NULL;
    }

    return head;
}

void admin()
{
    
    printf("ENTER PASSWORD:\n");
    char pass[10];
    scanf("%s",pass);
    if(strcmp(pass,"admin") !=0){
     printf("SORRY,INVALID PASSWORD!");
        return;
    }
    
    printf("\n\t\t\t\t\t   ----------------------------------\n");
    printf("\t\t\t\t\t\t\t    ADMIN SECTION\n");
    printf("\t\t\t\t\t   -----------------------------------\n");
    while(1)
    {
        ad_men();

        int opt;
        scanf("%d",&opt);

        if(opt==5)
            break;

        switch (opt)
        {
            case 1:
                disp(head_s);
                printf("\t\t\t\t\t\t\tTotal sales Rs.:%d\n",sum);
                break;
            case 2:

                printf("\n\t\t\t\t\t\t\tEnter serial no. of the food item: ");
                int num,flag = 0;
                char name[50]; char type[30];
                float price;
                scanf("%d",&num);

                struct node *temp = ads;

                while(temp!=NULL)
                {
                    if(temp->data==num)
                    {
                        printf("\n\t\t\t\t\t\tFood item with given serial number already exists!!\n\n");
                        flag = 1;
                        break;
                    }
                    temp = temp->next;
                }

                if(flag==1)
                    break;

                printf("\t\t\t\t\t\t\tEnter food item name: ");
                scanf("%s",name);
                printf("\t\t\t\t\t\t\tEnter price: ");
                scanf("%f",&price);
                char ntype[30];
                printf("\t\t\t\t\t\t\tEnter Type:");
                scanf("%s",&ntype);
                ads = cr_ad(ads, num, name, price,ntype);
                printf("\n\t\t\t\t\t\t\tNew food item added to the list!\n\n");
                break;
            case 3:
                if(deleteadmin())
                {
                    printf("\n\t\t\t\t\t\tITEMS IN CARTn");
                    disp(ads);
                }
                else
                    printf("\n\t\t\t\t\t\tNo such food item in cart!\n\n");

                break;
            case 4:
                printf("\n\t\t\t\t\t\t\t  ORDER MENU\n");
                disp(ads);
                break;

            default:
                printf("\n\t\t\t\t\t\tInvalid option! Enter correct choice!\n");
                break;
        }
    }
}

void customer()
{
    int flag=0,j=1;
    char ch;
    printf("\n\t\t\t\t\t   -----------------------------\n");
    printf("\t\t\t\t\t\t\t    CUSTOMER SECTION\n");
    printf("\t\t\t\t\t   -----------------------------\n");
    while(1)
    {
        cust_men();

        int opt;
        scanf("%d",&opt);

        if(opt==6)
            break;

        switch (opt)
        {
            case 1:
                disp(ads);
                printf("\n\t\t\t\t\t\tEnter number corresponding to the item you want to order: ");
                int n;
                scanf("%d",&n);
                printf("\t\t\t\t\t\tEnter quantity: ");
                int quantity;
                scanf("%d",&quantity);
                adc = cr_cus(adc, n, quantity);
                break;
            case 2:
                printf("\n\t\t\t\t\t\t\t  Items in cart\n");
                disp(adc);
                break;
            case 3:
                if(deletecustomer())
                {
                    printf("\n\t\t\t\t\t\tUPDATED CART\n");
                    disp(adc);
                }
                else
                    printf("\n\t\t\t\t\t\tFood item with given serial number doesn't exist!\n");
                break;
            case 4:
                calc_totalsale();
                printf("\n\t\t\t\t\t\t\t  FINAL AMOUNT(Bill)\n");
                displaybill();
                adc = del(adc);
                printf("\n\t\t\t\t\t\tPress any key to return to main menu:\n\t\t\t\t\t\t");
                fflush(stdin);
                ch=fgetc(stdin);
                flag=1;
                break;
                
            case 5:
            disp_type(ads);
            break;
               
                
            

            default:
                printf("\n\t\t\t\t\t\tInvalid option! Enter correct choice!\n");
                break;
        }
        if(flag==1)
            break;
    }
}

void mainmenu()
{
    printf("\n                                 ------------------------------------------------------------------\n");
    printf("                                                     AAKASH RESTAURANT MANAGEMENT SYSTEM\n");
    printf("                                 --------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t1. ADMIN LOGIN \n");
    printf("\t\t\t\t\t\t\t2. CUSTOMER VIEW\n");
    printf("\t\t\t\t\t\t\t3. Exit\n\n");
    printf("\t\t\t\t\t\t\tEnter Your Choice:");
}

int main()
{
    ads = cr_ad(ads,1,"vada",30,"South");
    ads = cr_ad(ads,2,"pongal",70,"South");
    ads = cr_ad(ads,3,"poori",80,"South");
    ads = cr_ad(ads,4,"dosa",90,"South");
    ads = cr_ad(ads,5,"idli",50,"South");
    ads= cr_ad(ads,6,"naan",110,"North");
    ads = cr_ad(ads,7,"noodles",200,"Chinese");
    ads = cr_ad(ads,8,"tikka",180,"North");
    

    while(1)
    {
        mainmenu();
        int choice;
        scanf("%d",&choice);

        if(choice==3)
        {
            printf("\n\n\t\t\t\t\t\t\tThank you!visit again!\n");
            break;
        }

        switch (choice)
        {
            case 1:
                admin();
                break;
            case 2:
                customer();
                break; 
            case 3:
                break;

            default:
                printf("\n\t\t\t\t\t\tInvalid option!\n");
                break;
        }
    }
}

