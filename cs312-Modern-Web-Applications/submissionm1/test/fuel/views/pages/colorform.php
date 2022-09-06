<!DOCTYPE html>
<html>
<head>
	<?php echo Asset::css('colorform.css'); ?>
</head>
<body>
	<h1 id="colorformpage">Color Form Page</h1>
	<div>
		<?php
			if (isset($error)) {
				echo $error;
			}
		?>
	</div>
	<div>
		<?php
			echo Form::open(array(
				"action" => "index/m1/colorform",
				"method" => "post",
				"id" => "fuel_form"
			));
			echo Form::label("Number of columns/rows. Please enter a number between 1 and 26:&nbsp", "numColsRows");
			echo Form::input("numColsRows", "");
		?>
		<br>
		<br>
		<?php
			echo Form::label("Number of colors. Please enter a number between 1 and 10:&nbsp", "numcolors");
			echo Form::input("numcolors", "");
		?>
		<br>
		<br>
		<?php
			echo "Please click submit below once you have your parameters entered to load the Color Page.";
		?>
		<br>
		<br>
		<?php
			echo Form::submit("", "Submit");
			echo Form::close();
		?>
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
</body>
</html>
