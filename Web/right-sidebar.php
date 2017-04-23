<!DOCTYPE HTML>
<!--
	Linear by TEMPLATED
    templated.co @templatedco
    Released for free under the Creative Commons Attribution 3.0 license (templated.co/license)
-->
<html>
	<head>
		<title>Sistema de Monitoreo</title>
		<meta http-equiv="content-type" content="text/html; charset=utf-8" />
		<meta name="description" content="" />
		<meta name="keywords" content="" />
		<link href='http://fonts.googleapis.com/css?family=Roboto:400,100,300,700,500,900' rel='stylesheet' type='text/css'>
		<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.11.0/jquery.min.js"></script>
		<script src="js/skel.min.js"></script>
		<script src="js/skel-panels.min.js"></script>
		<script src="js/init.js"></script>
		
		<link rel="stylesheet" href="http://code.jquery.com/ui/1.10.1/themes/base/jquery-ui.css" />
		<script src="http://code.jquery.com/jquery-1.9.1.js"></script>
		<script src="http://code.jquery.com/ui/1.10.1/jquery-ui.js"></script>
		<script src="jquery.ui.datepicker-es.js"></script>

		
		<noscript>
			<link rel="stylesheet" href="css/skel-noscript.css" />
			<link rel="stylesheet" href="css/style.css" />
			<link rel="stylesheet" href="css/style-desktop.css" />
		</noscript>
		
		<script>
			$(function () {

				$("#from").datepicker({ 
					changeMonth:true,
					dateFormat: "dd-mm-yy",


					onClose: function (selectedDate) {
						$("#to").datepicker("option", "minDate", selectedDate);
						}
					});

					$("#to").datepicker({
						changeMonth:true,dateFormat: "dd-mm-yy",
						onClose: function (selectedDate) {
						$("#from").datepicker("option", "maxDate", selectedDate);
					}
				});

			});

		</script>

		<script>
			function resizeIframe(obj) {
				obj.style.height = obj.contentWindow.document.body.scrollHeight + 'px';
			}

		</script>
		
	</head>
	<body>

	<!-- Header -->
		<div id="header">
			<div id="nav-wrapper"> 
				<!-- Nav -->
				<nav id="nav">
					<ul>
					
						<li><a href="index.php">Bienvenido</a></li>
						<li><a href="left-sidebar.php">Sistema de monitoreo</a></li>
						<li class="active"><a href="right-sidebar.php">Registro de monitoreo</a></li>
						<li><a href="#contacto">Contacto</a></li>
						
					</ul>
				</nav>
			</div>
			<div class="container"> 
				
				<!-- Logo -->
				<div id="logo">
					<h1><a href="#">Sistema de monitoreo</a></h1>
					<span class="tag"></span>
				</div>
			</div>
		</div>
	<!-- Header -->  

	<!-- Main -->
		<div id="main">
			<div class="container">
				<div >

					<!-- Content -->
					<div id="content" class="8u skel-cell-important">
						<section>
							<header>
								<h2>Registro de monitoreo</h2>
								<span </span>
							</header>
							<p style="text-align:justify">En este espacio se selecciona la información del tipo del módulo, variable y fecha requería para observar los resultados obtenidos, por cada uno de los sensores mediante una gráfica. </p>
							
						</section>
						
						
						<section>
								
									<form method="post" action="#content">
										<div class="field half first">
											<label for="modulo">Modulo</label>
											<select name="modulo" id="modulo">
												<option value="" disabled selected>--Seleccione el id del Modulo--</option>
												<option value="1">Modulo #1 </option>
												<option value="2">Modulo #2 </option>
												<option value="3">Modulo #3 </option>
												<option value="4">Modulo #4 </option>
											</select>
											
										</div>
										<div class="field half">
											<label for="variable">Variable</label>
											
											<select name="variable" id="variable">
												<option value="" disabled selected>--Seleccione Variable--</option>
												<option value="temp">Temperatura </option>
												<option value="pres">Presion</option>
												<option value="hum_s">Humedad del Suelo </option>
												<option value="hum_a">Humedad del Aire </option>
												<option value="lum">Luminosidad </option>
											</select>
											
										
										</div>
											
										<div>

												<label for="fecha">Fecha</label>
												
												Desde:
												<input type="text" id="from" name="from"   />
												Hasta:
												<input type="text" id="to" name="to" />
												

										</div>
										
										<div >
											
											<ul class="actions">
											<input type="submit" value="Enviar" name="Enviar">
										</ul
										
										</div>
										
													
										<?php
												
												if(isset($_POST['Enviar'])) 
													{ 
														if(isset($_POST['modulo']))
														{
															if(isset($_POST['variable']))
															{							
																
																$modulo=$_POST['modulo'];
																$variable= $_POST['variable'];
															
																if($variable=="temp"){ $titulo="Temperatura";}
																elseif($variable=="pres"){ $titulo="Presion";}		elseif($variable=="hum_s"){ $titulo="Humedad del Suelo";}
																elseif($variable=="hum_a"){ $titulo="Humedad del Aire";}	
																elseif($variable=="lum"){ $titulo="Luminosidad";}
																else{ $titulo=" ";}
																
																echo "Modulo:".$modulo." Variable:  ".$variable."Titulo: ".$titulo."fecha de inicio:".$_POST['from']."fecha final:".$_POST['to'];
																
																?>
																
																
	
																
																<p><iframe onload="resizeIframe(this)" src="http://186.155.238.250:8149/buscar_fechas.php?modulo=<?php echo $_POST['modulo']?>&dato=<?php echo $variable?>&fecha_inicio=<?php echo $_POST['from']?>&fecha_final=<?php echo $_POST['to']?>&titulo=<?php echo $titulo?>+registrada&tituloy=<?php echo $titulo?>+[bar]" width="100%" height="auto"  allowtransparency="true" ></iframe></p>
																<?php
															}
														
														}
														
																		
													
													}
													
										?>
										
										
											
										
									</form>
									
											
	
								</section>
								
						
						
						
						
						
						
						
						
						
						
					</div>

					<!-- Sidebar -->
					<div id="sidebar" class="4u">
						<!-- /Ma
						<section>
							<header>
								<h2>Etiam malesuada</h2>
							</header>
							<div class="row">
								<section class="6u">
									<ul class="default">
										<li><a href="#">Donec facilisis tempor</a></li>
										<li><a href="#">Nulla convallis cursus</a></li>
										<li><a href="#">Integer congue euismod</a></li>
										<li><a href="#">Venenatis vulputate</a></li>
										<li><a href="#">Morbi ligula volutpat</a></li>
									</ul>
								</section>
								<section class="6u">
									<ul class="default">
										<li><a href="#">Donec facilisis tempor</a></li>
										<li><a href="#">Nulla convallis cursus</a></li>
										<li><a href="#">Integer congue euismod</a></li>
										<li><a href="#">Venenatis vulputate</a></li>
										<li><a href="#">Morbi ligula volutpat</a></li>
									</ul>
								</section>
							</div>
						</section>
							<!-- /Main <section>
							<header>
								<h2>Mauris vulputate</h2>
							</header>
							<ul class="style">
								<li>
									<p class="posted">May 21, 2014  |  (10 )  Comments</p>
									<p><a href="#">Nullam non wisi a sem eleifend. Donec mattis libero eget urna. Pellentesque viverra enim.</a></p>
								</li>
								<li>
									<p class="posted">May 18, 2014  |  (10 )  Comments</p>
									<p><a href="#">Nullam non wisi a sem eleifend. Donec mattis libero eget urna. Pellentesque viverra enim.</a></p>
								</li>
							</ul>
						</section>-->
						
					</div>
					
				</div>
			</div>
		</div>
	<!-- /Main -->

	<!-- Tweet -->
		<div id="tweet">
			<div class="container">
				<section>
					<blockquote> "La Papa Tiene Lo Suyo"- Fedepapa </blockquote>
				</section>
			</div>
		</div>
	<!-- /Tweet -->

	<!-- Footer -->
		<div id="footer">
			<div class="container">
				<section>
					<header>
						<h2>Contacto</h2>
						<span class="byline"></span>
					</header>
					<ul class="contact">
						<li><a href="#" class="fa fa-twitter"><span>Twitter</span></a></li>
						<li class="active"><a href="#" class="fa fa-facebook"><span>Facebook</span></a></li>
						<li><a href="#" class="fa fa-dribbble"><span>Pinterest</span></a></li>
						<li><a href="#" class="fa fa-tumblr"><span>Google+</span></a></li>
					</ul>
				</section>
			</div>
		</div>
	<!-- /Footer -->

	<!-- Copyright -->
		<div id="contacto">
			<div class="container">
				
			</div>
		</div>


	</body>
</html>