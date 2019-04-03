# Intro-to-System-Calls

### Task 1: Reverse a File
      Given a file, you need to reverse the contents of that file and invert the case of each
      English character in the file and store the result in a new file within a new directory
      named “Assignment”. The file and directory thus created, can only be read/written
      by the user who created it. Program will be tested on LARGE ( > 1 GB ) files.
      
      Example:
      INPUT :
      “My name is Athira.\n”
      
      OUTPUT :
      “\n.ARIHTa SI EMAN Ym”
      
### Task 2 : Test and Verify
          Write a program to
          • Create a symlink to the above created file in “Assignment/..” (Directory where the
          original file is present)
          
          • Verify the creation of the symlink, new file and new directory created in the above
          part of question
          
          • Check permissions for the three files mentioned in the above point.
          
          • Check if the file created is reversed and case-inverted version of the input file.•
          Play around with the file permission commands and check which types of
          permissions you can give to various users, groups and others.

          Example:
          Checking whether the directory has been created: Yes
          Checking whether the file has been created: Yes
          Checking whether the symlink has been created: Yes
          Checking whether file contents have been reversed and case-inverted: Yes
          
          User has read permission on file: Yes
          User has write permission on file: Yes
          User has execute permission on file: No
          
          Group has read permission on file: No
          Group has write permission on file: No
          Group has execute permission on file: No
          
          Others has read permission on file: No
          Others has write permission on file: No
          Others has execute permission on file: No
