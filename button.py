from Tkinter import *
import random 

def hide():
	r1 = random.randint(1,395)
	r2 = random.randint(1,395)
	b1.place(x=r1, y=r2)

a = Tk()
a.geometry("400x400")
a.title("Button")

b1 = Button(text="Klick mich", command=hide)
b1.pack()

mainloop()


