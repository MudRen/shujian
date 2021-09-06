// /u/ciwei/tong.c
#include <ansi.h>
#include <get_place.h>
#define CMDS_SET "/cmds/wiz/setask"

inherit NPC;
inherit F_SAVE;

string *msg_dunno;
mapping baowu_list;
string* shuang_list;
string* no_tell;
mapping askwhat;
//add name here rumors

int do_ask(string arg);
int ask_me(object me,string arg);
string askabout(object me,string arg);
string query_save_file();

int set_ask(string pattern, mapping def)
{
	askwhat[pattern] = def;
	save();
	return 1;
}
int delete_ask(string pattern)
{
	if(!stringp(pattern)) return 0;
	map_delete(askwhat,pattern);
	save();
	return 1;
}
mapping query_ask()
{
	return askwhat;
}
string* query_baowu()
{
	return keys(baowu_list);
}

void create()
{
	seteuid(ROOT_UID);	
	//if( !restore() && !mapp(askwhat) )
	//	askwhat = ([]);
	call_out("dest_busy",2);
	
	set_name("����ͨ",({"wanshi tong","tong","wanshi","liulang"}));
	set("title",HIW"�齣����"NOR);
        set("nickname",HIY"������֪"NOR);
        set("rank_info/rude", "����ͨ�ϴ�");
	set("no_quest",1);
	set("no_ansuan",1);
	set("no_get","ֻ�������˶����ˡ�\n");
	set("gender", "����" );
	set("shen_type", 1);
	set("age", 23+random(6));
       	set("str", 15);
       	set("con", 15);
       	set("int", 27);
       	set("dex", 20);
       	set("env/wimpy", 110);
       	set("long", "���ǻ�ɽ��ţ�����˵ĵ�ϵ���ӡ�\n"
       		    "��˵�Ѿ����������ʤ�����ˡ�" );
       	set("combat_exp", 2500);
       	set("attitude", "friendly");
       	set("max_qi", 200);
       	set("max_jing", 200);       	
       	set_skill("unarmed", 10);
       	set_skill("dodge", 10);
	set_skill("parry", 10);	
	restore();
	call_out("fix_error",1);
			
	setup();
	carry_object(BINGQI_D("sword/gangjian"));
        carry_object("/d/gumu/obj/buxue1")->wear();
        carry_object("/d/gumu/obj/pao1")->wear();
}
void init()
{
	add_action("do_ask","ask");
}

int ask_busy;

string query_save_file()
{
        return "/log/wanshitong";
}

int do_ask(string arg)
{
	object me;
	string dest,topic;
	
	me = this_player();
	if (me->is_busy())
                return notify_fail("����Ъ������˵���ɡ�\n");
        if (me->query_temp("ask_tong_times") > 10){
        	message_vision("$n��$N���˷����ۣ�˵��������ô��ôjjww�ģ���������Ҫ�շѵģ��������������ȡ�\n", me, this_object());
        	return 1;
	}
        if (!arg || sscanf(arg, "%s about %s", dest, topic) != 2)
                return notify_fail("��Ҫ��˭ʲô�£�\n");
        if(  member_array(dest,my_id) == -1 )
        	return "/cmds/std/ask"->main(me,arg);        
        if (!INQUIRY_D->parse_inquiry(me, this_object(), topic))
                message_vision("$N��$n�����йء�" + topic + "������Ϣ��\n", me, this_object());
       	return ask_me(me,topic);
}

int accept_object(object who, object ob)
{
	
	if (ob->query("money_id") && ob->value() >= 400) 
	{
		message_vision("$n��$NЦ��Ц˵������Ǯ�ˣ������ʰɣ�������\n", who, this_object());
		who->delete_temp("ask_tong_times");
		return 1;
	}
	return 0;
}

int ask_me(object me,string arg)
{
	object ob = this_object();
	int chang,i;
	string re;
	if (!living(ob)) {
                message_vision("���Ǻ���Ȼ�ģ�$n���ڵ�״��û�а취��$N�κδ𸲡�\n", me, ob);
                return 1;
        }
        chang = strlen(arg);        
        for(i=0;i<chang;i++)
        {
        	if(arg[i]<'A' || arg[i]>'z' || ( arg[i]<'a' && arg[i]>'Z' )) break;
        }        
        if (i == chang &&((arg[i-1]>='A' && arg[i-1]<='Z')||( arg[i-1]>='a' && arg[i-1]<='z'))) arg = lower_case(arg);
        
        if (arg == ob->query("name") || ob->id(arg))
        	message_vision(CYN "$N˵�����Ǿ���" + RANK_D->query_self_rude(ob) + CYN "ѽ��\n" NOR, ob);
        else if (arg == me->query("name") || me->id(arg))
        	message_vision(CYN "$N˵�����Ǿ���" + RANK_D->query_rude(me) + CYN "��ѽ��\n" NOR, ob);
        //else if (ask_busy > 0 ) message_vision( CYN "$N��$n���ͷ���˵����������æ�ţ���Ȼ����ʰɡ���\n" NOR,ob,me );
        else if (random(10) == 1 ) message_vision( CYN "$N��$n�������"+(replace_string(no_tell[random(sizeof(no_tell))],"arg",arg))+"��\n" NOR,ob,me );
        else if (stringp(re = askabout(me,arg)))
        {
        	re = replace_string(re,"textn","\n");
        	message_vision( CYN "$N��$n�������"+re+"��\n" NOR,ob,me );
        	//����semote
        	if(mapp(askwhat)&& mapp(askwhat[arg]) && stringp(askwhat[arg]["semote"]) && askwhat[arg]["semote"]!="" ) "/adm/daemons/emoted"->do_emote(ob,askwhat[arg]["semote"]);
        }
        else message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
        
        me->add_temp("ask_tong_times",1);	
	return 1;
}
string askabout(object me,string arg)
{
	object ob;
	object* obs;	
	object user;
	//object where;
	mapping fam;
	string name = "";
	string msg;
	int exp,i;
	int flag = 0;
	ask_busy = 2;
	call_out("dest_busy",2);
	//����
	if(arg == "name"){
		return "С�˱�ס�����ݵĳǱߣ�
��������������������ޱߣ� 
˭֪���Ʋ����������᲻�����棬 
����ٸ�Ŀ���죬ռ�Ҵ��ݶ����
��үү�������������ұ���һ������⣬ 
���������������񣬷�����׽�����Ƹ��� 
ǿ����һ�ٱ飬һ�ٱ飬����������Ծ��ź��˼䡣 

�������Ҹ��ӣ�����˼�԰�����䵽���ߣ� 
��Ϊ�����ϵ���ֻ�ж�����������ǰ�� 
˭֪���Ʋ�������ʵ��̫���� ��
֪�������Σ������������㣬���Ҹ��ӿ�Ź����ǰ��

С����׳�������������棬�����ϸ�������죬 
Ϊ�����ϵ���Ψ������Ϊū�������� 
һ����׬Ǯ��һ�����ƪ�� 
���İѹ����ԣ����г�����־�ᣡ 
�Ӵ�����ʫ������ߣ������Ǵ˳𲻹����죡���� ";
	}
	if(arg == "rumors")
	{
		return "��˵����ͨ��������SJ�ˣ�";
	}
	if(arg == "here")
	{
		return "...";
	}
	if(arg == "���ﳤ�����ﳤ")
	{
		return "�������������磡��";
	}
	if (arg =="job" || arg =="����" || arg=="quest" )
	{
		obs = children(USER_OB);
		i = random(sizeof(obs));
		msg = obs[i]->query("name") + "(" + obs[i]->query("id") + ")";
		switch(random(7))
		{
			case 0:return "�Ҷ��ˣ���ȥ����Ū��Ե�����";
			case 1:return msg+"����ܸ��������ԣ���ȥ������ɱ�ˡ�";
			case 2:return msg+"���򲻴��������������һ�������޵У������ȥ����������";
			case 3:return "����æ�����������ء�";
			case 4:return "��������ү������һ������ȥ����";
			case 5:return "����������ã����ϵ�Ǯ����ˣ���ȥ����Ū��ƽ�(Gold)ȥ��";
			case 6:return "��˵��Ĺ�����������һ��MM,��ȥ����Ū����";
		}
	}
	if (arg =="fangqi" || arg=="����" || arg=="cancel")
	{
		switch(random(3))
		{
			case 0:return "�겻��Ҳû��ϵ���´���������ү������";
			case 1:return "��ô�򵥶��겻�ɣ���̫����ʧ����";
			case 2:return "����ô��ô�������Ǹ��������ˣ���";
		}
	}
	//����������	huju δ���
	if(member_array(arg,keys(baowu_list) ) != -1 )
	{		
		if (random(5) != 1 ) return arg+"����ʲô"+arg+"��û������û������";
		obs = children(baowu_list[arg]);		
		if(sizeof(obs) >= 1 )
		{
			ob = obs[random(sizeof(obs))];
			ob = environment(ob);
			if(!ob)	return "���ǲ�˵����";
			if(ob->is_character()) return random(2)?(arg+"��֪����˭�����ˡ���"):(arg+"����������"+ob->name()+"("+ob->query("id")+")�����ˡ�");
			return arg+"������ʧ��"+TASK_D->get_regions(base_name(ob))+"�����ˡ�" ;
		}
		else return arg+"����ʲô"+arg+"��û������û������";		
	}	
//����	
//shaer ����
	if(member_array(arg,shuang_list) != -1 )
	{
		ob = find_object("/d/city/npc/shuang")?find_object("/d/city/npc/shuang"):load_object("/d/city/npc/shuang");
		switch(arg)
		{
			case "����":case "beauty":
				return ob->ask_beauty();
			case "��ª":case "ugly":
				return ob->ask_ugly();
			case "����":case "age":
				return ob->ask_age();
			case "����":case "exp":
				return ob->ask_exp();
			case "���":case "fat":
				return ob->ask_fat();
			case "ɱ��":case "pk":
				return ob->ask_pk();
			case "���":case "balance":
				return ob->ask_balance();			
		}
	}	
// more ..	
	if (mapp(askwhat) && mapp(askwhat[arg]) && stringp(askwhat[arg]["word"])) return askwhat[arg]["word"];
	//is ob return name
	exp = strlen(arg);
	while (exp--) if (arg[exp] < 'a' || arg[exp] > 'z')
		return 0;
	if(!objectp(user = find_player(arg))) 
	{
		flag = 1;
		if(!objectp(user = CMDS_SET->get_player(arg))) return 0;
	}
	if(objectp(user)){	
		name = user->query("name");
		fam = user->query("family");
		exp = user->query("combat_exp");		
		
		/*if (!flag && random(10) > 7)
		{
		       msg = "Ŷ����˵"+name+"("+user->query("id")+")����";
		       where = environment(user);
       		       if (!where) 
       		       		msg += "���С�����Ӻ�����ʧ��Ү...";  
       		       else
       		       		msg += "������"+get_place(base_name(where)) + (string)where->query("short") +CYN+"�����������ɹ̫����";
       		       	return msg;
		}*/
			
		if(name!="")
		{	
			msg = "Ŷ����˵"+name+"("+user->query("id")+")�������˵���������������";
			if (mapp(fam)) msg += "��˵��"+fam["family_name"]+(fam["master_name"]?(fam["master_name"]+"����"):"")+(exp>1000000?"���֡�":"���֡�");
			if (stringp(user->query("nickname"))) {
				msg+= "������ŽС�"+user->query("nickname")+CYN+"����";
				switch(random(3))
				{
				case 0:msg += "������";break;
				case 1:msg += "��ק��";break;
				case 2:msg += "���ᡣ";break;
				}
			}
			if (flag) destruct(user);
			return msg;
		}
		
	}
	return 0;	
}
void dest_busy()
{
	ask_busy--;
	if(ask_busy > 0 ) call_out("dest_busy",2);
}
void fix_error()
{
}