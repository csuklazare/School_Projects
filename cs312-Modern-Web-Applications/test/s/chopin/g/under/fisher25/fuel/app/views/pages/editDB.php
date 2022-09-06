<!DOCTYPE html>
<html>
<head>
	<?php echo Asset::css('editDB.css'); ?>
  <?php echo Asset::js('createTable.js'); ?>
  <h1 id="editDBPage">Edit Colors</h1>
</head>
<body onload="editDB(<?=$ID?>, <?=$Name?>, <?=$Hex?>)">
<main>
  <div>
    <table id="dbTable">
      <tr>
        <td>ID</td>
        <td>Color</td>
        <td>Hex</td>
        <td>Delete</td>
        <td>Edit</td>
      </tr>
    </table>
    <br>
    <div id="Add color header">
        Add a color below! Please enter exact hex value for each color. If you don't know the hex value, follow the linke below to find it.
    </div>
    <div>
      <a href="https://htmlcolorcodes.com/">Click here for hex value website</a>
    </div>
    <br>
    <div>
    <?php
			echo Form::open(array(
				"action" => "index/m1/editDB?formType=add",
				"method" => "post",
				"id" => "fuel_form",
			));
			echo Form::label("Color Name:&nbsp", "colorName");
			echo Form::input("colorName", "");
            echo Form::label("Color Hexvalue:&nbsp", "hexValue");
			echo Form::input("hexValue", "");
            echo Form::submit("", "Submit");
			echo Form::close();
		?>
    </div>
    <br>
  </div>
    </main>
</body>
</html>