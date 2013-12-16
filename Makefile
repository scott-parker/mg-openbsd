PREFIX?= /usr/local
BINDIR?= $(PREFIX)/bin
MANDIR?= $(PREFIX)/man
DOCDIR?= $(PREFIX)/share/doc

CC?= gcc
CFLAGS+= -O2 -Wall -D_GNU_SOURCE -DFKEYS -DREGEX -DXKEYS
LDADD+= -lcurses

SRCS= $(shell ls *.c)
OBJS= $(SRCS:.c=.o)

all: mg

mg: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $+ $(LDADD)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $<

install: all
	install -m 755 -d $(DESTDIR)$(BINDIR)
	install -m 755 -d $(DESTDIR)$(MANDIR)/man1
	install -m 755 -d $(DESTDIR)$(DOCDIR)/mg
	install -m 755 mg $(DESTDIR)$(BINDIR)
	install -m 644 mg.1 $(DESTDIR)$(MANDIR)/man1
	install -m 644 tutorial $(DESTDIR)$(DOCDIR)/mg
	install -m 644 README $(DESTDIR)$(DOCDIR)/mg

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/mg
	rm -f $(DESTDIR)$(MANDIR)/man1/mg.1
	rm -rf $(DESTDIR)$(DOCDIR)/mg

clean:
	rm -f mg $(OBJS)

.PHONY: all install clean
