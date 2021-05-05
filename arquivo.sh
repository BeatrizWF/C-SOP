#!/bin/bash
echo Qual o nome do arquivo a ser compilado?
read nome

if [ [-f  /home/beatriz/Desktop/$nome.java] ]
then 
	echo "O arquivo $nome Java contém no diretório."
else
	echo "O arquivo $nome Java não existe nesse diretório."
fi

if [ [-f /home/beatriz/Desktop/$nome.class]]
then
	echo "O arquivo $nome.class contém no diretório."
	rm $nome.class
else
	echo "O arquivo $nome.class não existe nesse diretório."
fi

if [ [ -f /home/beatriz/Desktop/$nome.java]]
then 
	javac $nome.java
else
	echo "Não é possível compilar, não contém arquivo  .java no diretório"
fi

if [[ -f /home/beatriz/Desktop/$nome.class]]
then
	echo "O arquivo $nome .class foi gerado!"
else
	echo "O codigo não foi compilado."
fi
