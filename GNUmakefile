PREFIX?=	/usr/local
BINDIR?=	$(PREFIX)/bin
MANDIR?=	$(PREFIX)/man
DOCDIR?=	$(PREFIX)/share/doc

CC?=		gcc

UNAME:=		$(shell sh -c 'uname 2> /dev/null || echo undefined')

CFLAGS+=	-Iinclude -DFKEYS -DREGEX -DXKEYS

LDADD+=		-lcurses -lcrypto -lrt

SRCS=		autoexec.c basic.c bell.c buffer.c cinfo.c cmode.c cscope.c \
		dir.c dired.c display.c echo.c extend.c file.c fileio.c \
		funmap.c grep.c help.c kbd.c keymap.c line.c macro.c main.c \
		match.c modes.c paragraph.c random.c region.c re_search.c \
		search.c spawn.c tags.c theo.c tty.c ttyio.c ttykbd.c undo.c \
		version.c window.c word.c yank.c

ifeq ($(UNAME), Linux)
CFLAGS+=	-D_GNU_SOURCE
SRCS+=		compat/arc4random.c compat/arc4random_uniform.c \
		compat/explicit_bzero.c compat/fgetln.c compat/fparseln.c \
		compat/getentropy_linux.c compat/strlcat.c compat/strlcpy.c \
		compat/strtonum.c
endif

OBJS=		$(SRCS:.c=.o)

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
