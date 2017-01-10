/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:05:42 by nboute            #+#    #+#             */
/*   Updated: 2017/01/10 19:55:19 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define BLUE 0x000000FF
# define GREEN 0x0000FF00
# define YELLOW 0x00FFFF00
# define RED 0x00FF0000
# define PINK 0x00FF3399
# define TURQUOISE 0x00CCCC
# define VIOLET 0x00990099
# define BROWN 0x00663300
# define ORANGE 0x00FF9900
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "../libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../minilibx_macos/mlx.h"

typedef struct			s_point
{
	double				x;
	double				y;
	double				z;
	double				xs;
	double				ys;
	double				zs;
	struct s_point		*right;
	struct s_point		*down;
	int					color;
}						t_point;

typedef struct			s_readlines
{
	char				**tab;
	struct s_readlines	*next;
}						t_readlines;

typedef struct			s_honk
{
	void				*mlx;
	void				*win;
	void				*img;

	int					bpx;
	int					size;
	int					endian;
	int					prex;
	int					prey;
	float				zoom;
	float				xang;
	float				xsang;
	float				yang;
	float				ysang;
	float				zang;
	float				zsang;
	int					xrot;
	int					yrot;
	int					zrot;
	float				rs;
	short				grad;
	int					color;

	int					width;
	int					height;
	t_point				**grid;
	int					gwid;
	int					ghei;
	int					zmin;
	int					zmax;
	int					zrange;
	int					minval;
	char				*data;

}						t_honk;

void					ft_sort_grid_rev(t_honk *honk);
int						*ft_get_vals(t_honk *honk);
void					ft_sort_grid(t_honk *honk);
void					ft_keep_angles(float *ang, int rot, float sp);
int						ft_mouse_pressed(int button, int x, int y,
		t_honk *honk);
void					ft_key_pressed_p3(int keycode, t_honk *honk);
void					ft_key_pressed_p2(int keycode, t_honk *honk);
int						ft_key_pressed(int keycode, t_honk *honk);
int						set_color(int cp);
int						ft_rotate_action(t_honk *honk);
int						ft_prepdraw(long *l, int *d, int *s);
void					ft_getpoints(t_point *p0, t_point *p1, long *l);
void					ft_drawseg(t_point *p0, t_point *p1, t_honk *honk);
void					ft_drawseg_grad(t_point *p0, t_point *p1, t_honk *honk);
void					ft_drawmap(t_honk *honk, void	fct(t_point*,
			t_point*, t_honk*));
void					ft_drawcolors(t_honk *honk);
void					ft_setmap(t_honk *honk);
void					ft_place_point(t_honk *honk, double y, double x,
		int color);
void					ft_empty_grid(t_honk *honk);
void					ft_draw(t_honk *honk);
int						ft_redraw_map(t_honk *honk);
void					ft_rotate_axis(t_point *p, float x, float y, float z);
void					ft_rotate(t_honk *honk);
t_readlines				*ft_get_grid(int fd, t_honk *honk);
void					ft_set_height(t_honk *honk, t_point *p, char *nb);
void					ft_sethonk_p2(t_honk *honk, t_readlines *start,
		t_readlines *tmp);
void					ft_sethonk(t_honk *honk, int fd);
void					ft_setscale(t_honk *honk);
void					ft_set_gradations(t_honk *honk);
int						ft_gradation(unsigned int col, unsigned int col2,
		int p);
void					ft_error(void);
int						ft_getnbr_int(char *str);
void					ft_clear_readline(t_readlines *elem);

#endif
