#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"��𱦵�"NOR);
        set("long",@LONG
��������������������й���������ԭ���ݶ���һԲ��Ϊ������
���ƣ�����֧���Բ����ס�����﹩��������ȼ���Ϲŷ��棬�����
�£�����֮����һ������е�����͵�ֹ���ˣ��������������ɮ��
����֮�ء�
LONG
        );
       
         set("exits", ([
                "south" : __DIR__"baodian",
                "northdown" : __DIR__"yz6",
                "west" : __DIR__"men2",
                "east" : __DIR__"men1",
        ]));


	set("objects",([
                __DIR__"npc/ben-yin" : 1,
        ]));

        set("coor/x",-350);
  set("coor/y",-320);
   set("coor/z",30);
   setup();
}
int valid_leave(object me, string dir)
{
     mapping fam;
 fam = (mapping)me->query("family");
	
	if ( fam && fam["family_name"] != "������" &&
            present("benyin dashi", environment(me)) &&
			 dir == "northdown")
            return notify_fail("�����ʦ����һ�죬��ס�����ȥ·��\n"+
           "˵���������ӷ��㲻�������µ��ӣ�����������������ޡ�\n");
    if (fam)
	if ( present("benyin dashi", environment(me)) &&
			 !me->query("tls") &&
		dir == "northdown")
            return notify_fail("�����ʦ����һ�죬��ס�����ȥ·��\n"+
           "˵���������ӷ��㲻�������³��ҵ��ӣ�����������������ޡ�\n");                    
        return ::valid_leave(me, dir);
}
