CC = gcc
LDFLAGS = -L. -lm

TARGET = 0316
OBJS = 0316.o libm.a

.SUFFIEXS: .c .o
.c.o:
	$(CC) -c $<

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

0316.o:	0316.c

i_p.o:	i_p.c

r_p.o:	r_p.c

libm.a:	i_p.o r_p.o
	ar ruv libm.a i_p.o r_p.o

clean:
	rm -f core $(TARGET) $(OBJS)

