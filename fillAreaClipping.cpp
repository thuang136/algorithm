/*

Graphics packages typically support only fill areas that are polygons,and often only convex polygons. to clip a polygon fill area,we cannot apply

a line-clipping

we can process a polygon fill area against the borders of a clipping window using the same general approach as in line clipping.
a line segment is defined by its two endpoints,these endpoints are processed through a line-clipping procedure by constructing
a new set of clipping endpoints at each clipping-window boundary. similarly , we need to maintaina fill area as an entity as it is
processed through the clipping stages.thus , we can clip a polygon fill area by determining the new shape for the polygon as each clipping-window
edge is processed, of course, the interior fill for the polygon would not be applied until the final clipped border has been determined

just as we first tested a line segment to determine whether it could be completely saved or completely clipped,we can do the same with a polygon fill
area by checking its coordinate extents.if the minimum and maximum coordinate values for the fill area are inside all four clipping boundaries, the fill area
is saved for further processing.if these coordinate extents are all outside any of the clipping-window borders, we eliminate the polygon from the scene description

when we cannot identify a fill area as being completely inside or completely outside the clipping window, we then need to locate the polygon intersection
positions with the clipping boundaries.one way to clipping is to create a new vertex list at each clipping boundary, and then pass this new vertex list
to the next boundary clipper. the output of the final clipping stage is the vertex list for the clipped polygon. for concave-polygon clipping, we would need
to modify this basic approach so that multiple vertex list could be generated



an efficient  method for clipping a convex-polygon fill area, developed by Sutherland and hodgman , is to send the polygon vertices through each clipping stage
so that a single clipped vertex can be immediately passed to the next stage.this eliminates the need for an output set of vertices at each clipping stage.

the general strategy in this algorithm is to send the pair of endpoints for each successive polygon line segment through the series of clipper(left, right, bottom,and top)
as soon as a clipper completes the processing of one pair of vertices, then clipped coordinate value, if any, for the edge are sent to the next clipper.
then the first clipper processes the next pair of endpoints. in this way, the individual boundary clippers can be operating in parallel.


there are four possible cases that need to be consider when processing a polygon edge against one of the clipping boundaries.





*/


