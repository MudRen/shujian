// Room: /dali/chahuayuan.c
// Modify By River 98/12
inherit ROOM;
#include <ansi.h>
#include <wanted.h>
void create()
{
        set("short",HIC"�軨԰"NOR);
        set("long", @LONG
����軨�������£��������һ��Сɽ�£���԰��ɽ������ɽ����������
�軨�����ϵ�Ʒ�֡���ױ�ع�������ʮ��ѧʿ����Ҳ�в�һЩ�ġ������š���
�͡�ץ������������
LONG
       );
        set("exits", ([ 
           "northup" : __DIR__"chahuayuan2",
           "west" : __DIR__"dongjie6",
	]));
        set("outdoors","����");
        set("objects", ([
             __DIR__"npc/xiaosi" : 1, 
        ]));        
        set("coor/x",-280);
  set("coor/y",-440);
   set("coor/z",-20);
   setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "northup" && is_wanted(me))
		return 0;
     if ( !me->query_temp("flower_paid") && dir == "northup" )
	return notify_fail("�뿴�軨԰���ȸ�Ǯ����\n");     
	return ::valid_leave(me, dir);
}
