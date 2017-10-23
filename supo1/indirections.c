#include <stdio.h>

struct Integer {
	int *i;
};

void main() {
	int before = -1;
	int i = 5;
	int after = -2;
	printf(
		"before = %i (@%i)\n"
		"i = %i (@%i)\n"
		"after = %i (@%i)\n\n",
		before,
		&before,
		i,
		&i,
		after,
		&after
	);
	struct Integer s[] = {
		{ .i = &before },
		{ .i = &i },
		{ .i = &after }
	};
	struct Integer *p = s + 1;
	printf(
		"++p->i    = %i\n"
		"(before = %i, i = %i, after = %i)\n\n",
		++p->i, before, i, after
	);
	p = s + 1;
	printf(
		"p++->i    = %i\n"
		"(before = %i, i = %i, after = %i)\n\n",
		p++->i, before, i, after
	);
	p = s + 1;
	printf(
		"*p->i     = %i\n"
		"(before = %i, i = %i, after = %i)\n\n",
		*p->i, before, i, after
	);
	p = s + 1;
	printf(
		"*p->i++   = %i\n"
		"(before = %i, i = %i, after = %i)\n\n",
		*p->i++, before, i, after
	);
	p = s + 1;
	printf(
		"(*p->i)++ = %i\n"
		"(before = %i, i = %i, after = %i)\n\n",
		(*p->i)++, before, i, after
	);
	p = s + 1;
	printf(
		"*p++->i   = %i\n"
		"(before = %i, i = %i, after = %i)\n\n",
		*p++->i, before, i, after
	);
}
