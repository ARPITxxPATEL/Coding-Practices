from tkinter import *

root = Tk()
root.title("Root Window")

def clicked():
    window2 = Toplevel()
    window2.title("Second window")
    lblf = LabelFrame(window2,text="Labels")
    lblf.pack(padx=5,pady=5)
    Label(lblf,text="Click below").pack(padx=5,pady=5)
    Button(window2,text="Close window",command=window2.destroy).pack(padx=5,pady=5)

Button(root,text="New window",command=clicked).pack()

root.mainloop()