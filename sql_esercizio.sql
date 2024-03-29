--Creare tables esercizi 
CREATE TABLE IMPIEGATI  (
  MATRICOLA VARCHAR(20) PRIMARY KEY,
  NOME VARCHAR(20),
  RESIDENZA VARCHAR(20),
  STIPENDIO INT, 
  DIPARTIMENTO VARCHAR(20)
    
);

CREATE TABLE ASSEGNAMENTO  (
 IMPIEGATO VARCHAR(20),
 PROGETTO VARCHAR(50),
  MESI_UOMO FLOAT,
  FUNZIONE VARCHAR(50),
    FOREIGN KEY(IMPIEGATO) REFERENCES IMPIEGATI(MATRICOLA)

    
);


--- INSERIRE VALORI
INSERT INTO IMPIEGATI (MATRICOLA, NOME, RESIDENZA, STIPENDIO, DIPARTIMENTO)
VALUES
('XZ12', 'Max Viaggi', 'Modena', 2800, 'D13'),
('YX21', 'Pino Zoff', 'Ferrara', 1350, 'D23'),
('XY12', 'Jury Cecchi', 'Bologna', 2100, 'D09'),
-- inserire due impiegati in piú provare risultato query
('MP23', 'Federico Da Silenti', 'MODENA', 5400, 'D09'),
('GP15', 'Chiara Maria Rellaso', 'PARMA', 5400, 'D09'),
('OO11', 'Ornella Zazza', 'PARMA', 3800, 'D09')



;
INSERT INTO ASSEGNAMENTO (IMPIEGATO, PROGETTO, MESI_UOMO, FUNZIONE)
VALUES
('XY12', 'DURGA', 10, 'DIRETTORE'),
('YX21', 'LOKI', 5, 'PROGETTISTA'),
('XZ01', 'ANUBI', 4, 'CONSULENTE'),
('YX21', 'FUXY', 3, 'REVISORE'),
('ZZ20', 'DURGA', 6, 'DISEGNATORE'),
('XX11', 'FUXI', 9, 'DIRETTORE'),

-- inserire 2 progetti con direttore in piú per provare risultato query
('GP15', 'LIDU', 3, 'DIRETTORE'),
('MP23', 'LILLI', 18, 'DIRETTORE'),
('OO11', 'LILLI', 6, 'CONSULENTE')

;


SELECT PROGETTO, COUNT(MATRICOLA) AS NUM_IMPIEGATI, ROUND(CAST((SUM(a.MESI_UOMO) / 12) AS FLOAT),2) AS ANNI_UOMO, 

--SUM(a.mesi_uomo) AS MESI_UOMO -- MESI UOMO NON NECESSARIO PER ESERCIZIO

FROM ASSEGNAMENTO a

LEFT JOIN IMPIEGATI i ON i.MATRICOLA = a.impiegato

WHERE  a.PROGETTO IN ( -- il progetto deve avere un direttore che risieda in Modena o Parma
  /*
  SUBQUERY per identificare la lista di progetti che abbiano un direttore di Modena o Parma. 
  */
  (
SELECT a.PROGETTO FROM ASSEGNAMENTO a

LEFT JOIN IMPIEGATI i on a.IMPIEGATO = i.MATRICOLA

WHERE a.FUNZIONE = 'DIRETTORE' AND i.RESIDENZA IN ('MODENA', 'PARMA'))
  )


GROUP BY PROGETTO
ORDER BY NUM_IMPIEGATI DESC
;
