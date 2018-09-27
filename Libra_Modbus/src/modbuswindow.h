#ifndef MODBUSWINDOW_H
#define MODBUSWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QLabel>
#include <QString>
#include <QProcess>
#include <QDockWidget>

#include "about.h"
#include "settingsmodbusrtu.h"
#include "settingsmodbustcp.h"
#include "settings.h"
#include "busmonitor.h"
#include "modbuscommsettings.h"
#include "modbusadapter.h"
#include "infobar.h"

#include "function_extend.h"

namespace Ui {
    class ModbusWindow;
}

class ModbusWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModbusWindow(QWidget *parent = 0, ModbusAdapter *adapter = 0, ModbusCommSettings *settings = 0,Function_Extend *m_extend = 0);
    ~ModbusWindow();
    void showUpInfoBar(QString message, InfoBar::InfoType type);
    void hideInfoBar();

private:
    Ui::ModbusWindow *ui;
    //UI - Dialogs
    About *m_dlgAbout;
    SettingsModbusRTU *m_dlgModbusRTU;
    SettingsModbusTCP *m_dlgModbusTCP;
    Settings *m_dlgSettings;
    BusMonitor *m_busMonitor;


    ModbusCommSettings *m_modbusCommSettings;
    void updateStatusBar();
    QLabel *m_statusText;
    QLabel *m_statusInd;
    QLabel *m_baseAddr;
    QLabel *m_statusPackets;
    QLabel *m_statusErrors;
    ModbusAdapter *m_modbus;

    //功能扩展
    Function_Extend *m_extend;

    QDockWidget *m_dock;

    void modbusConnect(bool connect);

    void changeEvent(QEvent* event);


    void readModbus(int slave, int functionCode, int startAddress, int noOfItems);


    void initExtend();

private slots:
    void showSettingsModbusRTU();
    void showSettingsModbusTCP();
    void showSettings();
    void showBusMonitor();
    void changedModbusMode(int currIndex);
    void changedFunctionCode(int currIndex);
    void changedBase(int currIndex);
    void changedStartAddrBase(int currIndex);
    void changedScanRate(int value);
    void changedConnect(bool value);
    void changedStartAddress(int value);
    void changedNoOfRegs(int value);
    void changedSlaveID(int value);
    void addItems();
    void clearItems();
    void openLogFile();
    void scan(bool value);
    void request();
    void refreshView();
    void changeLanguage();
    void openModbusManual();
    void loadSession();
    void saveSession();

    void s_showUpInfoBar(QString message, InfoBar::InfoType type);


private slots:
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


signals:
    void resetCounters();



};

extern ModbusWindow *modbuswindow;

#endif // MAINWINDOW_H
