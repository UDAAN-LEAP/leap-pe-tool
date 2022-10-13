
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
+++++++++++++++++++++++++++++++++++++++++++++++++++

 **Inputs :** Reference of QString object.

 **Return type :** void.

 **Function :** 
  ==> This function will complete the words and will insert the word in the current cursor position.
  
  
void MainWindow::mousePressEvent(QMouseEvent *) 
+++++++++++++++++++++++++++++++++++++++++++++++++++

 **Inputs :** pointer to a object of QMouseEvent class

 **Return type :** Void

 **Function :**

 ==> This function is responsible for handling the right click and the menu after clicking the right click.

 ==> At first it will check if the right click event has occured or not.

 ==> It will also check if any text is selected or not an according to that it will show the menu bar.


void MainWindow::insertImageAction()
+++++++++++++++++++++++++++++++++++++

 **Inputs :** Void

 **Return type :** Void

 **Function :**

 ==> This function is responsible for inserting local images in the text.

 ==> It will take the image from the chosen directory and will copy it a specific folder. 

 ==> After that it will insert that image in the current cursor position.


void MainWindow::on_actionResize_Image_triggered()
++++++++++++++++++++++++++++++++++++++++++++++++++

 **Inputs :** Void

 **Return type :** Void

 **Function :**

 ==> This function resizes the images in the document. 
 
 ==> User has to input the new height or width and thus the image is appropriately resized.


void MainWindow::globalReplacePreviewfn(QMap <QString, QString> , QVector<int> )
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 **Inputs :** A object of QMap <QString, QString> and object QVector<int>

 **Return type :** Void

 **Function :**

 ==> This feature allows user to view the changes in advance that are going to be done by global replace and provide check boxes to make the desired     changes 

 


