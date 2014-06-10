#/bin/bash
 
echo -n "Type in your name: "
read name

if [ $name = "roman" ]; then
	echo "Hello Roman"
else
	echo "Your not Roman"
fi
