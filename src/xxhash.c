
/*
 * xxHash - Extremely Fast Hash algorithm
 * Copyright (C) 2012-2021 Yann Collet
 *
 * BSD 2-Clause License (https://www.opensource.org/licenses/bsd-license.php)
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above
 *      copyright notice, this list of conditions and the following disclaimer
 *      in the documentation and/or other materials provided with the
 *      distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * You can contact the author at:
 *   - xxHash homepage: https://www.xxhash.com
 *   - xxHash source repository: https://github.com/Cyan4973/xxHash
 */


/*
 * xxhash.c instantiates functions defined in xxhash.h
 */
#define XXH_INLINE_ALL  /* allow xxHash to be inlined */
#define XXH_STATIC_LINKING_ONLY   /* access advanced declarations */
#define XXH_IMPLEMENTATION   /* access definitions */

#include "xxhash.h"



typedef struct xxhash_ctx{
    XXH3_state_t* xxh3State;
}xxhash_ctx;



void hash_init_xxhash(void *ctx){
    ((xxhash_ctx*)ctx)->xxh3State = XXH_INLINE_XXH3_createState();
    XXH_INLINE_XXH3_128bits_reset(((xxhash_ctx*)ctx)->xxh3State);

}
void hash_update_xxhash(void *ctx, const unsigned char* buff, size_t len){
    XXH_INLINE_XXH3_128bits_update(((xxhash_ctx*)ctx)->xxh3State, buff, len);
}

void hash_final_xxhash(void *ctx,unsigned char* digest){
    XXH_INLINE_XXH128_canonicalFromHash((XXH128_canonical_t*)digest, XXH_INLINE_XXH3_128bits_digest(((xxhash_ctx*)ctx)->xxh3State));
    XXH_INLINE_XXH3_freeState(((xxhash_ctx*)ctx)->xxh3State);

}
