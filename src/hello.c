#include <rp6502.h>
#include <stdio.h>
#include <stdbool.h>

#define XRAM_DATA 0x0000
#define XRAM_TILE 0x2000
#define CANVAS_CONFIG 0xF000

#define WHITE 0xFF
#define GRAY  0x88
#define RED   0x99

void main()
{
    int i;

    xreg_vga_canvas(1); // 320x240

    xram0_struct_set(CANVAS_CONFIG, vga_mode2_config_t, x_wrap, false);
    xram0_struct_set(CANVAS_CONFIG, vga_mode2_config_t, y_wrap, false);
    xram0_struct_set(CANVAS_CONFIG, vga_mode2_config_t, x_pos_px, 0);
    xram0_struct_set(CANVAS_CONFIG, vga_mode2_config_t, y_pos_px, 0);
    xram0_struct_set(CANVAS_CONFIG, vga_mode2_config_t, width_tiles, 2);
    xram0_struct_set(CANVAS_CONFIG, vga_mode2_config_t, height_tiles, 2);
    xram0_struct_set(CANVAS_CONFIG, vga_mode2_config_t, xram_data_ptr, XRAM_DATA);
    xram0_struct_set(CANVAS_CONFIG, vga_mode2_config_t, xram_palette_ptr, 0xFFFF); // default palette
    xram0_struct_set(CANVAS_CONFIG, vga_mode2_config_t, xram_tile_ptr, XRAM_TILE);

    RIA.addr0 = XRAM_TILE;
    RIA.step0 = 1;
    // draw tile 0
    for (i = 0; i < 32; i++) {
        RIA.rw0 = WHITE;
    }
    // draw tile 1
    for (i = 0; i < 32; i++) {
        RIA.rw0 = GRAY;
    }
    // draw tile 2
    for (i = 0; i < 32; i++) {
        RIA.rw0 = RED;
    }
    // place tiles
    RIA.addr0 = XRAM_DATA;
    RIA.rw0 = 0;
    RIA.rw0 = 1;
    RIA.rw0 = 1;
    RIA.rw0 = 0;

    xreg_vga_mode(2, 2, CANVAS_CONFIG, 0);

    while (1) {}
}
