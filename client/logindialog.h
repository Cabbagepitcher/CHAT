#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "global.h"
namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private:
    void initHead();
    Ui::LoginDialog *ui;

    bool checkUserValid();//检测账号
    bool checkPwdValid();//检测密码

    void AddTipErr(TipErr te,QString);
    void DelTipErr(TipErr te);

    QMap<TipErr,QString> _tip_errs;
    void showTip(QString str,bool b_ok);
    bool enableBtn(bool enable);

    void initHttpHandlers();
    QMap<ReqId,std::function<void(const QJsonObject&)>> _handlers;
    int _uid;
    QString _token;
public slots:
    void slot_forget_pwd();
signals:
    void switchRegister();
    void switchReset();//忘记密码信号

    void sig_connect_tcp(ServerInfo);//长连接
private slots:
    void on_login_btn_clicked();

    void slot_login_mod_finish(ReqId id, QString res, ErrorCodes err);//登陆

    void slot_tcp_con_finish(bool bsuccess);
    void slot_login_failed(int);
};

#endif // LOGINDIALOG_H
