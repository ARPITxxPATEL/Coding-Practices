from tkinter import *

root = Tk()
root.title("This is just a title")

frame = LabelFrame(root,text="Frame name",padx=5,pady=5)
frame.pack(padx=10,pady=10)

button = Button(frame, text="Click here", padx=10,pady=10)
button.grid(row=0,column=0)

root.mainloop()