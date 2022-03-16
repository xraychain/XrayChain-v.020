#ifndef XRAYPUSHBUTTON_H
#define XRAYPUSHBUTTON_H
#include <QPushButton>
#include <QStyleOptionButton>
#include <QIcon>

class XrayPushButton : public QPushButton
{
public:
    explicit XrayPushButton(QWidget * parent = Q_NULLPTR);
    explicit XrayPushButton(const QString &text, QWidget *parent = Q_NULLPTR);

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private:
    void updateIcon(QStyleOptionButton &pushbutton);

private:
    bool m_iconCached;
    QIcon m_downIcon;
};

#endif // XRAYPUSHBUTTON_H
