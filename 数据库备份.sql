/*
SQLyog Ultimate v12.09 (64 bit)
MySQL - 8.3.0 : Database - 餐管信息管理系统
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
CREATE DATABASE /*!32312 IF NOT EXISTS*/`餐管信息管理系统` /*!40100 DEFAULT CHARACTER SET utf8mb3 */ /*!80016 DEFAULT ENCRYPTION='N' */;

USE `餐管信息管理系统`;

/*Table structure for table `收银记录` */

DROP TABLE IF EXISTS `收银记录`;

CREATE TABLE `收银记录` (
  `来客_日期` date NOT NULL,
  `来客_编号` int NOT NULL,
  `时间` time NOT NULL,
  `金额` float NOT NULL,
  `支付方式` varchar(16) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  PRIMARY KEY (`来客_日期`,`来客_编号`,`时间`),
  CONSTRAINT `收银记录_ibfk_1` FOREIGN KEY (`来客_日期`, `来客_编号`) REFERENCES `来客` (`日期`, `编号`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

/*Data for the table `收银记录` */

insert  into `收银记录`(`来客_日期`,`来客_编号`,`时间`,`金额`,`支付方式`) values ('2024-03-23',1,'11:20:48',16,'微信支付');

/*Table structure for table `来客` */

DROP TABLE IF EXISTS `来客`;

CREATE TABLE `来客` (
  `日期` date NOT NULL,
  `编号` int NOT NULL,
  `人数` tinyint NOT NULL,
  `座位数要求` tinyint NOT NULL,
  `排队时间` time DEFAULT NULL,
  `入座时间` time DEFAULT NULL,
  `桌号` char(5) DEFAULT NULL,
  PRIMARY KEY (`日期`,`编号`),
  KEY `桌号` (`桌号`),
  CONSTRAINT `来客_ibfk_1` FOREIGN KEY (`桌号`) REFERENCES `餐桌` (`桌号`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

/*Data for the table `来客` */

insert  into `来客`(`日期`,`编号`,`人数`,`座位数要求`,`排队时间`,`入座时间`,`桌号`) values ('2024-03-17',1,2,2,'00:36:00',NULL,NULL),('2024-03-17',2,2,2,'00:37:09',NULL,NULL),('2024-03-17',3,3,4,'00:37:59',NULL,NULL),('2024-03-18',1,2,8,'00:46:20',NULL,NULL),('2024-03-22',1,3,4,'15:28:41','15:41:59','A1'),('2024-03-23',1,2,2,'11:18:48','11:19:09','A1');

/*Table structure for table `点菜记录` */

DROP TABLE IF EXISTS `点菜记录`;

CREATE TABLE `点菜记录` (
  `来客_日期` date NOT NULL,
  `桌号` char(5) NOT NULL,
  `客户点菜编号` int NOT NULL,
  `来客_编号` int NOT NULL,
  `菜名` varchar(32) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `时间` time NOT NULL,
  `状态` varchar(5) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  PRIMARY KEY (`来客_日期`,`客户点菜编号`),
  KEY `来客_日期` (`来客_日期`,`来客_编号`),
  KEY `菜名` (`菜名`),
  CONSTRAINT `点菜记录_ibfk_1` FOREIGN KEY (`来客_日期`, `来客_编号`) REFERENCES `来客` (`日期`, `编号`) ON UPDATE CASCADE,
  CONSTRAINT `点菜记录_ibfk_2` FOREIGN KEY (`菜名`) REFERENCES `菜品` (`菜名`) ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

/*Data for the table `点菜记录` */

insert  into `点菜记录`(`来客_日期`,`桌号`,`客户点菜编号`,`来客_编号`,`菜名`,`时间`,`状态`) values ('2024-03-22','A1',1,1,'土豆丝','15:50:53','已上菜'),('2024-03-23','A1',1,1,'土豆丝','11:19:54','已上菜');

/*Table structure for table `菜品` */

DROP TABLE IF EXISTS `菜品`;

CREATE TABLE `菜品` (
  `菜名` varchar(32) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `价格` float NOT NULL,
  `折扣` float NOT NULL,
  `材料` varchar(32) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `类型` varchar(32) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  PRIMARY KEY (`菜名`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

/*Data for the table `菜品` */

insert  into `菜品`(`菜名`,`价格`,`折扣`,`材料`,`类型`) values ('土豆丝',20,0.8,'土豆','素菜'),('宫保鸡丁',48,0.9,'鸡肉、花生','川菜'),('梅菜扣肉',58,1,'梅干菜、猪肉','招牌菜'),('清蒸鲈鱼',88,0.95,'鲈鱼','海鲜'),('炒年糕',38,0.9,'年糕、蔬菜','特色小吃'),('炒面',22,0.85,'面条、蔬菜','快餐'),('炒饭',25,0.85,'米饭、蔬菜','快餐'),('炸鸡',48,0.9,'鸡肉、面包糠','小吃'),('番茄炒蛋',25,0.85,'鸡蛋、番茄','简单营养'),('糖醋排骨',58,0.9,'排骨、糖醋','甜酸口味'),('红烧肉',68,1,'五花肉、酱油','经典菜'),('酸菜鱼',68,0.95,'鱼、酸菜','酸辣口味'),('青椒肉丝',45,0.9,'猪肉、青椒','下饭菜'),('鱼香茄子',35,0.85,'茄子、辣椒','家常菜'),('麻婆豆腐',32,0.9,'豆腐、辣椒','麻辣口味');

/*Table structure for table `餐桌` */

DROP TABLE IF EXISTS `餐桌`;

CREATE TABLE `餐桌` (
  `桌号` char(5) NOT NULL,
  `容量` int NOT NULL,
  `状态` varchar(3) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  PRIMARY KEY (`桌号`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

/*Data for the table `餐桌` */

insert  into `餐桌`(`桌号`,`容量`,`状态`) values ('A1',8,'空闲'),('A2',8,'空闲'),('A3',8,'空闲'),('A4',8,'空闲'),('B1',4,'空闲'),('B2',4,'空闲'),('B3',4,'空闲'),('B4',4,'空闲'),('B5',4,'空闲'),('C1',2,'空闲'),('C2',2,'空闲'),('C3',2,'空闲'),('C4',2,'空闲'),('C5',2,'空闲'),('C6',2,'空闲');

/* Trigger structure for table `来客` */

DELIMITER $$

/*!50003 DROP TRIGGER*//*!50032 IF EXISTS */ /*!50003 `来客编号产生` */$$

/*!50003 CREATE */ /*!50017 DEFINER = 'root'@'localhost' */ /*!50003 TRIGGER `来客编号产生` BEFORE INSERT ON `来客` FOR EACH ROW BEGIN 
	DECLARE 当日最大编号 INT;
	SELECT MAX(来客.`编号`) + 1 INTO 当日最大编号 FROM 来客 WHERE 来客.`日期` = CURDATE();
	IF 当日最大编号 IS NULL THEN 
		SET 当日最大编号 = 1;
	END IF;
	SET New.编号 = 当日最大编号;
END */$$


DELIMITER ;

/* Procedure structure for procedure `上菜` */

/*!50003 DROP PROCEDURE IF EXISTS  `上菜` */;

DELIMITER $$

/*!50003 CREATE DEFINER=`root`@`localhost` PROCEDURE `上菜`(
	IN _点菜编号 INT
)
BEGIN
	UPDATE 点菜记录 SET 点菜记录.`状态` = '已上菜' WHERE 点菜记录.`客户点菜编号` = _点菜编号 and 点菜记录.`来客_日期` = curdate();
END */$$
DELIMITER ;

/* Procedure structure for procedure `取消点餐` */

/*!50003 DROP PROCEDURE IF EXISTS  `取消点餐` */;

DELIMITER $$

/*!50003 CREATE DEFINER=`root`@`localhost` PROCEDURE `取消点餐`(
	IN _点菜编号 INT
)
BEGIN
	delete FROM 点菜记录 where 点菜记录.`客户点菜编号` = _点菜编号;
END */$$
DELIMITER ;

/* Procedure structure for procedure `客人上桌` */

/*!50003 DROP PROCEDURE IF EXISTS  `客人上桌` */;

DELIMITER $$

/*!50003 CREATE DEFINER=`root`@`localhost` PROCEDURE `客人上桌`(
	IN _来客编号 INT,
	IN _桌号 CHAR(5)
)
BEGIN
	UPDATE 来客 SET 来客.`入座时间` = CURTIME(),来客.`桌号` = _桌号 WHERE 来客.`编号` = _来客编号 AND 来客.`日期` = CURDATE();
	UPDATE 餐桌 SET 餐桌.`状态` = '忙碌' WHERE 餐桌.`桌号` = _桌号;
END */$$
DELIMITER ;

/* Procedure structure for procedure `客人到来` */

/*!50003 DROP PROCEDURE IF EXISTS  `客人到来` */;

DELIMITER $$

/*!50003 CREATE DEFINER=`root`@`localhost` PROCEDURE `客人到来`(
	IN _人数 INT,
	IN _座位数要求 INT
)
BEGIN
	INSERT INTO 来客(日期,人数,座位数要求,排队时间) 
	VALUES (CURDATE(), _人数,_座位数要求,CURtime());
END */$$
DELIMITER ;

/* Procedure structure for procedure `点菜` */

/*!50003 DROP PROCEDURE IF EXISTS  `点菜` */;

DELIMITER $$

/*!50003 CREATE DEFINER=`root`@`localhost` PROCEDURE `点菜`(
	IN _桌号 CHAR(5),
	IN _菜名 VARCHAR(32)
)
BEGIN
	DECLARE 客户已点菜编号 INT;
	DECLARE _来客编号 INT;
	SELECT MAX(客户点菜编号) + 1 INTO 客户已点菜编号 FROM 点菜记录 WHERE 来客_日期 = CURDATE();
	IF 客户已点菜编号 IS NULL THEN
		SET 客户已点菜编号 = 1;
	END IF;
	SELECT 编号 INTO _来客编号 FROM 来客 WHERE 入座时间 = (SELECT MAX(入座时间) FROM 来客 INNER JOIN 餐桌 ON 来客.`桌号` = 餐桌.`桌号` AND 来客.`日期` = CURDATE());
	INSERT INTO 点菜记录
	VALUES (CURDATE(), _桌号, 客户已点菜编号, _来客编号,_菜名,CURTIME(),'未上菜');
END */$$
DELIMITER ;

/* Procedure structure for procedure `结账` */

/*!50003 DROP PROCEDURE IF EXISTS  `结账` */;

DELIMITER $$

/*!50003 CREATE DEFINER=`root`@`localhost` PROCEDURE `结账`(
	IN _桌号 CHAR(5),
	IN 支付方式 VARCHAR(5)
)
BEGIN
	DECLARE 应付金额 FLOAT;
	DECLARE 当前客户编号 INT;
	UPDATE 餐桌 SET 餐桌.`状态` = '空闲' WHERE 餐桌.`桌号` = _桌号;
	SELECT 来客.`编号` INTO 当前客户编号 FROM 来客 WHERE 来客.`入座时间` = (SELECT MAX(入座时间) FROM 来客 WHERE 来客.`桌号` = _桌号);
	select SUM(价格*折扣) INTO 应付金额 FROM 菜品 WHERE 菜名 = (
		Select 菜名 FROM 点菜记录 WHere 桌号 = _桌号 AND 来客_日期 = CURdate() AND 来客_编号 = 当前客户编号 AND 状态 = '已上菜');
	insert 收银记录
	Values (CURdate(),当前客户编号,CURtime(),应付金额,支付方式);
END */$$
DELIMITER ;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
