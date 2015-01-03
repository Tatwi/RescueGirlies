// These are basid functions that can be used by scripts in any level.

// Draw an indicator icon at the top of screen.
function topDraw(x,y,imgfile){
	imageD <- FloatingImage(imgfile);
	imageD.set_anchor_point(ANCHOR_TOP);
	imageD.set_pos(x, y);
	imageD.set_visible(true);
}