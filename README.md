# Restaurant-Billing-System 🍽️
The Restaurant Billing System is a console-based application developed in C language that automates the process of generating, managing, and storing customer invoices for restaurants or cafés.

This project is designed to simplify billing operations, reduce manual errors, and efficiently handle customer transaction records.

📌 Features     
• Generate detailed customer invoices    
• Search previous invoices by customer name   
• Store and retrieve unlimited billing records   
• Automatic calculation of:
Subtotal
Discount
VAT and Service Tax
Final payable amount  
• Display all previous invoices    
• Simple menu-driven interface with exit option  

⚙️ Functionalities:    
The system provides three main operations:     
1. Generate Invoice:                            
• Input customer name, items, quantity, and price    
• Automatically calculates total bill with discount and taxes
2. Search Invoice:           
• Find and display previous bills using customer name
3. Show All Invoices:       
•View all stored billing records

🛠️ Technical Details                            
• Language: C                             
• File Handling: Used to store and retrieve invoices (.dat file)                       
• Data Structures:                                                       
struct foods → Stores item details (name, price, quantity)             
struct orders → Stores customer and order details                                 
• Modular Functions:                          
Bill Header Generation               
Bill Body (items)                            
Bill Footer (calculations with discount & VAT)

💡 How It Works                         
User selects an option from the main menu                             
Inputs required billing details                  
System generates a formatted invoice                    
Option to save the invoice into a file                  
Stored data can be retrieved anytime                   

🎯 Purpose               
This project demonstrates:             
Core C programming concepts             
File handling                          
Structures and arrays                       
Menu-driven application design  

It can be used as a basic prototype for real-world billing systems in restaurants.                 

🚀 Future Improvements                     
GUI-based version (using C++/Java/Python)             
Database integration (MySQL)                  
User authentication system                    
Enhanced reporting and analytics                            
