#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�����䳡-����̨");
        set("long",@LONG
����̨��һ������ƽ̨��������ɮ����ϰ���յĵط���̨��
����ľ׮��÷��׮��ɳ����ɳ���������ʩ�͸���ɮ������������
�����ɮ������һ���໥�д衣����һ����ͨ�����֣��ſ�վ��λ
��ʦ��
LONG);
        set("outdoors","dali");
        set("exits", ([
                "east" : __DIR__"longxiang1",
                "west" : __DIR__"shanlu-1",
	             	]));
set("objects",([
		__DIR__"npc/liao-xing" : 1,
			]));

        set("coor/x",-410);
  set("coor/y",-320);
   set("coor/z",30);
   setup();
}


int valid_leave(object me, string dir)
{
       string name, new_name;
        name = me->query("name");
        new_name = name[0..1];

    if (me->query("family/family_name") != "������" &&
            present("liaoxing chanshi", environment(me)) &&
	    dir =="west")
            return notify_fail("������ʦ��ʦ����һ�죬��ס�����ȥ·��\n"+
           "˵���������ӷ�ʩ�������������ӣ����õ����Ҵ���\n");


        if (new_name != "��" && present("liaoxing chanshi", environment(me)) && dir =="west")
            return notify_fail("������ʦ����һ�죬��ס�����ȥ·��\n"+
           "˵���������ӷ���ı��ֲ�������Ҫȥ���������徻��\n");
                        
        return ::valid_leave(me, dir);
}
