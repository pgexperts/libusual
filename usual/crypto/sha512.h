/*
 * SHA2-512 implementation based on FIPS180-2.
 *
 * Copyright (c) 2009  Marko Kreen
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _USUAL_CRYPTO_SHA512_H_
#define _USUAL_CRYPTO_SHA512_H_

#include <usual/base.h>

#define SHA384_BLOCK_SIZE (16*8)
#define SHA512_BLOCK_SIZE (16*8)

#define SHA384_DIGEST_LENGTH (384/8)
#define SHA512_DIGEST_LENGTH (512/8)

struct sha512_ctx {
	union {
		uint64_t words[16];
		uint8_t raw[16 * 8];
	} buf;
	uint64_t state[8];
	uint64_t nbytes;
};

void sha512_reset(struct sha512_ctx *ctx);
void sha512_update(struct sha512_ctx *ctx, const void *data, unsigned int len);
void sha512_final(struct sha512_ctx *ctx, uint8_t *dst);

void sha384_reset(struct sha512_ctx *ctx);
void sha384_update(struct sha512_ctx *ctx, const void *data, unsigned int len);
void sha384_final(struct sha512_ctx *ctx, uint8_t *dst);

#endif
