// Room: /u/zqb/tiezhang/sslin-1.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "������");
	set("long", @LONG
���߽�һƬ��ѹѹ�������֣����������֦��Ҷï�����������������ա�
������������Ҽ������������ڵ����������У��γ�������ɫ�Ĺ�����ɷ�Ǻ�
�������������ţ���Ȼ�����Լ�����ʧ����Ƭ�����У��Ҳ�����ȥ��·�ˡ�
LONG
	);

	set("exits", ([ 
		"west" : __FILE__,
		"east" : __FILE__,
		"south" : __DIR__ "sslin-4",
		"north" : __DIR__"dezj",
	]));
	set("outdoors", "����ɽ");
	set("no_clean_up", 0);
	setup();

}

void init()
{
	add_action("do_fa","fa");
}

int do_fa(string arg)
{    
        object me,weapon,obj;
        int costj, costq;
        me = this_player();

        if(me->query_temp("job_name")!="��ľ") 
             return notify_fail("���������������⹤�������������! \n");
        if (me->is_busy())
             return notify_fail("��������æ����!\n");
        if (me->is_fighting())
             return notify_fail("������ս����,�޷�ר�ĸɻ�!\n");
        weapon = me->query_temp("weapon");
        if( !weapon || weapon->query("id") != "tie fu")
             return notify_fail("������ʲô����ľ��\n");
        if ( !arg || !(arg == "mu" || arg == "ľ"))
           return notify_fail("����Ҫ��ʲô��\n");
             
        costj = random((int)me->query("con")/2);
        costq = random((int)me->query("str")/2);

        if ((int)me->query("jingli") < costj 
         || (int)me->query("qi") < costq){
		message_vision(HIR"����һ�ô�������$N���ϣ�$Nһ���ӱ������˹�ȥ��\n"NOR,me);
		me->unconcious();
		return 1;
	}        
	me->receive_damage("jingli", costj);
	me->add("qi", -costq);       
	if (((int)me->query_temp("mark/��ľ") > 20 + random(5))){
		me->set_temp("mark/����",1);
		write(HIW"�㷢�ֵ��ϵ�ľͷ���ÿ�����һ���ˣ�Ӧ�û�ȥ������!!\n"NOR);
		return 1;
	}  
	write ("�����������������������һ���¿�ȥ��\n");
	me->add_busy(1);
	me->add_temp("mark/��ľ",1);
	if ( me->query("combat_exp", 1) > 30000 
	 && !me->query_temp("mark/meet_gf")
	 && random(10) > 7){
		obj = new(__DIR__"npc/gfbing");
		me->set_temp("mark/meet_gf", 1);
		obj->set_temp("guanfu", me->query("id"));
		obj->move(environment(me));
	}
	if ((int)me->query_skill("axe", 1) < 31 && random(10)> 6 ){
		write(HIM"����ڻ�����������Щ���!\n"NOR);
		me->improve_skill("axe", (int)(me->query("int") / 10));
	}
	return 1;
}
