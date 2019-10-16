# apue.3e
for learn unix api

* Q1 : \share\apue.3e\threads\Makefile
    ```
    /usr/bin/ld: cannot find -lbsd

    apt-cache search libbsd
    apt-get install libbsd-dev
    ```
* Q2 : \share\apue.3e\advio\Makefile
    ```
    ./fixup.awk rot13a.c >xlate
    /bin/sh: 1: ./fixup.awk: Permission denied
    make[1]: *** [rot13c2.c] Error 126

    rot13c2.c:	rot13c2.c.in $(LIBAPUE)
	    sudo chmod 777 fixup.awk
    ```

