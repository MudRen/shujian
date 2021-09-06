//  By Jpei  Aug 1997
//  Add cleaner By Bbb
//  Change question format By Look
//  Modified By Numa 20040128 2:36 for Log channel info to db
//  ReModified By Numa 20040201 for Log channel info to db

// Modified by mxzhao 2004/02/18

inherit NPC;

#include <ansi.h>
#include <mudlib.h>
#include <database.h>
//#define WEB_DB_NAME "discuz"

#define FROMID 42

#define MAX_SIZE 1300
/*Õâ¸ö×îºÃ²»Òª¶¯*/

void failed();
void CheckDbstep();

//int debug_mode = 0;

// Added By Numa 2004-02-01


string LogChannelTime = "06:10:01";
//string LogChannelTime = "12:10:01";
int InsertLines = 9;
string LogChannelFileDir = "/log/channel/";
string ChannelColorBG = "#000000";
mapping ChannelColor = ([
        //"chat"  :       "#00FFFF",
        "chat"  :       "Cyan", //HIC
        //"party" :       "Green",//HIG
        "party" :       "#00FF00",//HIG
        //"rumor" :       "#FF00FF",//HIM
        "rumor" :       "Magenta",
        //"sj"    :       "#FFFFFF",
        "sj"    :       "White",
        //"sj"    :       "Black",//HIW
        "master"    :      "yellow",
]);
mapping MudColors = ([
	"[0;30m":	"Black",
	"[0;31m":	"Red",
	"[0;32m":	"Green",
	"[0;33m":	"Yellow",
	"[0;34m":	"Blue",
	"[0;35m":	"Magenta",
	"[0;36m":	"Cyan",
	"[0;37m":	"White",
	"[1;31m":	"Red",
	//"[1;32m":	"Green",
	"[1;32m":	"#00FF00",
	"[1;33m":	"Yellow",
	"[1;34m":	"Blue",
	"[1;35m":	"Magenta",
	//"[1;35m":	"#FF00FF",
	"[1;36m":	"Cyan",
	//"[1;36m":	"Blue",
	//"[1;36m":	"#00FFFF",
	//"[1;37m":	"#FFFFFF",
	"[1;37m":	"Black",
	"[41;1m":	"Red",
	"[42;1m":	"Green",
	"[43;1m":	"Yellow",
	"[44;1m":	"Blue",
	"[45;1m":	"Magenta",
	"[46;1m":	"Cyan",
	"[47;1m":	"White",
	"[40m":	"Black",
	"[41m":	"Red",
	"[42m":	"Green",
	"[43m":	"Yellow",
	"[44m":	"Blue",
	"[45m":	"Magenta",
	"[46m":	"Cyan",
        "^[[47m":       "White"
]);

string ChannelCatMain = "6";
mapping ChannelCatIn = ([
        "chat"  :       "52",
        "party" :       "53",
        "rumor" :       "54",
        "sj"    :         "55",
        "master"    :  "56"
]);
string TimeDate(int t);
string TimeHMS(int t);
int InsertDB(string date);
void Check_Log_Channel_CallOut();
string get_data(string name,int part);

void create()
{
        int t = time();
        seteuid(ROOT_UID);
        set_name("Î×Ê¦ÔçÉÏºÃ", ({ "jiqiren faguan", "jiqiren", "faguan", "robot judge", "robot", "judge" }));
        set("shen_type", 0);

        set("gender", "»úÆ÷");
        set("age", 20);
        set("long", "ÕâÊÇÒ»¸ö×¨ÃÅÉóÅÐ»úÆ÷ÈËµÄ·¨¹Ù¡£\n");
        set_skill("dodge", 1000);
        set("max_qi", 10000);
        set("qi", 10000);
        set("max_jing", 10000);
        set("jing", 10000);

        set("combat_exp", 5000000);
        set("attitude", "friendly");
        set("env/invisibility",10);
        set("inquiry", ([
                "name": "Äã»¹ÓÐÕâÏÐ¹¦·ò°¡£¿",
                "rumors": "ÌýËµÄãÊÇ¸ö»úÆ÷ÈË£¬ºÙºÙ£¬ÎÒÕâ¹Ø¿ÉÊÇÌúÃæÎÞÇéÑ½¡£",                
        ]) );
        
        set("no_clean_up",1);

        setup();
        CHANNEL_D->register_relay_channel("chat");
        CHANNEL_D->register_relay_channel("rumor");
        CHANNEL_D->register_relay_channel("party");             
        CHANNEL_D->register_relay_channel("sj");

	set("log_channel_file", TimeDate(t));
	Check_Log_Channel_CallOut();
}

void init()
{        
        add_action("do_test","test");        
}

// Added By Numa 2004-02-01 for Delay Log Channel
void Check_Log_Channel_CallOut()
{
        int t = time();
        string tmp;
        /*
        if(!query("next_day")
        && query("log_channel_file")!=TimeDate(t) )
        {
        	int i;
        	string* chs = keys(ChannelColor);
        	set("next_day",1);
        	for(i=0;i<sizeof(chs);i++)
        	write_file(LogChannelFileDir+chs[i]+"."+query("log_channel_file"),
               	sprintf(HIY"ÒÔÏÂÎª%s\n",
                       	 TimeDate(t)));
        }*/
      /*  
        if (TimeHMS(t) != LogChannelTime) {
                call_out("Check_Log_Channel_CallOut", 1, this_object());
        }
        else {
                //tmp = TimeDate(t);
                tmp = copy(query("log_channel_file"));
                delete("next_day");
                InsertDB(tmp);
                set("log_channel_file", TimeDate(t+10));
                call_out("Check_Log_Channel_CallOut", 1000, this_object());
        }*/
        if (TimeDate(t) == query("log_channel_file") ) {
                call_out("Check_Log_Channel_CallOut", 1, this_object());
        }
        else {
                tmp = copy(query("log_channel_file"));
                InsertDB(tmp);
                set("log_channel_file", TimeDate(t+10));
                call_out("Check_Log_Channel_CallOut", 1000, this_object());
        }
}

int query_test()
{
	string tmp;
	int t = time();
	object me =this_player();
	
	if(getuid(me)!="linux" && getuid(me)!="ciwei" && getuid(me)!="mxzhao")
		return 0;

	write(TimeHMS(t)+"\n");
	
	tmp = TimeDate(t);
	set("log_channel_file", TimeDate(t+10));
	InsertDB(tmp);
	write("ok\n");
	return 1;
}

// Here Add By Numa 2004-01-28
int StrToInt(string s)
{
        int i;
        
        if (sscanf(s, "%s", i) == 1)
                return i;
        return 0;
}

string IntToStr(int i)
{
        return sprintf("%d", i);
}

string TimeDate(int t)
{
        string ts = ctime(t);
        string tm;
       // int tt;
        tm = ts[11..18];
        ts = ts[20..23]+"Äê"+ts[4..6]+"ÔÂ"+ts[8..9]+"ÈÕ";
        
        ts = replace_string(ts, " 1", "01");
        ts = replace_string(ts, " 2", "02");
        ts = replace_string(ts, " 3", "03");
        ts = replace_string(ts, " 4", "04");
        ts = replace_string(ts, " 5", "05");
        ts = replace_string(ts, " 6", "06");
        ts = replace_string(ts, " 7", "07");
        ts = replace_string(ts, " 8", "08");
        ts = replace_string(ts, " 9", "09");
        ts = replace_string(ts, "Jan", "01");
        ts = replace_string(ts, "Feb", "02");
        ts = replace_string(ts, "Mar", "03");
        ts = replace_string(ts, "Apr", "04");
        ts = replace_string(ts, "May", "05");
        ts = replace_string(ts, "Jun", "06");
        ts = replace_string(ts, "Jul", "07");
        ts = replace_string(ts, "Aug", "08");
        ts = replace_string(ts, "Sep", "09");
        ts = replace_string(ts, "Oct", "10");
        ts = replace_string(ts, "Nov", "11");
        ts = replace_string(ts, "Dec", "12");
        
        sscanf(tm,"%d:%*d:%*d",t);
        if(t<12) ts +="ÕýÎçÇ°";
        if(t>=12) ts +="ÕýÎçºó";
                        
        return ts;
}

string TimeHMS(int t)
{
        string ts = ctime(t);
        ts = ts[11..18];
        return ts;
}

int CheckLogDbExecErr(int rows, string filename, int LineBegin, int LineEnd, string msg)
{
	if (intp(rows)) {
                log_file("channel/LOG", "File : "+filename+"("+LineBegin+"--"+LineEnd+") "+msg+" Successful!\n");
                return 1;
        }
        else {
                log_file("channel/LOG", "File : "+filename+"("+LineBegin+"--"+LineEnd+") "+msg+" failed.\n");
                return 0;
        }
}

string ReplaceMudColors(string str,string channel)
{
	int i;
	string *key;

	key = keys(MudColors);
	for (i=0;i<sizeof(key);i++){
                        str = replace_string(str, key[i], "[/color][color="+MudColors[key[i]]+"]");
                        }
        //"[color="+ChannelColor[channel]+"]"        
	return str;
}

nosave int newtread;
nosave int tid;
nosave int end_flag;

nosave int st_channel;
nosave int st_line;
nosave string st_data;
/*
int ExecuteDbInsert(string msg, string filename, int LineBegin, int LineEnd, string catMain, string catIn)
{
        string *dl, sql, execinfo;
        
        dl = explode(filename, ".");
        if (dl[0]=="sj")
        	dl[1] = CHINESE_MUD_NAME + dl[1] + "¡¾Êé½£¡¿ÆµµÀÁÄÌì¼ÇÂ¼";
        else if (dl[0]=="party")
        	dl[1] = CHINESE_MUD_NAME + dl[1] + "¡¾ÃÅÅÉ¡¿ÆµµÀÁÄÌì¼ÇÂ¼";
        else if (dl[0]=="chat")
        	dl[1] = CHINESE_MUD_NAME + dl[1] + "¡¾ÏÐÁÄ¡¿ÆµµÀÁÄÌì¼ÇÂ¼";
        else if (dl[0]=="rumor")
        	dl[1] = CHINESE_MUD_NAME + dl[1] + "¡¾Ò¥ÑÔ¡¿ÆµµÀÁÄÌì¼ÇÂ¼";
        else if (dl[0]=="master")
        	dl[1] = CHINESE_MUD_NAME + dl[1] + "¡¾¹ÜÀíÔ±²Ù×÷¼ÇÂ¼¡¿";

        //msg = "[bgcolor="+ChannelColorBG+"]"+"[color="+ChannelColor[dl[0]]+"]"+msg+"[/color][/bgcolor]";
        // »¹ÊÇÖ±½Óµ½PHP´¦Àí±È½Ï·½±ãÐ© 
        
        //ÆÁ±ÎÌØÊâ×Ö·û
        msg = replace_string(msg,"'","¡®");
        msg = replace_string(msg,"&","¡ª");
        msg = replace_string(msg,"?","£¿");
        //¼¯ÖÐµ½ÕâÀïÀ´´¦Àí LogÖÐ±£³Öansi×Ö·û
        msg = ReplaceMudColors(msg,dl[0]);
	msg = replace_string(msg,"[0m","");
	
        if(msg!="[/bgcolor]")
        {
        	//msg = "[color="+ChannelColor[dl[0]]+"]"+msg+"[/color]";
        	message("wizard",sprintf(HIW"st_channel:%d,st_line:%d\n"NOR,st_channel,st_line),users() );
        }
                
        if (!LineBegin && newtread ) {
        	sql= "PostTothreads INSERT INTO threads (fid, creditsrequire, icon, author, subject, dateline, lastpost, lastposter, topped, digest) VALUES ('"+FROMID+"', '0', '', 'system', '"+dl[1]+"', '"+time()+"', '"+time()+"', 'system', '0', '0' )";
               	execinfo = "Insert Title";	        
	        BBS_D->add_Bbs_Up_Map(WEB_DB_NAME,sql,this_object(),"back_tid");
	        call_out("failed",30);
        	return 1;        
        }
        end_flag=0;
        
	if(!LineBegin) 
	msg = "[bgcolor=#000000][color="+ChannelColor[dl[0]]+"]"+msg;
        sql = "INSERT INTO posts (fid, tid, aid, icon, author, subject, dateline, message, useip) VALUES ('"+FROMID+"', '"+tid+"', '0', '', 'system', '"+dl[1]+"', '"+time()+"', '"+msg+"', '"+MUD_ADDR+"')";
        if(LineBegin>0) sql = "UPDATE posts SET message=CONCAT(message,'"+msg+"') WHERE subject='"+dl[1]+"' AND tid='"+tid+"'";
        execinfo = "Insert Detail";
        //rows = db_exec(mysql, sql);
        BBS_D->add_Bbs_Up_Map(WEB_DB_NAME,sql,this_object(),"CheckDbstep");
        //BBS_D->add_Bbs_Up_Map(WEB_DB_NAME,sql,this_object(),"dddddd");
        call_out("failed",30);
        return 1;
    	//return CheckLogDbExecErr(rows, filename, LineBegin, LineEnd, execinfo);
}
*/

void back_tid(mixed ret)
{
	remove_call_out("failed");
	if(!ret || !sizeof(ret)) {
			failed();
			return;
		}
	tid = ret[0][0];
	newtread=0;
	st_line--;
	CheckDbstep();
}
/*     
int GetFileLines(string fn)
{
        string fs, *fl;
        
        fs = read_file(LogChannelFileDir+fn);
        fl = explode(fs, "\n");
        return sizeof(fl);
}
*/

//string fffff;

void failed()
{
	string msg;
	st_line--;
	if((msg = get_data(LogChannelFileDir+keys(ChannelColor)[st_channel]+"."+st_data,st_line)))
	{
		write_file("/u/ciwei/channelerror",msg);
	}
	log_file("channel/LOG", "File : "+keys(ChannelColor)[st_channel]+"."+st_data+" Insert Error ("+st_line+" Execute, ), file not deleted.\n");
	st_line+=2;//Ìø¹ýÈ¥
	CheckDbstep();
}

string get_data(string name,int part)
{
	string* parts;
	string data;
	
	part= part+1;//heheÔ­À´ÊÇÒÔ1¿ªÊ¼µÄ
	data = read_file(name);
	if(!data) return 0;
	do
	{
		if(sizeof(data)<MAX_SIZE)
		{
			if(!parts) parts=({data});
			else parts += ({data});
			data = "";
		}
		else
		{
			if(!parts) parts=({data[0..MAX_SIZE-1]});
			else parts += ({data[0..MAX_SIZE-1]});
			data = data[MAX_SIZE..<0];
		}
	}
	while (data!="");
	if(part > sizeof(parts)) return 0;	
	return parts[part-1];
}
/*
void CheckDbstep()
{
	string fn, *ChannelNames, msg;
	
	remove_call_out("failed");
	ChannelNames = keys(ChannelColor);
	if(st_channel>=sizeof(ChannelNames))
	{
		message("wizard","ËùÓÐÎÄ¼þ´«ËÍÍê±Ï\n",users() );
		return;//all in web db then stop 
	}
	fn = ChannelNames[st_channel]+"."+st_data;
	if(!(msg = get_data(LogChannelFileDir+fn,st_line)))
	//if(!(msg = read_file(LogChannelFileDir+fn, st_line*InsertLines, st_line*InsertLines+InsertLines-1)))
	{
		message("wizard","Ò»¸öÆµµÀOK\n",users() );
		if(!end_flag)
		{
			ExecuteDbInsert("[/color][/bgcolor]", fn, st_line*InsertLines, st_line*InsertLines+InsertLines-1,0,0);
			end_flag=1;
			return;
		}
		st_channel++;
		newtread=1;
		st_line=0;
		if (rm(LogChannelFileDir+fn))
			log_file("channel/LOG", "File : "+fn+" deleted.\n");
		else
			log_file("channel/LOG", "File : "+fn+" delete Failed.\n");
		CheckDbstep();
		return;
	}//this channel is send over
	
	ExecuteDbInsert(msg, fn, st_line*InsertLines, st_line*InsertLines+InsertLines-1, ChannelCatMain,ChannelCatIn[ChannelNames[st_channel]]);
	st_line++;
}

²âÊÔÓÃ
void dddddd()
{
	string msg;
	if(!(msg = get_data(fffff,st_line)))
	//if(!(msg = read_file(LogChannelFileDir+fn, st_line*InsertLines, st_line*InsertLines+InsertLines-1)))
	{
		message("wizard","Ò»¸öÆµµÀOK\n",users() );		
		return;
	}//this channel is send over
	
	ExecuteDbInsert(msg, "sj.2004Äê05ÔÂ23ÈÕÕýÎçºó", st_line*InsertLines, st_line*InsertLines+InsertLines-1, ChannelCatMain,0 );
	st_line++;
}

void dd(string file)
{
	fffff=file;
	st_line=0;
	dddddd();	
}
*/
int InsertDB(string date)
{
        log_file("channel/LOG","start to INsertDB when "+date);
        st_data=date;
        st_channel=0;
        st_line=0;
        newtread=1;
        end_flag=1;
        CheckDbstep();
}

void Log_Channel(object ob, string channel, string msg,int emote)
{
        string tmpname, tmp;
        
        /*if (wizardp(ob))
                tmpname = "Ä³ÈË";
        else
        */
	tmpname = ob->query("name")+"("+ob->query("id")+")";
	if(channel == "sj" && ob->query_id())
		tmpname = ob->query_name()+"("+ob->query_id()+")";
        if (channel == "chat")
                tmp = "ÏÐÁÄ";
        else if (channel == "sj")
                tmp = "Êé½£";
        else if (channel == "rumor") {
                if (uptime() >= ob->query_temp("rumor_show"))
                        tmpname = "Ä³ÈË";
                tmp = "Ò¥ÑÔ";
        }
        else
                tmp = ob->query("family/family_name");
	
	//msg = ReplaceMudColors(msg,channel);
	//msg = replace_string(msg,"[0m","");
       	write_file(LogChannelFileDir+channel+"."+query("log_channel_file"),
               	sprintf("¡¾%s¡¿%s (%s)\n",
                       	tmp, (emote)?(msg):(tmpname+":"+msg), TimeHMS(time())));        
}
// End       

void relay_channel(object ob, string channel, string msg,int emote)
{
        string who;
        if(!userp(ob)
        && channel=="rumor"
        &&(
        sscanf(msg,"%s´ø×Å%*sÔÚ%*sÒ»´ø³öÏÖ£¡",who)==3
        || sscanf(msg,"¾ÝËµ%sºÃÏó²ØÔÚ%*s¸½½ü£¡",who)==2
        ) ) return;
        ///»¹ÓÐÆäËûÐèÒªÆÁ±ÎLogµÄÐÅÏ¢.....                       
        msg = replace_string(msg,"]","");//fear by Ciwei@SJ
        Log_Channel(ob, channel, msg, emote);
        // Added By Numa 20040201 22:50
        // End
}
