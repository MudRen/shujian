// Room:jpei����֮��
// Date: Jpei 2010

#include <ansi.h>
inherit ROOM;

void create()
{
          set("short",  HIW "����ɽ��" NOR);
	set("long", @LONG
������һ�����ɸߵ�ɽ�£���̧ͷһ������Ȼ����ɽ����������һ���������
���ɵ����п�ϲ���㲻ס�����Ͽ�����Ȼûע�⵽����û���κγ�·��
LONG
);

        set("no_clean_up", 0);
        set("no_death", 1);
        set("exits", ([
               "down" : "d/city/dangpu",
        ]));
        setup();
}
