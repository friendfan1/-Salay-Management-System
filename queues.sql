/*
 Navicat Premium Data Transfer

 Source Server         : mymenu
 Source Server Type    : SQLite
 Source Server Version : 3030001
 Source Schema         : main

 Target Server Type    : SQLite
 Target Server Version : 3030001
 File Encoding         : 65001

 Date: 16/03/2024 12:57:06
*/

PRAGMA foreign_keys = false;

-- ----------------------------
-- Table structure for queues
-- ----------------------------
DROP TABLE IF EXISTS "queues";
CREATE TABLE "queues" (
  "qno" TEXT NOT NULL,
  "qcno" TEXT,
  "qnum" INTEGER NOT NULL,
  "qstate" TEXT,
  "qontime" TEXT,
  "qofftime" TEXT,
  PRIMARY KEY ("qno")
);

-- ----------------------------
-- Records of queues
-- ----------------------------
INSERT INTO "queues" VALUES ('001', '001', 2, '排队中', '02:37:04', '');
INSERT INTO "queues" VALUES ('002', '002', 3, '排队中', '02:37:12', '');
INSERT INTO "queues" VALUES ('004', '004', 6, '排队中', '02:37:28', '');
INSERT INTO "queues" VALUES ('005', '005', 1, '排队中', '02:37:40', '');
INSERT INTO "queues" VALUES ('006', '006', 10, '排队中', '02:37:51', '');
INSERT INTO "queues" VALUES ('007', '007', 2, '排队中', '19:51:49', '');
INSERT INTO "queues" VALUES ('008', '008', 6, '排队中', '23:35:24', '');
INSERT INTO "queues" VALUES ('009', '009', 2, '排队中', '12:51:33', '');

PRAGMA foreign_keys = true;
