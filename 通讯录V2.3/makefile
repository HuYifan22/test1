TARGET ?= run
OBJS:=main.o mylib.o menu.o
CC:= cc
CFLAGS:= -c -o

$(TARGET):$(OBJS)
	$(CC) $(OBJS) -o $(TARGET)
%.o:%.c
	$(CC) $< $(CFLAGS) $@
clean:
	rm $(OBJS) $(TARGET)