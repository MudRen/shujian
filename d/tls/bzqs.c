#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
  set("short","�����ű�");
  set("long",@LONG
���߳������֣�һ���������ǰ����ס�����ȥ·��������һ
�����������ţ������������ٺ�ľ���������ģ�һ��紵������ҡҡ
��׹������ľ�廹������ȥ���㲻�ɵ���ԥ������ֹ����ǰ�ˡ�һ��
ʯ��(shibei)�������ԡ�
LONG);
     set("outdoors", "������");
     set("exits",([
           "north" : __DIR__"bzq",
           "south" : __DIR__"road5",
     ]));

set("objects",([
		__DIR__"npc/liao-kuan" : 1,
		]));


     set("item_desc", ([
                "shibei" :
HIW"


    ����������������
    ����������������
    ��������  ������
    ������ �� ������
    ������    ������
    ������ �� ������
    ��������  ������
    ������ �� ������
    ��������  ������
    ����������������
    ����������������\n"NOR,
        ]));

     set("coor/x",-390);
  set("coor/y",-290);
   set("coor/z",30);
   setup();
}
int valid_leave(object me, string dir)
{
       string name, new_name;
      //  me = this_player();
        name = me->query("name");
        new_name = name[0..1];

    if (me->query("family/family_name") != "������" &&
            present("liaokuan chanshi", environment(me)) &&
	    dir =="north")
            return notify_fail("�˿���ʦ��ʦ����һ�죬��ס�����ȥ·��\n"+
           "˵���������ӷ�ʩ�������������ӣ����ù������ŵ���ɽ��\n");
/*
     if ((new_name != "��" || && present("liaokuan chanshi", environment(me)) && dir =="north")
            return notify_fail("�˿���ʦ����һ�죬��ס�����ȥ·��\n"+
           "˵���������ӷ���ı��ֲ���������ȥ��ɽ��\n");
*/                       
        return ::valid_leave(me, dir);
}