// by dubei
// Modify By River@sj 99.5.24
#include <ansi.h>
#include <room.h>

inherit ROOM;
int do_jump(string arg);
int do_hit(string arg);

void create()
{
        set("short", YEL"ɽ����"NOR);
        set("long", @LONG
������ɽ��֮�У�ˮ��������ɽ���ͷ����¡��¡�ĳ���������������
֮��������춶�������Խ�죬���Ǽ����ˮ����ɽ���һ��������Ƶ��ٲ���
к���£�����һ��Ϫ������ʤ�������ļ��쳣��ˮ��Ю����֦ʯ�飬ת�۱���
�ò�֪ȥ�򡣿�����������֮�ˣ������ڴ�֧�Ź�һ�����ʱ�֡�
LONG
    );

        set("outdoors", "����");
        set("no_clean_up", 0);
        setup(); 
}

void init()
{
        add_action("do_jump", ({"jump", "tiao", "yue"}));
        add_action("do_hit", "ji");
}
 
int do_jump(string arg)
{
        object me = this_player();
        if (me->is_busy()) return notify_fail("����æ���أ�\n");
        if (arg != "anbian" && arg != "shore")
            return notify_fail("��Ҫ����������\n");
         tell_room(environment(me), me->name()+ "����һ������������Ծ�˹�ȥ��\n"NOR, ({ me }));
         me->move(__DIR__"pubu");
         message_vision("$N��Ȼ��ɽ����Ծ�˳������㲽��ϵ������˰��ߡ�\n", me);
         return 1;
} 

int do_hit(string arg)
{
	object me = this_player();
        object weapon;        
	int i;
	i = me->query_skill("sword");
	if ( i > 300) i = 300;
	i += random(i);

	weapon = me->query_temp("weapon");

	if (me->is_busy() || me->is_fighting()) 
		return notify_fail("����æ���أ�\n"); 

	if (!arg ||(arg != "flood" && arg != "hongshui"))
		return notify_fail("������ʲô��\n");

	if( !me->query("ygpass"))
		return notify_fail("�����ɽ��ȭ�������һ�󣬸е���ƣ������\n");

	if (!weapon || weapon->query("skill_type") != "sword")
		return notify_fail("�����ɽ��ȭ�������һ�󣬸е���ƣ������\n");

	if (me->query_skill("xuantie-jianfa",1) <= 120
	 && weapon->query("id") != "xuantie jian")
		return notify_fail("ƾ�����ڵ����������ȼ����������������������أ�\n");

	if (me->query_skill("xuantie-jianfa", 1) > 120 
	 && me->query_skill("xuantie-jianfa", 1) <= 160
	 && weapon->query("id") != "chang jian")
		return notify_fail("�����һ�����������������Ϊ��Ҫ��һ�ѽ��ˡ�\n");

	if (me->query_skill("xuantie-jianfa", 1) > 160 
	 && weapon->query("id") != "mu jian")
		return notify_fail("�����һ�����������������Ϊ��Ҫ��һ��ȥ�����ˡ�\n");

	if (me->query("neili") < 60) 
		return notify_fail("����������㣬�޷���������ȥ��\n");

	if (me->query("qi") < 60) 
		return notify_fail("���Ѿ������ˣ��޷���������ȥ��\n");

	if (me->query("jingli") < 60) 
		return notify_fail("�㾫�����㣬�޷���������ȥ��\n");

	if( me->query_skill("force", 1) < 220)
		me->improve_skill("force",i/8+1);

	if ( weapon->query("id") == "xuantie jian")
		weapon->ob_hit();

	if (me->query_skill("xuantie-jianfa",1) <= 30){
		me->improve_skill("xuantie-jianfa",i/5+1);
		message_vision("$N��"+weapon->name()+"����������ɽ�飬���е�"+weapon->name()+"��������΢�����졣\n",me);
		write("���ƺ�������������������֮����������\n");
		me->add("neili", -5);
		me->add("jingli",-30);
		return 1;
	}
	else if ((int)me->query_skill("xuantie-jianfa",1) <= 60){
		me->improve_skill("xuantie-jianfa", i/5+1);
		message_vision("$N��"+weapon->name()+"����������ɽ�飬���е�"+weapon->name()+"���������͵����졣\n",me);
		write("���ƺ�������������������֮����������\n");
		me->add("neili", -5);
		me->add("jingli",-30);
		return 1;
	}
	else if((int)me->query_skill("xuantie-jianfa",1) <= 90){
		me->improve_skill("xuantie-jianfa", i/5 +1);
		message_vision("$N��"+weapon->name()+"����������ɽ�飬���е�"+weapon->name() + "������ˢˢ�����졣\n",me);
		write("���ƺ��������������Ĳ���֮����������\n");
		me->add("neili", -5);
		me->add("jingli",-30);
		return 1;
	}
	else if((int)me->query_skill("xuantie-jianfa",1) <= 120){
		me->improve_skill("xuantie-jianfa",i/ 4 +1);
		message_vision("$N��"+weapon->name()+"����������ɽ�飬���е�"+weapon->name()+"������¡¡�ľ�����\n",me);
		write("���ƺ����������������ھ�������������\n");
		me->add("neili", -10);
		me->add("jingli",-35);
		return 1;
	}
	else if((int)me->query_skill("xuantie-jianfa",1) <= 150){
		me->improve_skill("xuantie-jianfa", i /4+1);
		message_vision("$N��"+weapon->name()+"����������ɽ�飬���е�"+weapon->name()+"������ˢˢ�����졣\n",me);
		write("���ƺ��������������ľ�����������\n");
		me->add("neili", -10);
		me->add("jingli",-35);
		return 1;
	}
	else if((int)me->query_skill("xuantie-jianfa",1) <= 180){
		me->improve_skill("xuantie-jianfa", i /3+1);
		message_vision("$N��"+weapon->name()+"����������ɽ�飬���е�"+weapon->name()+"���������͵����졣\n",me);
		write("���ƺ�������������������֮����������\n");
		me->add("neili", -10);
		me->add("jingli",-40);
		return 1;
	}
	else if((int)me->query_skill("xuantie-jianfa",1) <= 210){
		me->improve_skill("xuantie-jianfa", i /3 +1);
		message_vision("$N��"+weapon->name()+"����������ɽ�飬���е�"+weapon->name()+"��Ȼ������\n",me);
		write("���ƺ�������������������֮����������\n");
		me->add("neili", -10);
		me->add("jingli",-40);
		return 1;
	}
	message_vision("$N��"+weapon->name()+"����������ɽ�飬���е�"+weapon->name()+"��Ȼ������\n",me);
	write("���Ѿ��޷���������������������������Ϊ�ˣ�\n");
	if(! me->query("xtjf/gift")){
		me->add("max_neili", i/2);
		me->add("max_jingli", i/3);
		me->add("eff_jingli", i/3);
		me->set("xtjf/gift", 1);
		tell_object(me,HIW"\n������һ����ֻ���������;���������ߡ�\n\n"NOR);
	}
	return 1;
}

void reset()
{
	object *ob;
	int i;
        
	ob = all_inventory(this_object());

	for(i=0; i<sizeof(ob); i++) {
		if( userp(ob[i]) ) continue;
		if(ob[i]->query("env/invisibility")) continue;
		ob[i]->reincarnate();
		if( !ob[i]->return_home() ) destruct(ob[i]);
	}
}
