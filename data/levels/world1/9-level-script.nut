// Functions for level 9
// I wasn't able to make a more efficient system, because 
// VARIABLE_VALUE_IS_SCRIPTED_OBJECT_NAME.set_visible(bool) doesn't work.
// One MUST use the scripted object's name directly... Works for floating images though.

 sctgs <- [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
 
 function place_magic(){
	// Generate random choices
	for (local i = 0; i <= 15; i++){
		sctgs[i] = rand(3) + 1;
	}

	// Enable only the magic coins chosen
	if (sctgs[0] == 1){mc1.set_visible(true);}
	if (sctgs[0] == 2){mc2.set_visible(true);}
	if (sctgs[0] == 3){mc3.set_visible(true);}
	 
	if (sctgs[1] == 1){mc4.set_visible(true);}
	if (sctgs[1] == 2){mc5.set_visible(true);}
	if (sctgs[1] == 3){mc6.set_visible(true);}
	 
	if (sctgs[2] == 1){mc7.set_visible(true);}
	if (sctgs[2] == 2){mc8.set_visible(true);}
	if (sctgs[2] == 3){mc9.set_visible(true);}
		 
	if (sctgs[3] == 1){mc10.set_visible(true);}
	if (sctgs[3] == 2){mc11.set_visible(true);}
	if (sctgs[3] == 3){mc12.set_visible(true);}
		 
	if (sctgs[4] == 1){mc13.set_visible(true);}
	if (sctgs[4] == 2){mc14.set_visible(true);}
	if (sctgs[4] == 3){mc15.set_visible(true);}
		 
	if (sctgs[5] == 1){mc16.set_visible(true);}
	if (sctgs[5] == 2){mc17.set_visible(true);}
	if (sctgs[5] == 3){mc18.set_visible(true);}
		 
	if (sctgs[6] == 1){mc19.set_visible(true);}
	if (sctgs[6] == 2){mc20.set_visible(true);}
	if (sctgs[6] == 3){mc21.set_visible(true);}
		 
	if (sctgs[7] == 1){mc22.set_visible(true);}
	if (sctgs[7] == 2){mc23.set_visible(true);}
	if (sctgs[7] == 3){mc24.set_visible(true);}
		 
	if (sctgs[8] == 1){mc25.set_visible(true);}
	if (sctgs[8] == 2){mc26.set_visible(true);}
	if (sctgs[8] == 3){mc27.set_visible(true);}
		 
	if (sctgs[9] == 1){mc28.set_visible(true);}
	if (sctgs[9] == 2){mc29.set_visible(true);}
	if (sctgs[9] == 3){mc30.set_visible(true);}
		 
	if (sctgs[10] == 1){mc31.set_visible(true);}
	if (sctgs[10] == 2){mc32.set_visible(true);}
	if (sctgs[10] == 3){mc33.set_visible(true);}
		 
	if (sctgs[11] == 1){mc34.set_visible(true);}
	if (sctgs[11] == 2){mc35.set_visible(true);}
	if (sctgs[11] == 3){mc36.set_visible(true);}
		 
	if (sctgs[12] == 1){mc37.set_visible(true);}
	if (sctgs[12] == 2){mc38.set_visible(true);}
	if (sctgs[12] == 3){mc39.set_visible(true);}
		 
	if (sctgs[13] == 1){mc40.set_visible(true);}
	if (sctgs[13] == 2){mc41.set_visible(true);}
	if (sctgs[13] == 3){mc42.set_visible(true);}
		 
	if (sctgs[14] == 1){mc43.set_visible(true);}
	if (sctgs[14] == 2){mc44.set_visible(true);}
	if (sctgs[14] == 3){mc45.set_visible(true);}
}

function grant(trigger){
	Tux.add_coins(50);
	sctgs[trigger] = 99;
	secretinscript();
}