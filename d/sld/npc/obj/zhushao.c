// zhushao
// 98.8.5  by emnil
// 10/6/2001 by augx@sj

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG"����"NOR, ({ "zhushao","shao" }) );
	set("long",HIG"����һֻ����ѱ�ߵ����ڡ�\n"NOR);
	set("unit", "ֻ");
	set("weight", 50);
	set("no_sell",1);
	set("no_get",1);
	set("no_steal",1);
	set("no_drop",1);
	set("no_give",1);
	set("value", 1);
} 

void init()
{
	add_action("do_xunshe","xunshe");
	add_action("do_zhaoshe","zhaoshe");
	add_action("do_fangshe","fangshe");
	add_action("do_nashe","nashe");
	add_action("do_chushe","chushe");
	add_action("do_she","she");
	add_action("do_huti","huti");
	add_action("do_gongji","gongji");
}

int do_xunshe(string arg)       
{
	object me = this_player();
	
	if((int)me->query_skill("dulong-dafa",1) < 100) 
		return notify_fail("��Ķ�������Ϊ����������ѱ�ߡ�\n");
	if((int)me->query("eff_jingli") < 800) 
		return notify_fail("��ľ�Ѫ̫���ˣ�����ѱ�ߡ�\n");		
	if( objectp(me->query_temp("sld/snake")) )
		return notify_fail("���Ѿ��õ�һ�����ˡ�\n");
	if((int)environment(me)->query("canfindsnake")!=1)
		return notify_fail("���������Ҳ����ߡ�\n");

	message_vision(HIG"$N�ó����ڣ����ĵĴ�����������һ�����һ�����������С�ߴ����������˳�����\n"+
			  "$N����ָ�쵽����ǰ��С������$N�ľ�Ѫ��$N������ͻȻ�ֳ�һ˿��⣡\n"NOR,me);
	me->add("eff_jingli",-2);
	me->set("sld/mysnake",1);
	me->set("sld/getsnake",0);
	return 1;
}

int do_zhaoshe(string arg)
{ 
	object me,ob;
	int lvl,exp;

	me = this_player();
	if( !(int)me->query("sld/mysnake") )
		return notify_fail("�㻹û�����أ�\n");
	if( (int)me->query("sld/getsnake") )
		return notify_fail("���Ѿ��õ����ˡ�\n");
	if((int)environment(me)->query("canfindsnake")!=1)
		return notify_fail("���������Ҳ����ߡ�\n");

	message_vision(HIG"$N�ó����ڣ����ĵĴ�����������һ�����һ�����������С�ߴ���$N�����ϡ�\n"NOR,me);

	//seteuid(getuid());
	ob = new(__DIR__"ssnake");
	if (!ob) return notify_fail("�쳣�����޷��������ߣ�\n");
	ob->set("owner",me);
	
	exp = me->query("combat_exp"); 
	if( exp < 100000) exp = 100000;
	ob->set("combat_exp",exp);
	
	ob->set("max_qi",me->query("max_qi"));
	ob->set("eff_qi",me->query("max_qi"));
	ob->set("qi",me->query("max_qi"));  
	ob->set("max_jing",me->query("max_jing"));
	ob->set("eff_jing",me->query("max_jing"));
	ob->set("jing",me->query("max_jing")); 
	
	ob->set("max_neili",me->query("max_neili"));
	ob->set("neili",me->query("max_neili"));
	ob->set("eff_jingli",me->query("eff_jingli"));
	ob->set("jingli",me->query("eff_jingli"));
	
	lvl = me->query("max_pot") - 100;
	ob->set_skill("force",lvl);
	ob->set_skill("dodge",lvl);
	ob->set_skill("parry",lvl);
	ob->set_skill("poison",lvl);
	ob->set_temp("apply/attack",lvl);
	ob->set_temp("apply/dodge",lvl);
	ob->set_temp("apply/parry",lvl);
	ob->set_temp("apply/force",lvl);
	ob->set_temp("apply/defense", lvl);
	ob->set_temp("apply/damage",(lvl/10)>20?(lvl/10):20);
	ob->set_temp("apply/armor", (lvl/3)>50?(lvl/3):50);

	ob->move(me);

	me->set("sld/getsnake",1);
	if( objectp(me->query_temp("sld/snake")) )
		destruct(me->query_temp("snake"));
	me->set_temp("sld/snake",ob);
	return 1;
}

int do_fangshe(string arg)      
{
	object me;
	object * all;
	int i,j;

	me = this_player();
	if( !(int)me->query("sld/getsnake") )
		return notify_fail("��û���õ��ߡ�\n");
	if( !(int)environment(me)->query("canfindsnake") )
		return notify_fail("�㲻����������ߡ�\n");
		
	all = all_inventory(me);                      
	j=0; 
	for (i=0; i<sizeof(all); i++)
		if ( objectp(me->query_temp("sld/snake")) && all[i]==me->query_temp("sld/snake") ) j=1;
	if (!j) return notify_fail("��������ڲ��������ϣ�\n");

	message_vision(HIG"$N����İ�С�߷��£���������ͷ��С�����һ���ʹܻ�������ȥ�ˡ�\n"NOR,me);
	destruct(me->query_temp("sld/snake"));
	me->delete("sld/getsnake");
	me->delete_temp("sld/snake");
	me->delete_temp("sld/huti");
	
	return 1;
}

int do_nashe(string arg)        
{
	object * all,me;
	int i , j;

	me = this_player();
	if( !(int)me->query("sld/getsnake") )
                return notify_fail("��û���õ��ߡ�\n");
 
	all = all_inventory(environment(me));                      
	j=0;
	for (i=0; i<sizeof(all); i++)
		if ( objectp(me->query_temp("sld/snake")) && all[i]==me->query_temp("sld/snake") ) j=1;
	if (!j) return notify_fail("��Ҫ�õ��߲�������ѽ��\n");

	message_vision("$N��������С�ߡ�\n",me);
	(me->query_temp("sld/snake"))->move(me);

	return 1;
}

int do_chushe(string arg)       
{
	object * all,me;
	int i , j;

	me = this_player();
	if( !(int)me->query("sld/getsnake") )
		return notify_fail("��û���õ��ߡ�\n");

	all = all_inventory(me);                      
	j=0;
	for (i=0; i<sizeof(all); i++)
		if ( objectp(me->query_temp("sld/snake")) && all[i]==me->query_temp("sld/snake") ) j=1;
	if (!j)  return notify_fail("������Ѿ��ų�ȥ�ˣ�\n");

	message_vision("$N�������С�ߡ�\n",me);
	(me->query_temp("sld/snake"))->move(environment(me));

	return 1;
}
	
int do_she(string arg)  
{
	object me,ob;

	me = this_player();
	if( !(int)me->query("sld/getsnake") )
		return notify_fail("��û���õ��ߡ�\n");
 	if( !objectp(ob=me->query_temp("sld/snake")) )
		return notify_fail("������û���ߡ�\n");
	if( environment(ob) == me )
		notify_fail("����߻�û�зų�ȥ��\n");	
		
	ob->do_command(arg);
	return 1;
}

int do_gongji(string arg)  
{
	object me,ob;

	me = this_player();
	if( !(int)me->query("sld/getsnake") )
		return notify_fail("��û���õ��ߡ�\n");
 	if( !objectp(ob=me->query_temp("sld/snake")) )
		return notify_fail("������û���ߡ�\n");
	if( environment(ob) != me )
		return notify_fail("�߲��������ϣ�\n");
	if( !me->is_fighting() )
		return notify_fail("�㲢û����ս������\n");
		
	return notify_fail(ob->gongji());
}

int do_huti(string arg)  
{
	object me,ob;

	me = this_player();
	if( !(int)me->query("sld/getsnake") )
		return notify_fail("��û���õ��ߡ�\n");
 	if( !objectp(ob=me->query_temp("sld/snake")) )
		return notify_fail("������û���ߡ�\n");
	if( environment(ob) != me )
		return notify_fail("�߲��������ϣ�\n");
	if( !me->is_fighting() )
		return notify_fail("�㲢û����ս������\n");
		
	return notify_fail(ob->huti());
}
