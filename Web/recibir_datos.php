<?php



$comando = "python guardar.py";

if(!empty($_GET["mod"]) ||  ( isset($_GET["mod"]) && $_GET["mod"] !=null  )){
$MODULO=$_GET["mod"];
$comando.= " --mod=".floatval($MODULO);
echo "El modulo es".floatval($MODULO);
echo "<br>";
}

if(!empty($_GET["temp"]) ||  ( isset($_GET["temp"]) && $_GET["temp"] !=null  ) ){
$TEMP=$_GET["temp"];
$comando.= " --temp=".floatval($TEMP);
echo "La temperatura es: ".floatval($TEMP);
echo "<br>";
}

if(!empty($_GET["hum_s"]) ||  ( isset($_GET["hum_s"]) && $_GET["hum_s"] !=null  ) ){
$HUMEDAD_SUELO=$_GET["hum_s"];
$comando.= " --hum_s=".floatval($HUMEDAD_SUELO);
echo "La humedad del suelo es: ".floatval($HUMEDAD_SUELO);
echo "<br>";
}

if(!empty($_GET["hum_a"]) ||  ( isset($_GET["hum_a"]) && $_GET["hum_a"] !=null  ) ){
$HUMEDAD_AIRE= $_GET["hum_a"];
$comando.= " --hum_a=".floatval($HUMEDAD_AIRE);
echo "La humedad del aire es: ".floatval($HUMEDAD_AIRE);
echo "<br>";
}

if( !empty($_GET["pres"]) ||  ( isset($_GET["pres"]) && $_GET["pres"] !=null  )  ){
$PRESION= $_GET["pres"];
$comando.= " --pres=".floatval($PRESION);
echo "La presion es: ".floatval($PRESION);
echo "<br>";
}

if( (!empty($_GET["lum"])) ||  ( isset($_GET["lum"]) && $_GET["lum"] !=null  )     ){
$LUMINOCIDAD=$_GET["lum"];
$comando.= " --lum=".floatval($LUMINOCIDAD);
echo "La luminocidad es: ".floatval($LUMINOCIDAD);
echo "<br>";
}

//$time =  strtotime("now");
//echo "La fecha en forasto unix es: ".$time."<br>";
//echo "la fecha es ". date("d/m/Y h:i:s A T",$time);

//MODULO
//TEMP
//HUMEDAD_SUELO
//HUM_AIRE
//PRESION
//LUMINOCIDAD
//FECHA
//HORA

echo "<br>";


$command = escapeshellcmd($comando);
$output = shell_exec($command);
echo $output;



?>
