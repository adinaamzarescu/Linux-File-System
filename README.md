# Linux File System
### Copyright 2021 Adina-Maria Amzarescu 321CA
This is a project that simulates the file system.
It has 10 commands:

* #### **touch** 

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
    In order to make a new directory, the program will allocate memory for it
    and then it will initialize its parameters.
    
* **ls**

  This function will list all the directories and then all the files in the
  current directory.
  You can find this function in _list.c_.
  
  * Extra functions: ls_file()  ls_dir()
  
    Those 2 functions are used to list them separately.
  
* **rm**

     This removes a file. If no file can be found, it will print
     the "Could not find the file" message.
     You can find this function in _remove.c_.
     After removing the file from the list, it will free
     the memory that has been allocated for it.
     
* **rmdir**

     This removes a directory. If no directory can be found, it will print
     the "Could not find the directory" message.
     You can find this function in _remove.c_.
     After removing the directory from the list, it will free
     the memory that has been allocated for it.
     
     * Extra functions : free_directory()  free_file()
     
          You can find this functions in _free_mem.c_.
          The rmdir command removes the content of the directory
          as well, so in order to free all the memory for the directories
          and the files, the function free_directory will recursively
          delete all the directories and files.
* **cd**

    This changes the current directory in the one with the given name from
    the directory list of the current one. If the name is ".." then the
    directory will become the parent of the current one. 
    You can find this function in _paths.c_.
    Since it will be changes, the function will be called with the adress
    of the target parameter.
    
* **tree**

    This function will show the content of the current directory in an
    arborescent form. Firstly it will show the directories and after that
    the files.
    You can find this function in _list.c_.
    This is a recursive function so at first level will be 0. Then level
    will be incremented by 1 for every directory found inside. The spacing
    consists of 4 spaces.
   
* **pwd**

    This function shows the path of the current directory, staring with home.
    After the path is printed, the program will free the memory allocated
    for the string.
    
    * Extra function : find_path()
    
        Since it is a recursive function, find path will create a
        string from the parent to teh current directory by concatenating
        the names, followed by "/". Every path will start with "/home" because
        this is the first directory of the system.
* **mv**
* **stop**
