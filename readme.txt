Question 1:
In question lseek comand is used to find the total no. of characters to copy.
After finding the total size we will move the pointer using lseek to read the 1 mb of characters from the back as it is faster than reading and writing character by character
Then reversing the case and array and write the data  to the resulting file "reverse.txt".


Question2:
In question2 we use stat command,stat is a system call that is used to determine information about a file based on its file path.
st_mode is used to know whether a file is regular file or directory.
we can check the permissions by following commands:

S_IRUSR ---
read permission for the owner
S_IWUSR---
write permission for the owner
S_IXUSR ---
execute/search permission for the owner

S_IRGRP –
read for group
S_IWGRP –
write for group
S_IXGRP –
execute for group

S_IROTH ---
read for others
S_IWOTH –
write for others
S_IXOTH  --
execute for others

we can check whether file contents have been reversed and case-inverted by taking the reverse of one file and matching it with another file.The characters can by read by a buffer of size 1 mb by placing the pointer using lseek command in respective positions.
