from tkinter import *
import numpy as np
import matplotlib.pyplot as plt

root = Tk()
root.title("This is title")
root.geometry("200x200")

def b_command():
    house_prices = np.random.normal(200000, 25000, 5000)
    plt.hist(house_prices,200)
    plt.show()

b = Button(root,text="JUST DO IT!",padx=5,pady=5,command=b_command).pack()

root.mainloop()