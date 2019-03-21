					/*affiche cadrillage map*/

IMGDATA[((d->i * SPACEX)) * WIDTH + ((d->j * SPACEX))] = GREEN;
if ((d->j + 1 < d->max.x) && (d->i + 1 < d->max.y))
	while (++z < SPACEX)
	{
		IMGDATA[((d->i * SPACEX) + z) * WIDTH + (d->j * SPACEX)] = BLUE;
		IMGDATA[(d->i * SPACEX) * WIDTH + ((d->j * SPACEX) + z)] = RED;
	}
if ((d->i + 1 < d->max.y))
	while (++z < SPACEX)
		IMGDATA[((d->i * SPACEX) + z) * WIDTH + (d->j * SPACEX)] = BLUE;
if ((d->j + 1 < d->max.x))
	while (++z < SPACEX)
		IMGDATA[(d->i * SPACEX) * WIDTH + ((d->j * SPACEX) + z)] = RED;


//mlx_pixel_put(MLXPTR, IMGPTR, (midx + (x * SPACEX)), (midy + (y * SPACEX)), RED);



/*
** tableau[5]
**
** tableau[0] = fonction1
**
**
**
** result = (*tableau[0])(Variables);
*/
