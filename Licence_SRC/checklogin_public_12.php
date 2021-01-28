<?php	
	require('criptografia12.php');
	require('accounts.php');
	session_start();
	
	$username = isset($_POST["username"]) ? $_POST["username"] : "";
	$password = isset($_POST["password"]) ? $_POST["password"] : "";
	$sn = isset($_POST["sndisk"]) ? $_POST["sndisk"] : "";
	$apversion = isset($_POST["appversion"]) ? $_POST["appversion"] : "";
	
	$sessionid = isset($_POST["sessionid"]) ? $_POST["sessionid"] : "";
	$os = isset($_POST["os"]) ? $_POST["os"] : "";
	$pcname = isset($_POST["pcname"]) ? $_POST["pcname"] : "";
	$pcuser = isset($_POST["pcuser"]) ? $_POST["pcuser"] : "";
	
	// $myfile = fopen("log.txt", "a");			
		// fwrite($myfile, '[' . date("d/m/Y h:m:s") . "] " . $os . " - " . $sn . " - " . $username . " - " . $sessionid . " - hải " . $password . "\r\n");
		// fclose($myfile);
		
	function xor_str($textInput, $keyXor){
		$result = array();

		$j = 0;
		for ($i = 0; $i < strlen($textInput); $i++)
		{
			if ($j >= strlen($keyXor)) $j = 0;
			$charCode = ord($textInput[$i]);
			// print($charCode);
			$keychar1 = ord($keyXor[$j]);
			// print($keychar1);
			$combinedChar = $charCode ^ $keychar1;
			// print($combinedChar);
			if($combinedChar == 0) $combinedChar =  $charCode;        //cai nay co the dung` sau
			if($combinedChar == 38) $combinedChar =  $charCode;        //cai nay co the dung` sau
			if($combinedChar == 61) $combinedChar =  $charCode;        //cai nay co the dung` sau

			$j = $j + 1;
			$result[$i] = $combinedChar;
			
			// print("i=" . $i . "   combinedChar: " . $result[$i] . ' = ' . $combinedChar . ' => ' . $charCode . ' xor ' . $keychar1);
			// print('<br/>');
			
		}
		$str = "";
		for ($i = 0; $i < count($result); $i++)
		{
			$str .= chr($result[$i]);
		}
		return $str;
	}
	
	function custom_parse_str($str){
		$res = array();
		$arr1 = explode("&",$str);
		foreach($arr1 as $a){
			$arr2 = explode("=",$a);
			$res[$arr2[0]] = $arr2[1];
		}
		return $res;
	}
		
	if (isset($_POST["token"])){
		$token = str_replace(" ", "+", $_POST["token"]);		

		$foo = new Cipher;
		$data = $foo->decrypt($token);
		
		$parsedpost = array();
		// parse_str($data, $parsedpost);
		$parsedpost = custom_parse_str($data);
		
		// $username = isset($parsedpost["username"]) ? $parsedpost["username"] : "";
		// $password = isset($parsedpost["password"]) ? $parsedpost["password"] : "";
		// $sn = isset($parsedpost["sndisk"]) ? $parsedpost["sndisk"] : "";
		// $apversion = isset($parsedpost["appversion"]) ? $parsedpost["appversion"] : "";
		
		// $sessionid = isset($parsedpost["sessionid"]) ? $parsedpost["sessionid"] : "";
		// $os = isset($parsedpost["os"]) ? $parsedpost["os"] : "";
		// $pcname = isset($parsedpost["pcname"]) ? $parsedpost["pcname"] : "";
		// $pcuser = isset($parsedpost["pcuser"]) ? $parsedpost["pcuser"] : "";
		
		$username = isset($parsedpost["INFO5"]) ? xor_str($parsedpost["INFO5"], "mAh0aiuZopaTgu4c12ab34cfg") : "";
		$password = isset($parsedpost["INFO2"]) ? xor_str($parsedpost["INFO2"], "mAh0aiuZopaTgu4c12ab34cfg") : "";
		$sn = isset($parsedpost["INFO3"]) ? xor_str($parsedpost["INFO3"], "1C4nG49a2Ho7Id1HatG1e95at1rXsY50") : "";
		$sn2 = isset($parsedpost["INFO6"]) ? xor_str($parsedpost["INFO6"], "1C4nG49a2Ho7Id1HatG1e95at1rXsY50") : "";
		$apversion = isset($parsedpost["appversion"]) ? $parsedpost["appversion"] : "";
		
		$sessionid = isset($parsedpost["sessionid"]) ? $parsedpost["sessionid"] : "";
		$os = isset($parsedpost["INFO4"]) ? xor_str($parsedpost["INFO4"], "9h1ch12TP49fNghich8xthoi29Ge12mT") : "";
		$pcname = isset($parsedpost["INFO7"]) ? xor_str($parsedpost["INFO7"], "9h1ch12TP49fNghich8xthoi29Ge12mT") : "";
		$pcuser = isset($parsedpost["INFO8"]) ? xor_str($parsedpost["INFO8"], "9h1ch12TP49fNghich8xthoi29Ge12mT") : "";

		// $myfile = fopen("log.txt", "a");			
		// fwrite($myfile, '[' . date("d/m/Y h:m:s") . "] " . $token . "\r\n");
		// fwrite($myfile, '[' . date("d/m/Y h:m:s") . "] " . print_r($parsedpost,true) . "\r\n");
		
		// $str = xor_str($parsedpost["INFO1"], "9h1ch12TP49fNghich8xthoi29Ge12mT");
		// fwrite($myfile, '[' . date("d/m/Y h:m:s") . "] " . $str . "\r\n");
		// $str = xor_str($parsedpost["INFO2"], "mAh0aiuZopaTgu4c12ab34cfg");
		// fwrite($myfile, '[' . date("d/m/Y h:m:s") . "] " . $str . "\r\n");
		// $str = xor_str($parsedpost["INFO3"], "1C4nG49a2Ho7Id1HatG1e95at1rXsY50");
		// fwrite($myfile, '[' . date("d/m/Y h:m:s") . "] " . $str . "\r\n");
		// $str = xor_str($parsedpost["INFO4"], "9h1ch12TP49fNghich8xthoi29Ge12mT");
		// fwrite($myfile, '[' . date("d/m/Y h:m:s") . "] " . $str . "\r\n");
		// $str = xor_str($parsedpost["INFO5"], "mAh0aiuZopaTgu4c12ab34cfg");
		// fwrite($myfile, '[' . date("d/m/Y h:m:s") . "] " . $str . "\r\n");
		// $str = xor_str($parsedpost["INFO6"], "1C4nG49a2Ho7Id1HatG1e95at1rXsY50");
		// fwrite($myfile, '[' . date("d/m/Y h:m:s") . "] " . $str . "\r\n");
		// $str = xor_str($parsedpost["INFO7"], "9h1ch12TP49fNghich8xthoi29Ge12mT");
		// fwrite($myfile, '[' . date("d/m/Y h:m:s") . "] " . $str . "\r\n");
		// $str = xor_str($parsedpost["INFO8"], "9h1ch12TP49fNghich8xthoi29Ge12mT");
		// fwrite($myfile, '[' . date("d/m/Y h:m:s") . "] " . $str . "\r\n");
		// $str = xor_str($parsedpost["INFO9"], "9h1ch12TP49fNghich8xthoi29Ge12mT");
		// fwrite($myfile, '[' . date("d/m/Y h:m:s") . "] " . $str . "\r\n");
		
		
		// fwrite($myfile, '[' . date("d/m/Y h:m:s") . "] " . $data . "\r\n");
		
		// fclose($myfile);
		// exit();
	} 
	
	if (empty($apversion)){
		// $myfile = fopen("log.txt", "a");			
		// fwrite($myfile, '[' . date("d/m/Y h:m:s") . "] " . print_r($_POST,true) . "\r\n" . print_r($_GET,true) . "\r\n");
		// fclose($myfile);
		// exit();
	}
	
	
	
	
	// $tw_users = array(		
	
	// );
	
	
	// $tw_users_1_day = array(	
	
	// );
	
	// $tw_users_7_day = array(
	
	// );
	
	// $cn_users_2hours = array(
	
	// );

	
	if (in_array($username,$tw_users))
	{
		//check active
		if (!check_active_tw($username)){
			//active
			active_tw($username);
			log_active_tw($username);			
		}
	}
	if (in_array($username,$cn_users_2hours))
	{
		//check active
		if (!check_active_tw($username)){
			//active
			active_cn_2hours($username);
			log_active_tw($username);			
		}
	}
	
	if (in_array($username,$tw_users_7_day))
	{
		//check active
		if (!check_active_tw($username)){
			//active
			active_tw_7_day($username);
			log_active_tw($username);			
		}
	}

	if (in_array($username,$tw_users_1_day))
	{
		//check active
		if (!check_active_tw($username)){
			//active
			active_tw_1_day($username);
			log_active_tw($username);			
		}
	}
	
	if (in_array($username,$u_day_cn))
	{
		//check active
		if (!check_active_tw($username)){
			//active
			active_cn_1_day($username);
			log_active_tw($username);			
		}
	}
	
	function log_active_tw($name){
		$servername = "localhost";
		$username = "bot4league";
		$password = "ao5a2N7fo7H400gB";
		$dbname = "bot4league";

		if (empty($name)){
			
		}
		// Create connection
		$conn = new mysqli($servername, $username, $password, $dbname);
		// Check connection
		if ($conn->connect_error) {
			
		} 
		
		$name = $conn->real_escape_string($name);
		$date_create = date('Y-m-d H:i:s', strtotime('now'));
		$sql = "INSERT INTO `tw_active`(username,created_date) VALUES('$name','$date_create') ";
		$conn->query($sql);		
	}
	
	function active_tw($name){
		$servername = "localhost";
		$username = "bot4league";
		$password = "ao5a2N7fo7H400gB";
		$dbname = "bot4league";

		if (empty($name)){
			return true;
		}
		// Create connection
		$conn = new mysqli($servername, $username, $password, $dbname);
		// Check connection
		if ($conn->connect_error) {
			return true;
		} 
		
		$name = $conn->real_escape_string($name);
		
		$hansudung = date('Y-m-d H:i:s', strtotime('+30 days'));	
	
		$sql = "UPDATE `users` SET hansudung = '$hansudung' WHERE username = '$name' ";	
		$conn->query($sql);		
	}
	
	function active_tw_1_day($name){
		$servername = "localhost";
		$username = "bot4league";
		$password = "ao5a2N7fo7H400gB";
		$dbname = "bot4league";

		if (empty($name)){
			return true;
		}
		// Create connection
		$conn = new mysqli($servername, $username, $password, $dbname);
		// Check connection
		if ($conn->connect_error) {
			return true;
		} 
		
		$name = $conn->real_escape_string($name);
		
		$hansudung = date('Y-m-d H:i:s', strtotime('+1 days'));	
	
		$sql = "UPDATE `users` SET hansudung = '$hansudung' WHERE username = '$name' ";	
		$conn->query($sql);		
	}
	
	function active_cn_2hours($name){
		$servername = "localhost";
		$username = "bot4league";
		$password = "ao5a2N7fo7H400gB";
		$dbname = "bot4league";

		if (empty($name)){
			return true;
		}
		// Create connection
		$conn = new mysqli($servername, $username, $password, $dbname);
		// Check connection
		if ($conn->connect_error) {
			return true;
		} 
		
		$name = $conn->real_escape_string($name);
		
		$hansudung = date('Y-m-d H:i:s', strtotime('+2 hours'));	
	
		$sql = "UPDATE `users` SET hansudung = '$hansudung' WHERE username = '$name' ";	
		$conn->query($sql);		
	}
	
	function active_tw_7_day($name){
		$servername = "localhost";
		$username = "bot4league";
		$password = "ao5a2N7fo7H400gB";
		$dbname = "bot4league";

		if (empty($name)){
			return true;
		}
		// Create connection
		$conn = new mysqli($servername, $username, $password, $dbname);
		// Check connection
		if ($conn->connect_error) {
			return true;
		} 
		
		$name = $conn->real_escape_string($name);
		
		$hansudung = date('Y-m-d H:i:s', strtotime('+7 days'));	
	
		$sql = "UPDATE `users` SET hansudung = '$hansudung' WHERE username = '$name' ";	
		$conn->query($sql);		
	}
	
	function active_cn_1_day($name){
		$servername = "localhost";
		$username = "bot4league";
		$password = "ao5a2N7fo7H400gB";
		$dbname = "bot4league";

		if (empty($name)){
			return true;
		}
		// Create connection
		$conn = new mysqli($servername, $username, $password, $dbname);
		// Check connection
		if ($conn->connect_error) {
			return true;
		} 
		
		$name = $conn->real_escape_string($name);
		
		$hansudung = date('Y-m-d H:i:s', strtotime('+1 days'));	
	
		$sql = "UPDATE `users` SET hansudung = '$hansudung' WHERE username = '$name' ";	
		$conn->query($sql);		
	}
	
	
	
	function check_active_tw($name)
	{
		$servername = "localhost";
		$username = "bot4league";
		$password = "ao5a2N7fo7H400gB";
		$dbname = "bot4league";

		if (empty($name)){
			return true;
		}
		// Create connection
		$conn = new mysqli($servername, $username, $password, $dbname);
		// Check connection
		if ($conn->connect_error) {
			return true;
		} 
		
		$name = $conn->real_escape_string($name);
		$sql = "SELECT id FROM tw_active WHERE username= '$name'";		
		$rows = $conn->query($sql);
		if($rows->num_rows > 0){
			return true;
		}		
		return false;
	}
	
	
	
 	// if ($username == "QKVN_Free" || $username == "bot4league_com" || $username == "thuetoolgame_com"){
		// echo "ret=abc1234567&token=".time()."&code=0";
		// insert_log($username, $_SERVER['REMOTE_ADDR'],trim($sn),trim($os),trim($pcname),trim($pcuser),trim($apversion));
		// exit();
	// } 
	
 	// if ($username == "toir123"){
		// echo "ret=abc1234567&token=".time()."&code=0";
		// insert_log($username, $_SERVER['REMOTE_ADDR'],trim($sn),trim($os),trim($pcname),trim($pcuser),trim($apversion));
		// exit();
	// } 
	

	
	
	// if ($username == "fakervn"){
		// echo "ret=abc123456&token=".time()."&code=0";
		// insert_log($username, $_SERVER['REMOTE_ADDR'],trim($sn),trim($os),trim($pcname),trim($pcuser),trim($apversion));
		// exit();
	// }
	
	// if ($username == "suunhi" || $username == "chunglk"){
		// $myfile = fopen("log.txt", "a");			
		// fwrite($myfile, '[' . date("d/m/Y h:m:s") . "] " . $os . " - " . $sn . " - " . $username . " - " . $sessionid . " -  " . $password . "\r\n");
		// fclose($myfile);
	// }
	/*if ($username == "Nguyen.TienHai" || $sn == "S13QJ90S112636" || $username == "chunglk"){
		$myfile = fopen("log.txt", "a");			
		fwrite($myfile, '[' . date("d/m/Y h:m:s") . "] " . $os . " - " . $sn . " - " . $username . " - " . $sessionid . " - " . $password . "\r\n");
		fclose($myfile);
		
		if (!empty($sessionid)){// neu co session
			// $sid = file_get_contents('session.txt', true);
			$sid = getSession($username);
			if($sessionid == $sid){ //kiem tra session co ton tai hay khong, neu ton tai thi tra ve ss
				insert_log($username, $_SERVER['REMOTE_ADDR'],trim($sn),trim($os),trim($pcname),trim($pcuser),trim($apversion));
				
				echo "ret=".$sid."&token=".time()."&code=0";
			}
			else{
				//khong ton tai session tra ve session rong
				// $myfile = fopen("log.txt", "a");			
				// fwrite($myfile, '[' . date("d/m/Y h:m:s") . "] 222 " . $os . " - " . $sn . " - " . $username . " - " . $sessionid . " - " . $password . "\r\n");
				// fclose($myfile);
				echo "ret=&token=".time()."&code=3";
			}
		}
		else{
			if (login($username,$password)){   
				// //sinh session va xoa cac session cu di
				insert_log($username, $_SERVER['REMOTE_ADDR'],trim($sn),trim($os),trim($pcname),trim($pcuser),trim($apversion));
				$sid = session_id();


				
				deleteAllSession($username);
				setSession($username,$sid);
				
				echo "ret=".$sid."&token=".time()."&code=0";
				
			}
			else
			{
				// truong hop nay la dang nhap lan dau tien hoac dang nhap moi (da DN roi, bjo 1 may khac lai DN tiep)
				// tao session moi, tra ve cho user & cap nhat vao db
				//$ss_id = "abc456";
				//echo "ret=".$ss_id."&token=".time();
				// xoa tat ca cac session khac lien quan den user nay
				// ...
				echo "ret=&token=".time()."&code=2";
			}
		}
		exit();
	}
	*/
	// if ($sn == "S17AJA0SC01542"){
		// $myfile = fopen("log.txt", "a");			
		// fwrite($myfile, '[' . date("d/m/Y h:m:s") . "] " . $os . " - " . $sn . " - " . $username . " - " . $sessionid . " - " . $password . "\r\n");
		// fclose($myfile);
	// }
	
	// insert_log($username, $_SERVER['REMOTE_ADDR'],trim($sn),trim($os),trim($pcname),trim($pcuser),trim($apversion));
	// $sid = session_id();


	
	// deleteAllSession($username);
	// setSession($username,$sid);
	
	// echo "ret=".$sid."&token=".time()."&code=0";
	// exit();
	
	// 0 <=> thành công
	// 1 <=> lỗi sai username
	// 2 <=> lỗi sai password
	// 3 <=> lỗi đăng nhập ở máy khác
	// 4 <=> lỗi tài khoản hết hạn sử dung (cần phải nạp $ )
	
	// $sessionDate = getSessionDate($username);	
	// if (!empty($sessionid)){
		
	// }
	

	
	// $myfile = fopen("log.txt", "w");	
	// print($myfile);

	// fwrite($myfile, '[' . date("d/m/Y h:m:s") . "] " . $os . " - " . $sn . " - " . $username . " - " . $sessionid . " -  " . $password . "\r\n");
	// fwrite($myfile, "abc");
	// fclose($myfile);
	// echo '[' . date("d/m/Y h:m:s") . "] " . $os . " - " . $sn . " - " . $username . " - " . $sessionid . " -  " . $password . "\r\n";
	
	//date_default_timezone_set('UTC');
	date_default_timezone_set('asia/ho_chi_minh');
	
	function get_ssid($username, $password, $sn, $pcname){
		// return md5( md5($username . "123") . md5($sn . "456") . md5($password . "789") . md5($pcname . "299") );
		$output = exec('/usr/local/bin/pyconcrete /var/www/html/sea/myscript.pye ' . $username . ' ' . $sn . ' ' . $password . ' ' . $pcname, $output);
		return $output;
	}
	
	if (login($username,$password)){   
		insert_log($username, $_SERVER['REMOTE_ADDR'],trim($sn),trim($os),trim($pcname),trim($pcuser),trim($apversion));
		// //sinh session va xoa cac session cu di
		
		// $sid = session_id();
		
		// $sid = md5($username . $sn . $pcname);//session_id();
		$sid = get_ssid($username, $password, $sn, $pcname);
		
		$sid_server = getSession($username);
		if (empty($sid_server)){

			setSession($username,$sid);
			
			// $code1 = xor_str(rand(1000,10000) . rand(10,100),'9h1ch12TP49fNghich8xthoi29Ge12mT');
			$code1 = xor_str(strval(date('Y-m-d h:i:s')),'9h1ch12TP49fNghich8xthoi29Ge12mT');
			$code2 = md5(xor_str($username,'mAh0aiuZopaTgu4c12ab34cfg'));
			$temp = (rand(100000,999999) << 8) ^ 2;
			$code3 = xor_str(strval($temp),'9h1ch12TP49fNghich8xthoi29Ge12mT');
			$code4 = xor_str(hash('sha256',$password),'mAh0aiuZopaTgu4c12ab34cfg');
			$code5 = '';
			$code5 .= xor_str($sn . 'A01xG','1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
			$code5 .= xor_str($pcname . 'B2c9v','1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
			$code5 .= xor_str($sn2 . 'zK7Tm','1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
			$code5 .= xor_str($username . 'Kho5g','1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
			$code5 = md5($code5);
			$expire_date = getExpireDate($username);
			if (empty($expire_date)){
				$expire_date = '1970-01-01 01:01:01';
			}
			
			$code6 = xor_str(strval($expire_date),'1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
			
			print_encrypt("code1=".$code1 . "&" . "code2=".$code2 . "&" . "code3=".$code3 . "&" . "code4=".$code4 . "&" . "code5=".$code5 . "&" . "code6=".$code6);
			
			// print_encrypt("ret=".$sid."&token=".time()."&code=0");
		}
		else{
			$sessionDate = strtotime(getSessionDate($username)) + 40 * 60;

			$sessionNow = strtotime("now");
			// insert_log2($sessionNow);
			if ($sessionDate < $sessionNow){ //qua 30 phut
				deleteAllSession($username);
				// $sid = md5($username . $sn . $pcname);
				$sid = get_ssid($username, $password, $sn, $pcname);
				setSession($username,$sid);
			
				// print_encrypt("ret=".$sid."&token=".time()."&code=0");
				
				// $code1 = xor_str(rand(1000,10000) . rand(10,100),'9h1ch12TP49fNghich8xthoi29Ge12mT');
				$code1 = xor_str(strval(date('Y-m-d h:i:s')),'9h1ch12TP49fNghich8xthoi29Ge12mT');
				$code2 = md5(xor_str($username,'mAh0aiuZopaTgu4c12ab34cfg'));
				$temp = (rand(100000,999999) << 8) ^ 2;
				$code3 = xor_str(strval($temp),'9h1ch12TP49fNghich8xthoi29Ge12mT');
				$code4 = xor_str(hash('sha256',$password),'mAh0aiuZopaTgu4c12ab34cfg');
				$code5 = '';
				$code5 .= xor_str($sn . 'A01xG','1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
				$code5 .= xor_str($pcname . 'B2c9v','1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
				$code5 .= xor_str($sn2 . 'zK7Tm','1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
				$code5 .= xor_str($username . 'Kho5g','1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
				$code5 = md5($code5);
				$expire_date = getExpireDate($username);
				if (empty($expire_date)){
					$expire_date = '1970-01-01 01:01:01';
				}
				
				$code6 = xor_str(strval($expire_date),'1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
				
				print_encrypt("code1=".$code1 . "&" . "code2=".$code2 . "&" . "code3=".$code3 . "&" . "code4=".$code4 . "&" . "code5=".$code5 . "&" . "code6=".$code6);
				
			}
			else{
				if ($sid != $sid_server){
					// print_encrypt("ret=&token=".time()."&code=3");
					
					// $code1 = xor_str(rand(1000,10000) . rand(10,100),'9h1ch12TP49fNghich8xthoi29Ge12mT');
					$code1 = xor_str(strval(date('Y-m-d h:i:s')),'9h1ch12TP49fNghich8xthoi29Ge12mT');
					$code2 = md5(xor_str($username,'mAh0aiuZopaTgu4c12ab34cfg'));
					$temp = (rand(100000,999999) << 8) ^ 9;
					$code3 = xor_str(strval($temp),'9h1ch12TP49fNghich8xthoi29Ge12mT');
					$code4 = xor_str(hash('sha256',$password),'mAh0aiuZopaTgu4c12ab34cfg');
					$code5 = '';
					$code5 .= xor_str($sn . 'A01xG','1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
					$code5 .= xor_str($pcname . 'B2c9v','1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
					$code5 .= xor_str($sn2 . 'zK7Tm','1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
					$code5 .= xor_str($username . 'Kho5g','1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
					$code5 = md5($code5);
					$expire_date = getExpireDate($username);
					if (empty($expire_date)){
						$expire_date = '1970-01-01 01:01:01';
					}
					
					$code6 = xor_str(strval($expire_date),'1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
					
					print_encrypt("code1=".$code1 . "&" . "code2=".$code2 . "&" . "code3=".$code3 . "&" . "code4=".$code4 . "&" . "code5=".$code5 . "&" . "code6=".$code6);
					
				}
				else{
					// print_encrypt("ret=".$sid."&token=".time()."&code=0");
					// $code1 = xor_str(rand(1000,10000) . rand(10,100),'9h1ch12TP49fNghich8xthoi29Ge12mT');
					$code1 = xor_str(strval(date('Y-m-d h:i:s')),'9h1ch12TP49fNghich8xthoi29Ge12mT');
					$code2 = md5(xor_str($username,'mAh0aiuZopaTgu4c12ab34cfg'));
					$temp = (rand(100000,999999) << 8) ^ 2;
					$code3 = xor_str(strval($temp),'9h1ch12TP49fNghich8xthoi29Ge12mT');
					$code4 = xor_str(hash('sha256',$password),'mAh0aiuZopaTgu4c12ab34cfg');
					$code5 = '';
					$code5 .= xor_str($sn . 'A01xG','1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
					$code5 .= xor_str($pcname . 'B2c9v','1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
					$code5 .= xor_str($sn2 . 'zK7Tm','1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
					$code5 .= xor_str($username . 'Kho5g','1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
					$code5 = md5($code5);
					$expire_date = getExpireDate($username);
					if (empty($expire_date)){
						$expire_date = '1970-01-01 01:01:01';
					}
					
					$code6 = xor_str(strval($expire_date),'1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
					
					print_encrypt("code1=".$code1 . "&" . "code2=".$code2 . "&" . "code3=".$code3 . "&" . "code4=".$code4 . "&" . "code5=".$code5 . "&" . "code6=".$code6);
					
				}
			}
		}
		
	}
	else
	{
		// truong hop nay la dang nhap lan dau tien hoac dang nhap moi (da DN roi, bjo 1 may khac lai DN tiep)
		// tao session moi, tra ve cho user & cap nhat vao db
		//$ss_id = "abc456";
		//echo "ret=".$ss_id."&token=".time();
		// xoa tat ca cac session khac lien quan den user nay
		// ...
		
		// if (!check_user($username)) {
			// print_encrypt("ret=&token=".time()."&code=1");
		// }
		// else if (!check_pass($password)) {
			// print_encrypt("ret=&token=".time()."&code=2");
		// }
		// else{
			// print_encrypt("ret=&token=".time()."&code=4");
		// }
		
		// $code1 = xor_str(rand(1000,10000) . rand(10,100),'9h1ch12TP49fNghich8xthoi29Ge12mT');
		$code1 = xor_str(strval(date('Y-m-d h:i:s')),'9h1ch12TP49fNghich8xthoi29Ge12mT');
		if (!check_user($username)) {
			$username = "IDKhongTonTai";
		}
		
		if (!check_pass($password)) {
			$password = "KhongTonTaiPW";
		}
		$code2 = md5(xor_str($username,'mAh0aiuZopaTgu4c12ab34cfg'));
		$temp = (rand(100000,999999) << 8) ^ 5;
		$code3 = xor_str(strval($temp),'9h1ch12TP49fNghich8xthoi29Ge12mT');
		$code4 = xor_str(hash('sha256',$password),'mAh0aiuZopaTgu4c12ab34cfg');
		$code5 = '';
		$code5 .= xor_str($sn . 'A01xG','1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
		$code5 .= xor_str($pcname . 'B2c9v','1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
		$code5 .= xor_str($sn2 . 'zK7Tm','1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
		$code5 .= xor_str($username . 'Kho5g','1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
		$code5 = md5($code5);
		
		if (check_user($username)) {
			$expire_date = getExpireDate($username);
			if (empty($expire_date)){
				$expire_date = '1970-01-01 01:01:01';
			}
		}
		else{
			$expire_date = '1970-01-01 01:01:01';			
		}
		
		
		$code6 = xor_str(strval($expire_date),'1C4nG49a2Ho7Id1HatG1e95at1rXsY50');
		
		print_encrypt("code1=".$code1 . "&" . "code2=".$code2 . "&" . "code3=".$code3 . "&" . "code4=".$code4 . "&" . "code5=".$code5 . "&" . "code6=".$code6);
		
		
	}
		
	/*
	if (!empty($sessionid)){// neu co session
		// $sid = file_get_contents('session.txt', true);
		$sid = getSession($username);
		if($sessionid == $sid){ //kiem tra session co ton tai hay khong, neu ton tai thi tra ve ss
			insert_log($username, $_SERVER['REMOTE_ADDR'],trim($sn),trim($os),trim($pcname),trim($pcuser),trim($apversion));
			if (check_user_expire($username)){
				echo "ret=".$sid."&token=".time()."&code=0";
			}
			else{
				echo "ret=&token=".time()."&code=4";
			}			
		}
		else{
			//khong ton tai session tra ve session rong
		
			
			if (mb_detect_encoding($sessionid, 'ASCII', true)){
				echo "ret=&token=".time()."&code=3";
			}
			else{
				echo "ret=".$sessionid."&token=".time()."&code=0";
				// $myfile = fopen("log.txt", "a");			
				// fwrite($myfile, '[' . date("d/m/Y h:m:s") . "] 2 " . $os . " - " . $sn . " - " . $username . " - " . $sessionid . " - " . $password . "\r\n");
				// fclose($myfile);
			}				
		}
	}
	else{
		if (login($username,$password)){   
			// //sinh session va xoa cac session cu di
			insert_log($username, $_SERVER['REMOTE_ADDR'],trim($sn),trim($os),trim($pcname),trim($pcuser),trim($apversion));
			// $sid = session_id();
			
			$sid = md5($username . $sn . $pcname);//session_id();
			
			$sid_server = getSession($username);
			if (empty($sid_server)){
				
				// deleteAllSession($username);
				setSession($username,$sid);
				
				echo "ret=".$sid."&token=".time()."&code=0";
			}
			else{
				if ($sid != $sid_server){
					echo "ret=&token=".time()."&code=3";
				}
				else{
					echo "ret=".$sid."&token=".time()."&code=0";
				}
			}
			
		}
		else
		{
			// truong hop nay la dang nhap lan dau tien hoac dang nhap moi (da DN roi, bjo 1 may khac lai DN tiep)
			// tao session moi, tra ve cho user & cap nhat vao db
			//$ss_id = "abc456";
			//echo "ret=".$ss_id."&token=".time();
			// xoa tat ca cac session khac lien quan den user nay
			// ...
			if (!check_user($username)) {
				echo "ret=&token=".time()."&code=1";
			}
			else if (!check_pass($password)) {
				echo "ret=&token=".time()."&code=2";
			}
			else{
				echo "ret=&token=".time()."&code=4";
			}
		}
	}
	*/
	
	function print_encrypt($str){
		$foo = new Cipher;
		
		// echo $foo->encrypt('rnd='. rand(1000000,100000000) . '&' . $str);
		echo $foo->encrypt($str);
	}
	
	function insert_log2($str){
				$servername = "localhost";
		$username = "bot4league";
		$password = "ao5a2N7fo7H400gB";
		$dbname = "bot4league";

		// Create connection
		$conn = new mysqli($servername, $username, $password, $dbname);

		// Check connection
		if ($conn->connect_error) {
			//die("Connection failed: " . $conn->connect_error);
		}

		// prepare and bind
		$stmt = $conn->prepare("INSERT INTO autdit2 (msg) VALUES (?)");
		$stmt->bind_param("s", $str);
		$stmt->execute();		

		
		$stmt->close();
		$conn->close();
	}
	
	function insert_log($logged_username, $ip, $sn, $os, $pcname, $pcuser, $apversion){
		$servername = "localhost";
		$username = "bot4league";
		$password = "ao5a2N7fo7H400gB";
		$dbname = "bot4league";

		// Create connection
		$conn = new mysqli($servername, $username, $password, $dbname);

		// Check connection
		if ($conn->connect_error) {
			//die("Connection failed: " . $conn->connect_error);
		}

		// prepare and bind
		$stmt = $conn->prepare("INSERT INTO audit (username, ip, sn, os, pcname, pcuser, apversion, created_date) VALUES (?, ?, ?, ?, ?, ?, ?, NOW())");
		$stmt->bind_param("sssssss", $logged_username,$ip, $sn, $os, $pcname, $pcuser,$apversion);
		$stmt->execute();		

		
		$stmt->close();
		$conn->close();
	}
	
	function login($name, $pass){
				$servername = "localhost";
		$username = "bot4league";
		$password = "ao5a2N7fo7H400gB";
		$dbname = "bot4league";

		if (empty($name) || empty($pass)){
			return false;
		}
		// Create connection
		$conn = new mysqli($servername, $username, $password, $dbname);
		// Check connection
		if ($conn->connect_error) {
			return false;
		} 
		$hased_password = hash('sha256', $conn->real_escape_string($pass));
		// if ($name == 'chunglk'){
			// $name = $conn->real_escape_string($name);
			// $sql = "SELECT uid, trangthai FROM users WHERE username= '$name' AND pass = '$hased_password' AND DATE_FORMAT(hansudung,'%Y-%m-%d') >= CURDATE()";
		// }
		// else{
			// $name = $conn->real_escape_string($name);
			// $sql = "SELECT uid, trangthai FROM users WHERE username= '$name' AND pass = '$hased_password' ";	
		// }	
		$name = $conn->real_escape_string($name);
		$sql = "SELECT uid, trangthai FROM users WHERE trangthai=1 AND username= '$name' AND pass = '$hased_password' AND DATE_FORMAT(hansudung,'%Y-%m-%d %H:%i:%s') > NOW()";		
		$rows = $conn->query($sql);
		if($rows->num_rows > 0){
			return true;
		}
		return false;
	}
	
	function check_user($name){
				$servername = "localhost";
		$username = "bot4league";
		$password = "ao5a2N7fo7H400gB";
		$dbname = "bot4league";

		if (empty($name)){
			return false;
		}
		// Create connection
		$conn = new mysqli($servername, $username, $password, $dbname);
		// Check connection
		if ($conn->connect_error) {
			return false;
		}
		
		$name = $conn->real_escape_string($name);
		$sql = "SELECT uid, trangthai FROM users WHERE username= '$name' ";		
		$rows = $conn->query($sql);
		if($rows->num_rows > 0){
			return true;
		}
		return false;
	}
	
	function check_pass($pass){
				$servername = "localhost";
		$username = "bot4league";
		$password = "ao5a2N7fo7H400gB";
		$dbname = "bot4league";

		if (empty($pass)){
			return false;
		}
		// Create connection
		$conn = new mysqli($servername, $username, $password, $dbname);
		// Check connection
		if ($conn->connect_error) {
			return false;
		}
		$pass = hash('sha256', $pass);
		$pass = $conn->real_escape_string($pass);
		$sql = "SELECT uid, trangthai FROM users WHERE pass= '$pass' ";		
		$rows = $conn->query($sql);
		if($rows->num_rows > 0){
			return true;
		}
		return false;
	}
	
	function check_user_expire($name){
				$servername = "localhost";
		$username = "bot4league";
		$password = "ao5a2N7fo7H400gB";
		$dbname = "bot4league";

		if (empty($name)){
			return false;
		}
		// Create connection
		$conn = new mysqli($servername, $username, $password, $dbname);
		// Check connection
		if ($conn->connect_error) {
			return false;
		}
		
		$name = $conn->real_escape_string($name);
		$sql = "SELECT uid, trangthai FROM users WHERE username= '$name' AND DATE_FORMAT(hansudung,'%Y-%m-%d %H:%i:%s') > NOW() ";		
		$rows = $conn->query($sql);
		if($rows->num_rows > 0){
			return true;
		}
		return false;
	}
	
	
	
	function getSession($name){
				$servername = "localhost";
		$username = "bot4league";
		$password = "ao5a2N7fo7H400gB";
		$dbname = "bot4league";

		// Create connection
		$conn = new mysqli($servername, $username, $password, $dbname);
		// Check connection
		if ($conn->connect_error) {
			return "";
		} 
		$name = $conn->real_escape_string($name);
		$sql = "SELECT * FROM session WHERE `username`= '$name'";
		$rows = $conn->query($sql);
		while($row = $rows->fetch_assoc()) {
			return $row['ssid'];
		}
		return "";
	}
	
	function getSessionDate($name){
				$servername = "localhost";
		$username = "bot4league";
		$password = "ao5a2N7fo7H400gB";
		$dbname = "bot4league";

		// Create connection
		$conn = new mysqli($servername, $username, $password, $dbname);
		// Check connection
		if ($conn->connect_error) {
			return "";
		} 
		$name = $conn->real_escape_string($name);
		$sql = "SELECT * FROM session WHERE `username`= '$name'";
		$rows = $conn->query($sql);
		while($row = $rows->fetch_assoc()) {
			return $row['created'];
		}
		return "";
	}
	
	function getExpireDate($name){
		$servername = "localhost";
		$username = "bot4league";
		$password = "ao5a2N7fo7H400gB";
		$dbname = "bot4league";

		// Create connection
		$conn = new mysqli($servername, $username, $password, $dbname);
		// Check connection
		if ($conn->connect_error) {
			return "";
		} 
		$name = $conn->real_escape_string($name);
		$sql = "SELECT hansudung FROM users WHERE `username`= '$name'";
		$rows = $conn->query($sql);
		while($row = $rows->fetch_assoc()) {
			return $row['hansudung'];
		}
		return "";
	}
	
	function setSession($name, $ssid){
				$servername = "localhost";
		$username = "bot4league";
		$password = "ao5a2N7fo7H400gB";
		$dbname = "bot4league";

		// Create connection
		$conn = new mysqli($servername, $username, $password, $dbname);
		// Check connection
		if ($conn->connect_error) {
			return false;
		}
		$name = $conn->real_escape_string($name);
		$sql = "INSERT INTO session(username,ssid,created) VALUES('$name','$ssid',NOW())";
		if ($conn->query($sql) === TRUE) {
			return true;
		}
		return false;
	}
	
	function deleteAllSession($name){
		$servername = "localhost";
		$username = "bot4league";
		$password = "ao5a2N7fo7H400gB";
		$dbname = "bot4league";

		// Create connection
		$conn = new mysqli($servername, $username, $password, $dbname);
		// Check connection
		if ($conn->connect_error) {
			return false;
		}
		$name = $conn->real_escape_string($name);
		$sql = "DELETE FROM session WHERE username='$name'";
		if ($conn->query($sql) === TRUE) {
			return true;
		}
		return false;
	}
?>
