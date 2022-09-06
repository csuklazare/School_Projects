var previousColor;

function buildTables(n, numcolors) {
	let tableOne = document.getElementById('first');
	let columnsOne = 2;
	let rowsOne = numcolors;
	generateTableOne(tableOne, rowsOne, columnsOne);
	let tableTwo = document.getElementById('second');
	let columnsTwo = n+1;
	let rowsTwo = n+1;
	generateTableTwo(tableTwo, rowsTwo, columnsTwo);
}
function generateTableOne(table, rows, columns) {
	let divID = "columnOneDivs";
	let col1 = "columnOne";
	let col2 = "columnTwo";
	for (let i = 0; i < rows; i++) {
		let row = table.insertRow();
		for (let j = 0; j < columns; j++) {
			if (j == 0) {
				let cell = row.insertCell();
				cell.setAttribute("class", col1);
				let div = fillInTableOneButtons(divID);
				cell.appendChild(div);
			}
			else {
				let cell = row.insertCell();
				cell.setAttribute("class", col2);
			}	
		}

	}
	createDropDownColorMenu(document.getElementsByClassName(divID));
}
function fillInTableOneButtons(divID) {
	let div = document.createElement("div");
	div.setAttribute("class", divID);
	return div;
}
function createDropDownColorMenu(elements) {
	const colors = ['black','blue','brown','grey','green','orange','purple','red','teal','yellow'];
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
			if (i == 0) {
					let text = document.createTextNode(alphabet[j]);
					cell.appendChild(text);
			}
			else {
				if (j == 0) {
					let text = document.createTextNode(i);
					cell.appendChild(text);
				}
				else {
					let text = document.createTextNode('');
					cell.appendChild(text);
				}
			}
		}
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
	for (let i = 0; i < length; i++) {
		colorArray.push(select[i].value);
	}
	for (let i = 0; i < length; i++) {
		divs[i].innerHTML = colorArray[i];
		select[0].remove();
	}

}
