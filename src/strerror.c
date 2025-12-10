#include <stddef.h>

static const char *const g_error_lookup_table[] = {
        "Undefined error: 0",                        /*  0 - ENOERROR */
        "Operation not permitted",                /*  1 - EPERM */
        "No such file or directory",                /*  2 - ENOENT */
        "No such process",                        /*  3 - ESRCH */
        "Interrupted system call",                /*  4 - EINTR */
        "Input/output error",                        /*  5 - EIO */
        "Device not configured",                /*  6 - ENXIO */
        "Argument list too long",                /*  7 - E2BIG */
        "Exec format error",                        /*  8 - ENOEXEC */
        "Bad file descriptor",                        /*  9 - EBADF */
        "No child processes",                        /* 10 - ECHILD */
        "Resource deadlock avoided",                /* 11 - EDEADLK */
        "Cannot allocate memory",                /* 12 - ENOMEM */
        "Permission denied",                        /* 13 - EACCES */
        "Bad address",                                /* 14 - EFAULT */
        "Block device required",                /* 15 - ENOTBLK */
        "Resource busy",                        /* 16 - EBUSY */
        "File exists",                                /* 17 - EEXIST */
        "Cross-device link",                        /* 18 - EXDEV */
        "Operation not supported by device",        /* 19 - ENODEV */
        "Not a directory",                        /* 20 - ENOTDIR */
        "Is a directory",                        /* 21 - EISDIR */
        "Invalid argument",                        /* 22 - EINVAL */
        "Too many open files in system",        /* 23 - ENFILE */
        "Too many open files",                        /* 24 - EMFILE */
        "Inappropriate ioctl for device",        /* 25 - ENOTTY */
        "Text file busy",                        /* 26 - ETXTBSY */
        "File too large",                        /* 27 - EFBIG */
        "No space left on device",                /* 28 - ENOSPC */
        "Illegal seek",                                /* 29 - ESPIPE */
        "Read-only file system",                /* 30 - EROFS */
        "Too many links",                        /* 31 - EMLINK */
        "Broken pipe",                                /* 32 - EPIPE */

/* math software */
        "Numerical argument out of domain",        /* 33 - EDOM */
        "Result too large",                        /* 34 - ERANGE */

/* non-blocking and interrupt i/o */
        "Resource temporarily unavailable",        /* 35 - EAGAIN */
                                                /* 35 - EWOULDBLOCK */
        "Operation now in progress",                /* 36 - EINPROGRESS */
        "Operation already in progress",        /* 37 - EALREADY */

/* ipc/network software -- argument errors */
        "Socket operation on non-socket",        /* 38 - ENOTSOCK */
        "Destination address required",                /* 39 - EDESTADDRREQ */
        "Message too long",                        /* 40 - EMSGSIZE */
        "Protocol wrong type for socket",        /* 41 - EPROTOTYPE */
        "Protocol not available",                /* 42 - ENOPROTOOPT */
        "Protocol not supported",                /* 43 - EPROTONOSUPPORT */
        "Socket type not supported",                /* 44 - ESOCKTNOSUPPORT */
        "Operation not supported",                /* 45 - ENOTSUP */
        "Protocol family not supported",        /* 46 - EPFNOSUPPORT */
                                                /* 47 - EAFNOSUPPORT */
        "Address family not supported by protocol family",
        "Address already in use",                /* 48 - EADDRINUSE */
        "Can't assign requested address",        /* 49 - EADDRNOTAVAIL */

/* ipc/network software -- operational errors */
        "Network is down",                        /* 50 - ENETDOWN */
        "Network is unreachable",                /* 51 - ENETUNREACH */
        "Network dropped connection on reset",        /* 52 - ENETRESET */
        "Software caused connection abort",        /* 53 - ECONNABORTED */
        "Connection reset by peer",                /* 54 - ECONNRESET */
        "No buffer space available",                /* 55 - ENOBUFS */
        "Socket is already connected",                /* 56 - EISCONN */
        "Socket is not connected",                /* 57 - ENOTCONN */
        "Can't send after socket shutdown",        /* 58 - ESHUTDOWN */
        "Too many references: can't splice",        /* 59 - ETOOMANYREFS */
        "Operation timed out",                        /* 60 - ETIMEDOUT */
        "Connection refused",                        /* 61 - ECONNREFUSED */

        "Too many levels of symbolic links",        /* 62 - ELOOP */
        "File name too long",                        /* 63 - ENAMETOOLONG */

/* should be rearranged */
        "Host is down",                                /* 64 - EHOSTDOWN */
        "No route to host",                        /* 65 - EHOSTUNREACH */
        "Directory not empty",                        /* 66 - ENOTEMPTY */

/* quotas & mush */
        "Too many processes",                        /* 67 - EPROCLIM */
        "Too many users",                        /* 68 - EUSERS */
        "Disc quota exceeded",                        /* 69 - EDQUOT */

/* Network File System */
        "Stale NFS file handle",                /* 70 - ESTALE */
        "Too many levels of remote in path",        /* 71 - EREMOTE */
        "RPC struct is bad",                        /* 72 - EBADRPC */
        "RPC version wrong",                        /* 73 - ERPCMISMATCH */
        "RPC prog. not avail",                        /* 74 - EPROGUNAVAIL */
        "Program version wrong",                /* 75 - EPROGMISMATCH */
        "Bad procedure for program",                /* 76 - EPROCUNAVAIL */

        "No locks available",                        /* 77 - ENOLCK */
        "Function not implemented",                /* 78 - ENOSYS */
        "Inappropriate file type or format",        /* 79 - EFTYPE */
        "Authentication error",                        /* 80 - EAUTH */
        "Need authenticator",                        /* 81 - ENEEDAUTH */

        "Device power is off",                        /* 82 - EPWROFF */
        "Device error",                         /* 83 - EDEVERR */
        "Value too large to be stored in data type",        /* 84 - EOVERFLOW */

/* program loading errors */
        "Bad executable (or shared library)",   /* 85 - EBADEXEC */
        "Bad CPU type in executable",                /* 86 - EBADARCH */
        "Shared library version mismatch",        /* 87 - ESHLIBVERS */
        "Malformed Mach-o file",                /* 88 - EBADMACHO */
        "Operation canceled",                        /* 89 - ECANCELED */
        "Identifier removed",                        /* 90 - EIDRM */
        "No message of desired type",                /* 91 - ENOMSG */
        "Illegal byte sequence",                /* 92 - EILSEQ */
        "Attribute not found",                        /* 93 - ENOATTR */
        "Bad message",                                /* 94 - EBADMSG */
        "EMULTIHOP (Reserved)",                        /* 95 - EMULTIHOP */
        "No message available on STREAM",        /* 96 - ENODATA */
        "ENOLINK (Reserved)",                        /* 97 - ENOLINK */
        "No STREAM resources",                        /* 98 - ENOSR */
        "Not a STREAM",                                /* 99 - ENOSTR */
        "Protocol error",                        /* 100 - EPROTO */
        "STREAM ioctl timeout",                        /* 101 - ETIME */
        "Operation not supported on socket",        /* 102 - EOPNOTSUPP */
        "Policy not found",                        /* 103 - ENOPOLICY */
        "State not recoverable",                /* 104 - ENOTRECOVERABLE */
        "Previous owner died",                        /* 105 - EOWNERDEAD */

        "Interface output queue is full",        /* 106 - EQFULL */
};

static const int TOTAL_ERRORS = sizeof(g_error_lookup_table) / sizeof(g_error_lookup_table[0]);

static size_t 
copy_string_safe(char *dest, const char *src, size_t max_chars) 
{
    size_t count = 0;
    while (*src && count < max_chars - 1) {
        *dest++ = *src++;
        count++;
    }
    *dest = '\0';
    return count;
}

static void
generate_unknown_error_msg(int code, char *buffer, size_t buffer_len)
{
    const char *prefix_str = "Unknown error";
    char number_buf[32];
    unsigned int abs_val;
    int digit_idx = sizeof(number_buf) - 1;
    size_t current_len;
    
    number_buf[digit_idx] = '\0';
    digit_idx--;

    if (code >= 0) {
        abs_val = (unsigned int)code;
    } else {
        abs_val = (unsigned int)(-code);
    }

    if (abs_val == 0) {
        number_buf[digit_idx--] = '0';
    } else {
        while (abs_val > 0) {
            number_buf[digit_idx--] = (abs_val % 10) + '0';
            abs_val /= 10;
        }
    }

    if (code < 0) {
        number_buf[digit_idx--] = '-';
    }

    char *number_start = &number_buf[digit_idx + 1];

    current_len = copy_string_safe(buffer, prefix_str, buffer_len);

    if (current_len + 2 < buffer_len) {
        buffer[current_len++] = ':';
        buffer[current_len++] = ' ';
        buffer[current_len] = '\0';
    }

    copy_string_safe(buffer + current_len, number_start, buffer_len - current_len);
}

char *
strerror(int err_code)
{
    static char s_result_buffer[256];

    if (err_code >= 0 && err_code < TOTAL_ERRORS) {
        copy_string_safe(s_result_buffer, g_error_lookup_table[err_code], sizeof(s_result_buffer));
    } else {
        generate_unknown_error_msg(err_code, s_result_buffer, sizeof(s_result_buffer));
    }

    return s_result_buffer;
}
