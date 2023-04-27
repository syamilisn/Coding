clean:
	rm -rd *.out
conn:
	gcc connect.c -o conn.out  `mysql_config --cflags --libs`
	./conn.out

p1:
	gcc p1_clientvers.c -o p1.out `mysql_config --cflags --libs`
	./p1.out

