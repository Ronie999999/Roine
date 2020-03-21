<link rel="stylesheet" type="text/css" href="sql.css">
<div class="title">
    SQL_time_injection
</div>
<div class="search" id="container">
    <form id="form" action="index.php" method="post">
        <input id="search1" type="text" name="sql" placeholder=" Input ID ">
    </form>
</div>
<?php
include "config.php";
if (isset($_POST["sql"])) {
    $search = "SELECT * FROM users.users WHERE id=";
    $msg = $search.$_POST["sql"].";";
    $msg = trim($msg);
    $con = new mysqli($host, $username, $password);
    if ($con->connect_error) {
        die($con->connect_error);
    }
    $con->query($msg);

    $con->close();
}
?>