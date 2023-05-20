.SUFFIXES: .cpp .o .x .h
DIR = $(notdir $(CURDIR))
SYSNAME = $(shell uname -s)
NAME1 = main
NAME2 = prod
NAME3 = kons
EXEC1  = $(NAME1).x 
EXEC2  = $(NAME2)
EXEC3  = $(NAME3)
OBJS1  = $(NAME1).o
OBJS2  = $(NAME2).o
OBJS3  = $(NAME3).o
LIBS  = 
HEADS = 
CFLAGS = -Wall -std=c++17 -pedantic 
LFLAGS = -Wall -std=c++17 -pedantic
LDLIBS = -lm
CO = g++
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

$(EXEC3): $(OBJS3) $(LIBS)
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC2): $(OBJS2) $(LIBS) 
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC1): $(OBJS1) $(LIBS) 
	$(LD) -o $@ $(LFLAGS) $^


#Uruchamianie
.PHONY: help
help: $(EXEC2) $(EXEC3)


.PHONY: run_main
run_main: $(EXEC1)
	./$(EXEC1)


###############################################################################
# Sprzataczka (tez "phony target")
###############################################################################
.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out *.out $(EXEC2) $(EXEC3); rm -rf ${LIB_DIR}; clear;
# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
