# Linux File System
### Copyright 2021 Adina-Maria Amzarescu 321CA
This is a project that simulates the file system.
It has 10 commands:

* **touch** 

  This creates a new file in the current directory.
  You can find this function in _create.c_.
  Before creating a file, the function check_existance()
  will check if there already is a file/directory with the same name,
  in which case the touch() function will print the "File already exists" message.
  After the file is created, it will be added to the end of the list of files by
  changing the **_next_** parameter of the previous file.
  
  * Extra function : make_file()
    You can find it in _init.c_.
    In order to make a new file, the program will allocate memory for it
    and then it will initialize its parameters.
    
* **mkdir**

  This creates a new directory in the current directory.
  You can find this function in _create.c_.
  Before creating a directory, the function check_existance()
  will check if there already is a file/directory with the same name,
  in which case the touch() function will print the "Directory already exists" message.
  After the directory is created, it will be added to the end of the list of directories by
  changing the **_next_** parameter of the previous directory.
  
  * Extra function : make_file()
    You can find it in _init.c_.
    In order to make a new file, the program will allocate memory for it
    and then it will initialize its parameters.
    
* **ls**
* **rm**
* **rmdir**
* **cd**
* **tree**
* **pwd**
* **mv**
* **stop**
