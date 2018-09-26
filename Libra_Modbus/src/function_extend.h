#ifndef FUNCTION_EXTEND_H
#define FUNCTION_EXTEND_H

#include <QObject>
#include <QMenuBar>
#include <QToolBar>
#include <QTabWidget>

#include "modbuscommsettings.h"

class Function_Extend : public QObject
{
    Q_OBJECT
public:
    explicit Function_Extend(QObject *parent = 0);
    static Function_Extend &instaned()
    {
        static Function_Extend qinstance;
        return qinstance;
    }

    void set_settings(ModbusCommSettings *settings);

    void set_default_font();
    void set_default_style();

    void add_os_style(QMenuBar *menubar,QToolBar *toolbar);

    void add_tab_widget_content(QTabWidget *tabWidget);



private:

    Function_Extend(const Function_Extend&){}
    Function_Extend& operator == (const Function_Extend&){}


    ModbusCommSettings *m_modbusCommSettings;

signals:
    void sig_init(QString text);

private slots:
    void s_changeStyle();
};

#endif // FUNCTION_EXTEND_H

