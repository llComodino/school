/*M!999999\- enable the sandbox mode */ 
-- MariaDB dump 10.19-11.7.2-MariaDB, for Linux (x86_64)
--
-- Host: localhost    Database: appuser
-- ------------------------------------------------------
-- Server version	11.7.2-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*M!100616 SET @OLD_NOTE_VERBOSITY=@@NOTE_VERBOSITY, NOTE_VERBOSITY=0 */;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `user` (
  `id` tinyint(4) NOT NULL AUTO_INCREMENT,
  `surname` varchar(20) NOT NULL,
  `name` varchar(20) NOT NULL,
  `mail` varchar(64) NOT NULL DEFAULT '',
  `phone` varchar(25) NOT NULL,
  `city` varchar(25) NOT NULL,
  `prov` varchar(2) NOT NULL,
  `password` varchar(255) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `mail` (`mail`),
  UNIQUE KEY `mail_2` (`mail`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES
(1,'Diego','Gila','diego.gila@studenti.fauser.edu','333 444 5566','Novara','NO','$2y$12$zCjnMsCn4LDPBHDBoPVz.efVGvAKVBVmH6b2E19vnjEVQog43bTWm'),
(2,'Saccobabbo','Manuel','manuel.saccobabbo@studenti.fauser.edu','333 999 2277','Oleggio','NO','$2y$12$Sco.HUquLQljaiDMxWuv7ez6Fko2F7NuB3kZbfq/F1efyk9FztF5C'),
(3,'Guo Xu','Weng','gua.xua@cinesi.fauser.edu','999 888 2222','Chinatown','MI','$2y$12$//b96lD2jRx9fTKXigNFVeM3Rk6J3Epp9/NHRILPfAdO331Z7Wk5q'),
(4,'Turista','Per Sempre','turisti@occhialata.borsellata','000 999 2221','Busdapest','JS','$2y$12$dfucmATf9jUihpLwmMHNhe7MOkwkb8tZ3c0DLyD5NN/k/bWmigsG6'),
(5,'Ler','Federico Brasca','brasca@dottorporco.it','777 666 3322','Castelleto Ticino','NO','$2y$12$uojLGNvMRRwdKiG/Dl./7OX1Ag.ak7v5UVbOl3kEjcn2sctzKg3Cm');
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*M!100616 SET NOTE_VERBOSITY=@OLD_NOTE_VERBOSITY */;

-- Dump completed on 2025-04-07 20:46:55
