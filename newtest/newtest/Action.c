/*result��ʾ�Ƿ�ͨ���Ľ������,code��ʾ�������˷��ص�״̬��,str��ʾһ����ʱ�ַ�����textfind��ʾ�ı����� msg��ʾ����˷��ص�message*/

int result;
char *code;
char *str;
int textfind;
int msg;
char *error;
char content[200];
char real[200];
char *temp;
//���Խ���ı�
char V_testres[1024];
/*info��ʾ������Ϣ,content��ʾԤ�ڽ��,real ��ʾ���������ص���ʵ��� */
int write(int result,char V_testres[1024],char *info,char content[200],char real[200])
{

 if ( result==0 ) {
           strcpy(V_testres,"ͨ��");
         }
       else {
       strcpy(V_testres,"ʧ��");
         }
		 
	strcpy(t_result,"<tr bgcolor='#ffffff'><td bgcolor='##e2fbfe' align='center'>" );
    //д����Բ���
    strcat(t_result,info);

    strcat(t_result,"</td>");

    strcat(t_result,"<td id='yq'>");
	//д��Ԥ�ڽ��

    strcat(t_result,content);

    strcat(t_result,"</td>");

    strcat(t_result,"<td id='sj'>");
	//д��ʵ�ʽ��
    strcat(t_result,real);
    strcat(t_result,"</td>");
    if(strcmp(V_testres,"ʧ��")==0){
       strcat(t_result,"<td style='width:60px;color:red;' align='center'>");
       }
    else{
       strcat(t_result,"<td style='width:60px;color:blue;' align='center'>");
       }
    //д������Ƿ�ͨ��

    strcat(t_result, V_testres);

    strcat(t_result,"</td></tr>"); 

    fputs(t_result,file);
    return 0;
}
int reg_fun(char *code)
{
 web_reg_save_param(code,
        "LB=\"code\":",
		"RB=\,",
		LAST); 
 msg=web_reg_save_param("error",
		"LB=\"message\":\"",
		"RB=\"",
		"ORD=1",
		LAST); 	
return 0;
}
int logic(char *code,char *info,char *contentinfo,char *realinfo,char *errorinfo)
{
	 strcpy(real,"code:");
       strcat(real,code);
       strcpy(content,contentinfo);
       if(atoi(code)==200){
       	 if(textfind==0){
	      lr_output_message("�ı������ɹ�");
	       strcat(real,realinfo);
	      result=0;
	     }
	     else{
		  lr_output_message("�ı�����ʧ��");
	      result=1;
	      strcat(real,"message:");
	      strcat(real,errorinfo);
	     }	
       }
       	else{
       	result=1;         	
       	}
       write(result,V_testres,info,content,real);       
	
return 0;
}
Action()
{
       char token1[36];
       int i;
       char a[2];
       int b;
       char destString[1024];
       char dest1String[1024];
       char keywods[100];
//ȡ��������Ϣ
       char *info=lr_eval_string ("{username}");
       char content[200];
       char real[200];
       char *temp;
//����ҳ����������ֽ�����������Ӧ���ڷ������������ݵĴ�С
       web_set_max_html_param_len("20000");
       web_set_sockets_option("SSL_VERSION", "TLS1.1");
       lr_think_time(6);              
       web_reg_save_param("Token",
              "LB=token",
              "RB=",
              "SaveOffset=3",
              "SaveLen=36",
              LAST);
       web_reg_save_param("Usercode",
              "LB=\"usercode\":\"",
              "RB=\"",
              LAST);
       web_reg_find("Text/DIG/ALNUMIC=usercode",
       LAST); 
      

	  web_reg_save_param("code",
        "LB=\"code\":",
		"RB=\,\"result\"",
		LAST);

	  web_reg_save_param("phone",
		"LB=\"phone\":\"",
		"RB=\"",
		LAST);
	 
	
       //�����¼�ӿڵ�½ ������ȷ���û�����ȷ
       lr_start_transaction("login");
       web_custom_request("login_1", 
              "URL=https://g.t.dacube.cn/MESG-ADMIN/User/login", 
              "Method=POST", 
              "Resource=0", 
              "RecContentType=application/json", 
              "Referer=https://center.t.dacube.cn/", 
              "Snapshot=t15.inf", 
              "Mode=HTML", 
              "EncType=application/json;charset=UTF-8", 
              "Body={\"phone\":\"{account}\",\"userpwd\":\"{password}\"}", 
              LAST);
       lr_end_transaction("login", LR_AUTO);
       strcpy(real,"code:");
       strcat(real,lr_eval_string("{code}"));
       strcat(real," phone:");
       strcat(real,lr_eval_string("{phone}"));
       strcpy(content,"code:200 phone:18200000000");
       code=lr_eval_string("{code}");
       if(atoi(code)!=200)
       {
       result=1;
       }
       else{
       result=strcmp(real,content);
       }
    write(result,V_testres,"�û����������ȷ�ӿ���֤",content,real);
    temp=lr_eval_string("{code}");
    lr_output_message("codeΪ��%s", temp);
    lr_output_message("phoneΪ��%s",lr_eval_string("{phone}"));
       //��ӡ�û�token
    strcpy(token1, lr_eval_string("{Token}"));
    lr_output_message("tokenΪ��%s", token1);
    lr_output_message("usercodeΪ��%s", lr_eval_string("{Usercode}"));
    lr_output_message("%s", "��½�ɹ�");
    
	  web_reg_save_param("code1",
        "LB=\"code\":",
		"RB=\,\"result\"",
		LAST);
     web_reg_save_param("msg",
        "LB=\"msg\":\"",
		"RB=\"",
		LAST);
    //��½��֤���û���������
    web_custom_request("login_2", 
              "URL=https://g.t.dacube.cn/MESG-ADMIN/User/login", 
              "Method=POST", 
              "Resource=0", 
              "RecContentType=application/json", 
              "Referer=https://center.t.dacube.cn/", 
              "Snapshot=t152.inf", 
              "Mode=HTML", 
              "EncType=application/json;charset=UTF-8", 
              "Body={\"phone\":\"18200000001\",\"userpwd\":\"{password}\"}", 
              LAST);
       
       strcpy(real,"code:");
       code=lr_eval_string("{code1}");
       strcat(real,lr_eval_string("{code1}"));
       strcpy(content,"code:��Ϊ200 msg:��¼��������");
       //���code������200���ʹ�ӡmsg��
       if(atoi(code)!=200)
       {
       	result=0;
        strcat(real," msg:");
        lr_convert_string_encoding(
              lr_eval_string("{msg}"),
              "utf-8",
              "GBK",     
              "enmsg"
              );
       strcat(real,lr_eval_string("{enmsg}"));
       }
       write(result,V_testres,"��½�û�������ӿ���֤",content,real);
        
	  web_reg_save_param("code2",
        "LB=\"code\":",
		"RB=\,\"result\"",
		LAST);
     web_reg_save_param("msg2",
        "LB=\"msg\":\"",
		"RB=\"",
		LAST);
    
        //��½��֤���������
    web_custom_request("login_3", 
              "URL=https://g.t.dacube.cn/MESG-ADMIN/User/login", 
              "Method=POST", 
              "Resource=0", 
              "RecContentType=application/json", 
              "Referer=https://center.t.dacube.cn/", 
              "Snapshot=t153.inf", 
              "Mode=HTML", 
              "EncType=application/json;charset=UTF-8", 
              "Body={\"phone\":\"18200000000\",\"userpwd\":\"12345\"}", 
              LAST);
       
       strcpy(real,"code:");
       code=lr_eval_string("{code2}");
       strcat(real,lr_eval_string("{code2}"));
       strcpy(content,"code:��Ϊ200 msg:��¼�������벻ƥ��   ");
       //���code������200���ʹ�ӡmsg��
       if(atoi(code)!=200)
       {
       	result=0;
        strcat(real," msg:");
        lr_convert_string_encoding(
              lr_eval_string("{msg2}"),
              "utf-8",
              "GBK",     
              "enmsg2"
              );
       strcat(real,lr_eval_string("{enmsg2}"));
       }
       write(result,V_testres,"��½�û�������ӿ���֤",content,real);
       
       	       
	  web_reg_save_param("compname",
        "LB=\"compname\":\"",
		"RB=\"",
		"Ord=1",
		LAST);
        web_reg_save_param("companycode",
        "LB=\"code\":",
		"RB=\,\"result\"",
		LAST);
    //��ȡ��ҵ��Ϣ�ӿ�
       web_add_auto_header("token","{Token}");
       lr_start_transaction("getCompany");
       web_custom_request(token1,
              "URL=https://g.t.dacube.cn/MESG-ADMIN/User/getCompanyByUsercode/{Usercode}", 
              "Method=GET", 
              "Resource=0", 
              "Referer=https://center.t.dacube.cn/", 
              "Snapshot=t16.inf", 
              "Mode=HTML", 
              LAST);
       lr_end_transaction("getCompany", LR_AUTO);

       lr_output_message("compname��%s", lr_eval_string("{compname}"));
       strcpy(real,"code:");
       code=lr_eval_string("{companycode}");
       strcat(real,lr_eval_string("{companycode}"));
       strcpy(content,"code:200 compname:���ƿƼ�");
       //���code������200���ʹ�ӡmsg��
       if(atoi(code)==200)
       {
       	if(strcmp(lr_eval_string("{compname}"),"���ƿƼ�")){
       		result=0;
       	}
       	else{
       	result=1;
       	}
        strcat(real," compname:");
        lr_convert_string_encoding(
              lr_eval_string("{compname}"),
              "utf-8",
              "GBK",     
              "encompname"
              );
       strcat(real,lr_eval_string("{encompname}"));
       }
       write(result,V_testres,"��ȡ��ҵ��Ϣ�ӿ���֤",content,real);    
      web_reg_save_param("compid",
        "LB=\"compid\":\"",
		"RB=\"",
		"Ord=1",
		LAST);
        web_reg_save_param("updatecode",
        "LB=\"code\":",
		"RB=\,\"result\"",
		LAST);  
    lr_start_transaction("updateuserinfo");
    //ѡ����ҵ��½������û���Ϣ
    web_custom_request("updateuser",
              "URL= https://g.t.dacube.cn/MESG-ADMIN/User/updateUser ", 
              "Method=POST", 
              "Resource=0", 
              "RecContentType=application/json", 
              "Referer=https://center.t.dacube.cn/", 
              "Snapshot=t17.inf", 
              "Mode=HTML", 
              "EncType=application/json;charset=UTF-8", 
              "Body={\"compid\":\"{comid}\",\"createdata\":\"1541494436000\",\"easemobname\":\"115201811061611139ftrmgurx\",\"email\":\"{email}\",\"headimg\":\"https://oss.dacube.cn/mesg-admin/34e0a7e9-4e3a-4afc-9c93-75b24cd55660/u=3695931498,2381510501&fm=26&gp=0.jpg\",\"isuse\":\"1\",\"phone\":\"{account}\",\"token\":\"{Token}\",\"updatedata\":\"1541494436000\",\"usercode\":\"{Usercode}\"}",
              LAST);
  lr_end_transaction("updateuserinfo", LR_AUTO);
       strcpy(real,"code:");
       code=lr_eval_string("{updatecode}");
       strcat(real,code);
       strcpy(content,"code:200 comid:1");
       //���code������200���ʹ�ӡmsg��
       if(atoi(code)==200)
       {
       		result=0;
       }
       	else{
       	result=1;
       	}
        strcat(real," comid:");
        lr_convert_string_encoding(
              lr_eval_string("{comid}"),
              "utf-8",
              "GBK",     
              "encomid"
              );
       strcat(real,lr_eval_string("{encomid}"));
       
       write(result,V_testres,"��ҵ��½������û���Ϣ�ӿ���֤",content,real);
       

//��ȡȫý����Դ�����ӽӿ���֤
        web_reg_save_param("linkcode",
        "LB=\"code\":",
		"RB=\,",
		LAST); 
   web_reg_save_param("Mrp_link",
              "LB=\"redirect:",
              "RB=\"",
              LAST);
   lr_start_transaction("loginapp");
   web_custom_request("loginapp", 
              "URL= https://g.t.dacube.cn/MESG-ADMIN/Application/user/appLogin", 
              "Method=POST", 
              "Resource=0", 
              "RecContentType=application/json", 
              "Referer=https://center.t.dacube.cn/", 
              "Snapshot=t18.inf", 
              "Mode=HTML", 
              "EncType=application/json;charset=UTF-8", 
              "Body={\"appid\":\"1002\",\"compid\":\"{comid}\",\"loginType\":\"pc\",\"styleType\":\"\",\"usercode\":\"{Usercode}\"}",
              LAST);
    lr_end_transaction("loginapp", LR_AUTO);
    lr_output_message("mrp����Ϊ��%s", lr_eval_string("{Mrp_link}"));
     strcpy(real,"code:");
     code=lr_eval_string("{linkcode}");
       strcat(real,code);
       strcpy(content,"code:200 ");
       //���code������200���ʹ�ӡmsg��
       if(atoi(code)==200)
       {
       		result=0;
       }
       	else{
       	result=1;
       	}
        strcat(real," mrplink:");
       strcat(real,lr_eval_string("{Mrp_link}"));
       
       write(result,V_testres,"��½��ȡӦ�����ӽӿ���֤",content,real);    
        
       web_url("open_mrp_web",
              "URL=https://mrp.t.dacube.cn/?token={Token}#/",
              "TargetFrame=",
              "Resource=0",
              "Referer=",
              "Snapshot=t19.inf", 
              LAST);

       //�����ڸ��˿����������ļ���
       for(i=0;i<3;i++)
       {
       b=itoa(i+1,a,10);       
       lr_save_string(a, "a1");
       if(i==1){
       web_reg_save_param("Folderid2",
              "LB=\"id\":\"",
              "RB=\"",
              LAST);
       }
       else{
        web_reg_save_param("Folderid",
              "LB=\"id\":\"",
              "RB=\"",
              LAST);
       }
     lr_rendezvous("�����ļ��м��ϵ�");  //��Ӽ��ϵ�
    //�����ļ��нӿڲ���
    if(i==0)
    {
       web_reg_save_param("createfoldercode",
        "LB=\"code\":",
		"RB=\,",
		LAST); 
    	 web_reg_save_param("id_creator",
        "LB=\"id_creator\":\"",
		"RB=\"",
		LAST); 
    }
    lr_start_transaction("createfolder");
    web_custom_request("createfolder", 
              "URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/folder/add_folder", 
              "Method=POST", 
              "Resource=0", 
              "RecContentType=application/json", 
              "Referer=https://center.t.dacube.cn/", 
              "Snapshot=t20.inf", 
              "Mode=HTML", 
              "EncType=application/json;charset=UTF-8", 
              "Body={\"orgId\":\"1\",\"params\":{\"folder_detail\":\"\",\"folder_name\":\"t-{a1}\",\"id_parent\": null,\"id_repo\":\"repository-personal-1-article-e729e146-f249-42e1-960d-5c1f3f60bc9a\"},\"seed\":\"seed\",\"token\":\"{Token}\",\"userId\":\"{Usercode}\"}",
              LAST);
    lr_end_transaction("createfolder", LR_AUTO);
       lr_output_message("folderidΪ��%s", lr_eval_string("{Folderid}"));
       lr_output_message("folderid2Ϊ��%s", lr_eval_string("{Folderid2}"));
       lr_output_message("id_createrΪ��%s", lr_eval_string("{id_creator}"));
       if(i==0)
       {
       strcpy(real,"code:");
       code=lr_eval_string("{createfoldercode}");
       strcat(real,code);
       strcpy(content,"code:200 ");
       strcat(content," id_creater:");
       strcat(content,lr_eval_string("{Usercode}"));
       //���code������200���ʹ�ӡmsg��
       if(atoi(code)==200)
       {
       		result=0;
       }
       	else{
       	result=1;
       	}
       strcat(real," id_creater:");
       strcat(real,lr_eval_string("{id_creator}"));
       
       write(result,V_testres,"�����ļ��нӿ���֤",content,real); 
       }       
       }
       
   //ɾ���ļ��нӿڲ���
   web_reg_save_param("deletefoldercode",
        "LB=\"code\":",
		"RB=\,",
		LAST); 
    	 web_reg_save_param("flag_delete",
        "LB=\"flag_delete\":",
		"RB=\,",
		LAST); 
    web_reg_save_param("id_creator",
        "LB=\"id_creator\":\"",
		"RB=\"",
		LAST); 
   lr_start_transaction("deletefolder");
  web_custom_request("deletefolder", 
              "URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/folder/delete_folder", 
              "Method=POST", 
              "Resource=0", 
              "RecContentType=application/json", 
              "Referer=https://center.t.dacube.cn/", 
              "Snapshot=t21.inf", 
              "Mode=HTML", 
              "EncType=application/json;charset=UTF-8", 
              "Body={\"orgId\":\"1\",\"params\":{\"id\":\"{Folderid}\"},\"seed\":\"seed\",\"token\":\"{Token}\",\"userId\":\"{Usercode}\"}",
              LAST);
   lr_end_transaction("deletefolder", LR_AUTO);

       strcpy(real,"code:");
       code=lr_eval_string("{deletefoldercode}");
       strcat(real,code);
       strcpy(content,"code:200  flag_delete:true");
       strcat(content," id_creater:");
       strcat(content,lr_eval_string("{Usercode}"));
       //���code������200���ʹ�ӡmsg��
       if(atoi(code)==200)
       {
       		result=0;
       }
       	else{
       	result=1;
       	}
       strcat(real," id_creater:");
       strcat(real,lr_eval_string("{id_creator}"));
       strcat(real," flag_delete:");
       strcat(real,lr_eval_string("{flag_delete}"));
       write(result,V_testres,"ɾ���ļ����ļ��нӿ���֤",content,real);    
   
//�����޸��ļ��е����ֽӿڲ���
 web_reg_save_param("updatefoldercode",
        "LB=\"code\":",
		"RB=\,",
		LAST); 
lr_start_transaction("updatefolder");
  web_custom_request("updatefolder", 
              "URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/folder/update_folder_name", 
              "Method=POST", 
              "Resource=0", 
              "RecContentType=application/json", 
              "Referer=https://center.t.dacube.cn/", 
              "Snapshot=t22.inf", 
              "Mode=HTML", 
              "EncType=application/json;charset=UTF-8", 
              "Body={\"orgId\":\"1\",\"params\":{\"id\":\"{Folderid2}\",\"name\":\"t-edit\",\"detail\":\"\"},\"seed\":\"seed\",\"token\":\"{Token}\",\"userId\":\"{Usercode}\"}",
              LAST);
   lr_end_transaction("updatefolder", LR_AUTO);

              //���code������200���ʹ�ӡmsg��
        strcpy(real,"code:");
       code=lr_eval_string("{updatefoldercode}");
       strcat(real,code);
       strcpy(content,"code:200  flag_update:true");
       strcat(content," id_creater:");
       strcat(content,lr_eval_string("{Usercode}"));
       //���code������200���ʹ�ӡmsg��
       if(atoi(code)==200)
       {
       		result=0;
       }
       	else{
       	result=1;   	
       	}
       write(result,V_testres,"�޸��ļ����ļ��нӿ���֤",content,real);  

  /*�����������ݻ��ȡ�ؼ��ʽӿڲ��ԣ�articlecontent��ʾ���������*/     
       sprintf(
       destString,
        "{\"orgId\":\"1\",\"params\":{\"content\":\"%s\"},\"seed\":\"seed\",\"token\":\"%s\",\"userId\":\"%s\"}",
        lr_eval_string("{articlecontent}"),      
        lr_eval_string("{Token}"),
        lr_eval_string("{Usercode}")
       );       
       lr_save_string(destString, "str_article_content");
       lr_output_message("destString before��%s", lr_eval_string("{str_article_content}"));
       lr_convert_string_encoding(
       lr_eval_string("{str_article_content}"),
          NULL,
          "utf-8",
          "Body"
       );
lr_output_message("destString after ��%s", lr_eval_string("{Body}"));
 web_reg_save_param("keywordscode",
        "LB=\"code\":",
		"RB=\,",
		LAST); 
 textfind=web_reg_find("Text=keywords", LAST);	
msg=web_reg_save_param("error",
		"LB=\"message\":\"",
		"RB=\"",
		LAST); 
 lr_start_transaction("Getkeywords");
 web_custom_request("Getkeywords", 
              "URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/third_party/ai_checker/get_keywords", 
              "Method=POST", 
              "Resource=0", 
              "RecContentType=application/json", 
              "Referer=https://center.t.dacube.cn/", 
              "Snapshot=t23.inf", 
              "Mode=HTML", 
              "EncType=application/json;charset=UTF-8", 
              "Body={Body}",
              LAST);
 lr_end_transaction("Getkeywords", LR_AUTO);

	   strcpy(real,"code:");
       code=lr_eval_string("{keywordscode}");
       strcat(real,code);
       strcpy(content,"code:200  ��⵽�ؼ���");
       //���code������200���ʹ�ӡmsg��
       if(atoi(code)==200){
       	 if(textfind==0){
	      lr_output_message("�ı������ɹ�");
	       strcat(real," ��鵽��Ӧ�Ĺؼ���");
	      result=0;
	     }
	     else{
		  lr_output_message("�ı�����ʧ��");
	      result=1;
	      strcat(real,"message:");
	      strcat(real,lr_eval_string("{error}"));
	     }	
       }
       	else{
       	result=1;         	
       	}
       write(result,V_testres,"��ȡ�ؼ��ʽӿ���֤",content,real);  
 //articlecontent��ʾ���������       
 web_set_max_html_param_len("30");
       sprintf(
       dest1String,
              "{\"orgId\":\"1\",\"params\":{\"afinal\": false,\"author\":\"С��\",\"content\":\"�μ������ʱȴ������Щʧ�䣬�����������������ǣ��Լ�������ʮ��ԭ�ӵ����飬��������һ���ӹ������ʾ���ߣ���������Ƕ�Ц�ˣ������֣���Ҫ��ţ�ˣ���ԭ�ӵ��Ļ�ס��������ô���õĵط���\",\"id_folder\":\"default-repository-personal-1-article-e729e146-f249-42e1-960d-5c1f3f60bc9a\",\"id_repo\":\"repository-personal-1-article-e729e146-f249-42e1-960d-5c1f3f60bc9a\",\"source\":\"11111123\",\"summary\":\"�μ������ʱȴ������Щʧ�䣬�����������������ǣ��Լ�������ʮ��ԭ�ӵ����飬��������һ���ӹ������ʾ���ߣ���������Ƕ�Ц�ˣ������֣���Ҫ��ţ�ˣ���ԭ�ӵ��Ļ�ס��������ô���õĵط���\",\"title\":\"ԭ���ֵ���״\",\"update_type\": false},\"seed\":\"seed\",\"token\":\"%s\",\"userId\":\"%s\"}",
        lr_eval_string("{Token}"),
        lr_eval_string("{Usercode}")
       );       
       lr_save_string(dest1String, "str_article_content1");
    lr_output_message("destString before��%s", lr_eval_string("{str_article_content1}"));
       lr_convert_string_encoding(
          lr_eval_string("{str_article_content1}"),
          NULL,
          "utf-8",     
          "Body1"
       );
 //�ڸ��˿�Ĭ���ļ�������һƪ���
	textfind=web_reg_find("Text/BIN/DIG/ALNUMIC=content",
		LAST);                   
	   web_reg_save_param("articleid1",
              "LB=\"id\"",
              "RB=",
             "SaveOffset=2",
              "SaveLen=36",
              "ORD=1",
              LAST);
	  reg_fun("add_one");
	 lr_start_transaction("add_article");
 
      web_custom_request("add_article", 
              "URL= https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/article/add_one", 
              "Method=POST", 
              "Resource=0", 
              "RecContentType=application/json", 
              "Referer=https://center.t.dacube.cn/", 
              "Snapshot=t24.inf", 
              "Mode=HTML", 
              "EncType=application/json;charset=UTF-8", 
               "Body={Body1}",
              LAST);  
	 lr_end_transaction("add_article", LR_AUTO);
     lr_output_message("articleid��%s", lr_eval_string("{articleid1}"));      
       code=lr_eval_string("{add_one}");
       error=lr_eval_string("{error}");
       logic(code,"�½�һƪ����ӿڲ���","code:200 �½�����ɹ�","  �½�����ɹ�",error);
   //��з���
    reg_fun("analysis");
    lr_start_transaction("analysis");
  
      web_custom_request("analysis", 
              "URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/third_party/ai_checker/get_verify_package", 
              "Method=POST", 
              "Resource=0", 
              "RecContentType=application/json", 
              "Referer=https://center.t.dacube.cn/", 
              "Snapshot=t25.inf", 
              "Mode=HTML", 
              "EncType=application/json;charset=UTF-8", 
              "Body={\"orgId\":\"1\",\"params\":{\"content\": \"132\",\"id\":\"\",\"title\":\"7941555\"},\"seed\": \"seed\",\"toke\": \"{Token}\",\"userId\": \"{Usercode}\"}",
              LAST); 
    lr_end_transaction("analysis", LR_AUTO);

       code=lr_eval_string("{analysis}");
       error=lr_eval_string("{error}");
	   logic(code,"��з����ӿڲ���","code:200 ��з����ɹ�","  ��з����ɹ�",error);
       
  //��ѯ���
  lr_start_transaction("query_article");

      reg_fun("query_article");	
          web_custom_request("query_article", 
              "URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/article/query_article", 
              "Method=POST", 
              "Resource=0", 
              "RecContentType=application/json", 
              "Referer=https://center.t.dacube.cn/", 
              "Snapshot=t26.inf", 
              "Mode=HTML", 
              "EncType=application/json;charset=UTF-8", 
              "Body={\"orgId\":\"1\",\"params\":{\"flag_audit\": \"all\",\"flag_my_create\": false,\"flag_push\": \"all\",\"flag_sys_source\": \"all\",\"flag_use\": \"all\",\"id_folder\": \"default-repository-personal-1-article-e729e146-f249-42e1-960d-5c1f3f60bc9a\",\"keywords\": \"8\",\"match_field\": \"all\",\"page_size\": 10},\"seed\":\"seed\",\"token\":\"{Token}\",\"userId\":\"{Usercode}\"}",
              LAST); 
      lr_end_transaction("query_article", LR_AUTO);

       code=lr_eval_string("{query_article}");
       error=lr_eval_string("{error}");
	   logic(code,"��ѯ����ӿڲ���","code:200 ��ѯ�������ɹ�","  ��ѯ�������ɹ�",error);
 
	   
 //��ȡ΢�ſ���
 lr_start_transaction("query_article");

      reg_fun("query_article");	
      web_custom_request("query_article", 
              "URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/article/query_article", 
              "Method=POST", 
              "Resource=0", 
              "RecContentType=application/json", 
              "Referer=https://center.t.dacube.cn/", 
              "Snapshot=t27.inf", 
              "Mode=HTML", 
              "EncType=application/json;charset=UTF-8", 
              "Body={\"orgId\":\"1\",\"params\":{\"flag_audit\": \"all\",\"flag_my_create\": false,\"flag_push\": \"all\",\"flag_sys_source\": \"all\",\"flag_use\": \"all\",\"id_folder\": \"795902517245378560\",\"keywords\": \"\",\"match_field\": \"all\",\"page_size\": 20},\"seed\":\"seed\",\"token\":\"{Token}\",\"userId\":\"{Usercode}\"}",
              LAST);  
  lr_end_transaction("query_article", LR_AUTO);
    
       code=lr_eval_string("{query_article}");
       error=lr_eval_string("{error}");
	   logic(code,"��ȡ΢�ſ����ӿڲ���","code:200 ��ȡ΢�ſ����ɹ�","  ��ȡ΢�ſ����ɹ�",error);
 //Ϊ�����������
      reg_fun("add_comment");
  lr_start_transaction("add_comment");
     
      web_custom_request("add_comment", 
              "URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/log_comment/add_comment", 
              "Method=POST", 
              "Resource=0", 
              "RecContentType=application/json", 
              "Referer=https://center.t.dacube.cn/", 
              "Snapshot=t27.inf", 
              "Mode=HTML", 
              "EncType=application/json;charset=UTF-8", 
              "Body={\"orgId\":\"1\",\"params\":{\"comment\": \"this article is very good\",\"id\": \"{articleid1}\"},\"seed\":\"seed\",\"token\":\"{Token}\",\"userId\":\"{Usercode}\"}",
              LAST); 
  lr_end_transaction("add_comment", LR_AUTO);

       code=lr_eval_string("{add_comment}");
       error=lr_eval_string("{error}");
	   logic(code,"Ϊ����������۽ӿڲ���","code:200 Ϊ����������۳ɹ�","  Ϊ����������۳ɹ�",error);
 // ɾ�����
//     reg_fun("delete_one");	      
//     web_custom_request("delete_article", 
//              "URL= https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/article/delete_article", 
//              "Method=POST",       
//              "Resource=0", 
//              "RecContentType=application/json", 
//              "Referer=https://center.t.dacube.cn/", 
//              "Snapshot=t28.inf", 
//              "Mode=HTML", 
//              "EncType=application/json;charset=UTF-8", 
//              "Body={\"orgId\":\"1\",\"params\":{\"id\":\"{articleid1}\"},\"seed\":\"seed\",\"token\":\"{Token}\",\"userId\":\"{Usercode}\"}",
//              LAST);   
//        code=lr_eval_string("{delete_one}");
//	    logic(code,"ɾ������ӿڲ���","code:200  �ɹ�ɾ�����","  �ɹ�ɾ�����",error);
	
return 0;
}




