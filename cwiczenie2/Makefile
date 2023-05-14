.SUFFIXES: .c .o .x .h
DIR = $(notdir $(CURDIR))
SYSNAME = $(shell uname -s)
NAME1 = main
NAME2 = process
EXEC1  = $(NAME1).x  
EXEC2  = $(NAME2).x
OBJS1  = $(NAME1).o
OBJS2  = $(NAME2).o 
LIBS  = 
HEADS = 
CFLAGS = -Wall -std=c99 -pedantic -O -fPIC
LFLAGS = -Wall -std=c99 -pedantic -O
LDLIBS = -lm
CO = gcc
LD = $(CO)
AR = ar
ARFLAGS = rsv

%.o: %.c %.h
	$(CO) $(CFLAGS) -c $<

%.o: %.c
	$(CO) $(CFLAGS) -c $<

#all
.PHONY: all
all: $(EXEC1) $(EXEC2) 


#Komplilacja

$(EXEC2): $(OBJS2) $(LIBS) 
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC1): $(OBJS1) $(LIBS) 
	$(LD) -o $@ $(LFLAGS) $^


#Uruchamianie
.PHONY: run1
run1: $(EXEC1) $(EXEC2)
	./$(EXEC1) ./$(EXEC2)


###############################################################################
# Sprzataczka (tez "phony target")
###############################################################################
.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}
# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
