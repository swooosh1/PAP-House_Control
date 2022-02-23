<?php
	$ligaBD= mysqli_connect('localhost','root','root');
	if(!$ligaBD){
		echo "<br />Erro:Não foi posivel estabelecer ligaçao com o MySQL";exit;
	}
	
	$escolheBD=mysqli_select_db($ligaBD,'mywebsite_users');
	if(!$escolheBD){
		echo"<br />Erro ao escolher a BD"; exit;
	}
?>