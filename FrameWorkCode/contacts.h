#ifndef CONTACTS_H
#define CONTACTS_H


#include <QDialog>

namespace Ui {
class ContactUsDialog;
}

class ContactUsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ContactUsDialog(QWidget *parent = nullptr);
    ~ContactUsDialog();

private:
    Ui::ContactUsDialog *ui;
    QString list ="#### \n"
                  "Udaan tool developers can be reached at the udaan tool mailing list:\n"
                  "#### \t"
                  "hussainganie388@gmail.com\n"

                  "or the udaan tool managing team:\n"
                "#### \t"
                        "udaanprojectiitb@gmail.com ,"
                        " akshayj@iitb.ac.in\n"
                  "Contact us at "
                    "(+91) 9769525019 / 8369549390 / 8369370502 \n"
                    "\n"
                    "You can also chat with us at: [919769525019](https://api.whatsapp.com/send/?phone=919769525019) ,  [918369549390](https://api.whatsapp.com/send/?phone=918369549390) , [918369370502](https://api.whatsapp.com/send/?phone=918369370502) \n";;

};
#endif // CONTACTS_H
