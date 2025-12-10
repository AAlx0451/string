#include <stddef.h>

extern const char * const sys_errlist[];
extern const int sys_nerr;

#define UPREFIX "Unknown error"

#define EBUFSIZE (sizeof(UPREFIX) + 2 + 20)

static void
__errstr(int num, const char *uprefix, char *buf, size_t len)
{
    char tmp_num_buf[22];
    char *t;
    unsigned int uerr;

    t = tmp_num_buf + sizeof(tmp_num_buf);
    *--t = '\0';
    uerr = (num >= 0) ? num : -num;
    do {
        *--t = "0123456789"[uerr % 10];
    } while (uerr /= 10);
    if (num < 0) {
        *--t = '-';
    }

    char *p = buf;
    size_t remaining = len;
    while (remaining > 1 && *uprefix) {
        *p++ = *uprefix++;
        remaining--;
    }

    if (remaining > 2) {
        *p++ = ':';
        *p++ = ' ';
        remaining -= 2;
    }
    
    while (remaining > 1 && *t) {
        *p++ = *t++;
        remaining--;
    }

    *p = '\0';
}

char *
strerror(int num)
{
    static char ebuf[256];

    if (num >= 0 && num < sys_nerr) {
        const char *error_msg = sys_errlist[num];
        char *dst = ebuf;
        size_t i = 0;
        
        while (i < sizeof(ebuf) - 1 && *error_msg) {
            *dst++ = *error_msg++;
            i++;
        }
        *dst = '\0';
    } else {
        __errstr(num, UPREFIX, ebuf, sizeof(ebuf));
    }
    return (ebuf);
}
