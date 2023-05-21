###################################### using Python #########################################


def writeModel():
     with open('k1.txt', 'a' ) as file:
         c='y'
         while c=='y'or c=='Y':
             id=input('enter the id of car: ')
             name=input('enter the name of car: ')
             model=input('enter the model of car: ')
             price=input('enter the price of car: ')
             color=input('enter the color of car: ')
             file.write(id +'\t' +name +'\t' +model +'\t' +price +'\t' +color +'\n')
             c=input('do you want to add record again ??\n')
 
 
def readModel(): 
    with open('k1.txt', 'r' ) as file:
        print('{:10s} {:10s} {:10s} {:10s} {:10s}'.format('ID', 'NAME', 'MODEL', 'PRICE', 'COLOR'))
        #print('Id\tName\tModel\tPrice\tColor')
        for line in file:
            #print(line, end='')
            c= line.split("\t")
            print('{:10s} {:10s} {:10s} {:10s} {:10s}'.format(c[0], c[1], c[2], c[3], c[4]))
 
 
def searchByName():
     name = input('Enter the name of car to search: ')
     flag=False
     with open ('k1.txt' , 'r' ) as file:
          for line in file:
               s=line.split('\t')
               if name==s[1]:
                    flag=True
                    print('Id:',s[0])
                    print('Name:',s[1])
                    print('Model: ',s[2])
                    print('Price: ',s[3])
                    print('Color: ',s[4])
          if not flag:
               print('No cars are found !!')
 
 
def searchById():
     id = input('Enter the id of car to search: ') 
     flag=False
     with open ('k1.txt' , 'r' ) as file:
          for line in file:
               s=line.split('\t')
               if id==s[0]:
                    flag=True
                    print('Id:',s[0])
                    print('Name:',s[1])
                    print('Model: ',s[2])
                    print('Price: ',s[3])
                    print('Color: ',s[4])
          if not flag:
               print('No cars are found !!')
 
 
def search():
     a=input('do you want to search by name or id ?? (n/i) ')
     if a=='N' or a=='n':
          searchByName()
     elif a=='I' or a=='i':
          searchById()
 
 
def UpdateByName():
     import os
     id = input('Enter the id of record u want to update : ')
     flag=False
     file= open ('k1.txt' , 'r' )
     fl= open ('k2.txt' , 'w' )
     for line in file:
          s=line.split('\t')
          if id==s[0]:
               flag=True
               name=input('Enter new name of car to update:  ')
               line=s[0]+'\t'+name+'\t'+s[2]+'\t'+s[3]+'\t'+s[4]
 
          fl.write(line)
 
     file.close()
     fl.close()
     os.remove('k1.txt')
     os.rename('k2.txt','k1.txt')              
     if not flag:
          print('No cars are found !!')
 
 
def UpdateById():
     import os
     id = input('Enter the id of record u want to update : ')
     flag=False
     file= open ('k1.txt' , 'r' )
     fl= open ('k2.txt' , 'w' )
     for line in file:
          s=line.split('\t')
          if id==s[0]:
               flag=True
               newId=input('Enter new id of car to update:  ')
               line=newId+'\t'+s[1]+'\t'+s[2]+'\t'+s[3]+'\t'+s[4]
 
          fl.write(line)
 
     file.close()
     fl.close()
     os.remove('k1.txt')
     os.rename('k2.txt','k1.txt')              
     if not flag:
          print('No cars are found !!')          
 
 
def UpdateByModel():
     import os
     id = input('Enter the id of record u want to update : ')
     flag=False
     file= open ('k1.txt' , 'r' )
     fl= open ('k2.txt' , 'w' )
     for line in file:
          s=line.split('\t')
          if id==s[0]:
               flag=True
               model=input('Enter new model of car to update:  ')
               line=s[0]+'\t'+s[1]+'\t'+model+'\t'+s[3]+'\t'+s[4]
 
          fl.write(line)
 
     file.close()
     fl.close()
     os.remove('k1.txt')
     os.rename('k2.txt','k1.txt')              
     if not flag:
          print('No cars are found !!')
 
 
def UpdateByPrice():
     import os
     id = input('Enter the id of record u want to update : ')
     flag=False
     file= open ('k1.txt' , 'r' )
     fl= open ('k2.txt' , 'w' )
     for line in file:
          s=line.split('\t')
          if id==s[0]:
               flag=True
               price=input('Enter new price of car to update:  ')
               line=s[0]+'\t'+s[1]+'\t'+s[2]+'\t'+price+'\t'+s[4]
 
          fl.write(line)
 
     file.close()
     fl.close()
     os.remove('k1.txt')
     os.rename('k2.txt','k1.txt')              
     if not flag:
          print('No cars are found !!')        
 

def UpdateByColor():
     import os
     id = input('Enter the id of record u want to update : ')
     flag=False
     file= open ('k1.txt' , 'r' )
     fl= open ('k2.txt' , 'w' )
     for line in file:
          s=line.split('\t')
          if id==s[0]:
               flag=True
               color=input('Enter new color of car to update:  ')
               line=s[0]+'\t'+s[1]+'\t'+s[2]+'\t'+s[3]+'\t'+color+'\n'
 
          fl.write(line)
 
     file.close()
     fl.close()
     os.remove('k1.txt')
     os.rename('k2.txt','k1.txt')              
     if not flag:
          print('No cars are found !!')
 
 
def Updateitems():
     a=input('do you want to Update by Name:N , Id:I , Model:M , Price:P or Color:C ?? ')
     if a=='N' or a=='n':
          UpdateByName()
     elif a=='I' or a=='i':
          UpdateById()
     elif a=='M' or a=='m':
          UpdateByModel()
     elif a=='P' or a=='p':
          UpdateByPrice()
     elif a=='C' or a=='c':
          UpdateByColor()     
 
 
def UpdateAll(): 
     import os
     id = input('Enter the id of car you want to update : ')
     flag=False
     file= open ('k1.txt' , 'r' )
     fl= open ('k2.txt' , 'w' )
     for line in file:
          s=line.split('\t')
          if id==s[0]:
               flag=True
               id=input('Enter new id of car to update:  ')
               name=input('Enter new name of car to update:  ')
               model=input('Enter new model of car to update:  ')
               price=input('Enter new price of car to update:  ')
               color=input('Enter new color of car to update:  ')
               line=id +'\t'+name+'\t'+model+'\t'+price+'\t'+color+'\n'
 
          fl.write(line)
 
     file.close()
     fl.close()
     os.remove('k1.txt')
     os.rename('k2.txt','k1.txt')              
     if not flag:
          print('No cars are found !!')
 
 
def DeleteById():
     import os
     id = input('Enter the id of car to delete: ')
     flag=False
     file= open ('k1.txt' , 'r' )
     fl= open ('k2.txt' , 'w' )
     for line in file:
          s=line.split('\t')
          if id==s[0]:
               flag=True
          else:
               fl.write(line)
 
     file.close()
     fl.close()
     os.remove('k1.txt')
     os.rename('k2.txt','k1.txt')              
     if not flag:
          print('No cars are found !!')
 
 
def DeleteByName(): 
     import os
     name = input('Enter the name of car to delete: ')
     flag=False
     file= open ('k1.txt' , 'r' )
     fl= open ('k2.txt' , 'w' )
     for line in file:
          s=line.split('\t')
          if name==s[1]:
               flag=True
          else:
               fl.write(line)
 
     file.close()
     fl.close()
     os.remove('k1.txt')
     os.rename('k2.txt','k1.txt')              
     if not flag:
          print('No cars are found !!')          
 
 
def Delete():
     a=input('do you want to delete by name or id ?? (n/i)')
     if a=='N' or a=='n':
          DeleteByName()
     elif a=='I' or a=='i':
          DeleteById()
 
 
# Actual program :
 
c='y'
 
while c=='y' or c=='Y':
     print('\t\t----------------------------------------------------Welcome to Our Company------------------------------------------------\n\t\t===========================================================================================================================\n\t\t-----------------------------------------------choose the operation to execute--------------------------------------------\n\t--------------------------------------------------------------------------------------------------------------------------------------------- \n\t\t\t\t\t1: Add new model \t 2: Display all models \t 3: Search for model \n\t\t\t\t\t4: Delete model \t 5: Update model \t 6: Update items \n')               
     x=input("Enter the operation you want to execute: ") 
     match x:
          case "1":
               writeModel()
               c=input('do you want to continue ?? (y/n)')
               if c=='Y' or c=='y':
                    print('Enter the operation you want to execute: ')
 
          case "2":
               readModel()
               c=input('do you want to continue ?? (y/n)')
               if c=='Y' or c=='y':
                    print('Enter the operation you want to execute: ')
 
          case "3":
               search()
               c=input('do you want to continue ?? (y/n) ')
               if c=='Y' or c=='y':
                    print('Enter the operation you want to execute: ')
 
          case "4":
               Delete()
               print('Done')
               c=input('do you want to continue ?? (y/n)')
               if c=='Y' or c=='y':
                    print('Enter the operation you want to execute: ') 
 
          case "5":
               UpdateAll()
               print('Done')
               c=input('do you want to continue ?? (y/n) ')
               if c=='Y' or c=='y':
                    print('Enter the operation you want to execute: ')
 
          case "6":
               Updateitems()
               print('Done')
               c=input('do you want to continue ?? (y/n) ')
               if c=='Y' or c=='y':
                    print('Enter the operation you want to execute: ')
 
          case _:
               print('invalid')
        

            
    
        
        

            
    
