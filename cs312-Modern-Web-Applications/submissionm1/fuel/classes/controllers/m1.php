<?php

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
		$isNumColsRows = isset($_GET["numColsRows"]);
		$isNumColors = isset($_GET["numcolors"]);
		if ($isNumColsRows and $isNumColors) {
		 	$numColsRows = $_GET["numColsRows"];
			$numcolors = $_GET["numcolors"];
			$this->template->content = View::forge('pages/color', array(
				'numColsRows' => $numColsRows,
				'numcolors' => $numcolors
			));
		}
		else {
			$this->template->content = View::forge('pages/colorform');
			$numColsRows = Input::post('numColsRows');
			$numcolors = Input::post('numcolors');
			$this->template->content = View::forge('pages/color', array(
				'numColsRows' => $numColsRows,
				'numcolors' => $numcolors
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
	public function post_colorform() {
		$homeLink = 'https://www.cs.colostate.edu:4444/~fisher25/m1/index';
		$aboutLink = 'https://www.cs.colostate.edu:4444/~fisher25/m1/index/m1/about';
		$colorCoordinateLink = '#';
		$this->template->homeLink = $homeLink;
		$this->template->aboutLink = $aboutLink;
		$this->template->colorCoordinateLink = $colorCoordinateLink;
		$numColsRows = Input::post('numColsRows');
		$numcolors = Input::post('numcolors');
		if (($numColsRows < 27 and $numColsRows > 0) and ($numcolors < 11 and $numcolors > 0)) {
			$this->template->content = View::forge('pages/color', array(
				'numColsRows' => $numColsRows,
				'numcolors' => $numcolors,
			));
		}
		else {
			$this->template->content = View::forge('pages/colorform', array(
				'error' => "Invalid input, please provide valid input."
			));
		}
	}
}
