// zhujian-shi
// by augx@sj  9/15/2001

#include "ansi.h"
#include <job_mul.h>
/*
/adm/daemons/workerd.c
*/

inherit NPC;
inherit F_VENDOR; 

#include <mudlib.h>

#define RESET_TIME	15

string ask_job();
string ask_fail();
string ask_reward();
string ask_info();
string ask_list();
string ask_weilan();
int do_answer(string arg);
#include "/d/zhiye/npc/forbook.c"

int do_answer(string arg)
{
	string id1,id2,cmds;
	int i,j;
	object lu;
	object obj,npc;	
	object me = this_player();
		
//  if(wizardp(me) && INTERMUD_MUD_NAME!="TEST" && INTERMUD_MUD_NAME!="SJTY") return notify_fail("�����˼Ҳ���һֱ��SMASH��ô��\n");
	if(!me->query_temp("zj_answer")) return 0;
	if(!arg) return notify_fail("����˵ʲô��\n");
	switch(arg)
	{
		case "sword":
                case "axe":
                case "blade":
                case "brush":
                case "club":
                case "dagger":
                case "fork":
                case "hammer":
                case "hook":
                case "spear":
                case "staff":
                case "stick":
                case "xiao":
                case "whip": break;
                default:
                        return notify_fail("����������ô��\n");
	}

	me->delete_temp("zj_answer");
	
	if(objectp(query_temp("dazao_target")))
		return notify_fail("����æ���أ�\n");
	
	//if ( !objectp(weapon=this_object()->query_temp("weapon")) || weapon->query("id")!="tiechui" )
                //return notify_fail("�ҵ����������ˣ��Ժ���˵�ɡ�\n");
	if( !environment(this_object()) || !(lu=present("huo lu",environment(this_object())))) 
	{
		command("shout");
		return notify_fail("��ҹ��������¯�Ѿ���С����͵�ˡ�\n");
	}
	
	if( !me->query("imbue_reward")){
                if( me->query("combat_exp") < 1100000 ) // By Spiderii ���ƽ��������ʺŴ���
                	return notify_fail("����Ŀǰ��ˮƽ���ҿ��ǻ��Ǳ����������Ժ������ɡ�\n");
        
        	if( me->query("combat_exp")/1000000 < (int)me->query("user_weapon_imbued") ){
                	return notify_fail("Τ���������ں�æ���㻹�Ǻú�����������ʱ�������ɡ�\n");
        	}
        	me->add("user_weapon_imbued", 1);
        }
        else me->add("imbue_reward",-1);
        
        
        if(!me->query("imbue_reward")) me->delete("imbue_reward");
                
        if( me->query("combat_exp") > 4000000 && !random(me->query("kar"))
        && !random(me->query("per")) && !random(me->query("pur")) )
        	i = 4;        	
        else if( me->query("combat_exp") > 3000000 
        && random(me->query("kar")) > 20 && random(20) > 15 )
        	i = 3;
        else if(  me->query("combat_exp") > 1000000
        && random(me->query("kar")) > 10 && random(15) > 11 )
        	i = 2;
        else if(  random(me->query("kar")) > 5 )
        	i = 1;
        else i = 0;
        
        switch(i)
        {
        	case 0:j = 1+random(3);break;
        	case 1:j = 4+random(2);break;
        	case 2:j = 6+random(2);break;
        	case 3:j = 8+random(2);break;
            case 4:j = 10;break;
        	default:
        		return notify_fail("�ҿ����������ɰ���\n");
        }
                
        command("nod");
        npc = new(NPC_D("weilan_tj"));
        npc->move(environment(this_object()));
        
        message_vision("$N�첽���˹�����\n",npc);
        
        obj = new("/d/zhiye/obj/kuangshi");        
        if(obj && obj->set_level(j))
        {
        	obj->move(npc);
        	id1= obj->query("id");
        	message_vision("$N����$nһ"+obj->query("unit")+obj->name()+"��\n",this_object(),npc );
        }
        obj = new("/d/zhiye/obj/kuangshi");
        if(obj && obj->set_level(j))
        {
        	obj->move(npc);
        	//message_vision("$N�ӻ����ͳ�"+obj->name()+"��\n",this_object());
        	message_vision("$N����$nһ"+obj->query("unit")+obj->name()+"��\n",this_object(),npc );
        }
        obj = new("/d/zhiye/obj/othermaterial");
        if(obj && obj->set_level(i+1,1))
        {
        	obj->move(npc);
        	id2= obj->query("id");
        	message_vision("$N����$nһ"+obj->query("unit")+obj->name()+"��\n",this_object(),npc );
        }
        cmds=arg+" "+id1+" with "+id2;        
        set_temp("dazao_target",me);
                
        //lu->duanzao_it(this_object(),cmds)
        if(!npc->go_dazao(lu,me,cmds)){
        	log_file("career/worker",getuid(me)+" ask ����ʧ�ܡ�",this_object() );
        	return notify_fail("�����ˣ���ȥ֪ͨciwei��\n");
        }
        command("say �Ե�Ƭ�̡�\n");
        return 1;
}

string ask_weilan()
{
	object me;
	object lu;
	me = this_player();
	
	if(!userp(me)) return 0;
	
  //    if(wizardp(me)  && INTERMUD_MUD_NAME!="TEST" && INTERMUD_MUD_NAME!="SJ" ) return "�����˼Ҳ���һֱ��SMASH��ô��\n";
		
	if(objectp(query_temp("dazao_target")))
		return "����æ���أ�\n";
	
	//if ( !objectp(weapon=this_object()->query_temp("weapon")) || weapon->query("id")!="tiechui" )
                //return "�ҵ����������ˣ��Ժ���˵�ɡ�\n";
	if( !environment(this_object()) || !(lu=present("huo lu",environment(this_object())))) 
	{
		command("shout");
		return "��ҹ��������¯�Ѿ���С����͵�ˡ�\n";
	}
	if( !me->query("imbue_reward")){
                if( me->query("combat_exp") < 500000 ) // By Spiderii ���ƽ��������ʺŴ���
                	return "����Ŀǰ��ˮƽ���ҿ��ǻ��Ǳ����������Ժ������ɡ�\n";
        
        	if( me->query("combat_exp")/1000000 < (int)me->query("user_weapon_imbued") ){
                	return "Τ���������ں�æ���㻹�Ǻú�����������ʱ�������ɡ�\n";
        	}
        }
	command("say Ŷ��������Τ����������������");
        command("say Τ���������ڽ���Τ��ү�����ˣ�û��ô�����ʱ���ˡ�");
        command("whisper "+getuid(me)+" ������������ôŬ���ķ��ϣ��Ҿͽ�Τ���������ɡ�");
        me->set_temp("zj_answer",1);
        return "����Ҫ����ʲô�͸���˵(da)�ɣ�\n";
}

void create()
{
	set_name("����ʦ",({ "zhujian shi","shi" }) );
	set("gender", "����" );
	set("age", 51);
	set("long","����λ���಻����Ц������ʦ����Ȼû�������ʲô������������������ͨ��������������
�ڳ����Լ����������֮�⣬��Ҳ���չ����������⡣");

	set("str", 55);
	set("dex", 55);
	set("con", 25);
	set("int", 25);
	set("shen_type", 1);
	set("move_seller", 1);
	set("shen", 100);
	set("attitude", "peaceful");
	set("combat_exp", 1000000);
	set_max_encumbrance(10000000);

	set_skill("dodge", 300);
	set_skill("force", 300);
	set_skill("parry", 300);
	set_skill("unarmed", 300);
	set_skill("literate", 150);
	set_skill("duanzao", 300);

	set("max_qi", 99999);
	set("max_neili", 99999);
	set("max_jing", 99999);
	set("max_jingli", 99999);
	set("eff_jingli", 99999);

	set_temp("apply/dodge",888);
	set_temp("apply/parry",888);
	set_temp("apply/force",888);
	set_temp("apply/attack",888);
	set_temp("apply/damage",333);
	set_temp("apply/armor",888);

	set("chat_chance", 1);
 	set("chat_msg", ({
 		CYN"����ʦմմ��ϲ��˵������������򵽲��ٺñ�������\n"NOR,
 		CYN"����ʦ˵�������Ҵ���ı������������б�֤��Ŷ����\n"NOR,
 		CYN"����ʦ�Ĺ���˵�����������費��Ҫѧϰ���켼������������ѧϰ����ѧ��ô.....�ٺ١�\n"NOR,
 		CYN"����ʦ˵������������̫æ���߲�����˭�ܰ��ҰѴ�õı������û���ȥ������\n"NOR,
 		CYN"����ʦ˵��������Ȼ���첻����������������Ҽ��������ı��¿������µ�һ����\n"NOR,
 	}) );

 	set("no_ansuan",1);
 	set("no_bark",1);

	set("inquiry", ([
		"����"		: (: ask_job :),
		"job"		: (: ask_job :),
		"����"		: (: ask_job :),
		"����"		: (: ask_fail :),
		"abandon"	: (: ask_fail :),
		"���"		: (: ask_reward :),
		"����"		: (: ask_reward :),
		"reward"	: (: ask_reward :),
		"����"		: (: WORKER_D->ask_imbue("weapon") :),
		"weapon"	: (: WORKER_D->ask_imbue("weapon") :),
		"����"		: (: ask_info :),
		"jianding"	: (: ask_info :),
		"����"          : (: ask_list :),
		"������"          : (: ask_list :),
		"Τ������":(:ask_weilan:),
		"weilan":(:ask_weilan:),
		"Τ��":(:ask_weilan:),
	]));

	set("ask_user/123",1);
	set("forg_type","weapon");

	set("vendor_goods", ({
		(["name": BINGQI_D("sword/sword"),"number":10]),
		(["name": BINGQI_D("blade/blade"),"number":10]),
		(["name": BINGQI_D("hammer/chui"),"number":10]),
		(["name": BINGQI_D("club/gun"),"number":10]),
		(["name": BINGQI_D("staff/gangzhang"),"number":10]),
		(["name": BINGQI_D("whip/whip"),"number":10]),
		(["name": BINGQI_D("hook"),"number":10]),
		(["name": BINGQI_D("stick"),"number":10]),
                (["name": BINGQI_D("axe"),"number":10]),
                (["name": BINGQI_D("dagger"),"number":10]),
	}));

	setup();

	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(__DIR__"../obj/tiechui")->wield();
	add_money("coin",99);

//	if ( clonep() ) call_out("reset_var",RESET_TIME*60);
}

string ask_list()
{
	WORKER_D->show_rank(this_player(),"weapon");
	return RANK_D->query_respect(this_player())+"����Ŷ��";
}

void kill_ob(object ob)
{
	object me = this_object();
	command("!!!");
	command("say ����һ���ط�������ʦ��ΪʲôҪɱ���أ�");
	me->remove_enemy(ob);
	ob->remove_killer(me);
	return;
}

int accept_fight(object ob)
{
	command("say ����һ���ط�������ʦ��ΪʲôҪɱ���أ�");
	return 0;
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
	add_action("do_sell", "sell");
	//add_action("do_asktime", "asktime");
	add_action("do_jianding", "jianding");

	add_action("do_worker", "worker");
	add_action("do_taojiao","taojiao");///for tiejiang xx
	add_action("do_answer",({"da","answer"}));
}

int do_worker(string arg)
{
	object me = this_player();
	string * str;

	if( getuid(me) != "ciwei" ) return 0;
	if( !arg || arg=="" ) arg = "help";

	str = explode(arg," ");
	switch (str[0]) {
		case "debug":
			WORKER_D->set_debug_mode();			
			tell_object(me,"��������ģʽ��\n");
			tell_object(me,"���棡�뾡������ʽվʹ�ô�ָ�������������� �رղ���ģʽ\n");
			break;
		case "nodebug":
			WORKER_D->unset_debug_mode();
			tell_object(me,"�رղ���ģʽ��\n");
			break;
		case "querytick":
			tell_object(me , sprintf("tick_count: %f\n",WORKER_D->query_tick_count()) );
			break;
		case "settick":
			//WORKER_D->set_tick_count(atoi(str[1]));
			WORKER_D->set_tick_count(str[1]);
			tell_object(me,"set tick_count ok.\n");
			break;
		case "help":
		default:
			tell_object(me,"���������debug ; nodebug ; querytick ; settick\n");
			break;
	}
	return 1;
}

int prevent_learn(object me, string skill)
{
	if (skill == "duanzao")
		return 0;
	return 1;
}

int is_apprentice_of(object me)
{
	return 1;
}

int recognize_apprentice(object ob)
{
	int money = 150, level = ob->query_skill("duanzao", 1);

	if (level > 9) money = 300;
	if (level > 19) money = 600;
	if (level > 29) money = 1200;
	if (level > 39) money = 2500;
	if (level > 70) money = 3000;
	if (level > 140) money = 3500;	
	if (level > 220) return 0;

	switch (MONEY_D->player_pay(ob, money)) {
		case 0:
		case 2: tell_object(ob,"�����ڵ�ѧ����ÿ��"+MONEY_D->money_str(money)+"�����Ǯ������\n" ); return 0;
	}
	return 1;
}

////////////////////////////////////////////////////////////////////
int query_goods_value2(object goods)
{
	object me = this_player();
	int value, trade_level;

	value = goods->query("value");
	trade_level = me->query_skill("trade", 1) / 10;
	if (trade_level > 15) trade_level = 15;
	value = value * (85 + trade_level) / 100;

	return value;
}

int do_sell(string arg)
{
	object ob;
	object me = this_player();
	int value, improve;

	if (!living(this_object()))
		return notify_fail("���ǵȶԷ�������˵�ɡ�\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����ʦ˵��������æ���ء�\n");

	if (!arg || !(ob = present(arg, me)))
		return notify_fail("����ʦ˵������Ҫ��ʲô��\n");

	if (query_temp("busy"))
		return notify_fail("����ʦ˵����Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

	if ( !(int)ob->query("imbued") || !mapp(ob->query("weapon_mp/weapon_prop")) )
		return notify_fail("����ʦ˵������ֻ�չ��������ı�����\n");
	
	if(stringp(ob->query("owner")) && ob->query("owner")!="" && ob->query("owner")!="0")
		return notify_fail("�㻹����������������˽�б�ǰɡ�\n");

	value = query_goods_value2(ob);
	message_vision("$N��"+MONEY_D->price_str(value)+"�ļ۸�������һ"+ob->query("unit")+ob->name() + "��$n��\n", me, this_object());
	ob->delete_weapon(me);
	destruct(ob);
	MONEY_D->pay_player(me, value);
	improve = 40 - me->query("pur");
	me->improve_skill("trade", improve / 2 + random(improve));
	set_temp("busy", 1);
	call_out("delete_temp", 1, "busy");

	return 1;
}

///////////////////////////// worker job ////////////////////////////
int check(object ob)
{
	object room;
	string room_name;

	if( !objectp(ob)
	 || !ob->query("startroom")      // add by Yuj@SJ to void job NPC
	 || ob->query("env/invisibility")
	 || ob->query("no_quest")
	 || userp(ob)
	 || ob->query("attitude")=="aggressive"
	 || !objectp(room=environment(ob))
	 || room->query("no_fight")
	 || room->query("quest")
	 || room->query("outdoors") == "���ش��"
	 || strsrch(room_name = file_name(room),"/d/") != 0
	 || strsrch(room_name, "/d/wizard/") == 0
	 || strsrch(room_name, "/d/wuguan/") == 0
	 || strsrch(room_name, "/d/death/") == 0
	 || strsrch(room_name, "/d/group/") == 0
	 || strsrch(room_name, "/d/mingjiao/lsd/") == 0
	 || strsrch(room_name, "/d/mingjiao/bhd/") == 0
	 || strsrch(room_name, "/d/shaolin/fumoquan") == 0
	 || strsrch(room_name, "/d/baituo/") == 0 )
		return 0;
	return 1;
}

#include <get_place.h>

string ask_job()
{
	object me = this_player() ,room ,oroom ,lastroom ,target, *living , obj;
	int lvl = (int)me->query_skill("duanzao",1) , i,j,k,a,b;
	string * exits;

	if ( environment(me)->query("no_zhiye"))
		return "������ûʲô����Ҫ����";
	if( lvl<10 )
		return "��ļ���̫���ˣ��ҿɲ���������ȥ���¡�";
	if( lvl>=395 )
		return "���Ķ��켼����ô���ˣ��ҿɲ����ٲ�ǲ���ˡ�";
	if( !wizardp(me) && me->query("worker/job2") && time()<(int)me->query("worker/job2_time") )
		return "�Ҳ��ǽ���ѱ����͸�"+me->query("worker/job2_oroom")+"������"+me->query("worker/job2_target")+"����";
	if( !wizardp(me) && time()<(int)me->query("worker/job2_time") )
		return "��̫æ�˰ɣ�Ҫע����Ϣ����";

	living = livings();
	for (i=0;i<sizeof(living);i++){
		j = random(sizeof(living));
		if (j <= 1 || j == sizeof(living)-1) continue;
		if( check(living[j]) ){
			target = living[j];
			room = environment(target);
			if( !mapp(room->query("exits")) || sizeof(room->query("exits"))<1 ) continue;

			if( get_place(base_name(room))!="" ) {
				oroom = room;
				if ( random(10)<3 && target->query("race")=="����" ) {
					j = 0;
					break;
				}

				lastroom = room;
				j = 1+random(9);
				for(k=0;k<j;k++) {
					exits = values(room->query("exits"));
					b = sizeof(exits);
					while( (a=random(b))>=0 && b>1 ) {
						if (b==2)
							if ((exits[0]==base_name(lastroom) && exits[1]==base_name(oroom))
							 || (exits[1]==base_name(lastroom) && exits[0]==base_name(oroom)))
								break;
						if (exits[a]==base_name(lastroom) || exits[a]==base_name(oroom)) continue;
						break;
					}
					lastroom = room;
					if( !(room = find_object(exits[a])) )
						if( !(room = load_object(exits[a])) )
							break;
				}
				if(k<j) continue;
				break;
			}
		}
	}

	if( !target || !room )
		return "�����ûʲô���⣬���һ��������ɡ�";

	if(j>0) {
		target = new(__DIR__"customer");
		target->set("player",me->query("id"));
		target->move(room);
	}

	obj = new("/d/zhiye/obj/baojian");
	obj->move(me);

	me->set("worker/job2",1);
	me->set("worker/job2_oroom",get_place(base_name(oroom))+oroom->query("short"));
	me->set("worker/job2_far",j);
	me->set("worker/job2_finish",0);
	me->set("worker/job2_target",target->query("name"));
	me->set("worker/job2_room",base_name(room));
	me->set("worker/job2_time",time()+20*60);
	if(wizardp(me) && me->query("env/test"))
		tell_object(me,base_name(oroom)+" -> "+base_name(room)+"\n");

	command("pat "+me->query("id"));
	if (j)
		command("whisper "+me->query("id")+" ����Ұѱ����͸�"+me->query("worker/job2_target")+"������"
			+me->query("worker/job2_oroom")+"��Χ��Բ"+CHINESE_D->chinese_number(me->query("worker/job2_far"))+"��֮�ڡ�" );
	else
		command("whisper "+me->query("id")+" ����Ұѱ����͸�"+me->query("worker/job2_oroom")+"��"
			+me->query("worker/job2_target")+"��");
	message_vision(CYN"������$Nһ�Ѹոմ���õĶ��Ʊ�����\n"NOR, me);
	return "�úøɻ�Ҳ��������ġ�";
}

string ask_fail()
{
	object me = this_player() , obj;

	if( !me->query("worker/job2")
	 || time()>=(int)me->query("worker/job2_time")
	 || environment(me)->query("no_zhiye"))
		return "��Ҫ����ʲô��";

	me->delete("worker/job2");
	me->delete("worker/job2_oroom");
	me->delete("worker/job2_far");
	me->delete("worker/job2_target");
	me->delete("worker/job2_room");
	me->delete("worker/job2_finish");

	if ( objectp(obj = present("dingzhi baojian", me)) ) {
		message_vision(CYN"$N�Ѷ��Ʊ�����������ʦ��\n"NOR, me);
		destruct(obj);
		me->set("worker/job2_time",time()+(2+random(3))*60);
		command("disapp " + me->query("id"));
		return "û�뵽��ô�򵥵������㶼�����ˣ�";
	}
	else {
		command("slash " + me->query("id"));
		me->set("worker/job2_time",time()+(10+random(10))*60);
		return "���Ͳ���Ҳ�����ˣ�����ô�ѻ���Ū���ˣ�";
	}
}

void destroying(object obj)
{
	if (!obj) return;
	if (userp(obj))
		command("drop "+obj->parse_command_id_list()[0]);
	else
		destruct(obj);
}

string ask_reward()
{
	object me = this_player();
	int improve,lvl,exp;

	if( !me->query("worker/job2")
	|| environment(me)->query("no_zhiye"))
		return "����û���ҸɻҪʲô���꣡";

	if( !me->query("worker/job2_finish") )
		return "�㻹û����������أ�Ҫʲô���꣡";

	me->delete("worker/job2");
	me->delete("worker/job2_oroom");
	me->delete("worker/job2_target");
	me->delete("worker/job2_far");
	me->delete("worker/job2_room");
	me->delete("worker/job2_finish");
	me->set("worker/job2_time",time()+ 20 + random(30));

	lvl = (int)me->query_skill("duanzao",1) / 2;
	improve = (300 + lvl) * 11/10;
	improve = improve*2/3 + random(improve*2/3);
	//improve = improve*ZY_ZHUJIAN_JOB_MUL/100;
	exp = improve/20;
	
	exp = me->add_exp_combat( exp ,this_object(),"�ͽ�����",1);
	//me->add("combat_exp", exp);
		
	command("applaud " + me->query("id"));
	improve = WORKER_D->check_impove(me,"duanzao",improve,2);
	if(improve>0) tell_object(me, HIC"����ʦ��ϸ���㽲�����ľ��ϣ���Ķ��켼��������"+CHINESE_D->chinese_number(improve)+"�㼼�ܵ�������"+CHINESE_D->chinese_number(exp)+"�㾭�飡\n"NOR);
	else tell_object(me, HIC"����"+CHINESE_D->chinese_number(exp)+"�㾭�飡\n"NOR);
	/*
			
	if (me->query_skill("duanzao",1) <220){
		me->improve_skill("duanzao", improve);
		tell_object(me, HIC"����ʦ��ϸ���㽲�����ľ��ϣ���Ķ��켼��������"+CHINESE_D->chinese_number(improve)+"�㼼�ܵ�������"+CHINESE_D->chinese_number(exp)+"�㾭�飡\n"NOR);
	}
	else
	{
		improve = 0;
		tell_object(me, HIC"����"+CHINESE_D->chinese_number(exp)+"�㾭�飡\n"NOR);
	}
	*/
	log_file("job/wsongjian",sprintf("%s(%s)�����ܵ�����%d�����飺%d����exp��%d\n", me->name(), me->query("id"),improve,exp,me->query("combat_exp")),me);

	return "�����ģ��ɻ����������Ժ��пջ���������ɻ��";
}

string ask_info()
{
	return
"�����Ҫ������ı���������ʹ�����jianding ������ϸ�̶� ����id
���ṩ��ѵļ򵥼����������Ҫ֪����������ϸ��Ϣ��Ҫ���Ʒѵ��ˣ�hehe......

������ϸ�̶ȣ�
	1. �򵥼���		�۸����
	2. ����ϸ�ļ���		�۸�ʮ���ƽ�
	3. ��ϸ�ļ���		�۸���ʮ���ƽ�
	4. ����ϸ�ļ���		�۸�һ�ٶ��ƽ�
	5. ��ȫ����		�۸����ٶ��ƽ�
";
}

protected string make_info(int base,int rnd)
{
	int i =  base / rnd;
	if(rnd>1)
		return CHINESE_D->chinese_number(i*rnd) +" �� "+ CHINESE_D->chinese_number((i+1)*rnd-1);
	else
		return CHINESE_D->chinese_number(base);
}

int do_jianding(string arg)
{
	object me = this_player() , wp;
	string wpname , str;
	mapping mp;
	int lvl,money, a1,a2,a3,a4;

	if (!arg) return notify_fail(CYN"����ʦ˵������Ҫ����ʲô������\n"NOR);
	if (me->query_busy()) return notify_fail(CYN"����ʦ˵��������æ���أ�\n"NOR);
	if (query_temp("busy")) return notify_fail(CYN"����ʦ˵��������æ���أ�\n"NOR);
	if (sscanf(arg,"%d %s",lvl,wpname)<2 || !objectp(wp=present(wpname, me)) )
		return notify_fail("��Ҫ����ʲô������\n");
	if ( !wp->query("imbued") || !mapp(wp->query("weapon_mp/weapon_prop")) )
		return notify_fail(CYN"����ʦ˵������ֻ�ܼ����������ı�����\n"NOR);

	switch(lvl) {
		case 1: money=  0; break;
		case 2: money= 10*10000; break;
		case 3: money= 50*10000; break;
		case 4: money=100*10000; break;
		case 5: money=300*10000; break;
		default: return notify_fail(CYN"����ʦ˵������Ҫ������ʲô�̶ȣ�\n"NOR);
	}

	if(!wizardp(me) && money > 0) {
		switch( MONEY_D->player_pay(me,money) ) {
			case 0:
			case 2:	return notify_fail(CYN"����ʦ˵�������Ǯ��������\n");
			default: break;
		}
		message_vision("$N����$n"+MONEY_D->price_str(money)+"����$n����"+wp->query("name")+"��\n", me,this_object());
	}
	else message_vision("$N��$n����"+wp->query("name")+"��\n", me,this_object());

	command("say �˼������ı���ǣ�"+wp->query("weapon_mp/save_id")+"    "+
		"�����ȼ�Ϊ��"+CHINESE_D->chinese_number(6-wp->query("imbued"))+"    "+
		"�ۺ����ۣ�"+CHINESE_D->chinese_number(WORKER_D->weapon_rank(wp)));
	if(lvl==1) {
		set_temp("busy", 1);
		call_out("delete_temp", 1, "busy");
		return 1;
	}

	switch(lvl) {
		case 2: a1=50; a2=10; a3=10; a4=1000; break;
		case 3: a1=30; a2= 5; a3= 5; a4= 600; break;
		case 4: a1=20; a2= 3; a3= 3; a4= 300; break;
		case 5: a1= 1; a2= 1; a3= 1; a4=   1; break;
	}
	command("say ������"+make_info(wp->query("weapon_prop/damage"),a1)+"    "+
		"�����ȣ�"+make_info(wp->query("sharpness"),a2)+"    "+
		"Ӳ�ȣ�"+make_info(wp->query("rigidity"),a2)+"\n	      "+
		"�;ö�/����;öȣ�"+make_info(wp->query("weapon_mp/dur"),a4)+" / "+make_info(wp->query("weapon_mp/max_dur"),a4)+"\n	      "+
		"��ֵ��"+make_info(wp->query("value")/10000,a3)+"  ���ƽ�");
	if(lvl<=3) {
		set_temp("busy", 1);
		call_out("delete_temp", 1, "busy");
		return 1;
	}

	switch(lvl) {
		case 4: a1=30; a2=25; a3=100; break;
		case 5: a1= 1; a2= 1; a3=  1; break;
	}

	if( !mapp(wp->query("weapon_mp/weapon_prop")) ) {
		set_temp("busy", 1);
		call_out("delete_temp", 1, "busy");
		return 1;
	}
	else {
		mp = wp->query("weapon_mp/weapon_prop");
	}

	str = "say �������ԣ�\n	      ";	a4 = 0;
	if( !undefinedp(mp["qi"]) ) { str+="��������"+make_info(mp["qi"],1); a4++; }
	if( a4>0 ) if( a4<=1 ) str+="    "; else { str+="\n	      "; a4=0; }
	if( !undefinedp(mp["jing"]) ) { str+="���Ӿ���"+make_info(mp["jing"],1); a4++; }
	if( a4>0 ) if( a4<=1 ) str+="    "; else { str+="\n	      "; a4=0; }
	if( !undefinedp(mp["neili"]) ) { str+="����������"+make_info(mp["neili"],1); a4++; }
	if( a4>0 ) if( a4<=1 ) str+="    "; else { str+="\n	      "; a4=0; }
	if( !undefinedp(mp["jingli"]) ) { str+="���Ӿ�����"+make_info(mp["jingli"],1); a4++; }
	if( a4>0 ) { str+="\n	      "; a4=0; }

	if( !undefinedp(mp["strength"]) ) { str+="���ӱ�����"+make_info(mp["strength"],1); a4++; }
	if( a4>0 ) if( a4<=1 ) str+="    "; else { str+="\n	      "; a4=0; }
	if( !undefinedp(mp["intelligence"]) ) { str+="�������ԣ�"+make_info(mp["intelligence"],1); a4++; }
	if( a4>0 ) if( a4<=1 ) str+="    "; else { str+="\n	      "; a4=0; }
	if( !undefinedp(mp["constitution"]) ) { str+="���Ӹ��ǣ�"+make_info(mp["constitution"],1); a4++; }
	if( a4>0 ) if( a4<=1 ) str+="    "; else { str+="\n	      "; a4=0; }
	if( !undefinedp(mp["dexerity"]) ) { str+="��������"+make_info(mp["dexerity"],1); a4++; }
	if( a4>0 ) { str+="\n	      "; a4=0; }

	if( wp->query("poison_number") ) str+="���ԣ�"+make_info(wp->query("poison_number"),a3)+"\n	      ";
	if( !undefinedp(mp["attack"]) ) str+="�������У�"+make_info(mp["attack"],a1)+"\n	      ";
	if( !undefinedp(mp["parry"]) ) str+="���ӷ�����"+make_info(mp["parry"],a2)+"\n	      ";
	if( !undefinedp(mp["dodge"]) ) str+="���Ӷ�ܣ�"+make_info(mp["dodge"],a2)+"\n	      ";
	if( !undefinedp(mp["armor_vs_force"]) ) str+="�����ڹ����ԣ�"+make_info(mp["armor_vs_force"],a2)+"\n	      ";

	command(str);

	set_temp("busy", 1);
	call_out("delete_temp", 1, "busy");
	return 1;
}
//******************************************************************
/*
void reset_var()
{
	remove_call_out("reset_var");
	delete("ask_user");
	call_out("reset_var",RESET_TIME*60);
}

int do_asktime(string arg)
{
	object me = this_player() , wp;
	int delay;

	if (!arg) return notify_fail(CYN"����ʦ˵������Ҫ��ѯʲô������\n"NOR);
	if (me->query_busy()) return notify_fail(CYN"����ʦ˵��������æ���أ�\n"NOR);
	if ( !objectp(wp = present(arg, me)) )
		return notify_fail("������û�����������\n");
	if ( !wp->query("imbued") )
		return notify_fail(CYN"����ʦ˵������ֻ�ܲ�ѯ�������ı�����\n"NOR);
	if ( wp->query("imbued")<=3 )
		return notify_fail(CYN"����ʦ˵������������������Ҫ���¡�\n"NOR);
	if ( (int)query("ask_user/"+me->query("id"))>0 )
		return notify_fail(CYN"����ʦ˵������ող�ѯ������ô�����ˣ�\n"NOR);

	WORKER_D->update_UniqueValues("querytime","save_id="+wp->query("weapon_mp/save_id"),"time-"+wp->query("weapon_mp/save_id"));
	tell_object(me,CYN"����ʦ˵�����ðɣ��Ұ������һ�£����Ե�......\n"NOR);

	delay = 20;
	if(wizardp(me) && me->query("env/test")) delay = 5;
	me->start_busy(delay);
	call_out("asktime_finish",delay,me,wp);
	return 1;
}

void asktime_finish(object me,object wp)
{
	int t;

	if ( !objectp(me) || !userp(me) || !objectp(wp) ) return;
	t = WORKER_D->query_UniqueValues("querytime","time-"+wp->query("weapon_mp/save_id"));
	tell_object(me,CYN"����ʦ˵������ı������Ϊ��"+wp->query("weapon_mp/save_id")+"��\n"NOR);
	if(t<0)
		tell_object(me,CYN"����ʦ˵������Ҳ��֪������ʱ�䣬���ܵ�ԭ���ǣ���������޷�����ͬ����������\n"NOR);
	else
		tell_object(me,CYN"����ʦ˵���������������ĸ���ʱ��Ϊ��"+CHINESE_D->chinese_date(t,1)+"��\n"NOR);
	set("ask_user/"+me->query("id"),1);
}

void tell_limit(object me)
{
	int v1,v2,v3,v4;	

	if (!objectp(me) || !userp(me)) return;

	v1 = WORKER_D->query_UniqueValues("queryweapon","");
	v3 = WORKER_D->query_UniqueValues("queryweapon2","");
	if(v1<0) {
		tell_object(me,CYN"����ʦ˵������Ҳ��������ѽ�����ܵ�ԭ���ǣ���������޷�����ͬ����������\n"NOR);
	}
	else {
		v2 = v1 / 0x10000;
		v1 = v1 % 0x10000;
		v4 = v3 / 0x10000;
		v3 = v3 % 0x10000;
		tell_object(me,CYN"����ʦ˵������˵�������������й���"+CHINESE_D->chinese_number(v2)+"��ͷ�ȱ�����"+CHINESE_D->chinese_number(v4)+"�����ȱ�����\n"NOR);
		tell_object(me,CYN"����ʦ˵������˵����������������"+CHINESE_D->chinese_number(v1)+"��ͷ�ȱ�����"+CHINESE_D->chinese_number(v3)+"�����ȱ�����\n"NOR);
	}
	///////////////////////////////////
	int delay;
	object me = this_player();

	if( WORKER_D->update_UniqueValues("queryweapon","","") > 1 ) {
		delay = 2;
		me->start_busy(delay);
		call_out("tell_limit",delay,me);
		return "��������......";
	}
	else {
		delay = 20;
		if(wizardp(me) && me->query("env/test")) delay=5;
		me->start_busy(delay);
		call_out("tell_limit",delay,me);
		return "�����Ҫ���ʱ��˲�֪�������һ��......";
	}
	
}
*/
