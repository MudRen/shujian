// lotteryd.c
// by yuj@sj
// by augx@sj 5/27/2002 for fifa world cup 2002

inherit F_SAVE;
#include <ansi.h>
#include <localtime.h>
#include <mudlib.h>
#define CHECK_TIME	60


mapping games = ([
	"1":	([
		"name"		: "���籭�ھ�����",
		"status"	: 0,
		"starttime"	: 1022663400,
		"endtime"	: 1023010200,
		"result"	: "",
		"key"		: ([ ]),
		"tgold"		: ([ ]),
		"texp"		: ([ ]),
		]),
	"2":	([
		"name"		: "���籭�й�����������",
		"status"	: 0,
		"starttime"	: 1022663400,
		"endtime"	: 1023172200,
		"result"	: "",
		"key"		: ([ ]),
		"tgold"		: ([ ]),
		"texp"		: ([ ]),
		]),
	]);
int igames = 10;

string * bet26hn;
string * bet26sy;
mapping bet26;

void check_games();
void check_user_game(object me);

void dobet26();
void init_bet26();
void check_bet26(object me);


string query(string arg)
{
	if (arg == "channel_id") return "ΤС��(Wei Xiaobao)";
}

string query_save_file()
{
	return "/data/lottery";
}

void remove()
{
	//save();
}

void create()
{
	seteuid(getuid());
	restore();
	call_out("check_games",CHECK_TIME);

	if( !bet26 ) {
		init_bet26();
		dobet26();
	}
}

int set_key1(int idx,string team,int odds)
{
	games[sprintf("%d",idx)]["key"][team] = odds;
	games[sprintf("%d",idx)]["tgold"][team] = 0;
	games[sprintf("%d",idx)]["texp" ][team] = 0;
	save();

	return 1;
}

int set_key2(string name,int starttime,int endtime,string team1,string team2,int odds1,int odds2,int goal1,int goal2)
{
	games[sprintf("%d",igames)] = ([
		"name"		: name,
		"starttime"	: starttime,
		"endtime"	: endtime,
		"key1"		: team1,
		"key2"		: team2,
		"odds1"		: odds1,
		"odds2"		: odds2,
		"goal1"		: goal1,
		"goal2"		: goal2,
		"status"	: 0,
		"result"	: "",
		"tgold1"	: 0,
		"texp1"		: 0,
		"tgold2"	: 0,
		"texp2"		: 0,
		]);
	igames++;
	save();

	return 1;
}

int set_result(int idx,string result)
{
	object * user;
	int i;
	string sidx,msg;

	sidx = sprintf("%d",idx);
	games[sidx]["result"] = result;
	games[sidx]["status"] = 3;
	save();

	if( idx < 10 )
		msg = "��"+CHINESE_D->chinese_number(idx)+"�����ʡ�"+games[sidx]["name"]+"�������ˣ����Ϊ��"+result+"����";
	else
		msg = "��"+CHINESE_D->chinese_number(idx)+"�����ʡ�"+games[sidx]["key1"]+"VS"+games[sidx]["key2"]+"�������ˣ����Ϊ��"+result+"�򡱣�";
	message("channel", "\r"+HIW+query("channel_id")+"������Х����"+msg+"��\n"NOR,users());

	user = users();
	for(i=0;i<sizeof(user);i++)
		check_user_game(user[i]);

	return 1;
}

void check_games()
{
	string * sk;
	mapping * sv;
	string msg;
	int i,idx;

	sk = keys(games);
	sv = values(games);
	for(i=0;i<sizeof(sk);i++) {
		if( sv[i]["status"]==0 && sv[i]["starttime"]<time() ) {
			sv[i]["status"] = 1;

			sscanf(sk[i],"%d",idx);
			if( idx < 10 )
				msg = "��"+CHINESE_D->chinese_number(idx)+"�����ʡ�"+sv[i]["name"]+"����ʼͶע�ˣ��쵽�������ķ�����ע����";
			else
				msg = "��"+CHINESE_D->chinese_number(idx)+"�����ʡ�"+sv[i]["key1"]+"VS"+sv[i]["key2"]+"����ʼͶע�ˣ��쵽�������ķ�����ע����";
			message("channel", "\r"+HIW+query("channel_id")+"������Х����"+msg+"��\n"NOR,users());
		}
		if( sv[i]["status"]==1 && sv[i]["endtime"]<time() ) {
			sv[i]["status"] = 2;
		}
	}
	save();

	remove_call_out("check_games");
	call_out("check_games",CHECK_TIME);
}

void delete_game(string idx)
{
	map_delete(games,idx);
	save();
}

void debug_info(object me,string type)
{
	if( type == "games" )
		tell_object(me,sprintf("games: %O\n",games));
	else if( type == "bet26" )
		tell_object(me,sprintf("bet26: %O\n",bet26));
	else if( type == "bet26hn" )
		tell_object(me,sprintf("bet26hn: %O\n",bet26hn));
	else if( type == "bet26sy" )
		tell_object(me,sprintf("bet26sy: %O\n",bet26sy));
	else
		tell_object(me,"û�д����ĵ�����Ϣ��\n");
}


protected string str_goal(int goal)
{
	string msg;
	int i;

	if( goal == 0 ) return "ƽ��";

	msg = "";
	i = goal / 100;
	if( i )	msg += CHINESE_D->chinese_number(goal/100) + "��";
	if( (goal%100) > 0 ) msg += "��";
	if( !i ) msg += "��";

	return msg;
}

protected string str_time(int date)
{
	mixed *local;
	local = localtime(date);
	return sprintf("%1d��%2d��%2dʱ%2d��",local[LT_MON]+1,local[LT_MDAY],local[LT_HOUR],local[LT_MIN]);
}

string list(int type)
{
	string * sk;
	mapping * sv;
	string * sk2;
	int * sv2;
	int i,j,a,b;
	string goal,msg;

	sk = keys(games);
	sv = values(games);
	j = sizeof(sk);

	if( type == 1 )
		msg = "Ŀǰ����Ͷע�Ĳ����У�\n";
	else if( type == 2 )
		msg = "Ŀǰ�Ѿ�����Ͷע���ڽ��б����Ĳ����У�\n";
	else
		msg = "Ŀǰ�Ѿ������Ĳ����У�\n";

	for(i=0;i<j;i++) {
		if( sv[i]["status"] != type ) continue;
		if( strlen(sk[i]) > 1 ) continue;

		msg += CYN"���ʳ��Σ�"+sk[i]+"    ������Ŀ��"+sv[i]["name"] + "    Ͷע����ʱ�䣺"+str_time(sv[i]["endtime"])+"    ���ʣ�"NOR;
		sk2 = keys(sv[i]["key"]);
		sv2 = values(sv[i]["key"]);
		b = sizeof(sk2);
		for(a=0;a<b;a++) {
			if( (a%4) == 0 ) msg += "\n";
			msg += sprintf("%-10s��%3d.%1d      ",sk2[a],sv2[a]/100,(sv2[a]/10)%10);
		}
		msg += "\n";
		if( type == 3 ) msg += "�����"+sv[i]["result"]+"\n\n";
	}

	msg += CYN"\n���ʳ���  ���ʽ���Ͷעʱ��  �������һ  ����      ����      ����  ������Ӷ�";
	if( type == 3 ) msg += "  ���";
	msg += "\n"NOR;

	for(i=0;i<j;i++) {
		if( sv[i]["status"] != type ) continue;
		if( strlen(sk[i]) < 2 ) continue;

		goal = str_goal(sv[i]["goal1"]) + ( (sv[i]["goal2"]>=0)?("/"+str_goal(sv[i]["goal2"])):"" );
		msg += sprintf("%-8s  %-16s  %-10s  %1d.%02d  %-12s  %1d.%02d  %-10s",
			sk[i],str_time(sv[i]["endtime"]),
			sv[i]["key1"],sv[i]["odds1"]/100,sv[i]["odds1"]%100,
			goal,
			sv[i]["odds2"]/100,sv[i]["odds2"]%100,sv[i]["key2"]
			);
		if( type == 3 ) msg += "  "+sv[i]["result"];
		msg += "\n";
	}
	msg += "\n";

	return msg;
}

string buy(object me,int idx,string team,int exp,int gold)
{
	string sidx;
	mapping mp = ([ "key":"", "exp":0, "gold":0 ]);

 	sidx = sprintf("%d",idx);
	if( !mapp(games[sidx]) )
		return "�������ⳡ���ʡ�";
	if( games[sidx]["status"] < 1  )
		return "�ⳡ���ʻ�û�п�ʼ��";
	if( games[sidx]["status"] > 1  )
		return "�ⳡ�����Ѿ�����Ͷע�ˡ�";

	mp["key"] = team;
	mp["exp"] = exp;
	mp["gold"] = gold;

	if( idx < 10 ) {
		if( !mapp(me->query("fifa/"+sidx+"a")) )
			me->set("fifa/"+sidx+"a",copy(mp));
		else if( !mapp(me->query("fifa/"+sidx+"b")) )
			me->set("fifa/"+sidx+"b",copy(mp));
		else if( !mapp(me->query("fifa/"+sidx+"c")) )
			me->set("fifa/"+sidx+"c",copy(mp));
		else
			return "���Ѿ����ⳡ������Ͷע�ˡ�";
		if( games[sidx]["key"][team] == 0 )
			return "û�����Ͷע��Ŀ��";

		games[sidx]["tgold"][team] += gold;
		games[sidx]["texp" ][team] += exp;
	}
	else {
		if( mapp(me->query("fifa/"+sidx)) )
			return "���Ѿ����ⳡ������Ͷע�ˡ�";

		if( team == games[sidx]["key1"] ) {
			games[sidx]["tgold1"] += gold;
			games[sidx]["texp1"]  += exp;
		}
		else if( team == games[sidx]["key2"] ) {
			games[sidx]["tgold2"] += gold;
			games[sidx]["texp2"]  += exp;
		}
		else
			return "û�����Ͷע��Ŀ��";

		me->set("fifa/"+sidx,copy(mp));
	}
	save();

	log_file( "lottery/bet", sprintf("%-8s;i:%-2d;t:%-10s;g:%-3d;e:%-6d",me->query("id"),idx,team,gold,exp) );
	return "";
}

protected int calc_result(int r,string i,int goal,string key)
{
	if( r < goal ) {
		if( key == games[i]["key2"] )
			return 100 + games[i]["odds2"];
	}
	else if( r == goal ) {
		return 100;
	}
	else {
		if( key == games[i]["key1"] )
			return 100 + games[i]["odds1"];
	}
	return 0;
}

void check_user_game(object me)
{
	string * sk;
	mapping * sv;
	int i,j,k,r,gold,exp;
	string msg;

	if( !me ) return;

/*
	sk = keys(games);
	sv = values(games);
	j = sizeof(sk);
	msg = CYN+BLINK+"\n�������ڽ������籭���ʻ���뵽�������ĳ���ע��\n"NOR+CYN"���ڿ���Ͷע�ĵ��������У�\n";
	for(i=0;i<j;i++) {
		if( sv[i]["status"] != 1 ) continue;
		if( strlen(sk[i]) < 2 ) continue;
		msg += sprintf("%-8s  %10s VS %-10s\n",sk[i],sv[i]["key1"],sv[i]["key2"]);
	}
	msg += "\n"NOR;
	write(msg);
*/

	check_bet26(me);

	if( !mapp(me->query("fifa")) ) return;

	sk = copy(keys(me->query("fifa")));
	sv = copy(values(me->query("fifa")));
	j = sizeof(sk);
	for(i=0;i<j;i++) {
		if( strlen(sk[i]) < 2 ) continue;
		k = 0;
		if( sk[i][1]=='a' || sk[i][1]=='b' || sk[i][1]=='c' ) {
			if( games[sk[i][0..0]]["status"] != 3 ) continue;
			if( sv[i]["key"] == games[sk[i][0..0]]["result"] )
				k = games[sk[i][0..0]]["key"][sv[i]["key"]];
			msg = "\n��"+sk[i][0..0]+"�����ʽ����ˣ����Ϊ"+games[sk[i][0..0]]["result"]+"��";
		}
		else {
			if( undefinedp(games[sk[i]]) ) {
				me->delete("fifa/"+sk[i]);
				me->save();
				continue;
			}
			if( games[sk[i]]["status"] != 3 ) continue;
			if( sscanf(games[sk[i]]["result"],"%d",r) < 1 ) continue;
			k = calc_result(r*100,sk[i],games[sk[i]]["goal1"],sv[i]["key"]);
			if( games[sk[i]]["goal2"] >= 0 ) {
				k += calc_result(r*100,sk[i],games[sk[i]]["goal2"],sv[i]["key"]);
				k /= 2;
			}
			msg = "\n��"+sk[i]+"�����ʽ����ˣ����Ϊ"+CHINESE_D->chinese_number(r)+"��";
		}

		gold = sv[i]["gold"] * (k-100) / 100;
		exp  = sv[i]["exp" ] * (k-100) / 100;
		if( gold > 100000 ) gold = 100000;
		if( exp > 1000000 ) exp = 1000000;

		if( sv[i]["gold"] != 0 ) {
			if( gold < 0 ) msg += "�������ʣ��㹲����ƽ�"+CHINESE_D->chinese_number(-gold)+"����\n";
			else if( gold > 0 ) msg += "�������ʣ��㹲��òʽ�"+CHINESE_D->chinese_number(gold)+"����\n";
			else msg += "�������ʣ��㲻����׬��\n";
		}
		else {
			if( exp < 0 ) msg += "�������ʣ��㹲����ս������"+CHINESE_D->chinese_number(-exp)+"�㡣\n";
			else if( exp > 0 ) msg += "�������ʣ��㹲Ӯȡս������"+CHINESE_D->chinese_number(exp)+"�㡣\n";
			else msg += "�������ʣ��㲻����׬��\n";
		}
		tell_object(me,msg);

		me->add("fifawin/gold",gold);
		me->add("fifawin/exp",exp);
		log_file( "lottery/result", sprintf("%-8s;i:%-2s;g:%-3d;e:%-6d;g:%-5d;e:%-8d;e:%8d;g:%d",
			me->query("id"),sk[i],sv[i]["gold"],sv[i]["exp"],gold,exp,me->query("fifawin/exp"),me->query("fifawin/gold")) );

		me->add("balance",	(sv[i]["gold"]+gold)*10000);
		me->add("combat_exp",	exp );
		if( me->query("combat_exp") < 0 ) me->set("combat_exp",0);
		me->delete("fifa/"+sk[i]);
		me->save();
	}
}

string check(object me)
{
	string * sk;
	mapping * sv;
	int i,j;
	string msg,sidx;

	if( !mapp(me->query("fifa")) || sizeof(me->query("fifa"))<1 )
		return "�㲢û���ڱ��ĳ���ע����";

	sk = keys(me->query("fifa"));
	sv = values(me->query("fifa"));
	j = sizeof(sk);
	msg = "���ڱ��ĳ���ע�ĳ����У�\n";

	for(i=0;i<j;i++) {
		if( sk[i][1]=='a' || sk[i][1]=='b' || sk[i][1]=='c' ) {
			sidx = sk[i][0..0];
			msg += sprintf("���Σ�%-2s  ��Ŀ��%-22s  Ͷע����%-12s  Ͷע%s��%-6d\n",sidx,games[sidx]["name"],sv[i]["key"],
					(sv[i]["gold"]>0?"�ƽ�":"����"),(sv[i]["gold"]>0?sv[i]["gold"]:sv[i]["exp"]) );
		}
		else {
			if( undefinedp(games[sk[i]]) ) continue;
			sidx = sk[i];
			msg += sprintf("���Σ�%-2s  ��Ŀ��%-22s  Ͷע����%-12s  Ͷע%s��%-6d\n",sidx,games[sidx]["key1"]+"VS"+games[sidx]["key2"],sv[i]["key"],
					(sv[i]["gold"]>0?"�ƽ�":"����"),(sv[i]["gold"]>0?sv[i]["gold"]:sv[i]["exp"]) );
		}
	}

	return msg;
}

void check_bet26(object me)
{
	string u = me->query("id");
	int e,g;

	if( undefinedp(bet26[u]) ) return;
	if( bet26[u]["key"] == "�й�" ) {
		e = -bet26[u]["exp" ]*7/10;
		g = -bet26[u]["gold"]*7/10;
	}
	else {
		e = bet26[u]["exp" ]*7/10;
		g = bet26[u]["gold"]*7/10;
	}

	me->add("combat_exp",	e);
	me->add("balance",	g*10000);
	me->add("fifawin/exp",e);
	me->add("fifawin/gold",g);
	if( me->query("balance") < 0 ) me->set("balance",0);

	tell_object(me,"���籭���ʵ�26�����й�VS�����������ˣ������4��\n����"+
		CHINESE_D->chinese_number(g)+"���ƽ�"+
		CHINESE_D->chinese_number(e)+"�㾭�顣\n");
	log_file("lottery/bet26", sprintf("u:%-8s;k:%s;g:%-5d;e:%6d",u,bet26[u]["key"],bet26[u]["gold"],bet26[u]["exp"]));
	map_delete(bet26,u);
	save();
}

void dobet26()
{
	int i,j;
	string str;
	string * s;
	string t1,u,k;
	string * t2;
	int g,e;

	bet26 = ([ ]);

	if( INTERMUD_MUD_NAME == "BX" )
		j = sizeof(bet26hn);
	else
		j = sizeof(bet26sy);

	for(i=0;i<j;i++) {
		if( INTERMUD_MUD_NAME == "BX" )
			str = bet26hn[i];
		else
			str = bet26sy[i];
		s = explode(str,";");

		if( sscanf(s[1],"%s",t1)<1) continue;
		t2 = explode(t1," ");
		u = t2[0];

		if( sscanf(s[3],"t:%s",t1)<1) continue;
		t2 = explode(t1," ");
		k = t2[0];

		if( sscanf(s[4],"g:%d",g)<1) continue;
		if( sscanf(s[5],"e:%d",e)<1) continue;

		//tell_object(find_player("augx"),sprintf("%s,%s,%d,%d\n",u,k,g,e));

		bet26[u] = ([
			"key"	:	k,
			"gold"	:	g,
			"exp"	:	e,
		]);
	}

	bet26hn = bet26sy = 0;
	save();
}

void init_bet26()
{
	bet26hn = ({
"Sat Jun  8 19:25:54 ;shenlong;i:26;t:�й�      ;g:0  ;e:100000",
"Sat Jun  8 19:08:25 ;duxin   ;i:26;t:�й�      ;g:0  ;e:50000",
"Sat Jun  8 18:48:51 ;wangll  ;i:26;t:�й�      ;g:0  ;e:10000",
"Sat Jun  8 18:15:15 ;ggk     ;i:26;t:����      ;g:0  ;e:100000",
"Sat Jun  8 17:42:47 ;amy     ;i:26;t:�й�      ;g:0  ;e:100000",
"Sat Jun  8 17:01:06 ;zhaohao ;i:26;t:����      ;g:300;e:0",
"Sat Jun  8 16:29:43 ;yuikt   ;i:26;t:�й�      ;g:0  ;e:20000",
"Sat Jun  8 16:29:20 ;axiong  ;i:26;t:�й�      ;g:200;e:0",
"Sat Jun  8 16:25:50 ;babyblue;i:26;t:����      ;g:350;e:0",
"Sat Jun  8 16:25:38 ;wanguliu;i:26;t:�й�      ;g:0  ;e:100000",
"Sat Jun  8 16:18:06 ;yiran   ;i:26;t:����      ;g:0  ;e:30000",
"Sat Jun  8 15:08:18 ;only    ;i:26;t:����      ;g:0  ;e:100000",
"Sat Jun  8 15:02:26 ;cnunicom;i:26;t:�й�      ;g:0  ;e:100000",
"Sat Jun  8 14:55:58 ;mongols ;i:26;t:�й�      ;g:0  ;e:100000",
"Sat Jun  8 14:06:57 ;tree    ;i:26;t:����      ;g:0  ;e:30000",
"Sat Jun  8 13:47:11 ;bbstal  ;i:26;t:����      ;g:0  ;e:80000",
"Sat Jun  8 13:30:39 ;miluo   ;i:26;t:�й�      ;g:0  ;e:100000",
"Sat Jun  8 13:30:01 ;xiaoxiao;i:26;t:�й�      ;g:0  ;e:100000",
"Sat Jun  8 13:29:21 ;city    ;i:26;t:�й�      ;g:0  ;e:100000",
"Sat Jun  8 12:36:30 ;wqwa    ;i:26;t:�й�      ;g:0  ;e:70000",
"Sat Jun  8 12:21:03 ;sophidia;i:26;t:�й�      ;g:0  ;e:20000",
"Sat Jun  8 12:20:08 ;martix  ;i:26;t:�й�      ;g:0  ;e:35000",
"Sat Jun  8 12:10:56 ;skkevin ;i:26;t:����      ;g:0  ;e:20000",
"Sat Jun  8 12:07:29 ;terrific;i:26;t:�й�      ;g:0  ;e:6000",
"Sat Jun  8 11:38:08 ;cdj     ;i:26;t:����      ;g:0  ;e:50000",
"Sat Jun  8 10:36:15 ;alfios  ;i:26;t:����      ;g:0  ;e:45000",
"Sat Jun  8 09:35:18 ;vaco    ;i:26;t:�й�      ;g:0  ;e:100000",
"Sat Jun  8 08:48:25 ;legend  ;i:26;t:����      ;g:0  ;e:10000",
"Sat Jun  8 08:22:53 ;rsun    ;i:26;t:����      ;g:0  ;e:70000",
"Sat Jun  8 08:04:18 ;missluo ;i:26;t:�й�      ;g:0  ;e:100000",
"Sat Jun  8 02:17:29 ;religion;i:26;t:����      ;g:0  ;e:50000",
"Sat Jun  8 00:24:56 ;fair    ;i:26;t:����      ;g:0  ;e:100000",
"Sat Jun  8 00:19:10 ;mental  ;i:26;t:����      ;g:0  ;e:28000",
"Fri Jun  7 23:30:55 ;wyss    ;i:26;t:�й�      ;g:3000;e:0",
"Fri Jun  7 23:22:31 ;sdfg    ;i:26;t:�й�      ;g:0  ;e:100000",
"Fri Jun  7 23:00:00 ;zfeng   ;i:26;t:����      ;g:0  ;e:100000",
"Fri Jun  7 22:24:13 ;lane    ;i:26;t:�й�      ;g:0  ;e:3000",
"Fri Jun  7 22:02:14 ;bluehawk;i:26;t:�й�      ;g:0  ;e:66000",
"Fri Jun  7 22:00:05 ;vincent ;i:26;t:�й�      ;g:0  ;e:50000",
"Fri Jun  7 21:57:52 ;smart   ;i:26;t:�й�      ;g:0  ;e:80000",
"Fri Jun  7 21:37:24 ;xianzi  ;i:26;t:����      ;g:0  ;e:17000",
"Fri Jun  7 21:31:04 ;maianui ;i:26;t:�й�      ;g:0  ;e:40000",
"Fri Jun  7 19:16:36 ;mario   ;i:26;t:����      ;g:0  ;e:20000",
"Fri Jun  7 19:14:56 ;think   ;i:26;t:�й�      ;g:0  ;e:20000",
"Fri Jun  7 18:50:05 ;playboy ;i:26;t:�й�      ;g:0  ;e:10000",
"Fri Jun  7 18:36:07 ;fuxiao  ;i:26;t:����      ;g:157;e:0",
"Fri Jun  7 18:00:46 ;action  ;i:26;t:����      ;g:0  ;e:100000",
"Fri Jun  7 18:00:36 ;longfeng;i:26;t:����      ;g:0  ;e:100000",
"Fri Jun  7 17:06:42 ;muder   ;i:26;t:����      ;g:0  ;e:100000",
"Fri Jun  7 17:02:58 ;biaofeng;i:26;t:�й�      ;g:0  ;e:100000",
"Fri Jun  7 17:00:34 ;ptz     ;i:26;t:����      ;g:0  ;e:100000",
"Fri Jun  7 16:48:29 ;cooky   ;i:26;t:����      ;g:0  ;e:10000",
"Fri Jun  7 16:47:07 ;wxw     ;i:26;t:����      ;g:0  ;e:100000",
"Fri Jun  7 16:46:11 ;liumu   ;i:26;t:����      ;g:0  ;e:100000",
"Fri Jun  7 16:45:21 ;gmll    ;i:26;t:����      ;g:0  ;e:100000",
	});

	bet26sy = ({
"Sat Jun  8 19:43:57 ;susu    ;i:26;t:�й�      ;g:0  ;e:100000",
"Sat Jun  8 18:54:43 ;zcz     ;i:26;t:�й�      ;g:0  ;e:100000",
"Sat Jun  8 17:39:31 ;gucci   ;i:26;t:����      ;g:400;e:0",
"Sat Jun  8 16:17:31 ;lpinkpig;i:26;t:����      ;g:0  ;e:20000",
"Sat Jun  8 15:51:50 ;zxcvbnm ;i:26;t:�й�      ;g:0  ;e:100000",
"Sat Jun  8 14:53:29 ;sable   ;i:26;t:�й�      ;g:0  ;e:100000",
"Sat Jun  8 13:24:47 ;wwd     ;i:26;t:�й�      ;g:0  ;e:100000",
"Sat Jun  8 13:09:20 ;lengbing;i:26;t:�й�      ;g:1000;e:0",
"Sat Jun  8 13:08:20 ;jdzxgmwz;i:26;t:�й�      ;g:0  ;e:100000",
"Sat Jun  8 12:56:05 ;wyang   ;i:26;t:����      ;g:10 ;e:0",
"Sat Jun  8 12:50:35 ;wangy   ;i:26;t:�й�      ;g:25 ;e:0",
"Sat Jun  8 12:24:00 ;bbman   ;i:26;t:����      ;g:0  ;e:100000",
"Sat Jun  8 12:12:07 ;huanle  ;i:26;t:����      ;g:0  ;e:10000",
"Sat Jun  8 11:50:22 ;hert    ;i:26;t:�й�      ;g:0  ;e:80000",
"Sat Jun  8 11:31:56 ;goting  ;i:26;t:����      ;g:0  ;e:20000",
"Sat Jun  8 11:27:00 ;lovesx  ;i:26;t:����      ;g:0  ;e:10000",
"Sat Jun  8 10:55:13 ;zhd     ;i:26;t:����      ;g:0  ;e:70000",
"Sat Jun  8 10:45:42 ;luoxue  ;i:26;t:�й�      ;g:0  ;e:100000",
"Sat Jun  8 10:23:52 ;lilian  ;i:26;t:����      ;g:1000;e:0",
"Sat Jun  8 10:20:28 ;hmm     ;i:26;t:����      ;g:0  ;e:100000",
"Sat Jun  8 10:04:00 ;bdp     ;i:26;t:����      ;g:0  ;e:98000",
"Sat Jun  8 09:36:31 ;lvbu    ;i:26;t:����      ;g:0  ;e:70000",
"Sat Jun  8 09:02:16 ;tying   ;i:26;t:�й�      ;g:0  ;e:10000",
"Sat Jun  8 06:28:15 ;passwds ;i:26;t:����      ;g:0  ;e:100000",
"Sat Jun  8 06:03:59 ;slw     ;i:26;t:�й�      ;g:0  ;e:100000",
"Sat Jun  8 05:22:38 ;zlxcy   ;i:26;t:�й�      ;g:0  ;e:70000",
"Sat Jun  8 03:16:17 ;bluemary;i:26;t:�й�      ;g:0  ;e:5000",
"Sat Jun  8 01:38:59 ;jiajia  ;i:26;t:�й�      ;g:0  ;e:10000",
"Sat Jun  8 01:12:23 ;dracula ;i:26;t:����      ;g:0  ;e:10000",
"Sat Jun  8 00:05:43 ;mirale  ;i:26;t:����      ;g:0  ;e:100000",
"Fri Jun  7 23:44:54 ;wsjking ;i:26;t:����      ;g:0  ;e:50000",
"Fri Jun  7 23:18:27 ;xiaolong;i:26;t:�й�      ;g:0  ;e:41000",
"Fri Jun  7 23:18:13 ;gdg     ;i:26;t:�й�      ;g:0  ;e:57000",
"Fri Jun  7 23:11:27 ;fanghs  ;i:26;t:�й�      ;g:0  ;e:95540",
"Fri Jun  7 22:55:22 ;runy    ;i:26;t:�й�      ;g:0  ;e:100000",
"Fri Jun  7 22:55:02 ;maxwell ;i:26;t:����      ;g:0  ;e:100000",
"Fri Jun  7 22:34:05 ;xubint  ;i:26;t:����      ;g:0  ;e:100000",
"Fri Jun  7 22:34:01 ;jiejie  ;i:26;t:�й�      ;g:0  ;e:100000",
"Fri Jun  7 22:06:40 ;net     ;i:26;t:����      ;g:0  ;e:100000",
"Fri Jun  7 21:51:09 ;symbol  ;i:26;t:�й�      ;g:0  ;e:60000",
"Fri Jun  7 21:47:01 ;tlx     ;i:26;t:�й�      ;g:0  ;e:100000",
"Fri Jun  7 21:44:45 ;babycat ;i:26;t:����      ;g:0  ;e:75000",
"Fri Jun  7 21:43:23 ;fhun    ;i:26;t:�й�      ;g:0  ;e:100000",
"Fri Jun  7 21:42:41 ;gzyelang;i:26;t:�й�      ;g:0  ;e:30000",
"Fri Jun  7 21:41:31 ;yjxsw   ;i:26;t:�й�      ;g:0  ;e:100000",
"Fri Jun  7 21:40:22 ;ysy     ;i:26;t:�й�      ;g:0  ;e:100000",
"Fri Jun  7 21:39:34 ;hairll  ;i:26;t:����      ;g:40 ;e:0",
"Fri Jun  7 21:37:44 ;spp     ;i:26;t:����      ;g:0  ;e:40000",
"Fri Jun  7 21:36:44 ;zlong   ;i:26;t:����      ;g:0  ;e:100000",
"Fri Jun  7 21:31:03 ;mikle   ;i:26;t:�й�      ;g:0  ;e:100000",
"Fri Jun  7 21:29:53 ;glos    ;i:26;t:����      ;g:0  ;e:20000",
"Fri Jun  7 21:29:33 ;nani    ;i:26;t:�й�      ;g:0  ;e:100000",
"Fri Jun  7 21:27:09 ;wxb     ;i:26;t:����      ;g:0  ;e:100000",
"Fri Jun  7 21:21:20 ;weisher ;i:26;t:����      ;g:0  ;e:100000",
"Fri Jun  7 21:19:34 ;fengqing;i:26;t:����      ;g:0  ;e:85000",
"Fri Jun  7 20:37:51 ;ohan    ;i:26;t:�й�      ;g:0  ;e:60000",
"Fri Jun  7 19:47:03 ;pingping;i:26;t:�й�      ;g:0  ;e:80000",
"Fri Jun  7 19:19:06 ;router  ;i:26;t:����      ;g:0  ;e:100000",
"Fri Jun  7 19:17:18 ;wangyang;i:26;t:�й�      ;g:0  ;e:100000",
"Fri Jun  7 19:14:58 ;gmly    ;i:26;t:����      ;g:0  ;e:10000",
"Fri Jun  7 19:13:54 ;stefsun ;i:26;t:�й�      ;g:0  ;e:50000",
"Fri Jun  7 19:09:31 ;welcome ;i:26;t:�й�      ;g:0  ;e:100000",
"Fri Jun  7 19:08:53 ;xwd     ;i:26;t:�й�      ;g:0  ;e:100000",
"Fri Jun  7 19:06:03 ;yuyuz   ;i:26;t:����      ;g:0  ;e:10000",
"Fri Jun  7 19:01:15 ;tlslover;i:26;t:�й�      ;g:0  ;e:100000",
"Fri Jun  7 18:56:45 ;madge   ;i:26;t:����      ;g:0  ;e:100000",
"Fri Jun  7 18:52:17 ;tudou   ;i:26;t:�й�      ;g:0  ;e:45000",
"Fri Jun  7 18:47:08 ;axue    ;i:26;t:�й�      ;g:0  ;e:100000",
"Fri Jun  7 18:40:00 ;iii     ;i:26;t:����      ;g:0  ;e:100000",
"Fri Jun  7 18:39:56 ;bluesky ;i:26;t:�й�      ;g:17 ;e:0",
"Fri Jun  7 18:37:52 ;joe     ;i:26;t:�й�      ;g:0  ;e:100000",
"Fri Jun  7 18:23:57 ;yangz   ;i:26;t:�й�      ;g:0  ;e:85000",
"Fri Jun  7 18:14:55 ;yangzzz ;i:26;t:����      ;g:0  ;e:5000",
"Fri Jun  7 17:52:20 ;mulan   ;i:26;t:����      ;g:0  ;e:9000",
"Fri Jun  7 17:08:31 ;kelly   ;i:26;t:�й�      ;g:0  ;e:100000",
"Fri Jun  7 17:07:59 ;angles  ;i:26;t:�й�      ;g:0  ;e:100000",
"Fri Jun  7 17:06:45 ;yemao   ;i:26;t:�й�      ;g:0  ;e:100000",
"Fri Jun  7 17:06:30 ;tianyi  ;i:26;t:�й�      ;g:0  ;e:100000",
"Fri Jun  7 17:03:18 ;meimeid ;i:26;t:�й�      ;g:0  ;e:100000",
"Fri Jun  7 16:57:08 ;pix     ;i:26;t:�й�      ;g:0  ;e:50000",
"Fri Jun  7 16:55:16 ;cityboy ;i:26;t:����      ;g:0  ;e:100000",
"Fri Jun  7 16:54:54 ;bff     ;i:26;t:����      ;g:0  ;e:50000",
"Fri Jun  7 16:49:12 ;akun    ;i:26;t:����      ;g:0  ;e:54927",
	});
}


/*
inherit F_SAVE;
#include <ansi.h>
#define PRICE 20000
#define DUR 10800

string query(string arg)
{
	if (arg == "channel_id")
		return "ΤС��(Wei Xiaobao)";
}

string query_save_file()
{
	return "/data/lottery";
}

int t;

void remove()
{
	t = find_call_out("kaijiang");
	save();
}

void create()
{
	seteuid(getuid());
	restore();
	if (t)
		call_out("kaijiang", t < DUR?t:DUR);
	else
		call_out("finish", 1);
}

int generation = 1;
int last_award;
int award, no1;
int count1, award1, c1;
int count2, award2, c2;
int count3, award3, c3;

mapping total = ([
]);
int flag;

private number(int num)
{
	return chinese_number(num/1000%10)+chinese_number(num/100%10)
	+chinese_number(num/10%10)+chinese_number(num%10);
}

void purchase(mixed me, int num, int qty)
{
	if (!objectp(me))
		return;
	if (flag) {
		tell_object(me, "���ڿ������ȵȰɡ�\n");
		return;
	}
	if (qty < 1) {
		tell_object(me, "�������ţ�\n");
		return;
	}
	if (qty > 10000 || !me->query("lottery/"+generation+"/"+num) && sizeof(me->query("lottery/"+generation)) > 9) {
		tell_object(me, "�����������˰ɡ�\n");
		return;
	}
	if (num < 0 || num > 9999) {
		tell_object(me, "��ѡ����λ����(0000-9999)��\n");
		return;
	}
	switch (MONEY_D->player_pay(me, PRICE*qty)) {
		case 0:
		case 2:
			tell_object(me, "�����Ǯ������\n");
			return;
	}
	me->add("lottery/"+generation+"/"+num, qty);
	me->save();
	total[num] += qty;
	award += qty*PRICE;
	save();
	message_vision(
		sprintf("$N��%s�Ų�Ʊ��д�¡�"+HIW+"%s"+NOR+"���ĸ����֣�Ȼ�󽻸����С�ĵ��պá�\n",
			chinese_number(qty), number(num)
		), me
	);
}

private int check(int n1, int n2)
{
	string tmp1 = sprintf("%04d", n1), tmp2 = sprintf("%04d", n2);
	int i, k = 0;

	for (i = 0; i < 4; i++)
		k += tmp1[i] == tmp2[i];
	return k;
}

void show_now(mixed me)
{
	int i, n;
	mapping tmp, tmp2;

	if (!objectp(me))
		return;
	if (flag) {
		tell_object(me, "���ڿ������ȵȰɡ�\n");
		return;
	}
	tmp = me->query("lottery");
	if (!sizeof(tmp)) {
		tell_object(me, "��Ŀǰû���κβ�Ʊ��\n");
		return;
	}
	tell_object(me, "��Ʒ��˷���Ʊ�ǼǱ���˵��������\n");
	foreach (string gen in sort_array(keys(tmp),0)) {
		tmp2 = tmp[gen];
		if (!sizeof(tmp2))
			continue;
		if (atoi(gen) < generation-1 || atoi(gen) > generation) {
			tell_object(me, "һЩ���ڵĵ�"+chinese_number(atoi(gen))+"�ڲ�Ʊ������������ˡ�\n");
			map_delete(tmp, gen);
		} else
			foreach (string num in sort_array(keys(tmp2),0)) {
				i = atoi(gen);
				n = atoi(num);
				tell_object(me,
					sprintf("%s�ŵ�%s�ڲ�Ʊ������д�š�"+HIW+"%s"+NOR+"��",
						chinese_number(tmp2[num]), chinese_number(i), number(n)
					)
				);
				if (i == generation-1) {
					switch (check(no1, n)) {
						case 4:
							n = tmp2[num] * award1 / 10 * 9;
							c1 += tmp2[num];
							last_award -= n / 9;
							tell_object(me, "����ϲ����ͷ��������˰�󽱽�"+MONEY_D->money_str(n));
							break;
						case 3:
							n = tmp2[num] * award2;
							c2 += tmp2[num];
							tell_object(me, "����ϲ���˶�������������"+MONEY_D->money_str(n));
							break;
						case 2:
							n = tmp2[num] * award3;
							c3 += tmp2[num];
							tell_object(me, "����ϲ������������������"+MONEY_D->money_str(n));
							break;
						default:
							n = 0;
							tell_object(me, "����ϧû���н�");
					}
					if (n) {
						MONEY_D->pay_player(me, n, 1);
						log_file("LOTTERY", me->query("name")+"��ý���"+MONEY_D->money_str(n), me);
						CHANNEL_D->do_channel(
							this_object(), "chat", "��ϲ"+me->query("name")+RANK_D->query_respect(me)+"��ý���"+MONEY_D->money_str(n)
						);
					}
					last_award -= n;
				}
				tell_object(me, "��\n");
				if (i == generation-1) {
					map_delete(tmp, gen);
					tell_object(me, "��Щ���ڵĲ�Ʊ������������ˡ�\n");
				}
			}
	}
	save();
	me->save();
}

string show_total()
{
	string str, ret;

	if (flag)
		return "���ڿ������ȵȰɡ�\n";

	str = sprintf(
		"�������۵�%s�ڲ�Ʊ��Ŀǰ�ۼƽ���%s���뿪������%s��ʱ��\n"
		"���ڽ���%s���н����룺"+HIG+"%s"+NOR+"\n"
		"%s\n"
		"%s\n"
		"%s\n",
		chinese_number(generation),
		award?MONEY_D->money_str(award):"��",
		chinese_number((find_call_out("kaijiang")+119)/120),
		last_award?"��ʣ"+MONEY_D->money_str(last_award):"��ȫ������",
		number(no1),
		count1?chinese_number(count1)+"ע��ͷ����ÿע����"+MONEY_D->money_str(award1):"ͷ��������",
		count2?chinese_number(count2)+"ע�ж�����ÿע����"+MONEY_D->money_str(award2):"����������",
		count3?chinese_number(count3)+"ע��������ÿע����"+MONEY_D->money_str(award3):"����������"
	);
	ret = "\n";

	foreach (string item in explode(str, "\n"))
		ret += sprintf("%|78s\n", item);
	return ret;
}

private void tongji()
{
	int i;

	count1 = count2 = count3 = 0;
	award1 = award2 = award3 = 0;
	c1 = c2 = c3 = 0;
	if (!sizeof(total))
		return;
	foreach (i in keys(total)) {
		switch (check(i, no1)) {
			case 4:
				count1 += total[i];
				break;
			case 3:
				count2 += total[i];
				break;
			case 2:
				count3 += total[i];
		}
	}
	if (count1)
		award1 = last_award / 2 / count1;
	if (count2)
		award2 = last_award / 10 * 3 / count2;
	if (count3)
		award3 = last_award / 10 * 2 / count3;
}

private void kaijiang()
{
	flag = 1;
	CHANNEL_D->do_channel(this_object(),
		"chat", "��"+chinese_number(generation)+"�ڲ�Ʊ���������λ׼���ñ�īֽ�⣡"
	);
	if (last_award)
		CHANNEL_D->do_channel(this_object(),
			"chat", "����ʣ�ཱ��"+MONEY_D->money_str(last_award)+"���뱾�ڣ�"
		);
	call_out("k1", 3);
}

private void k1()
{
	int i = random(10);

	no1 = i*1000;
	CHANNEL_D->do_channel(this_object(), "chat", "��һλ������ "+chinese_number(i));
	call_out("k2", 1);
}

private void k2()
{
	int i = random(10);

	no1 += i*100;
	CHANNEL_D->do_channel(this_object(), "chat", "�ڶ�λ������ "+chinese_number(i));
	call_out("k3", 1);
}

private void k3()
{
	int i = random(10);

	no1 += i*10;
	CHANNEL_D->do_channel(this_object(), "chat", "����λ������ "+chinese_number(i));
	call_out("k4", 1);
}

private void k4()
{
	int i = random(10);

	no1 += i;
	CHANNEL_D->do_channel(this_object(), "chat", "����λ������ "+chinese_number(i));
	call_out("k5", 1);
}

private void k5()
{
	CHANNEL_D->do_channel(this_object(), "chat",
		sprintf("��%s�ڲ�Ʊ�ĺ����� %s", chinese_number(generation++), number(no1))
	);
	call_out("finish", 2);
}

private void finish()
{
	int i;
	string result;

	last_award += award;
	award = 0;
	tongji();
	i = last_award / 10;
/ *
	if (!count1) {
		last_award -= i * 5;
		award += i * 5;
	}
	if (!count2) {
		last_award -= i * 3;
		award += i * 3;
	}
	if (!count3) {
		last_award -= i * 2;
		award += i * 2;
	}
* /
	total = ([ ]);
	flag = 0;
	save();
	call_out("kaijiang", DUR);
	result = replace_string(show_total(), " ", "");
	result = implode(explode(result, "\n"), "�� ");
	CHANNEL_D->do_channel(this_object(), "chat", result);
}
*/

       
