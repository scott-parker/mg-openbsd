CFLAGS+=	-O2 -Wall -Wno-unused-but-set-variable \
		-D_GNU_SOURCE -DFKEYS -DREGEX -DXKEYS
LDADD+=		-lcurses

PREFIX?=	/usr/local
BINDIR?=	$(PREFIX)/bin
MANDIR?=	$(PREFIX)/man
DOCDIR?=	$(PREFIX)/share/doc

SRCS=	$(shell ls *.c)
OBJS=	$(SRCS:.c=.o)
DEPS=	$(addsuffix .depend, $(OBJS))

CC?=	gcc

all: mg

mg: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $+ $(LDADD)

%.o: %.c
	@echo "Generating $@.depend"
	@$(CC) -MM $(CPPFLAGS) $(CFLAGS) $< | \
	sed 's,^.*\.o[ :]*,$@ $@.depend : ,g' > $@.depend
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $<

install: all
	install -m 755 -d $(DESTDIR)$(BINDIR)
	install -m 755 -d $(DESTDIR)$(MANDIR)/man1
	install -m 755 -d $(DESTDIR)$(DOCDIR)/mg
	install -m 755 mg $(DESTDIR)$(BINDIR)
	install -m 644 mg.1 $(DESTDIR)$(MANDIR)/man1/mg.1
	install -m 644 tutorial $(DESTDIR)$(DOCDIR)/mg/tutorial
	install -m 644 README $(DESTDIR)$(DOCDIR)/mg/README

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/mg
	rm -f $(DESTDIR)$(MANDIR)/man1/mg.1
	rm -rf $(DESTDIR)$(DOCDIR)/mg

clean:
	rm -f mg $(OBJS) $(DEPS)

-include $(DEPS)

.PHONY: all install clean
