inherit ROOM;

#include "zhongjun.h"

void create()
{
	set("short", "�о�");
	set("long", @LONG
�����ɹŴ�����о���Զ�����������ŽǺ�ս���˻��֮��������ʿ����
��Χ������ȥ������ս��һ��������
LONG);
	set("exits", ([
        	"north" : __DIR__"zhongjun5",
        	"south" : __DIR__"zhongjun3",
        ]));
	set("objects", ([
        	__DIR__"npc/yuanbing-shiwei" : 1,
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
