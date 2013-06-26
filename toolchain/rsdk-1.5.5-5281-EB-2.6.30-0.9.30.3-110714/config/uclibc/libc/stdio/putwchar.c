/* Copyright (C) 2004       Manuel Novoa III    <mjn3@codepoet.org>
 *
 * GNU Library General Public License (LGPL) version 2 or later.
 *
 * Dedicated to Toni.  See uClibc/DEDICATION.mjn3 for details.
 */

#include "_stdio.h"

#ifdef __DO_UNLOCKED

libc_hidden_proto(fputwc_unlocked)

wint_t putwchar_unlocked(wchar_t wc)
{
	return fputwc_unlocked(wc, stdout);
}

#ifndef __UCLIBC_HAS_THREADS__
strong_alias(putwchar_unlocked,putwchar)
#endif

#elif defined __UCLIBC_HAS_THREADS__

libc_hidden_proto(__fputc_unlocked)
/* psm: should this be fputwc? */
libc_hidden_proto(fputc)

wint_t putwchar(wchar_t wc)
{
	return fputc(wc, stdout);
}

#endif