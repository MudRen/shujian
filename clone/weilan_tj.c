/* tiejiang.c 
  Imbue npc 
	Created by snowman@SJ 21/04/2001

   Copyright 1997-2004 ShuJian MUD Wizard Group.
   All rights reserved.
*/

#include <ansi.h>
inherit NPC;
string ask_money();
string ask_imbue();
#define USER_WEAPOND     "/adm/daemons/user_weapond"


void back_player(object obj)
{
	object me;
	if(!objectp(me = query_temp("dazao_target")))
	{
		destruct(obj);
		command("say �⵹���ˣ����Ҵ��죬��ȴ�ֲ����ˡ�");
		command("consider");
		delete_temp("dazao_target");
		call_out("ddd",1);
		return;
	}
	if(!present(me,environment()))
	{
		obj->move(me);
		message_vision("һ�������̵Ļ�Ƴ嵽$N��ǰ������$Nһ"+obj->query("unit")+obj->name()+"���漴˵���������ϰ彻������ġ�\n",me);
		//tell_object(me,
		//"һ�������̵Ļ�Ƴ嵽����ǰ��������һ"+obj->query("unit")+obj->name()+"���漴˵���������ϰ彻������ġ�\n"
		//);
		delete_temp("dazao_target");
		call_out("ddd",1);
		return;
	}
	command("give 1 to "+getuid(me));
	command("say �ȵ������˰ɣ��Ǻǡ�");
	
	call_out("ddd",1);
}

void ddd()
{
	object npc;
	command("say Τ��ү�ٻỹҪ�Ҵ��������");
	command("wave");
	delete_temp("dazao_target");
	
	npc=present("zhujian shi",environment(this_object()));
	if(npc) npc->delete_temp("dazao_target");
	destruct(this_object());
}


void create()
{
        set_name("Τ������", ({ "weilan tiejiang", "weilan", "tiejiang" }));
        set("nickname", HIY"�ɶ��칤"NOR);
        set("gender", "����");
        set("long", "
������������Ϊ�����۴����ǰѴ���ʽ�Ľ���������˹���İ��˰���
������������������¼�(name)��\n\n");
        set("age", 41);
        set("attitude", "heroism");
        set("unique", 1);
        set("combat_exp", 100000);
        set("no_quest", 1);
        set("shen", 3000);
        set("str", 1000);
        set("int", 1000);
        set("con", 1000);
        set("dex", 1000);
        set("jiali", 200);
        set("max_qi", 900000);
        set("max_jing", 900000);
        set("eff_jingli", 900000);
        set("max_neili", 900000);
        /*
        set("inquiry", ([
                "dazao": (: ask_imbue() :),
                "money": (: ask_money :),
                "name": "�����ڸ��������Ҵ���(dazao)�������ܴ����õ�����������.....�ٺ١�

Ҫ�� һ��"HIC"����"CYN"������(��Ͱ�������)��
����������������Դﵽ���콣�����������������кܶ฽�����ԡ�

���ƣ�  ÿ�˾���500Kʱ���Դ��죬�Ժ�ÿһ����������һ�δ�����ᣬ�úð���Ŷ��

\n",
        ]) );;
        */
        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        
                
        set_temp("apply/dodge", 700);
        set_temp("apply/parry", 700);
        set_temp("apply/attack", 700);
        
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object("/d/zhiye/obj/tiechui")->wield();
}

void init()
{
	::init();
	if(query("come")) return;
	
	set_skill("duanzao", 260+random(80) );
		
	set("come",1);
	call_out("iamhere",0);
	//add_action("do_imbue","dazao");
}

void iamhere()
{
	command("wink zhujian shi");
}

int go_dazao(object lu,object me,string cmds)
{
	set_temp("dazao_target",me);
	return lu->duanzao_it(this_object(),cmds);
}

void die()
{
	message_vision("$N�������˼���������ɫ�������ö��ˡ�\n",this_object());
	return;
}


string ask_money()
{
	return "�������Ѿ�׬��" + MONEY_D->money_str(this_object()->query("balance")) + "��";
}

string ask_imbue()
{
	object wp, me = this_player();
	mapping im;
	int i = me->query("get_imbue_weapon");
	
	if( i && i > time() )
		return "��û������أ����ٵȵȰɣ�\n";
	if( i && i <= time() ){
		me->delete("get_imbue_weapon");
		if( !mapp(im = me->query("imbue_weapon")) )
			return USER_WEAPOND->ask_imbue();		
		wp = USER_WEAPOND->make_weapon(me, im["type"], im["i"] , im["mar"]);
		me->delete("imbue_weapon");
		if( wp )
        		wp->move(me);
        	else return "�������ɳ�����֪ͨsnowman! \n";
        	
        	message_vision("$N������õ�"+wp->name()+"����$n��\n\n", this_object(), me);
        	write(HIW"��ϸʹ���뿴 uweapon ���\n"NOR);
        	return "��Ū���ˣ�\n";
        }
        
	return USER_WEAPOND->ask_imbue();
}

int do_imbue(string arg)
{
        object wp, me;
        string type, mar;
        int i;
        
        if( !living(this_object()) ) return 0;
        
        if( !arg )
                return notify_fail("��ʽ�� dazao <������Ҫ���������>\n");
        
        me = this_player();
        
        if( (int)me->query("get_imbue_weapon") )
        	return notify_fail("���ȰѴ��������ȡ����˵��(ask weilan about dazao)��\n");        
        if( wizardp(me) || SECURITY_D->get_status(me)!="(player)" )
                return notify_fail("��ʦû�д����Ȩ����\n");

        if( !objectp(wp = present(arg, me)) )
                return notify_fail("������û������������\n");
        
        if( !wp->query("weapon_prop") )
                return notify_fail("����Ŀǰֻ�ܴ���������\n");
        
        if( me->is_busy() || me->is_fighting() )
                return notify_fail("����æ����˵�ɡ�\n");
                
        if( wp->query("equipped") )
                return notify_fail("Ҫ���죬���ȷ��������ɡ�\n");
        if( wp->query("imbued") || strsrch(file_name(wp),USER_WEAPOND->query_uwname())==0  )
                return notify_fail("���������Ѿ�������ˡ�\n");
                
        if( !stringp(type = wp->query("skill_type")) )
                return notify_fail("����ֻ�ܴ����ʽ������\n");
               
        if( this_object()->is_busy() )
                return notify_fail("����æ���أ��ȵȡ�\n");
                
	if( wp->is_corpse() ){
		me->start_busy(5);
		message_vision("$N���ŵ����˹�ȥ��\n", this_object());
		this_object()->unconcious();
		return notify_fail("��⣡\n");
	}

        switch(type){
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
                case "whip": break;
                default:
                        return notify_fail("���ﲻ�ܴ�������������\n");
        }
        
        if( wp->id("xiao") ) type = "xiao";
        
        message_vision("$N�ó�"+wp->name()+"��Ҫ$n��æ���졣\n\n",me,  this_object());
	this_object()->start_busy(2);
	
	if( !me->query("imbue_reward")){
		if( me->query("combat_exp") < 500000 )
                	return notify_fail("����Ŀǰ��ˮƽ���ҿ����ò���ʲô�������ģ����Ժ������ɡ�\n");
        
        	if( me->query("combat_exp")/1000000 < (int)me->query("user_weapon_imbued") ){
                	return notify_fail("����Ŀǰ�ľ�����˵��������������Ժ�������ɡ�\n");        	
        	}
        	me->add("user_weapon_imbued", 1);
        }
        else me->add("imbue_reward",-1);
        
        if(!me->query("imbue_reward")) me->delete("imbue_reward");
	
	me->start_busy(2);
        mar = wp->query("material");
        mar = stringp(mar)?mar:"steel";
        
        destruct(wp);
        
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
        
        me->set("imbue_weapon/type", type);
        me->set("imbue_weapon/mar", mar);
        me->set("imbue_weapon/i", i);
                 	
 	if( !wizardp(me) ){
 		me->set("get_imbue_weapon", time() + 18000);
        	message_vision("$N���ͷ������������ʱ������ȡ�ɡ�\n\n", this_object());
	}
	else {
		message_vision("$N���ͷ����������ˡ�\n\n", this_object());
		me->set("get_imbue_weapon", 10000);
	}
        return 1;
}
