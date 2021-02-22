from tkinter import *

root = Tk()
root.title("This is title")

tk_variable = StringVar()
tk_variable.set("Cricket")

GAME_LIST = {
    "Cricket":"Cricket",
    "Football":"Football",
    "Volleyball":"Volleyball",
    "Tennis":"Tennis"
}

def clicked(s):
    Label(root,text=s).pack()
    return

Label(root,text="Your favourite game:").pack(anchor=W)

for first,second in GAME_LIST.items():
    Radiobutton(root,text=first,variable=tk_variable,value=second).pack(anchor=W)

b = Button(root,text="Click here",padx=10,pady=10,command=lambda:clicked(tk_variable.get()))
b.pack(padx=5,pady=5)

root.mainloop()