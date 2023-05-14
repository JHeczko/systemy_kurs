.SUFFIXES: .c .o .x .h
DIR = $(notdir $(CURDIR))
SYSNAME = $(shell uname -s)
NAME1 = p
NAME2 = k
NAME3 = potok
EXEC1  = $(NAME1).x  
EXEC2  = $(NAME2).x
EXEC3 = $(NAME3).x
OBJS1  = $(NAME1).o
OBJS2  = $(NAME2).o
OBJS3 = $(NAME3).o 
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
all: $(EXEC1) $(EXEC2) $(EXEC3)


#Komplilacja

$(EXEC1): $(OBJS1) $(LIBS) 
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC2): $(OBJS2) $(LIBS) 
	$(LD) -o $@ $(LFLAGS) $^


$(EXEC3): $(OBJS3) $(LIBS)
	$(LD) -o $@ $(LFLAGS) $^


#Uruchamianie
.PHONY: runP
runP: $(EXEC1)
	./$(EXEC1) 

.PHONY: runK
runK: $(EXEC2)
	./$(EXEC2)

.PHONY: potok
potok: $(EXEC3)
	./$(EXEC3)


###############################################################################
# Sprzataczka (tez "phony target")
###############################################################################
.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}
# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
