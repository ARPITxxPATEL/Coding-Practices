from tkinter import *

root = Tk()

label1 = Label(root, text="Block 1")
label2 = Label(root, text="Block 2")
label3 = Label(root, text="Block 3")
label4 = Label(root, text="Block 4")

label1.grid(row=0, column=0)
label2.grid(row=0, column=1)
label3.grid(row=1, column=0)
label4.grid(row=1, column=1)

root.mainloop()