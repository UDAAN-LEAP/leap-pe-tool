
Welcome to OpenOCRCorrect Documentation
=======================================

A framework for assisting human while correcting the OCR errors in documents, mostly dedicated to Indian Languages. Tested on Sanskrit, Hindi, Marathi and English.

**Use of the different classes and their functions**
================================================

CustomTextBrowser::modelFromFile()
++++++++++++++++++++++++++++++++++

**Inputs :** Reference of QString object which will provide the file name.

**Return type :** A pointer variable of QAbstractItemModel class object.

**Function :** It will create a qabstractmodel from the file given to it as the formal argument. And after that it will return the adress of that qabstractmodel.
