# 42_Cub3D

***My first RayCaster with MacrolibX***

This project is inspired by the world-famous Wolfenstein 3D game, which
was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to
make a dynamic view inside a maze, in which you’ll have to find your way.

## RESSOURCES

- https://austinhenley.com/blog/raycasting.html
- https://lodev.org/cgtutor/raycasting4.html#Introduction
- https://github.com/vinibiavatti1/RayCastingTutorial/wiki/RayCasting

==593753== Invalid read of size 4
==593753==    at 0x48C2D92: mlx::Texture::getPixel(int, int) (in /sgoinfre/goinfre/Perso/bapasqui/Core/42_Cub3D/MacroLibX/libmlx.so)
==593753==    by 0x487FE23: mlx_get_image_pixel (in /sgoinfre/goinfre/Perso/bapasqui/Core/42_Cub3D/MacroLibX/libmlx.so)
==593753==    by 0x402301: select_color (render_wall.c:45)
==593753==    by 0x404900: draw_in_color (draw.c:34)
==593753==    by 0x404AC0: draw_wall (draw.c:56)
==593753==    by 0x40414D: fov_details (ray_handle.c:118)
==593753==    by 0x4012EE: move_render (main.c:22)
==593753==    by 0x487DB97: mlx::core::Application::run() (in /sgoinfre/goinfre/Perso/bapasqui/Core/42_Cub3D/MacroLibX/libmlx.so)
==593753==    by 0x487F810: mlx_loop (in /sgoinfre/goinfre/Perso/bapasqui/Core/42_Cub3D/MacroLibX/libmlx.so)
==593753==    by 0x401413: main (main.c:47)
==593753==  Address 0xc9d7960 is 208 bytes inside a block of size 1,968 free'd
==593753==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==593753==    by 0x797CB60: ??? (in /usr/lib/x86_64-linux-gnu/libnvidia-glcore.so.555.42.06)
==593753==    by 0x7D5CD31: ??? (in /usr/lib/x86_64-linux-gnu/libnvidia-glcore.so.555.42.06)
==593753==    by 0x488DF0C: mlx::CmdBuffer::endRecord() (in /sgoinfre/goinfre/Perso/bapasqui/Core/42_Cub3D/MacroLibX/libmlx.so)
==593753==    by 0x488A9E5: mlx::Renderer::endFrame() (in /sgoinfre/goinfre/Perso/bapasqui/Core/42_Cub3D/MacroLibX/libmlx.so)
==593753==    by 0x4886D1D: mlx::GraphicsSupport::render() (in /sgoinfre/goinfre/Perso/bapasqui/Core/42_Cub3D/MacroLibX/libmlx.so)
==593753==    by 0x487DBC5: mlx::core::Application::run() (in /sgoinfre/goinfre/Perso/bapasqui/Core/42_Cub3D/MacroLibX/libmlx.so)
==593753==    by 0x487F810: mlx_loop (in /sgoinfre/goinfre/Perso/bapasqui/Core/42_Cub3D/MacroLibX/libmlx.so)
==593753==    by 0x401413: main (main.c:47)
==593753==  Block was alloc'd at
==593753==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==593753==    by 0x797C6B1: ??? (in /usr/lib/x86_64-linux-gnu/libnvidia-glcore.so.555.42.06)
==593753==    by 0x7D9F218: ??? (in /usr/lib/x86_64-linux-gnu/libnvidia-glcore.so.555.42.06)
==593753==    by 0x7D4F0C1: ??? (in /usr/lib/x86_64-linux-gnu/libnvidia-glcore.so.555.42.06)
==593753==    by 0x488D1F5: mlx::CmdBuffer::beginRecord(unsigned int) (in /sgoinfre/goinfre/Perso/bapasqui/Core/42_Cub3D/MacroLibX/libmlx.so)
==593753==    by 0x488A576: mlx::Renderer::beginFrame() (in /sgoinfre/goinfre/Perso/bapasqui/Core/42_Cub3D/MacroLibX/libmlx.so)
==593753==    by 0x4886BA6: mlx::GraphicsSupport::render() (in /sgoinfre/goinfre/Perso/bapasqui/Core/42_Cub3D/MacroLibX/libmlx.so)
==593753==    by 0x487DBC5: mlx::core::Application::run() (in /sgoinfre/goinfre/Perso/bapasqui/Core/42_Cub3D/MacroLibX/libmlx.so)
==593753==    by 0x487F810: mlx_loop (in /sgoinfre/goinfre/Perso/bapasqui/Core/42_Cub3D/MacroLibX/libmlx.so)
==593753==    by 0x401413: main (main.c:47)
==593753== 