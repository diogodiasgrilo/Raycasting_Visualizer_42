![Raycasting](./sprites/raycaster.png)

I created this program as a base for the minimap system of the cub3d project at 42 Lisbon.

Here is the proper usage when executing the program:

"program name" "map file"

Here is a visual example:
```bash
➜  ~ ./raycasting ./maps/test1.ber
```
You can move the square player around with the asdw keys and the square will move in the direction that the rays are shooting towards.

The a and d keys will move the angle of the rays (player's view perspective).

The s and w keys will move the player forward and backward based on where the rays are pointed to.

Raycasting can then be used to create 3D-looking games by assigning a rectangle of pixels on the screen for each ray cast, thus creating a different-sized rectangle based on how long each cast ray was. This will create the illusion of a 3D world with 2D objects. The next step for this raycaster is to start drawing rectangles on a split screen with the minimap or on a separate screen altogether!
Try using this raycaster program on different maps either from my maps folder or make your own.
