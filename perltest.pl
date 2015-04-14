#/usr/bin/env/perl 

sub hallo_welt() {
	print "Hallo Welt!\n";   # \n ! 
}

sub list() {
	@list = (1,2,3);
	print "@list[0]\n";
	print "@list\n";
}

sub list2() {
	@a = ("a");
	@nummern = (1..10);
	print "@nummern\n";
	@buchstaben = ("a".."z");
	print "@buchstaben\n";
}

sub input() {
	print "Gebe deinen Namen ein: ";
	$name = <>;
	print "Hallo $name"; # newline ist schon in $name enthalten 
}

