<html>
<head><title>Redireccionamento em curso...</title>
<meta http-equiv="refresh" content="1;URL=./home.php">

</head>
<body>

<?php 
	echo "<h1>Vai ser redireccionado para a página inicial</h1>";
	@session_start();
	unset($_SESSION["userlog"]);
	unset($_SESSION["pwdlog"]);
 ?> 
 
 </body>
 </html>
 