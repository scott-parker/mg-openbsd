size_t		 strlcpy(char *, const char *, size_t);
size_t		 strlcat(char *, const char *, size_t);
long long	 strtonum(const char *, long long, long long, const char **);
char		*fgetln(FILE *, size_t *);
char		*fparseln(FILE *, size_t *, size_t *, const char [3], int);

#define FPARSELN_UNESCESC	0x01
#define FPARSELN_UNESCCONT	0x02
#define FPARSELN_UNESCCOMM	0x04
#define FPARSELN_UNESCREST	0x08
#define FPARSELN_UNESCALL	0x0f

#define st_mtimespec		st_mtim

#ifndef __dead
#define __dead		__attribute__((__noreturn__))
#endif

#ifndef TAILQ_END
#define	TAILQ_END(head)	NULL
#endif

#ifndef TAILQ_FOREACH_SAFE
#define TAILQ_FOREACH_SAFE(var, head, field, tvar)	\
	for ((var) = TAILQ_FIRST(head);			\
	    (var) != TAILQ_END(head) &&			\
	    ((tvar) = TAILQ_NEXT(var, field), 1);	\
	    (var) = (tvar))
#endif
