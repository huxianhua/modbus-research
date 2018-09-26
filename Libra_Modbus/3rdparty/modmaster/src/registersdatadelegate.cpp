#include "registersdatadelegate.h"
#include "mainwindow.h"
#include "QsLog.h"
#include <QtDebug>
#include <QPainter>
#include <QSpinBox>
#include <QLineEdit>

#include "eutils.h"

void RegistersDataDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const
{

    QStyledItemDelegate::paint(painter, option, index);

}

QWidget *RegistersDataDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{

    if (m_base == 2) {//Bin
            if (m_is16Bit) {
                //16位 二进制 如  0000 0000 0000 0000
                QLineEdit *editor = new QLineEdit(parent);
                editor->setInputMask("bbbbbbbbbbbbbbbb");
                return editor;
            }
            else {
                //单位 二进制
                QSpinBox *editor = new QSpinBox(parent);
                editor->setMinimum(0);
                editor->setMaximum(1);
                return editor;
            }
    }
    else if (m_base == 10) {//Dec
            QLineEdit *editor = new QLineEdit(parent);
            //匹配 0个或1个负号， 0 ~ 9 的数字，长度为 1 ~ 5 位
            QRegExp rx("-{0,1}[0-9]{1,5}");
            QValidator *validator = new QRegExpValidator(rx);
            editor->setValidator(validator);
            return editor;
    }
    else if (m_base == 16) {//Hex
            QLineEdit *editor = new QLineEdit(parent);
            //Hexadecimal character required. A-F, a-f, 0-9.
            editor->setInputMask("hhhh");
            return editor;
    }
    else {//Default = Dec  默认使用 十进制
            QLineEdit *editor = new QLineEdit(parent);
            QRegExp rx("-{0,1}[0-9]{1,5}");
            QValidator *validator = new QRegExpValidator(rx);
            editor->setValidator(validator);
            return editor;
    }

}

void RegistersDataDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{

    QString value = index.model()->data(index, Qt::EditRole).toString();

    if (m_base == 2 && !m_is16Bit) {//Bin
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        spinBox->setValue(value.toInt());
    }
    else { //Bin 16 Bit, Dec, Hex
        QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
        lineEdit->setText(value);
    }
}

void RegistersDataDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex &index) const
{

    QString value;
    int intVal;
    bool ok;

    if (m_base == 2 && !m_is16Bit) {//Bin
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        intVal = (spinBox->text()).toInt(&ok,m_base);
        value = EUtils::formatValue(intVal, m_frmt, m_is16Bit);
    }
    else { //Bin 16 Bit,Dec, Hex
        QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
        intVal = (lineEdit->text()).toInt(&ok,m_base);
        if (intVal > 65535){
            //emit this->sig_send_info(tr("Set value failed\nValue is greater than 65535."), InfoBar::Error);

            QLOG_WARN() <<  "Set value failed. Value is greater than 65535";
            return;
        }
        else if (intVal < -32768){
            //emit sig_send_info(tr("Set value failed\nValue is smaller than -32768."), InfoBar::Error);
            //this->send_log("",InfoBar::Error);

            QLOG_WARN() <<  "Set value failed. Value is smaller than -32768";
            return;
        }
        else
        {
            mainWin->hideInfoBar();
        }
        value = EUtils::formatValue(intVal, m_frmt, m_is16Bit);
    }

    QLOG_TRACE() <<  "Set model data value = " << value;

    model->setData(index, value, Qt::EditRole);
}

void RegistersDataDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}

void RegistersDataDelegate::setBase(int frmt)
{

    m_base = frmt;
    m_frmt = frmt;

}

void RegistersDataDelegate::setIs16Bit(bool is16Bit)
{

    m_is16Bit = is16Bit;

}

