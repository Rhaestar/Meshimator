Meshimator
==========

Small mesh decimator project for image synthesis class

## Usage

```
mkdir build
cd build
cmake ..
make
./meshimator input_file output_file target_vertices
```

## Results

### LowPoly tree
Original, 230 vertices | Simplified, 100 vertices | Simplified, 30 vertices
--- | --- | ---
![](results/tree_original.png) | ![](results/tree_res1.png) | ![](results/tree_res2.png)

### Stanford Bunny
taken from [prinmath](https://www.prinmath.com/csci5229/OBJ/index.html)
Original, 69000 vertices | Simplified, 1000 vertices
--- | ---
![](results/rabbit_original.png) | ![](results/rabbit_res.png)

### Stanford T-Rex
taken from [prinmath](https://www.prinmath.com/csci5229/OBJ/index.html)
Original, 200000 vertices | Simplified, 3000 vertices
--- | ---
![](results/trex_original.png) | ![](results/trex_res.png)
