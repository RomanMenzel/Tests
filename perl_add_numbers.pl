sub add {
    foreach(@_) {
	$result += int($_);
    }
    return $result;
}

$num = add(1, 2, 3);
print $num;

