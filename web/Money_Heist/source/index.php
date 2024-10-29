<?php
$user = isset($_COOKIE['user']) ? $_COOKIE['user'] : null;

if (!$user){
    $user = uniqid();
    $targetDirectory = 'files/' . $user . '/';
    mkdir($targetDirectory, 0777, true);
    setcookie('user', $user, time() + 3600, '/');
}

if ($user) {
    if (!file_exists('files/' . basename($user))){
        echo "User does not exist";
        setcookie('user', '', -1, '/');
        header("location: /index.php");
        die();
    }

    $userFiles = [];
?>
<!DOCTYPE html>
<html>
<head>
    <title>The Royal Mint</title>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Oswald&display=swap" rel="stylesheet">
    <link rel="stylesheet" type="text/css" href="assets/style.css">
</head>
<body>
    <div class="container">
        <h1>La Casa de Moneda y Timbre</h1>
        <h2>Welcome dear customer: <?php echo $user; ?>!</h1>
    </div>
    
    <div class="container">
        <h1>Your Vaults:</h1>
        <div class="vaults">
            <?php
                $userFiles = array_diff(scandir('files/' . $user), array('..', '.'));

                foreach ($userFiles as $file) {
                    echo '<a href="/download.php?file=' . $file .'">';
                    echo '<img src="/static/vault.png"><p>' . $file . '</p></a>';
                }
            ?>
        </div>
    </div>
    <div class="container">
        <form action="upload.php" method="post" enctype="multipart/form-data">
            <div class="upload_text">ADD VAULT</div>
            <div class="upload_space">
                <input type="file" name="file" id="file" required="required">
            </div>
            <input type="submit" value="Upload Vault">
        </form>
    </div>
</body>
</html>
<?php
} 

?>
