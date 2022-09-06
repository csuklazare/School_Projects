<!DOCTYPE html>
<html>
<head>
	<?php echo Asset::css('color.css', array('id' => "css")); ?>
	<?php echo Asset::js('createTable.js'); ?>
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>
	<script>
		let value = $("input[type=radio][name=radio-buttons]:checked").val();
		$(document).ready(function() {
				$('#first').on('click','td', function() {
					value = $("input[type=radio][name=radio-buttons]:checked").val();
				});
				$('#second').on('click','td', function() {
					let addedClass = $("input[type=radio][name=radio-buttons]:checked").val();
					if ($(this).hasClass(addedClass)) {
						let id = $(this).attr("id");
						let list = $(this).attr("class");
						$(this).removeClass();
						let columnTwoDiv = $('#' + list + 'listID');
						let listOfColors = columnTwoDiv.text().split(' ');
						let index = listOfColors.indexOf(id);
						listOfColors.splice(index, 1);
						columnTwoDiv.empty();
						let newString = listOfColors[0];
							for (let j = 1; j < listOfColors.length; j++) {
								newString = newString + ' ' + listOfColors[j]
							}
						columnTwoDiv.append(newString);
					}
					else {
						$(this).addClass(addedClass);
						let id = $(this).attr("id");
						let list = $(this).attr("class");
						let columnTwoDiv = $('#' + list + 'listID');
						if (columnTwoDiv.is(':empty')) {
							columnTwoDiv.append(id);
						}
						else {
							let listOfColors = columnTwoDiv.text().split(' ');
							listOfColors.push(id);
							const sortArray = (a,b) => a.localeCompare(b, 'en', {numeric: true});
							listOfColors.sort(sortArray);
							columnTwoDiv.empty();
							let newString = listOfColors[0];
							for (let j = 1; j < listOfColors.length; j++) {
								newString = newString + ' ' + listOfColors[j]
							}
							columnTwoDiv.append(newString);
						}
					}
				});

		});
	</script>
</head>
<body>
<body onload="buildTables(<?=$numColsRows?>,<?=$numcolors?>, <?=$colorArr?>, <?=$hexArr?>)">
	<h1 id="colorpage">Color Page</h1>
	<main>
  <div id='edit colors'>
    <button onclick="window.location.href='https://www.cs.colostate.edu:4444/~fisher25/m1/index/m1/editDB';" id="button">Edit Colors</button>
  </div>
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
	</main>
</html>