<?php

$user = isset($_COOKIE['user']) ? $_COOKIE['user'] : null;


if ($user) {
    if (!file_exists('files/' . basename($user))){
        echo "User does not exist";
        setcookie('user', '', -1, '/');
        header("location: /index.php");
        die();
    }
    $requestedFile = isset($_GET['file']) ? $_GET['file'] : null;

    if ($requestedFile) {
        $filePath = 'files/' . basename($user) . '/' . $requestedFile;

        if (file_exists($filePath)) {
            header('Content-Type: application/octet-stream');
            header('Content-Disposition: attachment; filename="' . $requestedFile . '"');

            readfile($filePath);
            exit();
        } else {
            echo "File " . $filePath . " not found.";
        }
    } else {
        echo "Please provide filename.";
    }
} else {
    echo "User has not logged in.";
    header("Location: /index.php");
    die();
}
?>
