常见算法题总结
1：字符串相关算法：
  KMP
2：整数处理相关算法
3：动态规划
4：贪婪算法
5：排序算法总结
6：图论相关
   DFS
   BFS
7：树相关算法
8：链表相关

Mysql 数据库：
    基本操作
      create database db_name; 
      show create database db_name'
      use db_name;
      drop database db_name;
    MyISAM和InnoDB存储引擎
      show engines;支持的有8种。从5.5版本开始，默认支持InnoDB。
      
      InnoDB  需要大量Insert delete update时
        InnoDB是事务安全的，如果表主要提供OLTP
        联机事务处理OLTP（on-line transaction processing）
        联机分析处理OLAP（On-Line Analytica Processing）。
        OLTP是传统的关系型数据库的主要应用，主要是基本的、日常的事务处理，例如银行交易。
        OLAP是数据仓库系统的主要应用，支持复杂的分析操作，侧重决策支持，并且提供直观易懂的查询结果      
        支持外键
      MyISAM 不是事务安全的，也不支持外键。需要大量select是使用
    use choose;
    set default_storage_engine=InnoDB;
    create table my_table(
    taday datetime;
    name char(20);)
    
    显示表结构：
      show tables;
      describle table_name;
    
      show create table table_name;查看详细信息   字段名 数据类型 约束条件 存储引擎 默认字符集等
      
      
    
        
      
