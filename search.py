#/usr/bin/python3

import os
import sys

def search_for_file():
	print("Directory: ", end="")
	dir = input()
	if dir == ".":
		pass
	elif dir == "..":
		os.chdir("..")
	else:
		if os.path.exists(dir) == True:
			if os.path.isdir(dir) == True:
				os.chdir(dir)
			else:
				print("That directory isn't a directory!")
				exit(1)
		else:
			print("That directory doesn't exist!")
			exit(1)

	print("File name: ", end="")
	filename = input()
	files = os.listdir()
	similar = []
	x = 0

	for file in files:
		if file == filename and os.path.isfile(file) == True:
			print("--------------")
			print("| File found! |")
			print("--------------")
			x = 1
		elif filename in file:
			similar.append(file)

	if x == 0:
		print("-------------------")
		print("| File not found! |")
		print("-------------------")

	if not similar:
		pass
	else:
		print("Similar file names were: ")
		for sim in similar:
			print(sim)

try:
	if sys.argv[1] == "--help":
		print("Usage: python3 search.py <argv>")
		print("Choose one of these arguments:")
		print("--file: search for a file")
		exit(0)
	elif sys.argv[1] == "--file":
		search_for_file()
	else:
		print("Unknown argument")
		exit(1)
except IndexError:
	print("Usage: python3 search.py <argv>")
	print("Choose one of these arguments:")
	print("--file: search for a file")







	
