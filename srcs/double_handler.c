#include "fillit.h"


char	is_same(t_tetriminos tet1, t_tetriminos tet2)
{
	char nb_diff;

	nb_diff = 0;
	nb_diff += (tet1.crds[0].x != tet2.crds[0].x);
	nb_diff += (tet1.crds[0].y != tet2.crds[0].y);
	nb_diff += (tet1.crds[1].x != tet2.crds[1].x);
	nb_diff += (tet1.crds[1].y != tet2.crds[1].y);
	nb_diff += (tet1.crds[2].x != tet2.crds[2].x);
	nb_diff += (tet1.crds[2].y != tet2.crds[2].y);
	nb_diff += (tet1.crds[3].x != tet2.crds[3].x);
	nb_diff += (tet1.crds[3].y != tet2.crds[3].y);
	return (!nb_diff);
}

void	find_last_same(t_memtet *mtet, short i)
{
	short j;

	j = i - 1;
	while (j >= 0)
	{
		if (is_same(mtet->ltet[i], mtet->ltet[j]))
		{
			mtet->ltet[i].i_last = j;
			return ;
		}
		j--;
	}
	mtet->ltet[i].i_last = -1;
}

void	double_handler(t_memtet *mtet)
{
	short i;

	i = 0;
	while (i < mtet->nb_tet)
	{
		find_last_same(mtet, i);
		i++;
	}
}
