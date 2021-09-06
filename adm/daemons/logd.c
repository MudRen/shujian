/*
  `user_id` varchar(8) default NULL,
  `log_name` varchar(100) default NULL,
  `log_type` varchar(100) default NULL,
  `log_time` int(11) default NULL,
  `log_desc` varchar(200) default NULL,
  `other_id` varchar(200) default NULL,
*/

// Modified by mxzhao 2004/02/18

#include <mudlib.h>
#define DB(x) ""+save_variable(x)+""

void create()
{
	seteuid(getuid());
}

void log_file(string file, string text, mixed ob, mixed *obs, int db)
{
// Modified by mxzhao 2004/02/18
	int log_time = time();

	string user_id = "";
	string log_type = "/", log_name = file;
	string other_id = "";
	string log_desc = text;
	
	sscanf(log_name, "%s/%s", log_type, log_name);
	
	if (objectp(ob))
	{
		user_id = geteuid(ob);
	}
	else if (stringp(ob))
	{
		user_id = ob;
	}
	
	if (sizeof(obs))
	{
		foreach (mixed item in obs)
		{
			if (objectp(item))
			{
				other_id += "|"+geteuid(item)+"|";
			}
			else if (stringp(item))
			{
				other_id += "|"+item+"|";
			}
		}
	}
		
//        if (log_desc[<1] == '\n')
//        {
//                log_desc = log_desc[0..<2];
//        }
	//�����DB��Ǿͽ���DB
	if(db)	
	dbquery("INSERT DELAYED INTO log SET "
		"log_time=" DB(log_time) ","
		"log_name=" DB(log_name) ","
		"log_type=" DB(log_type) ","
		"user_id="  DB(user_id)  ","
		"other_id=" DB(other_id) ","
		"log_desc=" DB(log_desc) ","
		"Site=" DB(INTERMUD_MUD_NAME)); //����site by LinuX@SJ 2004/1/30
		
	file = LOG_DIR + file;
	assure_file(file);

//        if (text[<1] != '\n')
//        {
//                text += "\n";
//        }
	
	write_file(file, ctime(log_time) + " " + text);

	if (file_size(file) > 500000) 
	{
		mixed* lt = localtime(log_time);
		string ext = sprintf(".%04d%02d%02d%02d%02d%02d", lt[5], lt[4]+1, lt[3], lt[2], lt[1], lt[0]);
		rename(file, file + ext);
	}
/*
	int log_time = time();
	mixed mysql = db_connect("localhost","mud","root");

	if (intp(mysql)) {
		string user_id = "";
		string log_type = "/", log_name = file;
		string other_id = "";
		string log_desc = text;

		sscanf(log_name, "%s/%s", log_type, log_name);

		if (objectp(ob))
			user_id = geteuid(ob);
		else if (stringp(ob))
			user_id = ob;

		if (sizeof(obs))
			foreach (mixed item in obs)
				if (objectp(item))
					other_id += "|"+geteuid(item)+"|";
				else if (stringp(item))
					other_id += "|"+item+"|";

		if (log_desc[<1] == '\n')
			log_desc = log_desc[0..<2];
			                               
		db_exec(mysql, "INSERT DELAYED INTO log SET "
			"log_time=" DB(log_time) ","
			"log_name=" DB(log_name) ","
			"log_type=" DB(log_type) ","
			"user_id="  DB(user_id)  ","
			"other_id=" DB(other_id) ","
			"log_desc=" DB(log_desc) ","
			"Site=" DB(INTERMUD_MUD_NAME) //����site by LinuX@SJ 2004/1/30
		);
		db_close(mysql);
	}

	file = LOG_DIR + file;
	assure_file(file);
	if (text[<1] != '\n')
		text += "\n";
	write_file(file, ctime(log_time) + " " + text);
	if (file_size(file) > 500000) {
		mixed* lt = localtime(log_time);
		string ext = sprintf(".%04d%02d%02d%02d%02d%02d", lt[5], lt[4]+1, lt[3], lt[2], lt[1], lt[0]);

		rename(file, file + ext);
	}
*/
// End
}
