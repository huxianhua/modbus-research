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
//    explicit Function_Extend(QObject *parent = 0);
     Function_Extend(QWidget *parent = 0, ModbusAdapter *adapter = 0, ModbusCommSettings *settings = 0);


//    static Function_Extend &instaned()
//    {
//        static Function_Extend qinstance;
//        return qinstance;
//    }


    void set_default_font();
    void set_default_style();

    void add_os_style(QMenuBar *menubar,QToolBar *toolbar);

    void add_tab_widget_content(QTabWidget *tabWidget);


    void setModbusPara(int slave, int functionCode, int startAddress);


private:
    void readModbus(int slave, int functionCode, int startAddress,int noOfItems);


private:
    ModbusCommSettings *m_modbusCommSettings;
    ModbusAdapter *m_modbus;

    int m_slave;
    int m_functionCode;
    int m_startAddress;

signals:
    void sig_init(QString text);

private slots:
    void s_changeStyle();
    //零点标定
    // R 0x01 D 2000(0x7D0)

    /**
     * @brief s_zeroCalibration_1a
     *
     * R 0x01 D 2000(0x7D0)
     * 返回值 0: 零点标定没有运行 或 零点标定没有成功
     *       1: 零点标定正在运行中
     */
    void s_zeroCalibration_1a();
    void s_zeroCalibration_2a();
    void s_zeroCalibration_3a();
    void s_zeroCalibration_4a();
    void s_zeroCalibration_5a();


};

#endif // FUNCTION_EXTEND_H

