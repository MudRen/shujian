// bishui.c ��ˮ��̶
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIC"��ˮ��̶"NOR);
       set("long", @LONG
��һ�ߵ������Ȼ��һ�ɺ���ֱ�˶������㲻�ɵô���һ������������
ϸ��һ����ԭ������������һ��ˮ���������ĺ�̶���棬����ȥ�Ǳ̳����ģ�
����ס������Ϊ��ʵ���������羵��������ţ���ʱ�㲻�ɵò���һ����
��ȥ����(walk)����ͷ��Զ����һ���ܱ��ĵط������������(jump)��ȥ��
LONG);    
	set("exits", ([
		"west" : __DIR__"shanlu2",				
	]));             
        set("outdoors", "���̹�����");
        set("mj_xl", "zhang-zhong");
	setup();
}

void init()
{
        object me = this_player();
        string arg = this_object()->query("mj_xl");
        if(me->query_temp("mj/xunluo")
           && !me->query_temp(arg)
           && me->query_temp("eatroom")
           && me->query_temp("bingqi")
           && me->query_temp("yaofang")
           && me->query_temp("mj/xunluo") == 1){
              me->add_temp(arg,1);
              me->delete_temp("eatroom");
              me->delete_temp("bingqi");
              me->delete_temp("yaofang");
        }
	if ( userp(me))
		me->start_busy(1);
        add_action("do_walk", "walk");
	add_action("do_jump", "jump");
	add_action("do_jump","tiao");
}

int do_jump(string arg)
{
	object me;
	me=this_player();
	if ( !arg || arg!="down") return 0;
	if ( !living(me)) return 0;
	if(me->is_busy() || me->is_fighting())
	        return notify_fail("����æ���ء�\n");
	if ((int)me->query("jing") < 30)
		return notify_fail("��̫���ˣ��޷�����ô���ѶȵĶ�����\n");
        message("vision", me->name()+"����һ��������һ��������̶��������ȥ��\n",environment(me), ({me}) );
	if ((int)me->query_skill("force",1) < 30){
		me->move(__DIR__"tandi");
		write(HIR"�㷢��������������Եֿ���̶���ݹǺ��䡣\n"NOR);
	        me->unconcious();
                me->move(__DIR__"bishui");
                message("vision", me->name()+"��̶����������������\n",environment(me), ({me}) );
 	        return 1;
	}
	if ((int)me->query_skill("force",1) >= 101){
		write("\n������������������Ҳû��ʲô�ô��ˡ�\n\n");
		me->move(__DIR__"tandi");
                message("vision", me->name()+"��̶������������\n", environment(me), ({me}) );
	        return 1;
	}
        if ((int)me->query_skill("force", 1) >= 30 
         && (int)me->query_skill("force", 1) <= 101
         && arg=="down" ){
                me->receive_damage("jing", 20+random(10));
                me->improve_skill("force", me->query("int"));
		write("\n�����һ������������һ��Ư���Ķ�����������ȥ...\n\n");
		me->move(__DIR__"tandi");
                message("vision", me->name() + "��̶������������\n", environment(me), ({me}) );
                tell_object(me,"�㷢����̶�����ޱȣ���æ�����ڹ���֮������\n");
	return 1;
	}
}

int do_walk(string arg)
{
        object me;
        me = this_player();
	if (!living(me)) return 0;
	if(me->is_busy() || me->is_fighting())
	        return notify_fail("����æ���ء�\n");
	if ((int)me->query("jing") < 30)
		return notify_fail("��̫���ˣ��޷������ڱ��������ߣ�\n");
	if ((int)me->query_skill("dodge", 1) > 100)
		return notify_fail("�������ڹ⻬�ı������������ɣ�������ȥ���������Ṧû���İ�����\n");
	if ((int)me->query_skill("dodge", 1) < 30 )
		return notify_fail("��Ϊ����̫����ʹ���޷����������ߣ����ˤ����\n");
	me->receive_damage("jing", 20+random(10));
	me->improve_skill("dodge", me->query("int"));
	message_vision("$N�ڹ⻬�羵�ı����ϲ��ϵ������߶���\n", me);
	return 1;	
}
