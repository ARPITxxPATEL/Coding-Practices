from tkinter import *

root = Tk()
root.title("this is title")
root.geometry("400x400")

LIST = [
    "India",
    "USA",
    "UK",
    "Canada",
    "Australia",
    "Japan"
]

list_var = StringVar()
list_var.set(LIST[0])

def show_button():
    Label(root,text=list_var.get()).pack()

o = OptionMenu(root,list_var,*LIST)
o.pack()

Button(root,text="Your option",command=show_button).pack()

root.mainloop()