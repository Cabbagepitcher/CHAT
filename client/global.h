#ifndef GLOBAL_H
#define GLOBAL_H
#include <QWidget>
#include <functional>
#include "QStyle"
#include <memory>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QDir>
#include <QSettings>
/**
 * @brief repolish用来根据属性刷新qss
 */
extern std::function<void(QWidget*)> repolish;
/**
 * @brief The ReqId enum 表示请求的id
 */

extern std::function<QString(QString)> xorString;

enum ReqId{
    ID_GET_VARIFY_CODE = 1001, //获取验证码
    ID_REG_USER = 1002, //注册用户
    ID_RESET_PWD = 1003, //重置密码
    ID_LOGIN_USER = 1004, //用户登录
    ID_CHAT_LOGIN = 1005, //登陆聊天服务器
    ID_CHAT_LOGIN_RSP= 1006, //登陆聊天服务器回包
};

enum ErrorCodes{
    SUCCESS = 0,
    ERR_JSON = 1, //Json解析失败
    ERR_NETWORK = 2,
};

enum Modules{
    REGISTERMOD = 0,
    RESETMOD = 1,
    LOGINMOD = 2,
};
enum TipErr{
    TIP_SUCCESS = 0,//表示操作成功
    TIP_EMAIL_ERR = 1,//验证电子邮件地址时发生错误
    TIP_PWD_ERR = 2,// 表示在验证密码时发生错误
    TIP_CONFIRM_ERR = 3,//表示在验证确认码时发生错误
    TIP_PWD_CONFIRM = 4,//表示在 确认密码，密码一致性时发生错误
    TIP_VARIFY_ERR = 5,//表示验证码为空
    TIP_USER_ERR = 6//表示在处理用户信息时发生错误
};

enum ClickLbState{
    Normal = 0,    //闭眼
    Selected = 1   //睁眼
};

struct ServerInfo{
    QString Host;
    QString Port;
    QString Token;
    int Uid;
};

extern QString gate_url_prefix;

enum ChatUIMode{
    SearchMode,//搜索模式
    ChatMode,//聊天模式
    ContactMode,//联系模式
};

//自定义QListWidgetItem的几种类型
enum ListItemType{
    CHAT_USER_ITEM, //聊天用户
    CONTACT_USER_ITEM, //联系人用户
    SEARCH_USER_ITEM, //搜索到的用户
    ADD_USER_TIP_ITEM, //提示添加用户
    INVALID_ITEM,  //不可点击条目
    GROUP_TIP_ITEM, //分组提示条目
    LINE_ITEM,  //分割线
    APPLY_FRIEND_ITEM, //好友申请
};

enum class ChatRole{
    Self,
    Other
};
struct MsgInfo{
    QString msgFlag;//"text,image,file"
    QString content;//表示文件和图像的url,文本信息
    QPixmap pixmap;//文件和图片的缩略图
};

const std::vector<QString> heads = {
    ":/res/head_1.png",
    ":/res/head_2.png",
    ":/res/head_3.png",
    ":/res/head_4.png",
    ":/res/head_5.png"
};

const std::vector<QString> names = {
    "HanMeiMei",
    "Lily",
    "Ben",
    "Androw",
    "Max",
    "Summer",
    "Candy",
    "Hunter"
};

const std::vector<QString>  strs ={"hello world !",
                                   "nice to meet u",
                                   "New year，new life",
                                   "You have to love yourself",
                                   "My love is written in the wind ever since the whole world is you"};

//申请好友标签输入框最低长度
const int MIN_APPLY_LABEL_ED_LEN = 40;

const QString add_prefix = "添加标签 ";

const int  tip_offset = 5;
#endif // GLOBAL_H
