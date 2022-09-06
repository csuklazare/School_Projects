var previousColor;
var currColor = 'black';

function buildTables(n, numcolors, colorArr, hexArr) {
	let colors = [];
	let hexes = [];
	for (let i = 0; i < colorArr.length; i++) {
		colors.push(colorArr[i].Name);
		hexes.push(hexArr[i].Hex);
	}
	generateColorClasses(colors, hexes);
	let tableOne = document.getElementById('first');
	let columnsOne = 2;
	let rowsOne = numcolors;
	generateTableOne(tableOne, rowsOne, columnsOne, colors);
	let tableTwo = document.getElementById('second');
	let columnsTwo = n+1;
	let rowsTwo = n+1;
	generateTableTwo(tableTwo, rowsTwo, columnsTwo);
}
function generateColorClasses(colors, hexes) {
	let style = document.createElement('style');
	let styleString = '';
	for (let i = 0; i < colors.length; i++) {
		styleString = styleString + '.' + colors[i] + ' { background-color: #' + hexes[i] + '; }\n';
	}
	style.innerHTML = styleString;
	document.getElementsByTagName('head')[0].appendChild(style);

}
function generateTableOne(table, rows, columns, colors) {
	let dropdownID = "dropDownID";
	let radioID = "radioID";
	let col1 = "columnOne";
	let col2 = "columnTwo";
	let radioClass = "radioClass";
	let dropdownClass = "dropdownClass";
	let col2Class = "columnTwoClass";
	let list = "listID";
	for (let i = 0; i < rows; i++) {
		let row = table.insertRow();
		for (let j = 0; j < columns; j++) {
			if (j == 0) {
				let cell = row.insertCell();
				cell.setAttribute("class", col1);
				let div = fillInTableButtons(colors[i]+dropdownID, dropdownClass);
				cell.appendChild(div);
				let divTwo = fillInTableButtons(colors[i]+radioID, radioClass);
				cell.appendChild(divTwo);
			}
			else {
				let cell = row.insertCell();
				cell.setAttribute("class", col2);
				let div = fillInTableButtons(colors[i]+list, col2Class);
				cell.appendChild(div);
			}	
		}
	}
	createDropDownColorMenu(document.getElementsByClassName(dropdownClass), colors);
	createRadioButtons(document.getElementsByClassName(radioClass), colors);

}
function fillInTableButtons(divID, className) {
	let div = document.createElement("div");
	div.setAttribute("class", className);
	div.setAttribute("id", divID);
	return div;
}
function createRadioButtons(elements, colors) {
	for (let i = 0; i < elements.length; i++) {
		let radioButton  = document.createElement("input");
		radioButton.setAttribute("type", "radio");
		radioButton.setAttribute("name", "radio-buttons");
		radioButton.setAttribute("class", "radio-buttons");
		radioButton.setAttribute("value", colors[i]);
		if (i == 0) {
			radioButton.checked = true;
			currColor = colors[i];
		}
		let label = document.createElement("label");
		label.htmlFor = "radio-buttons";
		label.innerHTML = colors[i];
		label.setAttribute("id", colors[i] + "radiobutton");
		elements[i].appendChild(label).appendChild(radioButton);
	}
}
function rebuildRadioButton(color) {
	let radioButton = document.createElement("input");
	radioButton.setAttribute("type", "radio");
	radioButton.setAttribute("name", "radio-buttons");
	radioButton.setAttribute("class", "radio-buttons");
	radioButton.setAttribute("value", color);
	radioButton.checked = true;
	return radioButton;
}
function createDropDownColorMenu(elements, colors) {
	for (let i = 0; i < elements.length; i++) {
		let select = document.createElement("select");
		select.name = "colors";
		select.id = colors[i];
		for (const color of colors) {
			let option = document.createElement("option");
			option.value = color;
			option.text = color;
			select.appendChild(option);
		}
		select.value = colors[i];
		select.addEventListener("change", function() {
			previousColor = select.id;
			let index = 0;
			let divArray = document.getElementsByTagName("SELECT");
			let p = document.getElementById("error");
			for (let k = 0; k < divArray.length; k++) {
				if (select.value == divArray[k].value) {
					index = k;
				}
			}
			for (let j = 0; j < divArray.length; j++) {
				if (index != j) {
					if (divArray[j].value == select.value) {
						select.value = previousColor;
						p.textContent = "Two colors can't be the same. Each dropdown needs to be unique!";
						return;
					}
				}
			}
			select.id = select.value;
			p.textContent = "";
			document.getElementById(previousColor + "radiobutton").setAttribute('id', select.id + "radiobutton")
			document.getElementById(select.id + "radiobutton").innerHTML = select.id;
			document.getElementById(select.id + "radiobutton").appendChild(rebuildRadioButton(select.id));
			document.getElementById(previousColor + "listID").setAttribute('id', select.id + "listID");
			document.getElementById(previousColor + "radioID").setAttribute('id', select.id + "radioID");
			$("." + previousColor).addClass(select.id);
			$("." + previousColor).removeClass(previousColor);
			console.log(document.getElementById(previousColor + "radiobutton"));

		});
		let label = document.createElement("label");
		label.htmlFor = "colors";
		elements[i].appendChild(label).appendChild(select);
	}
}
function generateTableTwo(table, rows, columns) {
	const alphabet = ["","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"];
	for (let i = 0; i < rows; i++) {
		let row = table.insertRow();
		for (let j = 0; j < columns; j++) {
			let cell = row.insertCell();
			let id = alphabet[j] + i;
			cell.setAttribute("id", id);
			if (i == 0) {
					let text = document.createTextNode(alphabet[j]);
					cell.appendChild(text);
			}
			else {
				if (j == 0) {
					let text = document.createTextNode(i);
					cell.appendChild(text);
				}
			}
		}
	}
}
//create the edit colors table
function editDB(ID, Name, Hex) {
  console.log(ID);
  console.log(Name);
  console.log(Hex);

  let table = document.getElementById("dbTable");
  for (let i = 0; i < ID.length; i++) {
    let row = table.insertRow();
    
    let cell = row.insertCell();
    let text = document.createTextNode(ID[i].ID);
    cell.appendChild(text);
    
    cell = row.insertCell();
	cell.setAttribute("id", "color" + i);
    text = document.createTextNode(Name[i].Name);
    cell.appendChild(text);
    
    cell = row.insertCell();
	cell.setAttribute("id", "hex" + i);
    text = document.createTextNode(Hex[i].Hex);
    cell.appendChild(text);
    
    //still have to make button functions
    cell = row.insertCell();
    let btn = document.createElement("button");
	cell.setAttribute("class", "delete");
    btn.innerHTML = "Delete";
	btn.onclick = function () {
		location.href = ('https://www.cs.colostate.edu:4444/~fisher25/m1/index/m1/editDB' + '?formType=delete&name=' + Name[i].Name);
	};
	btn.setAttribute("id", "delete" + Name[i].Name);
	btn.setAttribute("class", "delete");
    cell.appendChild(btn);
    
    cell = row.insertCell();
	cell.setAttribute("id", "edit" + i);
    btn = document.createElement("button");
	btn.setAttribute("id", "bttn" + i);

	btn.onclick = function () {
		let colorCell = document.getElementById("color" + btn.id.substring(4));
		let hexCell = document.getElementById("hex" + btn.id.substring(4));
		let btnCell = document.getElementById("edit" + btn.id.substring(4));
		var form = document.createElement("form");
    	form.setAttribute("method", "post");
    	form.setAttribute("action", "https://www.cs.colostate.edu:4444/~fisher25/m1/index/m1/editDB?formType=edit&id=" + ID[i].ID);

		var name = document.createElement("input");
    	name.setAttribute("type", "text");
    	name.setAttribute("name", "editName");

		var hex = document.createElement("input");
    	hex.setAttribute("type", "text");
    	hex.setAttribute("name", "editHex");

		var submit = document.createElement("input");
		submit.setAttribute("type", "submit");
		submit.setAttribute("value", "Submit");

		colorCell.removeChild(colorCell.firstChild);
		hexCell.removeChild(hexCell.firstChild);
		btnCell.removeChild(btnCell.firstChild);

		form.appendChild(name);
		form.appendChild(hex);
		form.appendChild(submit);
		document.getElementsByTagName("body")[0].appendChild(document.createTextNode("Edit Row"));
		document.getElementsByTagName("body")[0].appendChild(form);
		
	};
    btn.innerHTML = "Edit";
    cell.appendChild(btn);
  }
}

function printView() {
	let p = document.getElementById("error");
	p.textContent = "";
	let nav = document.getElementById('nav');
	nav.remove();
	let button = document.getElementById('button');
	button.remove();
	document.getElementById('colorpage').innerHTML = "The Boolean Hooligans";
	let css = document.getElementById('css');
	document.getElementById('brand').style.filter = "grayscale(100%)";
	let select = document.getElementsByTagName('select');
	let divs = document.getElementsByClassName('columnOneDivs');
	let colorArray = Array();
	let length = select.length;
	$("#second td").removeClass();
	$('.radioClass').remove();
	$('main').css("border", "none");
	for (let i = 0; i < length; i++) {
		colorArray.push(select[i].value);
	}
	for (let i = 0; i < length; i++) {
		divs[i].innerHTML = colorArray[i];
		select[0].remove();
	}

}