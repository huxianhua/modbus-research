#ifndef MODBUSADAPTER_H
#define MODBUSADAPTER_H



#include <QObject>
#include "modbus.h"
#include "registersmodel.h"
#include "rawdatamodel.h"
#include <QTimer>
#include "eutils.h"
#include "infobar.h"

/**
 * @brief The ModbusAdapter class
 *          对 libmodbus 的封装
 */
class ModbusAdapter : public QObject
{
    Q_OBJECT
public:
    explicit ModbusAdapter(QObject *parent = 0);

     void busMonitorRequestData(uint8_t * data,uint8_t dataLen);
     void busMonitorResponseData(uint8_t * data,uint8_t dataLen);

     // //modbus_new_rtu("/dev/ttyUSB0", 115200, 'N', 8, 1);
     /**
      * @brief modbusConnectRTU  RTU 连接
      * @param port         linux (/dev/ttyUSB0)  windows (com3)
      * @param baud         波特率 9600, 19200, 57600, 115200, etc
      * @param parity       奇偶    无 奇 偶  'N', 'O', 'E'
      * @param dataBits     数据位数  7 ， 8
      * @param stopBits     停止位数   1  1.5  2
      * @param RTS          RTS    None Up Down
      * @param timeOut      响应时间 ,默认为 1s
      */
     void modbusConnectRTU(QString port, int baud, QChar parity, int dataBits, int stopBits, int RTS, int timeOut=1);
     void modbusConnectTCP(QString ip, int port, int timeOut=1);
     void modbusDisConnect();
     RegistersModel *regModel;
     RawDataModel *rawModel;
     bool isConnected();

     void setSlave(int slave);
     void setFunctionCode(int functionCode);
     void setStartAddr(int addr);
     void setNumOfRegs(int num);
     void addItems();

     void setScanRate(int scanRate);
     void setTimeOut(int timeOut);
     void startPollTimer();
     void stopPollTimer();
     int packets();
     int errors();

     QVariantMap modbusReadData_simple(int slave, int functionCode, int startAddress, int noOfItems);
     //void modbusWriteData__simple(int slave, int functionCode, int startAddress, int noOfItems);

private:
     void modbusReadData(int slave, int functionCode, int startAddress, int noOfItems);
     void modbusWriteData(int slave, int functionCode, int startAddress, int noOfItems);




     QString stripIP(QString ip);
     modbus_t * m_modbus;
     bool m_connected;
     int m_ModBusMode;
     int m_slave;
     int m_functionCode;
     int m_startAddr;
     int m_numOfRegs;
     int m_scanRate;
     QTimer *m_pollTimer;
     int m_packets;
     int m_errors;
     int m_timeOut;
     bool m_transactionIsPending;

     QVariantMap m_result;

signals:
    void refreshView();

    /**
     * @brief sig_send_info
     * @param info              当发送 hide 时 就调用 mainWin->hideInfoBar();
     * @param type
     */
    void sig_send_info(QString info,InfoBar::InfoType type);


public slots:
    void modbusTransaction();
    void resetCounters();

};

#endif // MODBUSADAPTER_H
