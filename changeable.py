#/usr/bin/env python
# -*- coding: utf-8 -*-

# (c) Roman Menzel 

from Tkinter import *

# functions: 

def func1():
	try:
		if e1.get() == "white":
			fenster.configure(bg=("white"))
			l1.configure(bg=("white"), fg=("black"))
			l2.configure(bg=("white"), fg=("black"))
			l3.configure(bg=("white"), fg=("black"))

		else:
			fenster.configure(bg=(e1.get()))
			l1.configure(bg=(e1.get()))
			l2.configure(bg=(e1.get()))
			l3.configure(bg=(e1.get()))


		if e1.get() == "black":
			fenster.configure(bg=("black"))
			l1.configure(bg=("black"), fg=("white"))
			l2.configure(bg=("black"), fg=("white"))
			l3.configure(bg=("black"), fg=("white"))

	except:
		fenster.configure(bg=("black")) 
		l1.configure(bg=("black"))      
		l2.configure(bg=("black")) 
		l3.configure(bg=("black")) 

def func2():

	if e2.get() == "":
		fenster.geometry("400x400")

	else:
		fenster.geometry("400x400")

	try:
		fenster.geometry(e2.get())

	except:
		fenster.geometry("400x400") 

def func3():
	fenster.title(e3.get())

##########################################

fenster = Tk()
fenster.title("Changeable")
fenster.geometry("400x400")
fenster.configure(bg=("black"))

##########################################

# main programme: 

l1 = Label(text="Background: ", fg="white", bg="black")
l1.place(y=0, x=0)

e1 = Entry()
e1.place(y=25, x=0)

b1 = Button(text="Confirm", command=func1)
b1.place(x=0, y=55)

l2 = Label(text="Size (for example: 200x200): ", fg="white", bg="black")
l2.place(x=0, y=120)

e2 = Entry()
e2.place(x=0, y=145)

b2 = Button(text="Confirm", command=func2)
b2.place(x=0, y=175)

l3 = Label(text="Title: ", fg="white", bg="black")
l3.place(x=0, y=240)

e3 = Entry()
e3.place(x=0, y=270)

b3 = Button(text="Confirm", command=func3)
b3.place(x=0, y=300)

mainloop()
