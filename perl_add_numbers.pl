sub add {
    foreach(@_) {
	$result += int($_);
    }
    return $result;
}
