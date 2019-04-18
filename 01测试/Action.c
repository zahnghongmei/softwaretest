Action()
{

	web_add_header("UA-CPU", 
		"AMD64");

	web_url("login.jsp", 
		"URL=http://4a.dacube.com.cn/samlidp/login.jsp", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t95.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=img/user.png", ENDITEM, 
		"Url=img/pass.png", ENDITEM, 
		"Url=img/userset.png", ENDITEM, 
		"Url=img/down.png", ENDITEM, 
		"Url=img/qrcode.png", ENDITEM, 
		"Url=img/close.png", ENDITEM, 
		"Url=img/1.png", ENDITEM, 
		"Url=img/close2.png", ENDITEM, 
		LAST);

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	web_custom_request("urs.asmx", 
		"URL=https://urs.microsoft.com/urs.asmx?MSURS-Client-Key=cu%2bUXfKtcCJgdmHn72IvRQ%3d%3d&MSURS-MAC=M1vC/E%2bg/MM%3d", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t96.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=utf-8", 
		"Body=<RepLookup v=\"6\"><G>4A72F430-B40C-4D36-A068-CE33ADA5ADF9</G><O>00000000-0000-0000-0000-000000000000</O><DID>S7SLDAmA61aW9UyApSWhd0SpNI0mxVqjW5B3NWoIW4o=:0</DID><UID>w:2062F45C-33C6-17F4-8429-14DA68C62970</UID><D>10.0.8110.6</D><C>11.0.0.0</C><OS>10.0.17763.0.0</OS><I>9.11.17763.0</I><L>zh-CN</L><RU></RU><RI>0.0.0.0</RI><R><Rq><URL>aHR0cDovLzRhLmRhY3ViZS5jb20uY24vc2FtbGlkcC9sb2dpbi5qc3A=</URL><O>POST</O><T>TOP</T><HIP>118.118.118.147</HIP></Rq><Rq><URL"
		">aHR0cDovLzRhLmRhY3ViZS5jb20uY24vc2FtbGlkcC9sb2dpbg==</URL><O>POST</O><T>ACTION</T><HIP>139.9.5.231</HIP></Rq><Rq><URL>aHR0cDovLzExOC4xMTguMTE4LjE0Nw==</URL><O>POST</O><T>IP</T><HIP>118.118.118.147</HIP></Rq></R><WA/><PRT>2525</PRT></RepLookup>", 
		LAST);

	web_custom_request("urs.asmx_2", 
		"URL=https://urs.microsoft.com/urs.asmx?MSURS-Client-Key=DhelVSGQgJtiwYsqPDYCvA%3d%3d&MSURS-MAC=b7w0RgvS0RU%3d", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t97.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=utf-8", 
		"Body=<RepLookup v=\"6\"><G>4A72F430-B40C-4D36-A068-CE33ADA5ADF9</G><O>00000000-0000-0000-0000-000000000000</O><DID>S7SLDAmA61aW9UyApSWhd0SpNI0mxVqjW5B3NWoIW4o=:0</DID><UID>w:2062F45C-33C6-17F4-8429-14DA68C62970</UID><D>10.0.8110.6</D><C>11.0.0.0</C><OS>10.0.17763.0.0</OS><I>9.11.17763.0</I><L>zh-CN</L><RU></RU><RI>0.0.0.0</RI><R><Rq><URL>aHR0cDovLzRhLmRhY3ViZS5jb20uY24vc2FtbGlkcC9sb2dpbi5qc3A=</URL><O>PRE</O><T>TOP</T><HIP>118.118.118.147</HIP></Rq><Rq><URL>aHR0cDovLzExOC4xMTguMTE4LjE0Nw==</URL><O"
		">PRE</O><T>IP</T><HIP>118.118.118.147</HIP></Rq></R><WA/><PRT>2525</PRT></RepLookup>", 
		LAST);

	return 0;
}