SET serveroutput ON;


Execute dbms_output.put_line(ganador('Rally de Catalu�a'));

SELECT codRally FROM RALLY WHERE nombre='Rally de Catalu�a';
SELECT COUNT(*) FROM TRAMO WHERE codRally='R001';

SELECT codPiloto, SUM(tiempo) AS tTotal, COUNT(numeroTramo)  FROM CORRE C1 WHERE codRally='R001' GROUP BY codPiloto HAVING COUNT(*)=3
AND SUM(tiempo) < ALL (SELECT SUM(tiempo) FROM CORRE C2 WHERE codRally='R001' AND C1.codPiloto <> C2.codPiloto GROUP BY codPiloto HAVING COUNT(*)=3);


Execute dbms_output.put_line(rallyCompletado('Rally de Catalu�a', 'Dani Sordo'));
Execute dbms_output.put_line(rallyCompletado('Rally de Catalu�a','Juan Perez'));
