<style type="text/css">
body {background:none transparent;
}
</style>
<?
error_reporting(0);
$lenguage = 'es_CO.UTF-8';
putenv("LANG=$lenguage");
setlocale(LC_ALL, $lenguage);
//echo strftime("%A %e %B %Y");
require 'vendor/autoload.php';

//$connection = new MongoClient(); // connects to localhost:27017
//$connection = new MongoClient( "mongodb://example.com" ); // connect to a rem$
//$connection = new MongoClient( "mongodb://example.com:65432" ); // connect to$
//echo "Connection to database successfull. <br>";
$collection = (new MongoDB\Client)->proyecto_embebidos->medidas;
$document = $collection->findOne();

$cantidad_datos=$collection->count();

//DATOS A RECIBIR POR GET PARA GRAFICAR

if(!empty($_GET["limitar"]) ||  ( isset($_GET["limitar"]) && $_GET["limitar"] !=null  )){
$limitar=trim($_GET["limitar"]);
}else
	$limitar=-1;


if(!empty($_GET["dato"]) ||  ( isset($_GET["dato"]) && $_GET["dato"] !=null  )){
$dato= trim($_GET["dato"]);
}else
	$dato="temp";

if(!empty($_GET["color"]) ||  ( isset($_GET["color"]) && $_GET["color"] !=null  )){
$color= "#".trim($_GET["color"]);
}else{
	$color = "#".dechex(random_int(0x000000, 0xFFFFFF)); //VALORES ALEATORIOS PARA EL COLOR
	//$color="#006400";
	if (strlen($color)<7) {
		$faltan= 7- strlen($color);
		$color= $color;
		for ($i=1;$i>=faltan;$i++){
			$color.="0";
		}
	}
}

$fecha_inicio_manual=0;
if(!empty($_GET["fecha_inicio"]) ||  ( isset($_GET["fecha_inicio"]) && $_GET["fecha_inicio"] !=null  )){
$fecha_inicio_manual=1;
$fecha_inicio= $_GET["fecha_inicio"];
}else
	$fecha_inicio = date("m/d/Y");
	//$fecha_inicio = "04/06/2017";




if(!empty($_GET["fecha_final"]) ||  ( isset($_GET["fecha_final"]) && $_GET["fecha_final"] !=null  )){
$fecha_final= trim($_GET["fecha_final"]);
}else
	$fecha_final= $fecha_inicio;
	

if(!empty($_GET["modulo"]) ||  ( isset($_GET["modulo"]) && $_GET["modulo"] !=null  )){
$modulo= intval($_GET["modulo"]);
}else
	$modulo=1 ;


if(!empty($_GET["titulo"]) ||  ( isset($_GET["titulo"]) && $_GET["titulo"] !=null  )){
$titulo= trim($_GET["titulo"]);
}else
	$titulo="Temperatura registrada" ;


if(!empty($_GET["tituloy"]) ||  ( isset($_GET["tituloy"]) && $_GET["tituloy"] !=null  )){
$tituloy= trim($_GET["tituloy"]);
}else
	$tituloy="Temperatura [°C]" ;


	
if ($limitar==-1)
		$limitar= $cantidad_datos;
else
 	$limitar=$limitar;
	

if ($fecha_final==$fecha_inicio && $fecha_inicio_manual==1)
	$titulo_completo= $titulo." el día ".strftime("%d-%B-%Y", strtotime($fecha_inicio))." para el modulo ".$modulo;
elseif ($fecha_final==$fecha_inicio  && $fecha_inicio_manual==0)
	$titulo_completo= $titulo." el día ".strftime("%d-%B-%Y", strtotime($fecha_inicio))." para el modulo ".$modulo;
	else
		$titulo_completo= $titulo." entre el ".strftime("%d-%B-%Y",strtotime($fecha_inicio))." y el ".strftime("%d-%B-%Y",strtotime($fecha_final))." para el modulo ".$modulo;







$cursor = $collection->find(
    [
	"id_modulo"=>$modulo,
	//encontrar valores desde la fecha x hasta el dia de hoy mes dia año
	//"fecha" => ['$gte'=> new MongoDB\BSON\UTCDateTime (strtotime("04/05/2017".' UTC-5')*1000)]
	
	//encontrar valores de una fecha determinada mes dia año
	"fecha" => ['$gte'=> new MongoDB\BSON\UTCDateTime (strtotime($fecha_inicio." 00:00:00")*1000),
				'$lte'=> new MongoDB\BSON\UTCDateTime (strtotime($fecha_final." 23:59:59")*1000)
			   
			   ]
	
	],
	[
	'limit'=>$limitar,
	 'sort' => ['fecha' => -1],
]
);

$output_completo = "";

$contador=0;



foreach ($cursor as $document) {
	$contador++;
	//print $contador;
	//print_r($document);
	$output="";
	//$output.= $document['id'];
	//$output.= $document['temp'];
	//$output.="<br>";
	//$output.="<br>";
	
	//convierto el objeto de la fecha a array
	$nuevo = (array)$document['fecha'];
	
	//divido en mil porque el resultado viene de formato ISO en milisegundos
	$anio=date("Y",$nuevo["milliseconds"]/1000);
	$mes=date("m",$nuevo["milliseconds"]/1000);
	$dia=date("d",$nuevo["milliseconds"]/1000);
	$hora=date("H",$nuevo["milliseconds"]/1000);
	$minuto=date("i",$nuevo["milliseconds"]/1000);
	
	$output.='{x:new Date(';
	$output.=$anio.",0".($mes-1).",".$dia.",".$hora.",".$minuto;
	$output.='),';
	
	$eliminar_comas = str_replace(',', '.', $document[$dato]);
	
	$output.='y:'.$eliminar_comas.", label:'".ucwords(strftime("%d/%b/%y %H:%M",$nuevo["milliseconds"]/1000))."'   },\n";
	
	
	//$output.= date("Y-m-d H:i",$nuevo["milliseconds"]/1000);
	//$output.= $document['created_at'];
	//$output.="<br>";

//foreach ($cursor as $document) {
//	
//	//print_r($document);
//	$output="";
//	$output.= $document['temp'];
//	$output.="<br>";
//	$output.="<br>";
//	

	//print $output;
	
	$output_completo.=$output;
	
    //printf("%s: %s, %s\n", $document['id'], $document['temp'], $fecha);
	//printf ("<br>");
	
	
	
}

if ($contador==0){
	$titulo_completo= $titulo." el día ".strftime("%d-%B-%Y",strtotime($fecha_final))." para el modulo ".$modulo;
	$output_completo.= "{x:0,y:1, label:'NO EXISTEN DATOS PARA ESTA FECHA'   },";
	
}

//print gmdate('c', strtotime("04/05/2017"));
//print "<br>";
//print  strtotime("04/05/2017");


?>

<script type="text/javascript">
window.onload = function () {
	
	CanvasJS.addCultureInfo("es", 
    {      
      //decimalSeparator: ",",// Observe ToolTip Number Format
      //digitGroupSeparator: ".", // Observe axisY labels                   
    days: ["domingo", "lunes", "martes", "miércoles", "jueves", "viernes", "sábado"],
	shortMonths:["ene","feb","mar","abr","may","jun","jul","ago","sep","oct","nov","dic"],
      
    });
	
	
    var chart = new CanvasJS.Chart("chartContainer",
    { //backgroundColor: "transparent",
		culture: "es",
		 height:450,
        title: {
            text: "<?= $titulo_completo; ?>" ,
			fontSize: 20,
        },
        animationEnabled: true,
        axisX:{      
           //interval: 5,
          labelAngle : 90,
			labelFontSize: 15,
		 title: "Hora del Dia",
          valueFormatString: "DD-MMM HH:mm 'hrs'"

        },
        axisY: {
            title: "<?=$tituloy?>"
        },
        legend: {
            verticalAlign: "bottom",
            horizontalAlign: "center"
        },

        data: [{    
			
            name: "Temperatura Modulo <?=$modulo;?>",
            showInLegend: true,
            legendMarkerType: "square",
            markerType: "circle",
            type: "splineArea",
            color: "<?=$color;?>",
            markerSize: 5,
			//toolTipContent: "{label}<br/>{name}, <strong>{y}</strong>°C ",
             toolTipContent: "<span style='\"'color: <?=$color;?>;'\"'>{label}</span>:<br> {y} ",
            dataPoints: [

				

			<?
				print $output_completo;
				?>
				
            
            ]
        }
        
        
        
        
        ]
    });

chart.render();
}
</script>
<script type="text/javascript" src="http://canvasjs.com/assets/script/canvasjs.min.js"></script>
<div id="chartContainer" style="height: 300px; width: 100%;">
</div>
