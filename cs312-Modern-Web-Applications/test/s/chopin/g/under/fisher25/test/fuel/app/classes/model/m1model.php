<?php
namespace Model;
use \DB;

class m1Model extends \Model {

public static function add_m1($name, $hex) {
    list($insert_id, $rows_affected) = DB::insert('colors')->set(array(
    'Name' => $name,
    'Hex' => $hex,
  ))->execute();
}

public static function edit_m1($name, $hex, $ID) {
  DB::update('colors')->value("Name", $name)->where('ID', '=', $ID)->execute();
  DB::update('colors')->value("Hex", $hex)->where('ID', '=', $ID)->execute();
}

public static function delete_m1($name) {
  DB::delete('colors')->where('Name', '=', $name)->execute();
}

public static function getID_m1() { 
  $columns = array('ID');
  $array = DB::select_array($columns)->from('colors')->execute();
  return json_encode($array->as_array());
}

public static function getName_m1() { 
  $columns = array('Name');
  $array = DB::select_array($columns)->from('colors')->execute();
  return json_encode($array->as_array());
}

public static function getHex_m1() { 
  $columns = array('Hex');
  $array = DB::select_array($columns)->from('colors')->execute();
  return json_encode($array->as_array());
}

public static function table_size_m1() {
  $size = DB::count_records('colors');
  return $size;
}

}


?>