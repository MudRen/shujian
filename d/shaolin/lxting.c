//lxting.c
//by bren

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", MAG"��ѩͤ"NOR);
	set("long", @LONG
����̨��ʰ�׶��ϣ���ǰ����һ��ͤ��һ��ĵ��á���ǰ������д�š�
��ѩͤ���������֡�����������Ħͤ�����ڷ��蹩���Ħͭ��Ͷ��棬����
�����棬����������ഫ���������ѩ�ϱ۵��ڴ�Ħ�洫�²��ĵط�����
�����е�����������һλ��ü�������ɮ��
LONG
	);

	set("exits", ([
		"north" : __DIR__"sblu-2",
                "southdown" : __DIR__"taijie",
       ]));
        set("objects",([
		CLASS_D("shaolin") + "/hui-guang" : 1,
	]));

	set("coor/x",50);
  set("coor/y",360);
   set("coor/z",130);
   set("coor/x",50);
 set("coor/y",360);
   set("coor/z",130);
   setup();
	
}

int valid_leave(object me, string dir)
{
     mapping myfam;
     myfam = (mapping)me->query("family");
    

    if (!me->query("luohan_winner") &&
       (!myfam || myfam["family_name"] == "������" ) &&
       objectp(present("huiguang zunzhe", environment(me))) &&
       dir == "north" ) 
    {
     return notify_fail("�۹�������ס�㹪��˵�����������Ǳ����صأ���ı���"
              "�������������룡\n");
    }
    if (!me->query("luohan_winner") &&
       (!myfam || myfam["family_name"] != "������" ) &&
       objectp(present("huiguang zunzhe", environment(me))) &&
       dir == "north" ) 
    {
          return notify_fail("�۹�������ס�㹪��˵�����������������صأ���Ǳ���"
              "���ӣ��������룡\n");
    }

    return ::valid_leave(me, dir);
}

