-- 1) nome e cognome degli studenti che svolgono il tirocinio in una azienda   richiesta in input attraverso una cc.
SELECT name, surname FROM trainee t
JOIN company c ON t.id_company = c.id
WHERE c.name = 'Name';

-- 2) nome e cognome dei tirocinanti di una classe richiesta in input attraverso una cc.
SELECT nome, cognome FROM trainee t
WHERE c.class = 'Class';

-- 3) settore e tipologia delle aziende in cui ha svolto il tirocinio un tirocinante(nome e cognome) richiesto in input (cc)
SELECT s.name AS sector, c.type AS type FROM trainee t
JOIN company c ON t.id_company = c.id
JOIN sector s ON c.id_sector = s.id
WHERE t.name = 'Name' AND t.surname = 'Surname';

-- 4) nome, cognome e materie dei tutor dei tirocinanti del settore informatica
SELECT t.name AS tutor_name, t.surname AS tutor_surname, t.subject FROM tutor t
JOIN trainee tr ON t.id = tr.id_tutor
JOIN company c ON tr.id_company = c.id
WHERE c.sector = 'Informatica';

-- 5) i luoghi dove svolgono i tirocini gli studenti seguiti dal prof. Rossi Mario
SELECT c.location FROM tutor t
JOIN trainee tr ON t.id = tr.id_tutor
JOIN company c ON tr.id_company = c.id
WHERE t.name = 'Mario' AND t.surname = 'Rossi';
