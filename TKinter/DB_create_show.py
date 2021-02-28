from tkinter import *
import sqlite3

root = Tk()
root.title("This is title")
root.geometry("400x400")

conn = sqlite3.connect("addresses_database.db")

c = conn.cursor()

# conn.execute("""
#     CREATE TABLE addresses (
#         first_name text,
#         last_name text,
#         address text,
#         city text,
#         state text,
#         zipcode integer
#     )
# """)

def submit():

    conn = sqlite3.connect("addresses_database.db")
    c = conn.cursor()
    c.execute("INSERT INTO addresses VALUES (:f_name,:l_name,:address,:city,:state,:zipcode)",{
        'f_name':f_name.get(),
        'l_name':l_name.get(),
        'address':address.get(),
        'city':city.get(),
        'state':state.get(),
        'zipcode':zipcode.get()
    })
    conn.commit()
    conn.close()

    f_name.delete(0,END)
    l_name.delete(0,END)
    address.delete(0,END)
    city.delete(0,END)
    state.delete(0,END)
    zipcode.delete(0,END)
    return

def show_query():
    conn = sqlite3.connect("addresses_database.db")
    c = conn.cursor()
    c.execute("SELECT *,oid FROM addresses")

    print_str = ""
    records = c.fetchall()
    for record in records:
        print_str += str(record) + "\n"
    
    print_label = Label(root,text=print_str)
    print_label.grid(row=8,column=0,columnspan=2)

    conn.commit()
    conn.close()
    return

f_name = Entry(root,width=30)
f_name.grid(row=0,column=1)
l_name = Entry(root,width=30)
l_name.grid(row=1,column=1)
address = Entry(root,width=30)
address.grid(row=2,column=1)
city = Entry(root,width=30)
city.grid(row=3,column=1)
state = Entry(root,width=30)
state.grid(row=4,column=1)
zipcode = Entry(root,width=30)
zipcode.grid(row=5,column=1)

f_name_label = Label(root,text="First Name:")
f_name_label.grid(row=0,column=0)
l_name_label = Label(root,text="Last Name:")
l_name_label.grid(row=1,column=0)
address_label = Label(root,text="Address:")
address_label.grid(row=2,column=0)
city_label = Label(root,text="City:")
city_label.grid(row=3,column=0)
state_label = Label(root,text="State:")
state_label.grid(row=4,column=0)
zipcode_label = Label(root,text="Zipcode:")
zipcode_label.grid(row=5,column=0)

submit_button = Button(root,text="Add to data",command=submit)
submit_button.grid(row=6,column=0,columnspan=2,padx=10,pady=5,ipadx=100)

show_button = Button(root,text="Show table",command=show_query)
show_button.grid(row=7,column=0,columnspan=2,padx=10,pady=5,ipadx=100)

conn.commit()

conn.close()

root.mainloop()