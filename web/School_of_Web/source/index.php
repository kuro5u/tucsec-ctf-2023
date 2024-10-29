<?php
$type = isset($_COOKIE['type']) ? $_COOKIE['type'] : null ;

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
            echo "<!-- Only users of type admin can access this page -->
<!-- TUC{y0u_Bu!ld-->
";
            }
        else{
            echo "
            <h1>Hello admin!</h1>
            <p>Here is a gift for you: </b>_Kn0wl3Dge</b><p>
            <p>You can find more under /admin.php<p>
            ";
        }
    ?>
</body>
</html>
<?php

?>
