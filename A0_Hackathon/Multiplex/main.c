#include <stdio.h>
#include "global.h" /* GLOBAL VAR. */
#include "functions.h" /* FUNCTION DEC. */

char line[100] = "************************************************************"; //Line = 30 stars
int counters[5] = {0,1,2,3,4};   //m- Number of counters
info screen;
movie list[50];
/* RELOAD DATA */
int movie_count;
int user_count;
int trans_count;
float gross_amount;

///
int total_seats;
int total_shows;
show dailyshows[1000*5];

/* MAIN FUNC. */
void main(){
    int choice;
    printf("%s\n---------------MULTIPLEX TICKET BOOKING SYSTEM--------------\n%s\n", line, line);
    load_data();
    do{
        printf("Enter choice:\n0-exit, 1-screen_info, 2-movie_list, 3-add_user\n4-display_users, 5-display_shows, 6-book_ticket\n7-display_earnings, 8-reserve_ticket\n>> ");
        scanf("%d", &choice);
        switch (choice){
            case 1:{
                printf("choice 1: View Screen Information.\n");
                screen_info();
                break;
            }
            case 2:{
                printf("choice 2: View Movie List.\n");
                movie_list();
                break;
            }

            case 3:{
                printf("choice 3: Add User.\n");
                add_user();
                break;
            }
            case 4:{
                printf("choice 4: Display Users.\n");
                display_users();
                break;
            }
            case 5:{
                printf("choice 5: Display Shows.\n");
                display_shows();
                break;
            }
            case 6:{
                printf("choice 6: Display Shows.\n");
                book_ticket(1);
                break;
            }
            case 7:{
                printf("choice 7: Display Earnings.\n");
                printf("Gross earnings = %.2f\n", gross_amount );
                break;
            }
            case 8:{
                printf("choice 8: Reserve Ticket.\n");
                book_ticket(2);
                break;
            }
            default:{
                printf("choice 0: Exit Booking!\n");
                printf("%s\n-------------------------COME AGAIN-------------------------\n%s\n", line, line);
                break;
            }
        }
    }while(choice);
    save_data();
}

/* FUNCTION DEFNS. */

void load_data(){

    FILE *data = fopen(stats, read);
    fscanf(data, "%d", &movie_count);
    fscanf(data, "%d", &user_count);
    fscanf(data, "%d", &trans_count);
    fscanf(data, "%f", &gross_amount);
    fclose(data);
    ///
    FILE *database = fopen(screenInfo, read);
    fscanf(database, "%d %d %d %d \n", &screen.n, &counters, &screen.x, &screen.y);
    total_seats = screen.x * screen.y;
    // printf("SCREEN INFORMATION:\nNo. of screens = %d\nNo. of counters = %d\nNo. of rows = %d\nNo. of cols = %d\n%s\n", screen.n, counters, screen.x, screen.y, line);
    fclose(database);
    ///
    database = fopen(movieList, read);
    int i = 0;
    // printf("MOVIE LIST:\nID  NAME  LANG  CERT  DUR.\n");
    while(i < movie_count){
        list[i].mov_id = i;
        fscanf(database, "%s %s %d %d", list[i].name, list[i].lang, &list[i].cert, &list[i].duration);
        // printf("%d %s %s %d %d \n", list[i].mov_id, list[i].name, list[i].lang, list[i].cert, list[i].duration);
        i++;
    }
    movie_count = i;
    fclose(database);
    /// STORE SHOW_LIST DATA

    database = fopen(showList, read);
    for(int i=0; i < movie_count*5; i++){
        fscanf(database, "%d, %d, %s, %d, %d, %d", &dailyshows[i].show_id, &dailyshows[i].scr_no, dailyshows[i].mov_name, &dailyshows[i].booked, &dailyshows[i].available, &dailyshows[i].status);
    }
    total_shows = movie_count*5;
    fclose(database);
}

void save_data(){
    FILE *data = fopen(stats, "w+");
    fprintf(data, "%d %d %d %.2f", movie_count, user_count, trans_count, gross_amount);
    fclose(data);
}

void screen_info(){
    printf("SCREEN INFORMATION:\nNo. of screens = %d\nNo. of counters = %d\nNo. of rows = %d\nNo. of cols = %d\n%s\n", screen.n, counters, screen.x, screen.y, line);
}

void movie_list(){
    int i = 0;
    printf("MOVIE LIST:\n<ID>  <NAME>  <LANG>  <CERT>  <DUR.>\n");
    while(i < movie_count){
        list[i].mov_id = i;
        printf("%d %s %s %d %d \n", list[i].mov_id, list[i].name, list[i].lang, list[i].cert, list[i].duration);
        i++;
    }
}

void update_stats(int m_count, int u_count){
    FILE *database = fopen(stats, write);
    fprintf(database, "%d %d", m_count, u_count);
    fclose(database);
}

void add_user(){
    FILE *database = fopen(userData, "a");
    user temp;
    temp.user_id = user_count;
    printf("user_count = %d \n", user_count);
    user_count += 1;
    update_stats(movie_count, user_count);
    printf("Enter: <name>, <email>, <0:customer/ 1:counter_staff> \n");
    scanf("%s %s %d", temp.name, temp.email, &temp.staff);
    fprintf(database, "%d %s %s %d\n", temp.user_id, temp.name, temp.email, temp.staff);
    fclose(database);
}

void display_users(){
    FILE *database = fopen(userData, read);
    char ch;
    while(1){
        ch = fgetc(database);
        if(ch == EOF) break;
        printf("%c", ch);
    }
    fclose(database);
}
char* search_movie(int index){
    FILE *database = fopen(movieList, read);
    int i = 0;
    static movie temp;
    while(i < movie_count){
        fscanf(database, "%s %s %d %d", temp.name, temp.lang, &temp.cert, &temp.duration);
        if(i == index)  return temp.name;
        i++;
    }
    fclose(database);
}
void display_shows(){
    int screen_count, show_count, k=0;
    int m, x, y;
    FILE *data = fopen(screenInfo, read);
    fscanf(data, "%d %d %d %d", &screen_count, &m, &x, &y);
    fclose(data);

    show_count = screen_count*5;
    show dailyshows[show_count];
    FILE *database = fopen(showList, write);
        {
            for(int i=0; i<show_count; i++){
                for(int j = 0; j < movie_count; j++){
                    dailyshows[i].show_id = i;
                    dailyshows[i].scr_no = k;
                    dailyshows[i].mov_name = search_movie(k);
                    dailyshows[i].booked = 0;
                    dailyshows[i].available = x*y;
                    dailyshows[i].status = 1;
                }
                    k++;
                    k = k % movie_count;
                    fprintf(database, "%d %d %s %d %d %d\n", dailyshows[i].show_id, dailyshows[i].scr_no, dailyshows[i].mov_name, dailyshows[i].booked, dailyshows[i].available, dailyshows[i].status);
                    printf("%d %d %s %d %d %d\n", dailyshows[i].show_id, dailyshows[i].scr_no, dailyshows[i].mov_name, dailyshows[i].booked, dailyshows[i].available, dailyshows[i].status);
            }

        }
    fclose(database);
}

int invalid_show(int show_id){

    return 0;
}

float calculate_amount(float price, ticket booked){
    if(booked)
        return gross_amount + price;
    else 
        return gross_amount - price;
}

void update_shows(int show_id, int booked, int available){
    show temp;
    FILE *database = fopen(showList, read);
    for(int i=0; i < total_shows; i++){
        fscanf(database, "%d %d %s %d %d %d", &temp.show_id, &temp.scr_no, &temp.mov_name, &temp.booked, &temp.available, &temp.status);
        if(temp.show_id == show_id){     
            // temp.booked = booked;
            // temp.available = available;
            // fprintf(database, "%d %d %s %d %d %d\n", temp.show_id, temp.scr_no, temp.mov_name, booked, available, temp.status);
            break;
        }
    }
    fclose(database);
}

void update_transactions(booking slot){
    FILE *database = fopen(transactions, add);
    fprintf(database, "%d %d %d %d %.2f %d\n", slot.trans_id, slot.show_id, slot.user_id, slot.tickets, slot.price, slot.status);
    fclose(database);
}

void book_ticket(int n){
    booking slot;
    int show_id, counter_id, seats, user_id = 0;
    float price;
    show dailyshows[movie_count*5];
    printf("Enter: <show_id> <counter_id> <Number-of-seats> \n");
    scanf("%d %d %d", &show_id, &counter_id, &seats);

    if(n == 1)  //online booking
        user_id = counter_id;
    else
        user_id = counters[counter_id];

    if(invalid_show(show_id))   printf("Invalid show.\n");
    else{
        int temp = dailyshows[show_id].booked + seats;
        if(temp < total_seats){
            price = seats * 200;
            gross_amount = calculate_amount(price, 1);  //1-booked
            // dailyshows[show_id].booked = temp;
            int booked = temp;
            // dailyshows[show_id].available = total_seats - dailyshows[show_id].booked;
            int available = total_seats - booked;
// updating transaction status:
            slot.trans_id = trans_count++;
            slot.show_id = show_id;
            slot.user_id = user_id;
            slot.tickets = seats;
            slot.price = price;
            slot.status = BOOKED;
            update_transactions(slot);
            // update_shows(show_id, booked, available);
        }
        else{
            printf("Requested seats not available! Try next slot.\n");
        }
    }
}