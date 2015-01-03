function levelstart(){
	// Do a nice visual transition into the level.
	Tux.deactivate();
	Effect.fade_out(0);
	Effect.sixteen_to_nine(0);
	wait(1);
	Effect.fade_in(2);
	Effect.four_to_three(2);
	Tux.activate();
}



