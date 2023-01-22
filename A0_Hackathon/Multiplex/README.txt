HEADER FILES:

1) "global.h" - contains user-defined datatype declarations.

2) "functions.h" - contains user-defined function declarations.

********************************************************************************************************

DATABASE FILES <FIELDS>: 

MAIN FUNCTION - "main.c"

1) stats.txt - contains static data
<movie_count>, <user_count>, <trans_count>

2) movie_list.txt - contains movie movie_list
<movie_name>, <language>, <certification>, <duration>

3) screen_info.txt - contains screen info
<no_of_screens>, <no_of_counters>, <no_of_rows>, <no_of_columns>

4) show_list.txt - contains list of shows from all no_of_screens
<show_id>, <movie_index>, <movie_name>, <seats_booked>, <seats_available>, <screening_status> 

5) user_data.txt - contains user info
<user_id>, <user_name>, <user_email>, <staff/ customer>

6) transactions.txt - contains booking transactions
<transaction_id>, <show_id>, <counter_id>, <no_of_seats>, <total_price>, <booked/cancelled_status>