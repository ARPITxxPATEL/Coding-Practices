from tkinter import *

root = Tk()

e = Entry(root, borderwidth=5, bg="yellow", fg="green", width=50)
e.pack()

def myClick():
    mylabel = Label(root, text="Hello "+e.get())
    mylabel.pack()

button1 = Button(root, text="Enter your name : ", command=myClick)
button1.pack()

root.mainloop()