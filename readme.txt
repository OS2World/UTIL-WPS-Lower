		      LOWER, by Matthew Austern
		     (matt@physics.berkeley.edu)

The OS/2 2.x Presentation Manager makes it easy to raise a window to the
top of the screen: you can just click on the window, or you can select
it from the Window List.

For some reason, though, OS/2 doesn't make the reverse operation---
lowering a window that is already at the top---equally easy.  You can
do it, but it requires using the keyboard.  Specifically, you select
the window and then type ALT+TAB.

LOWER is a small utility that provides this functionality without
having to use the keyboard.  When you start LOWER, the mouse pointer
changes to an X.  Just click the left mouse button on a window, and
this window will be moved to the bottom of the pile.  If the window
you click on is already at the bottom (such as the desktop), then
nothing will happen.  Also, if you click with any other mouse button
then nothing will happen.  In any case, the program will exit as soon
as you click any mouse button.

You install LOWER just by copying lower.exe to your hard disk, and you
deinstall it by deleting it.  It doesn't create any hidden files or
make changes to your configuration.

You can run LOWER from the command line, or by double-clicking on its
program object; it's probably most convenient, though, to add it to
the desktop popup menu.  You do this from the "Menu" page of the
desktop settings notebook.  Click on the entry "Primary pop-up menu"
from the "Available Menus" list on that page; then, underneath that
list, there's another list titled "Actions on menu", with a few buttons
to the right of it.  Click on the button that says "Create another".

LOWER is public domain.  I have included the complete source code in
this distribution.

OS/2 and Presentation Manager are trademarks of IBM.
