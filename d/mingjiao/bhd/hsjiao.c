// hsjiao.c ��ɽ����
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIR"��ɽ����"NOR);
	set("long", @LONG
��Խ��Խ�ȣ�����������ɽ���¡���ʱ�ѿɿ������ӻ�ɽ��ŭ�������
����������Ȼ��ֻ������Ҳ�Ƕ��ܲ�ס���������ǿڸ��������󺹣�����
��������һ����ľ���ݣ�ֻ���ͺͺ���ƽ�������ʯ��
LONG);
	set("exits",([
		"east"	: __DIR__"ysroad2",
		"westup" : __DIR__"huoshan1",
	]));
	set("outdoor","����");
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "westup"){
	   me->set_leader(0);
           me->unconcious();
        }
        return ::valid_leave(me, dir); 
}
