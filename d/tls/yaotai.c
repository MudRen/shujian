#include <room.h>

inherit ROOM;

void create()
{
        set("short", "�嶼��̨");
        set("long",@LONG
�ɴ˹�ȥһ·������ʯ·�ˣ���һ��ֻ׼����ɮ�½��룬������
�����û�з�������ǲ��������˵ġ��򱱿ɵ����޾����껨Ժ�Ķ�
�������ף��򶫿�������̨��ϰ�书�����������ڵ�ҩ����
LONG);
        set("outdoors","������");
        set("exits", ([
                "northup": __DIR__"road2",
                "eastup": __DIR__"banruo",
                "west": __DIR__"men3",
				"south":__DIR__"yaofang",                          
        ]));
			set("objects",([
                __DIR__"npc/liao-qing" : 1,
        ]));
        set("coor/x",-310);
  set("coor/y",-320);
   set("coor/z",30);
   setup();

        create_door("west", "ľ��", "east", DOOR_CLOSED);

}
int valid_leave(object me, string dir)
{	
	mapping myfam;
        myfam = (mapping)me->query("family");
                     
   if ((!myfam || myfam["family_name"] != "������") && objectp(present("liaoqing chanshi", environment(me)))
      &&(dir == "northup"||dir == "eastup"))
            return notify_fail("������ʦ����һ�죬��ס�����ȥ·��\n"+
           "˵���������ӷ��㲻�������µ��ӣ�����������������ޡ�\n");

if ( !me->query("tls") && objectp(present("liaoqing chanshi", environment(me)))
      &&(dir == "northup"||dir == "eastup"))
            return notify_fail("������ʦ����һ�죬��ס�����ȥ·��\n"+
           "˵���������ӷ��㲻�������³��ҵ��ӣ�����������������ޡ�\n");
                        
        return ::valid_leave(me, dir);
}