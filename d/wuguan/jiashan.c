// jiashan.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIM"��ɽ"NOR);
         set ("long",@LONG
����������ݵĺ�԰��������ʯ��ᾣ�ƽʱ�������˵���������������
���е�Ҳ�Ѿ���л�ˡ����׵�һ���ɽ����һ����϶��feng����Ŀ��Բ��¸�
���ˡ�����С·����ͨ�����ֵģ�·ǰ����һ�����ӣ�paizi����
LONG
   );
	 set("outdoors","���");

	 set("exits",([
             "north" : __DIR__"wxting",
	     "south" : __DIR__"zhulin1",
	 ]));

         set("item_desc", ([
             "feng" : BLU"һ���ں����ķ�϶����������꣨zuan����ȥ��\n"NOR,
             "paizi" : HIR"��������Σ�գ�����Ī�롣\n"NOR,
	 ]));

	 setup();
}

void init()
{
    add_action("do_zuan", "zuan"); 
}

int do_zuan(string arg)
{
        object me;
        me = this_player();

        if (arg !="feng") 
            return notify_fail("���������갡��\n");
        if( arg=="feng"){            
            write(HIG"������������϶���꣬�����ش����˷�϶��\n"NOR);
	    me->move(__DIR__"jiashan1");
            me->start_busy(2);
        }
        return 1;
}
