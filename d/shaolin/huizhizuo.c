// /d/mingjiao/bishui.c
// Jay 4/3/97 -qingyun
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
         set("short",HIG"����ʥ��"NOR);
       set("long", @LONG
������ʦʥ��������֮��ԭ��һ��ʯ������ö���ֻ����ʯ�̵ؾ�����
Ϊ��������������ӧ���磬�������ϡ������϶�ͨ��������磻�񴲱̼���
��Ⱦ�˳�������ʯ���������Ż���Ȼ�������⻪���ã�Ŀ����ɫ��������ʦ
���������׸���ѣĿ֮�������棬�������ġ��ıڸ�����һ��ǧ����������
��̬������ͬ����������������֮���������ס�
LONG
     );
    
	set("exits", ([
		"out" : __DIR__"fota2",				
	]));             
        setup();
}
void init()
{
	add_action("do_ningwang",({"gaze","ningwang"}));
}
int do_ningwang(string arg)
{
	object me;
	me=this_player();
	if (arg!="foxiang") return notify_fail("��Ҫ����ʲô��\n");
	if (!living(me)) return 0;
	if (!random(5))
        message("vision", me->name()+"���ڶ���ǽ������ۿ�������ַ���\n",
        environment(me), ({me}) );
      if ((int)me->query_skill("hand",1)<30){
		write("���������񣬵���ǧ�ַ�����ʵ�ް�������Ѱ��\n");
 	return 1;
	}
	if ((int)me->query_skill("hand",1)>100){
		      write("���������䷱�����Ѿ����������ġ�\n");
	return 1;
	}
        me->receive_damage("jing", 30);
        me->improve_skill("hand", (me->query("int"))*3/2);
        write("�����ŷ���ǧ��ٹ�֮�ַ������жԻ����ַ���������\n");
	return 1;
}
