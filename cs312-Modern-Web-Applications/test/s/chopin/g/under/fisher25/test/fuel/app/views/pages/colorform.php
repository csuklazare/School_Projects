<!DOCTYPE html>
<html>
<head>
	<?php echo Asset::css('colorform.css'); ?>

</head>
<body>
	<h1 id="colorformpage">Color Form Page</h1>
	<main>
	<div>
		<?php
			if (isset($error)) {
				echo $error;
			}
		?>
	</div>
	<div id='edit colors'>
    <button onclick="window.location.href='https://www.cs.colostate.edu:4444/~fisher25/m1/index/m1/editDB';" id="button">Edit Colors</button>
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
			echo Form::label("Number of colors. Please enter a number less than the amount you have added to the database. If you haven't added a color yet, do so above!:&nbsp", "numcolors");
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
		</main>
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
