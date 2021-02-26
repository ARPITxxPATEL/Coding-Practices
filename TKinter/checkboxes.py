from tkinter import *

# Somehow checkbutton works like radiobutton😪

root = Tk()
root.title("This is title")
root.geometry("400x400")

selected_var = StringVar()

def clicked():
    Label(root,text=selected_var.get()).pack()

FOODS = [
    ("pasta","pasta"),
    ("pizza","pizza"),
    ("petis","petis"),
    ("samosa","samosa")
]

Label(root,text="What is your favourite?").pack()

for show,val in FOODS:
    c = Checkbutton(root,text=show,variable=selected_var,onvalue=val,offvalue=val)
    c.deselect()
    c.pack()

Button(root,text="print favourite",command=clicked).pack()

root.mainloop()