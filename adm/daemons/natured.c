// natured.c
// added reclaim and unique find. by snowman 28/10/1999
// optimized by Yuj 19991112

#include <ansi.h>
#include <mudlib.h>
#include <localtime.h>

// #define TIME_TICK (time()*60)
#define ANTIROBOT "/clone/npc/antirobotnew"
#define CALLOUT_TICK 30
#define DECLARE_FILE "/data/declare.txt"
#define TIME_TICK1 ((time()-900000000)*60)
nosave int current_day_phase, current_month;
mapping *day_phase;
string daytime = "";

string *month_time = ({
	"�������ĵ������ˣ�",
	"��������ط���������ӣ�",
	"�����𽥱�ů�ˣ�",
	"�Ѿ��ǳ���ʱ���ˣ�",
	"֪�˵Ľ�������о�����ʢ�ĵ���Ϣ��",
	"������÷ǳ����ȣ�",
	"��Ȼ�������ˣ�����������Щ�ȣ�",
	"����ѽڿ쵽�ˣ�",
	"һ����紵���������˵��ϵ���Ҷ��",
	"��ȥ������",
	"����������",
	"�쵽����ˣ�",
});
string *month_desc = ({
	"����һ��������",
	"����һ���紺���µ�",
	"����һ���������µ�",
	"����һ�����ĵ�",
	"����һ��ʢ�ĵ�",
	"����һ�����ĵ�",
	"����һ�������",
	"����һ�����յ�",
	"����һ�������",
	"����һ��������",
	"����һ��¡����",
	"����һ��������",
});

mapping *read_table(string file);
void init_day_phase();

//ȡ�õ�ǰ���·�
int query_month()       
{ 
	mixed *local;
	local = localtime(TIME_TICK);
	return (local[LT_MON]+1);	
}

/*void create()
{
	seteuid(getuid());
	day_phase = read_table("/adm/etc/nature/day_phase");
	init_day_phase();
}
*/

void create()
{	
	string get_month, get_day;
	mixed *local;
	seteuid(getuid());
	local = localtime(TIME_TICK1);
	get_day = CHINESE_D->chinese_number(local[1]);
	get_month = CHINESE_D->chinese_number(local[4]);
	switch(get_month)
	{
		//spring weather
		case "��":
		case "��":
		case "��":
		     switch(random(2))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/spring_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/spring_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/spring_wind");
			   break;
		     }
		     break;
		//summer weather
		case "��":
		case "��":
		case "��":
		     switch(random(2))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/summer_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/summer_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/summer_wind");
			   break;
		     }
		     break;
		//autumn weather
		case "��":
		case "ʮ":
		case "ʮһ":
		     switch(random(2))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/autumn_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/autumn_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/autumn_wind");
			   break;
		     }
		     break;
		//winter weather
		case "ʮ��":
		case "һ":
		case "��":
		     switch(random(2))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		     break;
		default:
		     day_phase = read_table("/adm/etc/nature/day_phase");
	}
	switch(get_day)
	{
		case "һ��һ��":
		     day_phase = read_table("/adm/etc/nature/spring");
		     break;
//		case "��������":
//		case "��������":
//		case "����ʮ����":
//		case "���¾���":
//		case "ʮ���°���":
	}
//	day_phase = read_table("/adm/etc/nature/day_phase");
	init_day_phase();
}

void init_day_phase()
{
	mixed *local;
	int i, t;

	// Get minutes of today.
	local = localtime(TIME_TICK);
	t = local[2] * 60 + local[1];
	current_month = local[4];

	// Find the day phase for now.
	for( i=0; i < sizeof(day_phase); i++)
		if( t >= day_phase[i]["length"] )
			t -= (int)day_phase[i]["length"];
		else break;

	current_day_phase = i;
	daytime = day_phase[current_day_phase]["event_fun"];

	// MUD ����ʱ����ˣ�ʱ�����ƫ������ǵ�������ÿСʱִ��һ��
	// Modify by Yu Jue 98-8-20
	i = time();
	remove_call_out("init_day_phase");
	call_out("init_day_phase", 3600 - i % 3600);

	// check reboot
	local = localtime(i);
        if (local[6] == 5 && uptime() > 72000) {
		if (local[2] < 8) {
			if (find_call_out("update_day_phase") != -1)
				message("channel",
					"\n\t"+CHINESE_MUD_NAME+"���ڱ���ʱ��˵����ŵ�֮���Զ�����������\n\n", users()
				);
		} else if (local[2] < 10)
			"/cmds/common/reboot"->main(this_object(), "10");
        }

	// Since in our time scale, 1 minute == 1 second in RL, so we don't need
	// any conversion before using this number as call_out dalay, if you
	// changed the time scale, be sure to convert it.
	remove_call_out("update_day_phase");
	call_out("update_day_phase",
		day_phase[current_day_phase]["length"] - t);
	remove_call_out("test_robot");
	call_out("test_robot", 20+random(CALLOUT_TICK));
	remove_call_out("find_unique");
	call_out("find_unique", 60+random(CALLOUT_TICK));
	// ����Ƶ������ʱ������Ϣ
//	remove_call_out("declare_channel");
//	call_out("declare_channel",1200);
}

void declare_channel()
{
	string s_declare,txt;
	int line=1,i,totle=0,j,k;
	mapping *obj=({ });

	call_out("declare_channel",1200);

	while( s_declare = read_file(DECLARE_FILE,line,1) ) {
		if( sscanf( s_declare, "�ı���%sȨֵ��%d",	txt,i ) == 2 ) {
			obj += ({ (["txt": txt, "weight": i]) });
			totle += i;
		}

		line ++;
	}

	if( totle == 0 ) return;
	j=random(totle)+1;
	i=0;k=0;
	while(i+obj[k]["weight"]<j) {
		i+=obj[k]["weight"];
		k++;
	}
	message("channel:declare", HIY "\n����Ϣ��"+ obj[k]["txt"]+"\n" NOR,users());
	return;
}

string query_daytime(){ return daytime; }

int is_night()
{
	switch(daytime){
		case "event_night":
		case "event_midnight":
			return 1;
		default: return 0;
	}
}

void update_day_phase()
{
	current_day_phase = (++current_day_phase) % sizeof(day_phase);
	if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
		call_other(this_object(), day_phase[current_day_phase]["event_fun"]);
	message("outdoor:vision", day_phase[current_day_phase]["time_msg"] + "\n" NOR, users());
	daytime = day_phase[current_day_phase]["event_fun"];
	remove_call_out("update_day_phase");
	call_out("update_day_phase", day_phase[current_day_phase]["length"]);

}

void event_noon()
{
        object *ob;
        object env;
        int    ic;
        int    con;
        int    month;
        string ill, msg;
        int    i;

        if (random(4)) return;
        switch(month = query_month())
        {
        case 3: case 4: case 5:
                ill = "ill_kesou";
                msg = HIG + "��Ȼ��ͷһ���������о��ƺ�Ҫ�����ˡ�\n" + NOR;
                ic  = 5;
                break;
        case 6: case 7: case 8:
                ill = "ill_zhongshu";
                msg = HIG+"ͻȻ������֮��һ���ڣ��������ˡ�\n" + NOR;
                ic  = 5;
                break;
        case 9: case 10: case 11:
                ill = "ill_shanghan";
                msg = HIG+"��������˸���ս��ͷ������ģ�����˺����ˡ�\n"+NOR;
                ic  = 5;
                break;
        case 12: case 1: case 2:
                ill = "ill_dongshang";
                msg = HIG+"��֫��ĩ��һ��ֱ�������㱻�����ˡ�\n"+NOR;
                ic  = 0;
                break;
        }

        if (random(4) == 0)
        {
                ill = "ill_fashao";
                msg = HIG+"��ż�з纮����������������\n"+NOR;
        }

        ob = users();
        for (i = 0; i < sizeof(ob); i++)
        {
                if (! objectp(env = environment(ob[i]))) continue;
                if (! env->query("outdoors")) continue;
                if (! living(ob[i])) continue;
                if ( ob[i]->query("combat_exp") < 20000) continue;
                con = ob[i]->query_con();
                con = con / 2 + random(con);
                switch (ill)
                {
                case "ill_shanghan":
                case "ill_dongshang":
                        con += ob[i]->query_temp("apply/warm") +
                               env->query_temp("warm");
                        break;

                case "ill_zhongshu":
                        con -= ob[i]->query_temp("apply/warm") +
                               env->query_temp("warm");
                        break;
                }

                if (con + ic < 40 && !random(10))
                {
                       //ob[i]->apply_condition(ill, 30 - con);
                        ob[i]->apply_condition(ill, 60 - con);
                        message("wizard:linux",sprintf("id:%s,type:%s\n",ob[i]->query("id"),ill), ob);
                        tell_object(ob[i], msg);
                }
        }
}

string ppl;



int filtdata(object ob)
{
	reset_eval_cost();
	if (!clonep(ob) || ob->is_character() || !ob->query("unique") || !environment(ob))
		return 0;
	return 1;
}

void find_unique() // Reclaim and find unique stuffs.
{
	object where;
	mixed *obs;
	string str;
	int i;

	remove_call_out("find_unique");
	call_out("find_unique", 120+random(CALLOUT_TICK));
	reclaim_objects();
	obs = filter_array(objects(), (: filtdata :));

	i = sizeof(obs);
	if(!i) return;
/* ��Ҫ�Զ� reclaim�������д���Ҳ���ֲ��ˡ�
	i = sizeof(obs);
	while (i--)
	if (!environment(obs[i]) && !interactive(obs[i]) && !obs[i]->query_temp("body_ob")) {
		reset_eval_cost();
		destruct(obs[i]);
		obs -= ({ 0 });
		i = sizeof(obs);
	}

	if(!obs || sizeof(obs) < 1 ) return;
*/
	where = environment(obs[i=random(i)]);

	if (environment(where))
		while(environment(where)->is_character())
			where = (environment(where));

	if (where->is_character()) {
		if (!environment(where))
			str = sprintf("%O", where);
		else
			str = TASK_D->get_regions(base_name(environment(where)));
		if (str == "")
			str = "��ԭ";
		str = (!random(10)?where->query("name"):"����")+"����"+obs[i]->name(1)+ "��"+ str + "һ�����֣�";
	}
	else if(where->query("short"))
		str = "��˵"+obs[i]->name(1)+ "�������"+ TASK_D->get_regions(base_name(where)) + where->query("short") + "������";
	
	if(!str) return;
	
	CHANNEL_D->do_channel(this_object(), "rumor", str);
}

// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase
void event_sunrise()
{
	int i = localtime(TIME_TICK)[4];

	if (i != current_month) {
		message("outdoor:vision", month_time[i], users());
		current_month = i;
	}
}

string outdoor_room_description()
{
	return "����" + sprintf(
		day_phase[current_day_phase]["desc_msg"],
		month_desc[current_month]) + "��\n" NOR;
}

string game_time()
{
	return CHINESE_D->chinese_date(TIME_TICK);
}

// This function is to read a regular type of data table for day_phase and
// etc.
mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}

mapping *query_day_phase() { return day_phase; }
 
