<?php
$type = isset($_COOKIE['type']) ? $_COOKIE['type'] : null;

if (!$type){
    $type = 'user';
    setcookie('type', 'user', time() + 3600, '/');
}

?>
<!DOCTYPE html>
<html>
<head>
    <title>School of Web</title>
    <link rel="stylesheet" type="text/css" href="assets/style.css">
</head>
<body>
    <?php
        if ($type !== 'admin'){
            echo 'You should not be here! Who taught you about this place?';
                }
        elseif ($_SERVER['HTTP_USER_AGENT'] !== 'teacher')
        {
            echo 'Only \'teacher\' agents can enter the premises';
        }
        else{
            echo 'Teachers also receive another gift: _1n_St3ps}';
        }
    ?>
</body>
</html>
<?php

?>
