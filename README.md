UML Diagram :
	![Screenshot from 2024-09-13 16-36-39](https://github.com/user-attachments/assets/1ad056d4-5213-4c2e-ba02-3c11edaaa74a)
 src : https://shorturl.at/RuE3p




# In this system, there are 2 users who could login/sign up

	■ The Admin User and the Customer User
 
    The admin mainly for now just adds books to system
    The user can read 1 book at a time, but have history of his sessions
    
	■ During a session, the user can browse the book pages or end the session
	
# Advantages:
	■ File based Project
 
	■ Separation files headers and sources
 
	■ Support multiples and parallel sessions



# Here is logic of file:

	■ first we should have a book ,then for every 
	book there is a file contain content of book
	
	■ To add book on site , we should download it 
	from google, then there is file contain 
	book titles and there is file contain book that
	added by admin (Anas Elwkel)
	
	■ To save history for each user and view his profile
	we need to make file for each user and name this file 
	with username (to easy access)
	

Here is some of addition feature to update on this project:

	● Admin:

		○ Must activate a new sign-up before the user uses the system
  
		○ Edit/Delete/Search books
		
	● Customer
 
		○ Clear all the current sessions
