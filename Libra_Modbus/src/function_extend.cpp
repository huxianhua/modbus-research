#include "function_extend.h"

#include <QUrl>
#include <QAction>
#include <QStyleFactory>
#include <QQuickWidget>

#include <QQuickItem>


#include "app_config.h"
#include "QsLog.h"

//温度表控件
#include "thermometer.h"
//气压表控件
#include "manometer.h"


Function_Extend::Function_Extend(QObject *parent) : QObject(parent)
{

}
void Function_Extend::set_settings(ModbusCommSettings *settings)
{
    m_modbusCommSettings = settings;
    //Logging level
    QsLogging::Logger::instance().setLoggingLevel((QsLogging::Level)m_modbusCommSettings->loggingLevel());
    QLOG_INFO()<<  "Start Program" ;
}

void Function_Extend::set_default_font()
{
    QFont font;
    font.setPointSize(10);
#if  1
    font.setFamily("Microsoft YaHei"); //微软雅黑
#else
    font.setFamily("MS Shell Dlg 2"); // Tahoma 宋体
#endif
    qApp->setFont(font);
}

void Function_Extend::set_default_style()
{
#if defined(Q_OS_WIN32)
    QApplication::setStyle(QStyleFactory::create("Fusion")); //Windows , Fusion ,Macintosh
#endif
}

void Function_Extend::add_os_style(QMenuBar *menubar,QToolBar *toolbar)
{
    QStringList style_name_list = QStyleFactory::keys();

    int list_line = style_name_list.length();

    QMenu *style = menubar->addMenu("style");


    QAction *action;
    for(int index = 0; index < list_line; index++)
    {
        action = new QAction(style_name_list.at(index));
        action->setObjectName(style_name_list.at(index));
        style->addAction(action);
        connect(action,SIGNAL(triggered()),this,SLOT(s_changeStyle()));

        toolbar->addAction(action);
    }
}
void Function_Extend::s_changeStyle()
{
    QLOG_INFO();
    QLOG_INFO();

    qDebug("[%s %s %d]",__FUNCTION__,__FUNCTION__,__LINE__);

    QAction *style = qobject_cast<QAction *>(sender());

    style->setChecked(true);

    QLOG_INFO() << style->objectName();

    QApplication::setStyle(QStyleFactory::create(style->objectName()));

}

#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>

void Function_Extend::add_tab_widget_content(QTabWidget *tabWidget)
{
    tabWidget->setTabText(0,"零点标定");
    tabWidget->setTabText(1,"累积量设置");
    tabWidget->setTabText(2,"主要变量监测");

    tabWidget->addTab(new QWidget(),"参考变量监测");
    tabWidget->addTab(new QWidget(),"设备状态监测");
    tabWidget->addTab(new QWidget(),"设备操作");

    ThermoMeter *thermo = new ThermoMeter();
    QHBoxLayout *hboxlayout = new QHBoxLayout();
    hboxlayout->addWidget(new QPushButton(DATETIME));
    hboxlayout->addWidget(thermo);
    tabWidget->widget(1)->setLayout(hboxlayout);


    ManoMeter *bar = new ManoMeter();

    bar->setValue(88);

    QHBoxLayout *hboxlayout2 = new QHBoxLayout();
    hboxlayout2->addWidget(new QPushButton(DATETIME));
    hboxlayout2->addWidget(bar);
    tabWidget->widget(2)->setLayout(hboxlayout2);

    QQuickWidget *quickWidget = new QQuickWidget();
    QUrl url("qrc:/qml/resource/qml/main.qml");


    quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

    quickWidget->setSource(url);
    QHBoxLayout *hboxlayout3 = new QHBoxLayout();
    //hboxlayout3->addWidget(new QPushButton(DATETIME));
    hboxlayout3->addWidget(quickWidget);
    tabWidget->widget(3)->setLayout(hboxlayout3);


    QQuickItem *item = quickWidget->rootObject();
    QString name = item->objectName();

    connect(quickWidget->rootObject(),SIGNAL(sig_test()),qApp,SLOT(quit()));

    connect(this,SIGNAL(sig_init(QString)),quickWidget->rootObject(),SIGNAL(signal_init(QString)));

    emit sig_init("xxxxx");

    tabWidget->setCurrentIndex(3);

}
