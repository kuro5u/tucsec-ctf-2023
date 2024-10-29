<?php
$user = isset($_COOKIE['user']) ? $_COOKIE['user'] : null;
if (!file_exists('files/' . basename($user))){
    echo "User does not exist";
    header("Location: /index.php");
    die();
}

if ($user) {
    if (!file_exists('files/' . basename($user))){
        echo "User does not exist";
        setcookie('user', '', -1, '/');
        header("location: /index.php");
        die();
    }
    $targetDirectory = 'files/' . $user . '/';

    if (isset($_FILES['file'])) {
        $uploadedFile = $_FILES['file'];


        $targetFile = $targetDirectory . $_FILES['file']['name'];

        if (move_uploaded_file($uploadedFile['tmp_name'], $targetFile)) {
            header('Location: index.php');
        } else {
            echo "File upload failed.";
        }

        if ($uploadedFile['size'] > 100000) {
            echo "File size is too large. Maximum file size allowed is 100KB.";
            die();
        }
    }
} else {
    echo "User has not logged in.";
    header("Location: /index.php");
    die();
}
?>
