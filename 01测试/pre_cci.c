# 1 "e:\\test\\01\262\342\312\324\\\\combined_01.c"
# 1 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h" 1
 
 












 











# 103 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"





















































		


		typedef unsigned size_t;
	
	
        
	

















	

 



















 
 
 
 
 


 
 
 
 
 
 














int     lr_start_transaction   (char * transaction_name);
int lr_start_sub_transaction          (char * transaction_name, char * trans_parent);
long lr_start_transaction_instance    (char * transaction_name, long parent_handle);
int   lr_start_cross_vuser_transaction		(char * transaction_name, char * trans_id_param); 



int     lr_end_transaction     (char * transaction_name, int status);
int lr_end_sub_transaction            (char * transaction_name, int status);
int lr_end_transaction_instance       (long transaction, int status);
int   lr_end_cross_vuser_transaction	(char * transaction_name, char * trans_id_param, int status);


 
typedef char* lr_uuid_t;
 



lr_uuid_t lr_generate_uuid();

 


int lr_generate_uuid_free(lr_uuid_t uuid);

 



int lr_generate_uuid_on_buf(lr_uuid_t buf);

   
# 273 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"
int lr_start_distributed_transaction  (char * transaction_name, lr_uuid_t correlator, long timeout  );

   







int lr_end_distributed_transaction  (lr_uuid_t correlator, int status);


double lr_stop_transaction            (char * transaction_name);
double lr_stop_transaction_instance   (long parent_handle);


void lr_resume_transaction           (char * trans_name);
void lr_resume_transaction_instance  (long trans_handle);


int lr_update_transaction            (const char *trans_name);


 
void lr_wasted_time(long time);


 
int lr_set_transaction(const char *name, double duration, int status);
 
long lr_set_transaction_instance(const char *name, double duration, int status, long parent_handle);


int   lr_user_data_point                      (char *, double);
long lr_user_data_point_instance                   (char *, double, long);
 



int lr_user_data_point_ex(const char *dp_name, double value, int log_flag);
long lr_user_data_point_instance_ex(const char *dp_name, double value, long parent_handle, int log_flag);


int lr_transaction_add_info      (const char *trans_name, char *info);
int lr_transaction_instance_add_info   (long trans_handle, char *info);
int lr_dpoint_add_info           (const char *dpoint_name, char *info);
int lr_dpoint_instance_add_info        (long dpoint_handle, char *info);


double lr_get_transaction_duration       (char * trans_name);
double lr_get_trans_instance_duration    (long trans_handle);
double lr_get_transaction_think_time     (char * trans_name);
double lr_get_trans_instance_think_time  (long trans_handle);
double lr_get_transaction_wasted_time    (char * trans_name);
double lr_get_trans_instance_wasted_time (long trans_handle);
int    lr_get_transaction_status		 (char * trans_name);
int	   lr_get_trans_instance_status		 (long trans_handle);

 



int lr_set_transaction_status(int status);

 



int lr_set_transaction_status_by_name(int status, const char *trans_name);
int lr_set_transaction_instance_status(int status, long trans_handle);


typedef void* merc_timer_handle_t;
 

merc_timer_handle_t lr_start_timer();
double lr_end_timer(merc_timer_handle_t timer_handle);


 
 
 
 
 
 











 



int   lr_rendezvous  (char * rendezvous_name);
 




int   lr_rendezvous_ex (char * rendezvous_name);



 
 
 
 
 
char *lr_get_vuser_ip (void);
void   lr_whoami (int *vuser_id, char ** sgroup, int *scid);
char *	  lr_get_host_name (void);
char *	  lr_get_master_host_name (void);

 
long     lr_get_attrib_long	(char * attr_name);
char *   lr_get_attrib_string	(char * attr_name);
double   lr_get_attrib_double      (char * attr_name);

char * lr_paramarr_idx(const char * paramArrayName, unsigned int index);
char * lr_paramarr_random(const char * paramArrayName);
int    lr_paramarr_len(const char * paramArrayName);

int	lr_param_unique(const char * paramName);
int lr_param_sprintf(const char * paramName, const char * format, ...);


 
 
static void *ci_this_context = 0;






 








void lr_continue_on_error (int lr_continue);
char *   lr_unmask (const char *EncodedString);
char *   lr_decrypt (const char *EncodedString);


 
 
 
 
 
 



 







 















void   lr_abort (void);
void lr_exit(int exit_option, int exit_status);
void lr_abort_ex (unsigned long flags);

void   lr_peek_events (void);


 
 
 
 
 


void   lr_think_time (double secs);

 


void lr_force_think_time (double secs);


 
 
 
 
 



















int   lr_msg (char * fmt, ...);
int   lr_debug_message (unsigned int msg_class,
									    char * format,
										...);
# 513 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"
void   lr_new_prefix (int type,
                                 char * filename,
                                 int line);
# 516 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"
int   lr_log_message (char * fmt, ...);
int   lr_message (char * fmt, ...);
int   lr_error_message (char * fmt, ...);
int   lr_output_message (char * fmt, ...);
int   lr_vuser_status_message (char * fmt, ...);
int   lr_error_message_without_fileline (char * fmt, ...);
int   lr_fail_trans_with_error (char * fmt, ...);

 
 
 
 
 
# 540 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"

 
 
 
 
 





int   lr_next_row ( char * table);
int lr_advance_param ( char * param);



														  
														  

														  
														  

													      
 


char *   lr_eval_string (char * str);
int   lr_eval_string_ext (const char *in_str,
                                     unsigned long const in_len,
                                     char ** const out_str,
                                     unsigned long * const out_len,
                                     unsigned long const options,
                                     const char *file,
								     long const line);
# 574 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"
void   lr_eval_string_ext_free (char * * pstr);

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int lr_param_increment (char * dst_name,
                              char * src_name);
# 597 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"













											  
											  

											  
											  
											  

int	  lr_save_var (char *              param_val,
							  unsigned long const param_val_len,
							  unsigned long const options,
							  char *			  param_name);
# 621 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"
int   lr_save_string (const char * param_val, const char * param_name);



int   lr_set_custom_error_message (const char * param_val, ...);

int   lr_remove_custom_error_message ();


int   lr_free_parameter (const char * param_name);
int   lr_save_int (const int param_val, const char * param_name);
int   lr_save_timestamp (const char * tmstampParam, ...);
int   lr_save_param_regexp (const char *bufferToScan, unsigned int bufSize, ...);

int   lr_convert_double_to_integer (const char *source_param_name, const char * target_param_name);
int   lr_convert_double_to_double (const char *source_param_name, const char *format_string, const char * target_param_name);

 
 
 
 
 
 
# 700 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"
void   lr_save_datetime (const char *format, int offset, const char *name);









 











 
 
 
 
 






 



char * lr_error_context_get_entry (char * key);

 



long   lr_error_context_get_error_id (void);


 
 
 

int lr_table_get_rows_num (char * param_name);

int lr_table_get_cols_num (char * param_name);

char * lr_table_get_cell_by_col_index (char * param_name, int row, int col);

char * lr_table_get_cell_by_col_name (char * param_name, int row, const char* col_name);

int lr_table_get_column_name_by_index (char * param_name, int col, 
											char * * const col_name,
											size_t * col_name_len);
# 761 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"

int lr_table_get_column_name_by_index_free (char * col_name);

 
 
 
 
# 776 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"
int   lr_zip (const char* param1, const char* param2);
int   lr_unzip (const char* param1, const char* param2);

 
 
 
 
 
 
 
 

 
 
 
 
 
 
int   lr_param_substit (char * file,
                                   int const line,
                                   char * in_str,
                                   size_t const in_len,
                                   char * * const out_str,
                                   size_t * const out_len);
# 800 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"
void   lr_param_substit_free (char * * pstr);


 
# 812 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"





char *   lrfnc_eval_string (char * str,
                                      char * file_name,
                                      long const line_num);
# 820 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"


int   lrfnc_save_string ( const char * param_val,
                                     const char * param_name,
                                     const char * file_name,
                                     long const line_num);
# 826 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"

int   lrfnc_free_parameter (const char * param_name );







typedef struct _lr_timestamp_param
{
	int iDigits;
}lr_timestamp_param;

extern const lr_timestamp_param default_timestamp_param;

int   lrfnc_save_timestamp (const char * param_name, const lr_timestamp_param* time_param);

int lr_save_searched_string(char * buffer, long buf_size, unsigned int occurrence,
			    char * search_string, int offset, unsigned int param_val_len, 
			    char * param_name);

 
char *   lr_string (char * str);

 
# 929 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"

int   lr_save_value (char * param_val,
                                unsigned long const param_val_len,
                                unsigned long const options,
                                char * param_name,
                                char * file_name,
                                long const line_num);
# 936 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"


 
 
 
 
 











int   lr_printf (char * fmt, ...);
 
int   lr_set_debug_message (unsigned int msg_class,
                                       unsigned int swtch);
# 958 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"
unsigned int   lr_get_debug_message (void);


 
 
 
 
 

void   lr_double_think_time ( double secs);
void   lr_usleep (long);


 
 
 
 
 
 




int *   lr_localtime (long offset);


int   lr_send_port (long port);


# 1034 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"



struct _lr_declare_identifier{
	char signature[24];
	char value[128];
};

int   lr_pt_abort (void);

void vuser_declaration (void);






# 1063 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"


# 1075 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/lrun.h"
















 
 
 
 
 







int    _lr_declare_transaction   (char * transaction_name);


 
 
 
 
 







int   _lr_declare_rendezvous  (char * rendezvous_name);

 
 
 
 
 


typedef int PVCI;






typedef int VTCERR;









PVCI   vtc_connect(char * servername, int portnum, int options);
VTCERR   vtc_disconnect(PVCI pvci);
VTCERR   vtc_get_last_error(PVCI pvci);
VTCERR   vtc_query_column(PVCI pvci, char * columnName, int columnIndex, char * *outvalue);
VTCERR   vtc_query_row(PVCI pvci, int rowIndex, char * **outcolumns, char * **outvalues);
VTCERR   vtc_send_message(PVCI pvci, char * column, char * message, unsigned short *outRc);
VTCERR   vtc_send_if_unique(PVCI pvci, char * column, char * message, unsigned short *outRc);
VTCERR   vtc_send_row1(PVCI pvci, char * columnNames, char * messages, char * delimiter, unsigned char sendflag, unsigned short *outUpdates);
VTCERR   vtc_update_message(PVCI pvci, char * column, int index , char * message, unsigned short *outRc);
VTCERR   vtc_update_message_ifequals(PVCI pvci, char * columnName, int index,	char * message, char * ifmessage, unsigned short 	*outRc);
VTCERR   vtc_update_row1(PVCI pvci, char * columnNames, int index , char * messages, char * delimiter, unsigned short *outUpdates);
VTCERR   vtc_retrieve_message(PVCI pvci, char * column, char * *outvalue);
VTCERR   vtc_retrieve_messages1(PVCI pvci, char * columnNames, char * delimiter, char * **outvalues);
VTCERR   vtc_retrieve_row(PVCI pvci, char * **outcolumns, char * **outvalues);
VTCERR   vtc_rotate_message(PVCI pvci, char * column, char * *outvalue, unsigned char sendflag);
VTCERR   vtc_rotate_messages1(PVCI pvci, char * columnNames, char * delimiter, char * **outvalues, unsigned char sendflag);
VTCERR   vtc_rotate_row(PVCI pvci, char * **outcolumns, char * **outvalues, unsigned char sendflag);
VTCERR   vtc_increment(PVCI pvci, char * column, int index , int incrValue, int *outValue);
VTCERR   vtc_clear_message(PVCI pvci, char * column, int index , unsigned short *outRc);
VTCERR   vtc_clear_column(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_ensure_index(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_drop_index(PVCI pvci, char * column, unsigned short *outRc);
VTCERR   vtc_clear_row(PVCI pvci, int rowIndex, unsigned short *outRc);
VTCERR   vtc_create_column(PVCI pvci, char * column,unsigned short *outRc);
VTCERR   vtc_column_size(PVCI pvci, char * column, int *size);
void   vtc_free(char * msg);
void   vtc_free_list(char * *msglist);

VTCERR   lrvtc_connect(char * servername, int portnum, int options);
VTCERR   lrvtc_connect_ex(char * vtc_first_param, ...);
VTCERR   lrvtc_connect_ex_no_ellipsis(const char *vtc_first_param, char ** arguments, int argCount);
VTCERR   lrvtc_disconnect();
VTCERR   lrvtc_query_column(char * columnName, int columnIndex);
VTCERR   lrvtc_query_row(int columnIndex);
VTCERR   lrvtc_send_message(char * columnName, char * message);
VTCERR   lrvtc_send_if_unique(char * columnName, char * message);
VTCERR   lrvtc_send_row1(char * columnNames, char * messages, char * delimiter, unsigned char sendflag);
VTCERR   lrvtc_update_message(char * columnName, int index , char * message);
VTCERR   lrvtc_update_message_ifequals(char * columnName, int index, char * message, char * ifmessage);
VTCERR   lrvtc_update_row1(char * columnNames, int index , char * messages, char * delimiter);
VTCERR   lrvtc_retrieve_message(char * columnName);
VTCERR   lrvtc_retrieve_messages1(char * columnNames, char * delimiter);
VTCERR   lrvtc_retrieve_row();
VTCERR   lrvtc_rotate_message(char * columnName, unsigned char sendflag);
VTCERR   lrvtc_rotate_messages1(char * columnNames, char * delimiter, unsigned char sendflag);
VTCERR   lrvtc_rotate_row(unsigned char sendflag);
VTCERR   lrvtc_increment(char * columnName, int index , int incrValue);
VTCERR   lrvtc_noop();
VTCERR   lrvtc_clear_message(char * columnName, int index);
VTCERR   lrvtc_clear_column(char * columnName); 
VTCERR   lrvtc_ensure_index(char * columnName); 
VTCERR   lrvtc_drop_index(char * columnName); 
VTCERR   lrvtc_clear_row(int rowIndex);
VTCERR   lrvtc_create_column(char * columnName);
VTCERR   lrvtc_column_size(char * columnName);



 
 
 
 
 

 
int lr_enable_ip_spoofing();
int lr_disable_ip_spoofing();


 




int lr_convert_string_encoding(char * sourceString, char * fromEncoding, char * toEncoding, char * paramName);
int lr_read_file(const char *filename, const char *outputParam, int continueOnError);

int lr_get_char_count(const char * string);


 
int lr_db_connect (char * pFirstArg, ...);
int lr_db_disconnect (char * pFirstArg,	...);
int lr_db_executeSQLStatement (char * pFirstArg, ...);
int lr_db_dataset_action(char * pFirstArg, ...);
int lr_checkpoint(char * pFirstArg,	...);
int lr_db_getvalue(char * pFirstArg, ...);







 
 



















# 1 "e:\\test\\01\262\342\312\324\\\\combined_01.c" 2

# 1 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/SharedParameter.h" 1



 
 
 
 
# 100 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/SharedParameter.h"






typedef int PVCI2;






typedef int VTCERR2;


 
 
 

 
extern PVCI2    vtc_connect(char *servername, int portnum, int options);
extern VTCERR2  vtc_disconnect(PVCI2 pvci);
extern VTCERR2  vtc_get_last_error(PVCI2 pvci);

 
extern VTCERR2  vtc_query_column(PVCI2 pvci, char *columnName, int columnIndex, char **outvalue);
extern VTCERR2  vtc_query_row(PVCI2 pvci, int columnIndex, char ***outcolumns, char ***outvalues);
extern VTCERR2  vtc_send_message(PVCI2 pvci, char *column, char *message, unsigned short *outRc);
extern VTCERR2  vtc_send_if_unique(PVCI2 pvci, char *column, char *message, unsigned short *outRc);
extern VTCERR2  vtc_send_row1(PVCI2 pvci, char *columnNames, char *messages, char *delimiter,  unsigned char sendflag, unsigned short *outUpdates);
extern VTCERR2  vtc_update_message(PVCI2 pvci, char *column, int index , char *message, unsigned short *outRc);
extern VTCERR2  vtc_update_message_ifequals(PVCI2 pvci, char	*columnName, int index,	char *message, char	*ifmessage,	unsigned short 	*outRc);
extern VTCERR2  vtc_update_row1(PVCI2 pvci, char *columnNames, int index , char *messages, char *delimiter, unsigned short *outUpdates);
extern VTCERR2  vtc_retrieve_message(PVCI2 pvci, char *column, char **outvalue);
extern VTCERR2  vtc_retrieve_messages1(PVCI2 pvci, char *columnNames, char *delimiter, char ***outvalues);
extern VTCERR2  vtc_retrieve_row(PVCI2 pvci, char ***outcolumns, char ***outvalues);
extern VTCERR2  vtc_rotate_message(PVCI2 pvci, char *column, char **outvalue, unsigned char sendflag);
extern VTCERR2  vtc_rotate_messages1(PVCI2 pvci, char *columnNames, char *delimiter, char ***outvalues, unsigned char sendflag);
extern VTCERR2  vtc_rotate_row(PVCI2 pvci, char ***outcolumns, char ***outvalues, unsigned char sendflag);
extern VTCERR2	vtc_increment(PVCI2 pvci, char *column, int index , int incrValue, int *outValue);
extern VTCERR2  vtc_clear_message(PVCI2 pvci, char *column, int index , unsigned short *outRc);
extern VTCERR2  vtc_clear_column(PVCI2 pvci, char *column, unsigned short *outRc);

extern VTCERR2  vtc_clear_row(PVCI2 pvci, int rowIndex, unsigned short *outRc);

extern VTCERR2  vtc_create_column(PVCI2 pvci, char *column,unsigned short *outRc);
extern VTCERR2  vtc_column_size(PVCI2 pvci, char *column, int *size);
extern VTCERR2  vtc_ensure_index(PVCI2 pvci, char *column, unsigned short *outRc);
extern VTCERR2  vtc_drop_index(PVCI2 pvci, char *column, unsigned short *outRc);

extern VTCERR2  vtc_noop(PVCI2 pvci);

 
extern void vtc_free(char *msg);
extern void vtc_free_list(char **msglist);

 


 




 




















 




 
 
 

extern VTCERR2  lrvtc_connect(char *servername, int portnum, int options);
 
 
extern VTCERR2  lrvtc_disconnect();
extern VTCERR2  lrvtc_query_column(char *columnName, int columnIndex);
extern VTCERR2  lrvtc_query_row(int columnIndex);
extern VTCERR2  lrvtc_send_message(char *columnName, char *message);
extern VTCERR2  lrvtc_send_if_unique(char *columnName, char *message);
extern VTCERR2  lrvtc_send_row1(char *columnNames, char *messages, char *delimiter,  unsigned char sendflag);
extern VTCERR2  lrvtc_update_message(char *columnName, int index , char *message);
extern VTCERR2  lrvtc_update_message_ifequals(char *columnName, int index, char 	*message, char *ifmessage);
extern VTCERR2  lrvtc_update_row1(char *columnNames, int index , char *messages, char *delimiter);
extern VTCERR2  lrvtc_retrieve_message(char *columnName);
extern VTCERR2  lrvtc_retrieve_messages1(char *columnNames, char *delimiter);
extern VTCERR2  lrvtc_retrieve_row();
extern VTCERR2  lrvtc_rotate_message(char *columnName, unsigned char sendflag);
extern VTCERR2  lrvtc_rotate_messages1(char *columnNames, char *delimiter, unsigned char sendflag);
extern VTCERR2  lrvtc_rotate_row(unsigned char sendflag);
extern VTCERR2  lrvtc_increment(char *columnName, int index , int incrValue);
extern VTCERR2  lrvtc_clear_message(char *columnName, int index);
extern VTCERR2  lrvtc_clear_column(char *columnName);
extern VTCERR2  lrvtc_clear_row(int rowIndex);
extern VTCERR2  lrvtc_create_column(char *columnName);
extern VTCERR2  lrvtc_column_size(char *columnName);
extern VTCERR2  lrvtc_ensure_index(char *columnName);
extern VTCERR2  lrvtc_drop_index(char *columnName);

extern VTCERR2  lrvtc_noop();

 
 
 

                               


 
 
 





















# 2 "e:\\test\\01\262\342\312\324\\\\combined_01.c" 2

# 1 "globals.h" 1



 
 

# 1 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/web_api.h" 1







# 1 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/as_web.h" 1



























































 




 



 











 





















 
 
 

  int
	web_add_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_add_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
	
  int
	web_add_auto_header(
		const char *		mpszHeader,
		const char *		mpszValue);

  int
	web_add_header(
		const char *		mpszHeader,
		const char *		mpszValue);
  int
	web_add_cookie(
		const char *		mpszCookie);
  int
	web_cleanup_auto_headers(void);
  int
	web_cleanup_cookies(void);
  int
	web_concurrent_end(
		const char * const	mpszReserved,
										 
		...								 
	);
  int
	web_concurrent_start(
		const char * const	mpszConcurrentGroupName,
										 
										 
		...								 
										 
	);
  int
	web_create_html_param(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim);
  int
	web_create_html_param_ex(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim,
		const char *		mpszNum);
  int
	web_custom_request(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	spdy_custom_request(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_disable_keep_alive(void);
  int
	web_enable_keep_alive(void);
  int
	web_find(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_get_int_property(
		const int			miHttpInfoType);
  int
	web_image(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_image_check(
		const char *		mpszName,
		...);
  int
	web_java_check(
		const char *		mpszName,
		...);
  int
	web_link(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

	
  int
	web_global_verification(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
  int
	web_reg_find(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
				
  int
	web_reg_save_param(
		const char *		mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 

  int
	web_convert_param(
		const char * 		mpszParamName, 
										 
		...);							 
										 
										 


										 

										 
  int
	web_remove_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
				
  int
	web_remove_auto_header(
		const char *		mpszHeaderName,
		...);							 
										 



  int
	web_remove_cookie(
		const char *		mpszCookie);

  int
	web_save_header(
		const char *		mpszType,	 
		const char *		mpszName);	 
  int
	web_set_certificate(
		const char *		mpszIndex);
  int
	web_set_certificate_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_set_connections_limit(
		const char *		mpszLimit);
  int
	web_set_max_html_param_len(
		const char *		mpszLen);
  int
	web_set_max_retries(
		const char *		mpszMaxRetries);
  int
	web_set_proxy(
		const char *		mpszProxyHost);
  int
	web_set_pac(
		const char *		mpszPacUrl);
  int
	web_set_proxy_bypass(
		const char *		mpszBypass);
  int
	web_set_secure_proxy(
		const char *		mpszProxyHost);
  int
	web_set_sockets_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue
	);
  int
	web_set_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue,
		...								 
	);
  int
	web_set_timeout(
		const char *		mpszWhat,
		const char *		mpszTimeout);
  int
	web_set_user(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);

  int
	web_sjis_to_euc_param(
		const char *		mpszParamName,
										 
		const char *		mpszParamValSjis);
										 

  int
	web_submit_data(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	spdy_submit_data(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_submit_form(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_url(
		const char *		mpszUrlName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	spdy_url(
		const char *		mpszUrlName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_set_proxy_bypass_local(
		const char * mpszNoLocal
		);

  int 
	web_cache_cleanup(void);

  int
	web_create_html_query(
		const char* mpszStartQuery,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_create_radio_button_param(
		const char *NameFiled,
		const char *NameAndVal,
		const char *ParamName
		);

  int
	web_convert_from_formatted(
		const char * mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										
  int
	web_convert_to_formatted(
		const char * mpszArg1,
		...);							 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_ex(
		const char * mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_xpath(
		const char * mpszParamName,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_json(
		const char * mpszParamName,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_regexp(
		 const char * mpszParamName,
		 ...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_attrib(
		const char * mpszParamName,
		...);
										 
										 
										 
										 
										 
										 
										 		
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_js_run(
		const char * mpszCode,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_js_reset(void);

  int
	web_convert_date_param(
		const char * 		mpszParamName,
		...);










# 789 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/as_web.h"


# 802 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/as_web.h"



























# 840 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/as_web.h"

 
 
 


  int
	FormSubmit(
		const char *		mpszFormName,
		...);
  int
	InitWebVuser(void);
  int
	SetUser(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);
  int
	TerminateWebVuser(void);
  int
	URL(
		const char *		mpszUrlName);
























# 908 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/as_web.h"


  int
	web_rest(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 

  int
web_stream_open(
	const char *		mpszArg1,
	...
);
  int
	web_stream_wait(
		const char *		mpszArg1,
		...
	);

  int
	web_stream_close(
		const char *		mpszArg1,
		...
	);

  int
web_stream_play(
	const char *		mpszArg1,
	...
	);

  int
web_stream_pause(
	const char *		mpszArg1,
	...
	);

  int
web_stream_seek(
	const char *		mpszArg1,
	...
	);

  int
web_stream_get_param_int(
	const char*			mpszStreamID,
	const int			miStateType
	);

  double
web_stream_get_param_double(
	const char*			mpszStreamID,
	const int			miStateType
	);

  int
web_stream_get_param_string(
	const char*			mpszStreamID,
	const int			miStateType,
	const char*			mpszParameterName
	);

  int
web_stream_set_param_int(
	const char*			mpszStreamID,
	const int			miStateType,
	const int			miStateValue
	);

  int
web_stream_set_param_double(
	const char*			mpszStreamID,
	const int			miStateType,
	const double		mdfStateValue
	);

  int
web_stream_set_custom_mpd(
	const char*			mpszStreamID,
	const char*			aMpdBuf
	);

 
 
 






# 9 "C:\\Program Files (x86)\\Micro Focus\\LoadRunner\\include/web_api.h" 2

















 







 















  int
	web_reg_add_cookie(
		const char *		mpszCookie,
		...);							 
										 

  int
	web_report_data_point(
		const char *		mpszEventType,
		const char *		mpszEventName,
		const char *		mpszDataPointName,
		const char *		mpszLAST);	 
										 
										 
										 

  int
	web_text_link(
		const char *		mpszStepName,
		...);

  int
	web_element(
		const char *		mpszStepName,
		...);

  int
	web_image_link(
		const char *		mpszStepName,
		...);

  int
	web_static_image(
		const char *		mpszStepName,
		...);

  int
	web_image_submit(
		const char *		mpszStepName,
		...);

  int
	web_button(
		const char *		mpszStepName,
		...);

  int
	web_edit_field(
		const char *		mpszStepName,
		...);

  int
	web_radio_group(
		const char *		mpszStepName,
		...);

  int
	web_check_box(
		const char *		mpszStepName,
		...);

  int
	web_list(
		const char *		mpszStepName,
		...);

  int
	web_text_area(
		const char *		mpszStepName,
		...);

  int
	web_map_area(
		const char *		mpszStepName,
		...);

  int
	web_eval_java_script(
		const char *		mpszStepName,
		...);

  int
	web_reg_dialog(
		const char *		mpszArg1,
		...);

  int
	web_reg_cross_step_download(
		const char *		mpszArg1,
		...);

  int
	web_browser(
		const char *		mpszStepName,
		...);

  int
	web_control(
		const char *		mpszStepName,
		...);

  int
	web_set_rts_key(
		const char *		mpszArg1,
		...);

  int
	web_save_param_length(
		const char * 		mpszParamName,
		...);

  int
	web_save_timestamp_param(
		const char * 		mpszParamName,
		...);

  int
	web_load_cache(
		const char *		mpszStepName,
		...);							 
										 

  int
	web_dump_cache(
		const char *		mpszStepName,
		...);							 
										 
										 

  int
	web_reg_find_in_log(
		const char *		mpszArg1,
		...);							 
										 
										 

  int
	web_get_sockets_info(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 

  int
	web_add_cookie_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 

  int
	web_hook_java_script(
		const char *		mpszArg1,
		...);							 
										 
										 
										 

 
 
 
 
 
 
 
 
 
 
 
 
  int
	web_reg_async_attributes(
		const char *		mpszArg,
		...
	);

 
 
 
 
 
 
  int
	web_sync(
		 const char *		mpszArg1,
		 ...
	);

 
 
 
 
  int
	web_stop_async(
		const char *		mpszArg1,
		...
	);

 
 
 
 
 

 
 
 

typedef enum WEB_ASYNC_CB_RC_ENUM_T
{
	WEB_ASYNC_CB_RC_OK,				 

	WEB_ASYNC_CB_RC_ABORT_ASYNC_NOT_ERROR,
	WEB_ASYNC_CB_RC_ABORT_ASYNC_ERROR,
										 
										 
										 
										 
	WEB_ASYNC_CB_RC_ENUM_COUNT
} WEB_ASYNC_CB_RC_ENUM;

 
 
 

typedef enum WEB_CONVERS_CB_CALL_REASON_ENUM_T
{
	WEB_CONVERS_CB_CALL_REASON_BUFFER_RECEIVED,
	WEB_CONVERS_CB_CALL_REASON_END_OF_TASK,

	WEB_CONVERS_CB_CALL_REASON_ENUM_COUNT
} WEB_CONVERS_CB_CALL_REASON_ENUM;

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

typedef
int														 
	(*RequestCB_t)();

typedef
int														 
	(*ResponseBodyBufferCB_t)(
		  const char *		aLastBufferStr,
		  int				aLastBufferLen,
		  const char *		aAccumulatedStr,
		  int				aAccumulatedLen,
		  int				aHttpStatusCode);

typedef
int														 
	(*ResponseCB_t)(
		  const char *		aResponseHeadersStr,
		  int				aResponseHeadersLen,
		  const char *		aResponseBodyStr,
		  int				aResponseBodyLen,
		  int				aHttpStatusCode);

typedef
int														 
	(*ResponseHeadersCB_t)(
		  int				aHttpStatusCode,
		  const char *		aAccumulatedHeadersStr,
		  int				aAccumulatedHeadersLen);



 
 
 

typedef enum WEB_CONVERS_UTIL_RC_ENUM_T
{
	WEB_CONVERS_UTIL_RC_OK,
	WEB_CONVERS_UTIL_RC_CONVERS_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_TASK_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_INFO_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_INFO_UNAVIALABLE,
	WEB_CONVERS_UTIL_RC_INVALID_ARGUMENT,

	WEB_CONVERS_UTIL_RC_ENUM_COUNT
} WEB_CONVERS_UTIL_RC_ENUM;

 
 
 

  int					 
	web_util_set_request_url(
		  const char *		aUrlStr);

  int					 
	web_util_set_request_body(
		  const char *		aRequestBodyStr);

  int					 
	web_util_set_formatted_request_body(
		  const char *		aRequestBodyStr);


 
 
 
 
 

 
 
 
 
 

 
 
 
 
 
 
 
 

 
 
  int
web_websocket_connect(
		 const char *	mpszArg1,
		 ...
		 );


 
 
 
 
 																						
  int
web_websocket_send(
	   const char *		mpszArg1,
		...
	   );

 
 
 
 
 
 
  int
web_websocket_close(
		const char *	mpszArg1,
		...
		);

 
typedef
void														
(*OnOpen_t)(
			  const char* connectionID,  
			  const char * responseHeader,  
			  int length  
);

typedef
void														
(*OnMessage_t)(
	  const char* connectionID,  
	  int isbinary,  
	  const char * data,  
	  int length  
	);

typedef
void														
(*OnError_t)(
	  const char* connectionID,  
	  const char * message,  
	  int length  
	);

typedef
void														
(*OnClose_t)(
	  const char* connectionID,  
	  int isClosedByClient,  
	  int code,  
	  const char* reason,  
	  int length  
	 );
 
 
 
 
 





# 7 "globals.h" 2

# 1 "lrw_custom_body.h" 1
 




# 8 "globals.h" 2

# 1 "WebSocketCB.c" 1
void OnOpenCB0 (const char* connectionID,
				  const char * AccumulatedHeadersStr,
				  int AccumulatedHeadersLen)
{
	
 
 
 
 
 
 
 
 

}

void OnMessageCB0 (const char* connectionID,
				  int isbinary,
				  const char * data,
				  int length)
{
	
 
 
 
 
 
 
}

void OnErrorCB0 (const char* connectionID,
				  const char * message,
				  int length)
{
	
 
}

void OnCloseCB0 (const char* connectionID,
				  int isClosedByClient,
				  int code,
				  const char* reason,
				  int length)
{
	
 
}

# 9 "globals.h" 2

# 1 "WebSocketBuffer.h" 1



 

char WebSocketReceive0[] = "<open xmlns='urn:ietf:params:xml:ns:xmpp-framing' version='1.0' xml:lang='en' id"
                        "='2180439051' from='easemob.com'/>";
long WebSocketReceiveLen0   = sizeof(WebSocketReceive0) - 1;	 

 

char WebSocketReceive1[] = "<stream:features xmlns:stream='http://etherx.jabber.org/streams'><mechanisms xml"
                        "ns='urn:ietf:params:xml:ns:xmpp-sasl'><mechanism>PLAIN</mechanism></mechanisms><"
                        "c xmlns='http://jabber.org/protocol/caps' hash='sha-1' node='http://www.easemob."
                        "com/' ver='8CVZGa77VxP1VxmLlVkQdoIUnKU='/><register xmlns='http://jabber.org/fea"
                        "tures/iq-register'/></stream:features>";
long WebSocketReceiveLen1   = sizeof(WebSocketReceive1) - 1;	 

 

char WebSocketReceive2[] = "<success xmlns='urn:ietf:params:xml:ns:xmpp-sasl'/>";
long WebSocketReceiveLen2   = sizeof(WebSocketReceive2) - 1;	 

 

char WebSocketReceive3[] = "<open xmlns='urn:ietf:params:xml:ns:xmpp-framing' version='1.0' xml:lang='en' id"
                        "='3297807179' from='easemob.com'/>";
long WebSocketReceiveLen3   = sizeof(WebSocketReceive3) - 1;	 

 

char WebSocketReceive4[] = "<stream:features xmlns:stream='http://etherx.jabber.org/streams'><bind xmlns='ur"
                        "n:ietf:params:xml:ns:xmpp-bind'/><session xmlns='urn:ietf:params:xml:ns:xmpp-ses"
                        "sion'/><ver xmlns='urn:xmpp:features:rosterver'/><c xmlns='http://jabber.org/pro"
                        "tocol/caps' hash='sha-1' node='http://www.easemob.com/' ver='8CVZGa77VxP1VxmLlVk"
                        "QdoIUnKU='/><register xmlns='http://jabber.org/features/iq-register'/></stream:f"
                        "eatures>";
long WebSocketReceiveLen4   = sizeof(WebSocketReceive4) - 1;	 

 

char WebSocketReceive5[] = "<iq xmlns='jabber:client' id='_bind_auth_2' type='result'><bind xmlns='urn:ietf:"
                        "params:xml:ns:xmpp-bind'><jid>1197180723253749#center-test_115201811061611139ftr"
                        "mgurx@easemob.com/webim_1554888504856</jid></bind></iq>";
long WebSocketReceiveLen5   = sizeof(WebSocketReceive5) - 1;	 

 

char WebSocketReceive6[] = "<iq type='result' xmlns='jabber:client' id='_session_auth_2'/>";
long WebSocketReceiveLen6   = sizeof(WebSocketReceive6) - 1;	 

 

char WebSocketReceive7[] = "<message xmlns='jabber:client' from='1197180723253749#center-test_admin@easemob."
                        "com' to='1197180723253749#center-test_115201811061611139ftrmgurx@easemob.com' ty"
                        "pe='chat' id='589314075037542392'><body>{&quot;bodies&quot;:[{&quot;msg&quot;:&q"
                        "uot;"
                        "\xe3\x80\x90\xe5\x85\xac\xe4\xbc\x97\xe5\x8f\xb7\xe6\x8a\xa5\xe8\xa1\xa8\xe3\x80\x91\xe5\xbe\xae\xe4\xbf\xa1\xe5\x85\xac\xe4\xbc\x97\xe5\x8f\xb7\xe8\xbf\x90\xe8\x90\xa5\xe6\x8a\xa5\xe8\xa1\xa8\xe5\xb7\xb2\xe6\x9b\xb4\xe6\x96\xb0\xef\xbc\x8c\xe8\xaf\xb7\xe6\x9f\xa5\xe7\x9c\x8b"
                        " 2019-04-09 10:00&quot;,&quot;type&quot;:&quot;txt&quot;}],&quot;ext&quot;:{&quo"
                        "t;msg&quot;:&quot;{\\&quot;msg\\&quot;:\\&quot;{\\\\\\&quot;action\\\\\\&quot;:\\"
                        "\\\\&quot;"
                        "\xe6\x9f\xa5\xe7\x9c\x8b\xe8\xaf\xa6\xe6\x83\x85"
                        "\\\\\\&quot;,\\\\\\&quot;appname\\\\\\&quot;:\\\\\\&quot;"
                        "\xe5\x85\xac\xe4\xbc\x97\xe5\x8f\xb7\xe6\x8a\xa5\xe8\xa1\xa8"
                        "\\\\\\&quot;,\\\\\\&quot;appurl\\\\\\&quot;:\\\\\\&quot;https://g.t.dacube.cn/WX"
                        "-SERVICE/ObjWeixinReport/redirect?type=all\\\\\\&quot;,\\\\\\&quot;content\\\\\\"
                        "&quot;:\\\\\\&quot;"
                        "\xe5\xbe\xae\xe4\xbf\xa1\xe5\x85\xac\xe4\xbc\x97\xe5\x8f\xb7\xe8\xbf\x90\xe8\x90\xa5\xe6\x8a\xa5\xe8\xa1\xa8\xe5\xb7\xb2\xe6\x9b\xb4\xe6\x96\xb0\xef\xbc\x8c\xe8\xaf\xb7\xe6\x9f\xa5\xe7\x9c\x8b"
                        " 2019-04-09 10:00\\\\\\&quot;,\\\\\\&quot;contentType\\\\\\&quot;:\\\\\\&quot;"
                        "\xe8\xb7\xb3\xe8\xbd\xac"
                        "\\\\\\&quot;,\\\\\\&quot;logo\\\\\\&quot;:\\\\\\&quot;https://oss.dacube.cn/mesg"
                        "-admin/0019f949-8567-4610-a9f0-7d536b853601/15.png\\\\\\&quot;,\\\\\\&quot;pcurl"
                        "\\\\\\&quot;:\\\\\\&quot;https://g.t.dacube.cn/WX-SERVICE/ObjWeixinReport/redire"
                        "ct?type=all\\\\\\&quot;}\\&quot;,\\&quot;type\\&quot;:\\&quot;app\\&quot;}&quot;"
                        ",&quot;type&quot;:&quot;app&quot;},&quot;from&quot;:&quot;appadmin&quot;,&quot;t"
                        "o&quot;:&quot;115201811061611139ftrmgurx&quot;}</body><delay xmlns='urn:xmpp:del"
                        "ay' stamp='2019-04-09T01:59:35.416Z'/></message>";
long WebSocketReceiveLen7   = sizeof(WebSocketReceive7) - 1;	 

 

char WebSocketReceive8[] = "<message xmlns='jabber:client' from='1197180723253749#center-test_admin@easemob."
                        "com' to='1197180723253749#center-test_115201811061611139ftrmgurx@easemob.com' ty"
                        "pe='chat' id='589685153928841256'><body>{&quot;bodies&quot;:[{&quot;msg&quot;:&q"
                        "uot;"
                        "\xe3\x80\x90\xe5\x85\xac\xe4\xbc\x97\xe5\x8f\xb7\xe6\x8a\xa5\xe8\xa1\xa8\xe3\x80\x91\xe5\xbe\xae\xe4\xbf\xa1\xe5\x85\xac\xe4\xbc\x97\xe5\x8f\xb7\xe8\xbf\x90\xe8\x90\xa5\xe6\x8a\xa5\xe8\xa1\xa8\xe5\xb7\xb2\xe6\x9b\xb4\xe6\x96\xb0\xef\xbc\x8c\xe8\xaf\xb7\xe6\x9f\xa5\xe7\x9c\x8b"
                        " 2019-04-10 10:00&quot;,&quot;type&quot;:&quot;txt&quot;}],&quot;ext&quot;:{&quo"
                        "t;msg&quot;:&quot;{\\&quot;msg\\&quot;:\\&quot;{\\\\\\&quot;action\\\\\\&quot;:\\"
                        "\\\\&quot;"
                        "\xe6\x9f\xa5\xe7\x9c\x8b\xe8\xaf\xa6\xe6\x83\x85"
                        "\\\\\\&quot;,\\\\\\&quot;appname\\\\\\&quot;:\\\\\\&quot;"
                        "\xe5\x85\xac\xe4\xbc\x97\xe5\x8f\xb7\xe6\x8a\xa5\xe8\xa1\xa8"
                        "\\\\\\&quot;,\\\\\\&quot;appurl\\\\\\&quot;:\\\\\\&quot;https://g.t.dacube.cn/WX"
                        "-SERVICE/ObjWeixinReport/redirect?type=all\\\\\\&quot;,\\\\\\&quot;content\\\\\\"
                        "&quot;:\\\\\\&quot;"
                        "\xe5\xbe\xae\xe4\xbf\xa1\xe5\x85\xac\xe4\xbc\x97\xe5\x8f\xb7\xe8\xbf\x90\xe8\x90\xa5\xe6\x8a\xa5\xe8\xa1\xa8\xe5\xb7\xb2\xe6\x9b\xb4\xe6\x96\xb0\xef\xbc\x8c\xe8\xaf\xb7\xe6\x9f\xa5\xe7\x9c\x8b"
                        " 2019-04-10 10:00\\\\\\&quot;,\\\\\\&quot;contentType\\\\\\&quot;:\\\\\\&quot;"
                        "\xe8\xb7\xb3\xe8\xbd\xac"
                        "\\\\\\&quot;,\\\\\\&quot;logo\\\\\\&quot;:\\\\\\&quot;https://oss.dacube.cn/mesg"
                        "-admin/0019f949-8567-4610-a9f0-7d536b853601/15.png\\\\\\&quot;,\\\\\\&quot;pcurl"
                        "\\\\\\&quot;:\\\\\\&quot;https://g.t.dacube.cn/WX-SERVICE/ObjWeixinReport/redire"
                        "ct?type=all\\\\\\&quot;}\\&quot;,\\&quot;type\\&quot;:\\&quot;app\\&quot;}&quot;"
                        ",&quot;type&quot;:&quot;app&quot;},&quot;from&quot;:&quot;appadmin&quot;,&quot;t"
                        "o&quot;:&quot;115201811061611139ftrmgurx&quot;}</body><delay xmlns='urn:xmpp:del"
                        "ay' stamp='2019-04-10T01:59:33.965Z'/></message>";
long WebSocketReceiveLen8   = sizeof(WebSocketReceive8) - 1;	 


# 10 "globals.h" 2



 
 


# 3 "e:\\test\\01\262\342\312\324\\\\combined_01.c" 2

# 1 "vuser_init.c" 1
 







vuser_init()
{

	return 0;
}
# 4 "e:\\test\\01\262\342\312\324\\\\combined_01.c" 2

# 1 "Action.c" 1
Action()
{

	web_add_cookie("sts=1; DOMAIN=lh.kehuduan.2345.com");

	web_add_cookie("lc2=57816; DOMAIN=lh.kehuduan.2345.com");

	web_add_cookie("wc=57816; DOMAIN=lh.kehuduan.2345.com");

	web_add_cookie("wc_n=%25u8D35%25u9633; DOMAIN=lh.kehuduan.2345.com");

	web_add_cookie("bdUid=CBDDA5B869569FDA6C263750ABE0; DOMAIN=lh.kehuduan.2345.com");

	web_add_cookie("Hm_lvt_6ab7a391c8d69b4f62b7c54b2d70919c=1554887639,1554887882; DOMAIN=lh.kehuduan.2345.com");

	web_add_cookie("lc=57816; DOMAIN=lh.kehuduan.2345.com");

	web_submit_data("index.php", 
		"Action=http://lh.kehuduan.2345.com/ie/active/index.php", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		"ITEMDATA", 
		"Name=postdata", "Value="
		"ThsDEUVYDVZAQm5RDVNdGg5MQVBcDg5eU0oNEkZbGhJFSwQXU0U8Rl1YXlZBD0ZKQVIeHhECEEFAXQgVOwkOXVBJAANTE1kRW0VFSFkaHU9DQE0AAFVQHVFXC05bUlgFBgtDSBRVAlpfSEVZEF5tS0FHE11BFQBXEAIAAAgSBBwXXwgcaVIMXkNdVEwGUW1QVUQ8VloSFV9TQQMFRlsVQkBcTUZQWBtsQFleShdWR0wWDRgQUA4QXUYaXBpGBQRDXk0OFGlTEVxEQlRKQQ8CFBZTBkFYFQpDbV8TCAAEQwoFFUMQV0IIUVJDbloRWkVLUUVBCAMcSRFXQA8SEENbSxddBBddRQxDbFNDVxRGV0oWDRdARgRJEVZdFQoQDhFvUkwIAFMTWVVSXUJdTxdGWUdcAVNBPgdBXU8VBBZDW1ZUVRIBSx1BX1JCRWcTWkJNRGgXW14ERwkCFEQNBRIVb0FQDAEUCxgRV1RCUxdaQmdWRQxFQAQXEQ"
		"gISkMABBJbQVYRO1FECldWEwsITxdGWUdcAVNBPgdBXU8VBBZDWwBIFUMKWUU8Q0FeXEgXFwheVVsQVx9DF1ZUTRUEOwIORVtNQ14GTE8RVV1QSwsXCEMWVAxfQw4LVlxMOREUQ1tWVFUSARoTBVpBVFdXG2pcSBYNF0BGBEkRQUEVFQEMPllQG1sQREQGHxFCSEsXUF9nXVI8RFYTFlpdVkRbRlJTHAUVUUgHBlIRHxNCQRBBV1VrWRMQCRUXRlcURBIdEhVVWGYPFGlHBkFAWF5WQQ8QCgMZUxwDT1QLAhpKQxcYEkRQVD4URhNZR0FEVBRBRktLQFIObUMROkVXShUICw9DChcLVkoGH1MdAgkBGh4ZEF5bRQBXbBQVVEBZAgRGWxoSWVgSEGlFCl5WEwsIHhkQX1VaBm1bAAlfEAIdQwANDW9DXBMXX14NEQkTABZSGwIWAAJVEB9DAEtXZxAEFhIIX1sbW0YHH1IdAx8FDVUXHhpY"
		"VhZcUAk6QEZZEgRGW1NNGRsNAVBFPEBaVVRnAVRAGg5MQVBBDhJAV0o5Fg0FFVgXA1BdBAFPEVpCbk4KRltaWFJBCEcTEFZPFEQPARY%2BRFRbQ15NEw9SQEVuSwtAVF5YUjxBRxgJVm1MDwwBEhVRWElDXgYdQV9SQkVnEEJbTFdfPEFHGAlWbUwPDAESFVFYSUNeBh1BQEdIXV1BDwNFGBUMQFoGDF1TVDkJCwwEQFReBEYMEwtHR0ELF0xCRU8aBVAGBk8GXF8XWVJdVFICFxVDFlNSDF5eVF9cPEVRS1VRBhAJGkdRU0sDPhAIDFUXA1BRAwVbCwQFBA9PF1pRR0MMQEo%2BCkNXSgcVDQ4PEg9CQwZEXhRAVkNuWw9aQV0WDUEQH0MWVkZnAgQCABRcQWYHBV9dBlcRCxMaTxdHSFNFAlZWQ18REEVKQwgAEkRqSQ4UQ0E8R1pcVBpZThBaRlgUQVYTOlBeVxUERltRHBdKBBBpVQ"
		"ZVUkRdTDxTU1FYUgcQCVFJEUdIARMFBQQSDwkcSBRdAkBHbkVRDlAQAgQbQVxcFTpDQFcLERBDW0sXWxMLQUIGQWxSXVcQUBACUlYPQVZNR1ddWxIOFj4TVUVYCBYUCwVSX0JUFEFGV0xrUwZUUhQJR21eBwgIBAUSD18ACEVUHh8RQ1ReFkZXZ1dYFlxHQ19IEFoUDhMSBEJqWg0LRVRBCQMdE1wMVkZXRmgRV0MADEEQAlZNRhIERGpdBAJXRA9HbFdQUQ9QVhoOB08QQBUER0dLOQMFE0MKBUQcSBRDBlBcXFxdDVFtSF1ZGltdQ19IEFwDBwUUDURqUAwBFAsYEVdUQkoKRUZRW1lBCBGE253ahcmH792Ir4YbTUZaUA1UWlUTAlEFBwpJG0FaWhIRXEBBOQ4UBBNRQVAOChQLGBFRQ15PEFBAZ1dbDEFWQ18REEVKQw0MBG9ZUBIQFAs4EdaPn9DemtSziN78gRE8SRFeWRUVOxEO"
		"QEBJPhBfXAYRCUoTWhFaRUtRRTxRXw4WVhACVhxIQw1RRk0%2BEF9cBhEJAR0aDVpGZ0RFDF9DFUcJSRoEEwsWElVHZgIIWUIGEQlXUFQQUE8UFkcKXEoIC2xEXRQSDQ4PEg8bUUoGH1MdAxMdGhFQVE1HUjxRXBQLRxACHUMGEw5HRlwTO1VdDEBWEwsIHkgeGkdSAkBQCTpWXF8PDwESQwpOGwUBUFAWX0duQl0CR1FQa1INVVoPABEIGgQADQUUHlZWDEYaExBWUkNSUDxQXF9dWQZtXwgWRxACPUMGAAhUQBcCC1sTPh8RQllNBVNeXWtDCl9WQ18DHhoTEgETPkNCUBUHXm4XWl5UEwJTSB4aR1IXbVcEA1JHVBJDXhpDXFRKFTtQUApfVlVuTApYVxoOB08QXwAWR21ICRERET5EXFQERgwBTxFdXkVnE0ddVURDQQhVAAlAVxREEwEHFENQZgILQ18XEQkBHRoQXV1Pa0QGRmwF"
		"AFVTTQoVOxEOQEBJQ15CQxZWTh0TTRNRU0xRaBddXA1HCUkaAxkNEhUSDwlNRlpQEEdsVF9MEUwQAhYVTxBfABZHbUwPDAFDWwAZGxIRVVIGQEBYR108U1NRWFIHbVAOEF1GGlxRGU1DRUVeEwVSVDxVQV5cZxBcX0hYXgVbVgU6RVdKFQgLD0MKU1gNF1NMTxFQXlxVDFttUVpRDBAJGkdQWlkIDwENPllRG1tGAwFSAAoAExRBVl1VREIXV0E%2BC1JfXURbRiUkY35tLjQbciwAY3gBdEEZEFxYWzxEVhMWWl1WRFtGWE8GGwlPVQ4HUQQRHRNdG1BtTlFFEFtcD0cJEAFIV0pRTwEND1NTFB1BWl1CRVkPWW1cVU4QEAlRSRFbVhAODwQFb11QEhBZQxoRCWpKGhNUQFlZFVkQHkwDQV1VSwgKEhVRWVUEFhYcTl1cHFVdBVRHVEAaAUBcFhZWQBUFCQECChAYFAcIV1ZOQERYRVsL"
		"UEEVVlIEW11BSB5UVAcGSRIWWUFaCQFFHAZdVxMdGhdcX10WDVIHBlVdCwUMU1IZTRoSRVgTBVsTWREeHEJQDEdGW0FDXkNGCAZYXlkTDwcJQR0YXw0FURwQRFpFUlAGRh9aUVAKXBNMSFVeWQFMFxYIRFZRBBcbVA1XER0TTApYVxoOBlYHB1ldBAQLURxIGkNAVEsACRQLQR4eQllXEUFRTUAKEkdaAg5fU00IAgxBTB1TVQADG0IUWkdSWV0QGFBdU14NEh5MA19TX0sSEwgVU11cEklTXwcRHxNFUQ5QEAIFAlYGC1lSCwoIG00fQxFRR1gMRgwTTh5VXVBfTkZFUUBUC1dATAdWVVEIQUlMB1xUXkwXQVgXUFtUQhUGW1YYXEMXQkBbShxRXQgVARNPRBtdAAdDUwYdUF8eGk8XRlFZUkEIAlRQBwoAXlFVURxtGRsKEV9VQQkREx0aD1RBTGtCEFdXPgFSS0tEW1VNQ1xaWgAIaU"
		"UKXlYTCwlWAAYADA9TAwNNR15TW0RbRlUiHXB9TCJ0HFUGHgYAFVoGEBQWWgJRbA0MQEYaXDpGVSIdcH1MInQcVQYeBgAVWgYQZRgVDl1dCBFcQGcVDgIVFlFHXD4IX0IXEQkTAQhTBQIJBAdTAgNRVQMCCFZRVFFRAAUJUVQGAVMDAgEBGk8XXUtrVQpGEVtTBx4aCRI7FwRCRlAOChQLQQIDHwEaTxdCSltUBkFAPgRGRlAJEw0VGBIPCE1GQ1AAbFZfUFoPUFYaDlECXkAESRFHVg8OCj4IVBcDQ1cPBFABER0TTRBQQGdaVg5XEVtH1JmYgdvGh8O1FxVDEUNYBxEJE3MPIXZ2fAYHVwoFJ1AECwkkUFYlJHZ0fCBSBHdadwRyE0VPF0JKW1MWUUc%2BDF1UV0RbH0MFVVNYFAhCbgFBXEZCXREXCExGQgYeEQgAbERdFBINDg8SDxtQVRgBTQIEBgcLTQEBDxYbQVtAPgNBXVU5CA"
		"oSFVFZVQQWFAsFUl9CVBRBWVNLQGgKXEAVBF9eZxIICQRDCgQMVFAOCVQHBwYdGg9UQUxrQAxAWD4RWl9dRFtVVFQEDQFWXAEITxFDUkJZBVBtUVpEF1NfDQBXEAIAAAgSBBwXSwQHWVwOVl1VbkgARlNeUWgWXFoOC2xRTRUVCww%2BRExJBEYMAU8RQFRDTgpWV2dQWw9tRQQXQFtXCENeQ1YeBxdRSgIEUhEfE0JdEUNbW1FoBkpWPhNWQEsPDgpDWxICF1NKBh9XBgITHRoQXVtdWFM8QUcAEUZBGlxSSEMSWFxcDQBpRwZBQFheVkEPEAsaBU0CHVJSCxAURBIQABNEQEk%2BCVlVBhEJAExF", "ENDITEM", 
		"LAST");

	web_add_cookie("sts=1; DOMAIN=name.ie.2345.com");

	web_add_cookie("lc2=57816; DOMAIN=name.ie.2345.com");

	web_add_cookie("wc=57816; DOMAIN=name.ie.2345.com");

	web_add_cookie("wc_n=%25u8D35%25u9633; DOMAIN=name.ie.2345.com");

	web_add_cookie("bdUid=CBDDA5B869569FDA6C263750ABE0; DOMAIN=name.ie.2345.com");

	web_add_cookie("Hm_lvt_6ab7a391c8d69b4f62b7c54b2d70919c=1554887639,1554887882; DOMAIN=name.ie.2345.com");

	web_add_cookie("lc=57816; DOMAIN=name.ie.2345.com");

	web_custom_request("query.php", 
		"URL=http://name.ie.2345.com/query.php", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		"Body=url=https://center.t.dacube.cn/", 
		"LAST");

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	web_custom_request("dmdt_data.php", 
		"URL=http://update.khd.2345.cc/dmdt/dmdt_data.php", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=data_version=1.0&client_data="
		"ME04QT8qGQRNFAslDlANblNpawInOiZeKUU0NEp2bWVpQ2pQOC8CCVwWSHJJUBtuGywvFzt3eAloHWAkVj04KWlVahF8bBkSUB5IckkwAA4yAQ1AZWF6HQwEdWgJFmZ1DyoOchUPWlV%252FQy5%252FKFAbbhUpJQQwJ2ARaANsYRZlZHd8QXkAY35OSxsJAyxJSBV8U2lrGyYjLwlwE3JzFHY6JihNchFkLQkDXxhcfVxDDn9TaWsBLCY0TjgTeHMJZHl3Z15%252FBGZ9TksbGAM8GFANbglzfVB5dyZZPEcnIxpudXdpQ2pAPygYDl1YUGpbQgd8QXV5QmVlcht6AXJhCGRnd3tfeANgflxXCUpaeEleFT4UNDwXJiEdXzNBJ3MCdmZ2el94A2B%252bTksbChgnDwdUOC4xMAIwd3gJDnxgfRokJSgvGitHDzgJFRtASHpFQhl9QnV%252bXGRmcRtoHWAhSjszMigbF1I5PQACG0"
		"BIakdQRz4eITwRIQohRCdBJyUabnVlNg==", 
		"LAST");

	web_submit_data("check_new_version.php", 
		"Action=http://update.ie.2345.com/check_new_version.php", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		"ITEMDATA", 
		"Name=data_version", "Value=1.0", "ENDITEM", 
		"Name=client_data", "Value="
		"IQE6P18tACUFRgRvfmUJGwhCR0tIZkNEWQgAcQ1aBVEeX0BqE1p9AH5VZkYSR31maxt4XQABExszNgwAS0QyH1AXUAxDUjtAHiRfIDoiD1MSb35lWkNdERwlDjMBBwBXXmMRSFQCWgYGP3wOLEk9R2xUElVhZiVMQlQWKAwdJFFOSwkIdw9dF00MDBwzRgQ5bzgAJFQZVXRqcRcbFkNPTEphUVhLW18sTQ9BCFoAAikBUG8AflVmRhNHfXR3CRsJQkdKSGZDRVgIAHENWgVRHl9AagFGb1QrAzcDTwMSJjVWXEsXBVhCdEFHXQ11OU0GWhNLHTgObiZ2An1RYzNbByErNVxZFhcPH0NvXUJHCB5wBVwHVhVNXHhHDytROwkiKUoaKGZ9G86G3J%2FH17D4yICng2MRSF0AXTAFO0BIdxJ%2FR3pUShooN2UDCd3M2ZLF%2bZX%2F1dGv8gZIGUNHAQMuQgYhbyoELwUBTW91ZRUJVBMEDi"
		"cwGhgMZ1YtXA0XWwxfUnYBBixDOjo%2FGFADLCgrZl9RHxJYQnRCQVwMCHkKXgFWDENSNkwJLFwRBDUGAU1vfXQPCRRQGhsROCwREV1vN1gYF1sMVl5sDVpjAXZTZEEBW28pJlBFZwQSCFpsUU1HDhJtHwdQDHEcGSBGSHcSdlVlQQFbbys0ZklRBgRYQnRFQEsUEi5ONVcURwMUBU0fIFIrF3RMAUZ6c3EKCRRQGAknNRwaHV1INWIMWQBJTUp4E0hhEiEWCRtCHSI2GE9OSgEeFRZ0SVZYCBJtHwVGPkMGHjVRNTtVPBY%2FGU1Vd2Z3GwcaHQQlCDoSAA9XQixiA1FDFE1CeA9IIkMRFSQZRwIuMBhNUkgXVUBaZ1FYS1dDHk4PRxdHDBUFUwsuWxEINxxMBW9%2bZQkJFFAYCSclFgYfUVMkYhpUAkUwHTNNBT8SdEdmVA9VIjcYSl5RBhIlFTcAH0sCEnMIXBdNDAADBVUPPxJ0R2"
		"dGDUdvaGVKW10RHhsUCQURGxoKYwhaBFIXXlJ2AR89VC8RMwR8FjgwKBsRGkJVVlojAxAITFUzYh5MEUtNSngRWXkFCx0mGkwFKDZlFQlNBx4eWmxRNl56cwV5WAVVFlk2bxRTfHJ%2FVxIzZTYIBXELbQE2QDlaelEBHFFUcx9QFyMZLTMeZ1h9BHZTEEMUTnwGdgtvfTQ2PzlgQTJQfAcCHxc%2F", "ENDITEM", 
		"LAST");

	lr_think_time(6);

	web_custom_request("index.php_2", 
		"URL=http://c.ie.2345.com/wangpai/index.php", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/octet-stream", 
		"Referer=", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=stat_version=1.0&data="
		"SkQFFEpBDl1GWW4fFV5CV0BHFV86GRJMFF1GCEddRhBBFVxOFkIWR0pRBlACF1RdXhsIVlhXAwtAV1lUUWpwVG4SVUdJCBkDRh4ZHxVNXkZfURVfQ1ADDVPW2aOAqLKBntqO6ZPa3b2D%252bouBjo3ekLXRsu2E8bHe772Lju3QhdbU7v2Ego9QA4HagY2sjwDWi57R%252bemNjLBETEhJR1hdAFREXEMIFxwcH0FAEV5dFQgRd3UhJSMFe14HXQdTDHQgcFAlUw8GVgVUInchBxtKHkgWQhYEEFldRAtGB1UEAV0ARBtNQhcLWQIGWw1TGw0QEUkbHkMXXlAJXw1WRw8QUQFXVVgIFxwcH0FACl5WWUVWVhVfQwpETRYLSx0SQkVKA1VSVBdWDl1LXAZdAgoFEE4YTEcUDFlWCEENVkcPEFcIU1VTG0hNS0YCRRRoTEJbVxYNRyNVcnoidVYCUQ0EIgRRX1B7BFN0ISV0IXYPBXQKcA"
		"AmQx9tREpKRlUQUEEXE1w9GhtAE1xGWRcMQ01HQQkbGBIWFR4LVQVRHAZaX0sOVV9UCgdHVlkFATt1CWhGABJHWBlREkRKSkZGDEFeARNcRFMKAVTX2fLQ%252bbfcmI7bvJ2K3e%252FXoNjU3YaMl7SBtO6D8rjS6LyL372BgIvSuqjRjN9QUdWA0tj%252FhFLRis7X%252bu6OhbxDTUgYFwlYXVIQCRYGRxxOSxsTRA1WRw8QJ3MiIiAMd1kGXVYDXXF9dgRwBgFWVlcAeCR0VBAYGUlGRBUDE1BRQwpGVgVVBAAGEE4YTEcLC1ZcCFgAEF8XEBkdHUQUV1wOXg0HF14VDAcDAA0GRxxOSxsTXw1dC0JXBhNcRAlNQREKS0xCE0AXBQEHARkGDg8fBlUIUQFXF09ISkQTD1BaD0ANBxdeFQoOBwAGFRhNGRJYFkE7RxBcVkYLRCRWe3YldFZTAVwBfwIFCgV1VFMmdX8ndCUEV3ML"
		"IAYlRBxkSE1LRgRAAURKFQhoTxUQEw4SA0RZEEYVRghLHhERFhcHUgRRTVYLWhYIAQoBBFdHBA1fUm4mAjpBAUJBWx5SG0hNS0YXXBBbXBUIEQYEUVSFjaiDrOTXyona7JuJ2uzerN%252FV3dfcxrHcsrrWp7aC6O7fhe7U04CAvamBitxXUtyM1dn%252F1QKAj5PRrrvbi%252bxDHxxCRFwLVgAXCEYARBtNQhcURQ0HF14VenV2d3UCJ1lUCQxQCCJ2JANxVgdVUVQJdCN1VEFISEwbQkFWRl4BQ1gSDFYAVwtUF09ISkQMCF9QD1kAQQ9GFUQbSRFBWQwODFldRAtGB1UEAV0ARBtNQhcUXg0MWxNSWxUIEVxDERFYHxYRRhMcVwYGUR8FCQwWClIJUVAHRkoVTBBGWl4KDxJZXUQLRgFcAAFWExtKGhtUEUA7FkANUxsNEHEDdSYlJgIJUglSdFACC1VzV1QlfHMgdSVVByIOfQ"
		"BxEUlqGE0ZEl4TVBdBRw9pHxMTFA0bD0NYEBdFFw0WGEVEQxlXUlYFFwVeCR1aBgtRAlRABwRTVW8mU2oQBh9HD0sHFRhNGRJND0UIV0cPEFYCUlOGhKSEreSGmtjfsZ3dj7nQ%252FN%252bHiY2Pk%252bLX4L3X97CB7%252b3WienV09HQ7KzcjIgCB9Lc1Yurj1HV3JiDqbqLje9EHBVOQ10LB1BGDRsGEE4YTEcUF1ldRAtGcSdxdiUEJF5XAABXCSIndFJ0CwEBBAEHJCMnABsbHR8QEEZXFlgCRFsbAFEBV1oERkoVTBBZXVEADwtUG1wTRk9JThARXw8JD1BRQwpGVgVVBAAGEE4YTEcUDFlWCEYBUEcPEAxFEhZbFhoWRxNNB1cDDBlRXFkYWlJbBQpUExkeHhdHClgJCBFQUUMKRlAMUQQLFU8fTxUEERJvTBNYABBfF3BTcyUiJQsFVQhSJQBTDgh1AwFwciMgJ3EPVHdd"
		"dlJ2EBlsGzscMw==", 
		"LAST");

	web_url("center.t.dacube.cn", 
		"URL=https://center.t.dacube.cn/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		"EXTRARES", 
		"Url=/static/css/chunk-0e60.337feb5b.css", "ENDITEM", 
		"Url=/static/js/chunk-0e60.8ecc4d8f.js", "ENDITEM", 
		"Url=/static/js/chunk-3ffe.8fad3843.js", "ENDITEM", 
		"Url=/static/css/chunk-3ffe.2447e82b.css", "ENDITEM", 
		"Url=/static/images/szrm_ios.png", "ENDITEM", 
		"Url=/static/images/szrm.png", "ENDITEM", 
		"Url=/static/images/szxmt.png", "ENDITEM", 
		"Url=/static/element/fonts/element-icons.woff", "Referer=https://center.t.dacube.cn/static/element/index.css", "ENDITEM", 
		"Url=/static/css/chunk-384f.261f94f7.css", "ENDITEM", 
		"Url=/static/js/chunk-384f.46719686.js", "ENDITEM", 
		"Url=https://g.t.dacube.cn/MESG-ADMIN/User/getCompanyByUsercode/e729e146-f249-42e1-960d-5c1f3f60bc9a", "ENDITEM", 
		"Url=/static/js/LvDl.7a12a23b.js", "ENDITEM", 
		"Url=/static/css/chunk-9389.68968e48.css", "ENDITEM", 
		"Url=/static/css/chunk-cb6e.02e78bc3.css", "ENDITEM", 
		"Url=/static/js/chunk-9389.66841a0d.js", "ENDITEM", 
		"Url=/static/css/chunk-5514.6b511dea.css", "ENDITEM", 
		"Url=/static/css/chunk-ba2f.bb88bb45.css", "ENDITEM", 
		"Url=/static/css/chunk-476c.a256f8bb.css", "ENDITEM", 
		"Url=/static/js/chunk-cb6e.4b5d2982.js", "ENDITEM", 
		"Url=/static/css/chunk-29db.5869ff77.css", "ENDITEM", 
		"Url=/static/js/chunk-ba2f.d7d32b4f.js", "ENDITEM", 
		"Url=/static/js/chunk-476c.2e7ea8c5.js", "ENDITEM", 
		"Url=/static/js/chunk-5514.31b5387f.js", "ENDITEM", 
		"Url=/static/js/chunk-29db.0bfd4310.js", "ENDITEM", 
		"Url=/static/static/images/loading.3acad18.png", "ENDITEM", 
		"Url=https://g.t.dacube.cn/MESG-ADMIN/User/getPccUserInfoByUserCode/e729e146-f249-42e1-960d-5c1f3f60bc9a/1", "ENDITEM", 
		"Url=https://g.t.dacube.cn/UP-PAPER-4J/portal/getLatestTopic?top=10", "ENDITEM", 
		"Url=https://g.t.dacube.cn/WX-SERVICE/WxGraphicAudit/dapingGraphicAudit", "ENDITEM", 
		"Url=https://g.t.dacube.cn/MESG-ADMIN/Application/getAppList/e729e146-f249-42e1-960d-5c1f3f60bc9a", "ENDITEM", 
		"Url=https://g.t.dacube.cn/UP-PAPER-4J/portal/taskDynamics/all?pageNo=1&pageSize=10", "ENDITEM", 
		"Url=/static/images/rank-one.png", "ENDITEM", 
		"Url=/static/images/rank.png", "ENDITEM", 
		"Url=/static/images/rank-two.png", "ENDITEM", 
		"Url=https://g.t.dacube.cn/UP-PAPER-4J/portal/topicStatistics", "ENDITEM", 
		"Url=https://g.t.dacube.cn/MESG-ADMIN/User/getWeChatData/e729e146-f249-42e1-960d-5c1f3f60bc9a", "ENDITEM", 
		"Url=https://g.t.dacube.cn/MESG-ADMIN/User/getPccFabricByUserCode/e729e146-f249-42e1-960d-5c1f3f60bc9a/1", "ENDITEM", 
		"Url=https://oss.dacube.cn/mesg-admin/34e0a7e9-4e3a-4afc-9c93-75b24cd55660/u=3695931498,2381510501&fm=26&gp=0.jpg", "ENDITEM", 
		"Url=https://oss.dacube.cn/mesg-admin/933ff374-95f0-4b1f-86a0-4e4f33bc08b2/reporterpc.png", "ENDITEM", 
		"Url=https://oss.dacube.cn/mesg-admin/95fb6799-99ae-42d0-9618-3f18eaea48c9/10.png", "ENDITEM", 
		"Url=https://oss.dacube.cn/mesg-admin/6984570f-e9c1-46cb-a85e-17e839ad0d81/4.png", "ENDITEM", 
		"Url=https://oss.dacube.cn/mesg-admin/d4c4c6ff-809c-4845-af7a-d848d1aba551/2.png", "ENDITEM", 
		"Url=https://oss.dacube.cn/mesg-admin/883cfdf2-b24c-409b-8276-086f161fce61/1.png", "ENDITEM", 
		"Url=https://pcctest.oss-cn-hangzhou.aliyuncs.com/1/e16cbb8e-8f5f-47a1-88af-1b0578b8a1ee/2%20(1).jpg", "ENDITEM", 
		"Url=https://pcctest.oss-cn-hangzhou.aliyuncs.com/1/adfb5edc-6f40-4a5f-8a9d-8252b55399bc/4.png", "ENDITEM", 
		"Url=https://center.dacube.cn/oss/null/c0ebf204-b5df-454d-beeb-a0d7587e0a02/pc.jpg", "ENDITEM", 
		"Url=https://pcctest.oss-cn-hangzhou.aliyuncs.com/media_resource_repository/video_cover/51094f1a-0afd-4821-b07d-fec54573d3d1.jpg", "ENDITEM", 
		"Url=https://pcctest.oss-cn-hangzhou.aliyuncs.com/media_resource_repository/1/a7aac738-6b66-490f-a989-6c83216ada9c/picture/pic1547107580735_4wEDw3x5N1.jpeg", "ENDITEM", 
		"Url=https://g.t.dacube.cn/MESG-ADMIN/User/getUsersByFabid/c434d614-4829-42e4-8b9f-37c6016d04a6", "ENDITEM", 
		"Url=https://g.t.dacube.cn/MESG-ADMIN/User/getMesgRecord/115201811061611139ftrmgurx/1", "ENDITEM", 
		"Url=https://pcctest.oss-cn-hangzhou.aliyuncs.com/media_resource_repository/1/64121462-f785-4f51-ad8d-f8c41e2ffb62/picture/piceditcITmlg_pic1543804405223_L5SSEHKYQY.png", "ENDITEM", 
		"Url=https://pcccompany.oss-cn-hangzhou.aliyuncs.com/Company_Admin/1/e7ab1fde-38a9-4cb4-889f-6895ba495cd4png", "ENDITEM", 
		"Url=https://pcccompany.oss-cn-hangzhou.aliyuncs.com/Company_Admin/1/ee14b1cb-6f0a-4544-aa0d-700c2f9feed3png", "ENDITEM", 
		"Url=https://pcctest.oss-cn-hangzhou.aliyuncs.com/media_resource_repository/1/64121462-f785-4f51-ad8d-f8c41e2ffb62/picture/pic1543566603279_pTo7HvOkeV.jpg", "ENDITEM", 
		"Url=https://pcctest.oss-cn-hangzhou.aliyuncs.com/media_resource_repository/1/62725d3f-9f2c-442c-af42-f07193a8bdcf/picture/picpic1543547664684_pOjDNcTEBt.png", "ENDITEM", 
		"Url=https://pcctest.oss-cn-hangzhou.aliyuncs.com/media_resource_repository/1/e729e146-f249-42e1-960d-5c1f3f60bc9a/picture/pic1543818783967_X5bvQ3fZnC.jpg", "ENDITEM", 
		"Url=https://pcctest.oss-cn-hangzhou.aliyuncs.com/media_resource_repository/1/62725d3f-9f2c-442c-af42-f07193a8bdcf/picture/editgv15zY_picpic1543280135888_TLGhuq0PTE.jpg", "ENDITEM", 
		"Url=https://pcctest.oss-cn-hangzhou.aliyuncs.com/media_resource_repository/1/e729e146-f249-42e1-960d-5c1f3f60bc9a/picture/pic1543462432394_gvJlDLTRLm.jpg", "ENDITEM", 
		"Url=https://pcctest.oss-cn-hangzhou.aliyuncs.com/media_resource_repository/1/62725d3f-9f2c-442c-af42-f07193a8bdcf/picture/pic6c9f0f8e-f95d-43d5-92f6-5235a47d9699::NWjckGxZvm_%E7%AB%A0%E5%AD%90%E6%80%A11.jpeg", "ENDITEM", 
		"Url=https://pcctest.oss-cn-hangzhou.aliyuncs.com/media_resource_repository/1/62725d3f-9f2c-442c-af42-f07193a8bdcf/picture/pic6f1adbb2-d98a-4686-882a-854d9f482bd9::MYvC08oKfx_2.jpg", "ENDITEM", 
		"Url=https://pcctest.oss-cn-hangzhou.aliyuncs.com/media_resource_repository/1/62725d3f-9f2c-442c-af42-f07193a8bdcf/picture/pic5cc5b200-ba86-4719-816f-428125527d78::RA5tIaU9d2_14.jpg", "ENDITEM", 
		"Url=https://pcctest.oss-cn-hangzhou.aliyuncs.com/media_resource_repository/1/a7aac738-6b66-490f-a989-6c83216ada9c/picture/picedit3CtTGZ_1542615387505_fC7JENMNrd.jpg", "ENDITEM", 
		"Url=https://pcctest.oss-cn-hangzhou.aliyuncs.com/media_resource_repository/1/a7aac738-6b66-490f-a989-6c83216ada9c/picture/piceditihBy4d_79cc9a1a-fc87-4589-b39a-d25e9b4cf151::0xpyEttVZB_D3B9C8DE-C8BE-4955-BF32-990BCC130F1F.jpeg", "ENDITEM", 
		"Url=https://pcctest.oss-cn-hangzhou.aliyuncs.com/media_resource_repository/video_cover/c5ab6af4-3bcd-4cf1-9b41-d919954f0c78.jpg", "ENDITEM", 
		"Url=https://pcctest.oss-cn-hangzhou.aliyuncs.com/media_resource_repository/video_cover/037fa3fd-8de0-4edf-a52e-2fd9cf2e3665.png", "ENDITEM", 
		"Url=https://pcctest.oss-cn-hangzhou.aliyuncs.com/media_resource_repository/video_cover/5f129f49-3443-42ae-a4c7-0764f4946b32.png", "ENDITEM", 
		"Url=https://pcctest.oss-cn-hangzhou.aliyuncs.com/media_resource_repository/video_cover/a6d6a9df-3dc6-467c-8b9f-00b455d5529b.png", "ENDITEM", 
		"Url=https://oss.dacube.cn/mesg-admin/0019f949-8567-4610-a9f0-7d536b853601/15.png", "ENDITEM", 
		"Url=https://oss.dacube.cn/mesg-admin/fb3d2cdd-5720-46dd-8f2b-bea4777663d4/timg-5.jpeg", "ENDITEM", 
		"Url=https://oss.dacube.cn/mesg-admin/6ee0affa-666e-42d4-9bcd-e4bcd98a31b4/timg%20(1).gif", "ENDITEM", 
		"Url=https://oss.dacube.cn/mesg-admin/a54dc087-362b-476b-9087-53713412f4f2/1.jpg", "ENDITEM", 
		"Url=https://pcctest.oss-cn-hangzhou.aliyuncs.com/media_resource_repository/video_cover/c41774c5-ffc0-46e9-b41e-66ca70436f49.png", "ENDITEM", 
		"Url=https://oss.dacube.cn/mesg-admin/4a54aeb5-19eb-4a73-a79f-f917b44b4773/20140318161849_iAQiX.thumb.700_0.jpeg", "ENDITEM", 
		"Url=/static/images/system_icon.png", "ENDITEM", 
		"Url=https://pcctest.oss-cn-hangzhou.aliyuncs.com/media_resource_repository/video_cover/fb3e2713-29dc-4d37-a749-75728aab181a.png", "ENDITEM", 
		"Url=/static/static/images/default.f322b1f.png", "ENDITEM", 
		"Url=https://pcctest.oss-cn-hangzhou.aliyuncs.com/1/fe3d2703-4df0-444d-b035-0e56f9101c32/2019-01-31-17:24:45", "ENDITEM", 
		"LAST");

	web_set_sockets_option("SSL_VERSION", "TLS1.1");

	web_custom_request("index.php_3", 
		"URL=http://t.ie.2345.com/wangpai_realtime/index.php", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=stat_version=1.0&product=2345Explorer&main_ver=9.6&version=9.6.0.18627&data="
		"SkQFDlRYDl5GWU5GdgkHAgMWDUdTUQQMI0kUXgpHVxYTSkQgCQVRAUZZFyYAe3R2dwYHUVlUdgxRCFVwVAd2IXcnIyAPBycJIFR2RhsbdgIDBAVHW0AJF1AfVBxUDQRWBkRKQ3gEUAFVQQ9WShUVUVxBWRFDWEsbInogejoFA0YLV0pDcn8yYztTAkYNCEoeEV1ZEQQFVUtECx8QNHJ2Pm5WV0MDblFtGU8XF0NLXlxUFg0eQyl6ajVuVApHD2lGHEsADVhSTEMTCkEHX1xEH1FRUAwPQh0UAF0FVUhGRQ1FBQ4EShgEXgBDXRBDSUQIHBtUAA8WVUtIRUpWBFZHBlRIBQ8WFzwcRih%252FN2RmBgIRDmxHTE9WVQdWSUESXEYHWQMVTFtQBlkKQxhJUVVWVR5HQAwVAVhcFRwBXAEVWhBFFhVbFhoCVQoXUBYZTRlWUldCBwRMU1dJEzlPGD8=", 
		"LAST");

	web_add_cookie("sts=1; DOMAIN=update.ie.2345.com");

	web_add_cookie("lc2=57816; DOMAIN=update.ie.2345.com");

	web_add_cookie("wc=57816; DOMAIN=update.ie.2345.com");

	web_add_cookie("wc_n=%25u8D35%25u9633; DOMAIN=update.ie.2345.com");

	web_add_cookie("bdUid=CBDDA5B869569FDA6C263750ABE0; DOMAIN=update.ie.2345.com");

	web_add_cookie("Hm_lvt_6ab7a391c8d69b4f62b7c54b2d70919c=1554887639,1554887882; DOMAIN=update.ie.2345.com");

	web_add_cookie("lc=57816; DOMAIN=update.ie.2345.com");

	web_custom_request("notification.php", 
		"URL=http://update.ie.2345.com/wangpai/extpop/notification.php", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		"EncType=", 
		"LAST");

	web_add_cookie("uUid=CBDDA5B869569FDA6C263750ABE0; DOMAIN=guess.union2.50bang.org");

	web_add_cookie("uidFlag=1; DOMAIN=guess.union2.50bang.org");

	web_add_cookie("xHTL=1; DOMAIN=guess.union2.50bang.org");

	web_add_cookie("xHTT=1554887466; DOMAIN=guess.union2.50bang.org");

	web_add_cookie("uUid=CBDDA5B869569FDA6C263750ABE0; DOMAIN=union2.50bang.org");

	web_add_cookie("uidFlag=1; DOMAIN=union2.50bang.org");

	web_submit_data("index.php_4", 
		"Action=http://ts.helper.2345.cc/tray/index.php", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"ITEMDATA", 
		"Name=postdata", "Value=SkQFCVhbD1UIPFwAFQMVBwMFBFxQQBwbAl0IbRNQQBdYCQhDAxdYHlJNBUoGAQEABBYbRwQaVWYQVBZBDFpcRgtEX08PG1EeVVsDVgAbGxBaWkQRAA5cZgJQHUFHDwJIEw0TCF0XWxJGTxcIVkpDbVpTWQoTB29YCl07XwBGQQVWAxU%2BTVwMVUZZBUgVVVZBR2tHChEXQGYSWAlXRw8CSBMKCQJYWT5TERFHAVlNaEZaWVJHW1MFDFIJXApVAgJIEwsDEkpUBlU7C1wXQ1ZFSxEOTBhNQEBLCVIBQRZqWwpXCURbGwVRAFRTBFQHCQcCAwQHVVFSAAlWAVQCVQUCVAFWVlAJBUMcRhBBBUVNQkJsQF4IBEAKCFMEUApdDQJVAUpEFFdcDl47ClFGDRsECwYHBUdNQEVMD1VGCEd3BSZyIiJTCQFZBiJWAl0GewYAd3FxJCQjBgsgCCAFJhdP", "ENDITEM", 
		"EXTRARES", 
		"Url=https://guess.union2.50bang.org/home.php/AdsApi_BrowserPlan-index?channel=cu1000178,cu1000176&count=4", "Referer=", "ENDITEM", 
		"Url=http://union2.50bang.org/web/ajax111?uId2=SPTNPQRLSX&r=&fBL=1920*1080&lO=chrome%3A%2F%2Flocal-website-guide%2F%3F39532%26f%3Df2_B0_nt%26p%3Dx3", "Referer=", "ENDITEM", 
		"LAST");

	web_add_cookie("sts=1; DOMAIN=tianqi.2345.com");

	web_add_cookie("lc2=57816; DOMAIN=tianqi.2345.com");

	web_add_cookie("wc=57816; DOMAIN=tianqi.2345.com");

	web_add_cookie("wc_n=%25u8D35%25u9633; DOMAIN=tianqi.2345.com");

	web_add_cookie("bdUid=CBDDA5B869569FDA6C263750ABE0; DOMAIN=tianqi.2345.com");

	web_add_cookie("Hm_lvt_6ab7a391c8d69b4f62b7c54b2d70919c=1554887639,1554887882; DOMAIN=tianqi.2345.com");

	web_add_cookie("lc=57816; DOMAIN=tianqi.2345.com");

	web_url("detect2009v2.php", 
		"URL=http://tianqi.2345.com/t/detect2009v2.php?ver=1.0", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		"EXTRARES", 
		"Url=https://center.t.dacube.cn/static/static/images/bg.fc4878b.jpg", "Referer=https://center.t.dacube.cn/static/css/chunk-3ffe.2447e82b.css", "ENDITEM", 
		"Url=https://center.t.dacube.cn/static/static/images/login_bg.41390b0.png", "Referer=https://center.t.dacube.cn/static/css/chunk-0e60.337feb5b.css", "ENDITEM", 
		"LAST");

	lr_think_time(6);

	web_url("update.php", 
		"URL=http://extension.ie.2345.com/service/update.php?os=win&arch=x86&nacl_arch=x86-64&prod=chromiumcrx&prodchannel=&prodversion=56.0.2924.90&lang=zh-CN&x=id%3Dhoppdmcmndhiklcbncdmgagimabilbeb%26v%3D1.0.0.3%26installsource%3Dnotfromwebstore%26uc", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		"LAST");

	lr_think_time(17);

	web_submit_data("index.php_5", 
		"Action=http://t.ie.2345.com/wangpai_realtime/index.php", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		"ITEMDATA", 
		"Name=stat_version", "Value=1.0", "ENDITEM", 
		"Name=product", "Value=2345Explorer", "ENDITEM", 
		"Name=main_ver", "Value=9.6", "ENDITEM", 
		"Name=version", "Value=9.6.0.18627", "ENDITEM", 
		"Name=data", "Value=SkQFDlRYDl5GWU5GdgkHAgMWDUdTUQQMI0kUXgpHVxYTSkQgCQVRAUZZFyYAe3R2dwYHUVlUdgxRCFVwVAd2IXcnIyAPBycJIFR2RhsbdgIDBAVHW0AJF1AfVBxUDQRWBkRKQ3gEUAFVQQ9WShUVW11AUgIEEBIDHRMpdlBqAlUTXD1RZEhNEhcXRw1ZXhUISBZxNTk6bwheE15pR1cFVFQEVwUOUwIEUQcBAAILD1QEB1ZcVgdVWFADUAZWDgBTHVZKURUEWQBGPhlGcWlvamwFDkdbORIOBwFRUFQGAVYBX1IHAQxVCQZRVFJSCgBQCgRVBgVQUgJUBkgCSQUeVQlWRDwVFydgPDtqVgcbDWkRBwdXAlIHAANUUQBVVldWAQQDV1oGVFQAUlQFBF0EUAsPBFdNUhwJSgBTA0doTxk7", "ENDITEM", 
		"LAST");

	lr_think_time(13);

	web_custom_request("login", 
		"URL=https://g.t.dacube.cn/MESG-ADMIN/User/login", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("login_2", 
		"URL=https://g.t.dacube.cn/MESG-ADMIN/User/login", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"phone\":\"18200000000\",\"userpwd\":\"1234567\"}", 
		"LAST");

	web_custom_request("e729e146-f249-42e1-960d-5c1f3f60bc9a", 
		"URL=https://g.t.dacube.cn/MESG-ADMIN/User/getCompanyByUsercode/e729e146-f249-42e1-960d-5c1f3f60bc9a", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("updateUser", 
		"URL=https://g.t.dacube.cn/MESG-ADMIN/User/updateUser", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("updateUser_2", 
		"URL=https://g.t.dacube.cn/MESG-ADMIN/User/updateUser", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"BodyBinary={\"usercode\":\"e729e146-f249-42e1-960d-5c1f3f60bc9a\",\"username\":\"\\xE7\\xAB\\xA0\\xE7\\xBA\\xA2\\xE6\\xA2\\x852\",\"login_name\":null,\"userpwd\":null,\"email\":\"123@qq.com\",\"ismen\":null,\"phone\":\"18200000000\",\"headimg\":\"https://oss.dacube.cn/mesg-admin/34e0a7e9-4e3a-4afc-9c93-75b24cd55660/u=3695931498,2381510501&fm=26&gp=0.jpg\",\"createdata\":1541494436000,\"updatedata\":1541494436000,\"isuse\":\"1\",\"birthday\":null,\"cooVersionVo\":null,\"token\":\""
		"b722ff2d-dfff-4aa5-8361-51af7c3ee5bc\",\"easemobname\":\"115201811061611139ftrmgurx\",\"compid\":\"1\",\"code\":null,\"summary\":null,\"portal\":null,\"userIsCompLinkman\":false,\"userIsGroupLinkman\":false}", 
		"LAST");

	web_custom_request("1", 
		"URL=https://g.t.dacube.cn/MESG-ADMIN/User/getPccUserInfoByUserCode/e729e146-f249-42e1-960d-5c1f3f60bc9a/1", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		"EXTRARES", 
		"Url=https://center.t.dacube.cn/static/static/images/centre_bg.5e646f7.png", "Referer=https://center.t.dacube.cn/static/css/chunk-5514.6b511dea.css", "ENDITEM", 
		"Url=https://center.t.dacube.cn/static/static/images/portal_header_bg.f935581.png", "Referer=https://center.t.dacube.cn/static/css/chunk-ba2f.bb88bb45.css", "ENDITEM", 
		"LAST");

	web_custom_request("e729e146-f249-42e1-960d-5c1f3f60bc9a_2", 
		"URL=https://g.t.dacube.cn/MESG-ADMIN/Application/getAppList/e729e146-f249-42e1-960d-5c1f3f60bc9a", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("dapingGraphicAudit", 
		"URL=https://g.t.dacube.cn/WX-SERVICE/WxGraphicAudit/dapingGraphicAudit", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("audit_data", 
		"URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/data_portal/audit_data", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		"LAST");

	lr_think_time(4);

	web_custom_request("getLatestTopic", 
		"URL=https://g.t.dacube.cn/UP-PAPER-4J/portal/getLatestTopic?top=10", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("all", 
		"URL=https://g.t.dacube.cn/UP-PAPER-4J/portal/taskDynamics/all?pageNo=1&pageSize=10", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("data_counter", 
		"URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/data_portal/data_counter", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("newer_article", 
		"URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/data_portal/newer_article", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("newer_material", 
		"URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/data_portal/newer_material", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("e729e146-f249-42e1-960d-5c1f3f60bc9a_3", 
		"URL=https://g.t.dacube.cn/MESG-ADMIN/User/getWeChatData/e729e146-f249-42e1-960d-5c1f3f60bc9a", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("topicStatistics", 
		"URL=https://g.t.dacube.cn/UP-PAPER-4J/portal/topicStatistics", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("e729e146-f249-42e1-960d-5c1f3f60bc9a_4", 
		"URL=https://g.t.dacube.cn/MESG-ADMIN/User/getCompanyByUsercode/e729e146-f249-42e1-960d-5c1f3f60bc9a", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("audit_data_2", 
		"URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/data_portal/audit_data", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"userId\":\"e729e146-f249-42e1-960d-5c1f3f60bc9a\",\"orgId\":\"1\",\"token\":\"\",\"seed\":\"\",\"params\":{}}", 
		"LAST");

	web_custom_request("data_counter_2", 
		"URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/data_portal/data_counter", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"userId\":\"e729e146-f249-42e1-960d-5c1f3f60bc9a\",\"orgId\":\"1\",\"token\":\"\",\"seed\":\"\",\"params\":{}}", 
		"LAST");

	web_custom_request("newer_article_2", 
		"URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/data_portal/newer_article", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t33.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"userId\":\"e729e146-f249-42e1-960d-5c1f3f60bc9a\",\"orgId\":\"1\",\"token\":\"\",\"seed\":\"\",\"params\":{}}", 
		"LAST");

	web_custom_request("1_2", 
		"URL=https://g.t.dacube.cn/MESG-ADMIN/User/getPccFabricByUserCode/e729e146-f249-42e1-960d-5c1f3f60bc9a/1", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t34.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("newer_material_2", 
		"URL=https://g.t.dacube.cn/MRP-SERVICE/mrp/v1/data_portal/newer_material", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t35.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"userId\":\"e729e146-f249-42e1-960d-5c1f3f60bc9a\",\"orgId\":\"1\",\"token\":\"\",\"seed\":\"\",\"params\":{}}", 
		"LAST");

	web_custom_request("c434d614-4829-42e4-8b9f-37c6016d04a6", 
		"URL=https://g.t.dacube.cn/MESG-ADMIN/User/getUsersByFabid/c434d614-4829-42e4-8b9f-37c6016d04a6", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t36.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("1_3", 
		"URL=https://g.t.dacube.cn/MESG-ADMIN/User/getMesgRecord/115201811061611139ftrmgurx/1", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t37.inf", 
		"Mode=HTML", 
		"EXTRARES", 
		"Url=http://outin-26ccd6c8b67411e8b42a00163e024c6a.oss-cn-shanghai.aliyuncs.com/e575f7de36544f748fd39913e5cdb462/snapshots/a5a768c6e521446896a53b80eab371b8-00001.jpg?Expires=1554891751&OSSAccessKeyId=LTAIxSaOfEzCnBOj&Signature=uYeHRsROKvLahP%2BlBC06fIB8E0M%3D", "Referer=", "ENDITEM", 
		"Url=http://outin-26ccd6c8b67411e8b42a00163e024c6a.oss-cn-shanghai.aliyuncs.com/68201f0323d14a49a5ef886e07685b8e/snapshots/1a124234d74544cda813ff46a2fd9112-00002.jpg?Expires=1554891751&OSSAccessKeyId=LTAIxSaOfEzCnBOj&Signature=%2FitgaLmyD3LpsYBEW7veD4TxkJ4%3D", "Referer=", "ENDITEM", 
		"Url=http://outin-26ccd6c8b67411e8b42a00163e024c6a.oss-cn-shanghai.aliyuncs.com/d2253df575a84dd5a491166e0c711a95/snapshots/f58e9913bb454fb799ae1840d9a45209-00001.jpg?Expires=1554891751&OSSAccessKeyId=LTAIxSaOfEzCnBOj&Signature=qoXoJYEZNaQjb%2FoLBMuGKC0DgZo%3D", "Referer=", "ENDITEM", 
		"Url=http://outin-26ccd6c8b67411e8b42a00163e024c6a.oss-cn-shanghai.aliyuncs.com/1b2150ffe6a24b95ac56ce2f0ac817be/snapshots/863f24fd6be947f9ae8f54d38c4d027a-00001.jpg?Expires=1554891751&OSSAccessKeyId=LTAIxSaOfEzCnBOj&Signature=GD9IVtQZ5g%2FpD8yMhbZeSND1kys%3D", "Referer=", "ENDITEM", 
		"Url=http://outin-26ccd6c8b67411e8b42a00163e024c6a.oss-cn-shanghai.aliyuncs.com/7e3a8510343d4746b1c488d191bb92df/snapshots/2fc6e1d696714024ade237c9c1584f02-00001.jpg?Expires=1554891751&OSSAccessKeyId=LTAIxSaOfEzCnBOj&Signature=8RxvpTwdd8PB7agf3FtLw0Akjsw%3D", "Referer=", "ENDITEM", 
		"Url=http://outin-26ccd6c8b67411e8b42a00163e024c6a.oss-cn-shanghai.aliyuncs.com/b483f9707ac74914be8520f64f9ce156/snapshots/549bb3fbe0514f9ea45f93af38440080-00001.jpg?Expires=1554891751&OSSAccessKeyId=LTAIxSaOfEzCnBOj&Signature=PVJab3tN2551x%2FqmqsxCC4zCXKA%3D", "Referer=", "ENDITEM", 
		"Url=http://outin-26ccd6c8b67411e8b42a00163e024c6a.oss-cn-shanghai.aliyuncs.com/f800fe804c8b4f2abaab4d70502b57ab/covers/479baad86636447fa25a58062fdedf15-00005.jpg?Expires=1554891751&OSSAccessKeyId=LTAIxSaOfEzCnBOj&Signature=Q2tVXBkOLFw%2FNRxL5T8M1%2BDe8Ak%3D", "Referer=", "ENDITEM", 
		"Url=http://outin-26ccd6c8b67411e8b42a00163e024c6a.oss-cn-shanghai.aliyuncs.com/1adc1ffb3dcb450291f84362a7c378f7/covers/ab588d799113417b98918ae1b2f8bf6a-00001.jpg?Expires=1554891751&OSSAccessKeyId=LTAIxSaOfEzCnBOj&Signature=9lOxoZqAgjZl8JIrjtWB0LBSo%2FE%3D", "Referer=", "ENDITEM", 
		"Url=http://outin-26ccd6c8b67411e8b42a00163e024c6a.oss-cn-shanghai.aliyuncs.com/353abdc1088b4d62be78288d3e543449/covers/2db623b7fe6a458887f9661a506eb74d-00001.jpg?Expires=1554891751&OSSAccessKeyId=LTAIxSaOfEzCnBOj&Signature=FJAZtoATKXXU5Z9YvXZLeU%2F1nkc%3D", "Referer=", "ENDITEM", 
		"Url=http://outin-26ccd6c8b67411e8b42a00163e024c6a.oss-cn-shanghai.aliyuncs.com/3b563bf8482444a5b080f1756c0c969e/covers/467f18c6c8664ae99b3fbe8405542edc-00001.jpg?Expires=1554891751&OSSAccessKeyId=LTAIxSaOfEzCnBOj&Signature=s6cVtKTAMfTl%2ByrNSxf9wLrN8M4%3D", "Referer=", "ENDITEM", 
		"Url=http://outin-26ccd6c8b67411e8b42a00163e024c6a.oss-cn-shanghai.aliyuncs.com/274590f3f6d543f3bb50d5ca2b06ad72/covers/8b84b2c8eaa3490cb04cf75b6f2afdd7-00001.jpg?Expires=1554891751&OSSAccessKeyId=LTAIxSaOfEzCnBOj&Signature=TW9B41mXHwrOVq39Xs475hCA%2Buo%3D", "Referer=", "ENDITEM", 
		"Url=http://outin-26ccd6c8b67411e8b42a00163e024c6a.oss-cn-shanghai.aliyuncs.com/25f462dea2f54a33aa3a48e845bffa82/covers/c48e5e65dd874e0c9ed1da5931ff3fe6-00001.jpg?Expires=1554891751&OSSAccessKeyId=LTAIxSaOfEzCnBOj&Signature=5tFsZOjmapEVZIFsDWBTdBkdM9w%3D", "Referer=", "ENDITEM", 
		"Url=http://outin-26ccd6c8b67411e8b42a00163e024c6a.oss-cn-shanghai.aliyuncs.com/477923d658f94bb69a6817ab03ad6d8c/covers/1c3cd88bedd942e183e2af72fd514289-00001.jpg?Expires=1554891751&OSSAccessKeyId=LTAIxSaOfEzCnBOj&Signature=f%2BWpmNeo2MCWGIkLEe63zQcsxVo%3D", "Referer=", "ENDITEM", 
		"LAST");

	web_custom_request("token", 
		"URL=https://a1.easemob.com/1197180723253749/center-test/token", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t38.inf", 
		"Mode=HTML", 
		"EncType=text/plain;charset=UTF-8", 
		"Body={\"grant_type\":\"password\",\"username\":\"115201811061611139ftrmgurx\",\"password\":\"e729e146-f249-42e1-960d-5c1f3f60bc9a\",\"timestamp\":1554888167811}", 
		"EXTRARES", 
		"Url=http://outin-26ccd6c8b67411e8b42a00163e024c6a.oss-cn-shanghai.aliyuncs.com/94f023de99604d979741ada3e4b0d011/covers/eb4e0e7140bb4db5b667340375419c4a-00001.jpg?Expires=1554891751&OSSAccessKeyId=LTAIxSaOfEzCnBOj&Signature=tQUz8tnaihqwHJkHpK7Dg2qv9XU%3D", "Referer=", "ENDITEM", 
		"Url=http://outin-26ccd6c8b67411e8b42a00163e024c6a.oss-cn-shanghai.aliyuncs.com/8d6d53ad916d43c4a95ec163543ab273/covers/2e8d86349d9f40e3a9add00b6fea17c2-00001.jpg?Expires=1554891751&OSSAccessKeyId=LTAIxSaOfEzCnBOj&Signature=BWDbG9XhIIc1EvsbGyXMBcUADSI%3D", "Referer=", "ENDITEM", 
		"Url=http://outin-26ccd6c8b67411e8b42a00163e024c6a.oss-cn-shanghai.aliyuncs.com/0760f81f75ae4756aea4ae5a546a8a36/covers/d4f62c86fb75455a8ef33c16808d9bf9-00001.jpg?Expires=1554891751&OSSAccessKeyId=LTAIxSaOfEzCnBOj&Signature=Ey8kwwWFX%2FV5d5C2rRdyKs1jfSA%3D", "Referer=", "ENDITEM", 
		"Url=http://outin-26ccd6c8b67411e8b42a00163e024c6a.oss-cn-shanghai.aliyuncs.com/84e69e95e67941699f62bbfc433447d8/covers/6f662eb414da4de886446a8aaf2947b3-00005.jpg?Expires=1554891751&OSSAccessKeyId=LTAIxSaOfEzCnBOj&Signature=hPd3cnZRIGG8Gn%2BPJ5CPEOly4fE%3D", "Referer=", "ENDITEM", 
		"Url=http://outin-26ccd6c8b67411e8b42a00163e024c6a.oss-cn-shanghai.aliyuncs.com/e6bc19409ad14194bb88201a3f0968e6/covers/580c65358d3d4d0c9956237c130c1431-00001.jpg?Expires=1554891751&OSSAccessKeyId=LTAIxSaOfEzCnBOj&Signature=YJMNhzjXsp1qfIaLMVXomYRCYwo%3D", "Referer=", "ENDITEM", 
		"LAST");

	web_websocket_connect("ID=0", 
		"URI=wss://im-api.easemob.com/ws/", 
		"Origin=https://center.t.dacube.cn", 
		"OnOpenCB=OnOpenCB0", 
		"OnMessageCB=OnMessageCB0", 
		"OnErrorCB=OnErrorCB0", 
		"OnCloseCB=OnCloseCB0", 
		"LAST");

	web_websocket_send("ID=0", 
		"Buffer=<open xmlns='urn:ietf:params:xml:ns:xmpp-framing' to='easemob.com' version='1.0'/>", 
		"IsBinary=0", 
		"LAST");

	 

	web_websocket_send("ID=0", 
		"Buffer=<auth xmlns='urn:ietf:params:xml:ns:xmpp-sasl' mechanism='PLAIN'>MTE5NzE4MDcyMzI1Mzc0OSNjZW50ZXItdGVzdF8xMTUyMDE4MTEwNjE2MTExMzlmdHJtZ3VyeEBlYXNlbW9iLmNvbQAxMTk3MTgwNzIzMjUzNzQ5I2NlbnRlci10ZXN0XzExNTIwMTgxMTA2MTYxMTEzOWZ0cm1ndXJ4ACR0JFlXTXRONndQd2x0eUVlbVRBU04xeUg1ajk5SFNRUERZOHhIb21pQXpwRzZ0YzhsV0Z2Y1E0YUVSNkl5X2lYTThCem43QXdNQUFBRnFCbzZsd1FCUEdnQUpVQ3Y5bjNfMjgzMGJmRzhWT0JjaDczWlVkZWc5akF3eC12eFhBai1pbHc=</auth>", 
		"IsBinary=0", 
		"LAST");

	 

	web_websocket_send("ID=0", 
		"Buffer=<open xmlns='urn:ietf:params:xml:ns:xmpp-framing' to='easemob.com' version='1.0'/>", 
		"IsBinary=0", 
		"LAST");

	 

	 

	web_websocket_send("ID=0", 
		"Buffer=<iq type='set' id='_bind_auth_2' xmlns='jabber:client'><bind xmlns='urn:ietf:params:xml:ns:xmpp-bind'><resource>webim</resource><os>webim</os><device_uuid>1554888504856</device_uuid><is_manual_login>true</is_manual_login></bind></iq>", 
		"IsBinary=0", 
		"LAST");

	 

	web_websocket_send("ID=0", 
		"Buffer=<iq type='set' id='_session_auth_2' xmlns='jabber:client'><session xmlns='urn:ietf:params:xml:ns:xmpp-session'/></iq>", 
		"IsBinary=0", 
		"LAST");

	 

	web_websocket_send("ID=0", 
		"Buffer=<iq from='1197180723253749#center-test_115201811061611139ftrmgurx@easemob.com/webim_1554888504856' to='easemob.com' type='result' xmlns='jabber:client' id='01c05340-8a8f-4155-bca3-c4cd4cb87152:sendIQ'><query xmlns='jabber:iq:version'><name>easemob</name><version>1.4.2</version><os>webim</os></query></iq>", 
		"IsBinary=0", 
		"LAST");

	web_websocket_send("ID=0", 
		"Buffer=<presence xmlns='jabber:client'/>", 
		"IsBinary=0", 
		"LAST");

	 

	 

	web_websocket_send("ID=0", 
		"Buffer=<message from='1197180723253749#center-test_115201811061611139ftrmgurx@easemob.com/webim_1554888504856' to='easemob.com' id='589314075037542392' xmlns='jabber:client'><received xmlns='urn:xmpp:receipts' id='589314075037542392'/></message>", 
		"IsBinary=0", 
		"LAST");

	web_websocket_send("ID=0", 
		"Buffer=<message from='1197180723253749#center-test_115201811061611139ftrmgurx@easemob.com/webim_1554888504856' to='easemob.com' id='589685153928841256' xmlns='jabber:client'><received xmlns='urn:xmpp:receipts' id='589685153928841256'/></message>", 
		"IsBinary=0", 
		"LAST");

	web_custom_request("saveUnread", 
		"URL=https://g.t.dacube.cn/MESG-ADMIN/User/saveUnread", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t40.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("saveUnread_2", 
		"URL=https://g.t.dacube.cn/MESG-ADMIN/User/saveUnread", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t41.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("saveUnread_3", 
		"URL=https://g.t.dacube.cn/MESG-ADMIN/User/saveUnread", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t42.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"BodyBinary=[{\"modlename\":\"\\xE5\\x85\\xAC\\xE4\\xBC\\x97\\xE5\\x8F\\xB7\\xE6\\x8A\\xA5\\xE8\\xA1\\xA8\",\"modleImg\":null,\"from_user\":\"appadmin\",\"headimg\":null,\"summary\":null,\"username\":null,\"usercode\":null,\"groupid\":\"\",\"groupname\":null,\"pccUserInfos\":null,\"isorg\":false,\"istop\":null,\"owner\":\"\",\"no_disturb\":false,\"type\":\"app\",\"mesg_type\":\"txt\",\"unread\":12,\"payload\":\"{\\\\\"type\\\\\":\\\\\"app\\\\\",\\\\\"msg\\\\\":\\\\\"{\\\\\\\\\\\\\""
		"action\\\\\\\\\\\\\":\\\\\\\\\\\\\"\\xE6\\x9F\\xA5\\xE7\\x9C\\x8B\\xE8\\xAF\\xA6\\xE6\\x83\\x85\\\\\\\\\\\\\",\\\\\\\\\\\\\"appname\\\\\\\\\\\\\":\\\\\\\\\\\\\"\\xE5\\x85\\xAC\\xE4\\xBC\\x97\\xE5\\x8F\\xB7\\xE6\\x8A\\xA5\\xE8\\xA1\\xA8\\\\\\\\\\\\\",\\\\\\\\\\\\\"appurl\\\\\\\\\\\\\":\\\\\\\\\\\\\"https://g.t.dacube.cn/WX-SERVICE/ObjWeixinReport/redirect?type=all\\\\\\\\\\\\\",\\\\\\\\\\\\\"content\\\\\\\\\\\\\":\\\\\\\\\\\\\""
		"\\xE5\\xBE\\xAE\\xE4\\xBF\\xA1\\xE5\\x85\\xAC\\xE4\\xBC\\x97\\xE5\\x8F\\xB7\\xE8\\xBF\\x90\\xE8\\x90\\xA5\\xE6\\x8A\\xA5\\xE8\\xA1\\xA8\\xE5\\xB7\\xB2\\xE6\\x9B\\xB4\\xE6\\x96\\xB0\\xEF\\xBC\\x8C\\xE8\\xAF\\xB7\\xE6\\x9F\\xA5\\xE7\\x9C\\x8B 2019-04-09 10:00\\\\\\\\\\\\\",\\\\\\\\\\\\\"contentType\\\\\\\\\\\\\":\\\\\\\\\\\\\"\\xE8\\xB7\\xB3\\xE8\\xBD\\xAC\\\\\\\\\\\\\",\\\\\\\\\\\\\"logo\\\\\\\\\\\\\":\\\\\\\\\\\\\"https://oss.dacube.cn/mesg-admin/0019f949-8567-4610-a9f0-7d536b853601/"
		"15.png\\\\\\\\\\\\\",\\\\\\\\\\\\\"pcurl\\\\\\\\\\\\\":\\\\\\\\\\\\\"https://g.t.dacube.cn/WX-SERVICE/ObjWeixinReport/redirect?type=all\\\\\\\\\\\\\"}\\\\\"}\",\"isclose\":null,\"timestamp\":1554888187000,\"easemobname\":null,\"targetuser\":\"appadmin\",\"usereasemobname\":\"115201811061611139ftrmgurx\",\"deletetime\":null,\"compid\":null,\"guid\":\"\\xE5\\x85\\xAC\\xE4\\xBC\\x97\\xE5\\x8F\\xB7\\xE6\\x8A\\xA5\\xE8\\xA1\\xA8app\"}]", 
		"LAST");

	web_custom_request("saveUnread_4", 
		"URL=https://g.t.dacube.cn/MESG-ADMIN/User/saveUnread", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t43.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"BodyBinary=[{\"modlename\":\"\\xE5\\x85\\xAC\\xE4\\xBC\\x97\\xE5\\x8F\\xB7\\xE6\\x8A\\xA5\\xE8\\xA1\\xA8\",\"modleImg\":null,\"from_user\":\"appadmin\",\"headimg\":null,\"summary\":null,\"username\":null,\"usercode\":null,\"groupid\":\"\",\"groupname\":null,\"pccUserInfos\":null,\"isorg\":false,\"istop\":null,\"owner\":\"\",\"no_disturb\":false,\"type\":\"app\",\"mesg_type\":\"txt\",\"unread\":13,\"payload\":\"{\\\\\"type\\\\\":\\\\\"app\\\\\",\\\\\"msg\\\\\":\\\\\"{\\\\\\\\\\\\\""
		"action\\\\\\\\\\\\\":\\\\\\\\\\\\\"\\xE6\\x9F\\xA5\\xE7\\x9C\\x8B\\xE8\\xAF\\xA6\\xE6\\x83\\x85\\\\\\\\\\\\\",\\\\\\\\\\\\\"appname\\\\\\\\\\\\\":\\\\\\\\\\\\\"\\xE5\\x85\\xAC\\xE4\\xBC\\x97\\xE5\\x8F\\xB7\\xE6\\x8A\\xA5\\xE8\\xA1\\xA8\\\\\\\\\\\\\",\\\\\\\\\\\\\"appurl\\\\\\\\\\\\\":\\\\\\\\\\\\\"https://g.t.dacube.cn/WX-SERVICE/ObjWeixinReport/redirect?type=all\\\\\\\\\\\\\",\\\\\\\\\\\\\"content\\\\\\\\\\\\\":\\\\\\\\\\\\\""
		"\\xE5\\xBE\\xAE\\xE4\\xBF\\xA1\\xE5\\x85\\xAC\\xE4\\xBC\\x97\\xE5\\x8F\\xB7\\xE8\\xBF\\x90\\xE8\\x90\\xA5\\xE6\\x8A\\xA5\\xE8\\xA1\\xA8\\xE5\\xB7\\xB2\\xE6\\x9B\\xB4\\xE6\\x96\\xB0\\xEF\\xBC\\x8C\\xE8\\xAF\\xB7\\xE6\\x9F\\xA5\\xE7\\x9C\\x8B 2019-04-10 10:00\\\\\\\\\\\\\",\\\\\\\\\\\\\"contentType\\\\\\\\\\\\\":\\\\\\\\\\\\\"\\xE8\\xB7\\xB3\\xE8\\xBD\\xAC\\\\\\\\\\\\\",\\\\\\\\\\\\\"logo\\\\\\\\\\\\\":\\\\\\\\\\\\\"https://oss.dacube.cn/mesg-admin/0019f949-8567-4610-a9f0-7d536b853601/"
		"15.png\\\\\\\\\\\\\",\\\\\\\\\\\\\"pcurl\\\\\\\\\\\\\":\\\\\\\\\\\\\"https://g.t.dacube.cn/WX-SERVICE/ObjWeixinReport/redirect?type=all\\\\\\\\\\\\\"}\\\\\"}\",\"isclose\":null,\"timestamp\":1554888187012,\"easemobname\":null,\"targetuser\":\"appadmin\",\"usereasemobname\":\"115201811061611139ftrmgurx\",\"deletetime\":null,\"compid\":null,\"guid\":\"\\xE5\\x85\\xAC\\xE4\\xBC\\x97\\xE5\\x8F\\xB7\\xE6\\x8A\\xA5\\xE8\\xA1\\xA8app\"}]", 
		"LAST");

	lr_think_time(15);

	web_custom_request("appLogin", 
		"URL=https://g.t.dacube.cn/MESG-ADMIN/Application/user/appLogin", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t44.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("appLogin_2", 
		"URL=https://g.t.dacube.cn/MESG-ADMIN/Application/user/appLogin", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://center.t.dacube.cn/", 
		"Snapshot=t45.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"appid\":\"d15dd6b7-8e50-4fd8-b8fe-03c99f1bf918\",\"loginType\":\"pc\",\"styleType\":\"\",\"usercode\":\"e729e146-f249-42e1-960d-5c1f3f60bc9a\",\"compid\":\"1\"}", 
		"LAST");

	web_url("gtx-admin.t.dacube.cn", 
		"URL=http://gtx-admin.t.dacube.cn/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t46.inf", 
		"Mode=HTML", 
		"EXTRARES", 
		"Url=https://g.t.dacube.cn/APP-MANAGE-SV-4J/manager/OrgUsers/userinfo", "ENDITEM", 
		"Url=/static/img/moren.jpg", "ENDITEM", 
		"Url=http://pcccenter.oss-cn-qingdao.aliyuncs.com/App_Manage_Sv_4j/images/3f54309c-21c4-4c77-abe0-1023ff98f8af.jpg", "ENDITEM", 
		"LAST");

	web_custom_request("query.php_2", 
		"URL=http://name.ie.2345.com/query.php", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t47.inf", 
		"Mode=HTML", 
		"Body=url=http://gtx-admin.t.dacube.cn/%23/home%3Ftoken%3Db722ff2d-dfff-4aa5-8361-51af7c3ee5bc", 
		"LAST");

	web_custom_request("userinfo", 
		"URL=https://g.t.dacube.cn/APP-MANAGE-SV-4J/manager/OrgUsers/userinfo", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=http://gtx-admin.t.dacube.cn/", 
		"Snapshot=t48.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("userTreePermission", 
		"URL=https://g.t.dacube.cn/APP-MANAGE-SV-4J/manager/OrgUsers/userTreePermission", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=http://gtx-admin.t.dacube.cn/", 
		"Snapshot=t49.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("userTreePermission_2", 
		"URL=https://g.t.dacube.cn/APP-MANAGE-SV-4J/manager/OrgUsers/userTreePermission", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://gtx-admin.t.dacube.cn/", 
		"Snapshot=t50.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"token\":\"b722ff2d-dfff-4aa5-8361-51af7c3ee5bc\",\"compid\":\"\",\"usercode\":\"\"}", 
		"LAST");

	web_custom_request("userTreePermission_3", 
		"URL=https://g.t.dacube.cn/APP-MANAGE-SV-4J/manager/OrgUsers/userTreePermission", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://gtx-admin.t.dacube.cn/", 
		"Snapshot=t51.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"token\":\"b722ff2d-dfff-4aa5-8361-51af7c3ee5bc\",\"compid\":\"1\",\"usercode\":\"e729e146-f249-42e1-960d-5c1f3f60bc9a\"}", 
		"LAST");

	web_custom_request("statistics", 
		"URL=https://g.t.dacube.cn/APP-MANAGE-SV-4J/manager/HomePage/statistics", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=http://gtx-admin.t.dacube.cn/", 
		"Snapshot=t52.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("pageTodayOperationLog", 
		"URL=https://g.t.dacube.cn/APP-MANAGE-SV-4J/manager/HomePage/pageTodayOperationLog", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=http://gtx-admin.t.dacube.cn/", 
		"Snapshot=t53.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("statistics_2", 
		"URL=https://g.t.dacube.cn/APP-MANAGE-SV-4J/manager/HomePage/statistics", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://gtx-admin.t.dacube.cn/", 
		"Snapshot=t54.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"token\":\"b722ff2d-dfff-4aa5-8361-51af7c3ee5bc\",\"compid\":\"1\",\"usercode\":\"e729e146-f249-42e1-960d-5c1f3f60bc9a\"}", 
		"LAST");

	web_custom_request("pageTodayOperationLog_2", 
		"URL=https://g.t.dacube.cn/APP-MANAGE-SV-4J/manager/HomePage/pageTodayOperationLog", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://gtx-admin.t.dacube.cn/", 
		"Snapshot=t55.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"pageNo\":1,\"pageSize\":10,\"token\":\"b722ff2d-dfff-4aa5-8361-51af7c3ee5bc\",\"compid\":\"1\",\"usercode\":\"e729e146-f249-42e1-960d-5c1f3f60bc9a\"}", 
		"LAST");

	lr_think_time(7);

	web_custom_request("page", 
		"URL=https://g.t.dacube.cn/APP-MANAGE-SV-4J/manager/Channel/page", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=http://gtx-admin.t.dacube.cn/", 
		"Snapshot=t56.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("listChannelType", 
		"URL=https://g.t.dacube.cn/APP-MANAGE-SV-4J/manager/Channel/listChannelType", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=http://gtx-admin.t.dacube.cn/", 
		"Snapshot=t57.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("listUsableParentChannel", 
		"URL=https://g.t.dacube.cn/APP-MANAGE-SV-4J/manager/Channel/listUsableParentChannel", 
		"Method=OPTIONS", 
		"Resource=0", 
		"Referer=http://gtx-admin.t.dacube.cn/", 
		"Snapshot=t58.inf", 
		"Mode=HTML", 
		"LAST");

	web_custom_request("page_2", 
		"URL=https://g.t.dacube.cn/APP-MANAGE-SV-4J/manager/Channel/page", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://gtx-admin.t.dacube.cn/", 
		"Snapshot=t59.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"pageNo\":1,\"pageSize\":10,\"channel_name\":\"\",\"channel_typeid\":\"\",\"state\":\"\",\"timeStart\":null,\"timeEnd\":null,\"parent_channelid\":\"\",\"token\":\"b722ff2d-dfff-4aa5-8361-51af7c3ee5bc\",\"compid\":\"1\",\"usercode\":\"e729e146-f249-42e1-960d-5c1f3f60bc9a\"}", 
		"LAST");

	web_custom_request("listChannelType_2", 
		"URL=https://g.t.dacube.cn/APP-MANAGE-SV-4J/manager/Channel/listChannelType", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://gtx-admin.t.dacube.cn/", 
		"Snapshot=t60.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"token\":\"b722ff2d-dfff-4aa5-8361-51af7c3ee5bc\",\"compid\":\"1\",\"usercode\":\"e729e146-f249-42e1-960d-5c1f3f60bc9a\"}", 
		"LAST");

	web_custom_request("listUsableParentChannel_2", 
		"URL=https://g.t.dacube.cn/APP-MANAGE-SV-4J/manager/Channel/listUsableParentChannel", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://gtx-admin.t.dacube.cn/", 
		"Snapshot=t61.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"token\":\"b722ff2d-dfff-4aa5-8361-51af7c3ee5bc\",\"compid\":\"1\",\"usercode\":\"e729e146-f249-42e1-960d-5c1f3f60bc9a\"}", 
		"LAST");

	 

	lr_think_time(23);

	web_submit_data("upload.php", 
		"Action=http://dump.2345.com/upload.php", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t62.inf", 
		"Mode=HTML", 
		"ITEMDATA", 
		"Name=action_type", "Value=login", "ENDITEM", 
		"Name=mac-address", "Value=4C-ED-FB-65-71-93", "ENDITEM", 
		"Name=process-type", "Value=browser_hung", "ENDITEM", 
		"LAST");

	return 0;
}
# 5 "e:\\test\\01\262\342\312\324\\\\combined_01.c" 2

# 1 "vuser_end.c" 1
vuser_end()
{
	return 0;
}
# 6 "e:\\test\\01\262\342\312\324\\\\combined_01.c" 2

