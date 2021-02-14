from tkinter import *

root = Tk()

e = Entry(width=40,borderwidth=5)
e.grid(row=0,column=0,columnspan=4)

num = sign = None

def buttonClick(n):
    current = e.get()
    e.delete(0,END)
    e.insert(0, str(current)+str(n))

def button_add():
    global num
    global sign
    num = int(e.get())
    sign = "+"
    e.delete(0,END)

def button_sub():
    global num
    global sign
    num = int(e.get())
    sign = "-"
    e.delete(0,END)

def button_mul():
    global num
    global sign
    num = int(e.get())
    sign = "*"
    e.delete(0,END)

def button_div():
    global num
    global sign
    num = int(e.get())
    sign = "/"
    e.delete(0,END)

def button_eq():
    curr = int(e.get())
    e.delete(0,END)
    if sign == "+":
        e.insert(0,num+curr)
    if sign == "-":
        e.insert(0,num-curr)
    if sign == "*":
        e.insert(0,num*curr)
    if sign == "/":
        e.insert(0,num/curr)

def button_clear():
    e.delete(0,END)


Button_1 = Button(root,text="1",padx=20,pady=10,command=lambda: buttonClick(1))
Button_2 = Button(root,text="2",padx=20,pady=10,command=lambda: buttonClick(2))
Button_3 = Button(root,text="3",padx=20,pady=10,command=lambda: buttonClick(3))
Button_4 = Button(root,text="4",padx=20,pady=10,command=lambda: buttonClick(4))
Button_5 = Button(root,text="5",padx=20,pady=10,command=lambda: buttonClick(5))
Button_6 = Button(root,text="6",padx=20,pady=10,command=lambda: buttonClick(6))
Button_7 = Button(root,text="7",padx=20,pady=10,command=lambda: buttonClick(7))
Button_8 = Button(root,text="8",padx=20,pady=10,command=lambda: buttonClick(8))
Button_9 = Button(root,text="9",padx=20,pady=10,command=lambda: buttonClick(9))
Button_0 = Button(root,text="0",padx=20,pady=10,command=lambda: buttonClick(0))
Button_addition = Button(root,text="+",padx=20,pady=10,command=button_add)
Button_subtraction = Button(root,text="-",padx=20,pady=10,command=button_sub)
Button_multiplication = Button(root,text="*",padx=20,pady=10,command=button_mul)
Button_division = Button(root,text="/",padx=20,pady=10,command=button_div)
Button_equal = Button(root,text="=",padx=20,pady=10,command=button_eq)
Button_clear = Button(root,text="Clear",padx=10,pady=10,command=button_clear)



Button_7.grid(row=1,column=0)
Button_8.grid(row=1,column=1)
Button_9.grid(row=1,column=2)

Button_4.grid(row=2,column=0)
Button_5.grid(row=2,column=1)
Button_6.grid(row=2,column=2)

Button_1.grid(row=3,column=0)
Button_2.grid(row=3,column=1)
Button_3.grid(row=3,column=2)

Button_0.grid(row=4,column=0)
Button_addition.grid(row=4,column=1)
Button_subtraction.grid(row=4,column=2)

Button_clear.grid(row=1,column=3)
Button_division.grid(row=2,column=3)
Button_multiplication.grid(row=3,column=3)
Button_equal.grid(row=4,column=3)



root.mainloop()