DROP TABLE IF EXISTS "Computers";
CREATE TABLE "Computers" ("ComputerID" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL  UNIQUE , "ComputerName" VARCHAR NOT NULL , "PID" );
DROP TABLE IF EXISTS "People";
CREATE TABLE "People" ("ID" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL  UNIQUE , "Name" VARCHAR NOT NULL , "BirthYear" INTEGER NOT NULL , "DeathYear" INTEGER, "ComputerID" INTEGER);
