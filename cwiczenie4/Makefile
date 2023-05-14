.SUFFIXES: .c .o .x .h
DIR = $(notdir $(CURDIR))
SYSNAME = $(shell uname -s)
NAME1 = main
EXEC1  = $(NAME1).x  
OBJS1  = $(NAME1).o
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
all: $(EXEC1) 


#Komplilacja


$(EXEC1): $(OBJS1) $(LIBS) 
	$(LD) -o $@ $(LFLAGS) $^


#Uruchamianie
.PHONY: run1
run1: $(EXEC1)
	./$(EXEC1)


###############################################################################
# Sprzataczka (tez "phony target")
###############################################################################
.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}
# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
