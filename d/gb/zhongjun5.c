inherit ROOM;

#include "zhongjun.h"

void create()
{
	set("short", "�о�����");
	set("long", @LONG
�����ɹŴ�����о����ʣ�Զ�����������ŽǺ�ս���˻��֮���������
��ͨ�����������������Ĵ����������ס�
LONG);
	set("exits", ([
        	"south" : __DIR__"zhongjun4",
        ]));
	set("objects", ([
        	__DIR__"npc/yuanbing-shiwei" : 2,
     		__DIR__"npc/yuanshuai" :1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	ob = present("zhongjun shiwei",environment(this_player()) );
	if(ob)
    		return notify_fail("�о�����һ�ѽ�����ס�������ܣ�\n" );
        return ::valid_leave(me, dir);
}
