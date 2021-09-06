/*

Groupd
Created	by augx@SJ 3/13/2002

Copyright 1997-2002 ShuJian MUD Wizard Group.
All rights reserved.

// Modified by mxzhao 2004/02/18
*/

inherit F_SAVE;
inherit F_DBASE;
#include <ansi.h>
#include <localtime.h>
#include <mudlib.h>
#include <group.h>
#include <database.h>

#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif

// ͬ������վ�����õ��ļ�
#define MIRROR_FILE		"/log/group.mirror"
// ͬ������վ�����ļ�
#define MIRROR_CHECK_FILE	"/log/group.mirror.tmp"
// ��������
#define JIAMI_CMD		"/cmds/common/jiami.c"
// ������״����ʱ��������λΪ��
#define GROUP_CHECK_TIME	60
// ս��˫�������ʵ����࣬Ϊ�ٷֱ�
#define WAR_POWER		200
// ��ս��ĵȴ�ʱ��
#define DECLARE_TIME		5
// ǿ�Ʒ���ս������Сʱ��������λΪ��
#define FORCE_WAR_LIMIT		86400
// ���Ա��
#define DEBUG_MODE		0


/////////////////////////////////////////////////////////////////////////
//                               create                                //
/////////////////////////////////////////////////////////////////////////
mapping group = ([ ]);				// ��Ҫ����İ�������
mapping group_temp = ([ ]);			// ��ʱ�԰������ݣ���Ҫ��ս������
mapping group_member = ([ ]);		// ���ɳ�Ա���ݣ�ҲҪ����
string *group_list = ({ });			// ���������б�
nosave string last_error = "";		// ���Ĵ���


void setup_group();
int query_member_power(object ob);
void sort_group();
int update_room(string file);
void check_user_group(object me);


void create()
{
	string str;
	
	set("channel_id", "���ɾ���");
	str = read_file( "/data/npc/group/group_list.o" );
	group_list = restore_variable( str );
	setup_group();
	call_out("group_check",1);
}

// ������Ĵ���
string get_last_error()
{
	return last_error;
}

// ���ô�����Ϣ������
protected varargs int error(string info,int code)
{
	if(info) last_error = info + "\n";
	if(code) return code; else return 0;
}

// �жϴ�վ���Ƿ���Ҫ����
int need_encrypt()
{
         return ( INTERMUD_MUD_NAME != "SJZiTan" );
}

// ����һ���ļ�
int encrypt_file(string file)
{
	if( need_encrypt() ) JIAMI_CMD->main(this_object(),file);
	return 1;
}

// дͬ���ļ�
int mirror_file(string file,string site,string type)
{
/*	if( !file || !type ) return 0;
	switch( type ) {
		case "update":
			write_file(MIRROR_FILE,"UPDATE "+site+" "+file+"\n");
			break;
		case "delete":
			write_file(MIRROR_FILE,"DELETE ALLA "+file+"\n");
			break;
		case "defile":
			write_file(MIRROR_FILE,"DEFILE ALLA "+file+"\n");
			break;
		case "cpback":
			write_file(MIRROR_FILE,"CPBACK ALLA "+file+"\n");
			break;
		default:
			return 0;
	}
*/
	return 1;
}

// ��һ���������ɫ������ɻ�����ʶ��ı�׼��ɫ��
string color_string(string s)
{
	s=replace_string(s,"$RED$",RED,0); s=replace_string(s,"$HIR$",HIR,0);
	s=replace_string(s,"$GRN$",GRN,0); s=replace_string(s,"$HIG$",HIG,0);
	s=replace_string(s,"$YEL$",YEL,0); s=replace_string(s,"$HIY$",HIY,0);
	s=replace_string(s,"$BLU$",BLU,0); s=replace_string(s,"$HIB$",HIB,0);
	s=replace_string(s,"$MAG$",MAG,0); s=replace_string(s,"$HIM$",HIM,0);
	s=replace_string(s,"$CYN$",CYN,0); s=replace_string(s,"$HIC$",HIC,0);
	s=replace_string(s,"$WHT$",WHT,0); s=replace_string(s,"$HIW$",HIW,0);
	s=replace_string(s,"$NOR$",NOR,0); s+=NOR;
	return s;
}

// ɾ��һ��Ŀ¼�����е��ļ���������ɾ����Ŀ¼
int rm_dir(string dir)
{
	mixed * file;
	int i;
	object ob;

	file = get_dir(dir, -1);
	i = sizeof(file);
	while (i--) {
		if( file[i][1] < 0 ) continue;
		ob = find_object(dir+file[i][0]);
		if(ob) destruct(ob);
		rm(dir+file[i][0]);
	}

	return 1;
}

/////////////////////////////////////////////////////////////////////////
//                            create group                             //
/////////////////////////////////////////////////////////////////////////
// �洢��������
int save_group(string gid)
{
	if( undefinedp(group[gid]) ) return 0;

	if(member_array(gid, group_list)==-1)	//��group_list��û��gid������ɵ�ʱ��
	{
		group_list += ({gid});
		write_file( "/data/npc/group/group_list.o", save_variable(group_list), 1 );
	}

	return write_file( GROUP_SAVE_DIR+gid+"/"+gid+__SAVE_EXTENSION__, save_variable(group[gid]), 1 );
	
}

// ȡ�ذ�������
int load_group(string gid)
{
	string str;

	if( !(str=read_file(GROUP_SAVE_DIR+gid+"/"+gid+__SAVE_EXTENSION__)) ) 
	//if( !(str=read_file("/data/npc/group/futou/futou.o")) )
	{
		printf("%s\n",str);
		return 0;
	}
	group[gid] = restore_variable( str );

	if( !(str=read_file(GROUP_SAVE_DIR+gid+"/"+gid+"_member"__SAVE_EXTENSION__)) ) return 0;
	group_member[gid] = restore_variable( str );

	group_temp[gid] = ([
			"war":		0,	// ս��״̬
			"target":	0,	// ս������
			"time":		0,	// ս����ʼʱ��
			"war_score":	0,	// ս��
			"league_power":	0,	// ͬ����ʵ��
			"friend_pre":	"",	// �����������Ķ���
			"friend_to":	"",	// ��ĳ���ɽ���
			"friend1":	"",	// ���˰��ɣ������5��
			"friend2":	"",	// ����4�����ɽ�ɵ�ͬ�ˣ����������ɿ�ս���˰��ɲ��ܾܾ�
			"friend3":	"",
			"friend4":	"",
			"friend5":	"",
			]);

	return 1;
}

nosave string resstr;
public void set_res(string str)
{
	if(!str) return;
	resstr = str;
}

// ɾ�����ɣ���ɾ�������õ�������Ŀ¼���ļ�
int delete_group(string gid)
{
//	mixed mysql;
	object * user = users();
	string gname,dir;
	object entry;
	int i,j;

	if( undefinedp(group[gid]) ) return error("û��������ɡ�");

// Modified by mxzhao 2004/02/18
	if (!dbquery("delete from mud_group where id='"+gid+"'"))
	{
		write("���ݿ�����ʧ�ܡ�\n");
		return 0;
	}
/*
	mysql = db_connect("localhost","mud","root");
	if( !intp(mysql) ) return 0;
	db_exec(mysql,"delete from " + INTERMUD_MUD_NAME + "_mud_group where id='"+gid+"'");
	db_close(mysql);
*/
// End

	// ���ڴ˰�����������˶��Ƶ����ڣ�û�г��ھ��ƶ���VOID_OB
	if( stringp(group[gid]["entry"]) && group[gid]["entry"]!="" )
		if( !(entry=find_object(group[gid]["entry"])) )
			entry = load_object(group[gid]["entry"]);
	if( !entry ) entry = load_object(VOID_OB);
	j = sizeof(user);

	for(i=0;i<j;i++) {
		if( user[i]->query("group/id") == gid ) {
			user[i]->delete("group");
			user[i]->delete_temp("title");
		}

		if( !environment(user[i]) ) continue;
		if( sscanf(base_name(environment(user[i])),GROUP_DIR+"%s/",dir)<1 || dir!=gid ) continue;
		user[i]->move(entry);
		tell_room(entry,user[i]->name()+"���˹�����\n",({ user[i] }));
		tell_object(user[i],"���߳���������\n");
	}

	// ɾ������ʹ�õ�Ŀ¼�����ļ���
	rm_dir(GROUP_DIR+gid+"/npc/");
	rm_dir(GROUP_DIR+gid+"/obj/");
	rm_dir(GROUP_DIR+gid+"/");
	rm_dir(GROUP_SAVE_DIR+gid+"/");

	rmdir(GROUP_DIR+gid+"/npc/");
	rmdir(GROUP_DIR+gid+"/obj/");
	rmdir(GROUP_DIR+gid+"/");
	rmdir(GROUP_SAVE_DIR+gid+"/");

	mirror_file(GROUP_DIR+gid+"/npc/","ALL","delete");
	mirror_file(GROUP_DIR+gid+"/","ALL","delete");
	mirror_file(GROUP_SAVE_DIR+gid+"/","ALL","delete");

	if( group[gid]["entry"] != "" ) {
		cp(group[gid]["entry"]+".origin",group[gid]["entry"]+".c");
		mirror_file(group[gid]["entry"],"ALL","cpback");
		update_room(group[gid]["entry"]+".c");
	}

	gname = group[gid]["name"];
	map_delete( group, gid );
	map_delete( group_temp, gid );
	map_delete( group_member, gid );
	//ɾ��group_list�еļ�¼
	if(member_array(gid, group_list)!=-1)	//group_list�д���gid
	{
		group_list -= ({gid});
		write_file( "/data/npc/group/group_list.o", save_variable(group_list), 1 );
	}
		
	CHANNEL_D->do_channel(this_object(),"rumor",HIM"��˵�������𽭺���"+gname+"��Ϊ"+resstr+"��"+HIM"��ɢ�ˡ�"NOR);
	sort_group();
	return 1;
}

// ���ɳ�Ա���ݴ���
int save_group_member(string gid)
{
	if( undefinedp(group[gid]) ) return 0;
	return write_file( GROUP_SAVE_DIR+gid+"/"+gid+"_member"+__SAVE_EXTENSION__, save_variable(group_member[gid]), 1 );
}

// �����ݿ�ʹ����ļ����ȡ�������ݣ�����ʼ��group����
protected void setup_group()
{
/*	mixed mysql;
	mixed *res;
	int i;

	// �����ݿ���õ����ܻ᲻ͬ������
// Modified by mxzhao 2004/02/18
	mysql = db_connect(DB_HOST, DB_NAME, DB_USER);
	DB_D->log_out("db_connect", mysql);
//	mysql = db_connect("localhost","mud","root");
// End
	if( !intp(mysql) ) return;
	if( db_exec(mysql,"select id,name,site,master,members,score,power from mud_group") < 1 ) {
		db_close(mysql);
		return;
	}
	group = ([ ]);
	group_temp = ([ ]);
	group_member = ([ ]);
	for(i=1; sizeof(res=db_fetch(mysql,i))>0; i++) {
		group[res[0]] = ([ "name": res[1], "site": res[2], ]);
		group[res[0]]["site_next"] = "δ֪";
		group[res[0]]["members"] = res[4];
		group[res[0]]["score"] = res[5];
		group[res[0]]["power"] = res[6];
		sscanf(res[3],"%s(%s)",group[res[0]]["master1_name"],group[res[0]]["master1"]);
		if( res[2] == INTERMUD_MUD_NAME ) load_group(res[0]);
		group[res[0]]["site"] = res[2];
	}

	db_close(mysql);
	sort_group();*/
	foreach(string onegroup in group_list)
	{
		load_group(onegroup);
	}
	sort_group();
	return;
}

// ��������
int create_group(object me,string gid,string gname,string title1,string title2,string title3,string title4)
{
	group[gid] = ([
			"name":		gname,			// ����������
			"site":		INTERMUD_MUD_NAME,	// Ŀǰվ��
			"site_next":	INTERMUD_MUD_NAME,	// ҪǨ�Ƶ�վ��
			"money":	0,			// �ƽ�
			"score":	1000,			// ����
			"power":	query_member_power(me),	// ʵ��
			"utime":	time(),			// ������¼ʱ�䣬��������һ���²���¼�����ɻᱻ�Զ���ɢ
			"members":	1,			// ������Ŀ
			"max_members":	to_int(me->query("combat_exp")/333333), // ��������Ŀ
			"master1":	me->query("id"),	// �����ȼ�������
			"master1_name":	me->query("name"),
			"master2":	"",
			"master3":	"",
			"master4":	"",
			"master5":	"",
			"title1":	title1,			// �����ȼ����ڵĳ�ν
			"title2":	title2,
			"title3":	title3,
			"title4":	title4,
			"entry":	"",			// ���ڣ���build��һ��roomʱ����
			"force_war":	0,			// ��һ�α�ǿ��ս����ʱ��
		]);

	group_member[gid] = ([ me->query("id") : me->name(), ]);

	if( !save_group(gid) ) return 0;
	if( !save_group_member(gid) ) return 0;
	if( !load_group(gid) ) return 0;

	sort_group();		// Ϊglist����
	check_user_group(me);	// ����title
	return 1;
}


/////////////////////////////////////////////////////////////////////////
//                              get group                              //
/////////////////////////////////////////////////////////////////////////
// ȡ���ڲ��������б�����1Ϊgroup_temp��2Ϊgroup_member������Ϊgroup
varargs mapping get_group(string gid,int mode)
{
	if( !gid ) return 0;
	switch ( mode ) {
		case 1:
			if( undefinedp(group_temp[gid]) ) return 0;
			return group_temp[gid];
		case 2:
			if( undefinedp(group_member[gid]) ) return 0;
			return group_member[gid];
		default:
			if( undefinedp(group[gid]) ) return 0;
			return group[gid];
	}
}

// ȡ�������İ�������
varargs mapping get_groups(int mode)
{
	switch ( mode ) {
		case 1:
			return group_temp;
		case 2:
			return group_member;
		default:
			return group;
	}
}

mapping * sorted_group = ({ });
// ȡ������İ��ɣ�����������
mapping * get_sort_group()
{
	return sorted_group;
}

// ���������
protected int do_sort_group(mapping g1,mapping g2)
{
	if( g1["score"] <  g2["score"] ) return 1;
	if( g1["score"] >  g2["score"] ) return -1;
	return g2["power"] - g1["power"];
}

// �������
protected void sort_group()
{
	string * sk;
	mapping * sv;
	int i;

	sorted_group = ({ });
	sorted_group = allocate( sizeof(group) );

	sk = keys(group);
	sv = values(group);
	for(i=0;i<sizeof(sk);i++)
		sorted_group[i] = ([ "id": sk[i], "score": sv[i]["score"], "power":sv[i]["power"] ]);

	sorted_group = sort_array(sorted_group,(: do_sort_group :));
}


/////////////////////////////////////////////////////////////////////////
//                         get group variables                         //
/////////////////////////////////////////////////////////////////////////
// ���ó���
int set_entry(string gid,string path)
{
// Modified by mxzhao 2004/02/18
	if( !gid || undefinedp(group[gid]) ) 
	{
		return error("û��������ɣ�");
	}

	group[gid]["entry"] = path;
	save_group(gid);

	if (dbquery("update mud_group set "
		"sroom='" + path + "' where id='" + gid + "'"))
	{
		return error("���ݿ�����ʧ�ܣ�");
	}

	return 1;
/*
	mixed mysql;

	if( !gid || undefinedp(group[gid]) ) return error("û��������ɣ�");
	group[gid]["entry"] = path;
	save_group(gid);

	mysql = db_connect("localhost","mud","root");
	if( !intp(mysql) ) return error("���ݿ�����ʧ�ܣ�");
	if( db_exec(mysql,"update " + INTERMUD_MUD_NAME + "_mud_group set sroom='"+path+"' where id='"+gid+"'") < 1 ) {
		db_close(mysql);
		return 0;
	}
	db_close(mysql);
	return 1;
*/
// End
}

// ��ȡ����
int get_entry(string path)
{
// Modified by mxzhao 2004/02/18
	mixed ret = dbquery("select id from mud_group where sroom='" + path + "'");
	if (!ret)
	{
		return error("���ݿ�����ʧ�ܣ�");
	}

	if (sizeof(ret)>0)
	{
		return error("�Ѿ�������վ�������ڴ˴����������ˡ�");
	}

	return 1;
/*
	mixed mysql;
	mixed * res;

	mysql = db_connect("localhost","mud","root");
	if( !intp(mysql) ) return error("���ݿ�����ʧ�ܣ�");

	if( db_exec(mysql,"select id from " + INTERMUD_MUD_NAME + "_mud_group where sroom='"+path+"'")<1
	 || sizeof(res=db_fetch(mysql,1))<1 ) {
		db_close(mysql);
		return 1;
	}

	db_close(mysql);
	return error("�Ѿ�������վ�������ڴ˴����������ˡ�");
*/
}

// ��ð������������id(����)���������name���򷵻ذ�������������(�ַ���)
varargs mixed get_group_master(string gid,int name)
{
	if( !gid || undefinedp(group[gid]) ) return error("û��������ɣ�");
	if( name == 1 ) return group[gid]["master1_name"];
	else if( name == 2 ) return group[gid]["master1_name"]+"("+group[gid]["master"]+")";
	return ({ group[gid]["master1"],group[gid]["master2"],group[gid]["master3"],group[gid]["master4"],group[gid]["master5"] });
}

// ���������������������online�������������������
varargs int query_master_count(string gid,int online)
{
	int i,j;
	if( !gid || undefinedp(group[gid]) ) return error("û��������ɣ�");
	for(i=1,j=0;i<=5;i++) {
		if( group[gid]["master"+i] == "" ) continue;
		if( online ) {
			if( objectp( find_player(group[gid]["master"+i]) ) ) j++;
		}
		else
			j++;
	}
	return j;
}

int query_master_online(string gid)
{
	int i,j;
	if( !gid || undefinedp(group[gid]) ) return error("û��������ɣ�");
	for(i=j=0;i<5;i++)
		if( group[gid]["master"+i] != "" ) j++;
	return j;
}

// �������죬0��ʾȡ������Ȩ�ޣ�1Ϊ����(1)��2Ϊ������(1)��3Ϊ����(3)
int set_group_master(string gid,string uid,int gclass)
{
	object ob;

	if( !gid || undefinedp(group[gid]) ) return error("û��������ɣ�");

	if( gclass == 1 ) {
		if( group[gid]["master1"] != "" ) return error("�˵ȼ��Ѿ��ﵽ�������ơ�");
		group[gid]["master1"] = uid;
		if( (ob=find_player(uid)) ) group[gid]["master1_name"] = ob->name();
	}
	else if( gclass == 2 ) {
		if( group[gid]["master2"] != "" ) return error("�˵ȼ��Ѿ��ﵽ�������ơ�");
		group[gid]["master2"] = uid;
	}
	else if( gclass == 3 ) {
		if( group[gid]["master3"] == "" ) group[gid]["master3"] = uid;
		else if( group[gid]["master4"] == "" ) group[gid]["master4"] = uid;
		else if( group[gid]["master5"] == "" ) group[gid]["master5"] = uid;
		else return error("�˵ȼ��Ѿ��ﵽ�������ơ�");
	}
	else if( gclass == 0 ) {
		if( group[gid]["master1"] == uid ) { group[gid]["master1"] = ""; group[gid]["master1_name"] = ""; }
		else if( group[gid]["master2"] == uid ) group[gid]["master2"] = "";
		else if( group[gid]["master3"] == uid ) group[gid]["master3"] = "";
		else if( group[gid]["master4"] == uid ) group[gid]["master4"] = "";
		else if( group[gid]["master5"] == uid ) group[gid]["master5"] = "";
	}

	save_group(gid);
	return 1;
}

// ���ð��ڣ�modeΪ1����ӣ�0��ɾ���˰���
varargs int set_group_member(string gid,string uid,int mode,string uname)
{
	if( !gid || undefinedp(group_member[gid]) ) return error("û��������ɣ�");
	if( mode )
		group_member[gid][uid] = uname;
	else
		map_delete(group_member[gid],uid);
	save_group_member(gid);
	return 1;
}

// ȡ�ð�����ĳ���ȼ��ĳ�ν
string get_member_class(string gid,int gclass)
{
	if( !gid || undefinedp(group[gid]) ) return (string)error("û��������ɣ�");
	if( gclass<1 || gclass>4 ) return (string)error("û������ȼ���");
	return group[gid]["title"+gclass];
}

// ȡ�ð����������ƣ�mode�����ñ�ʾ������
varargs string get_group_name(string gid,int mode)
{
	if( !gid || undefinedp(group[gid]) ) return "";
	if( mode )
		return "��"+group[gid]["name"]+"��";
	else
		return group[gid]["name"];
}

// ���ذ�����
int get_group_members(string gid)
{
	if( undefinedp(group[gid]) ) return 0;
	return group[gid]["members"];
}

// ���Ӱ�������
int add_group_members(string gid,int gmember)
{
	if( undefinedp(group[gid]) ) return 0;
	group[gid]["members"] += gmember;
	save_group(gid);
	return get_group_members(gid);
}

// ȡ�ð�������������ɰ���ʵ���Ͱ��ɹ�ģ���������賿����
int get_max_group_members(string gid)
{
	if( !gid || undefinedp(group[gid]) ) return error("û��������ɣ�");
	return group[gid]["max_members"];
}

// ȡ�ð��ɻƽ���
int query_money(string gid)
{
	if( !gid || undefinedp(group[gid]) ) return error("û��������ɣ�",-99999);
	return group[gid]["money"];
}

// ���ð��ɻƽ���
int add_money(string gid,int money)
{
	if( !gid || undefinedp(group[gid]) ) return error("û��������ɣ�",-99999);
	group[gid]["money"] += money;
	if( !save_group(gid) ) return error("����ʧ�ܣ�",-99998);
	return query_money(gid);
}

// ��ȡ��������
int query_score(string gid)
{
	if( !gid || undefinedp(group[gid]) ) return error("û��������ɣ�",-99999);
	return group[gid]["score"];
}

// ��������
int add_score(string gid,int score)
{
	if( !gid || undefinedp(group[gid]) ) return error("û��������ɣ�",-99999);
	group[gid]["score"] += score;
	if( !save_group(gid) ) return error("����ʧ�ܣ�",-99998);
	sort_group();
	return query_score(gid);
}

// �����ɱ�������ĿǰΪ�㶨ֵ
int query_max_group_guard(string gid)
{
	return 10;
}

// ����һ�����ڵ�ʵ��
int query_member_power(object ob)
{
	int lv = 0;
	if( !ob ) return 0;

	lv = MAX( lv , ob->query_skill("caikuang",1) );
	//lv = MAX( lv , ob->query_skill("datie",1) );
	lv = MAX( lv , ob->query_skill("duanzao",1) );
	lv = MAX( lv , ob->query_skill("nongsang",1) );
	//lv = MAX( lv , ob->query_skill("bianzhi",1) );
	lv = MAX( lv , ob->query_skill("zhizao",1) );
	//lv = MAX( lv , ob->query_skill("caiyao",1) );
	//lv = MAX( lv , ob->query_skill("tilian",1) );
	//lv = MAX( lv , ob->query_skill("liandan",1) );

	if( lv <= 200 )
		return ob->query("combat_exp") / 1000;
	else
		return (lv*lv/10*lv) /1000 /2;
}

// ��ȡһ�����ɵĵж԰���
string query_enemy(string gid)
{
	if( undefinedp(group_temp[gid]) ) return "";
	return group_temp[gid]["target"];
}

// �ж�һ�������Ƿ���ս����
int is_war(string gid)
{
	if( undefinedp(group_temp[gid]) ) return 0;
	if( group_temp[gid]["war"] < 5 ) return 0;
	return 1;
}


/////////////////////////////////////////////////////////////////////////
//                       get group temp variables                      //
/////////////////////////////////////////////////////////////////////////
// ��ȡս��
int query_war_score(string gid)
{
	if( !gid || undefinedp(group_temp[gid]) ) return error("û��������ɣ�",-99999);
	if( group_temp[gid]["war"] <= 3 ) return error("���ɲ�������ս��״̬��",-99999);
	return group_temp[gid]["war_score"];
}

// ����ս��
int add_war_score(string gid,int score)
{
	if( !gid || undefinedp(group_temp[gid]) ) return error("û��������ɣ�",-99999);
	if( group_temp[gid]["war"] <= 3 ) return error("���ɲ�������ս��״̬��",-99999);
	group_temp[gid]["war_score"] += score;
	return query_war_score(gid);
}


/////////////////////////////////////////////////////////////////////////
//                           league functions                          //
/////////////////////////////////////////////////////////////////////////
// ��ȡ�˰�������ͬ��
string query_league(string gid)
{
	if( !gid || undefinedp(group[gid]) ) return (string)error("û��������ɣ�");
	if( group_temp[gid]["friend_to"] == "" ) return gid;
	if( undefinedp(group[group_temp[gid]["friend_to"]]) ) return (string)error("���˵İ��ɲ����ڡ�");
	return group_temp[gid]["friend_to"];
}

// ��ȡһ��ͬ�˵ĲμӰ�����
int query_league_members(string gid)
{
	int i,j;
	if( !gid || undefinedp(group[gid]) ) return error("û��������ɣ�");
	for(i=j=1;i<6;i++)
		if( group_temp[gid]["friend"+i] != "" ) j++;
	return j;
}

// ��ȡһ��ͬ�˵���ʵ��
int query_league_power(string gid)
{
	int i,j;
	if( !gid || undefinedp(group[gid]) ) return error("û��������ɣ�");
	for(i=1,j=group[gid]["power"];i<6;i++)
		if( group_temp[gid]["friend"+i] != "" )
			j += group[group_temp[gid]["friend"+i]]["power"];
	return j;
}

// ���ˣ���������Ҫͬ��������ɷ���request����Ȼ��Է�����answer����renegeΪ���ͬ��
int do_friend(string mid,string tid,string type)
{
	int i;
	string eid;

	if( !mid || !tid || undefinedp(group_temp[mid]) || undefinedp(group_temp[tid]) ) return error("û��������ɣ�");
	eid = group_temp[mid]["target"];

	switch( type ) {
		case "request":
			if( group_temp[tid]["friend_to"] != "" ) return error(get_group_name(tid)+"�Ѿ���"+get_group_name(group_temp[tid]["friend_to"])+"���ͬ���ˡ�");
			if( group_temp[mid]["friend_pre"] != "" ) return error("�����Ѿ������İ���������������ˡ�");
			if( group_temp[mid]["war"] < 1 ) return error("���ǲ�����������״̬������Ҫ�ͱ�İ��ɽ��ˡ�");
			if( query_league_members(mid) >= 6 ) return error("���ǵ�ͬ�˰��������Ѿ��ﵽ���ޡ�");
			if( tid == eid ) return error("�͵��˽��ˣ�");
			if( tid == mid ) return error("���Լ����ˣ�");
			if( (query_league_power(mid)+group[tid]["power"]) > (query_league_power(eid)*WAR_POWER/100) )
				return error("���ǵ������Ѿ����ǿ�󣬺�������˽��ˣ�");

			group_temp[mid]["friend_pre"] = tid;
			return 1;

		case "answer":
			if( group_temp[mid]["friend_to"] != "" ) return error("�����Ѿ���"+get_group_name(group_temp[mid]["friend_to"])+"���ͬ���ˡ�");
			if( group_temp[tid]["friend_pre"] != mid ) return error(get_group_name(tid)+"��û����������ǰ��ɽ��ˡ�");
			if( group_temp[tid]["war"] < 1 ) return error(get_group_name(tid)+"������������״̬������Ҫ���ˡ�");
			if( tid == eid ) return error("�͵��˽��ˣ�");
			if( tid == mid ) return error("���Լ����ˣ�");
			for(i=1;i<6;i++) {
				if( group_temp[tid]["friend"+i] == "" ) {
					group_temp[tid]["friend"+i] = mid;
					group_temp[tid]["friend_pre"] = "";
					group_temp[tid]["league_power"] = query_league_power(tid);
					group_temp[mid]["friend_to"] = tid;
					return 1;
				}
			}
			return error(get_group_name(tid)+"��ͬ�˰��������Ѿ��ﵽ���ޡ�");

		case "renege":
			for(i=1;i<6;i++) {
				if( group_temp[mid]["friend"+i] != tid ) continue;
				group_temp[mid]["friend"+i] = "";
				group_temp[mid]["league_power"] = query_league_power(mid);
				break;
			}
			if( i>=6 && group_temp[mid]["friend_pre"]!=tid && group_temp[mid]["friend_to"]!=tid ) return error("���ǲ�û��Ҫ��"+get_group_name(tid)+"���ͬ�˰���");
			if( group_temp[mid]["friend_pre"] == tid ) group_temp[mid]["friend_pre"] = "";
			if( group_temp[mid]["friend_to"]  == tid ) group_temp[mid]["friend_to"]  = "";

			for(i=1;i<6;i++) {
				if( group_temp[tid]["friend"+i] != mid ) continue;
				group_temp[tid]["friend"+i] = "";
				group_temp[tid]["league_power"] = query_league_power(tid);
				break;
			}
			if( group_temp[tid]["friend_pre"] == mid ) group_temp[tid]["friend_pre"] = "";
			if( group_temp[tid]["friend_to"]  == mid ) group_temp[tid]["friend_to"]  = "";

			return 1;
		default:
			return error("����Ľ���ָ��뱨����ʦ��");
	}
}


/////////////////////////////////////////////////////////////////////////
//                      group message functions                        //
/////////////////////////////////////////////////////////////////////////
// tell����group
int tell_group(string gid,string msg)
{
	mixed * gmembers;
	int i,j;

	if( !gid || !msg ) return 0;
	gmembers = users();
	j = sizeof(gmembers);
	for(i=0;i<j;i++)
		if( gmembers[i]->query("group/id") == gid )
			tell_object(gmembers[i],msg);
}

// tell����˵�е�����
int tell_group_master(string gid,string msg,int lv)
{
	string * gmembers = get_group_master(gid);
	object master;
	int i,j;

	if( !gmembers || sizeof(gmembers)<5 ) return 0;
	if( lv == 1 ) j = 1;
	else if( lv == 2 ) j = 2;
	else j = 5;
	for(i=0;i<j;i++) {
		if( gmembers[i]=="" || !(master=find_player(gmembers[i])) ) continue;
		tell_object(master,msg);
	}
}


/////////////////////////////////////////////////////////////////////////
//                        group site functions                         //
/////////////////////////////////////////////////////////////////////////
// �жϰ���Ŀǰ�Ƿ��ڴ�վ�㱻����
int site_now(string gid)
{
	if( undefinedp(group[gid]) ) return error("û��������ɣ�");
	if( group[gid]["site"] != INTERMUD_MUD_NAME ) return error("Ŀǰ�ɲ���"+get_group_name(gid)+"��վ��Ϊ"+group[gid]["site"]+"��");
	return 1;
}

// �˰���Ŀǰ�Ƿ����
int exist_now(string gid)
{
	string str;
// Modified by mxzhao 2004/02/18
/*	mixed ret = dbquery("select name from mud_group where id='" + gid + "'");
	if (!ret)
	{
		return (undefinedp(group[gid])?0:1);
	}

	return sizeof(ret)?1:0;
*/
	if( !(str=read_file(GROUP_SAVE_DIR+gid+"/"+gid+__SAVE_EXTENSION__)) ) return 0;

	if( !(str=read_file(GROUP_SAVE_DIR+gid+"/"+gid+"_member"__SAVE_EXTENSION__)) ) return 0;
	
	return 1;

/*
	mixed mysql;
	mixed * res;

	mysql = db_connect("localhost","mud","root");
	if( !intp(mysql) ) return (undefinedp(group[gid])?0:1);

	if( db_exec(mysql,"select name from " + INTERMUD_MUD_NAME + "_mud_group where id='"+gid+"'")<1
	 || sizeof(res=db_fetch(mysql,1))<1 ) {
		db_close(mysql);
		return 0;
	}

	db_close(mysql);
	return 1;
*/
}

// ����Ǩ��վ��
int set_site_next(string gid,string site_next)
{
	int i;
	mapping * sv;

	if( undefinedp(group[gid]) ) return error("û��������ɣ�");

	//sv = values(mudlist);
	for(i=0;i<sizeof(sv);i++)
		if( sv[i]["id"]==site_next && sv[i]["ver"]=="2.0" ) break;
	if( i >= sizeof(sv) ) return error("û�����վ��");

	group[gid]["site_next"] = site_next;

	save_group(gid);
	return 1;
}


/////////////////////////////////////////////////////////////////////////
//                             create room                             //
/////////////////////////////////////////////////////////////////////////
// ��������
int create_room(string path,string cshort,string clong,string exits,string objects,string groupid,string groupname,int indoor,int gboard)
{
	string str;

	str  = "// automake group room , "+ctime(time())+"\ninherit ROOM;\n#include <ansi.h>\n";
	if( stringp(groupid) && strlen(groupid)>2 )
		str += "#include `/d/group/gate.h`\n"; // ���ɷ���
	else
		str += "#include `/d/group/entry.h`\n"; // ����
	str += "void create()\n{\n";
	str += "set(`short`,`"+cshort+"`);\n";
	str += "set(`long`,`"+clong+"`);\n";

	if( exits && strlen(exits)>2 )
		str += "set(`exits`,([\n"+exits+"\n]));\n";
	if( objects && strlen(objects)>2 )
		str += "set(`objects`,([\n"+objects+"\n]));\n";
	if( groupname ) {
		if( indoor )
			str += "set(`indoors`,`"+groupname+"`);\n";
		else
			str += "set(`outdoors`,`"+groupname+"`);\n";
	}

	if (gboard)
	{
		str += "set(`have_board`, 1);\n";
	}

	if( stringp(groupid) && strlen(groupid)>2 ) {
		str += "set(`group1`,`"+groupid+"`);\n";
		str += "set(`group2`,`"+groupname+"`);\n";
		str += "setup();\nsetup_var();\n";
	}
	else {
		str += "set(`group`,1);\n";
		str += "setup();\n";
	}

	if (gboard)
	{
		string bdir = GROUP_DIR + groupid + "/obj/";
		string bfile;
		
		mkdir(bdir);

		bfile = "group_" + groupid + "_b"; 

		if (file_size(bdir + bfile + ".c") == -1)
		{
			string bstr = "// " + bfile + ".c\n"
				"// Created by The Group System.\n"
				"// " + ctime(time()) + "\n\n"
				"inherit BULLETIN_BOARD;\n\n"
				"void create()\n"
				"{\n";
			bstr += "\tset_name(\"" + groupname + "���԰�\", ({ \"board\" }) );\n";
			bstr += "\tset(\"location\", \"" + path + "\");\n";
			bstr += "\tset(\"board_id\", \"" + bfile + "\");\n";
			bstr += "\tset(\"long\", \"����һ��Ϊ" + groupname + "���������԰塣\\n\" );\n\n";
			bstr += "\tsetup();\n\n";
			bstr += "\tset(\"capacity\", 60);\n";
			bstr += "}\n";

			if( !write_file(bdir + bfile + ".c", bstr, 1) )
			{
				return error("д�ļ�ʧ��");
			}
		}

		str += "`" + bdir + bfile + "`->foo();\n";
	}

	str += "}\n";

	str = replace_string(str,"`","\"");

	if( !write_file(path,str,1) ) return error("д�ļ�ʧ��");
	return 1;
}

// ��ȡ������һ��room��exits����
string get_room_exits(object room)
{
	string str,str2;
	int i;
	mixed * sv, * sk;

	str = "";
	if( !room ) return "";

	str2 = base_name(room);
	for(i=strlen(str2)-1;i>=0;i--) {
		if( str2[i] == '/' ) {
			str2 = str2[0..i];
			break;
		}
	}

	if( mapp( room->query("exits") ) ) {
		sv = values( room->query("exits") );
		sk = keys( room->query("exits") );
		for(i=0;i<sizeof(sk);i++)
			str += replace_string( "`"+sk[i]+"`:`"+sv[i]+"`," , "`"+str2 , "__DIR__`" );
	}

	return str;
}

// ��ȡ������һ��room��objects����
string get_room_objects(object room)
{
	string str,str2;
	int i;
	mixed * sv, * sk;

	str = "";
	if( !room ) return "";

	str2 = base_name(room);
	for(i=strlen(str2)-1;i>=0;i--) {
		if( str2[i] == '/' ) {
			str2 = str2[0..i];
			break;
		}
	}

	if( mapp( room->query("objects") ) ) {
		sv = values( room->query("objects") );
		sk = keys( room->query("objects") );
		for(i=0;i<sizeof(sk);i++)
			str += replace_string( "`"+sk[i]+"`:"+sv[i]+"," , "`"+str2 , "__DIR__`" );
	}

	return str;
}


/////////////////////////////////////////////////////////////////////////
//                       drop object in group                          //
/////////////////////////////////////////////////////////////////////////
// �����ļ�����room�����е���Ʒ�����ᶪʧ
int update_room(string file)
{
	object * inv , room;
	int i;
	int hp;

	if ( !(room=find_object(file)) ) return 0;

	// move user in this room to VOID_OB
	inv = all_inventory(room);
	i = sizeof(inv);
	while(i--)
		if( inv[i] && inv[i]->query("startroom")!=file[0..<3] ) inv[i]->move(VOID_OB, 1); else inv[i] = 0;

	// save room vars
	hp = room->query("hp");

	// delete this room
	if( file_size("/binaries"+file[0..<3]+".b") >0 )
		rm( "/binaries"+file[0..<3]+".b" );
	destruct(room);

	// move back the users
	if ( catch(call_other(file, "???")) ) return 0;
	room = find_object(file);
	if( (i=sizeof(inv)) && room ) {
		while(i--)
			if( inv[i] ) inv[i]->move(room, 1);
	}

	// restore room vars
	room->set("hp",hp);

	return 1;
}

// ���°�����Ʒ
int drop_object(object obj,object me,object room,string start_str,string finish_str)
{
	int delay;

	if( !obj || !me ) return 0;
	if( !room || !room->query("group1") || room->query("group1")!=me->query("group/id") ) {
		tell_object(me,obj->name()+"���ܷ������\n");
		return 0;
	}

	if (room->query_temp("drop_lock"))
	{
		tell_object(me, "�������ڷ�����Ʒ�����Եȡ�\n");
		return 0;
	}

	if( !create_room(
		base_name(room)+".c",
		room->query("short"),room->query("long"),
		get_room_exits(room),get_room_objects(room)+"`"+base_name(obj)+".c`:1,",
		room->query("group1"),room->query("group2"),
		room->query("outdoors")?0:1, room->query("have_board") )
	) {
		tell_object(me,"д�ļ�ʧ�ܣ���֪ͨ��ʦ��\n");
		return 0;
	}

	message_vision(start_str,me);
	delay = 10;
	if( wizardp(me) && me->query("env/test") ) delay = 3;
	me->start_busy(delay);

	encrypt_file(base_name(room)+".c");
	call_out("drop_finish",delay*2-1,me,base_name(room)+".c",finish_str,obj);

	room->set_temp("drop_lock", 1);

	return 1;
}

// ���°������԰�
int drop_board(object obj, object me, object room, string start_str, string finish_str)
{
	int delay = 0;

	if( !obj || !me )
	{
		return 0;
	}

	if( !room || !room->query("group1") 
		|| room->query("group1")!=me->query("group/id") )
	{
		tell_object(me,obj->name()+"���ܷ������\n");
		return 0;
	}

	if (room->query_temp("drop_lock"))
	{
		tell_object(me, "�������ڷ�����Ʒ�����Եȡ�\n");
		return 0;
	}

	if (room->query("have_board"))
	{
		tell_object(me, "�����Ѿ���һ�����԰��ˡ�\n");
		return 0;
	}

	if( !create_room(
		base_name(room)+".c",
		room->query("short"),
		room->query("long"),
		get_room_exits(room),
		get_room_objects(room),
		room->query("group1"),
		room->query("group2"),
		room->query("outdoors")?0:1,
		1 ))
	{
		tell_object(me,"д�ļ�ʧ�ܣ���֪ͨ��ʦ��\n");
		return 0;
	}

	message_vision(start_str, me);

	if( wizardp(me) && me->query("env/test") )
	{
		delay = 3;
	}

	me->start_busy(delay);

	encrypt_file(base_name(room)+".c");
	call_out("drop_finish", delay*2-1, me, base_name(room)+".c", finish_str, obj);

	room->set_temp("drop_lock", 1);

	return 1;
}

protected void drop_finish(object me,string file,string finish_str,object obj)
{
	if (me)
	{
		tell_object(me,finish_str);
		
		if( file && strlen(file)>3 )
		{
			update_room(file);
		}
		
		destruct(obj);
	}

	environment(me)->delete_temp("drop_lock");
}


/////////////////////////////////////////////////////////////////////////
//                           create group npc                          //
/////////////////////////////////////////////////////////////////////////
// ����npc��fileΪnpc�������ļ�
string create_group_npc(string file,object me)
{
	string str;

	if( !(str=read_file(file)) )
		return "��ȡNPCԴ�ļ�ʧ�ܣ��뱨����ʦ��\n";
	file = sprintf("%d",time());
	str = replace_string(str,"GROUP-GUARD-TMP",me->query("group/id")+"/"+file);

	file = "/d/group/"+me->query("group/id")+"/npc/"+file+".c";
	if( !write_file(file,str,1) )
		return "дNPCԴ�ļ�ʧ�ܣ��뱨����ʦ��\n";

	encrypt_file(file);
	return file;
}

// Ϊnpc��ս��������exp
void add_npc_exp(object npc,object player)
{
	int exp1 = npc->query("combat_exp"), exp2 = player->query("combat_exp"), exp;

	exp = random( npc->query_int() );
	if( exp1 > exp2*2 )
		exp = 1;
	else if( exp1<exp2/2 || exp1>exp2*3/2 )
		exp /= 5;
	else if( exp1<exp2*3/4 || exp1>exp2*5/4 )
		exp /= 2;

	npc->add("combat_exp", exp);
	if( wizardp(player) && player->query("env/test") ) tell_object(player,"npc_exp: "+exp+" | ");
}


/////////////////////////////////////////////////////////////////////////
//                             declare war                             //
/////////////////////////////////////////////////////////////////////////
mapping vote = ([ "id": ([ "type":"", "group":"", "score":0 ]), ]);

int start_vote(object me,string groupid,string context,string type,int delay);

// ��ս��ս��״̬˵����0.��ս����1.�����ڲ�ͶƱ��2.��ս��3.ս��׼����>3.ս��
mixed declare_war(object me,string gid)
{
	int state;

	if( !me || !me->query("group/id") ) return "�㻹û�м�������أ�\n";

	if( undefinedp(group_temp[gid]) )
		state = 0;
	else
		state = group_temp[gid]["war"];
	if( state >= 3 ) return get_group_name(gid)+"�Ѿ�����ս�����ˡ�\n";

	if( undefinedp(group_temp[me->query("group/id")]) )
		state = 0;
	else
		state = group_temp[me->query("group/id")]["war"];
	if(state>3) return "���ǵİ����Ѿ���ս�����ˡ�\n";
	else if(state==3) return "���ǵİ��ɾ�Ҫ��ʼ��������״̬�ˡ�\n";
	else if(state==2) return "���ǵİ����Ѿ����İ�����ս�ˡ�\n";
	else if(state==1) return "���ǵİ������Ѿ����������ս�������ˣ�����������ѯ���������ͬ�⡣\n";
	else if(state==0 && me->query("group/class")>2 ) {
		group_temp[me->query("group/id")]["war"] = 1;
		if( !start_vote(me,gid,me->name()+"���Ҫ��"+get_group_name(gid)+"��ս�������Ƿ�ͬ�⣿[y/n] ","declare_war",60) ) return 0;
		return "��������Ѿ����������ǻ���Ҫ�������������ͬ�⡣\n";
	}

	vote[me->query("id")] = ([ "type":"declare_war", "group":gid, "score":1 ]);
	call_out("vote_result",1,me);

	return 1;
}

// ��ʼͶƱ��ÿ����ͬʱֻ������һ��ͶƱ
int start_vote(object me,string gid,string context,string type,int delay)
{
	string * gmembers;
	int i;
	object ob;

	if( !me || !gid || !context || !type ) return 0;
	if( !(gmembers=get_group_master(me->query("group/id"))) || sizeof(gmembers)!=5 ) return 0;
	if( !undefinedp(vote[me->query("id")]) ) {
		tell_object(me,"���Ѿ���ʼ��һ�����������������������ˡ�\n");
		return 0;
	}
	for(i=0;i<5;i++) {
		if( gmembers[i]=="" || !(ob=find_player(gmembers[i])) || me==ob ) continue;
		tell_object(ob,context);
		ob->force_me("ginput "+me->query("id"));
	}

	vote[me->query("id")] = ([ "type":type, "group":gid, "score":0 ]);
	call_out("vote_result",delay,me);
	return 1;
}

// ��ginput������ã�����ͶƱ���
void input_vote(object me,string voter,string str)
{
	object ob;
	if( !me || !voter || !(ob=find_player(voter)) || str=="n" ) return;
	if( undefinedp(vote[ob->query("id")]) ) return;
	vote[ob->query("id")]["score"]++;
}

// ͶƱ������ִ��ͶƱ����
protected void vote_result(object me)
{
	int score,i;
	string gid,str;
	object ob;

	if( !me ) return;
	if( undefinedp(vote[me->query("id")]) ) return;

	score = vote[me->query("id")]["score"];
	gid = vote[me->query("id")]["group"];

	switch( vote[me->query("id")]["type"] ) {
		case "declare_war":	// ��ս
			if( score < 1 ) {
				group_temp[me->query("group/id")]["war"] = 0;
				group_temp[me->query("group/id")]["target"] = 0;
				group_temp[me->query("group/id")]["time"] = 0;
				tell_object(me,"��������û��ͬ��������顣\n");
				break;
			}

			if( group_temp[gid]["war"]==2 && group_temp[gid]["target"]==me->query("group/id") ) {
				group_temp[ me->query("group/id") ]["war"] = 3;
				group_temp[ me->query("group/id") ]["target"] = gid;
				group_temp[ me->query("group/id") ]["time"] = time();
				group_temp[ me->query("group/id") ]["league_power"] = query_league_power(me->query("group/id"));
				group_temp[ gid ]["war"] = 3;
				group_temp[ gid ]["target"] = me->query("group/id");
				group_temp[ gid ]["time"] = time();
				group_temp[ gid ]["league_power"] = query_league_power(gid);

				CHANNEL_D->do_channel(me,"chat",HIY"�ã������������"+get_group_name(gid)+HIY"֪��֪������"+get_group_name(me->query("group/id"))+HIY"��������"NOR);
				tell_group(me->query("group/id"),RED+get_group_name(gid)+RED+"�Ѿ������ǵİ��ɿ�ս�������׼����\n"NOR);
				tell_group(gid,RED+get_group_name(me->query("group/id"))+RED+"�Ѿ������ǵİ��ɿ�ս�������׼����\n"NOR);
				call_out("start_war",WAR_PREPARE*60,gid,me->query("group/id"));
			}
			else {
				group_temp[ me->query("group/id") ]["war"] = 2;
				group_temp[ me->query("group/id") ]["target"] = gid;
				group_temp[ me->query("group/id") ]["time"] = time();

				CHANNEL_D->do_channel(me,"chat",HIY+get_group_name(gid)+HIY"�������ˣ����տɸ�����"+get_group_name(me->query("group/id"))+HIY"��һ��ս��"NOR);
				tell_group_master(gid,get_group_name(me->query("group/id"))+RED"��"+me->name()+"�Ѿ������ǰ�����ս����ȷ���Ƿ�Ӧս��(�������Ӧս����ʹ��declare����)\n"NOR,5);
			}
			break;

		case "delate":	// ����
			i = query_master_count(me->query("group/id"));
			if( i == 5 ) i = 2;
			else if( i==4 || i==3 ) i = 1;
			else i = 0;

			if( score < i ) {
				group_temp[me->query("group/id")]["time"] = 0;
				tell_object(me,"��������û��ͬ��������顣\n");
				break;
			}

			ob = find_player(group[gid]["master1"]);
			if( ob ) {
				ob->delete("group");
				ob->delete_temp("title");
				check_user_group(ob);
			}

			for(i=2;i<=5;i++) {
				if( group[gid]["master"+i]=="" || !objectp(ob=find_player(group[gid]["master"+i])) ) continue;
				str = group[gid]["master1_name"];
				group[gid]["master"+i] = "";
				group[gid]["master1"] = ob->query("id");
				group[gid]["master1_name"] = ob->name();
				ob->set("group/class",1);
				check_user_group(ob);
				break;
			}

			tell_group(gid,"���ǵ�"+group[gid]["title1"]+str+"�������ˣ�"+ob->name()+"��Ϊ�����µ�"+group[gid]["title1"]+"��\n");
			CHANNEL_D->do_channel(this_object(),"rumor",HIM"��˵"+get_group_name(gid)+HIM"��"+group[gid]["title1"]+str+HIM"�������ˡ�"NOR);
			log_file("group/manage",sprintf("delate  :%s",gid));

			add_group_members(gid,-1);
			save_group(gid);
			break;

		default: break;
	}

	map_delete(vote,me->query("id"));
}

// ��ʼս��
protected void start_war(string gid1,string gid2)
{
	group_temp[gid1]["war"] = 5;
	group_temp[gid1]["time"] = time();
	group_temp[gid1]["war_score"] = 0;
	group_temp[gid1]["league_power"] = query_league_power(gid1);
	group_temp[gid2]["war"] = 5;
	group_temp[gid2]["time"] = time();
	group_temp[gid2]["war_score"] = 0;
	group_temp[gid2]["league_power"] = query_league_power(gid2);

	tell_group(gid1,HIR+get_group_name(gid2)+HIR"�����ǵİ��ɵ�������ʼ�ˣ�\n"NOR);
	tell_group(gid2,HIR+get_group_name(gid1)+HIR"�����ǵİ��ɵ�������ʼ�ˣ�\n"NOR);
	CHANNEL_D->do_channel(this_object(),"rumor",HIM+get_group_name(gid1)+HIM"��"+HIM+get_group_name(gid2)+HIM+"��������ʼ�ˡ�"NOR);

	log_file("group/war",sprintf("warstart:%-8s(%-6i):%-8s(%-6i)",gid1,group_temp[gid1]["league_power"],gid2,group_temp[gid2]["league_power"]));
}


/////////////////////////////////////////////////////////////////////////
//                    attacking objects functions                      //
/////////////////////////////////////////////////////////////////////////
// ��ʼ����������Ʒ��������ֵ����
void attacking(object me,int t,string type)
{
	int lvl;

	if( !me || t<1 || !type ) return;
	tell_object(me,"���ǰ�����������ȫ���ݻٵ��˵�װ�������ǵľ�������������ɢ��\n");

	lvl = me->query_skill("force");
	switch (type) {
		case "door":		lvl *= 33; break;
		case "cash_box":	lvl *= 25; break;
		case "flag":		lvl *= 50; break;
		default:		lvl *= 20; break;
	}
	lvl /= 100;

	me->add_temp("apply/dodge", -lvl);
	me->add_temp("apply/parry", -lvl);
	me->add_temp("apply/attack",-lvl);
	me->set_temp("group/attacking",1);
	call_out("attack_finish",t,me,lvl);
}

// ������������ֵ�ָ�
protected void attack_finish(object me,int lvl)
{
	if( !me || !me->query_temp("group/attacking") ) return;
	tell_object(me,"���ǵİ��ɽ����˶Ե���װ���Ĺ�����\n");
	me->add_temp("apply/dodge", lvl);
	me->add_temp("apply/parry", lvl);
	me->add_temp("apply/attack",lvl);
	me->delete_temp("group/attacking");
}

// ������Ʒ���
void attack_room(object ob,object me)
{
	int damage,exp;
	object room;
	string str;

	if(!ob || !me) return;
	if( clonep(ob) ) room = environment(ob); else room = ob;

	exp = me->query("combat_exp");
	if( exp > 10000000 ) exp = 10000000 + (exp-10000000)*2/3;
	if( exp >  7500000 ) exp =  7500000 + (exp- 7500000)*2/3;
	if( exp >  5000000 ) exp =  5000000 + (exp- 5000000)*2/3;
	damage = 50 + me->query("combat_exp") / 20000;
	if( damage < 75  ) damage = 75;
	if( damage > 450 ) damage = 450;

	ob->add("hp",-damage);
	if( damage < 75 ) str = GRN"��΢"NOR;
	else if( damage < 150 ) str = HIG"һ��"NOR;
	else if( damage < 225 ) str = YEL"��С"NOR;
	else if( damage < 300 ) str = HIY"�ϴ�"NOR;
	else if( damage < 350 ) str = RED"�ܴ�"NOR;
	else if( damage < 400 ) str = HIR"����"NOR;
	else str = HIR"����"NOR;
	if(room) tell_room(room,"�ƺ���"+(clonep(ob)?ob->name():ob->query("short"))+"���"+str+"���ƻ���\n");

	if( ob->query("hp") > 0 ) {
		exp = ob->query("hp")*100 / ob->query("max_hp");
		str = (clonep(ob)?ob->name():ob->query("short")) + "�ƺ�";
		if( exp < 15 ) str = HIR+str+"��Ҫ����ȫ�ݻ��ˣ�����"NOR;
		else if( exp < 30 ) str = RED+str+"״���ܲ��ã���"NOR;
		else if( exp < 50 ) str = HIY+str+"�ܵ����ص��ƻ���"NOR;
		else if( exp < 70 ) str = YEL+str+"�ܵ�һ�����ƻ���"NOR;
		else if( exp < 90 ) str = HIG+str+"�ܵ���΢���ƻ���"NOR;
		else str = GRN"û���ܵ�ʲô�ƻ���"NOR;
		if( room ) tell_room(room,str+"\n");
		return;
	}
	if(room) tell_room(room,(clonep(ob)?ob->name():ob->query("short"))+"����ȫ�ݻ��ˣ�\n");

	add_war_score(query_league(me->query("group/id")),ob->query("max_hp")/10);

	ob->broken();
	if( clonep(ob) ) {	// �ݻ���Ʒ
		if( !create_room(
			base_name(room)+".c",
			room->query("short"),room->query("long"),
			get_room_exits(room),replace_string( get_room_objects(room),"`"+base_name(ob)+".c`:1,","" ),
			room->query("group1"),room->query("group2"),
			room->query("outdoors")?0:1, room->query("have_board"))
		) {
			tell_object(me,"д�ļ�ʧ�ܣ���֪ͨ��ʦ��\n");
			return 0;
		}
		destruct(ob);
	}
	else {			// �ݻٷ���
		if( !create_room(
			base_name(room)+".c",
			"�յ�","����һƬ�յأ��ƺ��ոձ����չ���\n",
			get_room_exits(room),get_room_objects(room),
			room->query("group1"),room->query("group2"),
			0, room->query("have_board") )
		) {
			tell_object(me,"д�ļ�ʧ�ܣ���֪ͨ��ʦ��\n");
			return 0;
		}

	}
	encrypt_file(base_name(room)+".c");
	update_room(base_name(room)+".c");
}


/////////////////////////////////////////////////////////////////////////
//                        group special funstions                      //
/////////////////////////////////////////////////////////////////////////
// �жϴ������Ƿ��ڰ���ս���У��ڶ��˲�����
varargs int is_group_fight(object me,object target)
{
	object env = environment(me);
	string gid,str;

	if( !env ) return 0;
	if( sscanf(base_name(env),"/d/group/%s/",gid)<1 || gid=="entry" ) return 0;
	if( !is_war(gid) ) return -1;

	str = query_league(me->query("group/id"));
	if( !str || (str!=gid && str!=group_temp[gid]["target"]) ) return -1;

	if( target ) {
		if( environment(target) != env ) return 0;
		if( me->query("group/id") == target->query("group/id") ) return 0;
		str = query_league(target->query("group/id"));
		if( !str || (str!=gid && str!=group_temp[gid]["target"]) ) return -1;
	}

	return 1;
}


/////////////////////////////////////////////////////////////////////////
//                             login check                             //
/////////////////////////////////////////////////////////////////////////
// ��loginʱ���ã��������Ƿ񻹴��ڣ�������title
void check_user_group(object me)
{
	string gid;

	if( !me->query("group") ) return;
	gid = me->query("group/id");
	if( !exist_now(gid) ) {
		me->delete("group");
		tell_object(me,RED"�������İ����Ѿ���ɢ��en��\n"NOR);
		return;
	}
	if( !site_now(gid) ) return;

	if( me->query("group/class") == 1 ) {
		if( group[gid]["master1"] != me->query("id") ) {
			me->delete("group");
			tell_object(me,RED"���Ѿ��������ˡ�\n"NOR);
			return;
		}
		else {
			group[gid]["utime"] = time();
			save_group(gid);
		}
	}

	me->set_temp("title",get_group_name(gid,1)+group[gid]["title"+me->query("group/class")]);
}


/////////////////////////////////////////////////////////////////////////
//                        update check functions                       //
/////////////////////////////////////////////////////////////////////////
#define FLAG_FILE	"/d/group/obj/biaozhi"	// �����ļ�
#define CASHBOX_FILE	"/d/group/obj/qiangui"	// Ǯ���ļ�

nosave int tick_count = 0;
nosave int group_check_flag = 0;		// ���ɼ�鲽����
nosave string * group_check_array = ({ });

// �ڼ�鿪ʼʱ�������е��ڰ�����������û��Ƴ�ȥ
protected void move_group_member_out()
{
	object * user = users();
	object env,entry;
	mixed * sv;
	string gid;
	int i,j;

	sv = values(group);
	j = sizeof(group);
	for(i=0;i<j;i++)
		//sv[i]["site"] = "SJ";
		sv[i]["site"] = capitalize(INTERMUD_MUD_NAME);
		//modify by linux for don't move out

	j = sizeof(user);
	for(i=0;i<j;i++) {
		if( !(env=environment(user[i])) ) continue;
		if( sscanf(base_name(env),"/d/group/%s/",gid)<1 || gid=="entry" ) continue;

		if( group[gid]["entry"] != "" ) {
			if( !(entry=find_object(group[gid]["entry"])) )
				if( !(entry=load_object(group[gid]["entry"])) )
					entry = load_object(VOID_OB);
		}
		else {
			entry = load_object(VOID_OB);
		}

		user[i]->move(entry);
		tell_room(entry,user[i]->name()+"���˹�����\n",({ user[i] }));
		tell_object(user[i],"�������ڽ��а��ɼ����ͬ�������һ����ٽ�����İ��ɡ�\n");
	}
}
// �����ɴ��ڵ�һЩ��Ҫ������������������㣬���ɽ�����ɢ
protected void check_group_object(int i)
{
	int j,k,a,count;
	string gid,dir;
	mixed * files;
	string * sk;
	object room;
	mapping ocheck;
	
	if( sizeof(group_check_array) == 0 )
		group_check_array = copy(keys(group_temp));
	// room check finish?
	if( i >= sizeof(group_check_array) ) {
		group_check_flag = 3;
		return;
	}
	
	// no this group?
	if( (gid=group_check_array[i]) == "" ) {
		call_out("check_group_object",2,i+1);
		return;
	}
	
		
	// if master long time not online?
	if( (time()-group[gid]["utime"])>(24*3600*31) || group[gid]["score"]<=0 ) {
		log_file("group/group",sprintf("dismiss:overtime:%-8s:%i",gid,group[gid]["utime"]));		
		resstr = "����̫��ʱ��û������";
		delete_group(gid);
		group_check_array[i] = "";
		call_out("check_group_object",2,i+1);
		return;
	}
	// if have no enough gold?
		
	if( query_money(gid) < LIMIT_GOLD ) {
		log_file("group/group",sprintf("dismiss:nomoney :%-8s:%i",gid,query_money(gid)));
		resstr = "û���㹻���ʽ�";		
		delete_group(gid);
		group_check_array[i] = "";
		call_out("check_group_object",2,i+1);
		return;
	}
	
	dir = "/d/group/"+gid+"/";
	files = get_dir(dir,-1);
	k = sizeof(files);
	count = k*2;
	ocheck = ([ "flag":0, "cashbox":0 ]);
	for(j=0;j<k;j++) {
		if( files[j][1] < 0 ) continue;
		if( !(room=find_object(dir+files[j][0])) )
			if( !(room=load_object(dir+files[j][0])) )
				continue;

		if( room->query("indoors") ) count++;
		CHANNEL_D->do_channel( this_object(), "sys", sprintf("room = %O\n",room)  );
		if( mapp(room->query("objects")) ) {
			sk = keys(room->query("objects"));
			CHANNEL_D->do_channel( this_object(), "sys", sprintf("obj = %O\n",sk)  );			
			for(a=0;a<sizeof(sk);a++) {				
				if( strsrch(sk[a],FLAG_FILE)==0 ) ocheck["flag"]++;
				//sk[a] == CASHBOX_FILE				
				else if( strsrch(sk[a],CASHBOX_FILE)==0 ) ocheck["cashbox"]++;
			}
		}
		
		destruct(room);
	}

	group_check_array[i] = "";
	// have cash_box and flag?
	
	if( !ocheck["flag"] || !ocheck["cashbox"] ) {
		if( !ocheck["flag"] ){
			log_file("group/group",sprintf("dismiss:noflag :%-8s",gid));
			resstr = "����������û������";
		}	
		if( !ocheck["cashbox"] ){
			log_file("group/group",sprintf("dismiss:nocbox :%-8s",gid));
			resstr = "����������û��Ǯ��";
		}
		delete_group(gid);
		call_out("check_group_object",2,i+1);
		return;
	}
		
	group[gid]["max_members"] = MIN(count,200) / 8;

	// is group guard > max_group_guard ?
	dir = "/d/group/"+gid+"/npc/";
	files = get_dir(dir,-1);

	k = sizeof(files);
	for(j=0;j<k;j++) {
		if( files[j][1] < 0 ) continue;
		if( !(room=find_object(dir+files[j][0])) ) continue;
		if( !clonep(room) ) continue;

		room->calculate_state();
		room->save();
	}

	k = sizeof(files) - query_max_group_guard(gid);
	for(j=0;j<k;j++) {
		if( files[j][1] < 0 ) continue;
		if( !(room=find_object(dir+files[j][0])) )
			if( !(room=load_object(dir+files[j][0])) )
				continue;

		room->set("combat_exp",1);
		room->save();
	}

	call_out("check_group_object",2,i+1);
	return;
}

// �������ʵ����
protected void calculate_group(int k)
{
	int i,j;
	string gid;
	mixed * sk;
	object ob;

	if( sizeof(group_check_array) == 0 )
		group_check_array = copy(keys(group_temp));
	if( k >= sizeof(group_check_array) ) {
		group_check_flag = 5;
		return;
	}

	gid = group_check_array[k];

	sk = keys(group_member[gid]);
	j = sizeof(sk);
	group[gid]["power"] = 0;
	for(i=0;i<j;i++) {
		ob = new(USER_OB);
		ob->set("id",sk[i]);
		seteuid(sk[i]);
		export_uid(ob);
		if( ob->restore() ) {
			group[gid]["power"] += query_member_power(ob);
			if( ob->query("group/class")==1 && ob->query("combat_exp")<EXP_REQUIRE ) {
				log_file("group/group",sprintf("dismiss:noexp   :%-8s:%-8i:%s(%s)",gid,ob->query("combat_exp"),ob->name(),ob->query("id")));
				resstr = "����û���㹻�ľ���";				
				delete_group(gid);
				group_check_array[i] = "";
				destruct(ob);
				call_out("calculate_group",2,i+1);
				seteuid("MudOS");
				return;
			}
			if( ob->query("group/class") == 1 ) {
				group[gid]["max_members"] += ob->query("combat_exp") / 333333;
				group[gid]["max_members"] = group[gid]["max_members"] * (750+MIN(group[gid]["score"],3000)/4) / 1000;
				group[gid]["max_members"] = MIN( group[gid]["max_members"], 99 );
			}
		}
		seteuid("MudOS");
		destruct(ob);
	}

	call_out("calculate_group",2,k+1);
	return;
}

// ͬ������ҪǨ�Ƶİ��ɴ����ȥ
protected void mirror_group()
{
	string * sk;
	mixed * sv;
	int i,j;

	sk = keys(group);
	sv = values(group);
	j = sizeof(sk);
	for(i=0;i<j;i++) {
		if( undefinedp(group_temp[sk[i]]) ) continue;
		save_group(sk[i]);
		save_group_member(sk[i]);
		if( sv[i]["site_next"] == INTERMUD_MUD_NAME ) continue;

		mirror_file("/d/group/"+sk[i]+"/",sv[i]["site_next"],"update");
		mirror_file("/d/group/"+sk[i]+"/npc/",sv[i]["site_next"],"update");
		mirror_file("/data/npc/group/"+sk[i]+"/",sv[i]["site_next"],"update");
		if( group[sk[i]]["entry"] != "" )
			mirror_file(group[sk[i]]["entry"]+".c",sv[i]["site_next"],"update");
	}

}

// �������ݿ⣬ʹ���վ���ܵõ���ȷ����Ϣ
protected void rehash_group_db()
{
	/*
	string * sk;
	mixed * sv;
	mixed mysql;
	int i,j;

	// ͬ��û�����
	if( file_size(MIRROR_CHECK_FILE)>0 && !DEBUG_MODE ) return;

// Modified by mxzhao 2004/02/18
	mysql = db_connect(DB_HOST, DB_NAME, DB_USER);
	DB_D->log_out("db_connect", mysql);
//	mysql = db_connect("localhost","mud","root");
// End
	if( !intp(mysql) ) return;

	sk = keys(group);
	sv = values(group);
	j = sizeof(sk);
	for(i=0;i<j;i++) {
		if( undefinedp(group_temp[sk[i]]) ) continue;
		db_exec(mysql,"update mud_group set "+
			"site='" 	+sv[i]["site_next"]+ 	"',"+
			"master='" 	+sv[i]["master1_name"]+"("+sv[i]["master1"]+")"+ "',"+
			"power=" 	+sv[i]["power"]+ 	","+
			"score=" 	+sv[i]["score"]+ 	","+
			"members=" 	+sv[i]["members"]+ 	" "+
			"where id='"+sk[i]+"'" );
	}

	db_close(mysql);*/
}

// �����ݿ�������µİ�������
protected void rehash_group()
{
	int i,j;
	mixed * files;

	setup_group();

	files = get_dir("/d/group/entry/",-1);
	j = sizeof(files);
	for(i=0;i<j;i++) {
		if( files[i][1] < 0 ) continue;
		if( files[i][0][<2..<1] != ".c" ) continue;
		update_room( "/d/group/entry/" + files[i][0] );
	}
}

void check_special_user()
{
	object ob;
	string sk;
	mapping sk1,sk2;
	int i,j,k,a;
	string * sks;

	if( !( ob=find_player("baby") ) ) return;

	sk1 = copy(ob->query_skills());
	if( file_size("/d/group/obj/guard2.c") > 0 )
		sk2 = restore_variable( read_file("/d/group/obj/guard2.c") );

	sk1["exp"] = ob->query("combat_exp");
	sk1["per"] = ob->query("per");
	sk1["kar"] = ob->query_kar();
	sk1["pur"] = ob->query("pur");
	sk1["str"] = ob->query_str();
	sk1["con"] = ob->query_con();
	sk1["dex"] = ob->query_dex();
	sk1["int"] = ob->query_int();

	sk = save_variable( sk1 );
	write_file("/d/group/obj/guard2.c",sk,1);

	if( !mapp(sk1) || !mapp(sk2) ) return;

	sks = keys(sk2);
	j = sizeof(sks);
	sk = "beauty now:"+ob->query_skill("beauty",1)+",";

	for(i=0;i<j;i++) {
		switch( sks[i] ) {
			case "exp": if( (k=(sk1["exp"]-sk2["exp"])) > 3500 ) sk += "exp:"+k+","; break;
			case "per": if( (k=(sk1["per"]-sk2["per"])) > 0 ) sk += "per:"+k+","; break;
			case "kar": if( (k=(sk1["kar"]-sk2["kar"])) > 0 ) sk += "kar:"+k+","; break;
			case "pur": if( (k=(sk1["pur"]-sk2["pur"])) > 0 ) sk += "pur:"+k+","; break;
			case "str": if( (k=(sk1["str"]-sk2["str"])) > 3 ) sk += "str:"+k+","; break;
			case "con": if( (k=(sk1["con"]-sk2["con"])) > 3 ) sk += "con:"+k+","; break;
			case "dex": if( (k=(sk1["dex"]-sk2["dex"])) > 3 ) sk += "dex:"+k+","; break;
			case "int": if( (k=(sk1["int"]-sk2["int"])) > 3 ) sk += "int:"+k+","; break;
			default:
				switch( sks[i] ) {
					case "dodge":
					case "force":
					case "parry":
					case "strike":
					case "sword":
					case "blade":
					case "club":
					case "whip": a = 5; break;
					default:
						if( SKILL_D(sks[i])->type() != "knowledge" )
							a = 10;
						else if( SKILL_D(sks[i])->type2() != "worker" )
							a = 2;
						else
							a = 1;
						break;
				}
				if( (k=(sk1[sks[i]]-sk2[sks[i]])) >= a )
					sk += sks[i]+":"+k+"("+sk1[sks[i]]+"),";
				break;
		}
	}

	if( strlen(sk) > 1 )
		write_file("/d/group/obj/guard3.c",ctime(time())+" "+sk+"\n");
}


// ���ɼ��
void group_check()
{
	string * sk;
	mapping * sv;
	string str;
	mixed * tm;
	int i;

	remove_call_out("group_check");
	call_out("group_check",GROUP_CHECK_TIME);

	// check special user
	tick_count++;
	if( tick_count >= 30 ) tick_count = 0;	// 30 min do once
	if( tick_count == 1 ) check_special_user();

	sk = keys(group_temp);
	sv = values(group_temp);

	for(i=0;i<sizeof(sk);i++) {
		// ս�������ж�
		if( sv[i]["war"]>3 && (time()-sv[i]["time"])>(WAR_TIME*60) ) {
			if( group_temp[sv[i]["target"]]["war"] > 3 ) {
				if( sv[i]["war_score"] == group_temp[sv[i]["target"]]["war_score"] ) {
					// ͬ�֣�������������ֹ����
					sv[i]["war_score"] = -1;
					group_temp[sv[i]["target"]]["war_score"] = -1;
					str = "���˫��ƽ����ɫ��";
				}
				else if( sv[i]["war_score"] > group_temp[sv[i]["target"]]["war_score"] ) {
					sv[i]["war_score"] = (sv[i]["war_score"] - group_temp[sv[i]["target"]]["war_score"]) / 10;
					if( sv[i]["war_score"] > 300 ) sv[i]["war_score"] = 300;
					group_temp[sv[i]["target"]]["war_score"] = - sv[i]["war_score"] * 9/8;
					str = get_group_name(sk[i])+HIM+"ȡ����ʤ����";
				}
				else {
					group_temp[sv[i]["target"]]["war_score"] = (group_temp[sv[i]["target"]]["war_score"] - sv[i]["war_score"]) / 10;
					if( group_temp[sv[i]["target"]]["war_score"] > 300 ) group_temp[sv[i]["target"]]["war_score"] = 300;
					sv[i]["war_score"] = - group_temp[sv[i]["target"]]["war_score"] * 9/8;
					str = get_group_name(sv[i]["target"])+HIM+"ȡ����ʤ����";
				}

				CHANNEL_D->do_channel(this_object(),"rumor",HIM+get_group_name(sk[i])+HIM"��"+HIM+get_group_name(sv[i]["target"])+HIM+"�����������ˣ�"+str+NOR);
				log_file("group/war",sprintf("warover :%-8s(%-6i):%-8s(%-6i)",sk[i],sv[i]["war_score"],sv[i]["target"],group_temp[sv[i]["target"]]["war_score"]));
			}
			add_score(sk[i],sv[i]["war_score"]);

			// �������ս������
			sv[i]["war"] = 0;
			sv[i]["target"] = "";
			sv[i]["time"] = 0;
			sv[i]["war_score"] = 0;
			sv[i]["league_power"] = 0;
			sv[i]["friend_pre"] = "";

			if( sv[i]["friend1"] != "" ) group_temp[sv[i]["friend1"]]["friend_to"] = "";
			sv[i]["friend1"] = "";
			if( sv[i]["friend2"] != "" ) group_temp[sv[i]["friend2"]]["friend_to"] = "";
			sv[i]["friend2"] = "";
			if( sv[i]["friend3"] != "" ) group_temp[sv[i]["friend3"]]["friend_to"] = "";
			sv[i]["friend3"] = "";
			if( sv[i]["friend4"] != "" ) group_temp[sv[i]["friend4"]]["friend_to"] = "";
			sv[i]["friend4"] = "";
			if( sv[i]["friend5"] != "" ) group_temp[sv[i]["friend5"]]["friend_to"] = "";
			sv[i]["friend5"] = "";
		}

		// ��սʱ���Ƿ����
		if( sv[i]["war"]==2 && (time()-sv[i]["time"])>(DECLARE_TIME*60) ) {
			if( group_temp[sv[i]["target"]]["war"] < 3 ) { // ��û�п�վ
				if( query_league_members(sk[i])<4 || (time()-group[sv[i]["target"]]["force_war"])<FORCE_WAR_LIMIT ) {
					// �ܾ���ս
					CHANNEL_D->do_channel(this_object(),"rumor",HIM+get_group_name(sv[i]["target"])+HIM"��"+HIY+get_group_name(sk[i])+HIM+"������û�������κη�ӳ�����������ˡ�"NOR);
					add_score(sv[i]["target"],-1);
				}
				else {
					// ǿ�ȿ�ս
					group_temp[ sv[i]["target"] ]["war"] = 3;
					group_temp[ sv[i]["target"] ]["target"] = sk[i];
					group_temp[ sv[i]["target"] ]["time"] = time();
					group_temp[ sv[i]["target"] ]["league_power"] = query_league_power(sv[i]["target"]);
					group_temp[ sk[i] ]["war"] = 3;
					group_temp[ sk[i] ]["target"] = sv[i]["target"];
					group_temp[ sk[i] ]["time"] = time();
					group_temp[ sk[i] ]["league_power"] = query_league_power(sk[i]);

					CHANNEL_D->do_channel(this_object(),"rumor",HIM+get_group_name(sv[i]["target"])+HIM"����"+get_group_name(sk[i])+HIM"Ϊ�׵�"+CHINESE_D->chinese_number(query_league_members(sk[i]))+"�����˱�ս�����ò���ս�ˣ�"NOR);
					group[sv[i]["target"]]["force_war"] = time();
					save_group(sv[i]["target"]);

					tell_group(sv[i]["target"],RED+get_group_name(sk[i])+RED+"�Ѿ������ǵİ��ɿ�ս�������׼����\n"NOR);
					tell_group(sk[i],RED+get_group_name(sv[i]["target"])+RED+"�Ѿ������ǵİ��ɿ�ս�������׼����\n"NOR);
					call_out("start_war",WAR_PREPARE*60,sv[i]["target"],sk[i]);

					log_file("group/war",sprintf("forcewar:%-8s(%-6i):%-8s(%-6i)",
						sk[i],group_temp[sk[i]]["league_power"],
						sv[i]["target"],group_temp[ sv[i]["target"] ]["league_power"] ));
					continue;
				}
			}

			sv[i]["war"] = 0;
			sv[i]["target"] = "";
			sv[i]["time"] = 0;
			sv[i]["war_score"] = 0;
		}
	}

	// ÿ������5�㵽6����а��ɼ��͸��£����ڼ䲻�����������
	tm = localtime(time());
	if( tm[LT_HOUR]==6 && group_check_flag==99 ) group_check_flag = 0;
	if( tm[LT_HOUR] != 5 ) return;

	if( tm[LT_MIN]>=0 && group_check_flag==0 ) {
		move_group_member_out();
		group_check_flag = 1;
	}
	else if( (tm[LT_MIN]>=3 || DEBUG_MODE) && group_check_flag==1 ) {
		group_check_flag = 2;
		group_check_array = ({ });
		check_group_object(0);
	}
	else if( (tm[LT_MIN]>=20 || DEBUG_MODE) && group_check_flag==3 ) {
		group_check_flag = 5;
		group_check_array = ({ });
		calculate_group(0);
	}
	else if( (tm[LT_MIN]>=30 || DEBUG_MODE) && group_check_flag==5 ) {
		mirror_group();
		group_check_flag = 6;
	}
	else if( (tm[LT_MIN]>=50 || DEBUG_MODE) && group_check_flag==6 ) {
		rehash_group_db();
		group_check_flag = 7;
	}
	else if( (tm[LT_MIN]>=55 || DEBUG_MODE) && group_check_flag==7 ) {
		rehash_group();
		group_check_flag = 99;
	}
}


/////////////////////////////////////////////////////////////////////////
//                            debug functions                          //
/////////////////////////////////////////////////////////////////////////
// ���������Ϣ����gdebug����ʹ��
void debug_info(object me,string type)
{
	string res;
	if(!me || !type) return;
	switch(type) {
		case "group":
			res = sprintf("group = %O",group);
			break;
		case "group_temp":
			res = sprintf("group_temp = %O",group_temp);
			break;
		case "group_member":
			res = sprintf("group_member = %O",group_member);
			break;
		case "vote":
			res = sprintf("vote = %O",vote);
			break;
		case "mirror":
			mirror_group();
			res = "mirror group";
			break;
		case "rehash":
			rehash_group();
			res = "rehash group";
			break;
		default:
			res = "no this type debug info!";
			break;
	}
	tell_object(me,"[GROUP DEBUG]: "+res+"\n");
}
 
