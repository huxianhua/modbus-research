#ifndef FUNCTION_EXTEND_H
#define FUNCTION_EXTEND_H

#include <QObject>
#include <QMenuBar>
#include <QToolBar>
#include <QTabWidget>

#include "modbuscommsettings.h"


#include "settingsmodbusrtu.h"
#include "settingsmodbustcp.h"
#include "settings.h"
#include "busmonitor.h"
#include "modbusadapter.h"


class Function_Extend : public QObject
{
    Q_OBJECT
public:
    explicit Function_Extend(QObject *parent = 0);

   // explicit Function_Extend(QWidget *parent = 0, ModbusAdapter *adapter = 0, ModbusCommSettings *settings = 0);


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


    ModbusCommSettings *m_modbusCommSettings;

signals:
    void sig_init(QString text);

private slots:
    void s_changeStyle();
};

#endif // FUNCTION_EXTEND_H

