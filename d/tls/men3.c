#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "������");
        set("long",@LONG
���˴��ţ���������ɮ������֮�ء�̧ͷ��ȥ��ֻ���������࣬
�������ƣ�����һ�����о���ľ��֮��������������˯������������
�׼ҵ�����Ϣ֮�ã��ſڹ���һ������(pai)�����Ҹ�վ��һλ��ɮ��
LONG);
	set("outdoors","dali");
        set("exits", ([    			
	        "west" : __DIR__"yz4",
		"east" : __DIR__"yaotai",
              "south" : __DIR__"xiuxishi1",
	]));

        set("objects",([
                __DIR__"npc/wuseng" : 2,
        ]));
                                                    
        set("item_desc",([
           "pai" : "����Ϊ�����׼ҵ���˯����\n"NOR,
        ]));

        create_door("east", "ľ��", "west", DOOR_CLOSED);

        set("coor/x",-320);
  set("coor/y",-320);
   set("coor/z",30);
   setup();
}
int valid_leave(object me, string dir)
{
        if (me->query("family/family_name") != "������" &&
            present("wu seng", environment(me)) && dir =="south")
           return notify_fail("��ɮ��ס���ȥ·����ȭ�����������׼ҵ��Ӳ�����˯����\n");
        if ((me->query("class") =="bonze") && dir =="south" )
           return notify_fail("���ǳ����ˣ�ȥ�����׼ҵ���˯�����\n");                
        return ::valid_leave(me, dir);
}


