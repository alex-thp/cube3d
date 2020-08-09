/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 11:18:10 by ade-temm          #+#    #+#             */
/*   Updated: 2020/07/01 10:30:58 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <mlx.h>

typedef struct		s_color
{
	int				red;
	int				green;
	int				blue;
	int				total;
}					t_color;

typedef struct		s_doc
{
	int				res_x;
	int				res_y;
	int				res;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	char			*texture;
	t_color			sol;
	t_color			plafond;
	char			*map;
	int				parsing_map;
}					t_doc;

typedef struct		s_pos
{
	int				res_x;
	int				res_y;
	double			camera;
	double			raydirx;
	double			raydiry;
	double			dirx;
	double			diry;
	double			olddirx;
	double			deltadistx;
	double			deltadisty;
	double			sidedistx;
	double			sidedisty;
	double			planx;
	double			plany;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	double			walldist;
	double			walldistnofish;
	double			hauteur_line;
	int				draw_start;
	int				draw_end;
	int				x;
}					t_pos;

typedef struct		s_set
{
	void			*ptr;
	void			*win;
	void			*img;
	int				*var;
}					t_set;

typedef struct		s_moove
{
	int				avancer;
	int				reculer;
	int				gauche;
	int				droite;
	int				tourner_g;
	int				tourner_d;
	double			speed;
}					t_moove;

typedef struct		s_text
{
	void			*texture_w;
	int				*img;
	int				*width;
	int				*height;
	double			column;
	int				line;
	int				size;
}					t_text;

typedef struct		s_sprite
{
	float			x;
	float			y;
	float			dist;
	float			perp_wd;
	float			pos_x;
	float			pos_y;
	int				height;
	int				width;
	int				indic;
	struct s_sprite *next;
}					t_sprite;

typedef struct		s_screenshot
{
	int				fd;
}					t_screenshot;

typedef struct		s_map
{
	t_doc			*doc;
	t_pos			*dist;
	t_sprite		*sprite;
	t_sprite		*new;
	t_set			mlx;
	t_moove			moove;
	t_text			texture[5];
	t_screenshot	screenshot;
	char			**map;
	double			*zbuffer;
	int				sprite_d;
	int				sprite_drawstarty;
	int				sprite_drawstartx;
	int				sprite_drawendx;
	int				sprite_drawendy;
	int				texx;
	int				texy;
	int				screenx;
	float			spritex;
	float			spritey;
	float			height_sprite_percue;
	float			sprite_width_percue;
	int				startx;
	int				starty;
	int				num;
	int				nb_sprite;
	float			planex;
	float			planey;
	float			oldplanex;
	float			oldplaney;
	float			invdet;
	float			transformx;
	float			transformy;
	float			pos_x;
	float			pos_y;
	int				map_x;
	int				map_y;
	float			angle;
	int				first_round;
	int				vmv;
	int				check_pos;
	int				check_gnl;
}					t_map;

void				ft_get_sprite(t_map *tab);
void				ft_sort_sprite(t_map *tab);
void				ft_calc_var_sprite(t_map *tab, int i);
void				ft_print_sprite(t_map *tab, int i);
void				init_dir(t_map *tab);
void				ft_make_screenshot(t_map *tab);
int					loop_game(t_map *tab);
void				check_doc(char *str, t_map *tab);
void				ft_error(int i);
int					ft_is_num(char c);
int					ft_get_color(t_color stuff);
void				position(t_map *tab);
double				ft_no_fish_eye(t_map *tab);
void				ft_init_ray(t_map *tab);
void				calc_dist_xy(t_map *tab);
void				wall_distance(t_map *tab);
void				ft_get_column(t_map *tab, char c);
void				ft_moove_r(t_map *tab);
void				ft_moove_l(t_map *tab);
void				ft_moove_f(t_map *tab);
void				ft_moove_b(t_map *tab);
void				ft_turn(t_map *tab);
void				ft_create_tab_sprite(t_map *tab, int count);
void				ft_sort_sprite(t_map *tab);
void				ft_dist_sprite(t_map *tab);
void				ft_swap_sp(t_sprite *t1, t_sprite *t2);
void				ft_get_column(t_map *tab, char c);
int					ft_get_pixel_from_texture(t_map *tab);
void				ft_get_line(t_map *tab, int i);
void				display_ray(t_map *tab);
int					check_game(t_map *tab);
void				calc_dist(t_map *tab);
void				calc_dist_2(t_map *tab);
int					read_xpm_texture(t_doc *doc, t_map *tab, int num);
int					read_xpm_texture_2(t_map *tab, int num, int *size);
int					relacher(int keycode, t_map *tab);
int					appuyer(int keycode, t_map *tab);
int					ft_close(void);
void				init_image(t_map *tab);
void				init_dir(t_map *tab);
void				parse_resolution(char *str, t_map *tab);
void				check_size(t_map *tab);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_is_num(char c);
int					is_whitespace(char c);
void				parse_map(t_map *tab, char *line);
int					what_is_it(char *str, t_map *tab);
int					is_it_map(char *str, t_map *tab);
void				parse_texture(char *str, t_map *tab, int i);
void				parse_texture_2(t_map *tab, int i, char *text);
void				check_parse(t_map *tab);
void				parse_line(char *str, t_map *tab);
int					ft_get_color(t_color stuff);
t_color				ft_parse_color(t_color stuff, char *str);
t_color				ft_parse_color_2(t_color stuff, char *str);
int					is_valid(t_map *tab, int i, int j);
int					is_okay(char c);
int					is_correct(char c);
void				ft_error(int i);
void				ft_error_2(int i);
void				check_map(t_map *tab);
void				ft_check(t_map *tab, int i);
#endif
