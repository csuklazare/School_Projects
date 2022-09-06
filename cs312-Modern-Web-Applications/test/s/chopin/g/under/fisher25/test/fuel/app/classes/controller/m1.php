<?php
use \Model\m1Model;
class Controller_m1 extends Controller_Template
{

	public function action_index()
	{
		$homeLink = '#';
		$aboutLink = 'https://www.cs.colostate.edu:4444/~fisher25/m1/index/m1/about';
		$colorCoordinateLink = 'https://www.cs.colostate.edu:4444/~fisher25/m1/index/m1/colorform';
		$this->template->homeLink = $homeLink;
		$this->template->aboutLink = $aboutLink;
		$this->template->colorCoordinateLink = $colorCoordinateLink;
        $this->template->content = View::forge('pages/index');
		$this->template->homeLink = $homeLink;
		$this->template->aboutLink = $aboutLink;
		$this->template->colorCoordinateLink = $colorCoordinateLink;
	}

    public function action_about()
    {
		$homeLink = 'https://www.cs.colostate.edu:4444/~fisher25/m1/index';
		$aboutLink = '#';
		$colorCoordinateLink = 'https://www.cs.colostate.edu:4444/~fisher25/m1/index/m1/colorform';
		$this->template->homeLink = $homeLink;
		$this->template->aboutLink = $aboutLink;
		$this->template->colorCoordinateLink = $colorCoordinateLink;
        $this->template->content = View::forge('pages/about');
    }

    public function action_color() 
    {
		$homeLink = 'https://www.cs.colostate.edu:4444/~fisher25/m1/index';
		$aboutLink = 'https://www.cs.colostate.edu:4444/~fisher25/m1/index/m1/about';
		$colorCoordinateLink = 'https://www.cs.colostate.edu:4444/~fisher25/m1/index/m1/colorform';
		$this->template->homeLink = $homeLink;
		$this->template->aboutLink = $aboutLink;
		$this->template->colorCoordinateLink = $colorCoordinateLink;
		$colorArr = m1Model::getName_m1();
		$hexArr = m1Model::getHex_m1();
		$isNumColsRows = isset($_GET["numColsRows"]);
		$isNumColors = isset($_GET["numcolors"]);
		if ($isNumColsRows and $isNumColors) {
		 	$numColsRows = $_GET["numColsRows"];
			$numcolors = $_GET["numcolors"];
			$this->template->content = View::forge('pages/color', array(
				'numColsRows' => $numColsRows,
				'numcolors' => $numcolors,
				'colorArr' => $colorArr,
				'hexArr' => $hexArr
			));
		}
		else {
			$this->template->content = View::forge('pages/colorform');
			$numColsRows = Input::post('numColsRows');
			$numcolors = Input::post('numcolors');
			$this->template->content = View::forge('pages/color', array(
				'numColsRows' => $numColsRows,
				'numcolors' => $numcolors,
				'colorArr' => $colorArr,
				'hexArr' => $hexArr
			));
		}
    }
	public function action_colorform()
	{
		$homeLink = 'https://www.cs.colostate.edu:4444/~fisher25/m1/index';
		$aboutLink = 'https://www.cs.colostate.edu:4444/~fisher25/m1/index/m1/about';
		$colorCoordinateLink = '#';
		$this->template->homeLink = $homeLink;
		$this->template->aboutLink = $aboutLink;
		$this->template->colorCoordinateLink = $colorCoordinateLink;
		$this->template->content = View::forge('pages/colorform');
	}
	public function action_editDB() {
		$formType = isset($_GET["formType"]);
		$name = isset($_GET["name"]);
		if ($formType and $name) {
			$formType = $_GET["formType"];
			$name = $_GET["name"];
			if ($formType == "delete") {
				m1Model::delete_m1($name);
			}
		}
		$homeLink = 'https://www.cs.colostate.edu:4444/~fisher25/m1/index';
		$aboutLink = 'https://www.cs.colostate.edu:4444/~fisher25/m1/index/m1/about';
		$colorCoordinateLink = 'https://www.cs.colostate.edu:4444/~fisher25/m1/index/m1/colorform';
		$this->template->homeLink = $homeLink;
		$this->template->aboutLink = $aboutLink;
		$this->template->colorCoordinateLink = $colorCoordinateLink;
		$ID = m1Model::getID_m1();
		$Name = m1Model::getName_m1();
		$Hex = m1Model::getHex_m1();
		$this->template->content = View::forge('pages/editDB', array(
			'ID' => $ID, 
			'Name' => $Name, 
			'Hex' => $Hex
		));
	  }
	public function post_editDB() {
		$formType = isset($_GET["formType"]);
		if ($formType) {
			$formType = $_GET["formType"];
		}
		if ($formType == "add") {
			$hexValue = Input::post('hexValue');
			$colorName = Input::post('colorName');
			m1Model::add_m1($colorName, $hexValue);
		}
		else if ($formType == "edit") {
			$ID = $_GET['id'];
			$editName = Input::post('editName');
			$editHex = Input::post('editHex');
			m1Model::edit_m1($editName, $editHex, $ID);
		}
		$homeLink = 'https://www.cs.colostate.edu:4444/~fisher25/m1/index';
		$aboutLink = 'https://www.cs.colostate.edu:4444/~fisher25/m1/index/m1/about';
		$colorCoordinateLink = 'https://www.cs.colostate.edu:4444/~fisher25/m1/index/m1/colorform';
		$this->template->homeLink = $homeLink;
		$this->template->aboutLink = $aboutLink;
		$this->template->colorCoordinateLink = $colorCoordinateLink;
		$ID = m1Model::getID_m1();
		$Name = m1Model::getName_m1();
		$Hex = m1Model::getHex_m1();
		$this->template->content = View::forge('pages/editDB', array(
			'ID' => $ID, 
			'Name' => $Name, 
			'Hex' => $Hex
		));
	}
	public function post_colorform() {
		$homeLink = 'https://www.cs.colostate.edu:4444/~fisher25/m1/index';
		$aboutLink = 'https://www.cs.colostate.edu:4444/~fisher25/m1/index/m1/about';
		$colorCoordinateLink = '#';
		$this->template->homeLink = $homeLink;
		$this->template->aboutLink = $aboutLink;
		$this->template->colorCoordinateLink = $colorCoordinateLink;
		$numColsRows = Input::post('numColsRows');
		$numcolors = Input::post('numcolors');
		$colorArr = m1Model::getName_m1();
		$hexArr = m1Model::getHex_m1();
		$dataBaseColorsNum = m1Model::table_size_m1();
		if (($numColsRows < 27 and $numColsRows > 0) and ($numcolors <= $dataBaseColorsNum and $numcolors > 0)) {
			$this->template->content = View::forge('pages/color', array(
				'numColsRows' => $numColsRows,
				'numcolors' => $numcolors,
				'colorArr' => $colorArr,
				'hexArr' => $hexArr

			));
		}
		else {
			$this->template->content = View::forge('pages/colorform', array(
				'error' => "Invalid input, please provide valid input."
			));
		}
	}
}
