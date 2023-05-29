.SUFFIXES: .cpp .o .x .h
DIR = $(notdir $(CURDIR))
SYSNAME = $(shell uname -s)
NAME1 = serwer
NAME2 = klient
EXEC1  = $(NAME1).x 
EXEC2  = $(NAME2).x
OBJS1  = $(NAME1).o
OBJS2  = $(NAME2).o
LIBS  = 
HEADS = 
CFLAGS = -Wall -std=c++17 -pedantic -lrt
LFLAGS = -Wall -std=c++17 -pedantic -lrt
LDLIBS = -lm -lrt
CO = g++
LD = $(CO)
AR = ar
ARFLAGS = rsv

%.o: %.c %.h
	$(CO) $(CFLAGS) -c -lrt $<

%.o: %.c
	$(CO) $(CFLAGS) -c -lrt $<

#all
.PHONY: all
all: $(EXEC1) $(EXEC2)


#Komplilacja


$(EXEC2): $(OBJS2) $(LIBS) 
	$(LD) -lrt -o $@ $(LFLAGS) $^

$(EXEC1): $(OBJS1) $(LIBS) 
	$(LD) -lrt -o $@ $(LFLAGS) $^


#Uruchamianie
.PHONY: help
help: $(EXEC1) $(EXEC2)


.PHONY: serwer
serwer: $(EXEC1) 
	./$(EXEC1)

.PHONY: klient
klient: $(EXEC2)
	./$(EXEC2)

###############################################################################
# Sprzataczka (tez "phony target")
###############################################################################
.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out *.out; rm -rf ${LIB_DIR}; clear;
# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
