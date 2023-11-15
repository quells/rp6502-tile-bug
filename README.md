# RP6502 Mode 2 Bug

Minimal reproduction of a Mode 2 VGA bug on the RP6502 platform (v0.4).

This should be a 2x2 checkerboard of white and gray tiles:

![tile bug](tile-bug.png)

But there seems to be an off-by-one-byte error when more than one bit-per-pixel is used.
