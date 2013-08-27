OPTS = -q -O -gd

lower.exe: lower.obj lower.res makefile
       icc -B"/pm:pm" -B"/stack:100000" $(OPTS) lower.obj
       rc lower.res lower.exe

lower.res: lower.rc lower.ico X.ptr makefile
       rc -r lower.rc

lower.obj: lower.c makefile
       icc -c $(OPTS) lower.c
