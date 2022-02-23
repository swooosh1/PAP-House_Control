<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<LINK REL="SHORTCUT ICON" HREF="./images/favicon.ico">
<title>Welcome to House Control © - Remote Control Your House</title>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<link rel="stylesheet" type="text/css" href="main.css" />
</head>
<script language="JavaScript" src="image_change.js"></script>

<body>

   <!-- Begin Wrapper -->
   <div id="wrapper">
   
         <!-- Begin Header -->
<div id="header"></div>
		 <!-- End Header -->
        <div id="menu"<center>
		 <a href="./home.php"><img src="./images/home.png" id="Image1" onmouseover="MM_swapImage('Image1','','./images/home2.png',1)" onmouseout="MM_swapImage('Image1','','./images/home.png',1)"></a>
		 <a href="./cpanel.php"><img src="./images/cpanel.png" id="Image2" onmouseover="MM_swapImage('Image2','','./images/cpanel2.png',1)" onmouseout="MM_swapImage('Image2','','./images/cpanel.png',1)" ></a>
		 <a href="./about.php"><img src="./images/about.png" id="Image3" onmouseover="MM_swapImage('Image3','','./images/about2.png',1)" onmouseout="MM_swapImage('Image3','','./images/about.png',1)"></a>
         
		 </center>
         </div>
         <!-- Begin Left Column -->
		 <div id="leftcolumn">
		   <p><strong>Contactos :</strong></p><center>
		<a href="mailto:pedroribeiroinfo@gmail.com"><img src="./images/mail_enc.png"><p><strong></a>pedroribeiroinfo@gmail.com</strong></p>
		<a href="http://www.esab.pt" target="_blank"><img src="./images/esab.png"><p><strong></a>ES Avelar Brotero</strong></p>
		<a href="http://www.pedroribeiro.pt.vc" target="_blank"><img src="./images/own.png"></a><p><strong>Pedro Ribeiro - WebPage</strong></p>
		
	

		</center>
     </div>
	 <!-- End Left Column -->
		 
		 <!-- Begin Right Column -->
		 <div id="rightcolumn">
         <h2 style="color:white;">Login</h2>
		 <br />
					
						<?php
							@Session_start();
							if(!isset($_SESSION["userlog"]))
							{
								echo '<form action="login.php" method="POST">
										<table style="color=white; height="100px" width="50px" alig="left">
											<tr>
												<td>Username:</td>
												<td><input type="text" maxlenght="20" name="user" /></td>
											</tr>
											<tr>
												<td >Password:</td>
												<td><input type="password" maxlenght="20" name="pwd" /></td>
											</tr>
											<tr>
												<td></td>
												<td><br /><input type="submit" value="   Entrar   "></td>
												
											</tr>
											
										</table>
									</form>';
									echo '<center><p>Não está registado? <a href="./registar">Clique Aqui!</a><p></center>';
							}
							else
							{
								echo "Bem Vindo <b>". $_SESSION["userlog"]."</b> !<br />";
								echo '<a href="./logout.php"><b>Logout ?</b></a>';
							}
						?>
         </div>

					
			
		 <!-- End Right Column -->
		 
		 <!-- Begin Footer -->
		<div id="footer">
		 <p align="center"><font size="2" face="lucida console" color="white">Copyright © <a  style="text-decoration:none; color:white;" href="www.pedroribeiro.pt.vc">Pedro Ribeiro</a> 2011 </font></p>      
		</div>
			   
		 <!-- End Footer -->
		 
   </div>
   <!-- End Wrapper -->
   
</body>
</html>
