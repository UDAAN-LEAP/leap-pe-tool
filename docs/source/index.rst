
Welcome to OpenOCRCorrect Documentation
=======================================

A framework for assisting human while correcting the OCR errors in documents, mostly dedicated to Indian Languages. Tested on Sanskrit, Hindi, Marathi and English.

**Use of the different classes and their functions**
================================================

QAbstractItemModel* CustomTextBrowser::modelFromFile(QString &)
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 **Inputs :** Reference of QString object which will provide the file name.

 **Return type :** A pointer variable of QAbstractItemModel class object.

 **Function :** 
 
 ==> It will create a qabstractmodel from the file given to it as the formal argument. And after that it will return the adress of that qabstractmodel.

void CustomTextBrowser::keyPressEvent(QKeyEvent* )
++++++++++++++++++++++++++++++++++++++++++++++++++++

 **Inputs :** Address of a QKeyEvent.

 **Return type :** Void.

 **Function :**

 ==> It will detect the type of the key pressed.

 ==> The text under the cursor will be also be detected here.

 ==> English model and Sanskrit model will be set to the completer.

QString CustomTextBrowser::textUnderCursor()
+++++++++++++++++++++++++++++++++++++++++++++++++++
 
 **Inputs :** Void.

 **Return type :** QString.

 **Function :** 
 
 ==>It will give us the text under the cursor.
 
void CustomTextBrowser::insertCompletion(QString &)
++++++++++++++++++++++++++++++++++++++++++++++++++++

 **Inputs :** Reference of QString object.

 **Return type :** void.

 **Function :** 
  ==> This function will complete the words and will insert the word in the current cursor position.
