#ifndef TCPMGR_H
#define TCPMGR_H
#include <QTcpSocket>
#include "singleton.h"
#include "global.h"
#include <functional>
#include <QObject>
#include"userdata.h"
class TcpMgr:public QObject, public Singleton<TcpMgr>,
               public std::enable_shared_from_this<TcpMgr>
{
    Q_OBJECT
public:
    ~ TcpMgr();
private:
    friend class Singleton<TcpMgr>;
    TcpMgr();
    void initHandlers();//注册回调 的处理
    void handleMsg(ReqId id, int len, QByteArray data);
    QTcpSocket _socket;
    QString _host;
    uint16_t _port;
    QByteArray _buffer;//收到数据缓存池
    bool _b_recv_pending;//数据完整校验位   true->不完整
    quint16 _message_id;
    quint16 _message_len;
    QMap<ReqId, std::function<void(ReqId id, int len, QByteArray data)>> _handlers;
public slots:
    void slot_tcp_connect(ServerInfo);//回调，连接成功触发
    void slot_send_data(ReqId reqId, QString data);//发送成功调用
signals:
    void sig_con_success(bool bsuccess);//连接成功
    void sig_send_data(ReqId reqId, QString data);//阻塞信号
    void sig_swich_chatdlg();//登陆切换聊天信号
    void sig_login_failed(int);//登陆失败信号

    void sig_user_search(std::shared_ptr<SearchInfo>);
};

#endif // TCPMGR_H
