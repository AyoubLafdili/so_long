// // // /* ************************************************************************** */
// // // /*                                                                            */
// // // /*                                                        :::      ::::::::   */
// // // /*   mlx.c                                              :+:      :+:    :+:   */
// // // /*                                                    +:+ +:+         +:+     */
// // // /*   By: alafdili <alafdili@student.42.fr>          +#+  +:+       +#+        */
// // // /*                                                +#+#+#+#+#+   +#+           */
// // // /*   Created: 2024/03/17 17:01:08 by alafdili          #+#    #+#             */
// // // /*   Updated: 2024/03/18 15:52:38 by alafdili         ###   ########.fr       */
// // // /*                                                                            */
// // // /* ************************************************************************** */

// #include "so_long.h"

// // // #define WIDTH 256
// // // #define HEIGHT 256

// #include <stdlib.h>
// #include <stdio.h>
// #include <unistd.h>
// #include "MLX42.h"

// // // // Exit the program as failure.
// // // // static void ft_error(void)
// // // // {
// // // // 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// // // // 	exit(EXIT_FAILURE);
// // // // }

// // // // // Print the window width and height.

// // // // int32_t	main(void)
// // // // {

// // // // 	// MLX allows you to define its core behaviour before startup.
// // // // 	mlx_set_setting(MLX_MAXIMIZED, true);
// // // // 	mlx_t* mlx = mlx_init(20, 10, "42Balls", true);
// // // // 	if (!mlx)
// // // // 		ft_error();

// // // // 	/* Do stuff */

// // // // 	// Create and display the image.
// // // // 	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
// // // // 	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
// // // // 		ft_error();

// // // // 	// Even after the image is being displayed, we can still modify the buffer.
// // // // 	mlx_put_pixel(img, 0, 0, 0xFF0000FF);

// // // // 	// Register a hook and pass mlx as an optional param.
// // // // 	// NOTE: Do this before calling mlx_loop!
// // // // 	mlx_loop_hook(mlx, ft_hook, mlx);
// // // // 	mlx_loop(mlx);
// // // // 	mlx_terminate(mlx);
// // // // 	return (EXIT_SUCCESS);
// // // // }

// mlx_image_t *img;

// // // int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// // // {
// // //     return (r << 24 | g << 16 | b << 8 | a);
// // // }

// // // void ft_randomize(void* param)
// // // {
// // // 	(void)param;
// // // 	for (uint32_t i = 0; i < img->width; ++i)
// // // 	{
// // // 		for (uint32_t y = 0; y < img->height; ++y)
// // // 		{
// // // 			uint32_t color = ft_pixel(
// // // 				rand() % 0xFF, // R
// // // 				rand() % 0xFF, // G
// // // 				rand() % 0xFF, // B
// // // 				rand() % 0xFF  // A
// // // 			);
// // // 			mlx_put_pixel(img, i, y, color);
// // // 		}
// // // 	}
// // // }

// // // // void ft_hook(void *param)
// // // // {
// // // // 	mlx_t *n_mlx = param;
// // // // 	double time = mlx_get_time();
// // // // 	char *times = ft_itoa(time);
// // // // 	//img = mlx_put_string(n_mlx, times, 0, 0);
// // // // }
// void ft_move_player(void *c_mlx)
// {
// 	mlx_t *mlx = c_mlx;
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W))
// 		img->instances[0].y -= 2;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN)|| mlx_is_key_down(mlx, MLX_KEY_S))
// 		img->instances[0].y += 2;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT)|| mlx_is_key_down(mlx, MLX_KEY_A))
// 		img->instances[0].x -= 2;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT)|| mlx_is_key_down(mlx, MLX_KEY_D))
// 		img->instances[0].x += 2;
// }

// int main()
// {
// 	mlx_t *mlx = mlx_init(600, 500, "", true);
// 	if (!mlx)
// 		error_hundler(NULL, NULL, "mlx_init failed!\n", '0');
// 	mlx_texture_t *texture = mlx_load_png("/Users/alafdili/Desktop/resized_assets/player.png");
// 	if (!texture)
// 		printf("failed!\n");
// 	img = mlx_texture_to_image(mlx, texture);
// 	int win = mlx_image_to_window(mlx, img, 0, 0);
// 	if (win == -1)
// 		printf("mlx_image_to_window faile\n");
// 	mlx_loop_hook(mlx, ft_move_player, mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	exit(EXIT_SUCCESS);
// }





















#include <MLX42.h>
#include <stdlib.h>
// #include "so_long"

int main()
{
	mlx_texture_t *txr = malloc(20);
	free(txr);
}