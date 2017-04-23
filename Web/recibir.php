<?php
if (isset($_POST["temp"]))
{
$temp=$_POST["temp"];
$content="hola";
$fp = fopen($temp.".txt","wb");
fwrite($fp,$content);
fclose($fp);

echo "temperatura: ".$temp;

}

?>
