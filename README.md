# Biblioteca-AEDs

Trabalho de Algoritmo e Estrutura de Dados (3º Período)
CEFET started to rebuild its library collection, and for the virtual management of the library it was decided to select a student of Computer Engineering to create a new management software.
to select a student of Computer Engineering to create a new management software. At
At the time of the selection, you were lucky enough to be chosen to develop this software. Now the CEFET
Now the CEFET library is in your hands, and it is up to you to bring it back to its former glory!
Your supervisors have sent you a set of specifications to be followed. These specifications detail
the functionality that the management software must have to accommodate the needs of the library:

1) Student Management: students who wish to perform activities in the library can have their registration
their registration. The registration consists of the student's name and registration (made up of numbers and letters), as well as an ID generated by the library.
an ID generated by the library. It should be possible to add and remove enrollments, as well as list all the
enrollments, and also search for a student's enrollment based on his/her ID. It should not be possible to remove the enrollment
of a student who has some pending issue with the library (borrowed something and has not yet returned it);

2) Book management: the library also has a physical book collection. To manage this collection
A digital registry of these books is required. The books have name, year of publication, category and an ID
generated by the library. It must be possible to add and remove books from this registry, as well as list all
the books, and also search the books by ID and by category. Another necessary functionality is the borrowing
of books. In book lending, it must be possible for students to borrow and return a book,
changing its status. To do this, the book record must also contain a status (available or borrowed),
as well as a student ID assigned to the book if the state is borrowed. Remember that this
information should also appear in the list or search of the books, but instead of the student's ID, the student's enrollment should be shown.
instead of the student's ID, the student's enrollment number should be shown. It should also not be possible to remove the record of a book that has not yet been
returned;

3) Managing Rooms, Computers and Lockers: some library rooms, computers and lockers can be lent to students. As the library infrastructure may change (new rooms may be built, computers
(new rooms may be built, computers may break down, etc.) so there must be a record for these resources. A resource
has a manually entered ID, a type (room, computer, or locker), a state (free or occupied), and a student
a student ID assigned to the resource if it is occupied. It should be possible to add, remove and list
these resources, as well as search for them by ID. It must also be possible for students to occupy or unoccupy these
resources, changing their state. It should not be possible to remove a resource that is already occupied. Remember that
in the list or search, the registration number of the student who is occupying the resource must be shown instead of the ID of that
student's ID;

4) Exporting/importing data (bonus worth 0.5 points): it would be interesting if the information created during use were stored when the system was closed (export) and retrieved the next time it was started (import). In addition, to prevent the data from being viewed by third parties if it is lost, by
store the information, it must be encrypted and, in turn, decrypted when importing the data
data;

5) UI (bonus worth 0.5 points): it is desirable, and was requested by the managers, that a graphical interface be developed to make the use of the system more friendly.
It is worth remembering that the management software is used by the library staff, that is, the students do not interact directly with it.
interact directly with it. The listing and search of the elements must show all the information
information about each element. The software must be developed in C language and have a command line interface.
In case of implementation of item 5, all the source code (including the UI) can be implemented in C++.
1 of 2

Translated with www.DeepL.com/Translator (free version)