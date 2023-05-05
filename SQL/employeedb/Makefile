manage:
	gcc manage.c -o manageA.out `mysql_config --cflags --libs`
emp:
	gcc employeedb.c -o emp.out `mysql_config --cflags --libs` -w
	./emp.out
a:
	gcc clientA.c -o clientA `mysql_config --cflags --libs` -w
	./clientA

b:
	gcc clientB.c -o clientB `mysql_config --cflags --libs` -w 
	./clientB
