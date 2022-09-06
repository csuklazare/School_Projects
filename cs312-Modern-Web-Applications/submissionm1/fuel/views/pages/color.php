<!DOCTYPE html>
<html>
<head>
	<?php echo Asset::css('color.css', array('id' => "css")); ?>
	<?php echo Asset::js('createTable.js'); ?>
</head>
<body>
<body onload="buildTables(<?=$numColsRows?>,<?=$numcolors?>)">
	<h1 id="colorpage">Color Page</h1>
	<div>
		<p id='error'></p>
	</div>
	<div>
		<table id='first'>
		</table>
	</div>
	<div>
		<br>
		<br>
	</div>
	<div>
		<table id='second'>
		</table>
	</div>
	<div>
		<button onclick="printView()" id="button">Print View</button>
	</div>
</body>
</html>
