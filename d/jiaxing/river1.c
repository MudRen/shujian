#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", GRN "������" NOR);
        set("long", @LONG
����ˮ��֮�ص����Ӳ��ݺᣬ��Ƭ�����ֱ�����һ��С���ԣ��������Ʈ
�ڣ������������衣ʱ��ʱ����һ��ֻ�������޴�����ǰ�ܹ��������Ǹ��õ�
����ǰ��С����·���޷����С�
LONG); 
        set("no_sleep_room", 1);
        set("objects", ([
        	CLASS_D("baituo") + "/guairen" : 1,                   
        ]));       
        set("exits", ([
              "west" : __DIR__"river",
        ]));
        set("outdoors", "����");
        setup(); 
}
