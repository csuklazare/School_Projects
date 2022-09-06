<!DOCTYPE html>
<html lang = "en">
	
	<head>
    		<meta charset="UTF-8">
    		<title>The Boolean Hooligans</title>
		<meta name="author" content="co-authored by Sam Fales, Brock Fisher, Jacki Hyatt, Henry Larson">
		<meta name="description" content="Group project for computer science 312 at Colorado State University - Spring 2022">
		<meta name="keywords" content="JavaScript, PHP, CSS, HTML5, group project, CS312, Colorado State University">
		<meta name=”robots” content=”index, follow”>
		<meta content='width=device-width, initial-scale=1' name='viewport'/>
		<?php echo Asset::css('main.css'); ?>
	</head>
	
	<body>
		
    		<div id="nav">
			<!--Make a horizontal nav bar with this layout: Icon-Title-Menu icons-->
           		<ul>
                		<li><a href='<?=$homeLink?>'>Welcome</a></li>
                		<li><a href='<?=$aboutLink?>'>About</a></li>
                		<li><a href='<?=$colorCoordinateLink?>'>Color Coordinate</a></li>
            		</ul>
        	</div>
		<?= Asset::img('Logo.jpg', array('id' => 'brand', 'alt' => 'The Boolean Hooligan Company Logo')); ?>
		<!--Add php code for general content to change-->
		<?=$content; ?>
	</body>
</html>
