# sc-simulate
To simulate how a page is assembled in sitecore using php.

##Assembling pages
Pages are assembled using **parts** described below.

Order of assembly:
1.Create appropriate individual content pieces (raw or formatted).
2.Insert content into sublayout using `insert_block()` or `insert_raw()`.
3.Insert sublayout into page using `require` or `include`.
4.Modify page name, description, keywords if necessary.


## Parts
Templates are located in /kit/

###`page.php`
Pages renders the complete page. Usually have the common elements (`head.raw.inc`, `header.raw.inc`, `footer.raw.inc`) inserted using `insert_raw()`;

Only the following should be modified:
* `<title>` of the page
* `<meta name="description" content="">`
* `<meta name="keywords" content="">`

###Sublayouts (`sublayout-1-row.sub.inc`, `sublayout-2-row.sub.inc`, etc)
Sublayouts determine the layout of a page. Contains `.container` class divs and `.row` class divs.

Only the following should be modified:
* `class=` attribute for the div with `.row` or `.container` class
* `id=` attribute for the div with `.row` or `.container` class

###blocks.php
`blocks.php` contains the function `insert_block` and `insert_raw`, use either to insert the appropriate type of content.
* `insert_block($tag, $content, $id, $classes);`
* `insert_raw($content);`

More detailed documentation can be found in `/kit/blocks.php`.

###Content
Currently there are two types of content, formatted and raw, all stored in the `/content` directory.

**Formatted** uses a object called `$contObj` contains the variables `$title` and `$body`. Naming: `_name.block.inc`.

**Raw** has no restrictions on what can be inserted. Naming: `_name_.raw.inc`.