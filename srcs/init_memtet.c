#include "fillit.h"

void	init_memtet(t_memtet *memtet)
{
	short	i;

	i = 0;
	memtet->c = 2;
	memtet->nb_tet = 0;
	while (i < 26)
	{
		memtet->ltet[i].crds[0].x = 0;
		memtet->ltet[i].crds[0].y = 0;
		memtet->ltet[i].crds[1].x = 0;
		memtet->ltet[i].crds[1].y = 0;
		memtet->ltet[i].crds[2].x = 0;
		memtet->ltet[i].crds[2].y = 0;
		memtet->ltet[i].crds[3].x = 0;
		memtet->ltet[i].crds[3].y = 0;
		memtet->ltet[i].x = 0;
		memtet->ltet[i].y = 0;
		memtet->ltet[i].l = 0;
		memtet->ltet[i].h = 0;
		memtet->ltet[i].i_last = 0;
		i++;
	}
}
