#little brute force example
import os
filepath = input("File path: ")

if os.path.exists(filepath) == True:
	if os.path.isfile(filepath) == True:
		tries = int(input("How many tries? "))
		op = str(input("Whats the message when typing a wrong password? "))
		for x in range(tries):
			print("Trying password: ", x)
			os.system("python3 "+filepath+" "+str(x)+" "+"| grep -v"+" "+"'"+op+"'"+" "+"&& bash")
	else:
		print("Is that a real file?")
else:
	print("Does that file really exist?")

