#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "������");
        set("long",@LONG
���˴��ţ�������Ԫ�������ʴ�ʿԺ�ȱ��̧ͷ��ȥ��ֻ��������
�࣬�������ƣ�����һ�����о���ľ��֮��������������˯������������
�׼ҵ�����Ϣ֮�ã��ſڹ���һ������(pai)�����Ҹ�վ��һλ��ɮ��
LONG
        );
	set("outdoors","dali");
        set("exits", ([    			
                "west" : __DIR__"3wg",
                "east" : __DIR__"yz5",
               "south" : __DIR__"xiuxishi2",
               	]));
        set("objects",([
                __DIR__"npc/wuseng" : 2,
        ]));
                                                    
        set("item_desc",([
           "pai" : "����Ϊ�����׼ҵ���˯����\n"NOR,
        ]));
       
        create_door("west", "ľ��", "east", DOOR_CLOSED);

        set("coor/x",-380);
  set("coor/y",-320);
   set("coor/z",20);
   setup();
}
int valid_leave(object me, string dir)
{
        if (me->query("family/family_name") != "������" &&
            present("wu seng", environment(me)) && dir =="south")
           return notify_fail("��ɮ��ס���ȥ·����ȭ�����������׼ҵ��Ӳ�����˯����\n");
        if ((me->query("class") =="bonze") && dir =="south" )
           return notify_fail("���ǳ����ˣ�ȥ�����׼ҵ���˯�Ÿ��\n");                
        return ::valid_leave(me, dir);
}
