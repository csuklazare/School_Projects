<!DOCTYPE html>
<html>
	<head>
		<?php echo Asset::css('about.css'); ?>
	</head>
	<body>
		<h1 id="team">Our Team</h1>
			<!--Author bios and photos-->
			<div id="cards">
				<div id="Sam">
        			<!--Sam-->
				<?= Asset::img('Sam.jpg'); ?>
				<h1>Sam Fales</h1>
				<p>A computer science major at CSU. In my freetime I like to play soccer and go to the gym. I also like to read books.</p>
				</div>
		
				<div id="Brock">
				<!--Brock-->
				<?= Asset::img('Brock.jpg'); ?>
				<h1>Brock Fisher</h1>
				<p>A student returning for their second Bachelor's degree. Likes to play video games, sports, go on hikes, and watch movies.</p>
				</div>

				<div id="Jacki">
				<!--Jacki-->
				<?= Asset::img('Jacki.jpg'); ?>
				<h1>Jacki Hyatt</h1>
				<p>An online computer science student at CSU. My hobbies include playing D&D with friends, running, and working on DIY projects. I reside with three cats, an awesome husband and soon to be son.</p>
				</div>

				<div id="Henry">
				<!--Henry-->
				<?= Asset::img('Henry.jpg'); ?>
				<h1>Henry Larson</h1>
				<p>A frontend and consulting focused computer science major at CSU. Loves to video game, read, cook, fence, and play the piano. Lives with a cat, a dog, and a boyfriend.</p>
				</div>
		</div>
	</body>
<html>
