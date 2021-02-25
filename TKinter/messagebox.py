from tkinter import *
from tkinter import messagebox

root = Tk()
root.title("Tis is title")

# showinfo, showwarning, showerror, askyesno, askquestion

def popup():
    response = messagebox.askyesno("This is title","Here is messagebox")
    if response==1:
        Label(root,text="You clicked yes").pack()
    else:
        Label(root,text="You clicked no").pack()

Button(root,text="Click me",command=popup,padx=5,pady=5).pack(padx=10,pady=10)

root.mainloop()