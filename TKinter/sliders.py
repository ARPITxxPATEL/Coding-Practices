from tkinter import *

root = Tk()
root.title("This is title")
root.geometry("400x400")

def button_resize():
    root.geometry(str(horizontal.get())+"x"+str(vertical.get()))

vertical = Scale(root,from_=0,to=500)
vertical.pack()

horizontal = Scale(root,from_=0,to=500,orient=HORIZONTAL)
horizontal.pack()

label = Label(root,text="horizontal:"+str(horizontal.get()) + " vertical:"+str(vertical.get()))

b = Button(root,text="Click to resize",padx=5,pady=5,command=button_resize).pack()

root.mainloop()