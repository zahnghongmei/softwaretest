Action()
{
  
	web_set_sockets_option("SSL_VERSION", "TLS1.1");
    lr_start_transaction("请求链接");
	web_url("center.t.dacube.cn", 
		"URL=https://center.t.dacube.cn/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
   lr_end_transaction("请求链接", LR_AUTO);


	lr_think_time(4);

	web_url("iecompatviewlist.xml", 
		"URL=https://iecvlist.microsoft.com/IE11/1478281996/iecompatviewlist.xml", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);
	return 0;
}