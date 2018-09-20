#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QLabel>
#include <QString>
#include <QProcess>

#include "about.h"
#include "settingsmodbusrtu.h"
#include "settingsmodbustcp.h"
#include "settings.h"
#include "busmonitor.h"
#include "modbuscommsettings.h"
#include "modbusadapter.h"
#include "infobar.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, ModbusAdapter *adapter = 0, ModbusCommSettings *settings = 0);
    ~MainWindow();
    void showUpInfoBar(QString message, InfoBar::InfoType type);
    void hideInfoBar();

private:
    Ui::MainWindow *ui;
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
    void modbusConnect(bool connect);

    void changeEvent(QEvent* event);

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

signals:
    void resetCounters();

};

extern MainWindow *mainWin;

#endif // MAINWINDOW_H
