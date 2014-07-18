#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
The function list_files was written by youtube.com/user/theregrunner.
I only modified it a bit 

"""

import os

def list_files(lang):
	try:                
	    from win32com.shell import shellcon, shell
	    Directory = shell.SHGetFolderPath(0, shellcon.CSIDL_APPDATA, 0, 0)   # Windows
	except ImportError: 
	    Directory = os.path.expanduser("~")                                  # Linux

	for root , dirs , files in os.walk(Directory):
	 for filename in files :
	   if filename.lower().endswith("." + lang):
	     PathToFile = os.path.join(root,filename)
	     print PathToFile

	print("Press enter")	
	enter = raw_input("")

print("py,rb,c,cpp,h,sh,html,php,js,asm,pas,lua")
end = raw_input("Which file ending do you want? ")

if end == "py":
	list_files("py")

elif end == "rb":
	list_files("rb")

elif end == "c":
	list_files("c")

elif end == "cpp":
	list_files("cpp")

elif end == "h":
	list_files("h")

elif end == "sh":
	list_files("sh")

elif end == "html":
	list_files("html")

elif end == "php":
	list_files("php")

elif end == "js":
	list_files("js")

elif end == "asm":
	list_files("asm")

elif end == "pas":
	list_files("pas")

elif end == "lua":
	list_files("lua")

else:
	print("Ending not supported")


