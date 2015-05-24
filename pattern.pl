print "Gebe deine Email Addrese ein: ";
$email = <>;
chomp($email);

if($email !~ /(.*)\@(.*)\.(.*)/) { 
    print "Das ist keine richtig Email, was?\n";
    exit();
}
$name = $1;
$anbieter = $2;
$endung = $3;

print "Dein Name ist: $name\n";
print "Dein Anbieter: $anbieter\n";
print "Die Endung deiner Email: $endung\n";
