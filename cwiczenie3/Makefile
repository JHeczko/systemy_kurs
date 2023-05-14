.SUFFIXES: .c .o .x .h
DIR = $(notdir $(CURDIR))
SYSNAME = $(shell uname -s)
NAME1 = z1
NAME2 = z2
NAME3 = z3main
NAME4 = z3
EXEC1  = $(NAME1).x  
EXEC2  = $(NAME2).x
EXEC3  = $(NAME3).x
EXEC4  = $(NAME4).x
OBJS1  = $(NAME1).o
OBJS2  = $(NAME2).o 
OBJS3  = $(NAME3).o
OBJS4  = $(NAME4).o
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

$(EXEC4): $(OBJS4) $(LIBS) 
	$(LD) -o $@ $(LFLAGS) $^



#Uruchamianie
.PHONY: run1
run1: $(EXEC1)
	./$(EXEC1)
.PHONY: run2
run2: $(EXEC2) $(EXEC1)
	./$(EXEC2) ./$(EXEC1)
.PHONY: run3
run3: $(EXEC3) $(EXEC4)
	./$(EXEC3) ./$(EXEC4)



###############################################################################
# Sprzataczka (tez "phony target")
###############################################################################
.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}
# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
