# Procedural2DTerrain
This is a tool designed to automate the process of making complex, non-uniform-tile-based terrain.
![image](https://user-images.githubusercontent.com/56327428/212569693-f3a45217-ddfe-4d76-b110-25e1520be635.png)
![image](https://user-images.githubusercontent.com/56327428/212569740-0257fd14-8ef3-431c-aa43-41bb93b09bec.png)

## How to Use
Inside the repo is an example project that has been set up correctly and is there for you to experiment with should this tutorial be insufficient.

1. Add the plugin to your project by copying the `ProceduralTerrainTool` folder from this repo to the `Plugins` folder (create the folder if it doesn't exist) of your project. You will need to restart the editor if it was already open.
2. In the editor right click on the `TerrainTileCreator` found in `Plugins/ProceduralTerrainTool Content` and click `Run Editor Utility Widget`. This will open up the tile data creation tool you will use to tell the generator what shape each of your tiles is.
3. Click `New Tile` and enter the name of the tile data asset and the folder to create it in. Then click `Create`.
4. Now select the class of actor you want to associate with this tile under tile data.
5. Now using the viewport or the array of vertices under tile data, create the outline of your tile. You can left-click to drag vertices & edges, right-click to delete vertices, and double-click on edges to create new vertices. `***IMPORTANT NOTE:***` Edges will only connect to each other when generating if they have the exact same length and type. Also, make sure the angles between your edges are precise so that there are no gaps when generating.
6. Repeat steps 4 & 5 until you have created all of the tiles that you want to spawn. If you would like to go back and edit a tile you already made you can select it through the `Tile Data` dropdown near the top left of the creator.
7. Now add a `TerrainGenerator` actor to your level and select it.
8. In the details panel add a new element to `Spawnable Tiles` for each tile you want this generator to be able to spawn. Then in each element the tile data and the spawn weight of that tile (higher values are more likely to spawn, and something with 0 weight will only spawn if it is the only tile that can spawn in a given location).
9. Next select a generation mode based on your needs:
   - Circular - This will generate terrain in a circle of a given radius, and is the least buggy, and usually quickest generation mode. 
   - Rectangular - This will generate terrain in a rectangle of a given width and height, which can be slow to generate. 
   - Manual - This will spawn an actor that you can move, and will place a single tile of a specified index from the spawnable tiles array as close to that actor as possible. This actor can be selected through the details of the generation mode. This is good if you want to pause generation and then add a specific tile before resuming generation on one of the other modes.
10. Now you can hit `Begin Generation`, and the terrain generator will try to fill an area with tiles. If the generation stops before it completely fills its area that means that the terrain has a location in it where no tile will fit. This can either be fixed by hitting `Reset` and generating the terrain again or by changing your spawnable tile set. If you would like the terrain to keep generating until successful then check `Generate Until Successful`. If you would like the generator to stop generating press `End Generation`. If you are unsatisfied with the terrain you can press `Reset`
11. You may now either delete the terrain generator actor or leave it in case you would like to regenerate the terrain.


## Limitations
This system has quite a few restrictions to its use that likely won't be fixed as this tool is no longer in development.

- Multiple terrain generators can not connect to each other.
- Concave tiles will certainly break things.
- Tiles that are significantly different in size (more than ~2x) and can be connected to each other will likely break the system. 
- Can cause lag as the system only spawns actors and does not support spawning of instanced static meshes instead.
- While the system may work during run time it has not been tested.
