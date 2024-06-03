/*
 Navicat Premium Data Transfer

 Source Server         : test
 Source Server Type    : MySQL
 Source Server Version : 80036
 Source Host           : mycgck.mysql.database.azure.com:3306
 Source Schema         : 餐馆信息管理系统

 Target Server Type    : MySQL
 Target Server Version : 80036
 File Encoding         : 65001

 Date: 02/06/2024 21:14:48
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for 收银记录
-- ----------------------------
DROP TABLE IF EXISTS `收银记录`;
CREATE TABLE `收银记录`  (
  `来客_日期` date NOT NULL,
  `来客_编号` int NOT NULL,
  `时间` time NOT NULL,
  `金额` float NOT NULL,
  `支付方式` varchar(16) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  PRIMARY KEY (`来客_日期`, `来客_编号`, `时间`) USING BTREE,
  CONSTRAINT `收银记录_ibfk_1` FOREIGN KEY (`来客_日期`, `来客_编号`) REFERENCES `来客` (`日期`, `编号`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of 收银记录
-- ----------------------------
INSERT INTO `收银记录` VALUES ('2024-04-26', 1, '14:02:48', 167.6, '微信支付');
INSERT INTO `收银记录` VALUES ('2024-04-26', 2, '16:05:00', 78, '现金');
INSERT INTO `收银记录` VALUES ('2024-04-26', 3, '16:12:06', 258.95, '支付宝');
INSERT INTO `收银记录` VALUES ('2024-05-10', 1, '07:54:02', 43.2, '支付宝');
INSERT INTO `收银记录` VALUES ('2024-05-10', 2, '07:55:14', 26, '支付宝');
INSERT INTO `收银记录` VALUES ('2024-05-10', 3, '08:00:26', 84, '现金');

-- ----------------------------
-- Table structure for 来客
-- ----------------------------
DROP TABLE IF EXISTS `来客`;
CREATE TABLE `来客`  (
  `日期` date NOT NULL,
  `编号` int NOT NULL,
  `人数` tinyint NOT NULL,
  `座位数要求` tinyint NOT NULL,
  `排队时间` time NULL DEFAULT NULL,
  `入座时间` time NULL DEFAULT NULL,
  `桌号` char(5) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`日期`, `编号`) USING BTREE,
  INDEX `桌号`(`桌号`) USING BTREE,
  CONSTRAINT `来客_ibfk_1` FOREIGN KEY (`桌号`) REFERENCES `餐桌` (`桌号`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of 来客
-- ----------------------------
INSERT INTO `来客` VALUES ('2024-04-26', 1, 2, 2, '13:19:03', '13:19:30', 'C1');
INSERT INTO `来客` VALUES ('2024-04-26', 2, 2, 2, '13:19:08', '13:19:33', 'C2');
INSERT INTO `来客` VALUES ('2024-04-26', 3, 8, 8, '16:06:19', '16:06:41', 'A1');
INSERT INTO `来客` VALUES ('2024-05-10', 1, 4, 4, '07:52:15', '07:52:22', 'B1');
INSERT INTO `来客` VALUES ('2024-05-10', 2, 4, 4, '07:54:20', '07:54:24', 'B1');
INSERT INTO `来客` VALUES ('2024-05-10', 3, 4, 4, '07:57:01', '07:57:08', 'B2');

-- ----------------------------
-- Table structure for 点菜记录
-- ----------------------------
DROP TABLE IF EXISTS `点菜记录`;
CREATE TABLE `点菜记录`  (
  `来客_日期` date NOT NULL,
  `桌号` char(5) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `客户点菜编号` int NOT NULL,
  `来客_编号` int NOT NULL,
  `菜名` varchar(32) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `时间` time NOT NULL,
  `状态` varchar(5) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  PRIMARY KEY (`来客_日期`, `客户点菜编号`) USING BTREE,
  INDEX `来客_日期`(`来客_日期`, `来客_编号`) USING BTREE,
  INDEX `菜名`(`菜名`) USING BTREE,
  CONSTRAINT `点菜记录_ibfk_1` FOREIGN KEY (`来客_日期`, `来客_编号`) REFERENCES `来客` (`日期`, `编号`) ON DELETE RESTRICT ON UPDATE CASCADE,
  CONSTRAINT `点菜记录_ibfk_2` FOREIGN KEY (`菜名`) REFERENCES `菜品` (`菜名`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of 点菜记录
-- ----------------------------
INSERT INTO `点菜记录` VALUES ('2024-04-26', 'C1', 1, 1, '土豆肉丝', '13:44:40', '已上菜');
INSERT INTO `点菜记录` VALUES ('2024-04-26', 'C1', 2, 1, '梅菜扣肉', '13:44:56', '已上菜');
INSERT INTO `点菜记录` VALUES ('2024-04-26', 'C1', 3, 1, '清蒸鲈鱼', '13:44:59', '已上菜');
INSERT INTO `点菜记录` VALUES ('2024-04-26', 'C2', 4, 2, '土豆肉丝', '15:54:09', '已上菜');
INSERT INTO `点菜记录` VALUES ('2024-04-26', 'C2', 5, 2, '土豆肉丝', '15:54:13', '已上菜');
INSERT INTO `点菜记录` VALUES ('2024-04-26', 'C2', 6, 2, '土豆肉丝', '15:54:16', '已上菜');
INSERT INTO `点菜记录` VALUES ('2024-04-26', 'A1', 7, 3, '宫保鸡丁', '16:07:00', '已上菜');
INSERT INTO `点菜记录` VALUES ('2024-04-26', 'A1', 8, 3, '梅菜扣肉', '16:07:03', '已上菜');
INSERT INTO `点菜记录` VALUES ('2024-04-26', 'A1', 9, 3, '清蒸鲈鱼', '16:07:06', '已上菜');
INSERT INTO `点菜记录` VALUES ('2024-04-26', 'A1', 10, 3, '炒年糕', '16:07:08', '已上菜');
INSERT INTO `点菜记录` VALUES ('2024-04-26', 'A1', 11, 3, '炒面', '16:07:12', '已上菜');
INSERT INTO `点菜记录` VALUES ('2024-04-26', 'A1', 12, 3, '炒饭', '16:07:14', '已上菜');
INSERT INTO `点菜记录` VALUES ('2024-05-10', 'B1', 1, 1, '宫保鸡丁', '07:52:47', '已上菜');
INSERT INTO `点菜记录` VALUES ('2024-05-10', 'B1', 2, 2, '土豆肉丝', '07:54:33', '已上菜');
INSERT INTO `点菜记录` VALUES ('2024-05-10', 'B1', 3, 2, '番茄炒蛋', '07:55:08', '已上菜');
INSERT INTO `点菜记录` VALUES ('2024-05-10', 'B2', 4, 3, '梅菜扣肉', '07:58:45', '已上菜');
INSERT INTO `点菜记录` VALUES ('2024-05-10', 'B2', 5, 3, '土豆肉丝', '07:59:18', '已上菜');

-- ----------------------------
-- Table structure for 菜品
-- ----------------------------
DROP TABLE IF EXISTS `菜品`;
CREATE TABLE `菜品`  (
  `菜名` varchar(32) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `价格` float NOT NULL,
  `折扣` float NOT NULL,
  `材料` varchar(32) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `类型` varchar(32) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  PRIMARY KEY (`菜名`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of 菜品
-- ----------------------------
INSERT INTO `菜品` VALUES ('土豆肉丝', 26, 1, '土豆、猪肉', '荤菜');
INSERT INTO `菜品` VALUES ('宫保鸡丁', 48, 0.9, '鸡肉、花生', '川菜');
INSERT INTO `菜品` VALUES ('梅菜扣肉', 58, 1, '梅干菜、猪肉', '招牌菜');
INSERT INTO `菜品` VALUES ('清蒸鲈鱼', 88, 0.95, '鲈鱼', '海鲜');
INSERT INTO `菜品` VALUES ('炒年糕', 38, 0.9, '年糕、蔬菜', '特色小吃');
INSERT INTO `菜品` VALUES ('炒面', 22, 0.85, '面条、蔬菜', '快餐');
INSERT INTO `菜品` VALUES ('炒饭', 25, 0.85, '米饭、蔬菜', '快餐');
INSERT INTO `菜品` VALUES ('番茄炒蛋', 25, 0.85, '鸡蛋、番茄', '简单营养');
INSERT INTO `菜品` VALUES ('糖醋排骨', 58, 0.9, '排骨、糖醋', '甜酸口味');
INSERT INTO `菜品` VALUES ('红烧肉', 68, 1, '五花肉、酱油', '经典菜');
INSERT INTO `菜品` VALUES ('酸菜鱼', 68, 0.95, '鱼、酸菜', '酸辣口味');
INSERT INTO `菜品` VALUES ('青椒肉丝', 45, 0.9, '猪肉、青椒', '下饭菜');
INSERT INTO `菜品` VALUES ('鱼香茄子', 35, 0.85, '茄子、辣椒', '家常菜');
INSERT INTO `菜品` VALUES ('麻婆豆腐', 32, 0.9, '豆腐、辣椒', '麻辣口味');

-- ----------------------------
-- Table structure for 账户
-- ----------------------------
DROP TABLE IF EXISTS `账户`;
CREATE TABLE `账户`  (
  `账号` char(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `密码` char(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`账号`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of 账户
-- ----------------------------
INSERT INTO `账户` VALUES ('1', '1');

-- ----------------------------
-- Table structure for 餐桌
-- ----------------------------
DROP TABLE IF EXISTS `餐桌`;
CREATE TABLE `餐桌`  (
  `桌号` char(5) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `容量` int NOT NULL,
  `状态` varchar(3) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  PRIMARY KEY (`桌号`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of 餐桌
-- ----------------------------
INSERT INTO `餐桌` VALUES ('A1', 8, '空闲');
INSERT INTO `餐桌` VALUES ('A2', 8, '空闲');
INSERT INTO `餐桌` VALUES ('A3', 8, '空闲');
INSERT INTO `餐桌` VALUES ('A4', 8, '空闲');
INSERT INTO `餐桌` VALUES ('B1', 4, '空闲');
INSERT INTO `餐桌` VALUES ('B2', 4, '空闲');
INSERT INTO `餐桌` VALUES ('B3', 4, '空闲');
INSERT INTO `餐桌` VALUES ('B4', 4, '空闲');
INSERT INTO `餐桌` VALUES ('B5', 4, '空闲');
INSERT INTO `餐桌` VALUES ('B6', 4, '空闲');
INSERT INTO `餐桌` VALUES ('B7', 4, '空闲');
INSERT INTO `餐桌` VALUES ('C1', 2, '空闲');
INSERT INTO `餐桌` VALUES ('C2', 2, '空闲');
INSERT INTO `餐桌` VALUES ('C3', 2, '空闲');
INSERT INTO `餐桌` VALUES ('C4', 2, '空闲');
INSERT INTO `餐桌` VALUES ('C5', 2, '空闲');

-- ----------------------------
-- Procedure structure for 上菜
-- ----------------------------
DROP PROCEDURE IF EXISTS `上菜`;
delimiter ;;
CREATE PROCEDURE `上菜`(IN _点菜编号 INT ,
IN _日期 DATE)
BEGIN
    UPDATE 点菜记录 SET 点菜记录.`状态` = '已上菜' WHERE 点菜记录.`客户点菜编号` = _点菜编号 AND 点菜记录.`来客_日期` = _日期;
END
;;
delimiter ;

-- ----------------------------
-- Procedure structure for 取消点餐
-- ----------------------------
DROP PROCEDURE IF EXISTS `取消点餐`;
delimiter ;;
CREATE PROCEDURE `取消点餐`(IN _点菜编号 INT,
IN _日期 DATE)
BEGIN
	delete FROM 点菜记录 where 点菜记录.`客户点菜编号` = _点菜编号 and 点菜记录.`来客_日期` = _日期;
END
;;
delimiter ;

-- ----------------------------
-- Procedure structure for 客人上桌
-- ----------------------------
DROP PROCEDURE IF EXISTS `客人上桌`;
delimiter ;;
CREATE PROCEDURE `客人上桌`(IN _来客编号 INT,
	IN _桌号 CHAR(5))
BEGIN
	UPDATE 来客 SET 来客.`入座时间` = CURTIME(),来客.`桌号` = _桌号 WHERE 来客.`编号` = _来客编号 AND 来客.`日期` = CURDATE();
	UPDATE 餐桌 SET 餐桌.`状态` = '忙碌' WHERE 餐桌.`桌号` = _桌号;
END
;;
delimiter ;

-- ----------------------------
-- Procedure structure for 客人到来
-- ----------------------------
DROP PROCEDURE IF EXISTS `客人到来`;
delimiter ;;
CREATE PROCEDURE `客人到来`(IN _人数 INT,
	IN _座位数要求 INT)
BEGIN
	INSERT INTO 来客(日期,人数,座位数要求,排队时间) 
	VALUES (CURDATE(), _人数,_座位数要求,CURtime());
END
;;
delimiter ;

-- ----------------------------
-- Procedure structure for 查看已上菜
-- ----------------------------
DROP PROCEDURE IF EXISTS `查看已上菜`;
delimiter ;;
CREATE PROCEDURE `查看已上菜`()
BEGIN
	SELECT 桌号,菜名,来客_日期,时间,客户点菜编号,状态 FROM 点菜记录 WHERE 状态='已上菜'
	ORDER BY 来客_日期 DESC,时间 DESC;
END
;;
delimiter ;

-- ----------------------------
-- Procedure structure for 查看已点菜
-- ----------------------------
DROP PROCEDURE IF EXISTS `查看已点菜`;
delimiter ;;
CREATE PROCEDURE `查看已点菜`(IN _桌号 CHAR(5))
BEGIN
	DECLARE 当前客户编号 INT;
	SELECT 来客.`编号` INTO 当前客户编号 FROM 来客 WHERE 来客.`入座时间` = (SELECT MAX(入座时间) FROM 来客 WHERE 来客.`桌号` = _桌号 AND 来客.`日期`=CURDATE()) AND 来客.`日期`=CURDATE();
	SELECT 菜品.菜名,菜品.价格,菜品.折扣  FROM (SELECT * FROM 点菜记录 WHERE 桌号 = _桌号 AND 来客_日期 = CURDATE() AND 来客_编号 = 当前客户编号 AND 状态='已上菜') AS 此桌点菜记录 JOIN 菜品 ON 此桌点菜记录.菜名 = 菜品.菜名;
END
;;
delimiter ;

-- ----------------------------
-- Procedure structure for 查看未上菜
-- ----------------------------
DROP PROCEDURE IF EXISTS `查看未上菜`;
delimiter ;;
CREATE PROCEDURE `查看未上菜`()
BEGIN
	SELECT 桌号,菜名,来客_日期,时间,客户点菜编号,状态 FROM 点菜记录 WHERE 状态='未上菜'
	ORDER BY 来客_日期 DESC , 时间 ASC;
END
;;
delimiter ;

-- ----------------------------
-- Procedure structure for 点菜
-- ----------------------------
DROP PROCEDURE IF EXISTS `点菜`;
delimiter ;;
CREATE PROCEDURE `点菜`(IN _桌号 CHAR(5),
	IN _菜名 VARCHAR(32))
BEGIN
	DECLARE 客户已点菜编号 INT;
	DECLARE _来客编号 INT;
	SELECT MAX(客户点菜编号) + 1 INTO 客户已点菜编号 FROM 点菜记录 WHERE 来客_日期 = CURDATE();
	IF 客户已点菜编号 IS NULL THEN
		SET 客户已点菜编号 = 1;
	END IF;
	SELECT 编号 INTO _来客编号 FROM 来客 WHERE 入座时间 = (SELECT MAX(入座时间) FROM 来客 WHERE 来客.`桌号`=_桌号 AND 来客.`日期` = CURDATE()) AND 来客.`日期` = CURDATE();
	INSERT INTO 点菜记录
	VALUES (CURDATE(), _桌号, 客户已点菜编号, _来客编号,_菜名,CURTIME(),'未上菜');
END
;;
delimiter ;

-- ----------------------------
-- Procedure structure for 结账
-- ----------------------------
DROP PROCEDURE IF EXISTS `结账`;
delimiter ;;
CREATE PROCEDURE `结账`(IN _桌号 CHAR(5),
	IN 支付方式 VARCHAR(5))
BEGIN
	DECLARE 应付金额 FLOAT;
	DECLARE 当前客户编号 INT;
	SELECT 来客.`编号` INTO 当前客户编号 FROM 来客 WHERE 来客.`入座时间` = (SELECT MAX(入座时间) FROM 来客 WHERE 来客.`桌号` = _桌号 AND 来客.`日期`=CURDATE()) AND 来客.`日期`=CURDATE();
	select SUM(菜品.价格*菜品.折扣) INTO 应付金额 FROM (SELECT * FROM 点菜记录 WHERE 桌号 = _桌号 AND 来客_日期 = CURDATE() AND 来客_编号 = 当前客户编号 AND 状态='已上菜') AS 此桌点菜记录 JOIN 菜品 ON 此桌点菜记录.菜名 = 菜品.菜名;
	insert 收银记录
	Values (CURdate(),当前客户编号,CURtime(),应付金额,支付方式);
	UPDATE 餐桌 SET 餐桌.`状态` = '空闲' WHERE 餐桌.`桌号` = _桌号;
END
;;
delimiter ;

-- ----------------------------
-- Triggers structure for table 来客
-- ----------------------------
DROP TRIGGER IF EXISTS `来客编号产生`;
delimiter ;;
CREATE TRIGGER `来客编号产生` BEFORE INSERT ON `来客` FOR EACH ROW BEGIN 
	DECLARE 当日最大编号 INT;
	SELECT MAX(来客.`编号`) + 1 INTO 当日最大编号 FROM 来客 WHERE 来客.`日期` = CURDATE();
	IF 当日最大编号 IS NULL THEN 
		SET 当日最大编号 = 1;
	END IF;
	SET New.编号 = 当日最大编号;
END
;;
delimiter ;

SET FOREIGN_KEY_CHECKS = 1;
