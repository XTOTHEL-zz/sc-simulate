<?php
/*
insert_block takes in a tag string, content string, id string, classes string and outputs the html code formatted with the coontent wrapped by the tag specified formatted with class and id, if specified.

insert_block($tag, $content, $id, $classes)
String, String, String, String -> String

$tag is the html tag that will be used to wrap the content block.
Example: if 'section' was passed in, the content will be wrapped with '<section>' tags.

$content, is the name of the file that contains the content object, located in the "/content/" directory.
Example: if 'teaser1' was passed in, the code will look for 'teaser1.block.inc' in the "/content" directory and include it. If it is not found, the code will halt.

$id, optional, is the id for that block.
Example: if 'teasers' was passed in, the tag will have an id of 'teasers', <section id="teasers">.

$classes, optional, is the classes to be applied for that block.
Example: if 'col-md-8 red' was passed in, the tag will have the classes 'col-md-8' and 'red' applied to it, <section class="col-md-8 red">.
*/

function insert_block($tag, $content, $id=NULL, $classes=NULL) {

	//begin content block
	$temp = '<'.$tag.' ';

	//optional id and class specifications
	if($id){$temp = $temp.'id="'.$id.'" ';}
	if($classes){$temp = $temp.'class="'.$classes.'" ';}

	echo $temp.'>';

	//including the content object specified
	$content = $_SERVER["DOCUMENT_ROOT"].'/content/'.$content.'.block.inc';

	require $content;

	//output content title and content body
	echo $contObj->title;
	echo $contObj->body;
	
	//end content block
	echo '</'.$tag.'>';
}


/*
insert_raw tags in a content string and outputs the file raw html contained in that file.
function insert_raw($content)
String -> String

$content, is the name of the file that contains the raw html code to be displayed.
Example: if 'teaser1' was passed in, the code will look for 'teaser1.raw.inc' in the "/content" directory and include it. If it is not found, the code will halt.
*/
function insert_raw($content){
	//including the raw html content specified
	$content = $_SERVER["DOCUMENT_ROOT"].'/content/'.$content.'.raw.inc';
	require $content;
}
?>