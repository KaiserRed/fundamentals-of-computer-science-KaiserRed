import os
import time
import pathlib

print("Declare suffix of the file")
suffix = input()
if (suffix == '?'):
    print("This code allows you to delete all files with specified suffix and modification date. To do this type suffix and then type the last date of modification. If files are existing they will be deleted, else they aren't")
    print("Declare suffix of the file")
    suffix = input()
    
suffix = '.' + suffix 
print ('Declare how old files are allowed to be and set the root directory')
days = int(input())
days_ago = time.time() - (days * 86400)
root = "/home/alexey/"
count = 0
for i in os.listdir(root):
    path = os.path.join(root, i)
    if ((os.stat(path).st_mtime <= days_ago) and (pathlib.PurePath(path).suffix == suffix)):
        if os.path.isfile(path):
            print(pathlib.PurePath(path).name)
            os.remove(path)
            count+=1
if (count == 0):
    print('Could not remove file')
