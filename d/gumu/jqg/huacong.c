// ���� ��������
// By River@SJ 7.26.2001

inherit ROOM;
#include <ansi.h>

int yueyin = 0;

void create()
{
	set("short", HIR"����"NOR);
	set("long", @LONG
���̤�������ݣ�����һ��С·���档��������Ӱ��涣������˱ǡ���
�Ｘ��С�������дУ�����һƬ��ݣ�������Ů�����ø��⽿�ޡ��չ��ľ���
̶ˮ�峺������ʵ���Ǹ������书�ĺõط���
LONG        );

	set("outdoors", "�����");

	set("exits", ([
		"west" : __DIR__"xiaolu",
	]));

	set("no_fight", 1);
	setup();
}

void do_leave(object me)
{
	if(!me) return;
	tell_object(me, HIC"�㷢�����������������书�����ǲ�����Ϊ�ã����Ǿ������뿪�ˡ�\n"NOR);
	me->move(__DIR__"xiaolu");
	message("vision", me->name()+"��"HIR"����"NOR"���˹�����\n",environment(me), ({me}));
}

void init()
{
	if(this_player()->query_temp("yueyin/ask") && yueyin == 0)
		call_out("do_wait", 2 + random(2), this_player());
	else if( yueyin > 0)
		do_leave(this_player());
	add_action("do_lian", ({"yanlian", "lianxi", "xiulian"}));
	add_action("do_wubian", "wubian");
}

int do_lian(string arg)
{
	object me, weapon;
	string msg;

	me = this_player();
	weapon = me->query_temp("weapon");

	if(!me->query_temp("yueyin/ask")) return 0;

	if( arg != "yueyin" || !arg)
		return notify_fail("��Ҫ��ʲô�أ�\n");

	if(me->query("yueyin",1))
		return notify_fail("�㲻���Ѿ����ڱ޷��������������� \n");

	if(!weapon || weapon->query("skill_type") != "whip")
		return notify_fail("������տգ���ô��Ū����������? \n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("���������̣��޷����������ˡ�\n");

	if( me->query_temp("yueyin/done"))
		return notify_fail("��ղŵ���޶�����û��ɡ�\n");

	me->add_temp("yueyin/lian", 1);

	switch(me->query_temp("yueyin/lian")) {
		case 1:  msg = HIC"\n$N΢΢һЦ������һ����"+weapon->name()+HIC"���ز���裬�ñȲʷﳯ��һ�㻮����ʡ�\n"NOR; break;
		case 2:  msg = HIC"\n$N����Ĭ�룬����"+weapon->name()+HIC"��ʽԴԴ������"+weapon->name()+HIC"������ž��������\n"NOR; break;
		case 3:  msg = HIC"\n$N���лӶ���"+weapon->name()+HIC"�����������죬���䲻��ȴ��ʮ�ֹ��죬�������ҡ�ǡ�\n"NOR; break;
		case 4:  msg = HIC"\n$N���ϴ߶���������һ���������ᷢ�ӵ����쾡�£�ֻ���������磬�������졣\n"NOR; break;
		case 5:  msg = HIC"\n$N��������������"+weapon->name()+HIC"�����û�������������ң�"+weapon->name()+HIC"�Ѿ��ܷ����Ƚ��ö��������ˡ�\n"NOR; break;
		default: msg = HIC"\n$N���ֵ�һ�ӣ�"+weapon->name()+HIC"�����ֱ۵İڶ��������У������н�������ɡ�\n"NOR; break;
	}
	message_vision(msg, me);

	me->receive_heal("jing", me->query_con()* 10);
	me->receive_damage("neili", 500);
	message_vision("����"+weapon->name()+"�ĻӶ���$N���˶�������ָ���Щ���������\n\n", me);
	me->set_temp("yueyin/done", 1);
	return 1;
}

int do_wait(object me)
{
	object *obj, ob = this_object();
	object weapon;
	int i;

        weapon = me->query_temp("weapon");        

	if(!me || environment(me) != ob
	 || !living(me) || me->is_fighting()) 
		return 0;

	if (! weapon || weapon->query("skill_type") != "whip") return 0;

	tell_room(ob, HIW"\n������С��Ů��ָ�㣬������Ƨ������׼����������������\n\n" NOR);
	tell_room(ob, HIW"����˵����Ƨ��������ػӶ��������е�"+weapon->query("name")+HIW"��������䷢���˵�������\n"NOR);
	ob->delete("exits");
	obj = all_inventory(ob);
	if(obj)
		for(i=0; i<sizeof(obj); i++) {
			if(obj[i]->query_temp("yueyin/ask")) continue;
			if(!obj[i]->is_character()) continue;
			if( obj[i]->is_corpse()) continue;
			do_leave(obj[i]);
		}

	yueyin = 10;

	me->start_busy(5);
	me->set_temp("yueyin/done", 1);

	call_out("do_wait2", 5+random(5), me, weapon);
	return 1;
}

int do_wait2(object me,object weapon)
{
	object *obj, ob = this_object();
	int i, p;

	if(!me || !userp(me) || environment(me) != ob || me->is_ghost() ){
		remove_call_out("do_over"); 
		call_out("do_over", 5, ob, weapon);
		return 0;
	}

	if (!weapon || weapon->query("skill_type") != "whip") return 0; 

	if( yueyin <= 0) {
		remove_call_out("do_over"); 
		call_out("do_over", 5, me, weapon);
		return 0;
	}

	yueyin--;

	me->start_busy(5);

	if(!living(me)) {
		yueyin = 0;
		me->delete_temp("yueyin");
		me->set_temp("last_damage_from", "�޷��ֿ������Ի��");
		me->die();
		this_object()->set("exits", ([	"west" : __DIR__"xiaolu",]));
		return 0;
	}

	obj = all_inventory(ob);
	if(obj)
		for(i=0; i<sizeof(obj); i++) {
			if(obj[i]->query_temp("yueyin/ask")) continue;
			if(!obj[i]->is_character()) continue;
			if( obj[i]->is_corpse()) continue;
			do_leave(obj[i]);
		}

	message_vision("\n$N��������"+weapon->query("name")+"��緢�����������������������˼��£�����������Щ��㱡�\n", me);
	me->receive_damage("jing", 200+random(300));
	p = (int)me->query("jing")*100/(int)me->query("max_jing");
	message_vision("( $N"+COMBAT_D->status_msg(p)+" )\n", me);
	me->delete_temp("yueyin/done");

	call_out("do_wait2", 5+random(5), me, weapon);
	return 1;
}

int do_over(object me,object weapon)
{
	yueyin = 0;

	tell_room(this_object(), HIW"\n�ص��ڻ��Լ��������ɲ�Ǽ���ʧ�ˣ���Χ�ָֻ�����ǰ�ļž���\n\n"NOR);
	tell_room(me, WHT"����˲����ϵĺ�������ղŵľ��ղ��ɻ�����Щ���£��������ֻӶ��������е�"+weapon->query("name")+WHT"��\n"NOR);

	this_object()->set("exits", ([
		"west" : __DIR__"xiaolu",
	]));

	if(!me || !userp(me) || environment(me) != this_object()
	 || !living(me) || me->is_ghost())
		return 0;

	me->start_busy(1);

	if((int)me->query_temp("yueyin/lian") >= 5){
		me->delete_temp("yueyin");
		me->set("yueyin", 1);
		tell_object(me, WHT"�����ֵ�һ�ӣ�"+weapon->query("name")+WHT"�������ֱ۵İڶ��������У������н�������ɡ�\n\n"NOR);
		tell_object(me, HIY"��ϲ����ѧ��������������\n"NOR);
		return 1;
	}
	me->delete_temp("yueyin");
	tell_object(me,WHT"������������ô�Ӷ������˻�����ʵĺ�Х֮��������û���ɵĸо���\n"+
		"���ʱ�Ļ����䣬��Ȼ�����������Լ�ʵ����û����ݣ�������Զѧ�������������ˡ�\n"NOR);
	return 1;
}

int do_wubian()
{
	object me=this_player();
	object weapon = me->query_temp("weapon");
	
	if(! me->query("family") || me->query("family/family_name") != "��Ĺ��")
		return notify_fail("�㲻�ǹ�Ĺ���ˣ�����������Ĺ�书��\n");

	if( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if( me->query_skill("whip", 1) > 100 )
		return notify_fail("�����򵥵�����Ѿ�����û���κΰ����ˡ�\n");

	if( me->query("jing") < 30 )
		return notify_fail("�㿴�������ۣ�����ȥ��Ϣһ��ɡ�\n");

	if( !weapon || weapon->query("skill_type") != "whip")
		return notify_fail("������û�б��ӣ�����ʲô����\n");

	me->receive_damage("jing", 15 + random(10));
	me->improve_skill("whip", (int)(me->query_int()/2)+(int)(me->query_skill("whip")/4));
	tell_object(me ,WHT"���趯���е�"+weapon->name()+WHT"���·����˵��ĵá�\n");
	return 1;
}
