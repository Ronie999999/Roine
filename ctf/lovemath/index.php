<?php
//flag.txt
header("Content-type: text/html; charset=gb2312");
error_reporting(0);
//��˵���ϲ����ѧ����֪�����Ƿ���ʤ����flag
if(!isset($_GET['c'])){
    show_source(__FILE__);
}else{
    //���� c=20-1
    $content = $_GET['c'];
    if (strlen($content) >= 80) {
        die("̫���˲�����");
    }
    $blacklist = [' ', '\t', '\r', '\n','\'', '"', '`', '\[', '\]'];
    foreach ($blacklist as $blackitem) {
        if (preg_match('/' . $blackitem . '/m', $content)) {
            die("�벻Ҫ��������ֵֹ��ַ�");
        }
    }

    //������ѧ����http://www.w3school.com.cn/php/php_ref_math.asp
    $whitelist = ['abs', 'acos', 'acosh', 'asin', 'asinh', 'atan2', 'atan', 'atanh', 'base_convert', 'bindec', 'ceil', 'cos', 'cosh', 'decbin', 'dechex', 'decoct', 'deg2rad', 'exp', 'expm1', 'floor', 'fmod', 'getrandmax', 'hexdec', 'hypot', 'is_finite', 'is_infinite', 'is_nan', 'lcg_value', 'log10', 'log1p', 'log', 'max', 'min', 'mt_getrandmax', 'mt_rand', 'mt_srand', 'octdec', 'pi', 'pow', 'rad2deg', 'rand', 'round', 'sin', 'sinh', 'sqrt', 'srand', 'tan', 'tanh'];
    preg_match_all('/[a-zA-Z_\x7f-\xff][a-zA-Z_0-9\x7f-\xff]*/', $content, $used_funcs);
    foreach ($used_funcs[0] as $func) {
        if (!in_array($func, $whitelist)) {
            die("�벻Ҫ��������ֵֹĺ���");
        }
    }

    eval('echo '.$content.';');
}

