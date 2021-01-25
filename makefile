PROG = covid_utility
CC = g++
CPPFLAGS  = -std=c++17
OBJS = main.o Country.o

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o:
	$(CC) $(CPPFLAGS) -c main.cpp

Country.o: Country.h
	$(CC) $(CPPFLAGS) -c Country.cpp

clean:
	rm -f core $(PROG) $(OBJS)