<!doctype html>
<html>
<head>
<meta charset="utf-8" />
<title>jQuery UI Datepicker - Seleccionar un rango de fechas</title>
<link rel="stylesheet" href="http://code.jquery.com/ui/1.10.1/themes/base/jquery-ui.css" />
<script src="http://code.jquery.com/jquery-1.9.1.js"></script>
<script src="http://code.jquery.com/ui/1.10.1/jquery-ui.js"></script>
<script src="jquery.ui.datepicker-es.js"></script>

<script>
$(function () {
	
	
$("#from").datepicker({ 
changeMonth:true,
dateFormat: "mm-dd-yy",


onClose: function (selectedDate) {
$("#to").datepicker("option", "minDate", selectedDate);
}
});

$("#to").datepicker({
changeMonth:true,dateFormat: "mm-dd-yy",
onClose: function (selectedDate) {
$("#from").datepicker("option", "maxDate", selectedDate);
}
});
	

	
});
	
	
</script>

</head>

<body>
<p>
<form method="post" action="http://186.155.238.250:8149/calendario.php">
Desde:
<input type="text" id="from" name="from"   />
Hasta:
<input type="text" id="to" name="to" />
<input type="submit" value="Ingresar Fecha" name="Ingresar_Fecha">

</p><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>

</form>
<?php 

		if(isset($_POST['Ingresar_Fecha']))
		{
			
			$from=$_POST['from'];
			$to=$_POST['to'];
			echo "fecha_inicio".$from;
			echo "fecha_final".$to;
			
		}
	
		if(isset ($_POST))
		{
			echo "modulo es=".$_POST['modulo'];
			echo "variable es=".$_POST['variable'];
			
				
		}


	?>
</body>


          
   
</html>


