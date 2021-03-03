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

def final_save():

    global f_name_editor
    global l_name_editor
    global address_editor
    global city_editor
    global state_editor
    global zipcode_editor
    
    conn = sqlite3.connect("addresses_database.db")
    c = conn.cursor()
    c.execute("UPDATE addresses SET first_name = :f_name,last_name  = :l_name,address=:address,city = :city,state = :state,zipcode = :zipcode WHERE oid=:oid",{
        'f_name':f_name_editor.get(),
        'l_name':l_name_editor.get(),
        'address':address_editor.get(),
        'city':city_editor.get(),
        'state':state_editor.get(),
        'zipcode':zipcode_editor.get(),
        'oid':delete_id.get()
    })
    conn.commit()
    conn.close()



def update():

    global f_name_editor
    global l_name_editor
    global address_editor
    global city_editor
    global state_editor
    global zipcode_editor

    roote = Tk()
    roote.title("This is title")
    roote.geometry("400x400")


    conn = sqlite3.connect("addresses_database.db")
    c = conn.cursor()
    c.execute("SELECT * FROM addresses WHERE oid = "+delete_id.get())
    records = c.fetchall()


    f_name_editor = Entry(roote,width=30)
    f_name_editor.grid(row=0,column=1)
    l_name_editor = Entry(roote,width=30)
    l_name_editor.grid(row=1,column=1)
    address_editor = Entry(roote,width=30)
    address_editor.grid(row=2,column=1)
    city_editor = Entry(roote,width=30)
    city_editor.grid(row=3,column=1)
    state_editor = Entry(roote,width=30)
    state_editor.grid(row=4,column=1)
    zipcode_editor = Entry(roote,width=30)
    zipcode_editor.grid(row=5,column=1)

    f_name_editor_label = Label(roote,text="First Name:")
    f_name_editor_label.grid(row=0,column=0)
    l_name_editor_label = Label(roote,text="Last Name:")
    l_name_editor_label.grid(row=1,column=0)
    address_editor_label = Label(roote,text="Address:")
    address_editor_label.grid(row=2,column=0)
    city_editor_label = Label(roote,text="City:")
    city_editor_label.grid(row=3,column=0)
    state_editor_label = Label(roote,text="State:")
    state_editor_label.grid(row=4,column=0)
    zipcode_editor_label = Label(roote,text="Zipcode:")
    zipcode_editor_label.grid(row=5,column=0)

    for record in records:
        f_name_editor.insert(0,record[0])
        l_name_editor.insert(0,record[1])
        address_editor.insert(0,record[2])
        city_editor.insert(0,record[3])
        state_editor.insert(0,record[4])
        zipcode_editor.insert(0,record[5])

    conn.commit()
    conn.close()

    save_button = Button(roote,text="Save record",command=final_save)
    save_button.grid(row=6,column=0,columnspan=2,padx=10,pady=5,ipadx=100)


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

def delete_func():
    conn = sqlite3.connect("addresses_database.db")
    c = conn.cursor()
    c.execute("DELETE FROM addresses WHERE oid="+delete_id.get())
    conn.commit()
    conn.close()


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

f_name_editor = None 
l_name_editor = None
address_editor = None
city_editor = None
state_editor = None
zipcode_editor = None

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

delete_id_label = Label(root,text="Select ID")
delete_id_label.grid(row=9,column=0)
delete_id = Entry(root,width=30)
delete_id.grid(row=9,column=1)
delete_button = Button(root,text="Delete record",command=delete_func)
delete_button.grid(row=10,column=0,columnspan=2,padx=10,pady=5,ipadx=100)

edit_button = Button(root,text="Edit record",command=update)
edit_button.grid(row=11,column=0,columnspan=2,padx=10,pady=5,ipadx=100)

conn.commit()

conn.close()

root.mainloop()