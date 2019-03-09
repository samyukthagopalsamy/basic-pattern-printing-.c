#include<stdio.h>


int layerFinder(int row, int col, int dim)
{
// row 0 col 0 to 7
// col 7 row 0 to 7
// row 7 col 0 to 7
// col 0 row 0 to 7
int no_of_layers, r=0, c=dim-1, layerctr;
no_of_layers = dim % 2 == 0 ? dim/2 : dim / 2 + 1;
for(layerctr = 1; layerctr <= no_of_layers; layerctr++,r++,c--)
{
    if(row == r && (col >= r && col <=c) || row == c && ( col >= r && col<=c) ||\
       ( col == c && (row >=r && row <=c )  || ( (col == r) && (row >= r && row <=c)))       )
        break;

}
return layerctr;

}

int getOffset(int row, int col, int dim)
{
    if(row == 0)  return col+1;
        //printf("right %d", col+1);
       else if(col == (dim- 1))  return dim + row;
       //printf("down %d" , dim + row);
          else if (row == (dim- 1)) return dim + (dim-1) + (row - col);
          // printf("left %d " , dim + (dim-1) + (row - col));
              else return dim + (2 * (dim - 1))+(dim - 1- row);
              // printf("up %d", dim + (2 * (dim - 1))+(dim - 1- row));
}
int main()
{
int row, col, dim = 7

,layer_number, offset=0,newdim, newrow, newcol, ctr;

for(row = 0; row < dim; row++,printf("\n") )
{
    for(col = 0; col < dim; col++, offset = 0)
    {
        layer_number = layerFinder(row, col, dim);
//printf("%d ", layer_number);
for(ctr = 1, newdim = dim; ctr < layer_number; ctr++, newdim-=2)
    offset += ( newdim + (2 * (newdim - 1)) + (newdim - 2));
newdim = dim - (2 * (layer_number-1));
newrow = row - (layer_number - 1);
newcol = col - (layer_number - 1);

offset  += getOffset(newrow, newcol, newdim);
printf("%02d ", ((dim * dim) - offset) + 1);
//printf("%02d ",  offset);

    }
}
} // main gets over here
