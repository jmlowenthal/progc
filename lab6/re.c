#include <stdlib.h>
#include <stdio.h>
#include "re.h"

arena_t create_arena(int size) { 
	arena_t a = malloc(sizeof(struct arena));
	a->elements = malloc(size * sizeof(Regexp));
	a->current = 0;
	a->size = size;
	return a;
}

void arena_free(arena_t a) { 
	free(a->elements);
	free(a);
}

Regexp *re_alloc(arena_t a) { 
	if (a->current < a->size) {
		return a->elements + a->current++;
	}
	else {
		return NULL;
	}
}

Regexp *re_chr(arena_t a, char c) { 
	Regexp *exp = re_alloc(a);
	if (NULL == exp) {
		return NULL;
	}
	else {
		exp->type = CHR;
		exp->data.chr = c;
		return exp;
	}
}

Regexp *re_alt(arena_t a, Regexp *r1, Regexp *r2) { 
	Regexp *exp = re_alloc(a);
	if (NULL == exp) {
		return NULL;
	}
	else {
		exp->type = ALT;
		exp->data.pair.fst = r1;
		exp->data.pair.snd = r2;
		return exp;
	}
}

Regexp *re_seq(arena_t a, Regexp *r1, Regexp *r2) { 
	Regexp *exp = re_alloc(a);
	if (NULL == exp) {
		return NULL;
	}
	else {
		exp->type = SEQ;
		exp->data.pair.fst = r1;
		exp->data.pair.snd = r2;
		return exp;
	}
}

int re_match(Regexp *r, char *s, int i) { 
	switch (r->type) {
		case CHR:
			if (s[i] == r->data.chr) {
				return i + 1;
			}
			else {
				return -1;
			}
		case SEQ: {
			int j = re_match(r->data.pair.fst, s, i);
			if (0 > j) {
				return -1;
			}
			else {
				return re_match(r->data.pair.snd, s, j);
			}
		}
		case ALT: {
			int j = re_match(r->data.pair.fst, s, i);
			if (0 <= j) {
				return j;
			}
			else {
				return re_match(r->data.pair.snd, s, i);
			}
		}
	}
	return -1;
}



void re_print(Regexp *r) { 
  if (r != NULL) { 
    switch (r->type) {
    case CHR: 
      printf("%c", r->data.chr);
      break;
    case SEQ:
      if (r->data.pair.fst->type == ALT) { 
	printf("(");
	re_print(r->data.pair.fst);
	printf(")");
      } else {
	re_print(r->data.pair.fst);
      }
      if (r->data.pair.snd->type == ALT) { 
	printf("(");
	re_print(r->data.pair.snd);
	printf(")");
      } else {
	re_print(r->data.pair.snd);
      }
      break;
    case ALT:
      re_print(r->data.pair.fst);
      printf("+");
      re_print(r->data.pair.snd);
      break;
    }
  } else { 
    printf("NULL");
  }
}    


      
  
