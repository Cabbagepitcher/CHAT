正则表达式邮箱验证
单例基类HTTP
boost库jsoncpp

计算机项目--》》手动启动MySQL

15

也可以用命令行直接开启mysql：

```sql
# 管理员模式
net start mysql
net stop mysql

# 检查启动
sc query "MySQL"
```

若出现`the user specified as a definer ('root'@'%') does not exist`等类似错误，是因为没有允许远程访问。可以执行下面的sql语句（适用于mysql8以上）

```sql
mysql> create user 'root'@'%' identified by '密码';
Query OK, 0 rows affected (2.35 sec)
 
mysql> grant all privileges on *.* to 'root'@'%';
Query OK, 0 rows affected (0.06 sec)
 
mysql> flush privileges;
Query OK, 0 rows affected (0.06 sec)
```