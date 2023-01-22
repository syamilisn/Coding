/* USER-DEFINED DATA STRUCTURES */

typedef char filename[20];  //string to store file names
typedef char mode[2];  //mode character
// typedef enum Certificate{
//     U = 1, UA, A, S
// }certify;

typedef enum Booking_status{
    CANCELLED, BOOKED   //cancelled-0, booked-1
}ticket;

typedef struct Screen{
    int n;  //  screen no.
    int x;  //  #oRows
    int y;  //  #oCols
}info;

typedef struct Movie{
    int mov_id; //  mov-ID (Auto-generated)
    char name[100];
    char lang[20];
    int cert;
    int duration;   //  time in minutes
}movie;

typedef struct Show{
    int show_id; //  show-ID (Auto-generated) (auto-incrementing counter) PRIMKEY
    int scr_no;  // show is airing on which screen (depC->screen number)
    char *mov_name;  //  movie name (depC->movie index)
    int booked; //  booked seats
    int available;  //  seats available for booking
    int status; // 1-upcoming, 2-now_showing, 3-ended, 4-cancelled
}show;

typedef struct User{
    int user_id;    //  auto-generated  PRIMKEY (whether user is CUSTOMER/ COUNTER_STAFF)
    char name[50];
    char email[25];
    int staff;  //0 - customer, 1 - staff (then, name and email is dummy value/ theatre name)
}user;

// struct Counter{
//     int cntr_id;    // {1,2,3,4,5}
//     i
// }counter[5];

// static int counter[5];

typedef struct Booking{
    int trans_id;   //    auto-generated  PRIMKEY
    int show_id;    
    int user_id; //  maps to "user.user_id" or "counter_id" (index) 
    int tickets;    //  #oTickets
    float price;
    ticket status;  // whether booked or cancelled 
}booking;


/* FILES */

filename  screenInfo = "screen_info.txt";
filename  movieList = "movie_list.txt"; 
filename userData = "user_data.txt";
filename stats = "stats.txt";
filename showList = "show_list.txt";
filename transactions = "transactions.txt";

/* FILE MODES */

mode read = "r+";
mode write = "w";
mode add = "a+";