# How to use graphical cut (CUTG, TCutG)

### Creating data

run `create_data.C` to make example data file
```bash
root -q create_data.C
```
which will create file `data/data.root` with tree `data` inside the file.
The tree has two branch "alala" and "boo".

### Creating and writting the graphical cut

run `make_cut.C` to draw the histogram.
```bash
root make_cut.C
```
Now to create the graphical cut do:
1. From the canvas click the menu View->Toolbar
   ![](https://github.com/ejungwoo/root_tcutg_example/blob/master/figures/menu.png "")
2. From the Toolbar, click the most right icon(scissor) which is "Graphical Cut".
   ![](https://github.com/ejungwoo/root_tcutg_example/blob/master/figures/icon.png "")
3. Draw the region by clicking on the histogram.
   **The last click should be a double-click**
   which will close the geometry by drawing the line from double-clicked-point to the first point.
   ![](https://github.com/ejungwoo/root_tcutg_example/blob/master/figures/cut1.png "")
4. By using example function `ww()` defined in the make_cut.C, write the graphical cut.
   Let's choose **"cut1"** for the first graphical cut name.
   ```c++
   [] ww("cut1")
   ```
   By doing this, the function `ww()` finds the primitive name CUTG 
   (which is the name of the clicked-drawing we just made) in the current TPad(gPad)
   and change the name into **"cut1"** and save it in the TFile **"cut1.root"**.
5. Do same for the second cut with name **"cut2"** (by repeating the step 2 to 4) and quit.
   ![](https://github.com/ejungwoo/root_tcutg_example/blob/master/figures/cut2.png "")
   ```c++
   [] ww("cut2")
   [] .q
   ```

### Applying graphical cut

Run `draw_with_cut.C` to draw with graphical cuts.
```bash
root draw_with_cut.C
```
Here, the cut-string "!cut1 || !cut2" is used to removed the two graphical cut regions.
![](https://github.com/ejungwoo/root_tcutg_example/blob/master/figures/result.png "")

### IMPORTANT!!

- User must set the variable name correctly to apply the cut in the tree; "alala" for x-axis, and "boo" for y-axis for this example.
  ```c++
  cg->SetVarX("alala");
  cg->SetVarY("boo");
  ```
- **Graphical cut works by cut name**, so the name should be set correctly (to "cut1" and "cut2" which is done in `ww()` for this example).
- Graphical cut also work with normal written cuts such as "cut1 && alala>5".
- Graphical cut can be used inline using the function `IsInsde(x,y)`. See `draw_with_cut.C`.
- If you don't like the clicked-drawing, just end by double clicking
  and click the graphical cut icon(scissor) to start all over again.

### Reference

- [TCutG](https://root.cern.ch/doc/master/classTCutG.html)
