#include <ansi.h>
inherit ROOM;

void create()
{
     set("short", GRN"����"NOR);
     set("long", @LONG
����������죬���������ݸɵ���Ҷ����֦����������������ٲ�
ά�衣�����������֦���������������������ϡ�
LONG);
        set("no_sleep_room", 1);
        set("objects", ([
        	CLASS_D("baituo") + "/ouyangfeng" : 1,
        ])); 
        set("exits", ([
         	"out" : __DIR__"shulin2",
        ]));         
        setup();
}        

void init()
{
	if(this_player() && userp(this_player()) )
	{
	write("\n�㼱�����������֣�������ֻ��һ��ò��Ů��һ����Ŀ��������\n"
	"����ȥ�������������������书��ǿ��������������֮�£���Ů��Ȼ��\n"
	"����ӯ��Ҳֻ������֧�Ŷ��ѡ�\n\n"NOR); 
        message_vision(HIY"\n$N��æ�ܳ������ݵ������м䣬������˫��ʮָ����������һ����������ԶԶ�ֿ���\n"NOR, this_player());
        write(HIY"����Ů����һ��������ת�������ּ�������Ͳ����ˡ�\n"NOR);            
        }
}

int valid_leave(object me, string dir)
{
        if (objectp(present("ouyang feng", environment(me))) && dir == "out")
                return notify_fail("ŷ�����߹�������ҡҡͷ��ʾ�����Ȳ�Ҫ�ߡ�\n");
        return ::valid_leave(me, dir);
}